// Lab13.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RabinStr.h"

int main()
{
	CRabinStr rabin;
	rabin.RabinProcess("input.txt");
	rabin.OutInFile();
    return 0;
}

