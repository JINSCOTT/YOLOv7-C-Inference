#pragma once
#include <onnxruntime_cxx_api.h>
#include<opencv2/opencv.hpp>
#include "Label.h"
#pragma comment(lib, "onnxruntime.lib")

class detection {
public:
	detection(int b, float x, float y, float xx, float yy, int label, float prob) {
		batch = b;
		x1 = x;
		y1 = y;
		x2 = xx;
		y2 = yy;
		Label = label;
		class_prob = prob;
	};
	int batch = 0;
	float x1, y1, x2, y2;
	int Label;
	float class_prob;
};

class YOLOv7 {
public:
	~YOLOv7() {
		if (sessionOptions != nullptr)delete(sessionOptions);
		if (session != nullptr) {
			session.release();
			delete(session);
		}
	}
	bool init(const wchar_t* ModelPath,bool UseCUDA);
	void preprocess(cv::Mat image);
	void predict();
	void DrawDetected(cv::Mat image);
	cv::Size original;
	bool UseCuda = false;
	bool debug = true;
	std::vector<detection> Detected;

private:
	std::vector<float>* input_tensor_values;
	std::vector<Ort::Value> inputTensor;
	std::vector<Ort::Value> outputTensor;
	size_t num_input_nodes;
	std::vector<const char*>* input_node_names;
	std::vector<int64_t> input_node_dims;
	char* input_name;
	char* output_name;

	Ort::Env env = Ort::Env(OrtLoggingLevel::ORT_LOGGING_LEVEL_WARNING, "Default");;
	Ort::MemoryInfo memory_info{ nullptr };
	Ort::AllocatorWithDefaultOptions allocator;
	ONNXTensorElementDataType type;
	Ort::TypeInfo* type_info;
	OrtCUDAProviderOptions cuda_options;
	Ort::SessionOptions *sessionOptions = nullptr;
	Ort::Session session{ nullptr };
	const COCOLabels LabelMap;
};


//env = Ort::Env( OrtLoggingLevel::ORT_LOGGING_LEVEL_WARNING, "Default");