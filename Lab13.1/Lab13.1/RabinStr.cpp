#include "stdafx.h"
#include "RabinStr.h"


CRabinStr::CRabinStr()
	: m_str("")
	, m_strSumm(0)
{

}

size_t GetStartWindowSumm(size_t const& elementNum, std::string const& str)
{
	size_t summ = 0;
	for (size_t i = 0; i < elementNum; ++i)
	{
		summ += str[i];
	}
	return summ;
}

void CRabinStr::HendleString(std::string const & line)
{
	std::string tempLine(line);
	if(tempLine.size() < m_str.size())
		return;
	size_t summ = GetStartWindowSumm(m_str.size(), line);
	size_t beginPos = 0;
	size_t endPos = m_str.size() - 1;

	while (endPos <= line.size())
	{
		if (summ == m_strSumm)
		{
			CheckStr(line.substr(beginPos, m_str.size()), beginPos);
		}
		++endPos;
		if (endPos >= line.size())
			break;
		summ += line[endPos] - line[beginPos];
		++beginPos;
	}
}

void CRabinStr::OutInFile()
{
	std::ofstream output("output.txt");
	if (m_occurrenceList.empty())
	{
		output << "No" << std::endl;
	}
	else
	{
		for (auto &it : m_occurrenceList)
		{
			output << it.first << " " << it.second << std::endl;
		}
	}
}

std::vector<std::pair<size_t, size_t>> CRabinStr::GetOccurrenceList()
{
	return m_occurrenceList;
}

void CRabinStr::RabinProcess(std::string const& input)
{
	std::string textFile;
	std::ifstream inputFile(input);
	inputFile >> m_str;
	inputFile >> textFile;
	inputFile.close();
	SetSumm();

	std::ifstream inputText(textFile);
	std::string line;
	m_lineCount = 1;
	while (std::getline(inputText, line))
	{
		HendleString(line);
		++m_lineCount;
	}
}


void CRabinStr::SetSumm()
{
	for (auto &it : m_str)
	{
		m_strSumm += it;
	}
}

void CRabinStr::CheckStr(std::string const & line, size_t const& pos)
{
	if (m_str == line)
	{
		m_occurrenceList.push_back({ m_lineCount, pos });
	}
}
