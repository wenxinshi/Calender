//
//  Event.h
//  Calendar
//
//  Created by Jiawei Shi on 3/18/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_Event_h
#define Calendar_Event_h

#include "Time.h"
#include <QString>

using namespace std;

class Event{
private:
    string subject;
    Time* startTime;
    Time* endTime;
    string description;
    string location;

public:
    Event(){
        startTime = new Time();
        endTime = new Time();
    }
    
    Event(string n){
        subject = n;
        startTime = new Time();
        endTime = new Time();
    }
    
    Event* clone(){
        Event* newEvent = new Event();
        newEvent->setSubject(subject);
        newEvent->setStartTime(startTime);
        newEvent->setEndTime(endTime);
        newEvent->setDescription(description);
        newEvent->setLocation(location);
        return newEvent;
    }
    
    void setSubject(string s){
        subject = s;
    }
    
    void setStartDate(string year, string month, string day){
        startTime->setDay(day);
        startTime->setMonth(month);
        startTime->setYear(year);
    }

    void setEndDate(string year, string month, string day){
        endTime->setDay(day);
        endTime->setMonth(month);
        endTime->setYear(year);
    }

    void setStartTime(string hour, string minute, string second){
        startTime->setHour(hour);
        startTime->setMinute(minute);
        startTime->setSecond(second);
    }

    void setEndTime(string hour, string minute, string second){
        endTime->setHour(hour);
        endTime->setMinute(minute);
        endTime->setSecond(second);
    }
    
    void setStartTime(Time* t){
        startTime = t;
    }
    
    void setEndTime(Time* t){
        endTime = t;
    }

    void setDescription(string d){
        description = d;
    }

    void setLocation(string l){
        location = l;
    }
    
    string getSubject(){
        return subject;
    }
    
    string getDescription(){
        return description;
    }
    
    string getLocation(){
        return location;
    }
    
    Time* getStartTime(){
        return startTime;
    }
    
    Time* getEndTime(){
        return endTime;
    }
    
    string getStartTimeInfo(){
        return startTime->toString();
    }
    
    string getEndTimeInfo(){
        return endTime->toString();
    }
    
    string toString(){
        string result = "";
        result.append("subject is: ");
        result.append(subject+"\n");
        result.append("start time is: ");
        result.append(startTime->toString()+"\n");
        result.append("end time is: ");
        result.append(endTime->toString()+"\n");
        result.append("description is: ");
        result.append(description+"\n");
        result.append("location is: ");
        result.append(location+"\n");
        return result;
    }

    //Tell if this event occurs on the selected date
    //The format of dateInfo is yyyy-mm-dd
    bool isOnSelectedDate(string dateInfo){
        int year = atoi(dateInfo.substr(0,4).c_str());
        int month = atoi(dateInfo.substr(5,2).c_str());
        int day = atoi(dateInfo.substr(8,2).c_str());
        return year==startTime->getYear() && month==startTime->getMonth()&& day==startTime->getDay();
        //string year = dateInfo.substr(0,4);
//        string month = dateInfo.substr(5,2);
//        string day = dateInfo.substr(8,2);
//        return year == QString::number(startTime->getYear()).toStdString() && month == QString::number(startTime->getMonth()).toStdString() && day == QString(startTime->getDay()).toStdString();
    }

    //Tell if this event occurs after the selected date (inclusively)
    bool isAfterTheDate(string dateInfo){
        cout<<dateInfo<<endl;
        int year = atoi(dateInfo.substr(0,4).c_str());
        int month = atoi(dateInfo.substr(5,2).c_str());
        int day = atoi(dateInfo.substr(8,2).c_str());
        qDebug()<<year<<month<<day;
        if(year != startTime->getYear())
            return year < startTime->getYear();
        else if(month != startTime->getMonth())
            return month < startTime->getMonth();
        else
            return day <= startTime->getDay();
    }

    //Tell if this event occurs before the selected date (inclusively)
    bool isBeforeTheDate(string dateInfo){
        int year = atoi(dateInfo.substr(0,4).c_str());
        int month = atoi(dateInfo.substr(5,2).c_str());
        int day = atoi(dateInfo.substr(8,2).c_str());
        
        if(year != endTime->getYear())
            return year > endTime->getYear();
        else if(month != endTime->getMonth())
            return month > endTime->getMonth();
        else
            return day >= endTime->getDay();
    }

    bool isStartTimeOnThisDate(int y, int m, int d){
    return startTime->getYear()==y && startTime->getMonth() == m && startTime->getDay()==d;
    }

    bool isEndTimeOnThisDate(int y, int m, int d){
    return endTime->getYear()==y && endTime->getMonth()==m && endTime->getDay()==d;
    }
    
};

#endif
