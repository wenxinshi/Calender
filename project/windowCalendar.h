#ifndef WINDOWCALENDAR_H
#define WINDOWCALENDAR_H

#include <QWidget>
#include <QMainWindow>
#include "cellTag.h"
#include "Calendar/Calendar.h"
#include "Calendar/Event.h"
#include <string>
#include <iostream>
#include <string>
#include <QPixmap>
QT_BEGIN_NAMESPACE
class QCalendarWidget;
class QHBoxLayout;
class QVBoxLayout;
class QComboBox;
class QDateEdit;
class QLabel;
class QAction;
class QMenu;
class QString;
class QDate;
class QTableWidgetItem;
class QPushButton;
class QTableWidget;
class QLineEdit;
class QTabWidget;
class QBrush;
class QFont;
class QIcon;
class QMessageBox;
QT_END_NAMESPACE

class windowCalendar:public QMainWindow
{
	Q_OBJECT
public:
    windowCalendar();
    ~windowCalendar();

private slots:
//menu
    void importXML();
    void exportXML();


//lowlayout
    void sortOption();
    void searchButtonClicked();
    void currentDateButtonClicked();

//calendar cell  event
     void popUpTag();
     void seletedDateChanged();
//Tagpopup different case
     void oneEventPopUpTag(vector<Event*> event,QDate selectedDate);
     void mutiEventPopUpTag(vector<Event*> event,QDate selectedDate);
//
//tabWidget
     void removeTag(int);
     void closeTag();
private:
 //calendar initialize
    void createItem();
    void createProperty();
    void createLayout();
    void createConnection();


//port for gui
    void highlightDateWithEvent (QDate date);
    void clearDateWithEvent (QDate date);
    void setDisplayEvent(vector<Event*> event);
    void clearDisplayEvent(vector<Event*> event);

    void highlightSearchDateWithEvent(QDate date);
    void clearSearchDateWithEvent(QDate date);
    void setSearchEvent(vector<Event*> event);
    void clearSearchEvent(vector<Event*> event);



private:
    QIcon* icon;
    QLabel* stateLable;

    QString currentDirectory;
    QWidget* mainWidget;

    QMenu* fileMenu;
	QAction* importXMLAction;
	QAction* exportXMLAction;
	QAction* exitAction;

    QCalendarWidget* calendarGui;

	QDateEdit* fromDateEdit;
	QDateEdit* endDateEdit;
	QLabel*   fromDateLabel;
	QLabel*   endDateLabel;
    QLabel*   sortOptionLabel;

	QComboBox* sortOptionBox;
    QLineEdit* searchLineEdit;
    QPushButton* searchButton;
    QPushButton* currentDateButton;
    cellTag* tag;
    QTabWidget* tagStack;

    Calendar* calendar;


};
#endif
