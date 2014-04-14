#include "cv.h"
#include "highgui.h"

int main()
{
	CvCapture* capture = 0;

	capture = cvCaptureFromCAM(0);

	if(!capture)
	{
		return -1;
	}	

	cvNamedWindow("video");

	IplImage *frame=0;
	IplImage *resize_frame=cvCreateImage(cvSize(320, 280), 8, 3);

	while(true)
	{
		frame = cvQueryFrame(capture);

		
		cvResize(frame, resize_frame, CV_INTER_LINEAR);
		//cvShowImage("video", frame);
		cvShowImage("video", resize_frame);

		cvWaitKey(1);
	}
}
