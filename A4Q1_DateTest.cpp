#include "TestHarness.h"
#include "A4Q1_Date.h"

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



TEST(functions, DayAdded)
{
    Date date{ 0,0,1 }; //year, month, day

    Date temp = addOneDay(date);
    CHECK_EQUAL(2, temp.day);

    Date date1{ 0,2,28 }; //year, month, day

    Date temp1 = addOneDay(date1);
    CHECK_EQUAL(1, temp1.day);
    CHECK_EQUAL(3, temp1.month);

    Date date2{ 0,3,31 }; //year, month, day

    Date temp2 = addOneDay(date2);
    CHECK_EQUAL(1, temp2.day);
}

TEST(functions, MonthsAdded)
{
    Date date{ 0,2,0 }; //year, month, day

    Date temp = addOneMonth(date);
    CHECK_EQUAL(3, temp.month);

    Date date1{ 0,12,0 }; //year, month, day

    Date temp1 = addOneMonth(date1);
    CHECK_EQUAL(1, temp1.month);
}

TEST(functions, YearsAdded)
{
    Date date{ 3,0,0 }; //year, month, day

    Date temp = addOneYear(date);
    CHECK_EQUAL(4, temp.year);

}

TEST(functions, SmartPointerAdded)
{
    auto dates = std::make_unique<Date>(1, 1, 1);
    auto temp = addOneYear(*dates);

    //std::cout << temp.year << "\n";
    CHECK_EQUAL(2, temp.year);
}

