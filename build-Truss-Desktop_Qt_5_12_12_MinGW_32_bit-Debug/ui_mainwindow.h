/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mygraphicsview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *save_Truss;
    QAction *load_Truss;
    QAction *new_Truss;
    QAction *save_as_image;
    QWidget *centralwidget;
    myGraphicsView *graphicsView;
    QLabel *currentCoordx;
    QLabel *currentCoordy;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QPushButton *initialize_Button;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *E_input;
    QLabel *label_4;
    QLineEdit *A_input;
    QLabel *label_28;
    QLabel *label_29;
    QRadioButton *if_nonlinear_Button;
    QGroupBox *groupBox;
    QRadioButton *if_support_button;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *joint_x_input;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *joint_y_input;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addJoint_Button;
    QPushButton *deleteJoint_Button;
    QLabel *label_18;
    QLabel *label_19;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *Fx_input;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *Fy_input;
    QLabel *label_7;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLineEdit *force_x_input;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *force_y_input;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *addForce_Button;
    QPushButton *deleteForce_Button;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_26;
    QLabel *label_27;
    QGroupBox *groupBox_4;
    QLabel *label_10;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QLineEdit *rod_x1_input;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_14;
    QLineEdit *rod_y1_input;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_13;
    QLineEdit *rod_x2_input;
    QLabel *label_11;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QLineEdit *rod_y2_input;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *RodConnect_Button;
    QPushButton *RodSeparate_Button;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QWidget *widget_2;
    QPushButton *simulate_Button;
    QPushButton *compare_Button;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *ItemInformation;
    QLabel *ItemInformation1;
    QLabel *ItemInformation2;
    QMenuBar *menubar;
    QMenu *File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1264, 902);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1264, 902));
        MainWindow->setMaximumSize(QSize(1264, 902));
        save_Truss = new QAction(MainWindow);
        save_Truss->setObjectName(QString::fromUtf8("save_Truss"));
        load_Truss = new QAction(MainWindow);
        load_Truss->setObjectName(QString::fromUtf8("load_Truss"));
        new_Truss = new QAction(MainWindow);
        new_Truss->setObjectName(QString::fromUtf8("new_Truss"));
        save_as_image = new QAction(MainWindow);
        save_as_image->setObjectName(QString::fromUtf8("save_as_image"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new myGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(420, 10, 801, 801));
        currentCoordx = new QLabel(centralwidget);
        currentCoordx->setObjectName(QString::fromUtf8("currentCoordx"));
        currentCoordx->setGeometry(QRect(470, 810, 101, 31));
        currentCoordy = new QLabel(centralwidget);
        currentCoordy->setObjectName(QString::fromUtf8("currentCoordy"));
        currentCoordy->setGeometry(QRect(610, 810, 91, 31));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 11, 381, 841));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 0));
        initialize_Button = new QPushButton(groupBox_2);
        initialize_Button->setObjectName(QString::fromUtf8("initialize_Button"));
        initialize_Button->setGeometry(QRect(190, 120, 93, 28));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 30, 291, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        E_input = new QLineEdit(layoutWidget1);
        E_input->setObjectName(QString::fromUtf8("E_input"));

        horizontalLayout->addWidget(E_input);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(21, 81, 136, 16));
        A_input = new QLineEdit(groupBox_2);
        A_input->setObjectName(QString::fromUtf8("A_input"));
        A_input->setGeometry(QRect(190, 80, 121, 21));
        label_28 = new QLabel(groupBox_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(320, 80, 31, 21));
        label_29 = new QLabel(groupBox_2);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(320, 40, 51, 21));
        if_nonlinear_Button = new QRadioButton(groupBox_2);
        if_nonlinear_Button->setObjectName(QString::fromUtf8("if_nonlinear_Button"));
        if_nonlinear_Button->setGeometry(QRect(20, 120, 111, 31));

        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        if_support_button = new QRadioButton(groupBox);
        if_support_button->setObjectName(QString::fromUtf8("if_support_button"));
        if_support_button->setGeometry(QRect(20, 70, 83, 19));
        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 30, 131, 23));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        joint_x_input = new QLineEdit(layoutWidget2);
        joint_x_input->setObjectName(QString::fromUtf8("joint_x_input"));

        horizontalLayout_3->addWidget(joint_x_input);

        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(200, 30, 131, 23));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        joint_y_input = new QLineEdit(layoutWidget3);
        joint_y_input->setObjectName(QString::fromUtf8("joint_y_input"));

        horizontalLayout_4->addWidget(joint_y_input);

        layoutWidget4 = new QWidget(groupBox);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(70, 100, 221, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        addJoint_Button = new QPushButton(layoutWidget4);
        addJoint_Button->setObjectName(QString::fromUtf8("addJoint_Button"));

        horizontalLayout_5->addWidget(addJoint_Button);

        deleteJoint_Button = new QPushButton(layoutWidget4);
        deleteJoint_Button->setObjectName(QString::fromUtf8("deleteJoint_Button"));

        horizontalLayout_5->addWidget(deleteJoint_Button);

        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(160, 30, 31, 21));
        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(340, 30, 31, 21));

        verticalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        layoutWidget5 = new QWidget(groupBox_3);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 30, 141, 23));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        Fx_input = new QLineEdit(layoutWidget5);
        Fx_input->setObjectName(QString::fromUtf8("Fx_input"));

        horizontalLayout_2->addWidget(Fx_input);

        layoutWidget_2 = new QWidget(groupBox_3);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(200, 30, 131, 23));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        Fy_input = new QLineEdit(layoutWidget_2);
        Fy_input->setObjectName(QString::fromUtf8("Fy_input"));

        horizontalLayout_6->addWidget(Fy_input);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 60, 91, 16));
        layoutWidget_4 = new QWidget(groupBox_3);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 90, 141, 23));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_8->addWidget(label_9);

        force_x_input = new QLineEdit(layoutWidget_4);
        force_x_input->setObjectName(QString::fromUtf8("force_x_input"));

        horizontalLayout_8->addWidget(force_x_input);

        layoutWidget_3 = new QWidget(groupBox_3);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(200, 90, 131, 23));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        force_y_input = new QLineEdit(layoutWidget_3);
        force_y_input->setObjectName(QString::fromUtf8("force_y_input"));

        horizontalLayout_7->addWidget(force_y_input);

        layoutWidget_5 = new QWidget(groupBox_3);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(70, 130, 221, 31));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        addForce_Button = new QPushButton(layoutWidget_5);
        addForce_Button->setObjectName(QString::fromUtf8("addForce_Button"));

        horizontalLayout_9->addWidget(addForce_Button);

        deleteForce_Button = new QPushButton(layoutWidget_5);
        deleteForce_Button->setObjectName(QString::fromUtf8("deleteForce_Button"));

        horizontalLayout_9->addWidget(deleteForce_Button);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(160, 90, 31, 21));
        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(340, 90, 31, 21));
        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(160, 30, 31, 21));
        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(340, 30, 31, 21));

        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 30, 101, 16));
        layoutWidget_6 = new QWidget(groupBox_4);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 60, 141, 23));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_10->addWidget(label_12);

        rod_x1_input = new QLineEdit(layoutWidget_6);
        rod_x1_input->setObjectName(QString::fromUtf8("rod_x1_input"));

        horizontalLayout_10->addWidget(rod_x1_input);

        layoutWidget_8 = new QWidget(groupBox_4);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(200, 60, 131, 23));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(layoutWidget_8);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_12->addWidget(label_14);

        rod_y1_input = new QLineEdit(layoutWidget_8);
        rod_y1_input->setObjectName(QString::fromUtf8("rod_y1_input"));

        horizontalLayout_12->addWidget(rod_y1_input);

        layoutWidget_7 = new QWidget(groupBox_4);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(10, 120, 141, 23));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_11->addWidget(label_13);

        rod_x2_input = new QLineEdit(layoutWidget_7);
        rod_x2_input->setObjectName(QString::fromUtf8("rod_x2_input"));

        horizontalLayout_11->addWidget(rod_x2_input);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 90, 101, 16));
        layoutWidget_9 = new QWidget(groupBox_4);
        layoutWidget_9->setObjectName(QString::fromUtf8("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(200, 120, 131, 23));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget_9);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_13->addWidget(label_15);

        rod_y2_input = new QLineEdit(layoutWidget_9);
        rod_y2_input->setObjectName(QString::fromUtf8("rod_y2_input"));

        horizontalLayout_13->addWidget(rod_y2_input);

        layoutWidget_10 = new QWidget(groupBox_4);
        layoutWidget_10->setObjectName(QString::fromUtf8("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(70, 160, 221, 31));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget_10);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        RodConnect_Button = new QPushButton(layoutWidget_10);
        RodConnect_Button->setObjectName(QString::fromUtf8("RodConnect_Button"));

        horizontalLayout_14->addWidget(RodConnect_Button);

        RodSeparate_Button = new QPushButton(layoutWidget_10);
        RodSeparate_Button->setObjectName(QString::fromUtf8("RodSeparate_Button"));

        horizontalLayout_14->addWidget(RodSeparate_Button);

        label_22 = new QLabel(groupBox_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(160, 60, 31, 21));
        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(160, 120, 31, 21));
        label_24 = new QLabel(groupBox_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(340, 120, 31, 21));
        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(340, 60, 31, 21));

        verticalLayout->addWidget(groupBox_4);

        widget_2 = new QWidget(layoutWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        simulate_Button = new QPushButton(widget_2);
        simulate_Button->setObjectName(QString::fromUtf8("simulate_Button"));
        simulate_Button->setGeometry(QRect(10, 0, 221, 51));
        compare_Button = new QPushButton(widget_2);
        compare_Button->setObjectName(QString::fromUtf8("compare_Button"));
        compare_Button->setGeometry(QRect(250, 0, 111, 41));

        verticalLayout->addWidget(widget_2);

        verticalLayout->setStretch(0, 151);
        verticalLayout->setStretch(1, 131);
        verticalLayout->setStretch(2, 161);
        verticalLayout->setStretch(3, 191);
        verticalLayout->setStretch(4, 51);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(500, 20, 72, 21));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(441, 80, 71, 20));
        ItemInformation = new QLabel(centralwidget);
        ItemInformation->setObjectName(QString::fromUtf8("ItemInformation"));
        ItemInformation->setGeometry(QRect(750, 810, 141, 31));
        ItemInformation1 = new QLabel(centralwidget);
        ItemInformation1->setObjectName(QString::fromUtf8("ItemInformation1"));
        ItemInformation1->setGeometry(QRect(900, 810, 321, 31));
        ItemInformation2 = new QLabel(centralwidget);
        ItemInformation2->setObjectName(QString::fromUtf8("ItemInformation2"));
        ItemInformation2->setGeometry(QRect(900, 830, 321, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1264, 26));
        File = new QMenu(menubar);
        File->setObjectName(QString::fromUtf8("File"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(File->menuAction());
        File->addSeparator();
        File->addAction(save_Truss);
        File->addAction(save_as_image);
        File->addAction(load_Truss);
        File->addAction(new_Truss);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Truss", nullptr));
        save_Truss->setText(QApplication::translate("MainWindow", "save", nullptr));
        load_Truss->setText(QApplication::translate("MainWindow", "load", nullptr));
        new_Truss->setText(QApplication::translate("MainWindow", "new", nullptr));
        save_as_image->setText(QApplication::translate("MainWindow", "save as image", nullptr));
        currentCoordx->setText(QApplication::translate("MainWindow", "X:", nullptr));
        currentCoordy->setText(QApplication::translate("MainWindow", "Y:", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "E and A:", nullptr));
        initialize_Button->setText(QApplication::translate("MainWindow", "initialize", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Elastic coefficient:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Thickness of rod:", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "cm\302\262", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "N/cm\302\262", nullptr));
        if_nonlinear_Button->setText(QApplication::translate("MainWindow", "non-linear", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Joint:", nullptr));
        if_support_button->setText(QApplication::translate("MainWindow", "Support", nullptr));
        label->setText(QApplication::translate("MainWindow", "X:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Y:", nullptr));
        addJoint_Button->setText(QApplication::translate("MainWindow", "add", nullptr));
        deleteJoint_Button->setText(QApplication::translate("MainWindow", "delete", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "cm", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "cm", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Force:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Fx:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Fy:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "coordinate:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "X:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Y:", nullptr));
        addForce_Button->setText(QApplication::translate("MainWindow", "add", nullptr));
        deleteForce_Button->setText(QApplication::translate("MainWindow", "delete", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "cm", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "cm", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "N", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "N", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Rod:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "coordinate 1:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "X:", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Y:", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "X:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "coordinate 2:", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "Y:", nullptr));
        RodConnect_Button->setText(QApplication::translate("MainWindow", "connect", nullptr));
        RodSeparate_Button->setText(QApplication::translate("MainWindow", "separate", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "cm", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "cm", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "cm", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "cm", nullptr));
        simulate_Button->setText(QApplication::translate("MainWindow", "simulate", nullptr));
        compare_Button->setText(QApplication::translate("MainWindow", "compare", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "x", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "y", nullptr));
        ItemInformation->setText(QApplication::translate("MainWindow", "Item information:", nullptr));
        ItemInformation1->setText(QString());
        ItemInformation2->setText(QString());
        File->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
