#ifndef CELLTAG_H
#define CELLTAG_H

#include <QWidget>
#include<QTime>
#include<QLabel>
#include<QTextEdit>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QTime>
#include<QSizePolicy>
#include<QDebug>
#include<QHBoxLayout>
#include<QDateEdit>
#include<QTimeEdit>
#include<QPushButton>
class cellTag : public QWidget
{
    Q_OBJECT

private:
    //main properties
    QDateEdit* currentDate;
    QTextEdit* subject;
    QTimeEdit* from;
    QTimeEdit* end;
    QTextEdit* description;
    QTextEdit* location;
   // temporal
    QLabel* subjectLabel;
    QLabel* fromLabel;
    QLabel* endLabel;
    QLabel* descriptionLabel;
    QLabel* locationLabel;
   //
    QPushButton* editButton;
    QPushButton* finishButton;
    QPushButton* closeButton;

private:
    void createObject(QDate _date,QString _subject,QTime _from,
                      QTime _end,QString _description,QString _location);
    void createLayout();
    void createConncetion();
    void createObjectProperty();
private slots:
    void editButtonClick();
    void finishButtonClick();
    void closeButtonClick();


signals:
    void editButtonFinished();
    void finishButtonFinished();
    void closeButtonFinished();


public:
    cellTag(QDate _date,QString _subject,QTime _from,
             QTime _end,QString _description,QString _location,QWidget *parent);
    cellTag(QWidget* parent);


};

#endif // CELLTAG_H
