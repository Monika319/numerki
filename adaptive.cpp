#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x){
    return x*sin(x);
}


double trapezoidal(double a, double b, int n){
    double h=(b-a)/(double)n;
    double s=0.5*f(a)+0.5*f(b); // na bocznych granicach wchodza jako 0,5, dlatego liczymy tylko 1 raz  na poczatku!
    for (int i=1;i<n;++i){
      s+=f(a+h*i);
    }


    return h*s;


}


double adapt(double epsilon,double a, double b, int n ){ //epsilon-accuracy, n-initial number of steps
    double I_0=trapezoidal(a,b,n);

    n*=2;// doubled number of steps
    double h_i=(b-a)/n;
    double I=0.5*I_0;
    double res=0.0;
  //  h_i=h_i*0.5;
    for (int j=1;j<n-1;j+=2){
     res+=f(a+j*h_i);
    }
    I+=h_i*res;
    cout<<"I: "<<I<<endl;
    double error=(I-I_0);
    cout<<"error: "<<error<<endl;
    if(abs(error)>epsilon){
   
      adapt(epsilon,a,b,n);
    }
else ;
return I;

//     double I_h=ptrapezoid(a,(a+b)/2.0,n)+trapezoid((a+b)/2.0,b,n);
// if (abs(I_0-I_h)<epsilon){
// cout<<(a+b)/2<<"\t"<<(b-a)/(double)n<<endl;
// 	return I_0;
// }
// else {
//   cout<<(a+b)/2<<"\t"<<(b-a)/(double)n<<endl;
//   return  adapt(epsilon,a,(a+b)/2.0,n)+adapt(epsilon,(a+b)/2.0,b,n);
  
// }
}

int main()
{
    cout<<setiosflags(ios::fixed)<<setprecision(10)<<endl;
    cout<<-2*M_PI<<endl;
    double epsilon=0.001;
    double a=0.0;
    double b=2*M_PI;
  cout<<"adapt: "<<adapt(epsilon,a,b,2)<<endl;
  cout<<"trapezoidal: "<<trapezoidal(a,b,10000)<<endl;

}
