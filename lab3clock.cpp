/*
 *  lab3clock.cpp
 *  ENSF 694 Lab 3 - Exercise C
 *  Created by Jeff Wheeler
 *  Submission date: July 17, 2024
 */

#include "lab3clock.h"
using namespace std;

int Clock::hms_to_sec(){
    return (hour * 3600 + minute * 60 + second);
}

void Clock::sec_to_hms(int s){
    if (s >= 86400)
        s %= 86400;
    hour = s / 3600;
    s %= 3600;
    minute = s / 60;
    second = s % 60;
}

Clock::Clock(): hour(0), minute(0), second(0) {}

Clock::Clock(int s) {
    if (s > 0)
        Clock::sec_to_hms(s);
    else{
        Clock::sec_to_hms(0);
    }
}

Clock::Clock(int h, int m, int s) {
    if (h < 0 || h > 23){
        Clock::sec_to_hms(0);
        return;
    }
    else
        hour = h;

    if (m < 0 || m > 59){
        Clock::sec_to_hms(0);
        return;
    }
    else
        minute = m;

    if (s < 0 || s > 59){
        Clock::sec_to_hms(0);
        return;
    }
    else
        second = s;
}

int Clock::get_hour() const{
    return hour;
}

int Clock::get_minute() const{
    return minute;
}

int Clock::get_second() const{
    return second;
}

void Clock::set_hour(int h){
    if (h >= 0 && h <= 23)
        hour = h;
}

void Clock::set_minute(int m){
    if (m >= 0 && m <= 59)
        minute = m;
}

void Clock::set_second(int s){
    if (s >= 0 && s <= 59)
        second = s;
}

void Clock::increment(){
    if (hour == 23 && minute == 59 && second == 59){
        hour = 0;
        minute = 0;
        second = 0;
    }
    else if (minute == 59 && second == 59){
        hour++;
        minute = 0;
        second = 0;
    }
    else if (second == 59){
        minute++;
        second = 0;
    }
    else
        second++;
}

void Clock::decrement(){
    if (hour == 0 && minute == 0 && second == 0){
        hour = 23;
        minute = 59;
        second = 59;
    }
    else if (minute == 0 && second == 0){
        hour--;
        minute = 59;
        second = 59;
    }
    else if (second == 0){
        minute--;
        second = 59;
    }
    else
        second--;
}

void Clock::add_seconds(int s){
    int clock_time = Clock::hms_to_sec();
    int new_time = clock_time + s;
    Clock::sec_to_hms(new_time);
}