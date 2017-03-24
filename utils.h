#ifndef _UTILS_
#define _UTILS_

#include <iostream>
#include <fstream>
#include <vector>
#include "Rectangle.h"

using namespace std;

void readInputFromFile(fstream &inputFile, vector<Rectangle> &rectangles);
void writeInputToFile(ofstream &outputFile, vector<Rectangle> const &rectangles);
void writeIntersectionsToFile(ofstream &outputFile, vector<Rectangle> const &rectangles);
void initializeIntersections(vector<Rectangle> const &intersections, vector<Rectangle> const &rectangles);
void printIntersectionsToFile(ofstream &outputFile, vector<Rectangle> const &rectangles);

// for tests
template<typename InputIterator1, typename InputIterator2>
bool range_equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2);
bool compare_files(const std::string& filename1, const std::string& filename2);
void run_tests(const std::string& inputFileName, const std::string& outputFileName);

#endif
