/****************************************************************************
** Meta object code from reading C++ file 'socketthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUIVersion_2/socketthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socketthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SocketThread_t {
    QByteArrayData data[12];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SocketThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SocketThread_t qt_meta_stringdata_SocketThread = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 5),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 23),
QT_MOC_LITERAL(4, 44, 11),
QT_MOC_LITERAL(5, 56, 13),
QT_MOC_LITERAL(6, 70, 7),
QT_MOC_LITERAL(7, 78, 9),
QT_MOC_LITERAL(8, 88, 12),
QT_MOC_LITERAL(9, 101, 8),
QT_MOC_LITERAL(10, 110, 4),
QT_MOC_LITERAL(11, 115, 2)
    },
    "SocketThread\0error\0\0QTcpSocket::SocketError\0"
    "socketerror\0disconnectTcp\0qintptr\0"
    "readyRead\0disconnected\0sendTest\0data\0"
    "id\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SocketThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06,
       5,    1,   42,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,   45,    2, 0x0a,
       8,    0,   46,    2, 0x0a,
       9,    2,   47,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,   10,   11,

       0        // eod
};

void SocketThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SocketThread *_t = static_cast<SocketThread *>(_o);
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->disconnectTcp((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        case 2: _t->readyRead(); break;
        case 3: _t->disconnected(); break;
        case 4: _t->sendTest((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qintptr(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SocketThread::*_t)(QTcpSocket::SocketError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketThread::error)) {
                *result = 0;
            }
        }
        {
            typedef void (SocketThread::*_t)(qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketThread::disconnectTcp)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject SocketThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SocketThread.data,
      qt_meta_data_SocketThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *SocketThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SocketThread.stringdata))
        return static_cast<void*>(const_cast< SocketThread*>(this));
    return QThread::qt_metacast(_clname);
}

int SocketThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SocketThread::error(QTcpSocket::SocketError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SocketThread::disconnectTcp(qintptr _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
