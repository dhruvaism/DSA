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
      void decreaseKey(int k,int smallest_Value);
      void heapsort();
      void printHeap()
      {
          for(int i=0;i<count;i++)
             cout<<arr[i]<<" ";
          cout<<endl;   
      }

    

};

void MinHeap::heapsort()
{
    int old_count = count;
    for(int i=count-1;i>=0;i--)
    {
        swap(&arr[i],&arr[0]);
        count--;
        minHeapify(0);
    }
    count = old_count;
}

void MinHeap::decreaseKey(int i,int smallest_Value)
{
   arr[i] = smallest_Value;
   while(i!=0 && arr[parent(i)]>arr[i])
   {
      swap(&arr[i],&arr[parent(i)]);
      i = parent(i);
   }

}

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
         cin>>n;
         MinHeap m(n);
         for(int i=0;i<n;i++)
         {
             int a;
             cin>>a;
             m.insert(a);
         }
         m.heapsort();
         m.printHeap();
    
       

     }




     return 0;
 }
