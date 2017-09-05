#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include <stdio.h>

int main(void)
{
	IplImage* src;
	src=cvLoadImage("eggs1.jpg",1);

	IplImage* hsv = cvCreateImage( cvGetSize(src), 8, 3 );
		IplImage* hsv2 = cvCreateImage( cvGetSize(src), 8, 3 );
		IplImage* bgr = cvCreateImage( cvGetSize(src), 8, 3 );
		IplImage* grey = cvCreateImage( cvGetSize(src), 8, 1 );
		IplImage* grey2 = cvCreateImage( cvGetSize(src), 8, 1 );
		IplImage* disp = cvCreateImage( cvGetSize(src), 8, 3 );

		cvCvtColor( src, hsv, CV_BGR2HSV );


			//Classify images
			CvMat *mat1 = cvCreateMat(src->height,src->width,CV_16UC3);
			cvConvert( src, mat1 );

			CvScalar scAvg1 = cvAvg(mat1);
				double AVG=(scAvg1.val[0]+scAvg1.val[0]+scAvg1.val[0])/3;

				IplImage* h_plane = cvCreateImage( cvGetSize(src), 8, 1 );
				IplImage* s_plane = cvCreateImage( cvGetSize(src), 8, 1 );
				IplImage* v_plane = cvCreateImage( cvGetSize(src), 8, 1 );
				IplImage* s_plane2 = cvCreateImage( cvGetSize(src), 8, 1 );

				cvCvtPixToPlane( hsv, h_plane, s_plane, v_plane, 0 );

				int w = src->width;
				int h = src->height;

	return 0;
}
