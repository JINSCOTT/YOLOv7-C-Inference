#include "CaptureDevice.h"

CaptureDevice::CaptureDevice() {};
CaptureDevice::CaptureDevice(std::string Fname) {
	CaptureDevice::Fname = Fname;
	mode = 1;
}
CaptureDevice::CaptureDevice(int DeviceID, int API_ID) {
	CaptureDevice::deviceID = DeviceID;
	CaptureDevice::API = API_ID;
	mode = 0;
}

bool CaptureDevice::Init() {
	if (mode == 1) {
		CaptureDevice::cap = new cv::VideoCapture(Fname);
	}
	else {
		CaptureDevice::cap = new cv::VideoCapture(deviceID, API);
	}
	if (!CaptureDevice::cap->isOpened()) {
		std::cerr << "ERROR! Unable to open camera\n";
		return false;
	}
	else return true;
}

bool CaptureDevice::Init(int DeviceID, int API_ID) {
	mode = 0;
	CaptureDevice::deviceID = DeviceID;
	CaptureDevice::API = API_ID;
	CaptureDevice::cap = new cv::VideoCapture(deviceID, API);
	if (!CaptureDevice::cap->isOpened()) {
		std::cerr << "ERROR! Unable to open camera\n";
		return false;
	}
	else return true;
}

bool CaptureDevice::Init(std::string Fname) {
	mode = 1;
	CaptureDevice::Fname = Fname;
	CaptureDevice::cap = new cv::VideoCapture(Fname);
	if (!CaptureDevice::cap->isOpened()) {
		std::cerr << "ERROR! Unable to open camera\n";
		return false;
	}
	else return true;
}
void CaptureDevice::Close() {
	if (cap != nullptr) {
		cap->release();
		delete(cap);
	}
}

bool CaptureDevice::Update() {
	return cap->read(Mat);
}

bool CaptureDevice::IsOpen() {
	if (cap != nullptr) {
		return cap->isOpened();
	}
	else {
		return false;
	}
}

cv::Mat CaptureDevice::GetFrame() {
	return Mat;
}