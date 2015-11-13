#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

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

double boole(double a,double b, int n){
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
    double I_0=trapezoidal(a,b,n);
    double I_h=trapezoidal(a,(a+b)/2.0,n)+trapezoidal((a+b)/2.0,b,n);
if (abs(I_0-I_h)<epsilon){
cout<<(a+b)/2<<"\t"<<(b-a)/(double)n<<endl;
	return I_0;
}
else {
  cout<<(a+b)/2<<"\t"<<(b-a)/(double)n<<endl;
  return  adapt(epsilon,a,(a+b)/2.0,n)+adapt(epsilon,(a+b)/2.0,b,n);
  
}
}

double rand_in_range(double a,double b){

double x=(double)rand()/static_cast<double>(RAND_MAX);
return a+x*(b-a);
}

double Min(double data[100000])
{   

  double  min=data[0];
     for (unsigned i=0;i<sizeof(data);++i)
     {
        if(data[i]<min)
        min=data[i];
      }

return min;

}
double Max(double data[100000])
{   

  double  max=data[0];
     for (unsigned i=0;i<sizeof(data);++i)
     {
        if(data[i]>max)
        max=data[i];
      }
cout<< "max: "<<max<<endl;
return max;

}



double integrate_monte_carlo(double a, double b,double y_min,double y_max){
double integral;
double x=0.0;
double y=0.0;
int N=100000;
double x_number_in_rectangle=0.0;
double function=0.0;
double results [N];
int counter=0;
double y_length=y_max+abs(y_min);
for (int i=0;i<N;++i){
    x=rand_in_range(a,b);
    y=rand_in_range(y_min,y_max);
    double z=f(x);
   // results[i]=z;
  // cout<<results[i]<<endl;
  if (z>0 && y>0 && y<z){ //y wylosowany mniejszy od wartosci funkcji w tym punkcie
    counter++;
  }
else if(z<0 && y<0 && y>z){
    counter--; //dodajemy z przeciwnym znakiem
  }
    
}
  
    
    double S=(b-a)*y_length;
    cout<<"S "<<S<<endl;
    integral=(double)counter/(double)N *S;
return (double)counter/(double)N*(b-a)*(y_max-y_min);
}




int main()
{
    srand(time(NULL));//z ktorego miejsca ma zaczac losowac
    cout<<setiosflags(ios::fixed)<<setprecision(10)<<endl;
  //  cout<<-2*M_PI<<endl;
    double epsilon=0.000001;
    double a=0.0;
    double b=2*M_PI;
  //cout<<"adapt: "<<adapt(epsilon,a,b,2)<<endl;
  cout<<"trapezoidal: "<<trapezoidal(a,b,1000)<<endl;
  cout<<"monte "<<integrate_monte_carlo(a,b,-5,2)<<endl;
  
}
