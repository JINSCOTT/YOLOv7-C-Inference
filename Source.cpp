#include <opencv2/core.hpp>
#include <iostream>
#include "CaptureDevice.h"
#include <chrono>
#include "ONNXModel.h"
# define mode 0
int main(int, char**)
{
	
	auto providers = Ort::GetAvailableProviders();
	for (auto provider : providers) {
		std::cout << provider << std::endl;
	}
	std::cout << "start"<<std::endl;
	YOLOv7 *Detector = new YOLOv7();

	cv::Mat frame;
	Detector->init(L"yolov7.onnx", true);
	
	if (mode == 1) {
		frame = cv::imread("bus.jpg");
		auto start = std::chrono::high_resolution_clock::now();
		Detector->preprocess(frame);
		Detector->predict();
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		std::cout << "inference time: " << duration.count() << " ms" << std::endl;
		Detector->DrawDetected(frame);
		cv::imshow("result", frame);
		std::cout << "press key to end" << std::endl;
		cv::waitKey(0);
	}
	else {
		CaptureDevice cap(0, 0);
		cap.Init();
		std::cout << "press ESC to end loop" << std::endl;
		while (1) {
			cap.Update();
			frame = cap.GetFrame();
			auto start = std::chrono::high_resolution_clock::now();
			Detector->preprocess(frame);
			Detector->predict();
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
			std::cout << "inference time: " << duration.count() << " ms" << std::endl;
			Detector->DrawDetected(frame);
			cv::imshow("result", frame);
			if (cv::waitKey(1) == 27) {
				cap.Close();
				break;
			}
		}
	}
	delete(Detector);
	cv::destroyAllWindows();
	return 0;
}


