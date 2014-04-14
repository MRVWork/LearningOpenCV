#include <cv.h>
#include <highgui.h>

#include <time.h>
#include <stdio.h>

using namespace std;

int main(int argc, char ** argv)
{
	CvCapture *capture = cvCaptureFromCAM(0);

	time_t start, end;

	double fps;

	int counter = 0;

	double sec;

	time(&start);

	while (cvGrabFrame(capture))
	{
		IplImage *frame = cvRetrieveFrame(capture);

		time(&end);
		++counter;

		sec = difftime(end, start);

		fps = counter / sec;

		printf("FPS = %.2f\n", fps);

	}

	cvReleaseCapture(&capture);

	return 0;

	}



