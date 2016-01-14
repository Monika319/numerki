#include <iostream>
#include <iomanip>
#include <vector>



using namespace std;

float L(float x,vector<float>x_points,vector<float>y_points){
    float result=0.0;
    unsigned n=x_points.size();//sprawdzic dlugoisc x i y
    
    for (unsigned  i=0;i<n;++i){
    float s=y_points.at(i);
        for (unsigned j=0;j<n;++j){
            if(i==j){
            continue;
            }
            s=s*(x-x_points.at(j))/(x_points.at(i)-x_points.at(j));
        }
    result=result+s;
    }
    
    

    return result;
}

int main(){
 cout<<setiosflags(ios::fixed)<<setprecision(20)<<endl;
   vector<float>y={0.0,-0.5,5.0,8.0,7.0,5.0,3.0};//moze miec dowolna dlugosc
   vector<float>x={5,8,11,14,17,21,23};
   
  cout<<L(10,x,y)<<endl;
   
   //for (unsigned i=0;i<x.size();++i) //<x.size(), bo wypisujemy od 0,1,...
  // cout<<x[i]<<endl;
   
   
   
}
