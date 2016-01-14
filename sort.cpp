#include <iostream>
#include <vector>
#include <time.h>

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

void print_vector(vector <int> data)
{
    for (unsigned i=0;i<data.size();++i)
        cout<<data.at(i)<<" ";
    cout<<endl;
}

//dziala tak samo szybko niezaleznie od tego, czy jest posortowany, czy nie
vector<int> selection_sort(vector <int> data)
{
      //2 petle for, bo musimy porownywac elementy  
    unsigned n=data.size();
    for (unsigned i=0;i<n;++i)
    {
    print_vector(data);
    int min=i;
    for (unsigned j=i;j<n;j++) //zaczynamy od i-tego indeksu!!!
    {
         if (data[j]<data[min])
        {
           min=j;
        }
    
    }
     swap(data[min],data[i]);
    }
    

    return data;
}


vector<int> selection_sort1(vector <int> data)
{
      //2 petle for, bo musimy porownywac elementy  
    unsigned n=data.size();
    for (unsigned i=0;i<n;++i)
    {
    print_vector(data);
    
    for (unsigned j=i;j<n;j++) //zaczynamy od i-tego indeksu!!!
    {
         if (data[j]<data[i])
        {
          // min=j;
        	swap(data[i],data[j]);
        }
    
    }
     //swap(data[min],data[i]);
    }
    

    return data;
}



//sprawdzamy z lewej strony
vector<int> insertion_sort(vector <int> data)
{
        
    unsigned n=data.size();
    for (unsigned i=1;i<n;++i)//zaczynamy od 1, bo sam ze soba sie nie porownuje
    {
    
    int c=i;//wedrujacy
    
    for (int j=i-1;j>-1;j--) //zaczynamy od i-tego indeksu!!!
    {
  //  print_vector(data);
    
         if (data[j]>data[c])
        {
         swap(data[j],data[c]);
         c=j; 
        } 
        else break; //juz konczymy
    
    }
     
    }
    

    return data;
}



vector<int> bubble_sort(vector <int> data)
{
        
    unsigned n=data.size();
    bool is_changed;
    for (unsigned i=0;i<n-1;++i)
    {
    is_changed=false;
   // print_vector(data);
    
    for (unsigned j=0;j<n-i-1;j++) //zaczynamy od i-tego indeksu!!!
    {
         if (data[j+1]<data[j])
        {
         swap(data[j],data[j+1]);
         is_changed=true;
        }
    
    }
    if(!is_changed) break;
     
    }
    

    return data;
}


vector<int> coctail_sort(vector <int> data)
{
        
    unsigned n=data.size();
    bool is_changed=true;
    
   
    for (unsigned i=0;i<n/2;++i)
    {
    is_changed=false;
   // print_vector(data);
    for(unsigned j=i;j<n-i-1;++j)
    {
    if (data[j]>data[j+1])
        {
         swap(data[j],data[j+1]);
         is_changed=true;
        }
       
        
    for (unsigned j=n-i-2;j>i;j--) 
    {
         if (data[j]<data[j-1])
        {
         swap(data[j],data[j-1]);
         is_changed=true;
        }
    }
  
    if(!is_changed) break;
     
     
     
     
    }
}    

    return data;
}


void quick_sort(vector <int> &data,int left, int right)
{
        
    
    int i=left;
    int j=right;
   
   int pivot=data[(i+j)/2];
   cout<<"pivot: "<<(i+j)/2<<endl;
   cout<<"left: "<<left<<endl;
   cout<<"right: "<<right<<endl;
    while( i <= j )
    {

        while(data[i]<pivot)
        {
            i++;
        }
        while (data[j]>pivot)
        {
            j--;
        }
        if(i<=j)
        {
            if (i!=j)
            {
                swap(data.at(i),data.at(j));
            }
            i++;
            j--; 
        }
   }
      
   //sprawdzic czy dlugosc lewej czesci juz nie jest 0 lub 1
   if(left<j)
   quick_sort(data,left,j);
      if(i<right)
   quick_sort(data,i,right);
    
}








//biblioteka time.h mozna policzyc czasy wykonywania programu
int main()
{
    srand(time(NULL));
    int N=7;
    vector <int> data;
    for(int i=0;i<N;++i){
        data.push_back(rand_in_range(0,N));
    }
    data = {0, 1, 1, 3, 1, 5, 2};
    cout<<"rand vector"<<endl; 
    print_vector(data);
    //cout<<"min "<<find_min(data)<<endl;
    //cout<<"selection"<<endl;
    //print_vector(selection_sort(data));
    //cout<<"insertion"<<endl;
   // print_vector(insertion_sort(data));
  //  cout<<"bubble"<<endl;
   cout<<endl;
	print_vector(selection_sort1(data));


	 cout<<endl;
	 cout<<"real selection"<<endl;
	print_vector(selection_sort(data));
   //quick_sort(data,0,6);
           //print_vector(data);
   // print_vector(bubble_sort(data));
   //  cout<<"coctail: "<<endl;
   //  bubble_sort(data);
    // print_vector(coctail_sort(data));
}




