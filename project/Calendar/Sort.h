//
//  Sort.h
//  Calendar
//
//  Created by Jiawei Shi on 4/3/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_Sort_h
#define Calendar_Sort_h

#include <iostream>
#include <string>
#include <vector>

#include "Event.h"
#include "Time.h"

using namespace std;

class Sort{
private:
    //Return the sort name
    virtual string getSortName() = 0;
    
    //Return true is first event shoule be placed before the second event if we want to place them in order
    virtual bool inOrder(Event* first, Event* second) = 0;
    
    //Swap the two items inside the vector
    vector<Event*> swap(vector<Event*> list, int first, int second){
        Event* temp = list[first]->clone();
        list[first] = list[second];
        list[second] = temp;
        return list;
    }
    
    vector<Event*> clone(vector<Event*> input){
        vector<Event*> result;
        for(int i=0;i<(int) input.size(); i++){
            result.push_back(input[i]);
        }
        return result;
    }
    
public:
    bool isThisType(string name){
        return toLowercase(name) == toLowercase(getSortName());
    }
    
    //inOrderSort is true when the standard sequence of sorting is needed
    //inOrderSort is false when the reverse sequence of sorting is needed
    //Here we use bubble sort
    vector<Event*> doSort(vector<Event*> eventList, bool inOrderSort){
        bool elementSwapped;
        vector<Event*> vector = clone(eventList);
        for(int i=0; i<(int) vector.size(); i++){
            elementSwapped = false;
            for(int j=(int) vector.size()-1; j>=i+1; j--){
                bool compare = inOrder(vector[j-1], vector[j]);
                if((!compare && inOrderSort) || (compare && !inOrderSort)){
                    elementSwapped = true;
                    Event* temp = vector[j-1];
                    vector[j-1] = vector[j];
                    vector[j] = temp;
                }
            }
            if(!elementSwapped)
                break;
        }
        return vector;
    }
    
    void printVector(vector<Event* >vector){
        for(int i=0; i<(int) vector.size();i++){
            cout<<vector[i]->getSubject()<<endl;
        }
        cout<<endl;
    }
    
    //Convert the string into lower case
    string toLowercase(string input){
        string result = input;
        for(int i=0; i<(int) input.size(); i++){
            result[i] = tolower(input[i]);
        }
        return result;
    }

};


#endif
