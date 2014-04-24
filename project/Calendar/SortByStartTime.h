//
//  SortByStartTime.h
//  Calendar
//
//  Created by Jiawei Shi on 4/4/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_SortByStartTime_h
#define Calendar_SortByStartTime_h

#include <iostream>
#include <string>
#include <vector>

#include "Event.h"
#include "Time.h"
#include "Sort.h"

using namespace std;

class SortByStartTime : public Sort{
private:
    virtual string getSortName(){
        return "startTime";
    }
    
    virtual bool inOrder(Event* first, Event* second){
        Time* firstTime = first->getStartTime();
        Time* secondTime = second->getStartTime();
        return firstTime->compareTo(secondTime) <=0;
    }
};

#endif
