#include "TestHarness.h"
#include <iostream>
#include "A4Q4_SimpleClass.cpp"

int main()
{
  // random number generator used in some tests
  srand(::time_t(NULL));


  SimpleClass obj;
  SimpleClass var1 = obj.f1(obj);
  SimpleClass var2 = obj.f2(var1);
  obj.f3(var2);

  //8 instances of Simple class was constructed. 5 destructed. 
  //   	     (1) obj 
  // var1 -> (2) copy constructor -> (3) obj2 default constructor
  // var2 -> (4) copy constructor -> (5) obj3 default constructor -> (6) copy constructor obj 3 -> return
  // var2 -> (7) copy constructor 
  // var3 -> (8) copy constructor
  // var4 -> (9) copy constructor
  //Once the function ended, they were destructed leaving the original "obj" in line 10 and
  //the retained SimpleClass in each variable with a returned Simple class object (i.e. f1, f2).


  TestResult tr;
  TestRegistry::runAllTests(tr);

  return 0;
}
