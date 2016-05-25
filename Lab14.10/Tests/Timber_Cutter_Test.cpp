#include "stdafx.h"
#include "../Lab14.10/Jewish—arpenter.h"

struct JCWorker
{
	CJewish—arpenter worker;
};

BOOST_FIXTURE_TEST_SUITE(Jewish_Carpenter, JCWorker);

	BOOST_AUTO_TEST_CASE(when_0_cut_return_0_price)
	{
		worker.SetTimber(123, 0);
		BOOST_CHECK_EQUAL(worker.GetCost(), 0);
	}

	BOOST_AUTO_TEST_CASE(when_1_cut_return_length_price)
	{
		worker.SetTimber(123, 1);
		BOOST_CHECK_EQUAL(worker.GetCost(), 123);
	}

	BOOST_AUTO_TEST_CASE(when_3_cuts)
	{
		worker.SetTimber(100, 3);
		BOOST_CHECK_EQUAL(worker.GetCost(), 105);
	}

	BOOST_AUTO_TEST_CASE(big_timber_with_many_cuts)
	{
		worker.SetTimber(200000, 160000);
		BOOST_CHECK_EQUAL(worker.GetCost(), 2923392);
	}
BOOST_AUTO_TEST_SUITE_END();