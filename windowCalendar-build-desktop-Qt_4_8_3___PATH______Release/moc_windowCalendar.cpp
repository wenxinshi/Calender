/****************************************************************************
** Meta object code from reading C++ file 'windowCalendar.h'
**
** Created: Sat Apr 13 21:04:25 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project/windowCalendar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowCalendar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_windowCalendar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      28,   15,   15,   15, 0x08,
      40,   15,   15,   15, 0x08,
      53,   15,   15,   15, 0x08,
      75,   15,   15,   15, 0x08,
     102,   15,   15,   15, 0x08,
     113,   15,   15,   15, 0x08,
     153,  134,   15,   15, 0x08,
     192,  134,   15,   15, 0x08,
     232,   15,   15,   15, 0x08,
     247,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_windowCalendar[] = {
    "windowCalendar\0\0importXML()\0exportXML()\0"
    "sortOption()\0searchButtonClicked()\0"
    "currentDateButtonClicked()\0popUpTag()\0"
    "seletedDateChanged()\0event,selectedDate\0"
    "oneEventPopUpTag(vector<Event*>,QDate)\0"
    "mutiEventPopUpTag(vector<Event*>,QDate)\0"
    "removeTag(int)\0closeTag()\0"
};

void windowCalendar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        windowCalendar *_t = static_cast<windowCalendar *>(_o);
        switch (_id) {
        case 0: _t->importXML(); break;
        case 1: _t->exportXML(); break;
        case 2: _t->sortOption(); break;
        case 3: _t->searchButtonClicked(); break;
        case 4: _t->currentDateButtonClicked(); break;
        case 5: _t->popUpTag(); break;
        case 6: _t->seletedDateChanged(); break;
        case 7: _t->oneEventPopUpTag((*reinterpret_cast< vector<Event*>(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2]))); break;
        case 8: _t->mutiEventPopUpTag((*reinterpret_cast< vector<Event*>(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2]))); break;
        case 9: _t->removeTag((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->closeTag(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData windowCalendar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject windowCalendar::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_windowCalendar,
      qt_meta_data_windowCalendar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &windowCalendar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *windowCalendar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *windowCalendar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_windowCalendar))
        return static_cast<void*>(const_cast< windowCalendar*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int windowCalendar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
