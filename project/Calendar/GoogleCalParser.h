//
//  GoogleCalParser.h
//  Calendar
//
//  Created by Jiawei Shi on 4/2/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_GoogleCalParser_h
#define Calendar_GoogleCalParser_h

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "CalParser.h"
#include "Event.h"

using namespace std;

class GoogleCalParser : public CalParser{
private:
    string convertMonthFormat(string input){
        if(input == "Jan")
            return "1";
        else if(input == "Feb")
            return "2";
        else if(input == "Mar")
            return "3";
        else if(input == "Apr")
            return "4";
        else if(input == "May")
            return "5";
        else if(input == "Jun")
            return "6";
        else if(input == "Jul")
            return "7";
        else if(input == "Aug")
            return "8";
        else if(input == "Sep")
            return "9";
        else if(input == "Oct")
            return "10";
        else if(input == "Nov")
            return "11";
        else
            return "12";
    }
    
    pair<string, string> parseTimeInfo_12H(string input){
        //cout<<"Input is "<<input<<endl;
        int hour;
        string minute = "0";
        string extension = input.substr(input.size()-2,2);
        if(input.find(":") != string::npos){
            vector<string> vector = split(input, ':');
            hour = atoi(vector[0].c_str());
            minute = vector[1].substr(0,2);
        }
        else
            hour = atoi(input.substr(0,input.size()-2).c_str());
        
        if(extension == "pm" && hour!=12)
            hour = hour + 12;
        else if(extension == "am" && hour==12)
            hour = 0;
        
        if(input.find("am") == string::npos && input.find("pm") == string::npos)
            return pair<string, string>("0","0");
        else
            return pair<string,string>(QString::number(hour).toStdString(),minute);
    }
    
    virtual string getPassword(){
        return "id";
    }
    
    virtual string getEventTag(){
        return "entry";
    }
    
    virtual string getSubjectTag(){
        return "title";
    }
    
    virtual string getStartDateTag(){
        return "summary";
    }

    virtual string getStartTimeTag(){
        return "summary";
    }
    
    virtual string getEndDateTag(){
        return "summary";
    }
    
    virtual string getEndTimeTag(){
        return "summary";
    }
    
    virtual string getDescriptionTag(){
        return "content";
    }
    
    virtual string getLocaitonTag(){
        return "summary";
    }
    
    virtual void setStartDate(string dateInfo, Event* event){
        string year, month, day;
        if(dateInfo.find("Recurring Event") == string::npos){
            string when = "When: ";
            unsigned long startPos = dateInfo.find(when)+9;
            vector<string> vector = split(dateInfo.substr(startPos+1), ' ');
            month = convertMonthFormat(vector[0]);
            day = vector[1].substr(0,vector[1].size()-1);
            year = vector[2].substr(0,4);
            
        }else{
            string start = "First start: ";
            unsigned long startPos = dateInfo.find(start)+12;
            vector<string> vector = split(dateInfo.substr(startPos+1), ' ');
            year = vector[0].substr(0,4);
            month = vector[0].substr(5,2);
            day = vector[0].substr(8,2);
        }
        event->setStartDate(year, month, day);
    }
    
    virtual void setEndDate(string dateInfo, Event* event){
        string year, month, day;
        if(dateInfo.find("Recurring Event") == string::npos){
            string when = "When: ";
            unsigned long startPos = dateInfo.find(when)+9;
            vector<string> vector = split(dateInfo.substr(startPos+1), ' ');
            month = convertMonthFormat(vector[0]);
            day = vector[1].substr(0,vector[1].size()-1);
            year = vector[2].substr(0,4);
            
        }else{
            string start = "First start: ";
            unsigned long startPos = dateInfo.find(start)+12;
            vector<string> vector = split(dateInfo.substr(startPos+1), ' ');
            year = vector[0].substr(0,4);
            month = vector[0].substr(5,2);
            day = vector[0].substr(8,2);
        }
        event->setEndDate(year, month, day);
    }
    
    virtual void setStartTime(string timeInfo, Event* event){
        string hour, minute, second;
        if(timeInfo.find("Recurring Event") == string::npos){
            string when = "When: ";
            unsigned long startPos = timeInfo.find(when)+9;
            vector<string> vector = split(timeInfo.substr(startPos+1), ' ');
            pair<string, string> result = parseTimeInfo_12H(vector[3]);
            hour = result.first;
            minute = result.second;
            second = "0";
        }else{
            string start = "First start: ";
            unsigned long startPos = timeInfo.find(start)+12;
            vector<string> vector = split(timeInfo.substr(startPos+1), ' ');
            hour = vector[1].substr(0,2);
            minute = vector[1].substr(3,2);
            second = vector[1].substr(6,2);
        }
        event->setStartTime(hour,minute,second);
    }
    
    virtual void setEndTime(string timeInfo, Event* event){
        if(timeInfo.find("Recurring Event") == string::npos){
            string when = "When: ";
            unsigned long startPos = timeInfo.find(when)+9;
            vector<string> vector = split(timeInfo.substr(startPos+1), ' ');
            pair<string, string> result = parseTimeInfo_12H(vector[5].substr(0,vector[5].size()-6));
            string hour = result.first;
            string minute = result.second;
            string second = "0";
            event->setEndTime(hour, minute, second);
        }
        else{
            string tag = "Duration: ";
            unsigned long startPos = timeInfo.find(tag) + 9;
            vector<string> vector = split(timeInfo.substr(startPos + 1), ' ');
            int addedSeconds = atof(vector[0].c_str());
            Time* startTime = event->getStartTime();
            Time* endTime = startTime ->addSeconds(addedSeconds);
            event->setEndTime(endTime);
        }
    }
    
    virtual void setDescription(string info, Event* event){
        event->setDescription(info);
    }
    
    virtual void setLocation(string info, Event* event){
        string where = "Where: ";
        unsigned long beginPos = info.find(where.c_str());
        if(beginPos == string::npos){
            event->setLocation("Not Specified");
        }
        else{
            unsigned long endPos = info.substr(beginPos+where.size()).find("<");
            string location = info.substr(beginPos+where.size(), endPos);
            event->setLocation(location);
        }
        
    }
    
    virtual void setSubject(string info, Event* event){
        event->setSubject(info);
    }
};

#endif
