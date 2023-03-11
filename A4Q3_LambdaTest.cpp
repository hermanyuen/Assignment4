#include "TestHarness.h"

#include <algorithm>

//Write a lambda function that makes the following TEST pass:
//TEST(lambdaTestProblem, lambdas)
//{
//    const auto values = { 2, 4, 6, 8, 10, 12 };
//	auto sum = 0;
//
//	std::for_each(values.begin(), values.end(), /*define lambda function here*/);
//
//	CHECK_EQUAL(42, sum);
//}

TEST(lambdaTestProblem, lambdas)
{
    const auto values = { 2, 4, 6, 8, 10, 12 };
	auto sum = 0;

	std::for_each(values.begin(), values.end(), [&](int i) {
		sum += i;
		});

	CHECK_EQUAL(42, sum);
}
