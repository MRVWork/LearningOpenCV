#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

int main( int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "Not enough parameters" << endl;
        return -1;
    }

    Mat I, J;
    if( argc == 4 && !strcmp(argv[3],"G") )
        I = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    else
        I = imread(argv[1], CV_LOAD_IMAGE_COLOR);

	imshow("Something", I);


    if (!I.data)
    {
        cout << "The image" << argv[1] << " could not be loaded." << endl;
        return -1;
    }

    int divideWith = 0; // convert our input string to number - C++ style
    stringstream s;
    s << argv[2];
    s >> divideWith;
    if (!s || !divideWith)
    {
        cout << "Invalid number entered for dividing. " << endl;
        return -1;
    }

    uchar table[256];
    for (int i = 0; i < 256; ++i)
       table[i] = (uchar)(divideWith * (i/divideWith));

    Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.data;
    for( int i = 0; i < 256; ++i)
        p[i] = table[i];

     LUT(I, lookUpTable, J);

	imshow("Something2", J);

waitKey(0);
    return 0;
}

