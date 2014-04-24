//
//  CalParser.h
//  Calendar
//
//  Created by Jiawei Shi on 4/1/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_CalParser_h
#define Calendar_CalParser_h

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "tinyxml.h"
#include "Event.h"


class CalParser{
private:
    vector<string> split(string s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
    
    string getInfo(string tag, TiXmlNode* node){
        vector<string> vector = split(tag,' ');
        TiXmlNode* current = node;
        for(int i=0; i<(int)vector.size()-1; i++){
            current = current->FirstChild(vector[i].c_str());
        }
        return current->FirstChildElement(vector[vector.size()-1].c_str())->GetText();
    }

    virtual void setSubject(string info, Event* event) = 0;
    
    virtual void setDescription(string info, Event* event) = 0;
    
    virtual void setLocation(string info, Event* event) = 0;
    
    virtual void setStartDate(string dateInfo, Event* event) = 0;
    
    virtual void setEndDate(string dateInfo, Event* event) = 0;
    
    virtual void setStartTime(string timeInfo, Event* event) = 0;
    
    virtual void setEndTime(string timeInfo, Event* event) = 0;
    
    virtual string getPassword() = 0;
    
    virtual string getEventTag() = 0;
    
    virtual string getSubjectTag() = 0;
    
    virtual string getStartDateTag() = 0;
    
    virtual string getStartTimeTag() = 0;
    
    virtual string getEndDateTag()= 0;
    
    virtual string getEndTimeTag() = 0;
    
    virtual string getDescriptionTag() = 0;
    
    virtual string getLocaitonTag() = 0;
    
public:
    bool isThisType(string filePath){
        TiXmlDocument doc(filePath.c_str());
        bool loadOkay = doc.LoadFile();
        
        if(!loadOkay){
//            cout<<"Error in load the file"<<endl;
//            exit(1);
            return false;
        }
        
        string value = doc.FirstChildElement()->FirstChild()->Value();
        return value == getPassword();
    }
    
    vector<Event*> doParse(string filePath){
        vector<Event*> eventList;
        
        TiXmlDocument doc(filePath.c_str());
        bool loadOkay = doc.LoadFile();
        
        if(!loadOkay){
            cout<<"Error in load the file"<<endl;
            exit(1);
        }
        
        TiXmlNode* current = doc.FirstChildElement()->FirstChild(getEventTag().c_str());
        
        while(current != NULL){
            Event* currentEvent = new Event();
            
            string subject = getInfo(getSubjectTag(), current);
            setSubject(subject,currentEvent);
                        
            string startDate = getInfo(getStartDateTag(), current);
            setStartDate(startDate, currentEvent);
            
            string startTime = getInfo(getStartTimeTag(), current);
            setStartTime(startTime, currentEvent);
            
            string endDate = getInfo(getEndDateTag(), current);
            setEndDate(endDate, currentEvent);
            
            string endTime = getInfo(getEndTimeTag(), current);
            setEndTime(endTime, currentEvent);
    
            string description = getInfo(getDescriptionTag(), current);
            setDescription(description,currentEvent);
            
            string location = getInfo(getLocaitonTag(), current);
            setLocation(location,currentEvent);
            
            eventList.push_back(currentEvent);
            current = current->NextSiblingElement();
        }
        return eventList;
    }
    
    vector<string> split(const string &s, char delim) {
        std::vector<std::string> elems;
        return split(s, delim, elems);
    }

};

#endif
