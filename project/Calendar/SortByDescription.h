//
//  SortByDescription.h
//  Calendar
//
//  Created by Jiawei Shi on 4/4/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_SortByDescription_h
#define Calendar_SortByDescription_h

#include <iostream>
#include <string>
#include <vector>

#include "Event.h"
#include "Time.h"
#include "Sort.h"

using namespace std;

class SortByDescription : public Sort{
private:
    virtual string getSortName(){
        return "description";
    }
    
    virtual bool inOrder(Event* first, Event* second){
        string firstDescription = toLowercase(first->getDescription());
        string secondDescription = toLowercase(second->getDescription());
        return firstDescription.compare(secondDescription) <= 0;
    }

};

#endif
