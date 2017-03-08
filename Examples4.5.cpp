#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

//声明
//声明结构体
struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double>homework;
};
//声明函数
bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
double median(std::vector<double>);

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::domain_error;
using std::streamsize;
using std::string;
using std::max;
using std::vector;
using std::istream;

//sort子函数
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

//输入函数，读取家庭作业
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		//清除原先的内容
		hw.clear();
		//读家庭作业成绩
		double x;
		while (in >> x)
			hw.push_back(x);
		//清除流以使输入动作对下一个学生有效
		in.clear();
	}
	return in;
}

//输入函数，读取学生姓名与期中、期末和家庭作业成绩
istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

//计算学生最终成绩
double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final, double homework)
{
	return 0.2*midterm + 0.4*final + 0.4*homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("studeng has done no homework");
	return grade(midterm, final, median(hw));
}

//计算一个vector<double>类型的对象中值
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0; //最长姓名的长度
								  //读入学生记录
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	//按字母排序学生记录
	sort(students.begin(), students.end(), compare);

	//输出姓名和成绩
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}
