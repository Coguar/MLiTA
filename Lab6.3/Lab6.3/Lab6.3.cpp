// Lab6.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LuckyTiketsCalculator.h"

int main()
{
	CLuckyTiketsCalculator calc;
	calc.ReadFromFile("input.txt");
	calc.DoCalculation();
	auto an = calc.GetAnswer();
    return 0;
}

