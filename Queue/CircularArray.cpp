#include<iostream>
using namespace std;

class Queue{
  
      public:
         int rear=-1;
         int front=-1;
         int size;
         int *arr;
         Queue(int s)
           {
               size=s;
               arr = new int[size];
           }
         void enQueue(int d);
         void deQueue();
         void display();  

};

void Queue::enQueue(int d)
  {
      if((front==0 && rear==size-1)||(rear==front-1))
        {
           cout <<"Queue is Full"<<endl;
        }
      else if(front==-1)
        {
            front=rear = 0;
            arr[front]=d;

        }  
       else if(front!=0 && rear==size-1)
        {
            rear=0;
            arr[rear]=d;
        } 
       else
       {
           arr[++rear]=d;
       }
        
  
  }

  void Queue::deQueue()
   {
       if(front==-1 || front==rear==size-1)
         {
            cout <<"Queue is Empty"<<endl;
         }

        arr[front]=-1;
        if(front==size-1 && rear<front)
         {
             front=0;
         }
         else
         {
             front++;
         }
          
   }

   void Queue::display()
    {
        if(front==-1)
          {
              cout<<"Empty"<<endl;
              return;
          }
        if(rear>=front)
          {
              for(int i=front;i<=rear;i++)
                {
                    cout <<arr[i]<<" ";
                }
          }
         else
         {
             for(int i=0;i<=rear;i++)
                {
                     cout <<arr[i]<<" ";
                }
              for(int i=front;i<size;i++)
                {
                     cout <<arr[i]<<" ";
                }  
         }
          
    }



int main()
  {

      Queue q(5);
      int m,n;
      while(1)
        {
            cin>>m;
            switch (m)
            {
            case 1: cout <<"Enter data: ";
                    cin>>n;
                    q.enQueue(n);
                
                break;
            case 2: q.deQueue();
                break;
            case 3: q.display();
                break;        
            
            default:
                break;
            }
        }
  }