#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;


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
    double delta_x=(double)(xmax-xmin)/(double)n;
     double x_tmp=xmin;
    for (unsigned i=0;i<n;++i)
    {
    double x_tmp_e=x_tmp+delta_x;
    for (int j=0;j<dane.size();++j){
        if (x_tmp<dane.at(j) && dane.at(j)<x_tmp_e)
        {
        result.at(i)++;
        }
        }
        x_tmp=x_tmp_e;
 
    }   
  
    return result;
}

int main()
{
    vector <int> dane;
    for(int i=0;i<100000;++i){
        dane.push_back(congruential());
    }
    int xmin=0;
    int xmax=1024;
    int n=1024;
    
    vector<unsigned int> res=histo(dane,xmin,xmax,n);
    
    for (int i=0;i<res.size();++i)
    {
        cout<<res.at(i)<<endl;
    
    }

}
