#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

std::vector<std::string> Split(const std::string&);
bool space(char);
bool not_space(char);

using namespace std;

bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

vector<string> Split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;
	iter i = str.begin();

	while (i != str.end()) {
		//找到单词的起始index
		i = find_if(i, str.end(), not_space);
		//找到单词的结尾index
		iter j = find_if(i, str.end(), space);
		//复制[i,j)中的字符
		if (i != str.end())
			ret.push_back(string(i,j));
		i = j;
	}
	return ret;
}

int main()
{
	string s;

	getline(cin, s);

	vector<string> output = Split(s);

	for (vector<string>::size_type i = 0; i != output.size(); ++i)
		cout << output[i] << endl;

	return 0;
}
