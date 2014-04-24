//
//  SortBySubject.h
//  Calendar
//
//  Created by Jiawei Shi on 4/3/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_SortBySubject_h
#define Calendar_SortBySubject_h

#include <iostream>
#include <string>
#include <vector>

#include "Event.h"
#include "Time.h"
#include "Sort.h"

using namespace std;

class SortBySubject : public Sort{
private:
    virtual string getSortName(){
        return "subject";
    }
    
    virtual bool inOrder(Event* first, Event* second){
        string firstSubject = toLowercase(first->getSubject());
        string secondSubject = toLowercase(second->getSubject());
        return firstSubject.compare(secondSubject) <= 0;
    }
};

#endif
