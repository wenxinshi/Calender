//
//  FilterByLocation.h
//  Calendar
//
//  Created by Jiawei Shi on 4/3/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_FilterByLocation_h
#define Calendar_FilterByLocation_h

#include <iostream>
#include <string>
#include <vector>

#include "Filter.h"
#include "Event.h"

using namespace std;

class FilterByLocation : public Filter{
    virtual string getFilterName(){
        return "location";
    }
    
    virtual bool isThisEventValid(string keyword, Event* event){
        string location = event->getLocation();
        string lowercaseLocation = toLowercase(location);
        string lowercaseKeyword = toLowercase(keyword);
        return lowercaseLocation.find(lowercaseKeyword) != string::npos;
    }

};

#endif
