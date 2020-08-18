// захват с камеры, лог-полярные координаты, запись на hdd

#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
	cv::namedWindow("Example", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("ExamplePolar", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap (0);

	double fps = cap.get(cv::CAP_PROP_FPS);

	cv::Size size(int(cap.get(cv::CAP_PROP_FRAME_WIDTH)), int(cap.get(cv::CAP_PROP_FRAME_HEIGHT)));

	cv::VideoWriter writer;

	writer.open("test.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);
	
	cv::Mat logpolar_frame, bgr_frame;

	while (true)
	{
		cap >> bgr_frame;
		if (bgr_frame.empty())
			break;
		cv::imshow("Example", bgr_frame);
		cv::logPolar(bgr_frame, logpolar_frame, cv::Point2f(bgr_frame.cols / 2, bgr_frame.rows / 2), 30, cv::WARP_FILL_OUTLIERS);

		cv::imshow("ExamplePolar", logpolar_frame);

		writer << logpolar_frame;

		char c = cv::waitKey(10);
		if (c == 27)
			break;
	}
	
	cap.release();
	
	cv::destroyAllWindows();
	return 0;
}
