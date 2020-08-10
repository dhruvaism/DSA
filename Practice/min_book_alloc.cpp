//HackerBlock question 408

//Time Complexity O(nLogn)
#include<iostream>
#include<set>
using namespace std;

#define ll long long int

bool isValidConfig(ll *p,ll n,ll m,ll mid){
     int students = 1;
     int current_pages=0;
     for(int i=0;i<n;i++){
         if(current_pages+p[i]>mid){
             current_pages = p[i];
             students++;
         }else{
             current_pages+=p[i];
         }
         if(students>m){
             return false;
         }
     }
     return true;
}

void findMinPages(ll *p,ll n,ll m){

   ll total_pages = 0;
   ll s=0,e=0;
   for(int i=0;i<n;i++){
       total_pages+=p[i];
       s = max(s,p[i]);
   }
   e = total_pages;

   ll finalAns = 0;
   while(s<=e){
       ll mid = (s+e)/2;
       if(isValidConfig(p,n,m,mid)){
           finalAns = mid;
           e = mid-1;

       }else{
           s = mid+1;
       }
   }

   cout<<finalAns<<endl;

}

int main(){

    ll n; //no of book
    ll m; //no of student
    cin>>n>>m;
    
    ll pages[n]; //no of pages in each book
    for(int i=0;i<n;i++) 
     cin>>pages[i];
    
    findMinPages(pages,n,m);




    return 0;
}