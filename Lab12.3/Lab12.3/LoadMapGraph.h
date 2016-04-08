#pragma once


typedef std::vector<std::vector<int>> Roads;
typedef std::vector<int> Towns;

class CLoadMapGraph
{
public:
	CLoadMapGraph(std::string const& fileName);
	~CLoadMapGraph();

	void OutputInFile(std::string const& fileName);

private:
	void InitGraph();

	void ReadFromFile(std::string const& fileName);

	void FindHeavierLoads();

	unsigned m_countTowns;
	unsigned m_countRoads;

	Roads m_roads;
	Towns m_towns;
};