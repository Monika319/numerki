#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x){
    return sin(x);
}

double prostokaty(double a,double b, int n){
    double dx=(b-a)/(double)n;
    double d=dx;
    double result=0.0;
    double x=a;
    double xs=0.0;;
    while(x<b){
        if(x+dx<b)
	    xs=(x+x+dx)/2.0;
	    else	{
	    xs=(x+b)/2.0;
	    d=b-x;//zmniejsza sie szerokosc przedzialu, jesli wychodzimy poza b
	    }
	    result+=d*f(xs);
	    x+=dx;
    }

   return result;

}

double calka(double a,double b, int n){
    double h=(b-a)/(double)n;
  //  cout<<h<<endl;
    double result=0.0;
    double poczatek=a;
    double koniec=a;
    for (int i=0;i<n;++i){
	    poczatek=a+h*i;
	    koniec=a+h*(i+1);
	    if (koniec>b){
		    break;
	}
        result+=h/90*(7*f(poczatek)+7*f(koniec)+12*f((poczatek+koniec)/2)+32*f((3*poczatek+koniec)/4))+32*f((poczatek+3*koniec)/4);
    }

   return result;

}

double adapt(double epsilon,double a, double b, int n ){
    double I_0=prostokaty(a,b,n);
    double I_h=prostokaty(a,(a+b)/2.0,n)+prostokaty((a+b)/2.0,b,n);
if (abs(I_0-I_h)<epsilon){
cout<<(a+b)/2<<"\t"<<(b-a)/(double)n<<endl;
	return I_0;
}
else {
  cout<<(a+b)/2<<"\t"<<(b-a)/(double)n<<endl;
  return  adapt(epsilon,a,(a+b)/2.0,n)+adapt(epsilon,(a+b)/2.0,b,n);
  
}
}

int main()
{
    cout<<setiosflags(ios::fixed)<<setprecision(10)<<endl;
    cout<<-2*M_PI<<endl;
    double epsilon=0.000001;
    double a=0.0;
    double b=2*M_PI;
  cout<<adapt(epsilon,a,b,2);

}
