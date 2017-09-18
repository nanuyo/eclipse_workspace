

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main () {
vector<vector<Point> > contours;
vector<Vec4i> hierarchy;
Rect bounding_rect;
Mat dst,bin;

Mat src = imread("/home/hjpark/Pictures/eggs4.jpg", CV_LOAD_IMAGE_COLOR); // reads image from file


cvtColor(src,dst,CV_BGR2GRAY);  // converts image from rgb(src) to gray level (dst)
threshold(dst,bin,100,255,THRESH_BINARY); // Tresholds image with level = 40 from gray level(dst) to binary (bin)
findContours(bin,contours, hierarchy,CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE ); // finds contours on bin image

Scalar color( 255,255,255 );
for( int i = 0; i< contours.size(); i++ ) // iterate through each contour.
  {
   if((contourArea(contours[i],false))>100){ // if counter area >100 pixel draw it on ero which is new image variable
    drawContours( bin, contours, i , color, CV_FILLED, 8, hierarchy ); //Draw contours on itself as filled
                                            }
   }

 findContours( bin, contours, hierarchy,CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE );

 for( int i = 0; i< contours.size(); i++ ) // iterate through each contour.
  {
      bounding_rect=boundingRect(contours[i]); //Bound and Draw rectangle each object which detected at the end on src(original image)
      rectangle(src, bounding_rect,  Scalar(0,255,0),3, 8,0);
   }
   namedWindow("Binary",CV_WINDOW_NORMAL);
   imshow("Binary",src);
   cout<<contours.size();
   waitKey(0);
   return 0;
}
