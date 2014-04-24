//
//  FilterByDescription.h
//  Calendar
//
//  Created by Jiawei Shi on 4/3/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_FilterByDescription_h
#define Calendar_FilterByDescription_h

#include <iostream>
#include <string>
#include <vector>

#include "Filter.h"
#include "Event.h"

using namespace std;

class FilterByDescription : public Filter{
    virtual string getFilterName(){
        return "description";
    }
    
    virtual bool isThisEventValid(string keyword, Event* event){
        string description = event->getDescription();
        string lowercaseDescription = toLowercase(description);
        string lowercaseKeyword = toLowercase(keyword);
        return lowercaseDescription.find(lowercaseKeyword) != string::npos;
    }

};

#endif
