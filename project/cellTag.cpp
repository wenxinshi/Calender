#include "cellTag.h"

cellTag::cellTag(QDate _date,QString _subject,QTime _from,
                 QTime _end,QString _description,QString _location,QWidget *parent=0): QWidget(parent)
{
    createObject(_date,_subject,_from,
                 _end,_description,_location);
    createObjectProperty();
    createLayout();
    createConncetion();

}


cellTag::cellTag(QWidget* parent=0):QWidget(parent)
{
    createObject(QDate(1900,1,1),"",QTime(0,0,0,0),
                 QTime(0,0,0,0),"","");
    createObjectProperty();
    createLayout();
    createConncetion();

}



void cellTag::createObject(QDate _date,QString _subject,QTime _from,
                           QTime _end,QString _description,QString _location){
    currentDate=new QDateEdit(_date,this);
    subject=new QTextEdit(_subject,this);
    from=new QTimeEdit(_from,this);
    end=new QTimeEdit(_end,this);
    description=new QTextEdit(_description,this);
    location=new QTextEdit(_location,this);

    subjectLabel=new QLabel("Subject:",this);
    fromLabel=new QLabel("From:",this);
    endLabel=new QLabel("End:",this);
    descriptionLabel=new QLabel("Description:",this);
    locationLabel=new QLabel("Location:",this);

    editButton=new QPushButton("Edit",this);
    finishButton=new QPushButton("Finish",this);
    closeButton=new QPushButton("Close",this);
}


void cellTag::createObjectProperty(){

    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setFixedSize(240,320);
    //this->setStyleSheet("background:lightGray;");

    currentDate->setFrame(false);
    currentDate->setDisplayFormat("MMM-dd-yyyy");
    subject->setFrameShape(QFrame::NoFrame);
    from->setFrame(false);
    end->setFrame(false);
    description->setFrameShape(QFrame::NoFrame);
    location->setFrameShape(QFrame::NoFrame);

    currentDate->setReadOnly(true);
    subject->setReadOnly(true);
    from->setReadOnly(true);
    end->setReadOnly(true);
    description->setReadOnly(true);
    location->setReadOnly(true);

    editButton->setVisible(true);
    finishButton->setVisible(false);

    subject->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    subject->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    description->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    description->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    location->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    location->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void cellTag::createLayout(){
    QHBoxLayout* hLayout0=new QHBoxLayout;
    QHBoxLayout* hLayout1=new QHBoxLayout;
    QHBoxLayout* hLayout2=new QHBoxLayout;
    QHBoxLayout* hLayout3=new QHBoxLayout;
    QHBoxLayout* hLayout4=new QHBoxLayout;
    QHBoxLayout* hLayout5=new QHBoxLayout;
    QHBoxLayout* hLayout6=new QHBoxLayout;
    QVBoxLayout*  vLayout=new QVBoxLayout;

    hLayout0->addWidget(currentDate);

    hLayout1->addWidget(subjectLabel);
    hLayout1->addWidget(subject);

    hLayout2->addWidget(fromLabel);
    hLayout2->addWidget(from);

    hLayout3->addWidget(endLabel);
    hLayout3->addWidget(end);

    hLayout4->addWidget(descriptionLabel);
    hLayout4->addStretch();

    hLayout5->addWidget(locationLabel);
    hLayout5->addWidget(location);

    hLayout6->addWidget(closeButton);
    hLayout6->addStretch();
    hLayout6->addWidget(finishButton);
    hLayout6->addWidget(editButton);

    vLayout->addLayout(hLayout0);
    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);
    vLayout->addLayout(hLayout3);
    vLayout->addLayout(hLayout4);
    vLayout->addWidget(description);
    vLayout->addLayout(hLayout5);
    vLayout->addLayout(hLayout6);

    this->setLayout(vLayout);
}

void cellTag::createConncetion(){
    connect(editButton,SIGNAL(clicked()),this,SLOT(editButtonClick()));
    connect(finishButton,SIGNAL(clicked()),this,SLOT(finishButtonClick()));
    connect(closeButton,SIGNAL(clicked()),this,SLOT(closeButtonClick()));
}

//slot
void cellTag::editButtonClick(){

    this->setStyleSheet("");

    currentDate->setFrame(true);
    subject->setFrameShape(QFrame::StyledPanel);
    from->setFrame(true);
    end->setFrame(true);
    description->setFrameShape(QFrame::StyledPanel);
    location->setFrameShape(QFrame::StyledPanel);

    currentDate->setCalendarPopup(true);

    currentDate->setReadOnly(false);
    subject->setReadOnly(false);
    from->setReadOnly(false);
    end->setReadOnly(false);
    description->setReadOnly(false);
    location->setReadOnly(false);

    subject->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    subject->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    description->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    description->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    location->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    location->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    editButton->setVisible(false);
    finishButton->setVisible(true);
    emit editButtonFinished();

}

void cellTag::finishButtonClick(){

   // this->setStyleSheet("background:lightGray;");

    currentDate->setFrame(false);
    currentDate->setDisplayFormat("MMM-dd-yyyy");
    subject->setFrameShape(QFrame::NoFrame);
    from->setFrame(false);
    end->setFrame(false);
    description->setFrameShape(QFrame::NoFrame);
    location->setFrameShape(QFrame::NoFrame);

    currentDate->setReadOnly(true);
    subject->setReadOnly(true);
    from->setReadOnly(true);
    end->setReadOnly(true);
    description->setReadOnly(true);
    location->setReadOnly(true);

    editButton->setVisible(true);
    finishButton->setVisible(false);

    subject->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    subject->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    description->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    description->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    location->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    location->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    currentDate->setCalendarPopup(false);
    emit finishButtonFinished();
}

void cellTag::closeButtonClick(){
    this->close();
    emit closeButtonFinished();
}
