#include <fstream>
#include<iostream>

using namespace std;

int main()
{
	//输入文件名
	ifstream inputfile("test.txt");
	//检查文件是否打开
	if (!inputfile.is_open())
		cout << "Error opening file";

	// 读取文件长度n
	int i=0;
	double arr[100];
	while (!inputfile.eof()) {
		inputfile >> arr[i];
		++i;
	}
	//关闭文件，清除流状态标志
	inputfile.close();

	//测试
	for (int j = 0; j != i-1; j++)
		cout << arr[j] << endl;

	return 0;
}
