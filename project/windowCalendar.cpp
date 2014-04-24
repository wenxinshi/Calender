#include <QtGui>

#include "windowCalendar.h"
#include <iostream>

windowCalendar::windowCalendar(){
    createItem();
    createProperty();
    createLayout();
    createConnection();
}
windowCalendar::~windowCalendar(){
    delete this;
    if(!(tag==0))
    delete tag;
    delete tagStack;
}
//menu
void windowCalendar::importXML(){
    QString filter="XML (*.xml)";
    currentDirectory=QFileDialog::getOpenFileName(0,"open file",
                                                 currentDirectory,filter);  
    if(currentDirectory!=""){
        if(calendar->addNewCalendar(currentDirectory.toStdString())){
            setDisplayEvent(calendar->getEventList());
            qDebug()<<"here1";

        }
        else{
                        QMessageBox msgBox;
                       // msgBox.move(mainWidget);
                        msgBox.setText("Error.");
                        msgBox.setInformativeText("File can't be parsed!");
                        msgBox.exec();
        }
    }
}
void windowCalendar::exportXML(){
    currentDirectory=QFileDialog::getSaveFileName( 0,"open file",
                                                        currentDirectory,"xml (*.xml)");
    qDebug()<<currentDirectory;
    if(currentDirectory!=""){
        calendar->outputToXMLFile(currentDirectory.toStdString());
        //setDisplayEvent(calendar->getDisplayedList());
    }
}
//lowlayout
void windowCalendar::sortOption(){}
void windowCalendar::currentDateButtonClicked(){
    calendarGui->setSelectedDate(QDate::currentDate());
}
void windowCalendar::searchButtonClicked(){
    QString sortOption=sortOptionBox->currentText();
    QString searchText=searchLineEdit->text();
    QString fromDateText=fromDateEdit->date().toString("yyyy-MM-dd");
    QString endDateText=endDateEdit->date().toString("yyyy-MM-dd");
    vector<string> info;
    info.insert(info.begin(),fromDateText.toStdString());
    info.insert(info.begin()+1,endDateText.toStdString());
    info.insert(info.begin()+2,sortOption.toStdString());
    info.insert(info.begin()+3,searchText.toStdString());

    clearSearchEvent(calendar->getDisplayedList());
    calendar->setDisplayedEvents(info);
   // calendar->sort(info[3],true);
    setSearchEvent(calendar->getDisplayedList());
}
//calendarGui cell  event
void windowCalendar::popUpTag(){
    QDate selectedDate=calendarGui->selectedDate();
    vector<Event*> tempEvent=calendar->eventsOnSelectedDate(selectedDate.toString("yyyy-MM-dd").toStdString());
 //   vector<Event*> tempEvent;
//    tempEvent.insert(tempEvent.begin(),new Event());
//    tempEvent.insert(tempEvent.begin()+1,new Event());
//    tempEvent.insert(tempEvent.begin()+2,new Event());
//    tempEvent.insert(tempEvent.begin()+3,new Event());
//    tempEvent.insert(tempEvent.begin()+4,new Event());
//    tempEvent.insert(tempEvent.begin()+5,new Event());

    if(tempEvent.size()!=0){
        if(tempEvent.size()==1)
            oneEventPopUpTag(tempEvent,selectedDate);
        else{
            mutiEventPopUpTag(tempEvent,selectedDate);
        }
    }

}

void windowCalendar::oneEventPopUpTag(vector<Event*> tempEvent,QDate selectedDate){
        delete tag;

        string subject_t=tempEvent[0]->getSubject();
        QString subject=QString::fromUtf8(subject_t.c_str());

        int hh=tempEvent[0]->getStartTime()->getHour();
        int mm=tempEvent[0]->getStartTime()->getMinute();
        int ss=tempEvent[0]->getStartTime()->getSecond();
        QTime from(hh,mm,ss);

        hh=tempEvent[0]->getEndTime()->getHour();
        mm=tempEvent[0]->getEndTime()->getMinute();
        ss=tempEvent[0]->getEndTime()->getSecond();
        QTime end(hh,mm,ss);

        string description_t=tempEvent[0]->getDescription();
        QString description=QString::fromUtf8(description_t.c_str());

        string location_t=tempEvent[0]->getLocation();
        QString location=QString::fromUtf8(location_t.c_str());

        tag=new cellTag(selectedDate,subject,from,end,description,location,0);
        tag=new cellTag(selectedDate,subject,from,end,description,location,0);
        tag->setVisible(true);
        tag->move(QCursor::pos());
}

void windowCalendar::mutiEventPopUpTag(vector<Event*> tempEvent,QDate selectedDate){
    delete tagStack;
    tagStack=new QTabWidget;
    for(int i=0;i<(int) tempEvent.size();i++){
        cellTag* tagTemp;
        string subject_t=tempEvent[i]->getSubject();
        QString subject=QString::fromUtf8(subject_t.c_str());

        int hh=tempEvent[i]->getStartTime()->getHour();
        int mm=tempEvent[i]->getStartTime()->getMinute();
        int ss=tempEvent[i]->getStartTime()->getSecond();
        QTime from(hh,mm,ss);

        hh=tempEvent[i]->getEndTime()->getHour();
        mm=tempEvent[i]->getEndTime()->getMinute();
        ss=tempEvent[i]->getEndTime()->getSecond();
        QTime end(hh,mm,ss);

        string description_t=tempEvent[i]->getDescription();
        QString description=QString::fromUtf8(description_t.c_str());

        string location_t=tempEvent[i]->getLocation();
        QString location=QString::fromUtf8(location_t.c_str());

        tagTemp=new cellTag(selectedDate,subject,from,end,description,location,0);
//      tagStack->addTab(tagTemp,subject);
        tagStack->insertTab(i,tagTemp,subject.leftJustified(10,'.',true));
        connect(tagTemp,SIGNAL(closeButtonFinished()),this,SLOT(closeTag()));
    }
    connect(tagStack,SIGNAL(tabCloseRequested(int)),this,SLOT(removeTag(int)));
    tagStack->setVisible(true);
    tagStack->setTabsClosable(true);
    tagStack->setFixedSize(240,360);
    tagStack->move(QCursor::pos());
    //tagStack->setWindowFlags(Qt::FramelessWindowHint);
}

void windowCalendar::seletedDateChanged(){
    tag->close();
    tagStack->close();
}

//calendarGui initialize

void windowCalendar::createItem(){
    mainWidget=new QWidget;
    tag=new cellTag(0);
    tagStack=new QTabWidget(0);
    currentDirectory=QDir::homePath();

     icon=new QIcon;
    stateLable=new QLabel("Calendar event search");


    fileMenu=menuBar()->addMenu("&File");
    importXMLAction=new QAction("&Import XML",mainWidget);
    exportXMLAction=new QAction("&Export XML",mainWidget);
    exitAction=new QAction("&Exit",mainWidget);

    fromDateLabel=new QLabel("From:",mainWidget);
    fromDateEdit=new QDateEdit(mainWidget);

    endDateLabel=new QLabel("End:",mainWidget);
    endDateEdit=new QDateEdit(mainWidget);

    calendarGui=new QCalendarWidget(mainWidget);

    sortOptionLabel=new QLabel("Sort:",mainWidget);
    sortOptionBox=new QComboBox(mainWidget);

    searchLineEdit=new QLineEdit(mainWidget);
    searchButton=new QPushButton("Search",mainWidget);
    currentDateButton=new QPushButton("Today",mainWidget);

    calendar=new Calendar();
}

void windowCalendar::createProperty(){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    setCentralWidget(mainWidget);

    tag->setVisible(false);
    tagStack->setVisible(false);

    setWindowTitle(tr("Calendar"));
    setMinimumSize(200, 200);
    resize(600, 600);

    fileMenu->addAction(importXMLAction);
    fileMenu->addAction(exportXMLAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    fromDateEdit->setDisplayFormat("MMM d yyyy");
    fromDateEdit->setDateRange(calendarGui->minimumDate(),calendarGui->maximumDate());
    fromDateEdit->setCalendarPopup(true);
    fromDateEdit->setDate(QDate::currentDate().addYears(-1));
    fromDateLabel->setBuddy(fromDateEdit);
    fromDateLabel->setAlignment(Qt::AlignCenter);
    fromDateLabel->setStyleSheet("background:white;");

    endDateEdit->setDisplayFormat("MMM d yyyy");
    endDateEdit->setDateRange(calendarGui->minimumDate(),calendarGui->maximumDate());
    endDateEdit->setDate(QDate::currentDate().addYears(1));
    endDateEdit->setCalendarPopup(true);
    endDateLabel->setBuddy(fromDateEdit);
    endDateLabel->setAlignment(Qt::AlignCenter);
    endDateLabel->setStyleSheet("background:white;");

    calendarGui->setDateEditEnabled(true);
    calendarGui->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    calendarGui->setMinimumDate(QDate(1900, 1, 1));
    calendarGui->setMaximumDate(QDate(2100, 1, 1));
    calendarGui->setGridVisible(true);


    sortOptionBox->addItem("All Included");
    sortOptionBox->addItem("Subject");
    sortOptionBox->addItem("StartDate");
    sortOptionBox->addItem("EndDate");
    sortOptionBox->addItem("Description");
    sortOptionBox->addItem("Location");

    sortOptionLabel->setAlignment(Qt::AlignCenter);
    sortOptionLabel->setStyleSheet("background:white;");

    searchButton->setStyleSheet("background:white;");

    currentDateButton->setStyleSheet("background:white;");

    searchLineEdit->setPlaceholderText("word or mm/dd/yyyy");
}

void windowCalendar::createLayout(){
//    QHBoxLayout* topLayout=new QHBoxLayout;
//    topLayout->addWidget(fromDateLabel);
//    topLayout->addWidget(fromDateEdit);
//    topLayout->addStretch();
//    topLayout->addWidget(endDateLabel);
//    topLayout->addWidget(endDateEdit);


//    QHBoxLayout* lowLayout=new QHBoxLayout;
//    lowLayout->addWidget(sortOptionLabel);
//    lowLayout->addWidget(sortOptionBox);
//    lowLayout->addStretch();
//    lowLayout->addWidget(searchLineEdit);
//    lowLayout->addWidget(searchButton);
//    lowLayout->addStretch();
//    lowLayout->addWidget(currentDateButton);

   
//    QVBoxLayout* verticalLayout=new QVBoxLayout;
//    verticalLayout->addLayout(topLayout);

//    verticalLayout->addWidget(calendarGui);

//    verticalLayout->addLayout(lowLayout);

//    mainWidget->setLayout(verticalLayout);

    QGridLayout* leftGridLayout=new QGridLayout;
    leftGridLayout->addWidget(fromDateLabel,0,0);
    leftGridLayout->addWidget(fromDateEdit,0,1);
    leftGridLayout->addWidget(sortOptionLabel,1,0);
    leftGridLayout->addWidget(sortOptionBox,1,1);

    QGridLayout* midGridLayout=new QGridLayout;
    midGridLayout->addWidget(endDateLabel,0,0);
    midGridLayout->addWidget(endDateEdit,0,1);
    midGridLayout->addWidget(searchLineEdit,1,0,1,2);

    QVBoxLayout* rightLayout=new QVBoxLayout;
    rightLayout->addWidget(currentDateButton);
    rightLayout->addWidget(searchButton);

    QHBoxLayout* hLayout=new QHBoxLayout;
    hLayout->addSpacing(25);
    hLayout->addLayout(leftGridLayout);
    hLayout->addSpacing(25);
    hLayout->addLayout(midGridLayout);
    hLayout->addSpacing(25);
    hLayout->addLayout(rightLayout);
    hLayout->addSpacing(25);

    QGroupBox* toolGroupBox=new QGroupBox;
    toolGroupBox->setLayout(hLayout);
    toolGroupBox->setFlat(true);

    QVBoxLayout* vLayout=new QVBoxLayout;
    vLayout->addWidget(toolGroupBox);
    vLayout->addWidget(calendarGui);
    mainWidget->setLayout(vLayout);
    mainWidget->setStyleSheet("background-image: url(:/resourse/summer.jpg);}");

 }

void windowCalendar::createConnection(){
    connect(importXMLAction,SIGNAL(triggered()),this,SLOT(importXML()));
    connect(exportXMLAction,SIGNAL(triggered()),this,SLOT(exportXML()));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
    //calendarGui->dateEdit's user defined
    connect(calendarGui,SIGNAL(selectionChanged()),this,SLOT(seletedDateChanged()));
    //double click calendarGui->cellTag's user defined
    connect(calendarGui,SIGNAL(activated(QDate)),this,SLOT(popUpTag()));
    //Button->current calendarGui's user defined
    connect(currentDateButton,SIGNAL(clicked()),this,SLOT(currentDateButtonClicked()));
    connect(searchButton,SIGNAL(clicked()),this,SLOT(searchButtonClicked()));
}

//port for gui

void windowCalendar::highlightDateWithEvent  (QDate date){
   QTextCharFormat cf = calendarGui->dateTextFormat( date);
    if(!(cf.fontItalic()||cf.fontUnderline())){
        cf.setFontItalic(true);
        cf.setFontUnderline(true);
        calendarGui->setDateTextFormat( date, cf );
    }
}

void windowCalendar::clearDateWithEvent(QDate date){
    QTextCharFormat cf = calendarGui->dateTextFormat( date);
     if(cf.fontItalic()||cf.fontUnderline()){
         cf.setFontItalic(false);
         cf.setFontUnderline(false);
         calendarGui->setDateTextFormat(date, cf );
     }

}

void windowCalendar::setDisplayEvent(vector<Event*> event){
    for(vector<Event*>::iterator it=event.begin();it!=event.end();++it){
        int year=(*it)->getStartTime()->getYear();
        int month=(*it)->getStartTime()->getMonth();
        int day=(*it)->getStartTime()->getDay();
        QDate date(year,month,day);
        highlightDateWithEvent(date);
    }
}

void windowCalendar::clearDisplayEvent(vector<Event*> event){
    for(vector<Event*>::iterator it=event.begin();it!=event.end();++it){
        int year=(*it)->getStartTime()->getYear();
        int month=(*it)->getStartTime()->getMonth();
        int day=(*it)->getStartTime()->getDay();
        QDate date(year,month,day);
        clearDateWithEvent(date);
    }

}

void windowCalendar::highlightSearchDateWithEvent(QDate date){
    QTextCharFormat cf = calendarGui->dateTextFormat( date);
    QBrush brush;
    brush.setColor( Qt::gray );
    cf.setBackground(brush);
    calendarGui->setDateTextFormat( date, cf );
//    QTextCharFormat cf = calendarGui->dateTextFormat( date);
//    QFont temp=cf.font();
//    temp.setBold(true);
//    cf.setFont(temp);
//    calendarGui->setDateTextFormat( date, cf );

}

void windowCalendar::clearSearchDateWithEvent(QDate date){
    QTextCharFormat cf = calendarGui->dateTextFormat( date);
    QBrush brush;
    brush.setColor(Qt::white );
    cf.setBackground(brush);
    calendarGui->setDateTextFormat( date, cf );
//    QTextCharFormat cf = calendarGui->dateTextFormat( date);
//    QFont temp=cf.font();
//    temp.setBold(false);
//    cf.setFont(temp);
//    calendarGui->setDateTextFormat( date, cf );
}

void windowCalendar::setSearchEvent(vector<Event*> event){
    for(vector<Event*>::iterator it=event.begin();it!=event.end();++it){
        int year=(*it)->getStartTime()->getYear();
        int month=(*it)->getStartTime()->getMonth();
        int day=(*it)->getStartTime()->getDay();
        QDate date(year,month,day);
        highlightSearchDateWithEvent(date);
    }


}

void windowCalendar::clearSearchEvent(vector<Event*> event){
    for(vector<Event*>::iterator it=event.begin();it!=event.end();++it){
        int year=(*it)->getStartTime()->getYear();
        int month=(*it)->getStartTime()->getMonth();
        int day=(*it)->getStartTime()->getDay();
        QDate date(year,month,day);
        clearSearchDateWithEvent(date);
    }

}

void windowCalendar::closeTag(){
        tagStack->close();

}

void windowCalendar::removeTag(int){
    tagStack->removeTab(tagStack->currentIndex());
    if(tagStack->currentIndex()==-1)
        tagStack->close();

}

