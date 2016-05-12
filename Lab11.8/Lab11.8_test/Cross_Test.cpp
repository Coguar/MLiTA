#include "stdafx.h"
#include "../Lab11.8/CrossChecker.h"

struct Checker
{
	Checker()
	{
		a = LineSegment(Point(1, 2), Point(4, 2));
		b = LineSegment(Point(2, 0), Point(2, 7));
		b = LineSegment(Point(3, 0), Point(3, 7));
		point_on_a = LineSegment(Point(3, 2), Point(3, 2));
		point_on_empty_place = LineSegment(Point(9, 9), Point(9, 9));
	}
	CCrossChecker checker;
	LineSegment a;
	LineSegment b;
	LineSegment c;
	LineSegment point_on_a;
	LineSegment point_on_empty_place;


};

BOOST_FIXTURE_TEST_SUITE(testing_linesegments_on_cross, Checker);

BOOST_AUTO_TEST_CASE(they_crossing_if_they_are_equal)
{
	checker.SetLineSegments(a, a);
	BOOST_CHECK(checker.IsCrossing());
}

BOOST_AUTO_TEST_CASE(they_not_crossing_if_they_are_have_not_cross_point)
{
	checker.SetLineSegments(b, c);
	BOOST_CHECK(!checker.IsCrossing());
}

BOOST_AUTO_TEST_CASE(they_crossing_if_they_are_have_cross_point)
{
	checker.SetLineSegments(a, b);
	BOOST_CHECK(checker.IsCrossing());
}

BOOST_AUTO_TEST_CASE(they_not_crossing_if_they_are_points_and_not_equal)
{
	checker.SetLineSegments(point_on_empty_place, point_on_a);
	BOOST_CHECK(!checker.IsCrossing());
}


BOOST_AUTO_TEST_SUITE_END();