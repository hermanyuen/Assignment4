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

  //6 instances of Simple class was constructed. 3 destructed + 3 more at the end of main().
  //   	     (1) obj 
  // var1 -> (2) copy constructor -> (3) obj2 default constructor -> destruct obj2
  // var2 -> (4) copy constructor -> (5) obj3 default constructor -> (6) copy constructor obj 3 -> return -> destruct obj3 + copy
  // var3 -> references same var2 object
  // var4 -> references same var2 object
  //Once the function ended, they were destructed leaving the original "obj" in line 10 and
  //the retained SimpleClass in each variable with a returned Simple class object (i.e. f1, f2).


  TestResult tr;
  TestRegistry::runAllTests(tr);

  return 0;
}
