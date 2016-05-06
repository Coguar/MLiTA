#include "stdafx.h"
#include "../Lab13.1/RabinStr.h"

struct Rabin
{
	CRabinStr rabin;
};

bool IsCollectionsEqual(std::vector<std::pair<size_t, size_t>> const& first, std::vector<std::pair<size_t, size_t>> const& second)
{
	if (first.size() != second.size())
	{
		return false;
	}
	for (size_t i = 0; i < first.size(); ++i)
	{
		if (first[i].first != second[i].first || first[i].second != second[i].second)
		{
			return false;
		}
	}
	return true;
}

BOOST_FIXTURE_TEST_SUITE(testing_rabin_string, Rabin);

BOOST_AUTO_TEST_CASE(cant_fing_into_empty_file)
{
	rabin.RabinProcess("./test_files/input3.txt");
	BOOST_CHECK(rabin.GetOccurrenceList().empty());
}

BOOST_AUTO_TEST_CASE(cant_find_word_if_it_missing_in_text)
{
	rabin.RabinProcess("./test_files/input2.txt");
	BOOST_CHECK(rabin.GetOccurrenceList().empty());
}

BOOST_AUTO_TEST_CASE(must_find_3_positions)
{
	std::vector<std::pair<size_t, size_t>> rightAnswer = { {size_t(1), size_t(5)}, { size_t(2), size_t(5)}, { size_t(3), size_t(5) } };
	rabin.RabinProcess("./test_files/input1.txt");
	auto answer = rabin.GetOccurrenceList();
	BOOST_CHECK(IsCollectionsEqual(answer, rightAnswer));
}


BOOST_AUTO_TEST_SUITE_END();