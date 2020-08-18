#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
	cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example2", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example3", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;

	if (argc == 1)
	{
		cap.open(0);
	}
	else
	{
		cap.open(argv[1]);
	}

	if (!cap.isOpened()) 
	{
		std::cerr << "Ошибка при открытии устройства захвата!" << std::endl;
		return EXIT_FAILURE;
	}

	cv::Mat frame, cannyFrame, greyframe;

	while (true)
	{
		cap >> frame;
		cv::cvtColor(frame, greyframe, cv::COLOR_BGR2GRAY);
		cv::Canny(greyframe, cannyFrame, 10, 100, 3, true);
		if (frame.empty())
			break;
		cv::imshow("Example2", cannyFrame);
		cv::imshow("Example1", frame);
		cv::imshow("Example3", greyframe);
		if (cv::waitKey(33) >= 0)
			break;
	}

	
	cv::destroyAllWindows();
	return 0;
}
