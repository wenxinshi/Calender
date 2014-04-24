//
//  FilterByEndTime.h
//  Calendar
//
//  Created by Jiawei Shi on 4/3/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_FilterByEndTime_h
#define Calendar_FilterByEndTime_h

#include <iostream>
#include <string>
#include <vector>

#include "Filter.h"
#include "Event.h"

using namespace std;

class FilterByEndTime : public Filter{
private:
    virtual string getFilterName(){
        return "endDate";
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
        std::cout<<"filterByendTime";
        std::cout<<month<<","<<day<<","<<year<<std::endl;
        return event->isEndTimeOnThisDate(year, month, day);
    }
};

#endif
