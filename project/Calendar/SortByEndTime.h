//
//  SortByEndTime.h
//  Calendar
//
//  Created by Jiawei Shi on 4/4/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_SortByEndTime_h
#define Calendar_SortByEndTime_h

#include <iostream>
#include <string>
#include <vector>

#include "Event.h"
#include "Time.h"
#include "Sort.h"

using namespace std;

class SortByEndTime : public Sort{
private:
    virtual string getSortName(){
        return "endTime";
    }
    
    virtual bool inOrder(Event* first, Event* second){
        Time* firstTime = first->getEndTime();
        Time* secondTime = second->getEndTime();
        return firstTime->compareTo(secondTime) <=0;
    }
};


#endif
