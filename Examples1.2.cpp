#include<iostream>
#include <string>

using std::cout;using std::cin;
using std::string;using std::endl;

int main()
{
  cout<<"Please enter your name:";

  string name;
  cin>>name;

  string greeting="Hello, "+name+" !";
  string line2(greeting.size()+2,' ');
  line2="*"+line2+"*";
  greeting="* "+greeting+" *";
  string line1(line2.size(),'*');

  cout<<line1<<endl;
  cout<<line2<<endl;
  cout<<greeting<<endl;
  cout<<line2<<endl;
  cout<<line1<<endl;

  return 0;
}
