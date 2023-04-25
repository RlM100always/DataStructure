#include <bits/stdc++.h>
using namespace std;
#define MAX 5

// class Node{
//    public :
//    int data ;
//    Node *link ;

//    Node(int data){
//        this->data = data ;
//        link = NULL ;
//    }

// };

   struct Node{
       int data ;
       Node * link ;

   };

    Node *top= NULL ;

   void push(int val){
      Node *newnode = new Node();
      newnode->data = val ;
      
      if(top==NULL){
        top = newnode ;
        newnode->link=NULL ;
      }else{
          newnode->link=top ;
          top = newnode ;
      }
   }

   void print(){
      Node *ptr = top ;
      cout<<"Stack Element LIFO : "<<endl ;
      while(ptr != NULL){
         cout<<ptr->data<<endl ;
         ptr= ptr->link ;
      }
   }
   
   int tp(){
    if(top ==NULL)return -1 ;
    
    return top->data ;
   }
 
      int peek(){
       if(top==NULL){
           return -1 ;
       }else{
           return top->data ;
       }

   }
   
   void pop(){
       if(top==NULL){
           cout<<"Stack is underflow "<<endl ;
       }else{
           Node *ptr = top ;
           top = top->link  ;
           delete(ptr);
       }

   }


int main() {

    push(2);
    push(4);
    push(8);
    push(10);
    print();
    pop();
    print();
    cout<<peek()<<endl ;
    print();



    return 0;
}
