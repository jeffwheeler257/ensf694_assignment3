/*
 *  lab3clock.h
 *  ENSF 694 Lab 3 - Exercise C
 *  Created by Jeff Wheeler
 *  Submission date: July 17, 2024
 */

#ifndef lab3clock_h
#define lab3clock_h

class Clock{
private:
    /*
    * REQUIRES: hour >= 0, hour < 24
    */
    int hour;

    /*
    * REQUIRES: minute >= 0, minute < 60
    */
    int minute;

    /*
    * REQUIRES: second >= 0, second < 60
    */
    int second;

    /*
    * PROMISES: converts a Clock objects hour, minute, and second into seconds and returns that value
    */
    int hms_to_sec();

    /*
    * REQUIRES: s > 0
    * PROMISES: takes the given s in seconds and assigns an hour, minute and second value to a Clock object
    */
    void sec_to_hms(int s);

public:
    /*
    * PROMISES: Default constructor for clock where hour, minute and second are all set to 0
    */
    Clock();

    /*
    * PROMISES: Constructor for clock that takes second and sets to hours, minutes, and seconds
    */
    Clock(int s);

    /*
    * PROMISES: Constructor for clock that sets hours, minutes, and seconds
    *           If s < 0 or s > 59, set second to 0.
    *           If m < 0 or m > 59, set minute to 0.
    *           If h < 0 or h > 23 set hour to 0.
    */
    Clock(int h, int m, int s);

    /*
    * PROMISES: returns the hour in a Clock object
    */
    int get_hour() const;

    /*
    * PROMISES: returns the minute in a Clock object
    */
    int get_minute() const;

    /*
    * PROMISES: returns the second in a Clock object
    */
    int get_second() const;

    /*
    * PROMISES: sets a new value for hour in a Clock object
    */
    void set_hour(int h);

    /*
    * PROMISES: sets a new value for minute in a Clock object
    */
    void set_minute(int m);

    /*
    * PROMISES: sets a new value for second in a Clock object
    */
    void set_second(int s);

    /*
    * PROMISES: Increments the second value of a Clock object by 1.
    *           If second = 59, increment will set the second to 0 and increment the minute
    *           If minute = 59 & second = 59, increment will set the minute, and second to 0 and increment the hour
    *           If hour = 23 & minute = 59 & second = 59, increment will set the hour, minute, and second to 0
    */
    void increment();

    /*
    * PROMISES: Decrements the second value of a Clock object by 1.
    *           If second = 0, increment will set the second to 59 and decrement the minute
    *           If minute = 0 & second = 0, decrement will set the minute, and second to 59 and decrement the hour
    *           If hour = 0 & minute = 0 & second = 0, idecrement will set the hour to 23, and the minute and second to 59
    */
    void decrement();

    /*
    * REQUIRES: s > 0
    * PROMISES: adds the value of the s in seconds to a Clock object
    *           Converts seconds to hours, minutes, and seconds then adds to Clock members
    */
    void add_seconds(int s);

};


#endif
