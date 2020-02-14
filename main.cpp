#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
/*
���ֱ���ͼ��ķ�ʽ
1.���õ�ַ��������
2.���õ�ַ�����������������mat.stepָ����������֮��ļ����mat�ܹ��Զ����񵽡�
3.����mat.ptr<Vec3b>�ӿڣ����ص���ָ��
3.����mat.at<Vec3b>�ӿڣ����ص�������
*/
void PrintMs(const char *text = "")
{
	static long long last = 0;
	long long cur = getTickCount();
	if (*text == 0)
	{
		last = cur;
		return;
	}
	int ms = ((double)((cur - last) / getTickFrequency()))* 1000;
	printf("ʱ��=%dms",ms);
}
int main()
{
	Mat mat(3000,4000,CV_8UC3);
	int x = mat.cols;
	int y = mat.rows;
	int elemsize =x*y* mat.elemSize();
	PrintMs("");
	/*for (int i = 0; i < elemsize; i += mat.elemSize())
	{
		mat.data[i] = 0;
		mat.data[i + 1] = 255;
		mat.data[i + 2] = 21;
	}*/
#if 0
	for (int i = 0; i < mat.rows; i ++)
	{
		for (int j = 0; j < mat.cols; j++)
		{

			(&mat.data[i*mat.step])[j * 3] = 250;
			(&mat.data[i*mat.step])[j * 3+1] = 50;
			(&mat.data[i*mat.step])[j * 3+2] = 20;
		}

	}
#endif
#if 0
	for (int i = 0; i < mat.rows; i++)
	{
		for (int j = 0; j < mat.cols; j++)
		{
			Vec3b *va = mat.ptr<Vec3b>(i,j);
			va->val[0] = 123;
			va->val[1] = 231;
			va->val[2] = 250;
		}
	}
#endif
	for (int i = 0; i < mat.rows; i++)
	{
		for (int j = 0; j < mat.cols; j++)
		{
			Vec3b &va = mat.at<Vec3b>(i, j);
			va[0] = 1;
			va[1] = 213;
			va[2] = 31;
		}
	}
	PrintMs("dd");
	namedWindow("picture");
	imshow("picture", mat);
	waitKey(0);
	return 0;
}
