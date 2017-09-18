#include "preprocess.hpp"

int main()
{
	int coin_no = 70;
	String  fname = format("/home/hjpark/Pictures/eggs1.jpg", coin_no);
	Mat  image  = imread(fname, 1 );
	CV_Assert(image.data);
	
	Mat th_img = preprocessing(image);
	vector<RotatedRect> circles = find_coins(th_img);

	for (int i = 0; i < circles.size(); i++) 
	{
		float radius = circles[i].angle * -1;
		cout << "i=" << i << " radius=" << radius << " Center=" << circles[i].center << "\n";
		if(radius>1)
	    circle(image, circles[i].center, radius, Scalar(0, 255, 0), 1, 4, 0);
	}

	imshow("Preprocessed image", th_img);
	imshow("Original", image);
	waitKey();

	return 0;
}



