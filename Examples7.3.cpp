#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

vector<string> SplitString(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	//Outter loop：遍历字符串s
	while (i != s.size()) {

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

map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = SplitString)
{
	string line;
	int line_number = 0;

	map<string, vector<int> >  ret;

	//按行读入句子
	while (getline(in, line)) {
		//标注句子号
		++line_number;
		//将读入的句子分割成单词
		vector<string> words = find_words(line);
		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
			ret[*it].push_back(line_number);
	}
	return ret;
}

int main()
{
	//调用xref函数，生成统计单词来自句子编号的hash table
	map<string, vector<int> > ret = xref(cin);
	//输出结果
	for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
		cout << it->first << " occurs on line(s): ";

		//进入table的second（int vector）部分
		vector<int>::const_iterator line_it = it->second.begin();
		//输出来自的句子号
		while (line_it != it->second.end()) {
			cout << *line_it << ";";
			++line_it;
		}
		cout << endl;
	}
	return 0;
}
