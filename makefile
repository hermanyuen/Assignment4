CC=g++
CFLAGS=-I. -I./include/CppUnitLite
CXXFLAGS += -std=c++20 -Wall -Werror
# -std=c++20: valid for g++ 10 and greater.
# -Wall: reports all warnings
# -Werror: warnings reported as errors

OBJ = CppUnitLite/Failure.o CppUnitLite/Test.o CppUnitLite/TestRegistry.o CppUnitLite/TestResult.o CppUnitLite/WFailure.o \
      Main.o \
      A4Q1_Date.o A4Q1_DateTest.o A4Q2_Write.o A4Q2_WriteTest.o A4Q3_LambdaTest.o A4Q4_SimpleClass.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(CXXFLAGS)

Assignment4: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(CXXFLAGS)


all: Assignment4

clean:
	rm *.o
	rm ./CppUnitLite/*.o
