#include<bits/stdc++.h>
using namespace std ;

struct Node{
   Node *prev ;
   int data ;
   Node *next ;
};

void print(Node *a)
{
   Node *ptr = a ;
  cout<< "Doubly linked list value are :"<<endl; 
   while(ptr !=nullptr){
     cout<<ptr->data<<" ";
     ptr=ptr->next;
   }
   cout<<endl ;
}

Node* create_node(int data){
    Node* newnode =new Node();
    newnode->data = data ;
    newnode->prev=NULL ;
    newnode->next=NULL ;
    return newnode ;
}

void insertFirst(Node *&b,int value){
  Node *newnode = create_node(value);
  if(b==NULL){
      b= newnode ;
  }
  else{
    newnode->next=b ;
    newnode->prev=NULL;
    b->prev = newnode ;
    
    b=newnode ;
  }

}

void insertLast(Node *&b,int value){

}
//code from scratch
int main()
{
    Node *head =NULL ;
    // Node *tail =NULL ;
    // int n ,data;cin>>n ;
    // for(int i=0 ;i<n ;i++){
    //     cout<<"Enter the value of Node : ";
    //     cin>>data ;
    //     Node *newnode = create_node(data);

    //     if(head==NULL){
    //         head = newnode ;
    //         tail = newnode ;
    //     }else{
    //         tail->next= newnode ;
    //         newnode->prev = tail ;
    //         tail = newnode ;
    //     }

    // }
    insertFirst(head ,10);
    //insertFirst(head ,90);
    print(head);
   

    return 0 ;
}