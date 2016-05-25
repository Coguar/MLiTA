#pragma once

// TODO: read about <stdint.h>

class CLuckyTiketsCalculator
{
public:
	CLuckyTiketsCalculator();

	void ReadFromFile(std::string const& fileName);
	void DoCalculation();
	void IncrementedPositionInNumber(int const& position);
	int GetAnswer() const;
private:
	int m_firstSum;
	int m_secondSum;
	int m_digitsCount;
	int m_ticketsCount;

	std::vector<int> m_numbers;
	std::vector<int> m_FirstPart;

};

