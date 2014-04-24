//
//  UserDefinedCalParser.h
//  Calendar
//
//  Created by Jiawei Shi on 4/6/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_UserDefinedCalParser_h
#define Calendar_UserDefinedCalParser_h

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "CalParser.h"
#include "Event.h"

using namespace std;

class UserDefinedCalParser : public CalParser{
private:
    string password;
    string eventTag;
    string subjectTag;
    string startDateTag;
    string startTimeTag;
    string endDateTag;
    string endTimeTag;
    string descriptionTag;
    string locationTag;
    
    
    virtual void setSubject(string info, Event* event){
        event->setSubject(info);
    }
    
    virtual void setDescription(string info, Event* event){
        event->setDescription(info);
    }
    
    virtual void setLocation(string info, Event* event){
        event->setLocation(info);
    }
    
    virtual void setStartDate(string dateInfo, Event* event){
        unsigned long pos = dateInfo.find(" ");
        string date = dateInfo.substr(0,pos);
        vector<string> vector = split(date, '-');
        event->setStartDate(vector[0], vector[1], vector[2]);
    }
    
    virtual void setEndDate(string dateInfo, Event* event){
        unsigned long pos = dateInfo.find(" ");
        string date = dateInfo.substr(0,pos);
        vector<string> vector = split(date, '-');
        event->setEndDate(vector[0], vector[1], vector[2]);
    }
    
    virtual void setStartTime(string timeInfo, Event* event){
        unsigned long pos = timeInfo.find(" ");
        string time = timeInfo.substr(pos+1,8);
        vector<string> vector = split(time, ':');
        event->setStartTime(vector[0], vector[1], vector[2]);
    }
    
    virtual void setEndTime(string timeInfo, Event* event){
        unsigned long pos = timeInfo.find(" ");
        string time = timeInfo.substr(pos+1,8);
        vector<string> vector = split(time, ':');
        event->setEndTime(vector[0], vector[1], vector[2]);
    }
    
    virtual string getPassword(){
        return password;
    }
    
    virtual string getEventTag(){
        return eventTag;
    }
    
    virtual string getSubjectTag(){
        return subjectTag;
    }
    
    virtual string getStartDateTag(){
        return startDateTag;
    }
    
    virtual string getStartTimeTag(){
        return startTimeTag;
    }
    
    virtual string getEndDateTag(){
        return endDateTag;
    }
    
    virtual string getEndTimeTag(){
        return endTimeTag;
    }
    
    virtual string getDescriptionTag(){
        return descriptionTag;
    }
    
    virtual string getLocaitonTag(){
        return locationTag;
    }
    
public:
    
    void setPassword(string info){
        password = info;
    }
    
    void setEventTag(string info){
        eventTag = info;
    }
    
    void setSubjectTag(string info){
        subjectTag = info;
    }
    
    void setStartDateTag(string info){
        startDateTag = info;
    }

    void setStartTimeTag(string info){
        startTimeTag = info;
    }

    void setEndDateTag(string info){
        endDateTag = info;
    }

    void setEndTimeTag(string info){
        endTimeTag = info;
    }

    void setDescriptionTag(string info){
        descriptionTag = info;
    }

    void setLocationTag(string info){
        locationTag = info;
    }
    
};

#endif
