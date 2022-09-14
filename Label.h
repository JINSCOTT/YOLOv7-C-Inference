#pragma once
/// COCO labels as in YOLOV7, with name and colors
#include <iostream>
#include <opencv2/core.hpp>
class LabelAndColor
{
public:
	LabelAndColor(std::string Name, cv::Scalar Color) {
		name = Name;
		color = Color;
	};
	std::string name;
	cv::Scalar color;

};

class COCOLabels {
public:
	std::vector<LabelAndColor> classmap{
		LabelAndColor("PERSON",cv::Scalar(0,0,0)) ,				//0
		LabelAndColor("BICYCLE",cv::Scalar(16,0,0)) ,			//1
		LabelAndColor("CAR",cv::Scalar(32,0,0)) ,				//2
		LabelAndColor("MOTORBIKE",cv::Scalar(48,0,0)) ,			//3
		LabelAndColor("AEROPLANE",cv::Scalar(64,0,0)) ,			//4
		LabelAndColor("BUS",cv::Scalar(80,0,0)) ,				//5
		LabelAndColor("TRAIN",cv::Scalar(96,0,0)) ,				//6
		LabelAndColor("BOAT",cv::Scalar(112,0,0)) ,				//7
		LabelAndColor("TRUCK",cv::Scalar(128,0,0)) ,			//8
		LabelAndColor("TRAFFIC_LIGHT",cv::Scalar(144,0,0)) ,	//9
		LabelAndColor("FIRE_HYDRANT",cv::Scalar(160,0,0)) ,		//10
		LabelAndColor("STOP_SIGN",cv::Scalar(176,0,0)) ,		//11
		LabelAndColor("PARKING_METER",cv::Scalar(192,0,0)) ,	//12
		LabelAndColor("BENCH",cv::Scalar(208,0,0)) ,			//13
		LabelAndColor("BIRD",cv::Scalar(224,0,0)) ,				//14
		LabelAndColor("CAT",cv::Scalar(240,0,0)) ,				//15
		LabelAndColor("DOG",cv::Scalar(255,0,0)) ,				//16
		LabelAndColor("HORSE",cv::Scalar(0,15,0)) ,				//17
		LabelAndColor("SHEEP",cv::Scalar(0,30,0)) ,				//18
		LabelAndColor("COW",cv::Scalar(0,45,0)) ,				//19
		LabelAndColor("ELEPHANT",cv::Scalar(0,60,0)) ,			//20
		LabelAndColor("BEAR",cv::Scalar(0,75,0)) ,				//21
		LabelAndColor("ZEBRA",cv::Scalar(0,90,0)) ,				//22
		LabelAndColor("GIRAFFE",cv::Scalar(0,105,0)) ,			//23
		LabelAndColor("BACKPACK",cv::Scalar(0,120,0)) ,			//24
		LabelAndColor("UMBRELLA",cv::Scalar(0,135,0)) ,			//25
		LabelAndColor("HANDBAG",cv::Scalar(0,150,0)) ,			//26
		LabelAndColor("TIE", cv::Scalar(0, 165, 0)),			//27
		LabelAndColor("SUITCASE", cv::Scalar(0, 180, 0)),		//28
		LabelAndColor("FRISBEE",cv::Scalar(0,195,0)) ,			//29
		LabelAndColor("SKIS",cv::Scalar(0,210,0)) ,				//30
		LabelAndColor("SNOWBOARD",cv::Scalar(0,225,0)) ,		//31
		LabelAndColor("SPORTS_BALL",cv::Scalar(0,240,0)) ,		//32
		LabelAndColor("KITE",cv::Scalar(0,255,0)) ,				//33
		LabelAndColor("BASEBALL_BAT",cv::Scalar(0,0,15)) ,		//34
		LabelAndColor("BASEBALL_GLOVE",cv::Scalar(0,0,30)) ,	//35
		LabelAndColor("SKATEBOARD",cv::Scalar(0,0,45)) ,		//36
		LabelAndColor("SURFBOARD",cv::Scalar(0,0,60)) ,			//37
		LabelAndColor("TENNIS_RACKET",cv::Scalar(0,0,75)) ,		//38
		LabelAndColor("BOTTLE",cv::Scalar(0,0,90)) ,			//39
		LabelAndColor("WINE_GLASS",cv::Scalar(0,0,105)) ,		//40
		LabelAndColor("CUP",cv::Scalar(0,0,120)) ,				//41
		LabelAndColor("FORK",cv::Scalar(0,0,135)) ,				//42
		LabelAndColor("KNIFE",cv::Scalar(0,0,150)) ,			//43
		LabelAndColor("SPOON",cv::Scalar(0,0,165)) ,			//44
		LabelAndColor("BOWL",cv::Scalar(0,0,180)) ,				//45
		LabelAndColor("BANANA",cv::Scalar(0,0,195)) ,			//46
		LabelAndColor("APPLE",cv::Scalar(0,0,210)) ,			//47
		LabelAndColor("SANDWICH",cv::Scalar(0,0,225)) ,			//48
		LabelAndColor("ORANGE",cv::Scalar(0,0,240)) ,			//49
		LabelAndColor("BROCCOLI",cv::Scalar(0,0,155)) ,			//50
		LabelAndColor("CARROT",cv::Scalar(10,10,10)) ,			//51
		LabelAndColor("HOT_DOG",cv::Scalar(20,20,20)) ,			//52
		LabelAndColor("PIZZA",cv::Scalar(30,30,30)) ,			//53
		LabelAndColor("DONUT",cv::Scalar(40,40,40)) ,			//54
		LabelAndColor("CAKE",cv::Scalar(50,50,50)) ,			//55
		LabelAndColor("CHAIR",cv::Scalar(60,60,60)) ,			//56
		LabelAndColor("SOFA",cv::Scalar(70,70,70)) ,			//57
		LabelAndColor("POTTEDPLANT",cv::Scalar(80,80,80)) ,		//58
		LabelAndColor("BED",cv::Scalar(90,90,90)) ,				//59
		LabelAndColor("DININGTABLE",cv::Scalar(100,100,100)) ,	//60
		LabelAndColor("TOILET",cv::Scalar(110,110,110)) ,		//61
		LabelAndColor("TVMONITOR",cv::Scalar(120,120,120)) ,	//62
		LabelAndColor("LAPTOP",cv::Scalar(130,130,130)) ,		//63
		LabelAndColor("MOUSE",cv::Scalar(140,140,140)) ,		//64
		LabelAndColor("REMOTE",cv::Scalar(150,150,150)) ,		//65
		LabelAndColor("KEYBOARD",cv::Scalar(160,160,160)) ,		//66
		LabelAndColor("CELL_PHONE",cv::Scalar(170,170,170)) ,	//67
		LabelAndColor("MICROWAVE",cv::Scalar(180,180,180)) ,	//68
		LabelAndColor("OVEN",cv::Scalar(190,190,190)),			//69
		LabelAndColor("TOASTER",cv::Scalar(200,200,200)),		//70
		LabelAndColor("SINK",cv::Scalar(210,210,210)) ,			//71
		LabelAndColor("REFRIGERATOR",cv::Scalar(220,220,220)) ,	//72
		LabelAndColor("BOOK",cv::Scalar(230,230,230)) ,			//73
		LabelAndColor("CLOCK",cv::Scalar(240,240,240)) ,		//74
		LabelAndColor("VASE",cv::Scalar(250,250,250)) ,			//75
		LabelAndColor("SCISSORS",cv::Scalar(255,255,255)) ,		//76
		LabelAndColor("TEDDY_BEAR",cv::Scalar(127,84,84)) ,		//77
		LabelAndColor("HAIR_DRIER ",cv::Scalar(127,168,168)) ,	//78
		LabelAndColor("TOOTHBRUSH",cv::Scalar(127,256,256))		//79
	};
};	
