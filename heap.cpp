#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>
#include <limits>
using namespace std;

int rand_in_range(int a,int b){
double x=(double)rand()/static_cast<double>(RAND_MAX);
return a+x*(b-a);

}

int find_min(vector <int> data)
{
    int min=data[0];
    int index=0;
    cout<<"size"<<data.size()<<endl;
    for (unsigned i=0; i<data.size();i++){
    {
        
        if (data[i]<min)
        {
           min=data[i];
           index=i;
        }
        
    }

}
    return index;

}

void print_heap(vector <int> data)
{
    int size=data.size();
    int height=log(size+1)/log(2);
    
   
   bool behave=false;
    for (int i=0;i<height;++i) // poziomy
    {   
       
       for (int z=i;z<=size;++z)
       {
       cout<<" ";
       }
       

       if (i%2==0) behave=true;
       else behave=false;
        
        for (int  j=pow(2,i)-1;j<pow(2,i+1)-1;++j)
        {   
        cout<<data.at(j)<<" ";
        if (!behave){
        
      //  cout<<data.at(j)<<"\t";
        }
       
       // else{
      //  cout<<"\t"<<data.at(j)<<"\t";
      //  }
        ///cout<<data.at(left)<<"\t";
        ///cout<<data.at(right)<<"\n";
        
        }
    cout<<endl;
}

}


void move_d(vector<int>& A, int start, int end)
{

    int current = start;
    
    while(2*current+1<=end)
    {
    int left=2*current+1;// lewe dziecko
    int right=2*current+2; // prawe dziecko
    
    if (A[current]>A[right]) {
    cout<<"right"<<endl;
    swap(A[current],A[right]);
    //int tmp=current;
   // A[current]=A[right];
   // A[right]=A[tmp];
    current=right;    
    }
   else if (A[current]>A[left]){
       cout<<"left"<<endl;
    swap(A[current],A[left]);
    current=left;
    //int tmp=A[current];
   // A[current]=A[left];
   // A[left]=tmp;
    }
    
    else break;

}
print_heap(A);


}


void move_down(vector<int>& A, int start, int end)
{

    int current = start;
    
    while(2*current+1<=end)
    {
   
    int left=2*current+1;// lewe dziecko
    int right=2*current+2; // prawe dziecko
    int flip=current; //index elementu, z ktorym bedziemy zamieniac sie miejscami
    
    if (A[current]<A[left])
    flip=left;
    if( (right<=end) && A[right]> A[flip])
    flip=right;
    
    if (current!=flip)
    {
        swap(A[current], A[flip]);
        current=flip;
    
    }
   else break;
   
   

}
print_heap(A);


}

void print_vector(vector <int> data)
{
  
    for (unsigned i=0;i<data.size();++i)
        cout<<data.at(i)<<" ";
    cout<<endl;
}




//biblioteka time.h mozna policzyc czasy wykonywania programu
int main()
{
    srand(time(NULL));
    int N=15;
    vector <int> data;
    for(int i=0;i<N;++i){
        data.push_back(rand_in_range(0,N));
    }
   
 
  
   
    print_heap(data);
    
    
    cout<<"Po sortowaniu: "<<endl;
    
    
    for (int i=(N-2)/2;i>=0;i--){
    move_down(data,i,N-1);
    }
    
    for (int i=0; i<N; ++i)
    {
        swap(data[0],data[N-i]);
        move_down(data,0, N-1-i);
    }
    
  }



