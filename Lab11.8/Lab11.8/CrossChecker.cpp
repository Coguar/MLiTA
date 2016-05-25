#include "stdafx.h"
#include "CrossChecker.h"

void CCrossChecker::ReadDataFromFile(std::string const & fileName)
{
	std::ifstream input(fileName);
	std::vector<int> coordinates(8);
	for (int &it : coordinates)
	{
		input >> it;
	}
	m_firstLine = LineSegment(Point(coordinates[0], coordinates[1]), Point(coordinates[2], coordinates[3]));
	m_secondLine = LineSegment(Point(coordinates[4], coordinates[5]), Point(coordinates[6], coordinates[7]));
}

void CCrossChecker::WriteAnswerIntoFile(bool isCrossing)
{
	std::ofstream output("output.txt");
	std::string answer = (isCrossing ? "Yes" : "No");
	output << answer << std::endl;
}

void CCrossChecker::SetLineSegments(LineSegment const & fLine, LineSegment const & sLine)
{
	m_firstLine = fLine;
	m_secondLine = sLine;
}

bool CCrossChecker::IsCrossing()
{
	auto fBegin = m_firstLine.beginPos;
	auto fEnd = m_firstLine.endPos;
	auto sBegin = m_secondLine.beginPos;
	auto sEnd = m_secondLine.endPos;
	if ((sBegin == fBegin) || (sBegin == fEnd) || (sEnd == fBegin) || (sEnd == fEnd))
	{
		return true;
	}
	auto X1 = (sEnd.x - sBegin.x) * (fBegin.y - sBegin.y) - (sEnd.y - sBegin.y) * (fBegin.x - sBegin.x);
	auto X2 = (sEnd.x - sBegin.x) * (fEnd.y - sBegin.y)	- (sEnd.y - sBegin.y) * (fEnd.x - sBegin.x);
	auto X3 = (fEnd.x - fBegin.x) * (sBegin.y - fBegin.y) - (fEnd.y - fBegin.y) * (sBegin.x - fBegin.x);
	auto X4 = (fEnd.x - fBegin.x) * (sEnd.y - fBegin.y)	- (fEnd.y - fBegin.y) * (sEnd.x - fBegin.x);
	return ((X1 * X2) < 0) && ((X3 * X4) < 0);
}

const bool Point::operator==(Point const & otherPoint)
{
	return (x == otherPoint.x) && (y == otherPoint.y);
}
