#include "stdafx.h"
#include "../Lab6.3/LuckyTiketsCalculator.h"

struct Vasya
{
	CLuckyTiketsCalculator calc;
};

BOOST_FIXTURE_TEST_SUITE(testing_Vasyas_calculator, Vasya);

BOOST_AUTO_TEST_CASE(ticket_already_lucky)
{
	calc.ReadFromFile("./test/lucky.txt");
	calc.DoCalculation();
	BOOST_CHECK_EQUAL(calc.GetAnswer(), 0);
}

BOOST_AUTO_TEST_CASE(ticket_less_then_lucky_on_1)
{
	calc.ReadFromFile("./test/one_to_luck.txt");
	calc.DoCalculation();
	BOOST_CHECK_EQUAL(calc.GetAnswer(), 1);
}

BOOST_AUTO_TEST_CASE(ticket_not_lucky)
{
	calc.ReadFromFile("./test/no_luck.txt");
	calc.DoCalculation();
	BOOST_CHECK_EQUAL(calc.GetAnswer(), 8);
}

BOOST_AUTO_TEST_CASE(big_ticket_not_lucky)
{
	calc.ReadFromFile("./test/big_no_luck.txt");
	calc.DoCalculation();
	BOOST_CHECK_EQUAL(calc.GetAnswer(), 69);
}

BOOST_AUTO_TEST_CASE(reversed_ticket_not_lucky)
{
	calc.ReadFromFile("./test/reversed_no_luck.txt");
	calc.DoCalculation();
	BOOST_CHECK_EQUAL(calc.GetAnswer(), 69);
}
BOOST_AUTO_TEST_SUITE_END();