# CPROGR 510, Assignment 4
## Logistics
In case of discrepancies between README.md and the assignment in Canvas, please alert the instructors!

After cloning this repo, create a branch off of main:

`git checkout -b Assignment4`

Do your work (modifications and additions of files) on the Assignment4 branch. 
Do include your code .cpp and .h files and your unit test .cpp files
Do not include exe, obj, or other results of compilation and linking. These would bloat the repository, and should not be under version control.
You may optionally turn in Visual Studio .vcproj and .sln files, or Makefiles (your-environment dependent).
`Commit` those changes to the Assignment4 branch. 

Push your changes up to `origin` (that is, to github).

When done, go to github.com and create a pull request to merge `Assignment4` branch to `main`.

## General Guidance


The header files for CppUnitLite are in the include\CppUnitLite directory.  In your project file or makefile, you will need to tell your compiler to seach this directory for headers

Microsoft Visual Studio: add this include directory to the "AdditionalIncludeDirectories"
makefile: add via the INC=-Iinclude/CppUnitLite flag

## Problem 1: `Date` struct
Write functions to add one day, another function to add one month, and yet another function to add one year to a Date struct. In your implementations, you can use the date functions provided with the C++ standard library.
```
struct Date
{
    int year;
    int month;
    int day;
};
```
Design your functions so that AAA (Almost Always Auto) can be used. Test your functions with data allocated on the stack. Provide at least one additional test that also passes `Date` data allocated on the heap with `make_unique`. Pass `Date`s by reference when appropriate (i.e., `Date&` or `const Date&`). For example, the following function returns by value a new `Date` instance with one day added to the passed-in date:
```
Date addOneDay(const Date& date);
```

## Problem 2: `write` functions
Populate the C++ header file named `A4Q2_write.h` with function prototypes for three functions named `write`. Write the implementations for each `write` function in the file named `A4Q2_write.cpp`.   Each `write` function takes two arguments. The first argument is always `std::ostream& os`. The second arguments are an `int`, a `float`, and a `std::string`, respectively. Each write function should stream its second argument to the passed-in `std::ostream`. 

Here's the prototype for the first write overload:
```
void write(std::ostream& os, int value);
```

* Write cppunitlite unit tests that pass a `std::stringstream` as the first argument to each function and verify its operation. 
* Write non-unit-test code that calls each `write` function and passes `std::cout` as the first argument (the cout tests are written outside the unit test framework because verification can't easily be automated). (This code can be in its own executable, or simply called from the `main` function of your unit-test executable.)

Notice that both `std::stringstream` and `std::cout` may be passed as the first argument. Both inherit from `std::ostream` and thus may be used wherever a `std::ostream&` is used. This is our first use of inheritance in C++. We'll do much more with inheritance as the course progresses.

## Problem 3: lambda function
Write a lambda function that makes the following TEST pass:
```
TEST(lambdaTestProblem, lambdas)
{
    auto values = { 2, 4, 6, 8, 10, 12 };
    auto sum = 0;

    std::for_each(values.begin(), values.end(), /*define lambda function here*/);

    CHECK_EQUAL(42, sum);
}
```

## Problem 4: 
_[Note: This assignment does not require CppUnitLite tests]_

Define a simple class called `SimpleClass`, with a default constructor, a copy constructor (i.e., a constructor that takes the single parameter: `const SimpleClass& src`), and destructor. Annotate each one so that it writes to `std::cout` each time it is invoked.

a. Declare four functions, `f1`, `f2`, `f3`, and `f4` with the following prototypes:
```
void f1(SimpleClass aSimpleClass);
void f2(SimpleClass aSimpleClass);
void f3(SimpleClass& aSimpleClass);
void f4(SimpleClass* aSimpleClass)
```
b. Declare an instance of `SimpleClass` in the function `main` and call `f1` with that instance as an argument.

c. Declare an instance of `SimpleClass` in the function `f1`. Pass that instance by value, to function `f2`.

d. Declare an instance of the `SimpleClass` in `f2` that uses the copy constructor. Pass that instance by reference to function `f3`.

e. Declare a function `f4` that takes a pointer to an instance of `SimpleClass`. Call `f4` from within `f3` using a pointer to the argument passed into `f3`.

f. How many instances of your class were constructed? How many instances of your class were destructed? Why?

## Problem 5: design problem (CRC/UML)
Let's explore an open-ended design problem to which we can apply our skills in the design of object-centered systems. You are the chief designer of a consulting firm and you have been hired by The First National Bank to upgrade its customer database. You have chosen to rewrite the database using C++. Each customer account consists of a savings account and a checking account.

Begin the design by developing a set of use cases for the combined account that will describe how a customer may interact with the account.

Based upon your design thus far, use CRC cards to identify each of the classes that comprise your design. Be certain to identify the primary public and private aspects of each of the classes that make up a customer account.

Express each of the classes that you have identified in a class diagram. Don't get carried away here. There are only a couple of basic attributes of such an account.
* To turn in your CRC cards, you can do them digitally in the first place; or photograph/scan them to a single computer document, and add that doc to the repo.
* To turn in your class diagram you can
  * Draw the class diagram using a computer graphics program, then provide the drawing in a PDF, JPEG, or other common format
  * Do the drawings using Mermaid syntax within this, or another, Markdown (.md) document (https://docs.github.com/en/get-started/writing-on-github/working-with-advanced-formatting/creating-diagrams)
  * Scan/photograph hand drawings. Seriously, this is fine as long as it's legible.
