/****************************************************************************
** Meta object code from reading C++ file 'battleship.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../battleship.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'battleship.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_battleship_t {
    QByteArrayData data[20];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_battleship_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_battleship_t qt_meta_stringdata_battleship = {
    {
QT_MOC_LITERAL(0, 0, 10), // "battleship"
QT_MOC_LITERAL(1, 11, 17), // "open_question_tab"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10), // "showShip00"
QT_MOC_LITERAL(4, 41, 10), // "showShip01"
QT_MOC_LITERAL(5, 52, 10), // "showShip02"
QT_MOC_LITERAL(6, 63, 10), // "showShip03"
QT_MOC_LITERAL(7, 74, 10), // "showShip10"
QT_MOC_LITERAL(8, 85, 10), // "showShip11"
QT_MOC_LITERAL(9, 96, 10), // "showShip12"
QT_MOC_LITERAL(10, 107, 10), // "showShip13"
QT_MOC_LITERAL(11, 118, 10), // "showShip20"
QT_MOC_LITERAL(12, 129, 10), // "showShip21"
QT_MOC_LITERAL(13, 140, 10), // "showShip22"
QT_MOC_LITERAL(14, 151, 10), // "showShip23"
QT_MOC_LITERAL(15, 162, 10), // "showShip30"
QT_MOC_LITERAL(16, 173, 10), // "showShip31"
QT_MOC_LITERAL(17, 184, 10), // "showShip32"
QT_MOC_LITERAL(18, 195, 10), // "showShip33"
QT_MOC_LITERAL(19, 206, 11) // "updateTimer"

    },
    "battleship\0open_question_tab\0\0showShip00\0"
    "showShip01\0showShip02\0showShip03\0"
    "showShip10\0showShip11\0showShip12\0"
    "showShip13\0showShip20\0showShip21\0"
    "showShip22\0showShip23\0showShip30\0"
    "showShip31\0showShip32\0showShip33\0"
    "updateTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_battleship[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    0,  106,    2, 0x0a /* Public */,
       5,    0,  107,    2, 0x0a /* Public */,
       6,    0,  108,    2, 0x0a /* Public */,
       7,    0,  109,    2, 0x0a /* Public */,
       8,    0,  110,    2, 0x0a /* Public */,
       9,    0,  111,    2, 0x0a /* Public */,
      10,    0,  112,    2, 0x0a /* Public */,
      11,    0,  113,    2, 0x0a /* Public */,
      12,    0,  114,    2, 0x0a /* Public */,
      13,    0,  115,    2, 0x0a /* Public */,
      14,    0,  116,    2, 0x0a /* Public */,
      15,    0,  117,    2, 0x0a /* Public */,
      16,    0,  118,    2, 0x0a /* Public */,
      17,    0,  119,    2, 0x0a /* Public */,
      18,    0,  120,    2, 0x0a /* Public */,
      19,    0,  121,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void battleship::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<battleship *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->open_question_tab();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->showShip00(); break;
        case 2: _t->showShip01(); break;
        case 3: _t->showShip02(); break;
        case 4: _t->showShip03(); break;
        case 5: _t->showShip10(); break;
        case 6: _t->showShip11(); break;
        case 7: _t->showShip12(); break;
        case 8: _t->showShip13(); break;
        case 9: _t->showShip20(); break;
        case 10: _t->showShip21(); break;
        case 11: _t->showShip22(); break;
        case 12: _t->showShip23(); break;
        case 13: _t->showShip30(); break;
        case 14: _t->showShip31(); break;
        case 15: _t->showShip32(); break;
        case 16: _t->showShip33(); break;
        case 17: _t->updateTimer(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject battleship::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_battleship.data,
    qt_meta_data_battleship,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *battleship::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *battleship::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_battleship.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int battleship::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
