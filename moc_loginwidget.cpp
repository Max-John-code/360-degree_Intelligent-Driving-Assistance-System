/****************************************************************************
** Meta object code from reading C++ file 'loginwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/loginwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginWidget_t {
    QByteArrayData data[16];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginWidget_t qt_meta_stringdata_LoginWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LoginWidget"
QT_MOC_LITERAL(1, 12, 11), // "loginToMain"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 6), // "userid"
QT_MOC_LITERAL(4, 32, 8), // "username"
QT_MOC_LITERAL(5, 41, 10), // "loginToSet"
QT_MOC_LITERAL(6, 52, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(7, 76, 10), // "RegToLogin"
QT_MOC_LITERAL(8, 87, 11), // "RegToLogin2"
QT_MOC_LITERAL(9, 99, 9), // "loginFail"
QT_MOC_LITERAL(10, 109, 9), // "hreatLoss"
QT_MOC_LITERAL(11, 119, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(12, 143, 12), // "toMainWidget"
QT_MOC_LITERAL(13, 156, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(14, 178, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(15, 202, 23) // "on_pushButton_5_clicked"

    },
    "LoginWidget\0loginToMain\0\0userid\0"
    "username\0loginToSet\0on_pushButton_3_clicked\0"
    "RegToLogin\0RegToLogin2\0loginFail\0"
    "hreatLoss\0on_pushButton_4_clicked\0"
    "toMainWidget\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_5_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       5,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   80,    2, 0x08 /* Private */,
       7,    1,   81,    2, 0x08 /* Private */,
       8,    0,   84,    2, 0x08 /* Private */,
       9,    0,   85,    2, 0x08 /* Private */,
      10,    0,   86,    2, 0x08 /* Private */,
      11,    0,   87,    2, 0x08 /* Private */,
      12,    1,   88,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoginWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginWidget *_t = static_cast<LoginWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loginToMain((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->loginToSet(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->RegToLogin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->RegToLogin2(); break;
        case 5: _t->loginFail(); break;
        case 6: _t->hreatLoss(); break;
        case 7: _t->on_pushButton_4_clicked(); break;
        case 8: _t->toMainWidget((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_pushButton_2_clicked(); break;
        case 11: _t->on_pushButton_5_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (LoginWidget::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginWidget::loginToMain)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LoginWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginWidget::loginToSet)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject LoginWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoginWidget.data,
      qt_meta_data_LoginWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LoginWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoginWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LoginWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void LoginWidget::loginToMain(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoginWidget::loginToSet()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
