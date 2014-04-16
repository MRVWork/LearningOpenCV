#include "cv.h"
#include "highgui.h"

#define h 280
#define w 320

int main()
{
	CvCapture* capture = 0;

	capture = cvCaptureFromCAM(0);

	if(!capture)
	{
		return -1;
	}	

	cvNamedWindow("Video");

	IplImage *frame=0;
	IplImage *resize_frame=cvCreateImage(cvSize(w,h), 8, 3);
	IplImage *grey_resize_frame=cvCreateImage(cvSize(w,h), 8, 1);

	CvSeq* contours;
	CvSeq* result;

	CvMemStorage *storage=cvCreateMemStorage(0);

	while(true)
	{
		frame = cvQueryFrame(capture);

		cvResize(frame, resize_frame, CV_INTER_LINEAR);
		
		cvCvtColor(resize_frame, grey_resize_frame, CV_BGR2GRAY);

/*
		cvFindContours(grey_resize_frame, storage, &contours, sizeof(CvContour),  CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

		int k=0;
		while(contours)
		{
			result = cvApproxPoly(contours, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contours)*.02,0);

			printf("%d: Total points in contour = %d\n", k++, result->total);
		
			if(result->total == 4)
			{
				CvPoint *pt[3];
				
				for(int i=0;i<4;i++)
				{
					pt[i] = (CvPoint*)cvGetSeqElem(result, i);
				} 

				cvLine(resize_frame, *pt[0], *pt[1], cvScalar(0, 0,255),4);
				cvLine(resize_frame, *pt[1], *pt[2], cvScalar(0, 0,255),4);
				cvLine(resize_frame, *pt[2], *pt[3], cvScalar(0, 0,255),4);
				cvLine(resize_frame, *pt[3], *pt[0], cvScalar(0, 0,255),4);
			}


			contours = contours->h_next;
		}
*/


		cvShowImage("Video", resize_frame);

		cvWaitKey(1);

	
	}
}
