#pragma once
class CRabinStr
{
public:
	CRabinStr();

	void RabinProcess(std::string const& input);
	void OutInFile();
	std::vector <std::pair<size_t, size_t>> GetOccurrenceList();
private:
	void SetSumm();
	void CheckStr(std::string const& line, size_t const& pos);
	void HendleString(std::string const& line);
	size_t m_lineCount;
	size_t m_strSumm;
	std::string m_str;
	std::vector <std::pair<size_t, size_t>> m_occurrenceList;
};

