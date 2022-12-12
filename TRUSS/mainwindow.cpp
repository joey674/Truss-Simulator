#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsItem"
#include "joint.h"
#include "edge.h"
#include "force.h"
#include "truss.h"
#include "QFileDialog"
#include <QMessageBox>
#include <QValidator>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setCursor(Qt::CrossCursor);
    ui->graphicsView->setMouseTracking(true);
    ui->addJoint_Button->setEnabled(false);
    ui->deleteJoint_Button->setEnabled(false);
    ui->addForce_Button->setEnabled(false);
    ui->deleteForce_Button->setEnabled(false);
    ui->RodConnect_Button->setEnabled(false);
    ui->RodSeparate_Button->setEnabled(false);
    ui->initialize_Button->setEnabled(false);
    ui->E_input->setEnabled(false);
    ui->A_input->setEnabled(false);
    ui->joint_x_input->setEnabled(false);
    ui->joint_y_input->setEnabled(false);
    ui->force_x_input->setEnabled(false);
    ui->force_y_input->setEnabled(false);
    ui->Fx_input->setEnabled(false);
    ui->Fy_input->setEnabled(false);
    ui->rod_x1_input->setEnabled(false);
    ui->rod_x2_input->setEnabled(false);
    ui->rod_y1_input->setEnabled(false);
    ui->rod_y2_input->setEnabled(false);
    ui->simulate_Button->setEnabled(false);
    ui->compare_Button->setEnabled(false);

    ui->joint_x_input->setValidator(new QIntValidator(0,800,this));
    ui->joint_y_input->setValidator(new QIntValidator(0,800,this));
    ui->force_x_input->setValidator(new QIntValidator(0,800,this));
    ui->force_y_input->setValidator(new QIntValidator(0,800,this));
    ui->rod_x1_input->setValidator(new QIntValidator(0,800,this));
    ui->rod_x2_input->setValidator(new QIntValidator(0,800,this));
    ui->rod_y1_input->setValidator(new QIntValidator(0,800,this));
    ui->rod_y2_input->setValidator(new QIntValidator(0,800,this));

    QRegExp regx("[0-9\\-]+$");
    QValidator *validator = new QRegExpValidator(regx);
    ui->Fx_input->setValidator(validator);
    ui->Fy_input->setValidator(validator);



    QGraphicsLineItem *line1 = new QGraphicsLineItem;
    QGraphicsLineItem *line2 = new QGraphicsLineItem;
    QGraphicsLineItem *line3 = new QGraphicsLineItem;
    QGraphicsLineItem *line4 = new QGraphicsLineItem;
    QGraphicsLineItem *line5 = new QGraphicsLineItem;
    QGraphicsLineItem *line6 = new QGraphicsLineItem;
    line1->setLine(-380,-380,-380,-330);
    line2->setLine(-380,-380,-330,-380);
    line3->setLine(-380,-330,-385,-335);
    line4->setLine(-380,-330,-375,-335);
    line5->setLine(-330,-380,-335,-385);
    line6->setLine(-330,-380,-335,-375);
    ui->graphicsView->scene->addItem(line1);
    ui->graphicsView->scene->addItem(line2);
    ui->graphicsView->scene->addItem(line3);
    ui->graphicsView->scene->addItem(line4);
    ui->graphicsView->scene->addItem(line5);
    ui->graphicsView->scene->addItem(line6);


    connect(ui->graphicsView,SIGNAL(mouseMoveSignal(QPoint)),this,SLOT(on_mouseMoveSignal(QPoint)));
    connect(ui->graphicsView,SIGNAL(JointSignal(int)),this,SLOT(on_JointSignal(int)));
    connect(ui->graphicsView,SIGNAL(EdgeSignal(int)),this,SLOT(on_EdgeSignal(int)));
    connect(ui->graphicsView,SIGNAL(ForceSignal(int)),this,SLOT(on_ForceSignal(int)));
    connect(ui->graphicsView,SIGNAL(noItemSignal()),this,SLOT(on_noItemSignal()));
    connect(ui->graphicsView->scene->menu->actions()[0],SIGNAL(triggered()),this,SLOT(set_JointPosition()));
    connect(this,SIGNAL(addJointSignal()),this,SLOT(on_addJoint_Button_clicked()));
    connect(ui->graphicsView->scene->menu->actions()[1],SIGNAL(triggered()),this,SLOT(set_SupportPosition()));
    connect(this,SIGNAL(addSupportSignal()),this,SLOT(on_addJoint_Button_clicked()));
    connect(ui->graphicsView->scene->menu->actions()[2],SIGNAL(triggered()),this,SLOT(set_JointPosition2()));
    connect(this,SIGNAL(deleteJointSignal()),this,SLOT(on_deleteJoint_Button_clicked()));
    connect(ui->graphicsView,SIGNAL(selectedEdgeSignal(int)),this,SLOT(set_EdgeInformation(int)));
    connect(this,SIGNAL(deleteEdgeSignal()),this,SLOT(on_RodSeparate_Button_clicked()));
    connect(ui->graphicsView,SIGNAL(selectedForceSignal(int)),this,SLOT(set_ForceInformation(int)));
    connect(this,SIGNAL(deleteForceSignal()),this,SLOT(on_deleteForce_Button_clicked()));
    connect(ui->graphicsView,SIGNAL(selectedJointSignal(int,int)),this,SLOT(set_JointInformation(int,int)));
    connect(this,SIGNAL(addEdgeSignal()),this,SLOT(on_RodConnect_Button_clicked()));
    connect(ui->graphicsView->scene->menu->actions()[7],SIGNAL(triggered()),this,SLOT(set_Joint_of_Force()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_mouseMoveSignal(QPoint point)
{
    ui->currentCoordx->setText(QString::asprintf("X: %d",point.x()));
    ui->currentCoordy->setText(QString::asprintf("Y: %d",point.y()));
}


void MainWindow::on_joint_x_input_textChanged(const QString &arg1)
{
    if(ui->joint_x_input->text().isEmpty() || ui->joint_y_input->text().isEmpty()){
        ui->addJoint_Button->setEnabled(false);
        ui->deleteJoint_Button->setEnabled(false);
     }
    else{
        ui->addJoint_Button->setEnabled(true);
        ui->deleteJoint_Button->setEnabled(true);
    }
    Q_UNUSED(arg1);
}

void MainWindow::on_joint_y_input_textChanged(const QString &arg1)
{
    if(ui->joint_x_input->text().isEmpty() || ui->joint_y_input->text().isEmpty()){
        ui->addJoint_Button->setEnabled(false);
        ui->deleteJoint_Button->setEnabled(false);
    }
    else{
        ui->addJoint_Button->setEnabled(true);
        ui->deleteJoint_Button->setEnabled(true);
    }
    Q_UNUSED(arg1);
}

void MainWindow::on_rod_x1_input_textChanged(const QString &arg1)
{
    if(ui->rod_x1_input->text().isEmpty() || ui->rod_y1_input->text().isEmpty()|| ui->rod_x2_input->text().isEmpty()|| ui->rod_y2_input->text().isEmpty()){
        ui->RodConnect_Button->setEnabled(false);
        ui->RodSeparate_Button->setEnabled(false);
    }
    else{
        ui->RodConnect_Button->setEnabled(true);
        ui->RodSeparate_Button->setEnabled(true);
    }
    Q_UNUSED(arg1);
}

void MainWindow::on_rod_y1_input_textChanged(const QString &arg1)
{
    if(ui->rod_x1_input->text().isEmpty() || ui->rod_y1_input->text().isEmpty()|| ui->rod_x2_input->text().isEmpty()|| ui->rod_y2_input->text().isEmpty()){
        ui->RodConnect_Button->setEnabled(false);
        ui->RodSeparate_Button->setEnabled(false);
    }
    else{
        ui->RodConnect_Button->setEnabled(true);
        ui->RodSeparate_Button->setEnabled(true);
    }
    Q_UNUSED(arg1);
}

void MainWindow::on_rod_x2_input_textChanged(const QString &arg1)
{
    if(ui->rod_x1_input->text().isEmpty() || ui->rod_y1_input->text().isEmpty()|| ui->rod_x2_input->text().isEmpty()|| ui->rod_y2_input->text().isEmpty()){
        ui->RodConnect_Button->setEnabled(false);
        ui->RodSeparate_Button->setEnabled(false);
    }
    else{
        ui->RodConnect_Button->setEnabled(true);
        ui->RodSeparate_Button->setEnabled(true);
    }
    Q_UNUSED(arg1);
}

void MainWindow::on_rod_y2_input_textChanged(const QString &arg1)
{
    if(ui->rod_x1_input->text().isEmpty() || ui->rod_y1_input->text().isEmpty()|| ui->rod_x2_input->text().isEmpty()|| ui->rod_y2_input->text().isEmpty()){
        ui->RodConnect_Button->setEnabled(false);
        ui->RodSeparate_Button->setEnabled(false);
    }
    else{
        ui->RodConnect_Button->setEnabled(true);
        ui->RodSeparate_Button->setEnabled(true);
    }
    Q_UNUSED(arg1);
}

void MainWindow::on_Fx_input_textChanged(const QString &arg1)
{
    if(ui->Fx_input->text().isEmpty() || ui->Fy_input->text().isEmpty()|| ui->force_x_input->text().isEmpty()|| ui->force_y_input->text().isEmpty()){
        ui->addForce_Button->setEnabled(false);
    }
    else{
        ui->addForce_Button->setEnabled(true);
    }
    Q_UNUSED(arg1);
}

void MainWindow::on_Fy_input_textChanged(const QString &arg1)
{
    if(ui->Fx_input->text().isEmpty() || ui->Fy_input->text().isEmpty()|| ui->force_x_input->text().isEmpty()|| ui->force_y_input->text().isEmpty()){
        ui->addForce_Button->setEnabled(false);
    }
    else{
        ui->addForce_Button->setEnabled(true);
    }
    Q_UNUSED(arg1);
}

void MainWindow::on_force_x_input_textChanged(const QString &arg1)
{
    if(ui->Fx_input->text().isEmpty() || ui->Fy_input->text().isEmpty()|| ui->force_x_input->text().isEmpty()|| ui->force_y_input->text().isEmpty()){
        ui->addForce_Button->setEnabled(false);
    }
    else{
        ui->addForce_Button->setEnabled(true);
    }
    if(ui->force_x_input->text().isEmpty()|| ui->force_y_input->text().isEmpty()){
        ui->deleteForce_Button->setEnabled(false);
    }
    else{
        ui->deleteForce_Button->setEnabled(true);
    }
    Q_UNUSED(arg1);
}

void MainWindow::on_force_y_input_textChanged(const QString &arg1)
{
    if(ui->Fx_input->text().isEmpty() || ui->Fy_input->text().isEmpty()|| ui->force_x_input->text().isEmpty()|| ui->force_y_input->text().isEmpty()){
        ui->addForce_Button->setEnabled(false);
    }
    else{
        ui->addForce_Button->setEnabled(true);
    }
    if(ui->force_x_input->text().isEmpty()|| ui->force_y_input->text().isEmpty()){
        ui->deleteForce_Button->setEnabled(false);
    }
    else{
        ui->deleteForce_Button->setEnabled(true);
    }
    Q_UNUSED(arg1);
}

void MainWindow::on_E_input_textChanged(const QString &arg1)
{
    if(ui->E_input->text().isEmpty() || ui->A_input->text().isEmpty()){
        ui->initialize_Button->setEnabled(false);
    }
    else{
        ui->initialize_Button->setEnabled(true);
    }
    Q_UNUSED(arg1);
}

void MainWindow::on_A_input_textChanged(const QString &arg1)
{
    if(ui->E_input->text().isEmpty() || ui->A_input->text().isEmpty()){
        ui->initialize_Button->setEnabled(false);
    }
    else{
        ui->initialize_Button->setEnabled(true);
    }
    Q_UNUSED(arg1);
}

void MainWindow::on_addJoint_Button_clicked(){
    QString x = ui->joint_x_input->text();
    QString y = ui->joint_y_input->text();
    bool s = ui->if_support_button->isChecked();
    if (ui->graphicsView->currentTruss->v_joint_ptr.size() != 0){
        for (int i = ui->graphicsView->currentTruss->v_joint_ptr.size();i>0;i--){
            if(ui->graphicsView->currentTruss->v_joint_ptr[i-1]->get_p_x() == x.toDouble() && ui->graphicsView->currentTruss->v_joint_ptr[i-1]->get_p_y() == y.toDouble()){
            QMessageBox::critical(this,  "Warning",  "already a Joint in this position");
            return;
            }
        }
    }
    ui->graphicsView->currentTruss->addJoint(x.toDouble(),y.toDouble(),s);
    int p = ui->graphicsView->currentTruss->v_joint_ptr.size();
    ui->graphicsView->scene->addItem(ui->graphicsView->currentTruss->v_joint_ptr[p-1]);
    ui->joint_x_input->clear();
    ui->joint_y_input->clear();
}

void MainWindow::on_deleteJoint_Button_clicked()
{
    QString x = ui->joint_x_input->text();
    QString y = ui->joint_y_input->text();
    for (int p = ui->graphicsView->currentTruss->v_joint_ptr.size();p>0;p--){
        if (x.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_p_x() && y.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_p_y()){
            while(ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_edges().empty() == false){
                int pos1 = ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_edges()[0]->get_joint_ptr1()->get_num();
                int pos2 = ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_edges()[0]->get_joint_ptr2()->get_num();
                ui->graphicsView->scene->removeItem(ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_edges()[0]);
                ui->graphicsView->currentTruss->deleteEdge(pos1,pos2);
            }
            for (int n = 0;n < ui->graphicsView->currentTruss->v_force_ptr.size();n++){
                if(ui->graphicsView->currentTruss->v_force_ptr[n]->get_joint_ptr()->get_num() == p-1){
                    ui->graphicsView->scene->removeItem(ui->graphicsView->currentTruss->v_force_ptr[n]);
                    ui->graphicsView->currentTruss->deleteForce(n);
                }
            }
            ui->graphicsView->scene->removeItem(ui->graphicsView->currentTruss->v_joint_ptr[p-1]);
            ui->graphicsView->currentTruss->deleteJoint(p-1);
            ui->joint_x_input->clear();
            ui->joint_y_input->clear();
            break;
        }
    }
}

void MainWindow::on_new_Truss_triggered(){
    ui->E_input->setEnabled(true);
    ui->A_input->setEnabled(true);
    ui->if_nonlinear_Button->setEnabled(true);
    ui->joint_x_input->setEnabled(true);
    ui->joint_y_input->setEnabled(true);
    ui->force_x_input->setEnabled(true);
    ui->force_y_input->setEnabled(true);
    ui->Fx_input->setEnabled(true);
    ui->Fy_input->setEnabled(true);
    ui->rod_x1_input->setEnabled(true);
    ui->rod_x2_input->setEnabled(true);
    ui->rod_y1_input->setEnabled(true);
    ui->rod_y2_input->setEnabled(true);
    ui->simulate_Button->setEnabled(false);
    ui->compare_Button->setEnabled(false);
    if(ui->graphicsView->currentTruss == nullptr){
        ui->graphicsView->currentTruss = new Truss();
    }
    else{
        int n_joints = ui->graphicsView->currentTruss->v_joint_ptr.size();
        int n_edges = ui->graphicsView->currentTruss->v_edge_ptr.size();
        int n_forces = ui->graphicsView->currentTruss->v_force_ptr.size();
        for(int i=0; i < n_joints; i++){
            ui->graphicsView->scene->removeItem(ui->graphicsView->currentTruss->v_joint_ptr[i]);
        }
        for(int i=0; i < n_edges; i++){
            ui->graphicsView->scene->removeItem(ui->graphicsView->currentTruss->v_edge_ptr[i]);
        }
        for(int i=0; i < n_forces; i++){
            ui->graphicsView->scene->removeItem(ui->graphicsView->currentTruss->v_force_ptr[i]);
        }
        ui->graphicsView->currentTruss = new Truss();
    }
    if(ui->graphicsView->deformedTruss != nullptr){
        int n_joints = ui->graphicsView->deformedTruss->v_joint_ptr.size();
        int n_edges = ui->graphicsView->deformedTruss->v_edge_ptr.size();
        for(int i=0; i < n_joints; i++){
            ui->graphicsView->scene->removeItem(ui->graphicsView->deformedTruss->v_joint_ptr[i]);
        }
        for(int i=0; i < n_edges; i++){
            ui->graphicsView->scene->removeItem(ui->graphicsView->deformedTruss->v_edge_ptr[i]);
        }
        ui->graphicsView->deformedTruss = nullptr;
    }
}

void MainWindow::on_save_Truss_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, tr("save Truss"), "new_truss.txt", tr("Truss (*.txt)"));
    if(file_name == ""){return;}
    ui->graphicsView->currentTruss->save_truss(file_name.toStdString());
}

void MainWindow::on_load_Truss_triggered()
{
    QString file_name;
    file_name = QFileDialog::getOpenFileName(this,tr("load Truss"), "",tr("Truss (*.txt);;All Files (*)"));
    std::string std_file_name = file_name.toStdString();
    if(std_file_name == ""){return;}
    ui->E_input->setEnabled(true);
    ui->A_input->setEnabled(true);
    ui->if_nonlinear_Button->setEnabled(true);
    ui->joint_x_input->setEnabled(true);
    ui->joint_y_input->setEnabled(true);
    ui->force_x_input->setEnabled(true);
    ui->force_y_input->setEnabled(true);
    ui->Fx_input->setEnabled(true);
    ui->Fy_input->setEnabled(true);
    ui->rod_x1_input->setEnabled(true);
    ui->rod_x2_input->setEnabled(true);
    ui->rod_y1_input->setEnabled(true);
    ui->rod_y2_input->setEnabled(true);
    ui->compare_Button->setEnabled(false);
    int n_joints,n_edges,n_forces;
    if(ui->graphicsView->currentTruss == nullptr){
        ui->graphicsView->currentTruss = new Truss(std_file_name);
    }
    else{
        n_joints = ui->graphicsView->currentTruss->v_joint_ptr.size();
        n_edges = ui->graphicsView->currentTruss->v_edge_ptr.size();
        n_forces = ui->graphicsView->currentTruss->v_force_ptr.size();
        for(int i=0; i < n_joints; i++){
            ui->graphicsView->scene->removeItem(ui->graphicsView->currentTruss->v_joint_ptr[i]);
        }
        for(int i=0; i < n_edges; i++){
            ui->graphicsView->scene->removeItem(ui->graphicsView->currentTruss->v_edge_ptr[i]);
        }
        for(int i=0; i < n_forces; i++){
            ui->graphicsView->scene->removeItem(ui->graphicsView->currentTruss->v_force_ptr[i]);
        }
        ui->graphicsView->currentTruss = new Truss(std_file_name);
    }
    n_joints = ui->graphicsView->currentTruss->v_joint_ptr.size();
    n_edges = ui->graphicsView->currentTruss->v_edge_ptr.size();
    n_forces = ui->graphicsView->currentTruss->v_force_ptr.size();
    for(int i=0; i < n_joints; i++){
        ui->graphicsView->scene->addItem(ui->graphicsView->currentTruss->v_joint_ptr[i]);
    }
    for(int i=0; i < n_edges; i++){
        ui->graphicsView->scene->addItem(ui->graphicsView->currentTruss->v_edge_ptr[i]);
    }
    for(int i=0; i < n_forces; i++){
        ui->graphicsView->scene->addItem(ui->graphicsView->currentTruss->v_force_ptr[i]);
    }
    if(ui->graphicsView->deformedTruss != nullptr){
        int n_joints = ui->graphicsView->deformedTruss->v_joint_ptr.size();
        int n_edges = ui->graphicsView->deformedTruss->v_edge_ptr.size();
        for(int i=0; i < n_joints; i++){
            ui->graphicsView->scene->removeItem(ui->graphicsView->deformedTruss->v_joint_ptr[i]);
        }
        for(int i=0; i < n_edges; i++){
            ui->graphicsView->scene->removeItem(ui->graphicsView->deformedTruss->v_edge_ptr[i]);
        }
        ui->graphicsView->deformedTruss = nullptr;
    }
}

void MainWindow::on_save_as_image_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("save image"), "truss.png", tr("image (*.png)"));
    if (!fileName.isNull()){
        QPixmap pixMap = this->ui->graphicsView->grab();
        pixMap.save(fileName);
    }
}

void MainWindow::on_RodConnect_Button_clicked()
{
    QString x1 = ui->rod_x1_input->text();
    QString y1 = ui->rod_y1_input->text();
    QString x2 = ui->rod_x2_input->text();
    QString y2 = ui->rod_y2_input->text();
    for (int p = ui->graphicsView->currentTruss->v_joint_ptr.size();p>0;p--){
        if (x1.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_p_x() && y1.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_p_y()){
            for (int q = ui->graphicsView->currentTruss->v_joint_ptr.size();q>0;q--){
                if (x2.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[q-1]->get_p_x() && y2.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[q-1]->get_p_y()){
                    if (ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_edges().size() != 0){
                        vector<Edge*> v_edges1 = ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_edges();
                        for (int m = 0;m < ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_edges().size();m++) {
                            if(v_edges1[m]->get_joint_ptr1()->get_num() == q-1 || v_edges1[m]->get_joint_ptr2()->get_num() == q-1 ){
                                QMessageBox::critical(this,  "Warning",  "already connected");
                                return;
                            }
                        }
                    }
                    ui->graphicsView->currentTruss->addEdge(p-1,q-1);
                    int n = ui->graphicsView->currentTruss->v_edge_ptr.size();
                    ui->graphicsView->scene->addItem(ui->graphicsView->currentTruss->v_edge_ptr[n-1]);
                }
            }
        }
    }
}

void MainWindow::on_RodSeparate_Button_clicked()
{
    QString x1 = ui->rod_x1_input->text();
    QString y1 = ui->rod_y1_input->text();
    QString x2 = ui->rod_x2_input->text();
    QString y2 = ui->rod_y2_input->text();
    for (int p = ui->graphicsView->currentTruss->v_joint_ptr.size();p>0;p--){
        if (x1.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_p_x() && y1.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_p_y()){
            for (int q = ui->graphicsView->currentTruss->v_joint_ptr.size();q>0;q--){
                if (x2.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[q-1]->get_p_x() && y2.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[q-1]->get_p_y()){
                    vector<Edge*> v_edges1 = ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_edges();
                    int target = 0;
                    for(int i  = 0;i<v_edges1.size();i++){
                        if (v_edges1[i]->get_joint_ptr1()->get_num() == q-1 ||  v_edges1[i]->get_joint_ptr2()->get_num() == q-1){
                            target = i;
                            Edge* target_edge = v_edges1[target];
                            for(int i = 0;i<ui->graphicsView->currentTruss->v_edge_ptr.size();i++){
                                if (ui->graphicsView->currentTruss->v_edge_ptr[i] == target_edge){
                                    ui->graphicsView->scene->removeItem(ui->graphicsView->currentTruss->v_edge_ptr[i]);
                                    ui->graphicsView->currentTruss->deleteEdge(p-1,q-1);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::on_addForce_Button_clicked()
{
    QString x = ui->force_x_input->text();
    QString y = ui->force_y_input->text();
    QString fx = ui->Fx_input->text();
    QString fy = ui->Fy_input->text();
    for (int p = ui->graphicsView->currentTruss->v_joint_ptr.size();p>0;p--){
        if (x.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_p_x() && y.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_p_y()){
            if(ui->graphicsView->currentTruss->v_force_ptr.size() != 0){
                for (int n = 0;n < ui->graphicsView->currentTruss->v_force_ptr.size();n++){
                    if(ui->graphicsView->currentTruss->v_force_ptr[n]->get_joint_ptr()->get_num() == p-1){
                        QMessageBox::critical(this,  "Warning",  "already a force in this position");
                        return;
                    }
                }
            }
            ui->graphicsView->currentTruss->addForce(fx.toDouble(),fy.toDouble(),p-1);
            int a = ui->graphicsView->currentTruss->v_force_ptr.size();
            ui->graphicsView->scene->addItem(ui->graphicsView->currentTruss->v_force_ptr[a-1]);
            ui->force_x_input->clear();
            ui->force_y_input->clear();
            ui->Fx_input->clear();
            ui->Fy_input->clear();
        }
    }
}

void MainWindow::on_deleteForce_Button_clicked()
{
    QString x = ui->force_x_input->text();
    QString y = ui->force_y_input->text();
    for (int p = ui->graphicsView->currentTruss->v_joint_ptr.size();p>0;p--){
        if (x.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_p_x() && y.toDouble() == ui->graphicsView->currentTruss->v_joint_ptr[p-1]->get_p_y()){
            if(ui->graphicsView->currentTruss->v_force_ptr.size() != 0){
                for (int n = 0;n < ui->graphicsView->currentTruss->v_force_ptr.size();n++){
                    if(ui->graphicsView->currentTruss->v_force_ptr[n]->get_joint_ptr()->get_num() == p-1){
                        ui->graphicsView->scene->removeItem(ui->graphicsView->currentTruss->v_force_ptr[n]);
                        ui->graphicsView->currentTruss->deleteForce(n);
                        ui->force_x_input->clear();
                        ui->force_y_input->clear();
                        ui->Fx_input->clear();
                        ui->Fy_input->clear();
                    }
                }
            }
        }
    }
}

void MainWindow::on_initialize_Button_clicked()
{
    QString x = ui->A_input->text();
    QString y = ui->E_input->text();
    bool ok1,ok2;
    y.toDouble(&ok1);
    x.toDouble(&ok2);
    if(((!ok1) && ui->if_nonlinear_Button->isChecked() == false) || (!ok2)){
        QMessageBox::critical(this,  "Warning",  "invalid input");
        return;
    }
    if(ui->if_nonlinear_Button->isChecked() == false){    
        ui->graphicsView->currentTruss->set_emodule(y.toDouble());
        ui->graphicsView->currentTruss->set_thickness(x.toDouble());
        ui->A_input->clear();
        ui->E_input->clear();
        QMessageBox::information(this,  "Warning",  "successfully initialized");
        ui->simulate_Button->setEnabled(true);
        ui->if_nonlinear_Button->setEnabled(false);
    }
    else{
        ui->graphicsView->currentTruss->input_expression = ui->E_input->text().toStdString();
        ui->graphicsView->currentTruss->set_thickness(x.toDouble());
        ui->A_input->clear();
        ui->E_input->clear();
        QMessageBox::information(this,  "Warning",  "successfully initialized");
        ui->simulate_Button->setEnabled(true);
        ui->if_nonlinear_Button->setEnabled(false);
    }
}

void MainWindow::on_simulate_Button_clicked()
{
    if(ui->if_nonlinear_Button->isChecked() == false){
            ui->graphicsView->currentTruss->solve_linear();
    }
    else{
        ui->graphicsView->currentTruss->solve_nonlinear();
    }
    ui->graphicsView->deformedTruss = new Truss();
    for (int i = 0;i < ui->graphicsView->currentTruss->v_joint_ptr.size();i++){
        ui->graphicsView->deformedTruss->addJoint(ui->graphicsView->currentTruss->v_joint_ptr[i]->get_newp_x(),ui->graphicsView->currentTruss->v_joint_ptr[i]->get_newp_y(),ui->graphicsView->currentTruss->v_joint_ptr[i]->get_support());
        int p = ui->graphicsView->deformedTruss->v_joint_ptr.size();
        ui->graphicsView->scene->addItem(ui->graphicsView->deformedTruss->v_joint_ptr[p-1]);
        ui->graphicsView->currentTruss->v_joint_ptr[i]->setVisible(false);
    }
    for (int i = 0;i < ui->graphicsView->currentTruss->v_edge_ptr.size();i++){
        ui->graphicsView->deformedTruss->addEdge(ui->graphicsView->currentTruss->v_edge_ptr[i]->get_joint_ptr1()->get_num(),ui->graphicsView->currentTruss->v_edge_ptr[i]->get_joint_ptr2()->get_num());
        int p = ui->graphicsView->deformedTruss->v_edge_ptr.size();
        ui->graphicsView->scene->addItem(ui->graphicsView->deformedTruss->v_edge_ptr[p-1]);
        ui->graphicsView->currentTruss->v_edge_ptr[i]->setVisible(false);
    }
    for (int i = 0;i < ui->graphicsView->currentTruss->v_force_ptr.size();i++){
        ui->graphicsView->currentTruss->v_force_ptr[i]->setVisible(false);
    }
    ui->compare_Button->setEnabled(true);
    ui->simulate_Button->setEnabled(false);
    ui->E_input->setEnabled(false);
    ui->A_input->setEnabled(false);
    ui->joint_x_input->setEnabled(false);
    ui->joint_y_input->setEnabled(false);
    ui->force_x_input->setEnabled(false);
    ui->force_y_input->setEnabled(false);
    ui->Fx_input->setEnabled(false);
    ui->Fy_input->setEnabled(false);
    ui->rod_x1_input->setEnabled(false);
    ui->rod_x2_input->setEnabled(false);
    ui->rod_y1_input->setEnabled(false);
    ui->rod_y2_input->setEnabled(false);
    ui->RodConnect_Button->setEnabled(false);
    ui->RodSeparate_Button->setEnabled(false);
}

void MainWindow::on_compare_Button_pressed()
{
    for (int i = 0;i < ui->graphicsView->currentTruss->v_joint_ptr.size();i++){
        ui->graphicsView->deformedTruss->v_joint_ptr[i]->setVisible(false);
        ui->graphicsView->currentTruss->v_joint_ptr[i]->setVisible(true);
    }
    for (int i = 0;i < ui->graphicsView->currentTruss->v_edge_ptr.size();i++){
        ui->graphicsView->deformedTruss->v_edge_ptr[i]->setVisible(false);
        ui->graphicsView->currentTruss->v_edge_ptr[i]->setVisible(true);
    }
    for (int i = 0;i < ui->graphicsView->currentTruss->v_force_ptr.size();i++){
        ui->graphicsView->currentTruss->v_force_ptr[i]->setVisible(true);
    }
}

void MainWindow::on_compare_Button_released()
{
    for (int i = 0;i < ui->graphicsView->currentTruss->v_joint_ptr.size();i++){
        ui->graphicsView->deformedTruss->v_joint_ptr[i]->setVisible(true);
        ui->graphicsView->currentTruss->v_joint_ptr[i]->setVisible(false);
    }
    for (int i = 0;i < ui->graphicsView->currentTruss->v_edge_ptr.size();i++){
        ui->graphicsView->deformedTruss->v_edge_ptr[i]->setVisible(true);
        ui->graphicsView->currentTruss->v_edge_ptr[i]->setVisible(false);
    }
    for (int i = 0;i < ui->graphicsView->currentTruss->v_force_ptr.size();i++){
        ui->graphicsView->currentTruss->v_force_ptr[i]->setVisible(false);
    }
}

void MainWindow::on_JointSignal(int i)
{
    int x = ui->graphicsView->currentTruss->v_joint_ptr[i]->get_p_x();
    int y = ui->graphicsView->currentTruss->v_joint_ptr[i]->get_p_y();
    ui->ItemInformation1->setText(QString::asprintf("Joint         X:%d        Y:%d",x,y));
    ui->ItemInformation2->clear();
}

void MainWindow::on_EdgeSignal(int i)
{
    int x1 = ui->graphicsView->currentTruss->v_edge_ptr[i]->get_joint_ptr1()->get_p_x();
    int y1 = ui->graphicsView->currentTruss->v_edge_ptr[i]->get_joint_ptr1()->get_p_y();
    int x2 = ui->graphicsView->currentTruss->v_edge_ptr[i]->get_joint_ptr2()->get_p_x();
    int y2 = ui->graphicsView->currentTruss->v_edge_ptr[i]->get_joint_ptr2()->get_p_y();
    ui->ItemInformation1->setText(QString::asprintf("Rod         X1:%d        Y1:%d",x1,y1));
    ui->ItemInformation2->setText(QString::asprintf("            X2:%d        Y2:%d",x2,y2));
}

void MainWindow::on_ForceSignal(int i)
{
    int x = ui->graphicsView->currentTruss->v_force_ptr[i]->get_joint_ptr()->get_p_x();
    int y = ui->graphicsView->currentTruss->v_force_ptr[i]->get_joint_ptr()->get_p_y();
    int Fx = ui->graphicsView->currentTruss->v_force_ptr[i]->get_xforce();
    int Fy = ui->graphicsView->currentTruss->v_force_ptr[i]->get_yforce();
    ui->ItemInformation1->setText(QString::asprintf("Force         X:%d        Y:%d",x,y));
    ui->ItemInformation2->setText(QString::asprintf("              Fx:%dN      Fy:%dN",Fx,Fy));
}

void MainWindow::on_noItemSignal()
{
    ui->ItemInformation1->clear();
    ui->ItemInformation2->clear();
}

void MainWindow::set_JointPosition()
{
    this->ui->joint_x_input->setText(QString::number( ui->graphicsView->scene->get_Point().x()));
    this->ui->joint_y_input->setText(QString::number( ui->graphicsView->scene->get_Point().y()));
    this->ui->if_support_button->setChecked(false);
    emit addJointSignal();
}

void MainWindow::set_SupportPosition()
{
    this->ui->joint_x_input->setText(QString::number( ui->graphicsView->scene->get_Point().x()));
    this->ui->joint_y_input->setText(QString::number( ui->graphicsView->scene->get_Point().y()));
    this->ui->if_support_button->setChecked(true);
    emit addSupportSignal();
}

void MainWindow::set_JointPosition2()
{
    this->ui->joint_x_input->setText(QString::number( ui->graphicsView->scene->get_Point().x()));
    this->ui->joint_y_input->setText(QString::number( ui->graphicsView->scene->get_Point().y()));
    emit deleteJointSignal();
}

void MainWindow::set_EdgeInformation(int i)
{
    this->ui->rod_x1_input->setText(QString::number( ui->graphicsView->currentTruss->v_edge_ptr[i]->get_joint_ptr1()->get_p_x()));
    this->ui->rod_y1_input->setText(QString::number( ui->graphicsView->currentTruss->v_edge_ptr[i]->get_joint_ptr1()->get_p_y()));
    this->ui->rod_x2_input->setText(QString::number( ui->graphicsView->currentTruss->v_edge_ptr[i]->get_joint_ptr2()->get_p_x()));
    this->ui->rod_y2_input->setText(QString::number( ui->graphicsView->currentTruss->v_edge_ptr[i]->get_joint_ptr2()->get_p_y()));
    emit deleteEdgeSignal();
}

void MainWindow::set_ForceInformation(int i)
{
    this->ui->Fx_input->setText(QString::number( ui->graphicsView->currentTruss->v_force_ptr[i]->get_xforce()));
    this->ui->Fy_input->setText(QString::number( ui->graphicsView->currentTruss->v_force_ptr[i]->get_yforce()));
    this->ui->force_x_input->setText(QString::number( ui->graphicsView->currentTruss->v_force_ptr[i]->get_joint_ptr()->get_p_x()));
    this->ui->force_y_input->setText(QString::number( ui->graphicsView->currentTruss->v_force_ptr[i]->get_joint_ptr()->get_p_y()));
    emit deleteForceSignal();

}

void MainWindow::set_JointInformation(int i, int j)
{
    this->ui->rod_x1_input->setText(QString::number( ui->graphicsView->currentTruss->v_joint_ptr[i]->get_p_x()));
    this->ui->rod_y1_input->setText(QString::number( ui->graphicsView->currentTruss->v_joint_ptr[i]->get_p_y()));
    this->ui->rod_x2_input->setText(QString::number( ui->graphicsView->currentTruss->v_joint_ptr[j]->get_p_x()));
    this->ui->rod_y2_input->setText(QString::number( ui->graphicsView->currentTruss->v_joint_ptr[j]->get_p_y()));
    emit addEdgeSignal();
}

void MainWindow::set_Joint_of_Force()
{
    this->ui->force_x_input->setText(QString::number( ui->graphicsView->scene->get_Point().x()));
    this->ui->force_y_input->setText(QString::number( ui->graphicsView->scene->get_Point().y()));
}

