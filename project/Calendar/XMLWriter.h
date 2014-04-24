//
//  XMLWriter.h
//  Calendar
//
//  Created by Jiawei Shi on 4/5/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_XMLWriter_h
#define Calendar_XMLWriter_h

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "tinyxml.h"
#include "Event.h"

class XMLWriter{
private:
     string eventTag;
     string subjectTag;
     string startTimeTag ;
     string endTimeTag ;
     string locationTag;
     string descriptionTag;
    
    string getContent(vector<Event*> eventList){
        string content = "<Events>";
        content.append("\n");
        for(int i=0; i<(int)eventList.size(); i++){
            Event* current = eventList[i];
            content.append("<Event>");
            content.append("\n");
            //Append the subject info
            content.append(getStartTag(eventTag));
            content.append(current->getSubject());
            content.append(getEndTag(eventTag));
            content.append("\n");
            //Append the start time info
            content.append(getStartTag(startTimeTag));
            content.append(current->getStartTime()->toString());
            content.append(getEndTag(startTimeTag));
            content.append("\n");
            //Append the end time info
            content.append(getStartTag(endTimeTag));
            content.append(current->getEndTime()->toString());
            content.append(getEndTag(endTimeTag));
            content.append("\n");
            //Append the location info
            content.append(getStartTag(locationTag));
            content.append(current->getLocation());
            content.append(getEndTag(locationTag));
            content.append("\n");
            //Append the description info
            content.append(getStartTag(descriptionTag));
            content.append(current->getDescription());
            content.append(getEndTag(descriptionTag));
            content.append("\n");
                        
            content.append("</Event>");
            content.append("\n");
        }
        content.append("</Events>");
        content.append("\n");
        return content;
    }
        
    //Return the tag before each item
    //For example, if the input tag is "Event", then the output is "<Event>"
    string getStartTag(string tag){
        string result = "<";
        result.append(tag);
        result.append(">");
        return result;
    }
    
    //Return the tag at the end of each item
    //For example, if the input tag is "Event", then the output is "</Event>"
    string getEndTag(string tag){
        string result = "<";
        result.append("/");
        result.append(tag);
        result.append(">");
        return result;
    }
    
public:
    XMLWriter(){
        eventTag = "Event";
        subjectTag = "Subject";
        startTimeTag = "StartTime";
        endTimeTag = "EndTime";
        locationTag = "Location";
        descriptionTag = "Description";
    }

    void writeToFile(string filePath,vector<Event*> eventList){
        TiXmlDocument doc(filePath.c_str());
        string content = getContent(eventList);
        doc.Parse(content.c_str() );
        
        if ( doc.Error() )
        {
            printf( "Error in %s: %s\n", doc.Value(), doc.ErrorDesc() );
            exit( 1 );
        }
        doc.SaveFile();
    }
    
};

#endif
