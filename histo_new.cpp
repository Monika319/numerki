#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;

double rand_in_range(double a,double b){

double x=(double)rand()/static_cast<double>(RAND_MAX);
return a+x*(b-a);
}// sa wikesze skoki na plocie, bo losuje z wiekszego zakresu, duzo wiekszego tak naprawde


double congruential()
{
    int a=33;
    int c=1;
    int m=1024;
    static int x=0;
    x=(a*x+c) % m;
    return x;
}

vector<unsigned int> histo(vector<int> dane, int xmin, int xmax, unsigned int n)
{
    //wypelniamy wektor zerami
    vector<unsigned int> result(n,0);
    double delta_x=(double)(xmax-xmin)/(double)n; //szerokosc binu
    int n_data=dane.size();
    for (int i=0;i<n_data;++i)
   {
    if(dane[i]>xmin && dane[i]<xmax)
    {
    int bin_nr=(int)((dane[i]-xmin)/delta_x);
    result[bin_nr]+=1;
    }
    }

  
    return result;
}






int main()
{
    vector <int> dane;
    for(int i=0;i<100000;++i){
        dane.push_back(rand_in_range(33,1024));
    }
    int xmin=0;
    int xmax=1024;
    int n=1024;
    
    vector<unsigned int> res=histo(dane,xmin,xmax,n);
    double dx=(xmax-xmin)/n;
    for (int i=0;i<res.size();++i)
    {
       cout<<(i+0.5)*dx+xmin<<" "<<res[i]<<endl;

    
    }
   
}
