#include <iostream>

using namespace std;

double AplusB(double a,double b)
{
  return a+b;
}

int main()
{
  double a,b;
  while(cin>>a>>b){
    double ret=AplusB(a,b);
    cout<<ret<<endl;
  }
  return 0;
}
