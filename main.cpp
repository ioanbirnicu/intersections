#include <iostream>
#include "utils.h"

using namespace std;

int main(int argc, char **argv)
{
	string inputFileName(argv[1]);  // IO\\input1.txt
	string outputFileName("IO\\output.txt"); 
	fstream inputFile(inputFileName.c_str(), ios_base::in); 
	ofstream outputFile(outputFileName.c_str(), ofstream::out);
	
	vector<Rectangle> rectangles;
	
	readInputFromFile(inputFile, rectangles);	
	writeInputToFile(outputFile, rectangles);
	writeIntersectionsToFile(outputFile, rectangles);
	
	inputFile.close();
	outputFile.close();
	
	// run a few tests
	// check if the output of a defined input matches the expected output for that input
	run_tests(inputFileName, outputFileName);
	
	return 0;
}

