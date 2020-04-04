#include<bits/stdc++.h>
using  namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};



class Node{
    public:
      node* root;
      Node(){root=nullptr;}
      void insertNode(int data)
       {
           node* newnode = new node();
           newnode->data=data;
           newnode->left = nullptr;
           newnode->right = nullptr;
          if(root==nullptr)
            {
                root = newnode;
            }
           else
           {
                linker(root,newnode,data);
           }
             
       }

       void linker(node* root,node* newnode ,int data)
         {

           queue<node*> q;
           q.push(root);
           while(!q.empty())
           {
             node* temp = q.front();
             q.pop();
             if(temp->left)
              {
                 q.push(temp->left);
              }
              else
              {
                 temp->left=newnode;
                 break;
              }

              if(temp->right)
              {
                 q.push(temp->right);
              }
              else
              {
                 temp->right=newnode;
                 break;
              }
           }
         

         }

     void preorder(node* root)
         {
             if(root)
               {
                   cout <<root->data<<" ";
                   preorder(root->left);
                   preorder(root->right); 
               }
         }  

     void usingLevelOrder(node* root,int d)
       {
           if(!root)
             return;
           queue<node*> q;
           q.push(root);

           while(!q.empty())
            {
                node* temp = q.front();
                q.pop();
                if(temp->data==d)
                   cout <<"Found"<<endl;
                if(temp->left)
                   q.push(temp->left);
                if(temp->right)
                   q.push(temp->right);
         
            }  
       }  

      void usingRecursion(node* root, int p)
       {
           if(!root)
             return;
           if(root->data==p)
              {
                  cout <<"found"<<endl;
                  return;
              }
              usingRecursion(root->left,p);
              usingRecursion(root->right,p);

              return;

       } 
      int length(node* root)
        {
            if(!root)
              return 0;

            return 1+length(root->left)+length(root->right);  

        }   

      int height(node* root)
       {
         if(!root)
          return 0;

         int left = height(root->left);
         int right = height(root->right);
         if(left>right)
          return left+1;
         return right+1;  
       }  

      int findDeepest(node* root)
       {
         int depest=-1;
         queue<node*> q;
         q.push(root);
         while(!q.empty())
          {
            node* temp=q.front();
            depest = temp->data;
            q.pop();
            if(temp->left)
             q.push(temp->left);
            if(temp->right)
             q.push(temp->right);

          }

         return depest; 
       } 



float round1(float var) 
{ 
    // 37.66666 * 100 =3766.66 
    // 3766.66 + .5 =3767.16    for rounding off value 
    // then type cast to int so value is 3767 
    // then divided by 100 so the value converted into 37.67 
    float value = (int)(var * 100 + .5); 
    return (float)value / 100; 
} 

 void findAverageLevel(node* a)
{
    queue<node*> q;
    q.push(a);
    q.push(nullptr);
    float sum=0.00;
    int c=0;
    cout<<round1((float)a->data)<<" ";
    while(!q.empty())
     {
       
       node* temp=q.front();
       q.pop();
       
       if(!temp)
        {
          if(!q.empty()){
           q.push(nullptr);
           float avg=(float)sum/c;
          cout<<round1(avg)<<" ";
          sum=0.00;
          c=0;
          }
           
          
           
        }
       else
        {
          if(temp->left)
           {
             q.push(temp->left);
             sum+=(float)temp->left->data;
             c++;
           }
          if(temp->right)
           {
             q.push(temp->right);
             sum+=(float)temp->right->data;
             c++;
           }
        }
     }
}   

};

bool getPath(node* root, vector<int>& arr, int x) 
{ 
    // if root is NULL 
    // there is no path 
    if (!root) 
        return false; 
  
    // push the node's value in 'arr' 
    arr.push_back(root->data); 
  
    // if it is the required node 
    // return true 
    if (root->data == x) 
        return true; 
  
    // else check whether the required node lies 
    // in the left subtree or right subtree of 
    // the current node 
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) 
        return true; 
  
    // required node does not lie either in the 
    // left or right subtree of the current node 
    // Thus, remove current node's value from 
    // 'arr'and then return false 
    arr.pop_back(); 
    return false; 
} 

int countPathBetweenNodes(node* root, int n1, int n2) 
{ 
    // vector to store the path of 
    // first node n1 from root 
    vector<int> path1; 
  
    // vector to store the path of 
    // second node n2 from root 
    vector<int> path2; 
  
    getPath(root, path1, n1); 
    getPath(root, path2, n2); 
  
    int intersection = -1; 
  
    // Get intersection point 
    int i = 0, j = 0; 
    while (i != path1.size() || j != path2.size()) { 
  
        // Keep moving forward until no intersection 
        // is found 
        if (i == j && path1[i] == path2[j]) { 
            i++; 
            j++; 
        } 
        else { 
            intersection = j - 1; 
            break; 
        } 
    } 
  
    // Print the required path 
    int count=0;
    for (int i = path1.size() - 1; i > intersection; i--) 
        count++; 
  
    for (int i = intersection; i < path2.size(); i++) 
        count++; 

    return count;    
} 
  
  


int findDiameter(node* root)
 {
   int count=0;
   node* current=nullptr;
   queue<node* > q;
   q.push(root);
   while(!q.empty())
    {
      node* temp = q.front();
      q.pop();

      if(!temp->left && !temp->right)
       {
            if(!current)
             {
               current=temp;
             }
            else
            {
              int ccount = countPathBetweenNodes(root,current->data,temp->data);
              if(count<ccount)
               count = ccount;
               current = temp;
            }
             
       }

      if(temp->left)
       q.push(temp->left);
      if(temp->right)
       q.push(temp->right);  
    }

    return count;
 }


struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
} 

int add(node* root)
 {
   if(root)
    {
      return root->data+add(root->left)+add(root->right);
    }
   return 0; 
 }

int checkSumTree(node* root)
 {
   if(!root)
    return 1;
   if(!root->left && !root->right)
    return 1;

   int left = add(root->left);
   int right = add(root->right);
   if(root->data==left+right)
    {
      if(checkSumTree(root->left) && checkSumTree(root->right))
       return 1;
      return 0; 
    }  

   return 0; 

 } 

 void makeSumTree(node * root)
  {
    if(!root)
     return;

    int left = add(root->left);
    int right = add(root->right);
    root->data=left+right;
    makeSumTree(root->left);
    makeSumTree(root->right);
  }

  void inorder(node* root)
   {
     if(root)
      {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
      }
   }

  


  void findPath(node* root)
   {
     queue<node*> q;
     q.push(root);
     while(!q.empty())
      {
        node* temp = q.front();
        q.pop();
        if(!temp->left && !temp->right)
         {
           vector<int> path;
           if(getPath(root,path,temp->data))
            {
              for(int i=0;i<path.size();i++)
               {
                 cout<<path.at(i)<<" ";
               }
               cout<<endl;
            }
           

         }
        if(temp->left)
         q.push(temp->left);
        if(temp->right)
         q.push(temp->right);  
      }
   } 

int search(int in[],int inOrderStart,int inOrderedEnd,int data)
 {
   int res=-1;
   for(int i=inOrderStart;i<=inOrderedEnd;i++)
    {
      if(in[i]==data)
         {
          res = i;
          break;
         }
    }
   return res;  
 }   

struct node* constructTree(int pre[],int in[],int inOrderStart,int inOrderedEnd)
 {
     struct node* root;
     static int preOrderIndex=0;
     if(inOrderStart>inOrderedEnd)
      return NULL;

     root = newNode(pre[preOrderIndex]);
     preOrderIndex++;
     if(inOrderStart==inOrderedEnd)
      return root;

     int inOrderIndex = search(in,inOrderStart,inOrderedEnd,root->data);
     root->left = constructTree(pre,in,inOrderStart,inOrderIndex-1);
     root->right = constructTree(pre,in,inOrderIndex+1,inOrderedEnd);
     
     return (root);  
 }

 void topView(node * root,int n,bool isRight)
  {
    if(!root)
     return;
    if(isRight==false)
     {
        topView(root->left,n+1,false);
        cout<<root->data<<" ";
     } 
    if(n==0)
     {
       cout<<root->data<<" ";
       topView(root->right,n+1,true);
     } 
    if(n>0 && isRight)
     {
       cout<<root->data<<" ";
       topView(root->right,n+1,true);
     } 
  }


  bool getPath1(node* root, set<int>& arr, node* temp) 
{ 
    // if root is NULL 
    // there is no path 
    if (!root) 
        return false; 
  
    // push the node's value in 'arr' 
    arr.insert(root->data); 
  
    // if it is the required node 
    // return true 
    if (root == temp) 
        return true; 
  
    // else check whether the required node lies 
    // in the left subtree or right subtree of 
    // the current node 
    if (getPath1(root->left, arr,temp) || getPath1(root->right, arr, temp)) 
        return true; 
  
    // required node does not lie either in the 
    // left or right subtree of the current node 
    // Thus, remove current node's value from 
    // 'arr'and then return false 
    arr.erase(prev(arr.end())); 
    return false; 
} 


void findPath1(node* root)
   {
     queue<node*> q;
     q.push(root);
     while(!q.empty())
      {
        node* temp = q.front();
        q.pop();
        if(!temp->left && !temp->right)
         {
           set<int> path;
           if(getPath1(root,path,temp))
            {
              cout<<path.size()<<" ";
            }
           

         }
        if(temp->left)
         q.push(temp->left);
        if(temp->right)
         q.push(temp->right);  
      }
   } 



int main()
 {

    string str;
    str+='a';
    str+='b';
    cout<<str<<endl;
    // cout<<"jhjbjh"<<endl;

    // int pre[]={1,2,3,4,5,6};
    // int in[]={3,2,4,1,6,5};

    // struct node* root = constructTree(pre,in,0,5);
    // //cout<<root->data<<endl;
    // findPath1(root);
    //topView(root,0,false);
    //inorder(root);
    // Node tree;
    //cout<<root->data<<endl;
    // struct node* root = newNode(1);
    // root->left =  newNode(2);
    // root->right=newNode(3);
    // root->left->left=newNode(6);
    // root->left->right=newNode(4);
    // root->right->left=newNode(3);
    
    // findPath(root);
    // makeSumTree(root);
    // inorder(root);

    // if(checkSumTree(root))
    //  cout<<"Yes"<<endl;
    // else
    //  cout<<"No"<<endl; 

    //  int n;
    //  for(int i=0;i<8;i++)
    //    {
    //        cin >>n;
    //        tree.insertNode(n);
    //    }
      //tree.preorder(tree.root); 
      // int p;
      // cin >>p;
      // //tree.usingLevelOrder(tree.root,p);
      // // tree.usingRecursion(tree.root,p);
      // cout <<tree.length(tree.root)<<endl;
      //tree.findAverageLevel(tree.root);
      //cout<<tree.height(tree.root)<<endl;
      //cout<<tree.findDeepest(tree.root)<<endl;
      //cout<<findDiameter(root)<<endl;
     
 }