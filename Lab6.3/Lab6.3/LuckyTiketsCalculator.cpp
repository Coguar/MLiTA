#include "stdafx.h"
#include "LuckyTiketsCalculator.h"


CLuckyTiketsCalculator::CLuckyTiketsCalculator()
	: m_firstSum(0)
	, m_secondSum(0)
	, m_ticketsCount(0)
{}

void CLuckyTiketsCalculator::ReadFromFile(std::string const & fileName)
{
	std::ifstream input(fileName);
	input >> m_digitsCount;
	std::string number;
	input >> number;
	int i = 0;
	m_FirstPart.resize(m_digitsCount);
	for (i; i < m_digitsCount; ++i)
	{
		m_FirstPart[m_digitsCount - 1 - i] = number[i] - '0';
		m_firstSum += number[i] - '0';
	}
	m_numbers.resize(m_digitsCount);
	for (i; i < m_digitsCount * 2; ++i)
	{
		m_numbers[m_digitsCount - 1 - (i - m_digitsCount)] = number[i] - '0';
		m_secondSum += number[i] - '0';
	}
}

void CLuckyTiketsCalculator::IncrementedPositionInNumber(int const& position)
{
	auto pos = position;
	++m_ticketsCount;
	if (m_numbers[pos] < 10)
	{
		++m_numbers[pos];
		++m_secondSum;
	}
	while (m_numbers[pos] >= 10)
	{
		m_secondSum -= 9;
		m_numbers[pos] = 0;
		if ((pos + 1) < m_digitsCount)
		{
			m_numbers[pos + 1] += 1;
		}
		++pos;
	}
}

int CLuckyTiketsCalculator::GetAnswer() const
{
	return m_ticketsCount;
}

void CLuckyTiketsCalculator::DoCalculation()
{
	int position = 0;
	while (m_firstSum > m_secondSum)
	{
		if ((m_firstSum - m_secondSum) > (9 - m_numbers[position]))
		{
			m_secondSum += 9 - m_numbers[position];
			m_ticketsCount += (9 - m_numbers[position]) * int(std::pow(10, position));
			m_numbers[position] = 9;
			++position;
		}
		else
		{
			m_ticketsCount += (m_firstSum - m_secondSum) * int(std::pow(10, position));
			m_secondSum += m_firstSum - m_secondSum;
		}
	}

	while (m_firstSum != m_secondSum)
	{
		IncrementedPositionInNumber(0);
	}
}
