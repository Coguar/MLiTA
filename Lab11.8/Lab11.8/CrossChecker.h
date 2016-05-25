#pragma once


struct Point
{
	Point(){}
	Point(int xPos, int yPos)
		: x(xPos)
		, y(yPos)
	{}
	const bool operator== (Point const& otherPoint);
	int x;
	int y;
};

struct LineSegment
{
	LineSegment(){}
	LineSegment(Point const& begin, Point const& end)
		: beginPos(begin)
		, endPos(end)
	{}
	Point beginPos;
	Point endPos;
};

class CCrossChecker
{
public:
	CCrossChecker() {};
	void ReadDataFromFile(std::string const& fileName);
	void WriteAnswerIntoFile(bool isCrossing);
	void SetLineSegments(LineSegment const& fLine, LineSegment const& sLine);
	bool IsCrossing();

private:
	LineSegment m_firstLine;
	LineSegment m_secondLine;
};

