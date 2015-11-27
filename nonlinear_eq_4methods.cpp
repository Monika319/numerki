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

double newton(double x0)
{
double epsilon=0.0001;
double h=0.5;
double x=x0;
int i=0; 
double delta_y=abs(f(x0));
if (f(x0)==0) return x0;
while(delta_y>epsilon)
{   i++;
    h= f(x0)/df(x0);
	x=x-h;
	cout<<i<<"\t"<<x<<"\t";
    delta_y=abs(f(x));
    cout<<delta_y<<endl;
}
return x;
}

double sieczne(double x0, double x1)
{
double epsilon=0.00001;
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
   	cout<<"h: "<<h<<endl;
   	xn_prev=xn;
	xn=xn-h; //tutaj juz bedzie x_n+1
	cout<<i<<"\t"<<xn<<"\t";
    	delta_y=abs(f(xn));
    	cout<<delta_y<<endl;
	
	cout<<"xnprev: "<<xn_prev<<endl;
}




return xn;

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
