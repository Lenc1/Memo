/****************************************************************************
** Meta object code from reading C++ file 'check1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Memo/check1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'check1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Check1_t {
    QByteArrayData data[14];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Check1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Check1_t qt_meta_stringdata_Check1 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Check1"
QT_MOC_LITERAL(1, 7, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 27), // "on_listWidget_doubleClicked"
QT_MOC_LITERAL(4, 58, 5), // "index"
QT_MOC_LITERAL(5, 64, 40), // "on_listWidget_customContextMe..."
QT_MOC_LITERAL(6, 105, 3), // "pos"
QT_MOC_LITERAL(7, 109, 14), // "on_menu_click1"
QT_MOC_LITERAL(8, 124, 14), // "on_menu_click2"
QT_MOC_LITERAL(9, 139, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(10, 163, 8), // "LoadList"
QT_MOC_LITERAL(11, 172, 9), // "findFiles"
QT_MOC_LITERAL(12, 182, 8), // "startDir"
QT_MOC_LITERAL(13, 191, 7) // "filters"

    },
    "Check1\0on_pushButton_clicked\0\0"
    "on_listWidget_doubleClicked\0index\0"
    "on_listWidget_customContextMenuRequested\0"
    "pos\0on_menu_click1\0on_menu_click2\0"
    "on_pushButton_2_clicked\0LoadList\0"
    "findFiles\0startDir\0filters"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Check1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       5,    1,   58,    2, 0x08 /* Private */,
       7,    1,   61,    2, 0x08 /* Private */,
       8,    1,   64,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    2,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QStringList, QMetaType::QString, QMetaType::QStringList,   12,   13,

       0        // eod
};

void Check1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Check1 *_t = static_cast<Check1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_listWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_listWidget_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->on_menu_click1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_menu_click2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->LoadList(); break;
        case 7: { QStringList _r = _t->findFiles((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject Check1::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Check1.data,
      qt_meta_data_Check1,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Check1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Check1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Check1.stringdata0))
        return static_cast<void*>(const_cast< Check1*>(this));
    return QWidget::qt_metacast(_clname);
}

int Check1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
