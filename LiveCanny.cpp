#include <cv.h>
#include <highgui.h>

using namespace std;

#define h 240 
#define w 320 

CvFont font;
double hScale=0.25;
double vScale=0.25;
int lineWidth=0.5;

int main()
{
	IplImage *img=cvCreateImage(cvSize(w, h), 8, 3);
	IplImage *grey_img=cvCreateImage(cvSize(w, h), 8, 1);

	CvCapture* capture = 0;

	capture = cvCreateCameraCapture(0);

	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, w);
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, h);

	if(!capture)
	{
		return -1;
	}	

	cvNamedWindow("Original Image");

	while(1)
	{
		frame = cvQueryFrame(capture);
		
		cvShowImage("Original Image", frame);
		
		cvWaitKey(1);	
	}
	


}
