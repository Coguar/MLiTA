#include "stdafx.h"
#include "CrossChecker.h"

void CCrossChecker::ReadDataFromFile(std::string const & fileName)
{
	std::ifstream input(fileName);
	std::vector<int> coordinates;
	int pos;
	for (int i = 0; i < 8; ++i)
	{
		input >> pos;
		coordinates.push_back(pos);
	}
	m_firstLine = LineSegment(Point(coordinates[0], coordinates[1]), Point(coordinates[2], coordinates[3]));
	m_secondLine = LineSegment(Point(coordinates[4], coordinates[5]), Point(coordinates[6], coordinates[7]));
}

void CCrossChecker::WriteAnswerIntoFile(bool const & isCrossing)
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
	if ((m_secondLine.beginPos == m_firstLine.beginPos) || (m_secondLine.beginPos == m_firstLine.endPos)
		|| (m_secondLine.endPos == m_firstLine.beginPos) || (m_secondLine.endPos == m_firstLine.endPos))
	{
		return true;
	}

	auto X1 = (m_secondLine.endPos.x - m_secondLine.beginPos.x) * (m_firstLine.beginPos.y - m_secondLine.beginPos.y)
		- (m_secondLine.endPos.y - m_secondLine.beginPos.y) * (m_firstLine.beginPos.x - m_secondLine.beginPos.x);
	auto X2 = (m_secondLine.endPos.x - m_secondLine.beginPos.x) * (m_firstLine.endPos.y - m_secondLine.beginPos.y)
		- (m_secondLine.endPos.y - m_secondLine.beginPos.y) * (m_firstLine.endPos.x - m_secondLine.beginPos.x);

	auto X3 = (m_firstLine.endPos.x - m_firstLine.beginPos.x) * (m_secondLine.beginPos.y - m_firstLine.beginPos.y)
		- (m_firstLine.endPos.y - m_firstLine.beginPos.y) * (m_secondLine.beginPos.x - m_firstLine.beginPos.x);
	auto X4 = (m_firstLine.endPos.x - m_firstLine.beginPos.x) * (m_secondLine.endPos.y - m_firstLine.beginPos.y)
		- (m_firstLine.endPos.y - m_firstLine.beginPos.y) * (m_secondLine.endPos.x - m_firstLine.beginPos.x);

	return ((X1 * X2) < 0) && ((X3 * X4) < 0);
}

const bool Point::operator==(Point const & otherPoint)
{
	return (x == otherPoint.x) && (y == otherPoint.y);
}
