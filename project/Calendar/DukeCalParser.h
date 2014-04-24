//
//  DukeCalParser.h
//  Calendar
//
//  Created by Jiawei Shi on 4/3/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_DukeCalParser_h
#define Calendar_DukeCalParser_h

#include <iostream>
#include <string>
#include <vector>

#include "CalParser.h"
#include "Event.h"

using namespace std;

class DukeCalParser: public CalParser{
private:
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
        string year = dateInfo.substr(0,4);
        string month = dateInfo.substr(4,2);
        string day = dateInfo.substr(6,2);
        event->setStartDate(year, month, day);
    }
    
    virtual void setEndDate(string dateInfo, Event* event){
        string year = dateInfo.substr(0,4);
        string month = dateInfo.substr(4,2);
        string day = dateInfo.substr(6,2);
        event->setEndDate(year, month, day);
    }
    
    virtual void setStartTime(string timeInfo, Event* event){
        string hour = timeInfo.substr(9,2);
        string minute = timeInfo.substr(11,2);
        string second = timeInfo.substr(13,2);
        event->setStartTime(hour, minute, second);
    }
    
    virtual void setEndTime(string timeInfo, Event* event){
        string hour = timeInfo.substr(9,2);
        string minute = timeInfo.substr(11,2);
        string second = timeInfo.substr(13,2);
        event->setEndTime(hour, minute, second);
    }
    
    virtual string getPassword(){
        return "event";
    }
    
    virtual string getEventTag(){
        return "event";
    }
    
    virtual string getSubjectTag(){
        return "summary";
    }
    
    virtual string getStartDateTag(){
        return "start utcdate";
    }
    
    virtual string getStartTimeTag(){
        return "start utcdate";
    }
    
    virtual string getEndDateTag(){
        return "end utcdate";
    }
    
    virtual string getEndTimeTag(){
        return "end utcdate";
    }
    
    virtual string getDescriptionTag(){
        return "description";
    }
    
    virtual string getLocaitonTag(){
        return "location address";
    }
};

#endif
