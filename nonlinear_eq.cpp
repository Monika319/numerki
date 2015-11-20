#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;



double f(double x)
{

return pow(x,3);
}

int sign(double x){
	if (f(x)>0) return 1;
	else if (f(x)<0) return -1;
	else return 0;



}

double bisection(double a, double b, double epsilon)
{
double c;
double delta_x=b-a;
cout<<"delta "<<endl;
if (sign(a)==0) return a;
else if(sign(b)==0) return b;
    while(delta_x>epsilon)
    {
       c=(a+b)/2.0;
   	 if(sign(a)*sign(c)<0)
    	{
   		 b=c;
   	 }
    else if(sign(c)*sign(b)<0)
	{
      		 a=c;
	 }
    delta_x=b-a;
    }
return c;

}

int main()
{
double result=bisection(-5,10,0.001);

cout<<result<<endl;



}
