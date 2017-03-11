#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

std::vector<std::string> SplitString(const std::string&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::string::size_type Weidth(const std::vector<std::string>&);
std::vector<std::string> verticat(const std::vector<std::string>&, const std::vector<std::string>&);
std::vector<std::string> horizcat(const std::vector<std::string>&, const std::vector<std::string>&);

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

string::size_type Width(const vector<string>& s)
{
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != s.size(); ++i)
		maxlen = max(maxlen, s[i].size());
	return maxlen;
}

vector<string> frame(const vector<string>& s)
{
	vector<string> ret;
	string::size_type w = Width(s);
	string border(w + 4, '*');

	ret.push_back(border);
	for (vector<string>::size_type i = 0; i != s.size(); ++i)
		ret.push_back("*" + s[i] + string(w - s[i].size()+2, ' ') + "*");
	ret.push_back(border);
	return ret;
}

vector<string> verticat(const vector<string>& top, const vector<string>& bottom)
{
	vector<string> ret = top;
	ret.insert(ret.end(), bottom.begin(), bottom.end());
	return ret;
}

vector<string> horizcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;
	string::size_type w = Width(left);
	vector<string>::size_type i = 0, j = 0;

	while (i != left.size() || j != right.size()) {
		string s;
		if (i != left.size())
			s = left[i++];
		s += string(w + 1 - s.size(), ' ');
		if (j != right.size())
			s += right[j++];
		ret.push_back(s);
	}
	return ret;
}

int main()
{
	string s;

	getline(cin, s);

	vector<string> v1 = SplitString(s);
	vector<string> v2 = frame(v1);
	vector<string> output1 = verticat(v1, v2);
	vector<string> output2 = horizcat(v1, v2);

	for (vector<string>::size_type i = 0; i != output1.size(); ++i)
		cout << output1[i] << endl;

	for (vector<string>::size_type i = 0; i != output2.size(); ++i)
		cout << output2[i] << endl;

	return 0;
}
