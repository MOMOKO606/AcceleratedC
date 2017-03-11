#include<iostream>
#include<string>
#include<vector>

std::vector<std::string> SplitString(const std::string&);

using namespace std;

vector<string> SplitString(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	//Outter loop：遍历字符串s
	while (i!= s.size()) {

		//Inner loop1：i表示单词开始的index
		while (i != s.size() && isspace(s[i]))
			i++;

		//Inner loop2:j表示单词结束后的第一个空格的位置
		string_size j = i;
		while (j != s.size() && !isspace(s[j]))
			j++;

		if (i != j) {
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}

int main()
{
	string s;

	getline(cin, s);

	vector<string> output = SplitString(s);

	for (vector<string>::size_type i = 0; i != output.size(); ++i)
		cout << output[i] << endl;

	return 0;
}
