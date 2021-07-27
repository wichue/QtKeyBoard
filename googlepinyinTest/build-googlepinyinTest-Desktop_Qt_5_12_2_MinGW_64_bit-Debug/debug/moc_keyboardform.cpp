/****************************************************************************
** Meta object code from reading C++ file 'keyboardform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../googlepinyinTest/keyboardAll/keyboardform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keyboardform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KeyboardForm_t {
    QByteArrayData data[18];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KeyboardForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KeyboardForm_t qt_meta_stringdata_KeyboardForm = {
    {
QT_MOC_LITERAL(0, 0, 12), // "KeyboardForm"
QT_MOC_LITERAL(1, 13, 18), // "sendKeyToFocusItem"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "keyText"
QT_MOC_LITERAL(4, 41, 13), // "letterClicked"
QT_MOC_LITERAL(5, 55, 10), // "numClicked"
QT_MOC_LITERAL(6, 66, 12), // "hanziClicked"
QT_MOC_LITERAL(7, 79, 7), // "setText"
QT_MOC_LITERAL(8, 87, 3), // "str"
QT_MOC_LITERAL(9, 91, 12), // "shiftClicked"
QT_MOC_LITERAL(10, 104, 15), // "changeInputMode"
QT_MOC_LITERAL(11, 120, 12), // "changeSymbol"
QT_MOC_LITERAL(12, 133, 5), // "space"
QT_MOC_LITERAL(13, 139, 5), // "enter"
QT_MOC_LITERAL(14, 145, 9), // "backSpace"
QT_MOC_LITERAL(15, 155, 8), // "prevPage"
QT_MOC_LITERAL(16, 164, 8), // "nextPage"
QT_MOC_LITERAL(17, 173, 11) // "changeStyle"

    },
    "KeyboardForm\0sendKeyToFocusItem\0\0"
    "keyText\0letterClicked\0numClicked\0"
    "hanziClicked\0setText\0str\0shiftClicked\0"
    "changeInputMode\0changeSymbol\0space\0"
    "enter\0backSpace\0prevPage\0nextPage\0"
    "changeStyle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KeyboardForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   87,    2, 0x0a /* Public */,
       5,    0,   88,    2, 0x0a /* Public */,
       6,    0,   89,    2, 0x0a /* Public */,
       7,    1,   90,    2, 0x0a /* Public */,
       9,    0,   93,    2, 0x0a /* Public */,
      10,    0,   94,    2, 0x0a /* Public */,
      11,    0,   95,    2, 0x0a /* Public */,
      12,    0,   96,    2, 0x0a /* Public */,
      13,    0,   97,    2, 0x0a /* Public */,
      14,    0,   98,    2, 0x0a /* Public */,
      15,    0,   99,    2, 0x0a /* Public */,
      16,    0,  100,    2, 0x0a /* Public */,
      17,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
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

void KeyboardForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KeyboardForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendKeyToFocusItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->letterClicked(); break;
        case 2: _t->numClicked(); break;
        case 3: _t->hanziClicked(); break;
        case 4: _t->setText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->shiftClicked(); break;
        case 6: _t->changeInputMode(); break;
        case 7: _t->changeSymbol(); break;
        case 8: _t->space(); break;
        case 9: _t->enter(); break;
        case 10: _t->backSpace(); break;
        case 11: _t->prevPage(); break;
        case 12: _t->nextPage(); break;
        case 13: _t->changeStyle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KeyboardForm::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyboardForm::sendKeyToFocusItem)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KeyboardForm::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_KeyboardForm.data,
    qt_meta_data_KeyboardForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KeyboardForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KeyboardForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KeyboardForm.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int KeyboardForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void KeyboardForm::sendKeyToFocusItem(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
