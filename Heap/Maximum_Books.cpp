#include<bits/stdc++.h>
using namespace std;


void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

class MinHeap{ 
    int *arr;
    int capacity;
    int count;
    public:
      MinHeap(int cap)
      {
          capacity=cap;
          count=0;
          arr = new int[cap];
      }
      int parent(int i){return (i-1)/2;}
      int left(int i){return 2*i+1;}
      int right(int i){return 2*i+2;}
      void insert(int key)
      {
         
          if(count==capacity)
           return;

          count++;
          int i = count-1;
          arr[i]=key;
          while(i!=0 && arr[parent(i)]>arr[i])
           { 
              // cout<<arr[parent(i)]<<" "<<arr[i]<<"  ";
               swap(&arr[parent(i)],&arr[i]);
               //cout<<arr[parent(i)]<<" "<<arr[i]<<endl;
               i=parent(i);
           }
      }

      void minHeapify(int i);
      int extractMin();
   

    

};


int MinHeap::extractMin()
{
    if(count==1)
     {
         count--;
         return arr[0];
     }

     int temp = arr[0];
     arr[0] = arr[count-1];
     count--;
     minHeapify(0);
     return temp;
     
}

void MinHeap::minHeapify(int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if(l<count && arr[smallest]>arr[l])
     smallest = l;
    if(r<count && arr[smallest]>arr[r])
     smallest = r;
   // cout<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<endl;
    if(smallest!=i)
    {
        //cout<<arr[smallest]<<" "<<arr[i]<<endl;
        swap(&arr[i],&arr[smallest]);
       // cout<<arr[smallest]<<" "<<arr[i]<<endl;
        minHeapify(smallest);
    }  
}



int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n,k;
         cin>>n>>k;
         MinHeap m(n);
         for(int i=0;i<n;i++)
         {
             int a;
             cin>>a;
             m.insert(a);
         }

         int count=0;
         int sum=0;
         while(sum<k)
         {
             int min = m.extractMin();
             sum+=min;
             count++;
         }
        cout<<count-1<<endl; 
        
    
       

     }




     return 0;
 }
