#include "truss.h"
#include "joint.h"
#include "edge.h"
#include "force.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <limits>

using ADDM = Eigen::Matrix<ad::tangent_t<double>, Eigen::Dynamic, Eigen::Dynamic>; // dynamic ad matrix
using ADDV = Eigen::Matrix<ad::tangent_t<double>, Eigen::Dynamic, 1>; // dynamic ad vector
using DM = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>; // dynamic matrix
using DV = Eigen::Matrix<double, Eigen::Dynamic, 1>;


Truss::Truss()
{
    v_joint_ptr.reserve(50);
    v_edge_ptr.reserve(100);
    v_force_ptr.reserve(50);

    symbol_table.add_variable("x",x_as_variable);
    my_expression.register_symbol_table(symbol_table);
    std::string str = "x";
    parser.compile(str,my_expression);
}

Truss::Truss(std::string file_name)
{
    v_joint_ptr.reserve(50);
    v_edge_ptr.reserve(100);
    v_force_ptr.reserve(50);
    load_truss(file_name);

    symbol_table.add_variable("x",x_as_variable);
    my_expression.register_symbol_table(symbol_table);
    std::string str = "x";
    parser.compile(str,my_expression);
}

Truss::~Truss()
{
    int n_joints = v_joint_ptr.size(), n_edges = v_edge_ptr.size(), n_forces = v_force_ptr.size();

    for(int i = 0; i < n_edges;i++){
        delete v_edge_ptr[i];
    }
    for(int i = 0; i < n_forces ; i++){
        delete v_force_ptr[i];
    }
    for(int i = 0; i < n_joints;i++){
        delete v_joint_ptr[i];
    }
}

void Truss::save_truss(std::string file_name)
{
    ofstream save_stream;
    save_stream.open(file_name);

    int n_joints = v_joint_ptr.size(), n_edges = v_edge_ptr.size(), n_forces = v_force_ptr.size();
    save_stream << n_joints << " " << n_edges << " " << n_forces << "\n";

    for(int i = 0; i < n_joints;i++){
        save_stream << v_joint_ptr[i]->get_p_x() << " " << v_joint_ptr[i]->get_p_y() << " " << v_joint_ptr[i]->get_support() << "\n";
    }

    for(int i = 0; i < n_edges;i++){
        int joint_index1 = v_edge_ptr[i]->get_joint_ptr1()->get_num();
        int joint_index2 = v_edge_ptr[i]->get_joint_ptr2()->get_num();
        save_stream << joint_index1 << " " << joint_index2  << "\n";
    }

    for(int i = 0; i < n_forces ; i++){
        int joint_index = v_force_ptr[i]->get_joint_ptr()->get_num();
        double xforce  = v_force_ptr[i]->get_xforce();
        double yforce  = v_force_ptr[i]->get_yforce();
        save_stream << joint_index << " " << xforce << " " << yforce << "\n";
    }

    save_stream.close();
}

void Truss::load_truss(std::string file_name)
{
    ifstream load_stream;
    load_stream.open(file_name);
    int n_joints, n_edges, n_forces;
    load_stream >> n_joints >> n_edges >> n_forces;
    v_joint_ptr.clear();
    v_edge_ptr.clear();
    v_force_ptr.clear();
    for(int i = 0; i < n_joints;i++){
        double x, y, support;
        load_stream >> x >> y >> support;
        Joint * new_joint = new Joint(i, x, y, support);
        v_joint_ptr.push_back(new_joint);
    }
    int joint_index1, joint_index2;
    for(int i = 0; i < n_edges;i++){
        load_stream >> joint_index1 >> joint_index2;
        Edge* new_edge = new Edge(v_joint_ptr[joint_index1], v_joint_ptr[joint_index2]);
        v_edge_ptr.push_back(new_edge);
    }

    int joint_index;
    double xforce, yforce;
    for(int i = 0; i < n_forces;i++){
        load_stream >> joint_index >> xforce >> yforce;
        Force* new_force = new Force(v_joint_ptr[joint_index],xforce,yforce);
        v_force_ptr.push_back(new_force);
    }
    load_stream.close();
}


void Truss::addJoint(double px, double py, bool psupport) {

    int num = v_joint_ptr.size();
    Joint * new_joint = new Joint(num, px, py, psupport);
    v_joint_ptr.push_back(new_joint);

}

void Truss::deleteJoint(int num)
{
    delete v_joint_ptr[num];
    v_joint_ptr.erase(v_joint_ptr.begin()+num);
    int n_joints = v_joint_ptr.size();
    for(int i = num; i < n_joints; i++){
        v_joint_ptr[i]->set_num(i);
        v_joint_ptr[i]->update();
    }
}

void Truss::addEdge(int num1, int num2)
{
    Edge* new_edge = new Edge(v_joint_ptr[num1], v_joint_ptr[num2]);
    v_edge_ptr.push_back(new_edge);
}

void Truss::deleteEdge(int num1, int num2)
{
    vector<Edge*> v_edges1 = v_joint_ptr[num1]->get_edges();
    int target = 0;
    for(int i  = 0;i<v_edges1.size();i++){
        if (v_edges1[i]->get_joint_ptr1()->get_num() == num2 ||  v_edges1[i]->get_joint_ptr2()->get_num() == num2){
            target = i;
            break;
        }
    }
    Edge* target_edge = v_edges1[target];
    v_joint_ptr[num1]->remove_edge(target_edge);
    v_joint_ptr[num2]->remove_edge(target_edge);
    for(int i = 0;i<v_edge_ptr.size();i++){
        if (v_edge_ptr[i] == target_edge){
            delete v_edge_ptr[i];
            v_edge_ptr.erase(v_edge_ptr.begin()+i);
        }
    }
}

void Truss::addForce(double fx, double fy, int num)
{
    Force* temp_force = new Force(v_joint_ptr[num],fx,fy);
    v_force_ptr.push_back(temp_force);
}

void Truss::deleteForce(int force_num)
{
    delete v_force_ptr[force_num];
    v_force_ptr.erase(v_force_ptr.begin() + force_num);
}

void Truss::set_emodule(double e)
{
    e_module = e;
}

void Truss::set_thickness(double A)
{
    thickness = A;
}

void Truss::solve_linear()
{
     int uLength = 2*v_joint_ptr.size();

            Eigen::MatrixXd F(uLength,1);//U
            for(int i=0;i<uLength;i++){
                F(i,0)=0;
            }

            Eigen::MatrixXd K(uLength,uLength);//K
            for(int i=0;i<uLength;i++){
                for(int j=0;j<uLength;j++){
                    K(i,j)=0;
                }
            }

            Eigen::MatrixXd U(uLength,1);//
            for(int i=0;i<uLength;i++){
                U(i,0)=0;
            }



            for(int i=0;i<v_edge_ptr.size();i++){//

                Eigen::MatrixXd EM(4,4);//

                double Ax,Ay,Bx,By;//
                Ax=v_edge_ptr[i]->get_joint_ptr1()->get_p_x(); Ay=v_edge_ptr[i]->get_joint_ptr1()->get_p_y();
                Bx=v_edge_ptr[i]->get_joint_ptr2()->get_p_x(); By=v_edge_ptr[i]->get_joint_ptr2()->get_p_y();

                double L0 = sqrt(pow(Bx-Ax,2)+pow(By-Ay,2));
                double ls = (Bx-Ax)/L0;
                double ms = (By-Ay)/L0;
                double P  = (e_module * thickness)/L0;

                Eigen::MatrixXd K_small(4,4);

                double K1=pow(ls,2);
                double K2=ls*ms;
                double K3=pow(ms,2);

                K_small(0,0)=K1; K_small(0,1)=K2;     K_small(0,2)=(-1)*K1; K_small(0,3)=(-1)*K2;
                K_small(1,0)=K2; K_small(1,1)=K3;     K_small(1,2)=(-1)*K2; K_small(1,3)=(-1)*K3;
                K_small(2,0)=(-1)*K1; K_small(2,1)=(-1)*K2;     K_small(2,2)=K1; K_small(2,3)=K2;
                K_small(3,0)=(-1)*K2; K_small(3,1)=(-1)*K3;     K_small(3,2)=K2; K_small(3,3)=K3;

                EM=K_small*P;//

                //两个点的序号
                int Xi = v_edge_ptr[i]->get_joint_ptr1()->get_num();
                int Yi = v_edge_ptr[i]->get_joint_ptr2()->get_num();

                //把EM阵里的数据加到K阵里
                //左上四个
                K(2*Xi,2*Xi)=K(2*Xi,2*Xi)+EM(0,0);
                K(2*Xi+1,2*Xi)=K(2*Xi+1,2*Xi)+EM(1,0);
                K(2*Xi,2*Xi+1)=K(2*Xi,2*Xi+1)+EM(0,1);
                K(2*Xi+1,2*Xi+1)=K(2*Xi+1,2*Xi+1)+EM(1,1);
                //右下四个
                K(2*Yi,2*Yi)=K(2*Yi,2*Yi)+EM(2,2);
                K(2*Yi+1,2*Yi)=K(2*Yi+1,2*Yi)+EM(3,2);
                K(2*Yi,2*Yi+1)=K(2*Yi,2*Yi+1)+EM(2,3);
                K(2*Yi+1,2*Yi+1)=K(2*Yi+1,2*Yi+1)+EM(3,3);
                //右上
                K(2*Xi,2*Yi)=K(2*Xi,2*Yi)+EM(0,2);
                K(2*Xi+1,2*Yi)=K(2*Xi+1,2*Yi)+EM(1,2);
                K(2*Xi,2*Yi+1)=K(2*Xi,2*Yi+1)+EM(0,3);
                K(2*Xi+1,2*Yi+1)=K(2*Xi+1,2*Yi+1)+EM(1,3);
                //左下
                K(2*Yi,2*Xi)= K(2*Yi,2*Xi)+EM(0,2);
                K(2*Yi+1,2*Xi)= K(2*Yi+1,2*Xi)+EM(1,2);
                K(2*Yi,2*Xi+1)= K(2*Yi,2*Xi+1)+EM(0,3);
                K(2*Yi+1,2*Xi+1)= K(2*Yi+1,2*Xi+1)+EM(1,3);

            }


            //standpoint修改K阵   和   F向量叠加
                for(int i=0;i<v_joint_ptr.size();i++){

                    int a=v_joint_ptr[i]->get_num();

                    if( v_joint_ptr[i]->get_support() ){

                        for(int j=0;j<2*v_joint_ptr.size();j++){

                            K(2*a,j)=0;K(2*a+1,j)=0;
                            K(j,2*a)=0;K(j,2*a+1)=0;

                        }

                        K(2*a,2*a)=1;
                        K(2*a+1,2*a+1)=1;
                        F(2*a,0)=0;
                        F(2*a+1,0)=0;

                    }
                    else{
                        for(int j=0;j<v_force_ptr.size();j++){
                            if(v_force_ptr[j]->get_joint_ptr()->get_num() == a){
                                F(2*a,0) = v_force_ptr[j]->get_xforce();
                                F(2*a+1,0) = v_force_ptr[j]->get_yforce();
                            }
                        }
                    }



                }

        //Ku=F 解u
            U=K.colPivHouseholderQr().solve(F);


        //代回各个点的新位置
            for(int i=0;i<v_joint_ptr.size();i++){

                int a=v_joint_ptr[i]->get_num();

                v_joint_ptr[i]->set_newp_x(v_joint_ptr[i]->get_p_x()+U(2*a,0));
                v_joint_ptr[i]->set_newp_y(v_joint_ptr[i]->get_p_y()+U(2*a+1,0));


            }
}

void Truss::solve_nonlinear()
{

     parser.compile(input_expression,my_expression);



    Eigen::Matrix<double,Eigen::Dynamic,1> u(v_joint_ptr.size()*2);

        int v_size = u.size();
        u = DM::Zero(v_size,1);
        DV delta_u = DV::Zero(v_size,1);
        DV R= DV::Zero(v_size,1);
        DM JR= DM::Zero(v_size,v_size);
        double norm = 0;

        int k=0;
        do{
            calc_Residuum(R,JR,u);

            delta_u = JR.llt().solve(-R);
            norm = delta_u.norm();
            //std::cout<<norm;
            u += delta_u;
            k++;

       } while(norm > 0.000001 && k<=1000);


        

        //put result back to new variable
        for(int i=0;i<v_joint_ptr.size();i++){

                    int a=v_joint_ptr[i]->get_num();

                    v_joint_ptr[i]->set_newp_x(v_joint_ptr[i]->get_p_x()+u(2*a,0));
                    v_joint_ptr[i]->set_newp_y(v_joint_ptr[i]->get_p_y()+u(2*a+1,0));

                }
}

void Truss::calc_Residuum(DV& Origi_R, DM& JR, const DV& Origi_u){

    int v_size = V_u.size();
    ADDM K = ADDM::Zero(v_size,v_size);
    ADDV F = ADDV::Zero(v_size,1);
    ADDV u = ADDM::Zero(v_size,1);
    ADDV R = ADDM::Zero(v_size,1);

    DM test_k = DM::Zero(v_size,v_size);

    for(int i=0;i<v_size;i++){
      ad::value(u(i)) = Origi_u(i);
      }


    for(int i = 0; i < v_size; i++)
      {

        ad::derivative(u(i)) = 1.0;
        assemble(K,u,F);
        //std::cout<<K;
        //std::cout<<u;
        //std::cout<<F;

        R = K*u-F;


        for(int j=0; j < v_size; j++){
            JR(j,i) = ad::derivative(R(j));
          }

        ad::derivative(u(i)) = 0;

        for(int m=0;m<v_size;m++){
            for(int n=0;n<v_size;n++){
              test_k(m,n) = ad::value(K(m,n)) ;
              }
          }

        K = ADDM::Zero(v_size,v_size);
      }

    //Update R
    for(int i=0;i<v_size;i++){
      Origi_R(i) = ad::value(R(i));
      }

}


void Truss::assemble(
    Eigen::Matrix<ad::tangent_t<double>, Eigen::Dynamic, Eigen::Dynamic>& K,
    Eigen::Matrix<ad::tangent_t<double>, Eigen::Dynamic, 1>& u,
    Eigen::Matrix<ad::tangent_t<double>, Eigen::Dynamic, 1>& F)
{

    int n_joints = v_joint_ptr.size();
    int n_edges = v_edge_ptr.size();
    int n_forces = v_force_ptr.size();

    //stiffness Matrix K
    for(int i=0;i<n_edges;i++){
        Eigen::Matrix<ad::tangent_t<double>,2,2> partial_K = calc_partial_K(v_edge_ptr[i],u);
        int index1 = v_edge_ptr[i]->get_joint_ptr1()->get_num();
        int index2 = v_edge_ptr[i]->get_joint_ptr2()->get_num();
        K.block(2*index1,2*index1,2,2) += partial_K;
        K.block(2*index1,2*index2,2,2) -= partial_K;
        K.block(2*index2,2*index1,2,2) -= partial_K;
        K.block(2*index2,2*index2,2,2) += partial_K;
    }

//    force vector
    for(int i = 0; i < n_forces;i++){
            int joint_index = v_force_ptr[i]->get_joint_ptr()->get_num();
            ad::value(F(2*joint_index) )  = v_force_ptr[i]->get_xforce();
            ad::value(F(2*joint_index+1)) = v_force_ptr[i]->get_yforce();
    }

    //K with support effect
    for(int i=0;i<n_joints;i++){
        bool support = v_joint_ptr[i]->get_support();

        if(support == true ){
                K.block(2*i,2*i,2,2) = Eigen::Matrix<ad::tangent_t<double>,2,2>::Identity();////////////////////////
                K.block(0,2*i,2*i,2) = ADDM::Zero(2*i,2);
                K.block(2*(i+1),2*i,2*(n_joints-i-1),2) = ADDM::Zero(2*(n_joints-i-1),2);
                K.block(2*i,0,2,2*i) = ADDM::Zero(2,2*i);
                K.block(2*i,2*(i+1),2,2*(n_joints-i-1)) = ADDM::Zero(2,2*(n_joints-i-1));

                ad::value(F(2*i)) = 0.0;
                ad::value(F(2*i+1)) = 0.0;

        }
    }


   //standpoint修改K阵   和   F向量叠加
        // for(int i=0;i<v_joint_ptr.size();i++){

        //     int a=v_joint_ptr[i]->get_num();

        //     if( v_joint_ptr[i]->get_support() ){

        //         for(int j=0;j<2*v_joint_ptr.size();j++){

        //             K(2*a,j)=0.0;K(2*a+1,j)=0.0;
        //             K(j,2*a)=0.0;K(j,2*a+1)=0.0;

        //         }

        //         K(2*a,2*a)=1.0;
        //         K(2*a+1,2*a+1)=1.0;
        //         F(2*a,0)=0.0;
        //         F(2*a+1,0)=0.0;

        //     }
        //     else{
        //         for(int j=0;j<v_force_ptr.size();j++){
        //             if(v_force_ptr[j]->get_joint_ptr()->get_num() == a){
        //                 F(2*a,0) = v_force_ptr[j]->get_xforce();
        //                 F(2*a+1,0) = v_force_ptr[j]->get_yforce();
        //             }
        //         }
        //     }
        // }
}


Eigen::Matrix<ad::tangent_t<double>,2,2> Truss::calc_partial_K(Edge* edge_ptr, Eigen::Matrix<ad::tangent_t<double>,Eigen::Dynamic,1>& u){
  
  ad::tangent_t<double> x1,nx1,x2,nx2,y1,ny1,y2,ny2,delta_L,old_L,new_L,b,h,A,E,coeff; //l=kantenlaenge, b=breite, h=hoehe

    x1 = edge_ptr->get_joint_ptr1()->x();
    x2 = edge_ptr->get_joint_ptr2()->x();
    y1 = edge_ptr->get_joint_ptr1()->y();
    y2 = edge_ptr->get_joint_ptr2()->y();
    A  = thickness;


    int ind1 = edge_ptr->get_joint_ptr1()->get_num();
    int ind2 = edge_ptr->get_joint_ptr2()->get_num();

    nx1 = u(2*ind1) + x1;
    nx2 = u(2*ind2) + x2;
    ny1 = u(2*ind1+1) + y1;
    ny2 = u(2*ind2+1) + y2;

    old_L = sqrt( pow(x1-x2,2) + pow(y1-y2,2));
    new_L = sqrt( pow(nx1-nx2,2) + pow(ny1-ny2,2));

    delta_L = new_L - old_L;
    b = (x2-x1)/old_L;
    h = (y2-y1)/old_L;

    double E_val,E_A = 1,delta_L_value,fool;
    delta_L_value = ad::value(delta_L);

    custom_function(delta_L_value,E_val);


    E = delta_L*E_A;
    fool = delta_L_value*E_A;
    E  += E_val - fool;

    coeff = (E*A)/old_L;

    Eigen::Matrix<ad::tangent_t<double>,2,2> partial_K;
    partial_K(0,0) = pow(b,2);
    partial_K(1,0) = b*h;
    partial_K(0,1) = b*h;
    partial_K(1,1) = pow(h,2);
    return partial_K*coeff;
}

void Truss::custom_function(double& delta_L_value,double& E){
    x_as_variable = delta_L_value;
    E = my_expression.value();
}


