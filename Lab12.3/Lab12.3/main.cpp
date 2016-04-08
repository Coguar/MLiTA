// Lab12.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LoadMapGraph.h"

int main()
{
	CLoadMapGraph graph("input.txt");
	graph.OutputInFile("output.txt");
    return 0;
}

