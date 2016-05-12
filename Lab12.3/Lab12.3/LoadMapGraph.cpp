#include "stdafx.h"
#include "LoadMapGraph.h"

Conflict for Stepan Domasevich
this is commit for education on pull requests

void CLoadMapGraph::InitGraph()
{
	m_roads.resize(m_countTowns);
	m_towns.resize(m_countTowns);
	m_towns[0] = INT32_MAX;

	for (auto &it : m_roads)
	{
		it.resize(m_countTowns, -1);
	}
}

void CLoadMapGraph::ReadFromFile(std::string const& fileName)
{
	std::fstream input(fileName);
	input >> m_countTowns;
	input >> m_countRoads;
	InitGraph();

	std::string line;
	unsigned x;
	unsigned y;
	unsigned wt;
	while(input)
	{
		input >> x;
		input >> y;
		input >> wt;
		m_roads[x - 1][y - 1] = wt;

	}
}

int FindMin(unsigned const& a, unsigned const& b)
{
	if (a > b)
		return b;
	return a;
}

int FindMax(unsigned const& a, unsigned const& b)
{
	if (a < b)
		return b;
	return a;
}

void CLoadMapGraph::FindHeavierLoads()
{
	for (int from = 0; from < m_roads.size(); ++from)
	{
		for (int to = 0; to < m_roads.size(); ++to)
		{
			if (m_roads[from][to] != -1)
			{
				m_towns[to] = FindMax(FindMin(m_roads[from][to], m_towns[from]), m_towns[to]);
			}
		}
	}
}
