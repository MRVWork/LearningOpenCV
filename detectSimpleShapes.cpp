#include <cv.h>
#include <highgui.h>

using namespace std;

#define h 480
#define w 640 

CvFont font;
double hScale=0.5;
double vScale=0.5;
int lineWidth=1;

int main()
{
	IplImage *img=cvCreateImage(cvSize(w, h), 8, 3);
	IplImage *grey_img=cvCreateImage(cvSize(w, h), 8, 1);

	cvCircle(img, cvPoint(200,200), 50, cvScalar(255, 0, 0, 4), -1, 8, 1);

	cvRectangle(img, cvPoint(100, 150), cvPoint(1500, 250), cvScalar(0, 255, 0, 4), -1, 8,3);

	cvCvtColor(img, grey_img, CV_BGR2GRAY);
	cvShowImage("Original Image",img);
	//cvShowImage("Grey Scale Image",grey_img);

	cvWaitKey(100);
	CvSeq* contours;
	CvSeq* result;

	CvMemStorage *storage=cvCreateMemStorage(0);

	cvFindContours(grey_img, storage, &contours, sizeof(CvContour),  CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
	

	int k=0;

	while(contours)
	{
		result = cvApproxPoly(contours, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contours)*.01,0);
	
		printf("%d. Total no of vertices = %d\n", k++, result->total);

		for(int i=0;i<result->total; i++)
		{
			if(i==0)
			{
				cvLine(img, *(CvPoint*)cvGetSeqElem(result, i),*(CvPoint*)cvGetSeqElem(result, result->total-1), cvScalar(0, 0,255),2);
			}
			else
			{
				cvLine(img, *(CvPoint*)cvGetSeqElem(result, i-1),*(CvPoint*)cvGetSeqElem(result, i), cvScalar(0, 0,255),2);
			}

		}

			char strComment[80];

			sprintf(strComment, "Polygon.%d (%d sides)", k, result->total);
			 
			cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale, vScale, 0, lineWidth);
			cvPutText(img, strComment, *(CvPoint*)cvGetSeqElem(result, 0), &font, cvScalar(255, 255, 0));

		



		contours = contours->h_next;
	}
	
	cvShowImage("Original Image",img);

cvWaitKey(100000);	


}
