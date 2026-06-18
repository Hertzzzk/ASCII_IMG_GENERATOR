#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>

char Pixel_to_ASCII(float val)
{
	std::string ascii = " .'`^\",:;Il !i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
	int idx = (int)(val*(ascii.length()-1));
	//std::cout << " Index in ascii string : " << idx << "\n";
	return ascii.at(idx);
}

void Traverse_and_Process(int h,int w,cv::Mat& img,std::ofstream& file)
{
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			float pixel_val = img.at<uchar>(i,j);// 0[Black] to 255[White]
			pixel_val /= 255;
			file << Pixel_to_ASCII(pixel_val);
			//std::cout << " H : " << i << " W : " << j << " ";
		}
		file << "\n";
	}
	file.close();
}

int main()
{
	cv::Mat img;
	//std::ofstream outputFile("/home/hertzz/cpp/ASCII_IMG/output.txt");
	cv::Mat scaled_img;
	double scale = 0.2;
	std::cout << "Enter the  absolute location of the source image : " << "\n";
	std::string src ;
	std::cin >> src;
	img = cv::imread(src,cv::IMREAD_GRAYSCALE);
	std::cout << "Enter the scale : " << "\n";
	std::cin >> scale;
	std::cout << "Enter the output location of text file : " << "\n";
	std::string out ;
	std::cin >> out ;
	std::ofstream outputFile(out);
	if(img.empty())
	{
		std::cout << "img not found!!\n";
		return -1;
	}

	cv::resize(img,scaled_img, cv::Size(),scale,scale*0.5);
	
	int i_h = scaled_img.rows;
	int i_w = scaled_img.cols;

	std::cout << "Height : " << i_h << " Width : " << i_w << "\n";
	Traverse_and_Process(i_h,i_w,scaled_img,outputFile);
	return 0;
}




