/****************************************************************************
** Meta object code from reading C++ file 'mygraphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Truss/mygraphicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygraphicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_myGraphicsView_t {
    QByteArrayData data[16];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myGraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myGraphicsView_t qt_meta_stringdata_myGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "myGraphicsView"
QT_MOC_LITERAL(1, 15, 15), // "mouseMoveSignal"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "point"
QT_MOC_LITERAL(4, 38, 11), // "JointSignal"
QT_MOC_LITERAL(5, 50, 1), // "i"
QT_MOC_LITERAL(6, 52, 10), // "EdgeSignal"
QT_MOC_LITERAL(7, 63, 11), // "ForceSignal"
QT_MOC_LITERAL(8, 75, 12), // "noItemSignal"
QT_MOC_LITERAL(9, 88, 18), // "selectedEdgeSignal"
QT_MOC_LITERAL(10, 107, 19), // "selectedForceSignal"
QT_MOC_LITERAL(11, 127, 19), // "selectedJointSignal"
QT_MOC_LITERAL(12, 147, 1), // "j"
QT_MOC_LITERAL(13, 149, 10), // "on_action4"
QT_MOC_LITERAL(14, 160, 10), // "on_action5"
QT_MOC_LITERAL(15, 171, 10) // "on_action8"

    },
    "myGraphicsView\0mouseMoveSignal\0\0point\0"
    "JointSignal\0i\0EdgeSignal\0ForceSignal\0"
    "noItemSignal\0selectedEdgeSignal\0"
    "selectedForceSignal\0selectedJointSignal\0"
    "j\0on_action4\0on_action5\0on_action8"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myGraphicsView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       7,    1,   78,    2, 0x06 /* Public */,
       8,    0,   81,    2, 0x06 /* Public */,
       9,    1,   82,    2, 0x06 /* Public */,
      10,    1,   85,    2, 0x06 /* Public */,
      11,    2,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   93,    2, 0x08 /* Private */,
      14,    0,   94,    2, 0x08 /* Private */,
      15,    0,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void myGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<myGraphicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseMoveSignal((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->JointSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->EdgeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ForceSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->noItemSignal(); break;
        case 5: _t->selectedEdgeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->selectedForceSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->selectedJointSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->on_action4(); break;
        case 9: _t->on_action5(); break;
        case 10: _t->on_action8(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (myGraphicsView::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myGraphicsView::mouseMoveSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (myGraphicsView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myGraphicsView::JointSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (myGraphicsView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myGraphicsView::EdgeSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (myGraphicsView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myGraphicsView::ForceSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (myGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myGraphicsView::noItemSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (myGraphicsView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myGraphicsView::selectedEdgeSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (myGraphicsView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myGraphicsView::selectedForceSignal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (myGraphicsView::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myGraphicsView::selectedJointSignal)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject myGraphicsView::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_myGraphicsView.data,
    qt_meta_data_myGraphicsView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *myGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_myGraphicsView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int myGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void myGraphicsView::mouseMoveSignal(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void myGraphicsView::JointSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void myGraphicsView::EdgeSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void myGraphicsView::ForceSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void myGraphicsView::noItemSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void myGraphicsView::selectedEdgeSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void myGraphicsView::selectedForceSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void myGraphicsView::selectedJointSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
