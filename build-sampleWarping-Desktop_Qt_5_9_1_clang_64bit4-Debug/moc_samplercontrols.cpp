/****************************************************************************
** Meta object code from reading C++ file 'samplercontrols.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../assignment_package/src/ignore_me/samplercontrols.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'samplercontrols.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SamplerControls_t {
    QByteArrayData data[25];
    char stringdata0[383];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SamplerControls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SamplerControls_t qt_meta_stringdata_SamplerControls = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SamplerControls"
QT_MOC_LITERAL(1, 16, 14), // "sig_setSamples"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "sig_setSampleMode"
QT_MOC_LITERAL(4, 50, 10), // "SampleMode"
QT_MOC_LITERAL(5, 61, 17), // "sig_setWarpMethod"
QT_MOC_LITERAL(6, 79, 10), // "WarpMethod"
QT_MOC_LITERAL(7, 90, 18), // "sig_setDisplayGrid"
QT_MOC_LITERAL(8, 109, 15), // "sig_computePDFs"
QT_MOC_LITERAL(9, 125, 18), // "sig_updateThetaMax"
QT_MOC_LITERAL(10, 144, 15), // "slot_setSamples"
QT_MOC_LITERAL(11, 160, 18), // "slot_setSampleMode"
QT_MOC_LITERAL(12, 179, 18), // "slot_setWarpMethod"
QT_MOC_LITERAL(13, 198, 28), // "slot_updateNumSampleControls"
QT_MOC_LITERAL(14, 227, 19), // "slot_setDisplayGrid"
QT_MOC_LITERAL(15, 247, 21), // "slot_fixWarpMethodBox"
QT_MOC_LITERAL(16, 269, 21), // "slot_fixSampleModeBox"
QT_MOC_LITERAL(17, 291, 16), // "slot_computePDFs"
QT_MOC_LITERAL(18, 308, 15), // "slot_updatePDFs"
QT_MOC_LITERAL(19, 324, 4), // "disc"
QT_MOC_LITERAL(20, 329, 6), // "sphere"
QT_MOC_LITERAL(21, 336, 9), // "sphereCap"
QT_MOC_LITERAL(22, 346, 8), // "hemiUnif"
QT_MOC_LITERAL(23, 355, 7), // "hemiCos"
QT_MOC_LITERAL(24, 363, 19) // "slot_updateThetaMax"

    },
    "SamplerControls\0sig_setSamples\0\0"
    "sig_setSampleMode\0SampleMode\0"
    "sig_setWarpMethod\0WarpMethod\0"
    "sig_setDisplayGrid\0sig_computePDFs\0"
    "sig_updateThetaMax\0slot_setSamples\0"
    "slot_setSampleMode\0slot_setWarpMethod\0"
    "slot_updateNumSampleControls\0"
    "slot_setDisplayGrid\0slot_fixWarpMethodBox\0"
    "slot_fixSampleModeBox\0slot_computePDFs\0"
    "slot_updatePDFs\0disc\0sphere\0sphereCap\0"
    "hemiUnif\0hemiCos\0slot_updateThetaMax"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SamplerControls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       3,    1,   97,    2, 0x06 /* Public */,
       5,    1,  100,    2, 0x06 /* Public */,
       7,    0,  103,    2, 0x06 /* Public */,
       8,    0,  104,    2, 0x06 /* Public */,
       9,    1,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  108,    2, 0x0a /* Public */,
      11,    1,  111,    2, 0x0a /* Public */,
      12,    1,  114,    2, 0x0a /* Public */,
      13,    1,  117,    2, 0x0a /* Public */,
      14,    0,  120,    2, 0x0a /* Public */,
      15,    1,  121,    2, 0x0a /* Public */,
      16,    1,  124,    2, 0x0a /* Public */,
      17,    0,  127,    2, 0x0a /* Public */,
      18,    5,  128,    2, 0x0a /* Public */,
      24,    1,  139,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   19,   20,   21,   22,   23,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void SamplerControls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SamplerControls *_t = static_cast<SamplerControls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_setSamples((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sig_setSampleMode((*reinterpret_cast< SampleMode(*)>(_a[1]))); break;
        case 2: _t->sig_setWarpMethod((*reinterpret_cast< WarpMethod(*)>(_a[1]))); break;
        case 3: _t->sig_setDisplayGrid(); break;
        case 4: _t->sig_computePDFs(); break;
        case 5: _t->sig_updateThetaMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slot_setSamples((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slot_setSampleMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slot_setWarpMethod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->slot_updateNumSampleControls((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->slot_setDisplayGrid(); break;
        case 11: _t->slot_fixWarpMethodBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->slot_fixSampleModeBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->slot_computePDFs(); break;
        case 14: _t->slot_updatePDFs((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5]))); break;
        case 15: _t->slot_updateThetaMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SamplerControls::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SamplerControls::sig_setSamples)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SamplerControls::*_t)(SampleMode );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SamplerControls::sig_setSampleMode)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SamplerControls::*_t)(WarpMethod );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SamplerControls::sig_setWarpMethod)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SamplerControls::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SamplerControls::sig_setDisplayGrid)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (SamplerControls::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SamplerControls::sig_computePDFs)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (SamplerControls::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SamplerControls::sig_updateThetaMax)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject SamplerControls::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SamplerControls.data,
      qt_meta_data_SamplerControls,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SamplerControls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SamplerControls::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SamplerControls.stringdata0))
        return static_cast<void*>(const_cast< SamplerControls*>(this));
    return QWidget::qt_metacast(_clname);
}

int SamplerControls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void SamplerControls::sig_setSamples(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SamplerControls::sig_setSampleMode(SampleMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SamplerControls::sig_setWarpMethod(WarpMethod _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SamplerControls::sig_setDisplayGrid()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SamplerControls::sig_computePDFs()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SamplerControls::sig_updateThetaMax(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
