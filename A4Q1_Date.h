#include <iosfwd>

#pragma once

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