#include "ONNXModel.h"

bool YOLOv7::init(const wchar_t* FilePath, bool CUDA) {
	YOLOv7::UseCuda = CUDA;
	sessionOptions = new Ort::SessionOptions();
	sessionOptions->SetIntraOpNumThreads(1);
	sessionOptions->SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_ALL);
	memory_info = std::move(Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault));

	if (YOLOv7::UseCuda)
	{
		cuda_options.device_id = 0;
		cuda_options.cudnn_conv_algo_search = OrtCudnnConvAlgoSearchExhaustive;
		cuda_options.arena_extend_strategy = 1;
		cuda_options.do_copy_in_default_stream = 1;
		cuda_options.has_user_compute_stream = 0;
		cuda_options.default_memory_arena_cfg = nullptr;
		sessionOptions->AppendExecutionProvider_CUDA(cuda_options);
	}
	session = std::move(Ort::Session(env, FilePath, *sessionOptions));

	num_input_nodes = session.GetInputCount();
	input_node_names = new std::vector<const char*>(num_input_nodes);

	output_name = session.GetOutputName(0, allocator);
	for (int i = 0; i < num_input_nodes; i++) {
		input_name = session.GetInputName(i, allocator);
		input_node_names->at(i) = input_name;
		type_info = new Ort::TypeInfo(session.GetInputTypeInfo(i));
		auto tensor_info = type_info->GetTensorTypeAndShapeInfo();
		type = tensor_info.GetElementType();
		input_node_dims = tensor_info.GetShape();
	}
	return true;
}

void YOLOv7::preprocess(cv::Mat image) {
	original = image.size();
	cv::Mat blob = cv::dnn::blobFromImage(image, 1 / 255.0, cv::Size(640, 640), (0, 0, 0), false, false);

	size_t input_tensor_size = blob.total();
	input_tensor_values = new std::vector<float>((float*)blob.data, (float*)blob.data + input_tensor_size);
	inputTensor.clear();
	inputTensor.emplace_back(Ort::Value::CreateTensor<float>(memory_info, input_tensor_values->data(), input_tensor_size, input_node_dims.data(), 4));
}
void YOLOv7::predict() {
	Detected.clear();
	std::vector<const char*> output_node_names = { "output" };
	try {
		//outputTensor =
		outputTensor = session.Run(Ort::RunOptions{ nullptr }, input_node_names->data(), inputTensor.data(), inputTensor.size(), output_node_names.data(), 1);
	}
	catch (const Ort::Exception& exception)
	{
		const char* err_msg = exception.what();
		std::cout << "exception caught: " << err_msg << std::endl;
		// Print error
	}
	delete(input_tensor_values);
	if (outputTensor.size() > 0) {
		float* arr = outputTensor.front().GetTensorMutableData<float>();
		for (int i = 0; i < outputTensor.front().GetTensorTypeAndShapeInfo().GetElementCount(); i += 7) {
			Detected.push_back(detection(int(arr[i]), arr[i + 1] / 640 * original.width, arr[i + 2] / 640 * original.height, arr[i + 3] / 640 * original.width, arr[i + 4] / 640 * original.height, int(arr[i + 5]), arr[i + 6]));
		}

	}
}

void YOLOv7::DrawDetected(cv::Mat image) {
	for (int i = 0; i < Detected.size(); i++) {
		std::string text = LabelMap.classmap[Detected[i].Label].name +  std::to_string(std::round(Detected[i].class_prob*100.0)/100.0);
		for (int i = text.size()-1; i > 0; --i) {
			if (text[i] == '0')text.pop_back();
			else break;
		}
		cv::Size textsize = cv::getTextSize(text, 1, 1, 1, 0);
		cv::rectangle(image, cv::Point(Detected[i].x1, Detected[i].y1-2) , cv::Point(Detected[i].x1, Detected[i].y1-2) +cv::Point(textsize.width, -textsize.height), LabelMap.classmap[Detected[i].Label].color, cv::FILLED);
		cv::putText(image, text, cv::Point(Detected[i].x1, Detected[i].y1-2), 1, 1, cv::Scalar(255,255,255),1);
		cv::rectangle(image, cv::Point(Detected[i].x1, Detected[i].y1), cv::Point(Detected[i].x2, Detected[i].y2), LabelMap.classmap[Detected[i].Label].color, 2);
	}
};

