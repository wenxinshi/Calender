//
//  main.cpp
//  Calendar
//
//  Created by Jiawei Shi on 3/18/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#include <iostream>
#include <string>

#include "Calendar.h"
#include "CalParser.h"
#include "GoogleCalParser.h"
#include "DukeBasketBallCalParser.h"
#include "DukeCalParser.h"

using namespace std;

int main(int argc, const char * argv[])
{
    Calendar* myCalendar = new Calendar();
//    myCalendar->addNewCalendar("/Users/larry/Documents/ECE590.1/Project/Calendar/Calendar/data/DukeBasketBall.xml");
//    myCalendar->addNewCalendar("/Users/larry/Documents/ECE590.1/Project/Calendar/Calendar/data/googlecal.xml");
//    myCalendar->addNewCalendar("/Users/larry/Documents/ECE590.1/Project/Calendar/Calendar/data/dukecal.xml");
//    myCalendar->filter("Duke vs", "subject");
//    myCalendar->filter("11/10/2011 10:00:00-11/30/2011 20:00:00", "endTime");
//    myCalendar->sort("subject", true);
//    myCalendar->printEvents();
//    myCalendar->outputToXMLFile("/Users/larry/Documents/ECE590.1/Project/Calendar/Calendar/data/output.xml");
    
    vector<string> info;
    info.push_back("row");
    info.push_back("row");
    info.push_back("Col1");
    info.push_back("Col8");
    info.push_back("Col9");
    info.push_back("Col15");
    info.push_back("Col3");
    myCalendar->addNewParser(info);
    
    myCalendar->addNewCalendar("/Users/larry/Documents/ECE590.1/Project/Calendar/Calendar/data/NFL.xml");
    myCalendar->printEvents();
    
    
    return 0;
}



