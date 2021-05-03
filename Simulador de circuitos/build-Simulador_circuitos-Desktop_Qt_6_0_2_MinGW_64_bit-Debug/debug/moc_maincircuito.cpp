/****************************************************************************
** Meta object code from reading C++ file 'maincircuito.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Simulador_circuitos/maincircuito.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maincircuito.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainCircuito_t {
    const uint offsetsAndSize[54];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainCircuito_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainCircuito_t qt_meta_stringdata_MainCircuito = {
    {
QT_MOC_LITERAL(0, 12), // "MainCircuito"
QT_MOC_LITERAL(13, 8), // "sgnalMup"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 1), // "a"
QT_MOC_LITERAL(25, 8), // "slotNovo"
QT_MOC_LITERAL(34, 2), // "NE"
QT_MOC_LITERAL(37, 2), // "NS"
QT_MOC_LITERAL(40, 2), // "NP"
QT_MOC_LITERAL(43, 14), // "slotMudarPorta"
QT_MOC_LITERAL(58, 7), // "idporta"
QT_MOC_LITERAL(66, 4), // "nome"
QT_MOC_LITERAL(71, 9), // "Nentradas"
QT_MOC_LITERAL(81, 3), // "id1"
QT_MOC_LITERAL(85, 3), // "id2"
QT_MOC_LITERAL(89, 3), // "id3"
QT_MOC_LITERAL(93, 3), // "id4"
QT_MOC_LITERAL(97, 14), // "slotMudarsaida"
QT_MOC_LITERAL(112, 7), // "idsaida"
QT_MOC_LITERAL(120, 2), // "id"
QT_MOC_LITERAL(123, 23), // "on_actionNovo_triggered"
QT_MOC_LITERAL(147, 22), // "on_actionLer_triggered"
QT_MOC_LITERAL(170, 25), // "on_actionSalvar_triggered"
QT_MOC_LITERAL(196, 31), // "on_actionGerar_Tabela_triggered"
QT_MOC_LITERAL(228, 27), // "on_Portas_cellDoubleClicked"
QT_MOC_LITERAL(256, 3), // "row"
QT_MOC_LITERAL(260, 6), // "column"
QT_MOC_LITERAL(267, 27) // "on_Saidas_cellDoubleClicked"

    },
    "MainCircuito\0sgnalMup\0\0a\0slotNovo\0NE\0"
    "NS\0NP\0slotMudarPorta\0idporta\0nome\0"
    "Nentradas\0id1\0id2\0id3\0id4\0slotMudarsaida\0"
    "idsaida\0id\0on_actionNovo_triggered\0"
    "on_actionLer_triggered\0on_actionSalvar_triggered\0"
    "on_actionGerar_Tabela_triggered\0"
    "on_Portas_cellDoubleClicked\0row\0column\0"
    "on_Saidas_cellDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainCircuito[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    3,   77,    2, 0x08,    2 /* Private */,
       8,    7,   84,    2, 0x08,    6 /* Private */,
      16,    2,   99,    2, 0x08,   14 /* Private */,
      19,    0,  104,    2, 0x08,   17 /* Private */,
      20,    0,  105,    2, 0x08,   18 /* Private */,
      21,    0,  106,    2, 0x08,   19 /* Private */,
      22,    0,  107,    2, 0x08,   20 /* Private */,
      23,    2,  108,    2, 0x08,   21 /* Private */,
      26,    2,  113,    2, 0x08,   24 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   11,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   24,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   24,   25,

       0        // eod
};

void MainCircuito::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainCircuito *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sgnalMup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slotNovo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->slotMudarPorta((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 3: _t->slotMudarsaida((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_actionNovo_triggered(); break;
        case 5: _t->on_actionLer_triggered(); break;
        case 6: _t->on_actionSalvar_triggered(); break;
        case 7: _t->on_actionGerar_Tabela_triggered(); break;
        case 8: _t->on_Portas_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->on_Saidas_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainCircuito::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainCircuito::sgnalMup)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainCircuito::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainCircuito.offsetsAndSize,
    qt_meta_data_MainCircuito,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainCircuito_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainCircuito::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainCircuito::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainCircuito.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainCircuito::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MainCircuito::sgnalMup(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
