#pragma once
// Useful if the same code will be adopted into a dll.
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
	class CaptureDevice {	
	public:
		CaptureDevice();
		CaptureDevice(std::string Fname);
		CaptureDevice(int DeviceID,int API_ID);
		CaptureDevice(int DeviceID) :CaptureDevice(DeviceID, cv::CAP_ANY) {};
	
		bool Init();
		bool Init(int DeviceID, int API_ID);
		bool Init(std::string Fname);
		void Close();
		bool Update();
		bool IsOpen();
		cv::Mat GetFrame();

	private:
	
		cv::VideoCapture *cap = nullptr;
		cv::Mat Mat;
		std::string Fname;
		int deviceID =0;
		int API = 0;
		bool mode = 0;
	};

