    #include <iostream>
    #include <iomanip>
    #include <vector>
    #include <fstream>
    #include <cmath>


using namespace std;



void load_data(char* file_name,vector<float>& x_points,vector<float>& y_points,vector<float>& y_prim)
{
    ifstream data_file(file_name);
        while(true)//nieskonczona petla
        {
            float x;
            float y,yp;
            data_file>>x;
            data_file>>y;
            data_file>>yp;
            if(data_file.eof())
                break;
            x_points.push_back(x);
            y_points.push_back(y);
            y_prim.push_back(yp);
            
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

float hermite(vector<float> x_points,vector<float> y,vector<float> y_prim,float x)
{
   int N2=y.size()*2;
   vector<float> f(N2);
   vector<float> f_prim(N2);
   vector<float> z(N2);
   int N=y.size();
   float result;
   
   

   for (unsigned i=0;i<N;++i)
   {	
       
      f[2*i]=y[i];
      f[2*i+1]=y[i];
      if((i % 2)==0){
          f_prim[2*i]=y_prim[i];
    		//f_prim[2*i+1]=y_prim[i];
      }
      else
      {
      }
      z[2*i]=x_points[i];
      z[2*i+1]=x_points[i];

      
  }
  f_prim.pop_back();
  result=y[0];

  for (int j=1;j<N2-1;++j)
  {
   cout<<f_prim[j]<<endl;
    	result+=y_prim[j-1]*(x-z[j])*(x-z[j-1]);//y_prim[j-i],bo mam przesuniety index
    }
    return result;
}



int main(int argc, char **argv){
   cout<<setiosflags(ios::fixed)<<setprecision(3)<<endl;

   vector<float>x;
   vector<float>y;
   vector<float>y_prim;

   load_data(argv[1],x,y,y_prim);
   cout<<x.size()<<endl;
   
   
   cout<< "H(5)"<<hermite(x,y,y_prim,5);
}
