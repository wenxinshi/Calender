//
//  Filter.h
//  Calendar
//
//  Created by Jiawei Shi on 4/3/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_Filter_h
#define Calendar_Filter_h

#include <iostream>
#include <string>
#include <vector>

#include "Event.h"
#include "Time.h"

using namespace std;

class Filter{
private:
    vector<string> split_helper(string s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
    
    //Parse the mm/dd/yyyy format into Time object
    void setDate(string timeInfo,Time* time){
        vector<string> date = split(timeInfo,'/');
        time->setMonth(date[0]);
        time->setDay(date[1]);
        time->setYear(date[2]);
    }
    
    //Parse the hh:mm:ss format into Time object
    void setTime(string timeInfo, Time* time){
        vector<string> vector = split(timeInfo, ':');
        time->setHour(vector[0]);
        time->setMinute(vector[1]);
        time->setSecond(vector[2]);
    }
    
    virtual string getFilterName() = 0;
    
    virtual bool isThisEventValid(string keyword, Event* event) = 0;
    
public:
    bool isThisType(string name){
        return toLowercase(name) == toLowercase(getFilterName());
    }
    
    virtual vector<Event*> doFilter(vector<Event*> eventList, string keyword){
        vector<Event*> result;
        for(int i=0; i<(int)eventList.size(); i++){
            Event* current = eventList[i];
            if(isThisEventValid(keyword,current))
                result.push_back(current);
        }
        return result;
    }
    
    //Convert the string into lower case 
    string toLowercase(string input){
        string result = input;
        for(int i=0; i<(int)input.size(); i++){
            result[i] = tolower(input[i]);
        }
        return result;
    }
    
    //Parse the time format like mm/dd/yyyy hh:mm:ss
    //Store the elements of time by sequence 
    Time* getTimeInfo(string timeInfo){
        vector<string> vector = split(timeInfo, ' ');
        
        Time* result = new Time();
        setDate(vector[0], result);
        setTime(vector[1],result);
        return result;
    }
    
    //Split the string with delim
    vector<string> split(const string s, char delim) {
        std::vector<std::string> elems;
        return split_helper(s, delim, elems);
    }


};

#endif
