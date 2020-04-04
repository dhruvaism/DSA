#include<bits/stdc++.h>
using namespace std;


void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

class MaxHeap{ 
    int *arr;
    int capacity;
    int count;
    public:
      MaxHeap(int cap)
      {
          capacity=cap;
          count=0;
          arr = new int[cap];
      }
      int parent(int i){return (i-1)/2;}
      int left(int i){return 2*i+1;}
      int right(int i){return 2*i+2;}

      void maxHeapify(int i);
      int extractMax();
     void insert(int key)
      {
         
          if(count==capacity)
           return;

          count++;
          int i = count-1;
          arr[i]=key;
          while(i!=0 && arr[parent(i)]<arr[i])
           { 
              // cout<<arr[parent(i)]<<" "<<arr[i]<<"  ";
               swap(&arr[parent(i)],&arr[i]);
               //cout<<arr[parent(i)]<<" "<<arr[i]<<endl;
               i=parent(i);
           }
      }

    

};


int MaxHeap::extractMax()
{
    if(count==1)
     {
         count--;
         return arr[0];
     }

     int temp = arr[0];
     arr[0] = arr[count-1];
     count--;
     maxHeapify(0);
     return temp;
     
}

void MaxHeap::maxHeapify(int i)
{
    int largest = i;
    int l = left(i);
    int r = right(i);

    if(l<count && arr[largest]<arr[l])
     largest = l;
    if(r<count && arr[largest]<arr[r])
     largest = r;
   // cout<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<endl;
    if(largest!=i)
    {
        //cout<<arr[smallest]<<" "<<arr[i]<<endl;
        swap(&arr[i],&arr[largest]);
       // cout<<arr[smallest]<<" "<<arr[i]<<endl;
        maxHeapify(largest);
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
         MaxHeap m(n);
         for(int i=0;i<n;i++)
         {
             int a;
             cin>>a;
             m.insert(a);    
         }
         int res;
        for(int i=0;i<k;i++)
        {
            res=m.extractMax();
        }
        cout<<res<<endl;

        
    
       

     }




     return 0;
 }
