/****************************************************************************
** Meta object code from reading C++ file 'drone.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TestSwarm_1/drone.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drone.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Drone_t {
    QByteArrayData data[11];
    char stringdata[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Drone_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Drone_t qt_meta_stringdata_Drone = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 13),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 9),
QT_MOC_LITERAL(4, 31, 8),
QT_MOC_LITERAL(5, 40, 12),
QT_MOC_LITERAL(6, 53, 8),
QT_MOC_LITERAL(7, 62, 7),
QT_MOC_LITERAL(8, 70, 15),
QT_MOC_LITERAL(9, 86, 10),
QT_MOC_LITERAL(10, 97, 9)
    },
    "Drone\0mSignalNewPos\0\0signalPos\0signalID\0"
    "matePosInput\0aMatePos\0aMateID\0"
    "changeSwarmDate\0aSwarmSize\0aLeaderID\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Drone[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    2,   34,    2, 0x0a,
       8,    2,   39,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QVector3D, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QVector3D, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,

       0        // eod
};

void Drone::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Drone *_t = static_cast<Drone *>(_o);
        switch (_id) {
        case 0: _t->mSignalNewPos((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->matePosInput((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->changeSwarmDate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Drone::*_t)(QVector3D , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Drone::mSignalNewPos)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Drone::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Drone.data,
      qt_meta_data_Drone,  qt_static_metacall, 0, 0}
};


const QMetaObject *Drone::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Drone::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Drone.stringdata))
        return static_cast<void*>(const_cast< Drone*>(this));
    return QObject::qt_metacast(_clname);
}

int Drone::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Drone::mSignalNewPos(QVector3D _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
