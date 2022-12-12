#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

signals:
    void addJointSignal();
    void addSupportSignal();
    void deleteJointSignal();
    void addEdgeSignal();
    void deleteEdgeSignal();
    void deleteForceSignal();

private slots:
    void on_mouseMoveSignal(QPoint point);
    void on_joint_x_input_textChanged(const QString &arg1);
    void on_joint_y_input_textChanged(const QString &arg1);
    void on_rod_x1_input_textChanged(const QString &arg1);
    void on_rod_y1_input_textChanged(const QString &arg1);
    void on_rod_x2_input_textChanged(const QString &arg1);
    void on_rod_y2_input_textChanged(const QString &arg1);
    void on_Fx_input_textChanged(const QString &arg1);
    void on_Fy_input_textChanged(const QString &arg1);
    void on_force_x_input_textChanged(const QString &arg1);
    void on_force_y_input_textChanged(const QString &arg1);
    void on_E_input_textChanged(const QString &arg1);
    void on_A_input_textChanged(const QString &arg1);
    void on_addJoint_Button_clicked();
    void on_deleteJoint_Button_clicked();
    void on_new_Truss_triggered();
    void on_save_Truss_triggered();
    void on_load_Truss_triggered();
    void on_save_as_image_triggered();
    void on_RodConnect_Button_clicked();
    void on_RodSeparate_Button_clicked();
    void on_addForce_Button_clicked();
    void on_deleteForce_Button_clicked();
    void on_initialize_Button_clicked();
    void on_simulate_Button_clicked();
    void on_compare_Button_pressed();
    void on_compare_Button_released();
    void on_JointSignal(int i);
    void on_EdgeSignal(int i);
    void on_ForceSignal(int i);
    void on_noItemSignal();
    void set_JointPosition();
    void set_SupportPosition();
    void set_JointPosition2();
    void set_EdgeInformation(int i);
    void set_ForceInformation(int i);
    void set_JointInformation(int i,int j);
    void set_Joint_of_Force();
};
#endif // MAINWINDOW_H
