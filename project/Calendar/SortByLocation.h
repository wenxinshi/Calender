//
//  SortByLocation.h
//  Calendar
//
//  Created by Jiawei Shi on 4/4/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_SortByLocation_h
#define Calendar_SortByLocation_h

#include <iostream>
#include <string>
#include <vector>

#include "Event.h"
#include "Time.h"
#include "Sort.h"

using namespace std;

class SortByLocation : public Sort{
private:
    virtual string getSortName(){
        return "location";
    }
    
    virtual bool inOrder(Event* first, Event* second){
        string firstLocation = toLowercase(first->getLocation());
        string secondLocation = toLowercase(second->getLocation());
        return firstLocation.compare(secondLocation) <= 0;
    }
};

#endif
