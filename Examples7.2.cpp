#include<map>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	map<string, int> counters;

	//s为键值(此处为string)，counters值为键值s出现的次数。
	while (cin >> s)
		++counters[s];

	//输出结果
	for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it)
		cout << it -> first << "\t" << it -> second << endl;
	return 0;
}
