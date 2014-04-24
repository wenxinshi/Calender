//
//  Time.h
//  Calendar
//
//  Created by Jiawei Shi on 4/1/13.
//  Copyright (c) 2013 Jiawei Shi. All rights reserved.
//

#ifndef Calendar_Time_h
#define Calendar_Time_h

#include <iostream>
#include <stdlib.h>
#include <string>
#include <QString>

using namespace std;

class Time{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    
    //Convert the integer to a string represents two digits
    //For example, 8 to "08"
    string parseToTwoDigit(int input){
        if(input >= 10)
            return QString::number(input).toStdString();
        else{
            string result = "0";
            result.append(QString::number(input).toStdString());
            return result;
        }
    }
    
public:
    Time(){
        
    };
    
    //Create a clone of the current object
    Time* clone(){
        Time* time = new Time();
        time->setYear(year);
        time->setMonth(month);
        time->setDay(day);
        time->setHour(hour);
        time->setMinute(minute);
        time->setSecond(second);
        return time;
    }
    
    void setYear(int digitY){
        year = digitY;
    }
    
    void setMonth(int digitM){
        month = digitM;
    }
    
    void setDay(int digitD){
        day = digitD;
    }
    
    void setHour(int digitH){
        hour = digitH;
    }
    
    void setMinute(int digitM){
        minute = digitM;
    }
    
    void setSecond(int digitS){
        second = digitS;
    }
    
    void setYear(string y){
        year = atoi(y.c_str());
    }
    
    void setMonth(string m){
        month = atoi(m.c_str());
    }
    
    void setDay(string d){
        day = atoi(d.c_str());
    }
    
    void setHour(string h){
        hour = atoi(h.c_str());
    }
    
    void setMinute(string m){
        minute = atoi(m.c_str());
    }
    
    void setSecond(string s){
        second = atoi(s.c_str());
    }
    
    int getYear(){
        return year;
    }
    
    int getMonth(){
        return month;
    }
    
    int getDay(){
        return day;
    }
    
    int getHour(){
        return hour;
    }
    
    int getMinute(){
        return minute;
    }
    
    int getSecond(){
        return second;
    }
    
    //Add number of seconds to the current time
    //Return a new time
    //For example, 08:00:00 add 3600 seconds equals 09:00:00
    Time* addSeconds(int seconds){
        int addedHours = seconds / 3600;
        int addedMinutes = (seconds - 3600*addedHours) / 60;
        int addedSeconds = seconds - 3600* addedHours - 60*addedMinutes;
        
        Time* newTime = clone();
        int carry = 0;
        int newSecond = second + addedSeconds;
        if(newSecond >= 60){
            carry = 1;
            newSecond = newSecond - 60;
        }
        else
            carry = 0;
        
        int newMinute = minute + addedMinutes + carry;
        if(newMinute >= 60){
            carry = 1;
            newMinute = newMinute - 60;
        }
        else
            carry = 0;
        
        int newHour = hour + addedHours + carry;
        
        newTime->setHour(newHour);
        newTime->setMinute(newMinute);
        newTime->setSecond(newSecond);
        return newTime;
    }
    
    //Return a string represents the time
    //The type is like: 10/03/2010 10:50:40
    string toString(){
        string result = "";
        result.append(QString::number(year).toStdString());
        result.append("/");
        result.append(QString::number(month).toStdString());
        result.append("/");
        result.append(QString::number(day).toStdString());
        result.append(" ");
        result.append(parseToTwoDigit(hour));
        result.append(":");
        result.append(parseToTwoDigit(minute));
        result.append(":");
        result.append(parseToTwoDigit(second));
        return result;
    }
    
    //return negative integer if current time is before input time
    //return positive integer if the current time is after input time
    //return zero if the current time is equal to input time
    int compareTo(Time* time){
        int result = 0;
        if(year != time->getYear())
            result = year - time->getYear();
        else if(month != time->getMonth())
            result = month - time->getMonth();
        else if(day != time->getDay())
            result = day - time->getDay();
        else if(hour != time->getHour())
            result = hour - time->getHour();
        else if(minute != time ->getMinute())
            result = minute - time->getMinute();
        else
            result = second - time->getSecond();
        return result;
    }

};


#endif
