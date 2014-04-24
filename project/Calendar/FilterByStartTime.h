//
//  FilterByStartTime.h
//  Calendar
//
//  Created by Jiawei Shi on 4/3/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_FilterByStartTime_h
#define Calendar_FilterByStartTime_h

#include <iostream>
#include <string>
#include <vector>

#include "Filter.h"
#include "Event.h"

using namespace std;

class FilterByStartTime : public Filter{
private:
    virtual string getFilterName(){
        return "startDate";
    }
    
    //The keyword here contains the from time and to time
    //Its format is like this: mm/dd/yyyy hh:mm:ss-mm/dd/yyyy hh:mm:ss
    virtual bool isThisEventValid(string keyword, Event* event){
        vector<string>vector = split(keyword,'/');
        if(vector.size() != 3)
        return false;
        int month = atoi(vector[0].c_str());
        int day = atoi(vector[1].c_str());
        int year = atoi(vector[2].c_str());

        return event->isStartTimeOnThisDate(year, month, day);
    }
};

#endif
