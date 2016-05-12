// Lab11.8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CrossChecker.h"

int main()
{
	CCrossChecker checker;
	checker.ReadDataFromFile("input.txt");
	checker.WriteAnswerIntoFile(checker.IsCrossing());
    return 0;
}

