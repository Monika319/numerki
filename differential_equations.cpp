#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector <double> function(double t, vector<double> x)
{
    vector <double> lambda= {1,2};
    x[0]=-lambda[0]*x[0];
    for (unsigned i=1;i<=x.size()-1;++i)
    {
        x[i]=-lambda[i]*x[i]+lambda[i-1]*x[i-1];
    }
    x[x.size()]=lambda[lambda.size()-1]*x[x.size()-1];
    
    return x;

}
double f(double t,double x)
{
    int lambda=1;
    return -lambda*x;
}


double euler(double h, double xi,double ti)
{

    return xi+h*f(ti+h/2,xi+h/2*f(ti,xi));
}

vector <double> add_vector(vector <double> x, double c1, vector <double> y, double c2)
{
    vector <double> result;
    for(int i=0;i<=x.size();++i)
    {
        result.push_back(x[i]*c1+y[i]*c2);
     }
    
    return result;
}


vector <double> modified_euler(double h, vector <double> x,double ti)
{
      vector <double> mult=function(ti,x);
    for (unsigned i=0;i<=x.size();++i)
    {
      
        for (unsigned j=0;j<=mult.size();++j)
        {
            mult[j]=h/2*mult[j];
        }
        x[i]=x[i]+h*function(ti+h/2,add_vector(x[i],1.,mult[i],1.)); 
    }

    return x;
}





double runge_kutta(double h, double xi,double ti)
{
    double K1 = f(ti,xi);
    double K2 = f(ti+h/2,xi+h/2*K1);
    double K3 = f(ti+h/2,xi+h/2*K2);
    double K4 = f(ti+h,xi+h*K3);
    
    return xi+h/6*(K1+2*K2+2*K3+K4);

}

int main()
{
    double dt=0.1;
    //int N=1000;
   // int N_rk=1000;
    vector <double> N_vector={1000,0};
    for (double i=0;i<=3;i+=dt)
    {   
        N_vector=modified_euler(dt,N_vector,i);
       // cout<<"t"<<"\t"<<i<<"\t"<<"N"<<"\t"<<N<<"\t"<<"R_K"<<"\t"<<N_rk<<endl;
        //N=euler(dt,N,i);
        //N_rk=runge_kutta(dt,N_rk,i);
        for (unsigned i=0;i<=N_vector.size();++i)
    {
        cout<<N_vector[i];
    }

    }
    



}
