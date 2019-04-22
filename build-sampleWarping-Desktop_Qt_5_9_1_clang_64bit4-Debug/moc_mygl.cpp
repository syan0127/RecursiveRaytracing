/****************************************************************************
** Meta object code from reading C++ file 'mygl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../assignment_package/src/ignore_me/mygl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyGL_t {
    QByteArrayData data[13];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGL_t qt_meta_stringdata_MyGL = {
    {
QT_MOC_LITERAL(0, 0, 4), // "MyGL"
QT_MOC_LITERAL(1, 5, 20), // "sig_updateNumSamples"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 20), // "sig_fixWarpMethodBox"
QT_MOC_LITERAL(4, 48, 20), // "sig_fixSampleModeBox"
QT_MOC_LITERAL(5, 69, 12), // "sig_sendPDFs"
QT_MOC_LITERAL(6, 82, 15), // "slot_setSamples"
QT_MOC_LITERAL(7, 98, 18), // "slot_setSampleMode"
QT_MOC_LITERAL(8, 117, 10), // "SampleMode"
QT_MOC_LITERAL(9, 128, 18), // "slot_setWarpMethod"
QT_MOC_LITERAL(10, 147, 10), // "WarpMethod"
QT_MOC_LITERAL(11, 158, 11), // "computePDFs"
QT_MOC_LITERAL(12, 170, 19) // "slot_updateThetaMax"

    },
    "MyGL\0sig_updateNumSamples\0\0"
    "sig_fixWarpMethodBox\0sig_fixSampleModeBox\0"
    "sig_sendPDFs\0slot_setSamples\0"
    "slot_setSampleMode\0SampleMode\0"
    "slot_setWarpMethod\0WarpMethod\0computePDFs\0"
    "slot_updateThetaMax"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,
       5,    5,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   79,    2, 0x0a /* Public */,
       7,    1,   82,    2, 0x0a /* Public */,
       9,    1,   85,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    1,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void MyGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGL *_t = static_cast<MyGL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_updateNumSamples((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sig_fixWarpMethodBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sig_fixSampleModeBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sig_sendPDFs((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5]))); break;
        case 4: _t->slot_setSamples((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slot_setSampleMode((*reinterpret_cast< SampleMode(*)>(_a[1]))); break;
        case 6: _t->slot_setWarpMethod((*reinterpret_cast< WarpMethod(*)>(_a[1]))); break;
        case 7: { int _r = _t->computePDFs();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->slot_updateThetaMax((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGL::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_updateNumSamples)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_fixWarpMethodBox)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_fixSampleModeBox)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyGL::*_t)(float , float , float , float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendPDFs)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MyGL::staticMetaObject = {
    { &GLWidget277::staticMetaObject, qt_meta_stringdata_MyGL.data,
      qt_meta_data_MyGL,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyGL.stringdata0))
        return static_cast<void*>(const_cast< MyGL*>(this));
    return GLWidget277::qt_metacast(_clname);
}

int MyGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GLWidget277::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MyGL::sig_updateNumSamples(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGL::sig_fixWarpMethodBox(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGL::sig_fixSampleModeBox(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGL::sig_sendPDFs(float _t1, float _t2, float _t3, float _t4, float _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
