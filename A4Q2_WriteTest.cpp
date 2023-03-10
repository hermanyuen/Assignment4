#include "TestHarness.h"

#include "A4Q2_Write.h"
#include <iostream>

//Create a C++ header file named A4Q2_Write.h which contains function prototypes for three functions named write. 

//Write the implementations for each write function in a file named A4Q2_Write.cpp. 
//Each write function takes two arguments. The first argument is always std::ostream& os. The second arguments are an int, a float, and a std::string respectively. 
//Each write function should stream its second argument to the passed in std::ostream. 
//
//Write cppunitlite unit tests that pass a std::stringstream as the first argument to each function and verify its operation. 
//Write non unit test code that calls each write function and passes std::cout as the first argument (the cout tests are written outside the unit test framework because verification can't easily be automated). 
//
//Here's the prototype for the first write overload:
//void write(std::ostream& os, int value);
//
//Notice that both std::stringstream and std::cout may be passed as the first argument. Both inherit from std::ostream and thus may be used where ever a std::ostream& is used. 
//This is our first use of inheritance in C++. We'll do much more with inheritance as the course progresses.

int nonTest(int value) {
	std::stringstream out;
	write(out, value);
	std::cout << out.str() << "\n";
	return 0;
}

int nonTest(float value) {
	std::stringstream out;
	write(out, value);
	std::cout << out.str() << "\n";
	return 0;
}

int nonTest(std::string value) {
	std::stringstream out;
	write(out, value);
	std::cout << out.str() << "\n";
	return 0;
}

TEST(FunctionStream, intStream)
{
	nonTest(100);
	int value = 1;
	std::stringstream out;
	write(out, value);
	// Test passes if expression is true
	CHECK(out);
}

TEST(FunctionStream, floatStream)
{
	nonTest(100.1f);
	float value = 100.1f;
	std::stringstream out;
	write(out, value);
	// Test passes if expression is true
	CHECK(out);
}

TEST(FunctionStream, stringStream)
{
	nonTest("helloWorld");
	std::string value{"helloWorld"};
	std::stringstream out;
	write(out, value);
	// Test passes if expression is true
	CHECK(out);
}