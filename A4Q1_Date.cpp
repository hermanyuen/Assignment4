#include "A4Q1_Date.h"
#include <stdexcept>
#include <ostream>
#include <iostream>

//Write functions to:
//  add one day, 
//  add one month, 
//  add one year 
//to a Date struct (as below). 
//
//struct Date
//{
//    int year;
//    int month;
//    int day;
//};
//
//In your implementations, you can use the date functions provided with the C++ standard library.
//
//Design your functions so that AAA (Almost Always Auto) can be used. Test your functions with data allocated on the stack. 
//Provide at least one additional test that also passes Date data allocated on the heap with make_unique. 
//
//Pass Dates by reference when appropriate (i.e., Date& or const Date&). 
//For example, the following function returns by value a new Date instance with one day added to the passed-in date:
//
//Date addOneDay(const Date& date);

//struct Date
//{
//    int year;
//    int month;
//    int day;
//};
Date addOneDay(Date& date) {
    date.day += 1;
    if (date.month == 2) {
        if (date.day > 28) {
            date.day = 1;
            date.month++;
        }
    }
    else if (date.month == 1 || date.month == 3 || date.month == 5 ||
        date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) {
        if (date.day > 31) {
            date.day = 1;
            if (date.month != 12) {
                date.month++;
            }
            else {
                date.month = 1;
            }
        }
    }
    else {
        if (date.day > 30) {
            date.day = 1;
            date.month++;
        }
    }
    return date;
}

Date addOneMonth(Date& date) {
    if (date.month == 12) {
        date.month = 1;
    }
    else {
        date.month += 1;
    }
    return date;
}

Date addOneYear(Date& date) {
    date.year += 1;
    return date;
}
