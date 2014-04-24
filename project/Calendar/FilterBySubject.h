//
//  FilterBySubject.h
//  Calendar
//
//  Created by Jiawei Shi on 4/3/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_FilterBySubject_h
#define Calendar_FilterBySubject_h

#include <iostream>
#include <string>
#include <vector>

#include "Filter.h"
#include "Event.h"

using namespace std;

class FilterBySubject: public Filter{
private:
    virtual string getFilterName(){
        return "subject";
    }
    
    virtual bool isThisEventValid(string keyword, Event* event){
        string subject = event->getSubject();
        string lowercaseSubject = toLowercase(subject);
        string lowercaseKeyword = toLowercase(keyword);
        return lowercaseSubject.find(lowercaseKeyword) != string::npos;
    }
};

#endif
