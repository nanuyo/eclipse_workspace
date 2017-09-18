// ugaveCountEggs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include <stdio.h>


//Function to do segmentation and counting the eggs 
void doCount(char F[])
{
	//cvNamedWindow("ContourImage", 1 );

	IplImage* src;
	src=cvLoadImage(F,1);
	
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

	//Saturation Thresholding 

	/*for low values of Saturation, a color can be approximated by a
	gray value specified by the Intensity level while for higher
	Saturation, the color can be approximated by its Hue.
	It is observed that for higher
	values of intensity, a saturation of 0.2 differentiates
	between Hue and Intensity dominance*/

	/*The above methodology doesnt work good for stone background for which we use thresholding using 
	Otsu's algo that adaptively does saturation thresholding by histogram thresholding */

	if(AVG<= 114 )//for plain & grass background
	{
	for (int i = 0; i<h;i++)
	{
		for (int j = 0; j<w;j++)
		{
		int V = (unsigned char)v_plane->imageData[i*w+j];
		float thresh = 1.0- (0.8*V/255);
		//printf("%f\n",thresh);
		if(thresh<=0.2)
		{s_plane->imageData[i*w+j]=0;}
		else
		{s_plane->imageData[i*w+j]=1;}
		/*int Z =(unsigned char)s_plane->imageData[i*w+j];
		printf("%d\n",Z);*/
		
		}
	}
	}
	else //For stone background 
	{cvThreshold( s_plane, s_plane2,0, 255, CV_THRESH_OTSU  );}
	
	//Merging channels converting to RGB and GRAY and doing binary thresholding 

	if(AVG<= 114 ){
	cvMerge(h_plane, s_plane, v_plane,0,hsv2);
	cvCvtColor( hsv2, bgr, CV_HSV2BGR );
	cvCvtColor( bgr, grey, CV_BGR2GRAY );
	}


	//Binary Thresholds 

	if(AVG<= 43 )//for plain background
	{
		cvThreshold( grey, grey2, 204, 255, CV_THRESH_BINARY  );
	}
	else if(AVG>114)//for stone background
	{
		cvThreshold( s_plane2, grey2, 205, 255, CV_THRESH_BINARY  );
	}
	else if(43<AVG<=114)//for grass background
	{
		cvThreshold( grey, grey2, 208, 255, CV_THRESH_BINARY  );
	}
	
	//Finding Contour

	CvMemStorage* storage = cvCreateMemStorage();
	CvSeq* first_contour = NULL;

	int Nc = cvFindContours(
				grey2,
				storage,
				&first_contour,
				sizeof(CvContour),
				CV_RETR_LIST 
				);
	int n=0;
	int j=0;
	printf( "Total Contours Detected: %d\n", Nc );

	for( CvSeq* c=first_contour; c!=NULL; c=c->h_next) 
	{
		cvCvtColor( grey2, disp, CV_GRAY2BGR );
		cvDrawContours(
						disp,
						c,
						CV_RGB(0xff,0x00,0x00),
						CV_RGB(0x00,0x00,0xff),
						250, // Try different values of max_level, and see what happens
						2,
						8
						);
		printf("Contour #%d\n", n );
		//cvShowImage("ContourImage", disp );
		printf(" %d elements:\n", c->total );
		
		//Counting the eggs 
		if (AVG<=43)
		{
			if(c->total>40){j++;}
		}
		else if(AVG>114)
		{
			if(c->total>105 && c->total<=270 ){j++;}
			if(c->total>270 && c->total<=390){j=j+2;}
			if(c->total>390){j=j+3;}
		} 
		else if(43<AVG<=114)
		{
			if(c->total>80){j++;}
		}

		

		printf("Total no. of EGGS : %d",j);

		for( int i=0; i<c->total; ++i ) 
			{
				CvPoint* p = CV_GET_SEQ_ELEM( CvPoint, c, i );
				printf(" (%d,%d)\n", p->x, p->y );
			}
			//cvWaitKey(0);
			n++;
		}
	// Open txt file for writing & write the file names

		FILE* not = fopen("RESULT.txt", "a+");
		int c;
		for(c=0;c<18;c++) {fprintf(not,"%c",F[c]);	}
		fprintf(not," contains %d eggs. \n",j);

	printf("Finished all contours.\n");
	
	/*cvWaitKey(0);
	cvDestroyWindow("ContourImage");
	cvReleaseImage( &grey2 );*/
}


//Function to load images from text file 
int loadImage(char *filename)
{
	FILE *imgListF = 0;
	char imgFilename[100];
	int iImg, nImageF=0;

	//opening input file
	imgListF =fopen(filename,"r");

	//count no. of images 
	while(fgets(imgFilename,100,imgListF)) ++nImageF;
	rewind(imgListF);

	//retrieve file names one after the other 
	for(iImg=0;iImg<nImageF;iImg++)
		{
			//read image no. and name of image file
			fscanf(imgListF,"%s",imgFilename);
			doCount(imgFilename);
		}
	fclose(imgListF);

	return nImageF;
}




int _tmain(int argc, _TCHAR* argv[])
{
	loadImage("eggBasket.txt");
	return 0;
}

