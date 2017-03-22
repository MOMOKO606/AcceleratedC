#include<iostream>

using namespace std;

template<class T>
T zero()
{
	return 123;
}

int main()
{
	double x = zero<double>();
	cout << x << endl;

	return 0;
}
