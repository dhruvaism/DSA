//Using Doybling Size method;
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct Dstack
   {
       int size;
       int top;
       int* array;
   };


  Dstack* createStack()
     {
         Dstack* st = new Dstack;
         st->top = -1;
         st->size = 1;
         st->array = (int*)malloc(st->size*sizeof(int));
         return st;
     }
 
 
 bool isFULL(Dstack* st)
   {
       if(st->top == st->size - 1)
          return true;
        return false;  

   }

  void doubleSize(Dstack* st)
     {
         st->size = st->size*2;
         st->array = (int*)realloc(st->array,st->size*sizeof(int));
     }  


 void push(Dstack* st)
     {
         if(isFULL(st))
           doubleSize(st);

         
         int n;
         cin >>n;
         st->array[++st->top] = n;
          

         cout <<st->size<<" ";  
           

     }
  void display(Dstack* st)
     {
         cout <<endl;
         for(int i=st->top;i>=0;i--)
           {
               cout<<st->array[i]<<endl;
               
           }
     }   
    

 int main()
    {
 
        Dstack* st = createStack();
        for(int i=0;i<5;i++)
          {
              push(st);
          }

         display(st); 
        

        return 0;
    }    