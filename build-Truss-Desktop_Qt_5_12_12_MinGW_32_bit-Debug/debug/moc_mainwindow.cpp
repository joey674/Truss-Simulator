/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Truss/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[50];
    char stringdata0[1045];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "addJointSignal"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 16), // "addSupportSignal"
QT_MOC_LITERAL(4, 44, 17), // "deleteJointSignal"
QT_MOC_LITERAL(5, 62, 13), // "addEdgeSignal"
QT_MOC_LITERAL(6, 76, 16), // "deleteEdgeSignal"
QT_MOC_LITERAL(7, 93, 17), // "deleteForceSignal"
QT_MOC_LITERAL(8, 111, 18), // "on_mouseMoveSignal"
QT_MOC_LITERAL(9, 130, 5), // "point"
QT_MOC_LITERAL(10, 136, 28), // "on_joint_x_input_textChanged"
QT_MOC_LITERAL(11, 165, 4), // "arg1"
QT_MOC_LITERAL(12, 170, 28), // "on_joint_y_input_textChanged"
QT_MOC_LITERAL(13, 199, 27), // "on_rod_x1_input_textChanged"
QT_MOC_LITERAL(14, 227, 27), // "on_rod_y1_input_textChanged"
QT_MOC_LITERAL(15, 255, 27), // "on_rod_x2_input_textChanged"
QT_MOC_LITERAL(16, 283, 27), // "on_rod_y2_input_textChanged"
QT_MOC_LITERAL(17, 311, 23), // "on_Fx_input_textChanged"
QT_MOC_LITERAL(18, 335, 23), // "on_Fy_input_textChanged"
QT_MOC_LITERAL(19, 359, 28), // "on_force_x_input_textChanged"
QT_MOC_LITERAL(20, 388, 28), // "on_force_y_input_textChanged"
QT_MOC_LITERAL(21, 417, 22), // "on_E_input_textChanged"
QT_MOC_LITERAL(22, 440, 22), // "on_A_input_textChanged"
QT_MOC_LITERAL(23, 463, 26), // "on_addJoint_Button_clicked"
QT_MOC_LITERAL(24, 490, 29), // "on_deleteJoint_Button_clicked"
QT_MOC_LITERAL(25, 520, 22), // "on_new_Truss_triggered"
QT_MOC_LITERAL(26, 543, 23), // "on_save_Truss_triggered"
QT_MOC_LITERAL(27, 567, 23), // "on_load_Truss_triggered"
QT_MOC_LITERAL(28, 591, 26), // "on_save_as_image_triggered"
QT_MOC_LITERAL(29, 618, 28), // "on_RodConnect_Button_clicked"
QT_MOC_LITERAL(30, 647, 29), // "on_RodSeparate_Button_clicked"
QT_MOC_LITERAL(31, 677, 26), // "on_addForce_Button_clicked"
QT_MOC_LITERAL(32, 704, 29), // "on_deleteForce_Button_clicked"
QT_MOC_LITERAL(33, 734, 28), // "on_initialize_Button_clicked"
QT_MOC_LITERAL(34, 763, 26), // "on_simulate_Button_clicked"
QT_MOC_LITERAL(35, 790, 25), // "on_compare_Button_pressed"
QT_MOC_LITERAL(36, 816, 26), // "on_compare_Button_released"
QT_MOC_LITERAL(37, 843, 14), // "on_JointSignal"
QT_MOC_LITERAL(38, 858, 1), // "i"
QT_MOC_LITERAL(39, 860, 13), // "on_EdgeSignal"
QT_MOC_LITERAL(40, 874, 14), // "on_ForceSignal"
QT_MOC_LITERAL(41, 889, 15), // "on_noItemSignal"
QT_MOC_LITERAL(42, 905, 17), // "set_JointPosition"
QT_MOC_LITERAL(43, 923, 19), // "set_SupportPosition"
QT_MOC_LITERAL(44, 943, 18), // "set_JointPosition2"
QT_MOC_LITERAL(45, 962, 19), // "set_EdgeInformation"
QT_MOC_LITERAL(46, 982, 20), // "set_ForceInformation"
QT_MOC_LITERAL(47, 1003, 20), // "set_JointInformation"
QT_MOC_LITERAL(48, 1024, 1), // "j"
QT_MOC_LITERAL(49, 1026, 18) // "set_Joint_of_Force"

    },
    "MainWindow\0addJointSignal\0\0addSupportSignal\0"
    "deleteJointSignal\0addEdgeSignal\0"
    "deleteEdgeSignal\0deleteForceSignal\0"
    "on_mouseMoveSignal\0point\0"
    "on_joint_x_input_textChanged\0arg1\0"
    "on_joint_y_input_textChanged\0"
    "on_rod_x1_input_textChanged\0"
    "on_rod_y1_input_textChanged\0"
    "on_rod_x2_input_textChanged\0"
    "on_rod_y2_input_textChanged\0"
    "on_Fx_input_textChanged\0on_Fy_input_textChanged\0"
    "on_force_x_input_textChanged\0"
    "on_force_y_input_textChanged\0"
    "on_E_input_textChanged\0on_A_input_textChanged\0"
    "on_addJoint_Button_clicked\0"
    "on_deleteJoint_Button_clicked\0"
    "on_new_Truss_triggered\0on_save_Truss_triggered\0"
    "on_load_Truss_triggered\0"
    "on_save_as_image_triggered\0"
    "on_RodConnect_Button_clicked\0"
    "on_RodSeparate_Button_clicked\0"
    "on_addForce_Button_clicked\0"
    "on_deleteForce_Button_clicked\0"
    "on_initialize_Button_clicked\0"
    "on_simulate_Button_clicked\0"
    "on_compare_Button_pressed\0"
    "on_compare_Button_released\0on_JointSignal\0"
    "i\0on_EdgeSignal\0on_ForceSignal\0"
    "on_noItemSignal\0set_JointPosition\0"
    "set_SupportPosition\0set_JointPosition2\0"
    "set_EdgeInformation\0set_ForceInformation\0"
    "set_JointInformation\0j\0set_Joint_of_Force"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  234,    2, 0x06 /* Public */,
       3,    0,  235,    2, 0x06 /* Public */,
       4,    0,  236,    2, 0x06 /* Public */,
       5,    0,  237,    2, 0x06 /* Public */,
       6,    0,  238,    2, 0x06 /* Public */,
       7,    0,  239,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,  240,    2, 0x08 /* Private */,
      10,    1,  243,    2, 0x08 /* Private */,
      12,    1,  246,    2, 0x08 /* Private */,
      13,    1,  249,    2, 0x08 /* Private */,
      14,    1,  252,    2, 0x08 /* Private */,
      15,    1,  255,    2, 0x08 /* Private */,
      16,    1,  258,    2, 0x08 /* Private */,
      17,    1,  261,    2, 0x08 /* Private */,
      18,    1,  264,    2, 0x08 /* Private */,
      19,    1,  267,    2, 0x08 /* Private */,
      20,    1,  270,    2, 0x08 /* Private */,
      21,    1,  273,    2, 0x08 /* Private */,
      22,    1,  276,    2, 0x08 /* Private */,
      23,    0,  279,    2, 0x08 /* Private */,
      24,    0,  280,    2, 0x08 /* Private */,
      25,    0,  281,    2, 0x08 /* Private */,
      26,    0,  282,    2, 0x08 /* Private */,
      27,    0,  283,    2, 0x08 /* Private */,
      28,    0,  284,    2, 0x08 /* Private */,
      29,    0,  285,    2, 0x08 /* Private */,
      30,    0,  286,    2, 0x08 /* Private */,
      31,    0,  287,    2, 0x08 /* Private */,
      32,    0,  288,    2, 0x08 /* Private */,
      33,    0,  289,    2, 0x08 /* Private */,
      34,    0,  290,    2, 0x08 /* Private */,
      35,    0,  291,    2, 0x08 /* Private */,
      36,    0,  292,    2, 0x08 /* Private */,
      37,    1,  293,    2, 0x08 /* Private */,
      39,    1,  296,    2, 0x08 /* Private */,
      40,    1,  299,    2, 0x08 /* Private */,
      41,    0,  302,    2, 0x08 /* Private */,
      42,    0,  303,    2, 0x08 /* Private */,
      43,    0,  304,    2, 0x08 /* Private */,
      44,    0,  305,    2, 0x08 /* Private */,
      45,    1,  306,    2, 0x08 /* Private */,
      46,    1,  309,    2, 0x08 /* Private */,
      47,    2,  312,    2, 0x08 /* Private */,
      49,    0,  317,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   38,   48,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addJointSignal(); break;
        case 1: _t->addSupportSignal(); break;
        case 2: _t->deleteJointSignal(); break;
        case 3: _t->addEdgeSignal(); break;
        case 4: _t->deleteEdgeSignal(); break;
        case 5: _t->deleteForceSignal(); break;
        case 6: _t->on_mouseMoveSignal((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->on_joint_x_input_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_joint_y_input_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_rod_x1_input_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_rod_y1_input_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_rod_x2_input_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_rod_y2_input_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_Fx_input_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_Fy_input_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->on_force_x_input_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->on_force_y_input_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->on_E_input_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->on_A_input_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->on_addJoint_Button_clicked(); break;
        case 20: _t->on_deleteJoint_Button_clicked(); break;
        case 21: _t->on_new_Truss_triggered(); break;
        case 22: _t->on_save_Truss_triggered(); break;
        case 23: _t->on_load_Truss_triggered(); break;
        case 24: _t->on_save_as_image_triggered(); break;
        case 25: _t->on_RodConnect_Button_clicked(); break;
        case 26: _t->on_RodSeparate_Button_clicked(); break;
        case 27: _t->on_addForce_Button_clicked(); break;
        case 28: _t->on_deleteForce_Button_clicked(); break;
        case 29: _t->on_initialize_Button_clicked(); break;
        case 30: _t->on_simulate_Button_clicked(); break;
        case 31: _t->on_compare_Button_pressed(); break;
        case 32: _t->on_compare_Button_released(); break;
        case 33: _t->on_JointSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_EdgeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->on_ForceSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->on_noItemSignal(); break;
        case 37: _t->set_JointPosition(); break;
        case 38: _t->set_SupportPosition(); break;
        case 39: _t->set_JointPosition2(); break;
        case 40: _t->set_EdgeInformation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->set_ForceInformation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->set_JointInformation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 43: _t->set_Joint_of_Force(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::addJointSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::addSupportSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::deleteJointSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::addEdgeSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::deleteEdgeSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::deleteForceSignal)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 44)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 44;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::addJointSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::addSupportSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::deleteJointSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::addEdgeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::deleteEdgeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::deleteForceSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
