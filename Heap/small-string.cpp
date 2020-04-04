#include<iostream>
using namespace std;


void swap(char *x, char *y) 
{ 
	char temp = *x; 
	*x = *y; 
	*y = temp; 
} 

class MinHeap{ 
    char *arr;
    int capacity;
    int count;
    public:
      MinHeap(int cap)
      {
          capacity=cap;
          count=0;
          arr = new char[cap];
      }
      int parent(int i){return (i-1)/2;}
      int left(int i){return 2*i+1;}
      int right(int i){return 2*i+2;}
      void insert(char key)
      {
         
          if(count==capacity)
           return;

          count++;
          int i = count-1;
          arr[i]=key;
          while(i!=0 && arr[parent(i)]>arr[i])
           { 
               swap(&arr[parent(i)],&arr[i]);
               i=parent(i);
           }
      }

   char extractMin();
   void minHeapify(int i);


    

};

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

char MinHeap::extractMin()
{
    if(count==1)
     {
         count--;
         return arr[0];
     }

     char temp = arr[0];
     arr[0] = arr[count-1];
     count--;
     minHeapify(0);
     return temp;
     
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        int q;
        cin>>str>>q;
        MinHeap m(q);
        for(int i=0;i<q;i++)
         {
             m.insert(str[i]);
         }
        string S=""; 
        int qq=q;
        while(q<str.length())
         {
            S+=m.extractMin();
            m.insert(str[q]);
            q++;

         } 
        for(int i=0;i<qq;i++)
         S+=m.extractMin();

        cout<<S<<endl;  

    }



    return 0;
}