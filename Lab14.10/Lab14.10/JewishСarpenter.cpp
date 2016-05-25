#include "stdafx.h"
#include "JewishÑarpenter.h"


CJewishÑarpenter::CJewishÑarpenter()
	: m_cost(0)
{
}

void CJewishÑarpenter::SetTimber(std::string const & fileName)
{
	m_cost = 0;
	ReadFromFile(fileName);
	CutTimber();
}

void CJewishÑarpenter::SetTimber(size_t length, size_t cutCount)
{
	m_cost = 0;
	m_length = length;
	m_cutCount = cutCount;
	CutTimber();
}

size_t CJewishÑarpenter::GetCost()
{
	return m_cost;
}

void CJewishÑarpenter::ReadFromFile(std::string const & fileName)
{
	std::ifstream input(fileName);
	input >> m_length;
	input >> m_cutCount;
}

void CJewishÑarpenter::CutTimber()
{
	//first - value
	//second - count
	std::map <size_t, size_t> parts = {
		{1, m_cutCount},
		{m_length - m_cutCount, 1}
	};

	while (parts.size() != 1)
	{
		auto value = parts.begin()->first;
		auto count = parts.begin()->second;

		if (count > 1)
		{
			parts.emplace(value * 2, count / 2);
			parts.begin()->second = count % 2;
			m_cost += (value * 2) * (count / 2);
		}
		else if (count == 1)
		{
			auto it = parts.begin();
			it++;
			parts.emplace(value + it->first, 1);
			m_cost += value + it->first;
			--it->second;
			parts.erase(parts.begin());
		}
		else
		{
			parts.erase(parts.begin());
		}
	}
}
