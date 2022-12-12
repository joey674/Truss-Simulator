#ifndef TRUSS_H
#define TRUSS_H

#include <vector>
#include <Eigen/Dense>
#include  "exprtk.hpp"
#include <string>
#include "ad.hpp"



class Joint;
class Edge;
class Force;

using ADDM = Eigen::Matrix<ad::tangent_t<double>, Eigen::Dynamic, Eigen::Dynamic>; // dynamic ad matrix
using ADDV = Eigen::Matrix<ad::tangent_t<double>, Eigen::Dynamic, 1>; // dynamic ad vector
using DM = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>; // dynamic matrix
using DV = Eigen::Matrix<double, Eigen::Dynamic, 1>;



class Truss
{
public:
    Truss();
    Truss(std::string file_name);
    ~Truss();

    void save_truss(std::string file_name);
    void load_truss(std::string file_name);

    void addJoint(double P_x, double P_y, bool status_if_support);
    void deleteJoint(int num);

    void addEdge(int num1,int num2);
    void deleteEdge(int num1,int num2);

    void addForce(double fx, double fy, int num);
    void deleteForce(int force_num);

    void set_emodule(double e);

    void set_thickness(double A);


    void solve_linear();
    void solve_nonlinear();


    std::vector<Joint* > v_joint_ptr;
    std::vector<Edge* > v_edge_ptr;
    std::vector<Force* > v_force_ptr;


    double e_module;
    bool status_if_linear;
    double thickness;
    std::string input_expression;

    void calc_Residuum( DV& V_R, DM& JR, const DV& V_u); 
    void assemble(
        Eigen::Matrix<ad::tangent_t<double>, Eigen::Dynamic, Eigen::Dynamic>& K,
        Eigen::Matrix<ad::tangent_t<double>, Eigen::Dynamic, 1>& u,
        Eigen::Matrix<ad::tangent_t<double>, Eigen::Dynamic, 1>& F);
    Eigen::Matrix<ad::tangent_t<double>,2,2> calc_partial_K(Edge* edge_ptr, Eigen::Matrix<ad::tangent_t<double>,Eigen::Dynamic,1>& u);
    void custom_function(double& delta_L_value,double& E);


    //exprtk part
    exprtk::symbol_table<double> symbol_table;
    exprtk::expression<double>my_expression;
    exprtk::parser<double>parser;
    double x_as_variable;
 };

#endif // TRUSS_H
