#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>


using namespace std;

void load_data(char* file_name,vector<float>& x_points,vector<float>& y_points)
{
    ifstream data_file(file_name);
    while(true)//nieskonczona petla
    {
        float x;
        float y;
        data_file>>x;
        data_file>>y;
        if(data_file.eof())
            break;
        x_points.push_back(x);
        y_points.push_back(y);
            
    }


}

void Min_max(vector<float>& x_points, float& min, float& max)
{   

    min=x_points[0];
    max=x_points[0];
     for (unsigned i=0;i<x_points.size();++i)
     {
        if(x_points[i]<min)
        min=x_points[i];
        if(x_points[i]>max)
        max=x_points[i];
      }



}

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

int main(int argc, char **argv){
 //cout<<setiosflags(ios::fixed)<<setprecision(1)<<endl;

   vector<float>x;
   vector<float>y;
   float min=0.0;
   float max=0.0;
   char* file_name;

   load_data(argv[1],x,y);
  // for (unsigned i=0;i<x.size();++i)
  // { //<x.size(), bo wypisujemy od 0,1,...
  // cout<<x[i]<<"\t"<<y[i]<<endl;
   
   //  }
     
       cout<<"wauuuu"<<L(10,x,y)<<endl;
       
       Min_max(x,min,max);
       
       float dx=(max-min)/100;
       for(float i=min;i<=max;i+=dx)
       {
         //   cout<<"L("<<i+dx<<"): "<<L(i,x,y)<<endl;
       cout<<i<<"\t"<<L(i,x,y)<<endl;
       }
       
       
       //podzielic na 100 odcinkow i dla kazdego z punbktow wypisujemy L(x)
      // cout<<"Min: "<<min<<" Max: "<<max<<endl;

 
   
   
   
}
