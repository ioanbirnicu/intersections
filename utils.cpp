#include "utils.h"

void readInputFromFile(fstream &inputFile, vector<Rectangle> &rectangles)
{
	int x, y, w, h;
	while (inputFile >> x >> y >> w >> h)
	{
		rectangles.push_back(Rectangle(x, y, w, h));
	}
}

void writeInputToFile(ofstream &outputFile, vector<Rectangle> const &rectangles)
{
	outputFile << "Input:" << endl;
	
	vector<Rectangle>::const_iterator it = rectangles.begin();
	for (; it != rectangles.end(); ++it)
	{
		int currentIndex = it - rectangles.begin() + 1;
		outputFile << "\t" << currentIndex << ": Rectangle at (" << it->x << "," << it->y << "), "
				   "w=" << it->w << ", h=" << it->h << "." << endl;
	}
	outputFile << endl;
}

void printIntersectionsToFile(ofstream &outputFile, vector<Rectangle> const &rectangles)
{
	vector<Rectangle>::const_iterator it = rectangles.begin();
	for (; it != rectangles.end(); ++it)
	{
		outputFile << "\tBetween rectangle " << it->parentRectangles[0];
		int size = it->parentRectangles.size();
		for (int i = 1; i < size - 1; ++i)
		{
			outputFile <<", " << it->parentRectangles[i];
		}
		outputFile << " and " << it->parentRectangles[size - 1] << " at (" << it->x << "," << it->y << "), "
				   "w=" << it->w << ", h=" << it->h << "." << endl;
	}
}

void initializeIntersections(vector<Rectangle> &intersections, vector<Rectangle> const &rectangles)
{
	vector<Rectangle>::iterator it = intersections.begin();
	for (; it != intersections.end(); ++it)
	{
		int currentIndex = it - intersections.begin() + 1;
		it->parentRectangles.push_back(currentIndex);
	}
}

void writeIntersectionsToFile(ofstream &outputFile, vector<Rectangle> const &rectangles)
{
	outputFile << "Intersections:" << endl;
	bool intersectionsExist = true;
	
	// this vector retains the intersections of x Rectangles. Initialized first with the current rectangle index
	vector<Rectangle> intersections(rectangles);
	vector<Rectangle> newIntersections;
	initializeIntersections(intersections, rectangles);
	 
	// at first, consider rectangle intersections of 2, then 3, and so on
	// compare each original rectangle with the existing intersections rectangles
	// retain the new formed intersections in newIntersections, and then print them
	while (intersectionsExist == true) 
	{
		intersectionsExist = false;
		for (vector<Rectangle>::const_iterator it = rectangles.begin(); it != rectangles.end(); ++it)
		{
			int currentRectangleIndex = it - rectangles.begin() + 1;			
			for (vector<Rectangle>::const_iterator it_inter = intersections.begin(); it_inter != intersections.end(); ++it_inter)
			{
				Rectangle tempRect = it->intersectionWith(*it_inter);
				if (!(tempRect == Rectangle(0, 0, 0, 0))) 
				{
					int maxIndexParent = *max_element(it_inter->parentRectangles.begin(), it_inter->parentRectangles.end());
					if (currentRectangleIndex > maxIndexParent) // to avoid duplicates
					{
						tempRect.parentRectangles = it_inter->parentRectangles;
						tempRect.parentRectangles.push_back(currentRectangleIndex);
						newIntersections.push_back(tempRect);
						intersectionsExist = true;
					}
				}
			}
		}
		printIntersectionsToFile(outputFile, newIntersections);
		intersections = newIntersections;
		newIntersections.clear();
	}
}

template<typename InputIterator1, typename InputIterator2>
bool
range_equal(InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2)
{
    while(first1 != last1 && first2 != last2)
    {
        if(*first1 != *first2) return false;
        ++first1;
        ++first2;
    }
    return (first1 == last1) && (first2 == last2);
}

bool compare_files(const std::string& filename1, const std::string& filename2)
{
    std::ifstream file1(filename1.c_str());
    std::ifstream file2(filename2.c_str());

    std::istreambuf_iterator<char> begin1(file1);
    std::istreambuf_iterator<char> begin2(file2);

    std::istreambuf_iterator<char> end;

    return range_equal(begin1, end, begin2, end);
}

void run_tests(const std::string& inputFileName, const std::string& outputFileName)
{
	if (inputFileName == "IO\\input1.txt")
	{
		compare_files(outputFileName, "IO\\outputExpectedForInput1.txt") == true ? 
		std::cout << "Results OK for input1" << endl : std::cout << "Results NOK for input1" << endl;
	}
	
	if (inputFileName == "IO\\input2.txt")
	{
		compare_files(outputFileName, "IO\\outputExpectedForInput2.txt") == true ? 
		std::cout << "Results OK for input2" << endl : std::cout << "Results NOK for input2" << endl;
	}
	
	if (inputFileName == "IO\\input3.txt")
	{
		compare_files(outputFileName, "IO\\outputExpectedForInput3.txt") == true ? 
		std::cout << "Results OK for input3" << endl : std::cout << "Results NOK for input3" << endl;
	}
}
