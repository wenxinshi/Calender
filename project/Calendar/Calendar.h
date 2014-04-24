//
//  Calendar.h
//  Calendar
//
//  Created by Jiawei Shi on 4/3/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_Calendar_h
#define Calendar_Calendar_h

#include <iostream>
#include <string>
#include <vector>

#include "Event.h"
#include "CalParser.h"
#include "GoogleCalParser.h"
#include "DukeBasketBallCalParser.h"
#include "DukeCalParser.h"
#include "UserDefinedCalParser.h"
#include "Filter.h"
#include "FilterBySubject.h"
#include "FilterByDescription.h"
#include "FilterByLocation.h"
#include "FilterByStartTime.h"
#include "FilterByEndTime.h"
#include "Sort.h"
#include "SortBySubject.h"
#include "SortByDescription.h"
#include "SortByLocation.h"
#include "SortByStartTime.h"
#include "SortByEndTime.h"
#include "XMLWriter.h"

class Calendar{
private:
    vector<Event*> eventList;
    vector<Event*> displayedList;
    vector<CalParser*> myParsers;
    vector<Filter*> myFilters;
    vector<Sort*> mySorts;
    
public:
    Calendar(){
        myParsers.push_back(new GoogleCalParser());
        myParsers.push_back(new DukeBasketBallCalParser());
        myParsers.push_back(new DukeCalParser());
        
        myFilters.push_back(new FilterBySubject());
        myFilters.push_back(new FilterByLocation());
        myFilters.push_back(new FilterByDescription());
        myFilters.push_back(new FilterByStartTime());
        myFilters.push_back(new FilterByEndTime());
        
        mySorts.push_back(new SortBySubject());
        mySorts.push_back(new SortByDescription());
        mySorts.push_back(new SortByLocation());
        mySorts.push_back(new SortByStartTime());
        mySorts.push_back(new SortByEndTime());
    }
    
    
    //parse a new xml file
    bool addNewCalendar(string filePath){
        for(int i=0; i<(int)myParsers.size(); i++){
            if(myParsers[i]->isThisType(filePath)){
                vector<Event*> newEvents = myParsers[i]-> doParse(filePath);
                addToEventList(newEvents);
                return true;
            }
        }
        return false;
    }
    
    //Filter
    //filterType is like "subject", "description","lcoation","startTime","endTime", case-insensitive
    bool filter(string filterType, string keyword){
        std::cout<<filterType<<endl;
        std::cout<<keyword<<endl;
        for(int i=0; i<(int)myFilters.size(); i++){
            Filter* filter = myFilters[i];

            if(filter->isThisType(filterType)){
                displayedList = filter->doFilter(displayedList, keyword);
                return true;
            }
        }
        return false;
    }
    
    //Sort
    bool sort(string keyword, bool inOrder){
        for(int i=0; i<(int)mySorts.size(); i++){
            Sort* sort = mySorts[i];
            if(sort->isThisType(keyword)){
                displayedList = sort->doSort(displayedList, inOrder);
                return true;
            }
        }
        return false;
    }

    //Print all the events currently avaiable
    void printEvents(){
        for(int i=0; i<(int)eventList.size(); i++){
            cout<<eventList[i]->toString()<<endl;
            cout<<endl;
        }
    }
    
    //Print all the events currently being displayed
    void printDisplayedEvents(){
        for(int i=0; i<(int)displayedList.size(); i++){
            cout<<displayedList[i]->toString()<<endl;
            cout<<endl;
        }
    }
    
    //Add a vector of events into the eventList
    void addToEventList(vector<Event*> events){
        for(int i=0; i<(int)events.size(); i++){
            eventList.push_back(events[i]);
        }
    }
    
    //Output the current events into a xml file
    void outputToXMLFile(string filePath){
        XMLWriter* writer = new XMLWriter();

        writer->writeToFile(filePath,displayedList);
        std::cout<<filePath<<endl;
    }
    
    //The vector contains all the tags for XML file
    //The order is: password, subjectTag, startTimeTag, endTimeTag, descriptionTag, locationTag
    void addNewParser(vector<string> info){
        UserDefinedCalParser* parser = new UserDefinedCalParser();
        parser->setPassword(info[0]);
        parser->setEventTag(info[1]);
        parser->setSubjectTag(info[2]);
        parser->setStartDateTag(info[3]);
        parser->setStartTimeTag(info[3]);
        parser->setEndDateTag(info[4]);
        parser->setEndTimeTag(info[4]);
        parser->setDescriptionTag(info[5]);
        parser->setLocationTag(info[6]);
        
        myParsers.push_back((CalParser*) parser);
    }
    
    //Tell if there is any event occurs on the selected date
    //2012-10-21
    bool hasEvent(string dateInfo){
        for(int i=0; i<(int)displayedList.size(); i++){
            if(displayedList[i]->isOnSelectedDate(dateInfo))
                return true;
        }
        return false;
    }
    
    //Get all the events to be displayed on the selected date
    vector<Event*> eventsOnSelectedDate(string dateInfo){
        vector<Event*> result;
       // cout<<dateInfo<<""<<endl;
        for(int i=0; i<(int)eventList.size(); i++){
            if(eventList[i]->isOnSelectedDate(dateInfo))
                result.push_back(eventList[i]);
        }

       // cout<<result.size()<<endl;
        return result;
    }
    
    //2012-10-21
    //startDate, endDate, searchType. searchKeyword
    void setDisplayedEvents(vector<string> info){
        vector<Event*> vector;
        for(int j=0; j<(int)info.size(); j++){
            cout<<info[j]<<endl;
        }

        for(int i=0; i<(int)eventList.size(); i++){
            Event* current = eventList[i];
            if(current->isAfterTheDate(info[0]) && current->isBeforeTheDate(info[1]))
                vector.push_back(current);
        }
        cout<<"size is "<<vector.size()<<endl;

        if(info.size() == 2)
            displayedList = vector;
        else if(info[2] == "All Included")
            displayedList = vector;
        else{
            displayedList = vector;
            filter(info[2],info[3]);
        }
    }

    vector<Event*> getEventList(){
        return eventList;
    }
    
    vector<Event*> getDisplayedList(){
        return displayedList;
    }
    
    void setEventList(vector<Event*> input){
        eventList = input;
    }
    
};

#endif
