/****************************************************************************
** Meta object code from reading C++ file 'cellTag.h'
**
** Created: Wed Apr 10 13:47:11 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project/cellTag.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cellTag.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cellTag[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      30,    8,    8,    8, 0x05,
      53,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      75,    8,    8,    8, 0x08,
      93,    8,    8,    8, 0x08,
     113,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_cellTag[] = {
    "cellTag\0\0editButtonFinished()\0"
    "finishButtonFinished()\0closeButtonFinished()\0"
    "editButtonClick()\0finishButtonClick()\0"
    "closeButtonClick()\0"
};

void cellTag::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        cellTag *_t = static_cast<cellTag *>(_o);
        switch (_id) {
        case 0: _t->editButtonFinished(); break;
        case 1: _t->finishButtonFinished(); break;
        case 2: _t->closeButtonFinished(); break;
        case 3: _t->editButtonClick(); break;
        case 4: _t->finishButtonClick(); break;
        case 5: _t->closeButtonClick(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData cellTag::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject cellTag::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_cellTag,
      qt_meta_data_cellTag, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &cellTag::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *cellTag::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *cellTag::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cellTag))
        return static_cast<void*>(const_cast< cellTag*>(this));
    return QWidget::qt_metacast(_clname);
}

int cellTag::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void cellTag::editButtonFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void cellTag::finishButtonFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void cellTag::closeButtonFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
