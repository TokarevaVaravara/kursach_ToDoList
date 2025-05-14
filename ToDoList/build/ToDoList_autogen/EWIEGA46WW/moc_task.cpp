/****************************************************************************
** Meta object code from reading C++ file 'task.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../task.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'task.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Task_t {
    uint offsetsAndSizes[26];
    char stringdata0[5];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[18];
    char stringdata5[14];
    char stringdata6[5];
    char stringdata7[8];
    char stringdata8[16];
    char stringdata9[18];
    char stringdata10[24];
    char stringdata11[21];
    char stringdata12[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Task_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Task_t qt_meta_stringdata_Task = {
    {
        QT_MOC_LITERAL(0, 4),  // "Task"
        QT_MOC_LITERAL(5, 7),  // "setupUi"
        QT_MOC_LITERAL(13, 0),  // ""
        QT_MOC_LITERAL(14, 14),  // "setupShortcuts"
        QT_MOC_LITERAL(29, 17),  // "loadTasksFromFile"
        QT_MOC_LITERAL(47, 13),  // "addTaskToList"
        QT_MOC_LITERAL(61, 4),  // "text"
        QT_MOC_LITERAL(66, 7),  // "checked"
        QT_MOC_LITERAL(74, 15),  // "saveTasksToFile"
        QT_MOC_LITERAL(90, 17),  // "on_btnAdd_clicked"
        QT_MOC_LITERAL(108, 23),  // "on_btnRemoveAll_clicked"
        QT_MOC_LITERAL(132, 20),  // "on_btnRemove_clicked"
        QT_MOC_LITERAL(153, 21)   // "on_btnDiagram_clicked"
    },
    "Task",
    "setupUi",
    "",
    "setupShortcuts",
    "loadTasksFromFile",
    "addTaskToList",
    "text",
    "checked",
    "saveTasksToFile",
    "on_btnAdd_clicked",
    "on_btnRemoveAll_clicked",
    "on_btnRemove_clicked",
    "on_btnDiagram_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Task[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    2,   71,    2, 0x08,    4 /* Private */,
       8,    0,   76,    2, 0x08,    7 /* Private */,
       9,    0,   77,    2, 0x08,    8 /* Private */,
      10,    0,   78,    2, 0x08,    9 /* Private */,
      11,    0,   79,    2, 0x08,   10 /* Private */,
      12,    0,   80,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Task::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Task.offsetsAndSizes,
    qt_meta_data_Task,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Task_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Task, std::true_type>,
        // method 'setupUi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setupShortcuts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadTasksFromFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addTaskToList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveTasksToFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnAdd_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRemoveAll_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRemove_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnDiagram_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Task::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Task *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setupUi(); break;
        case 1: _t->setupShortcuts(); break;
        case 2: _t->loadTasksFromFile(); break;
        case 3: _t->addTaskToList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 4: _t->saveTasksToFile(); break;
        case 5: _t->on_btnAdd_clicked(); break;
        case 6: _t->on_btnRemoveAll_clicked(); break;
        case 7: _t->on_btnRemove_clicked(); break;
        case 8: _t->on_btnDiagram_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *Task::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Task::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Task.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Task::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
