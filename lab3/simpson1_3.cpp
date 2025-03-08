//Write a program to calculate integration using Simpson’s 1/3 rule
#include<iostream>
using namespace std;
double f(double x){
 return 3*x-2;
}
int main(){
 double xn,x0;
	
 cout<<"enter upper limit:"<<endl;
 cin>>xn;
 cout<<"enter lower limit:"<<endl;
 cin>>x0;
 
 double h=(xn-x0)/2.0;
 double x1=x0+h;
 double result=(f(x0)+4*f(x1)+f(xn))*(h/3);
 
	
 cout<<"the result is "<<result<<endl;
	
}
