#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<iostream>
#include<Windows.h>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture pozitif(0);
	if (!pozitif.isOpened())
	{
		cout << "kamera bulunamadi";
		return -1;
	}
	int i = 0;
	while (true)
	{
		Mat okuma;
		bool kontrol = pozitif.read(okuma);
		cvtColor(okuma, okuma, COLOR_BGR2GRAY);
		resize(okuma, okuma, Size(450, 450));
		if (!kontrol) {
			cout << "frame alýnamadi";
			break;
		}
		imshow("webcam", okuma);
		if (waitKey(20) == 27)break;
		imwrite("p"+to_string(i) + ".jpg",okuma);
		waitKey(0);
		i++;
	}
}