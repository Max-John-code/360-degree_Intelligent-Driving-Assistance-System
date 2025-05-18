/****************************************************************************
** Meta object code from reading C++ file 'readthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Thread/readthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'readthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReadThread_t {
    QByteArrayData data[15];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReadThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReadThread_t qt_meta_stringdata_ReadThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ReadThread"
QT_MOC_LITERAL(1, 11, 12), // "loginSuccess"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "loginFail"
QT_MOC_LITERAL(4, 35, 10), // "regSuccess"
QT_MOC_LITERAL(5, 46, 7), // "regFail"
QT_MOC_LITERAL(6, 54, 9), // "heartLoss"
QT_MOC_LITERAL(7, 64, 16), // "emitPhotoSuccess"
QT_MOC_LITERAL(8, 81, 8), // "getPhoto"
QT_MOC_LITERAL(9, 90, 15), // "GET_PHOTOS_INFO"
QT_MOC_LITERAL(10, 106, 8), // "packLoss"
QT_MOC_LITERAL(11, 115, 9), // "FILE_LOSS"
QT_MOC_LITERAL(12, 125, 12), // "emitBackPage"
QT_MOC_LITERAL(13, 138, 9), // "BACK_PAGE"
QT_MOC_LITERAL(14, 148, 7) // "setFail"

    },
    "ReadThread\0loginSuccess\0\0loginFail\0"
    "regSuccess\0regFail\0heartLoss\0"
    "emitPhotoSuccess\0getPhoto\0GET_PHOTOS_INFO\0"
    "packLoss\0FILE_LOSS\0emitBackPage\0"
    "BACK_PAGE\0setFail"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReadThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    0,   67,    2, 0x06 /* Public */,
       4,    0,   68,    2, 0x06 /* Public */,
       5,    0,   69,    2, 0x06 /* Public */,
       6,    0,   70,    2, 0x06 /* Public */,
       7,    0,   71,    2, 0x06 /* Public */,
       8,    1,   72,    2, 0x06 /* Public */,
      10,    1,   75,    2, 0x06 /* Public */,
      12,    1,   78,    2, 0x06 /* Public */,
      14,    0,   81,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,

       0        // eod
};

void ReadThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReadThread *_t = static_cast<ReadThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loginSuccess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->loginFail(); break;
        case 2: _t->regSuccess(); break;
        case 3: _t->regFail(); break;
        case 4: _t->heartLoss(); break;
        case 5: _t->emitPhotoSuccess(); break;
        case 6: _t->getPhoto((*reinterpret_cast< GET_PHOTOS_INFO(*)>(_a[1]))); break;
        case 7: _t->packLoss((*reinterpret_cast< FILE_LOSS(*)>(_a[1]))); break;
        case 8: _t->emitBackPage((*reinterpret_cast< BACK_PAGE(*)>(_a[1]))); break;
        case 9: _t->setFail(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GET_PHOTOS_INFO >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FILE_LOSS >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BACK_PAGE >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ReadThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::loginSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::loginFail)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::regSuccess)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::regFail)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::heartLoss)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::emitPhotoSuccess)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(GET_PHOTOS_INFO );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::getPhoto)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(FILE_LOSS );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::packLoss)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)(BACK_PAGE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::emitBackPage)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (ReadThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReadThread::setFail)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject ReadThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ReadThread.data,
      qt_meta_data_ReadThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ReadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReadThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ReadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ReadThread::loginSuccess(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ReadThread::loginFail()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ReadThread::regSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ReadThread::regFail()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ReadThread::heartLoss()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ReadThread::emitPhotoSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ReadThread::getPhoto(GET_PHOTOS_INFO _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ReadThread::packLoss(FILE_LOSS _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ReadThread::emitBackPage(BACK_PAGE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ReadThread::setFail()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
