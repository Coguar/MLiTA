#pragma once
class CJewish—arpenter
{
public:
	CJewish—arpenter();
	void SetTimber(std::string const& fileName);
	void SetTimber(size_t length, size_t cutCount);
	size_t GetCost();

private:
	void ReadFromFile(std::string const& fileName);
	void CutTimber();

	size_t m_length;
	size_t m_cutCount;
	size_t m_cost;
};

