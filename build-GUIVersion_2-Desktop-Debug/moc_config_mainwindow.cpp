/****************************************************************************
** Meta object code from reading C++ file 'config_mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUIVersion_2/config_mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'config_mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_config_mainwindow_t {
    QByteArrayData data[8];
    char stringdata[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_config_mainwindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_config_mainwindow_t qt_meta_stringdata_config_mainwindow = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 8),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 12),
QT_MOC_LITERAL(4, 41, 7),
QT_MOC_LITERAL(5, 49, 12),
QT_MOC_LITERAL(6, 62, 4),
QT_MOC_LITERAL(7, 67, 21)
    },
    "config_mainwindow\0close_cg\0\0emit_confeNb\0"
    "eNbconf\0emit_to_main\0info\0"
    "on_pushButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_config_mainwindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06,
       3,    1,   35,    2, 0x06,
       5,    1,   38,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,   41,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void config_mainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        config_mainwindow *_t = static_cast<config_mainwindow *>(_o);
        switch (_id) {
        case 0: _t->close_cg(); break;
        case 1: _t->emit_confeNb((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->emit_to_main((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (config_mainwindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&config_mainwindow::close_cg)) {
                *result = 0;
            }
        }
        {
            typedef void (config_mainwindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&config_mainwindow::emit_confeNb)) {
                *result = 1;
            }
        }
        {
            typedef void (config_mainwindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&config_mainwindow::emit_to_main)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject config_mainwindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_config_mainwindow.data,
      qt_meta_data_config_mainwindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *config_mainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *config_mainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_config_mainwindow.stringdata))
        return static_cast<void*>(const_cast< config_mainwindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int config_mainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void config_mainwindow::close_cg()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void config_mainwindow::emit_confeNb(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void config_mainwindow::emit_to_main(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
