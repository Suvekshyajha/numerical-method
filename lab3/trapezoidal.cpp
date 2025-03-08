//integration using simple trapezoidal
#include<iostream>
using namespace std;
double f(double x){
 return 3*x-2;
}
int main(){
 double a,b,n;
 cout<<"enter upper limit:"<<endl;
 cin>>b;
 cout<<"enter lower limit:"<<endl;
 cin>>a;
 cout<<"enter the number of partition:"<<endl;
 cin>>n;
 double h=(b-a)/n;
 double result=0;
 result=f(b)+f(a);
 cout<<"the result is "<<result*h*0.5<<endl;
	
}
