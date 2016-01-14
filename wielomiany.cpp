#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cmath>


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

float P(float x,vector<float>x_points,vector<float>y_points){
    float result=0.0;
    unsigned n=x_points.size();//sprawdzic dlugoisc x i y
    vector<float>p=y_points;
    for (unsigned  i=1;i<n;++i){
 	    for (unsigned j=0;j<n-i;++j){
            p.at(j)=((x-x_points.at(j+i))*p.at(j)-((x-x_points.at(j))*p.at(j+1)))/(x_points.at(j)-x_points.at(i+j));
        }
    result=p.at(0);
    }
    
    

    return result;
}
void Min_max(vector<float>& x_points, float& min, float& max,int& minr)
{   

    min=fabs(x_points[0]);

    max=x_points[0];

     for (unsigned i=0;i<x_points.size();++i)
     {
	
        if(fabs(x_points[i])<min){
        min=fabs(x_points[i]);
        minr=i;
	cout<<minr<<endl;
        }
        if(x_points[i]>max)
        max=x_points[i];
      }



}

void polynomial(vector<float> x,vector<float> y)
{
   float min_fabs=0.0;//min podawany do policzenia warunku na abd
   float max=0.0;
   int min=0;//prawdziwa wartosc min
   int N=x.size();
   string result;
   vector<float>c(y.size());
   cout<<"c.size()"<<c.size()<<endl;
   Min_max(x,min_fabs,max,min);

   for (int i=0;i<N;++i){

            c[i]=P(0,x,y); //znajdujemy wartosc w 0!
            //min zwraca numer indeksu
            Min_max(x,min_fabs,max,min);
            x.erase(x.begin()+min);
            y.erase(y.begin()+min); 

           for (unsigned j=0;j<y.size();++j)
              {

                  y.at(j)=(y.at(j)-c.at(i))/x.at(j);

              }
  
    //cout<<"c["<<i<<"]"<<c[i]<<endl;
    cout<<c[i]<<"*"<<"x**"<<i<<"+";

   }



}

int main(int argc, char **argv){
 cout<<setiosflags(ios::fixed)<<setprecision(3)<<endl;

   vector<float>x;
   vector<float>y;

   load_data(argv[1],x,y);
   cout<<x.size()<<endl;
   
   polynomial(x,y);
     
}
