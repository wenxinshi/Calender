//
//  DukeBasketBallCalParser.h
//  Calendar
//
//  Created by Jiawei Shi on 4/3/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_DukeBasketBallCalParser_h
#define Calendar_DukeBasketBallCalParser_h

#include <iostream>
#include <string>
#include <vector>

#include "CalParser.h"
#include "Event.h"

using namespace std;

class DukeBasketBallCalParser: public CalParser{
private:
    virtual string getPassword(){
        return "Calendar";
    }
    
    virtual string getEventTag(){
        return "Calendar";
    }
    
    virtual string getSubjectTag(){
        return "Subject";
    }
    
    virtual string getStartDateTag(){
        return "StartDate";
    }
    
    virtual string getStartTimeTag(){
        return "StartTime";
    }
    
    virtual string getEndDateTag(){
        return "EndDate";
    }
    
    virtual string getEndTimeTag(){
        return "EndTime";
    }
    
    virtual string getDescriptionTag(){
        return "Description";
    }
    
    virtual string getLocaitonTag() {
        return "Location";
    }
    
    
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
        vector<string> result = getStandardDateInfo(dateInfo);
        event->setStartDate(result[0],result[1],result[2]);
    }
    
    virtual void setEndDate(string dateInfo, Event* event){
        vector<string> result = getStandardDateInfo(dateInfo);
        event->setEndDate(result[0],result[1],result[2]);    }
    
    virtual void setStartTime(string timeInfo, Event* event){
        vector<string> result = getStandardTimeInfo(timeInfo);
        event->setStartTime(result[0], result[1], result[2]);
    }
    
    virtual void setEndTime(string timeInfo, Event* event){
        vector<string> result = getStandardTimeInfo(timeInfo);
        event->setEndTime(result[0], result[1], result[2]);
    }
    
    vector<string> getStandardDateInfo(string dateInfo){
        unsigned long pos1 = dateInfo.find('/');
        unsigned long pos2 = dateInfo.substr(pos1+1).find('/') + pos1 + 1;
        string month = dateInfo.substr(0,pos1);
        string day = dateInfo.substr(pos1+1,pos2-pos1-1);
        string year = dateInfo.substr(pos2+1);

        vector<string> result;
        result.push_back(year);
        result.push_back(month);
        result.push_back(day);
        return result;
    }
    
    vector<string> getStandardTimeInfo(string timeInfo){
        unsigned long pos1 = timeInfo.find(':');
        unsigned long pos2 = timeInfo.substr(pos1+1).find(':') + pos1 + 1;
        unsigned long pos3 = timeInfo.find(" ");
        
        string hour = timeInfo.substr(0,pos1);
        string minute = timeInfo.substr(pos1+1,2);
        string second = timeInfo.substr(pos2+1,2);
        string extend = timeInfo.substr(pos3+1,2);
        
        int h = atoi(hour.c_str());
        if(h == 12 && extend == "AM")
            h = 0;
        else if(h != 12 && extend == "PM")
            h = h + 12;
        
        string convertedHour = QString::number(h).toStdString();
        vector<string> result;
        result.push_back(convertedHour);
        result.push_back(minute);
        result.push_back(second);
        return result;
    }
    
};


#endif
