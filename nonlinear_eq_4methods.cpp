#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;



double f(double x)
{

return sin(x+cos(x))-cos(x+sin(x));
}

double df(double x)
{
return -cos(x+cos(x))* (-1+sin(x))-(-1-cos(x))* sin(x+sin(x));

}
int sign(double x){
  
	if (f(x)>0) return 1;
	else if (f(x)<0) return -1;
	else return 0;



}

double newton(double x0)
{
double epsilon=pow(10,-5);
double h=0.5;
double x=x0;
int i=0; 
double delta_y=abs(f(x0));
if (f(x0)==0) return x0;
while(delta_y>epsilon)
{   i++;
    h= f(x)/df(x);
	x=x-h;
	
    delta_y=abs(f(x));
}
return x;
}

double sieczne(double x0, double x1)
{
double epsilon=pow(10,-5);
double h;
double xn=x1;
double xn_prev=x0;
int i=0; 
double delta_y=abs(f(xn));
if (f(x0)==0) return x0;
else if(f(x1)==0) return x1;
while(delta_y>epsilon)
{   
	i++;
   	h= f(xn)*(xn-xn_prev)/(f(xn)-f(xn_prev));
   
   	xn_prev=xn;
	xn=xn-h; //tutaj juz bedzie x_n+1

    	delta_y=abs(f(xn));
    
	
}




return xn;

}

double bisection(double a, double b, double epsilon)
{
double c;
double delta_x=b-a;

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



double falsi(double a, double b, double epsilon)
{
double c;
double delta_y=abs(f(b));


if (sign(a)==0) return a;
else if(sign(b)==0) return b;
    while(delta_y>epsilon)
    {
       c=b-f(b)*(b-a)/(f(b)-f(a));
	
   	 if(sign(a)*sign(c)<0)
    	{
   		 b=c;
   	 }
    else if(sign(c)*sign(b)<0)
	{
      		 a=c;
	 }
    delta_y=abs(f(c));

    }
return c;

}

int main()
{
double result_bisection=bisection(-5,5,pow(10,-5));
double result_newton=newton(1);
double result_falsi=falsi(-5,5,pow(10,-5));
double result_sieczne=sieczne(-5,5);

cout<<"bisection: "<<result_bisection<<endl;
cout<<"newton: "<<result_newton<<endl;
cout<<"falsi: "<<result_falsi<<endl;
cout<<"sieczne: "<<result_sieczne<<endl;

//newton 5,sieczne 8, falsi 16, bisekcja 43

}
