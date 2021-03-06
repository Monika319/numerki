#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x){
    return x*sin(x);
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
	    xs=(x+b)/2.0;// bierzemy b zamiast x+dx jako koniec przedzialu
	    d=b-x;//zmniejsza sie szerokosc przedzialu, jesli wychodzimy poza b
	    }
	    result+=d*f(xs);
	    x+=dx;
    }

   return result;

}
double trapezoidal(double a, double b, int n){
    double h=(b-a)/(double)n;
    double s=0.5*f(a)+0.5*f(b); // na bocznych granicach wchodza jako 0,5, dlatego liczymy tylko 1 raz  na poczatku!
    for (int i=1;i<n;++i){
      s+=f(a+h*i);
    }


    return h*s;


}

double simpson(float a,float b, int n){
    float h=(b-a)/(float)n;
  //  cout<<h<<endl;
    double result=0.0;
float poczatek=a;
float koniec=a;
    for (int i=0;i<n;++i){
	poczatek=a+h*i;
	koniec=a+h*(i+1);
        result+=h/6*(function(poczatek)+function(koniec)+4*function((poczatek+koniec)/2));
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

double adapt(double epsilon,double a, double b, int n ){ //epsilon-accuracy, n-initial number of steps
    double I_0=trapezoid(a,b,n);
    double I_h=ptrapezoid(a,(a+b)/2.0,n)+trapezoid((a+b)/2.0,b,n);
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
  cout<<"adapt: "<<adapt(epsilon,a,b,2)<<endl;
  cout<<"trapezoidal: "<<trapezoidal(a,b,10000)<<endl;

}
