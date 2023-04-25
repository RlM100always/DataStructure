#include<bits/stdc++.h>
using namespace std ;

struct Node
{
    int data ;
    struct Node* next ;

    
};

Node *head = NULL ;

void insertLast(int value){
    Node *ptr = head ;

    Node *newnode = new Node();
    newnode->data=value ;


    if(head==NULL){
        newnode->next=newnode ;
        head = newnode ;
    }else{
        while(ptr->next != head){
             ptr= ptr->next ;
        }
        ptr->next = newnode ;
        newnode->next=head ;
    }
}

void insertFirst(int value){
    Node *ptr = head ;

    Node *newnode = new Node();
    newnode->data=value ;
    newnode->next=NULL ;

    if(head== NULL){
        newnode->next=newnode ;
        head = newnode ;

    }else{
         while(ptr->next  != head){
              ptr=ptr->next ;
         }
         ptr->next= newnode ;
         newnode->next = head ;
         head = newnode ;
    }

}

void insertPos(int value ,int pos){
    Node *ptr = head ;
   // Node *ptr1 = head->next ;

    Node *newnode = new Node();
    newnode->data=value ;
    int i=1;
    while(i<pos-1){
         ptr = ptr->next ;
        // ptr1 = ptr1->next ;
         i++ ;
    }
      Node *val = ptr->next ;
      ptr->next = newnode ;
      newnode->next = val ;
     
//      ptr->next = newnode ;
//      newnode->next = ptr1 ;
 }

void print(){
    Node *a = head ;
    do{
        
        cout<<a->data<<" ";
        a = a->next;
        
    }while(a!= head);
    cout<<endl;
}

void deleteFirst(){
    if(head==NULL){
        cout<<"There is No element in the linkedlist"<<endl;
    }
    else{
        Node *ptr = head ;
        while(ptr->next != head){
              ptr = ptr->next ;
        }
        
        head = head->next ;
        ptr->next = head ;
    }


}


void deleteLast(){
    if(head==NULL){
        cout<<"There is No element in the linkedlist"<<endl;
    }else{
        Node *ptr = head ;
        Node *ptr1 = head->next ;
        while(ptr1->next != head){
            ptr1 = ptr1 ->next ;
            ptr = ptr ->next ;        
        }
        ptr->next = head ;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    //struct Node *head =NULL;
    // insertFirst(10);
    // print();
    // insertFirst(20);
    // print();
    // insertFirst(30);
    // print();

    //   insertLast(10);
    //   insertLast(20);
    //   insertLast(40);
    //   insertLast(50);
    //   print();
    //   insertFirst(5);
    //   print();

    int n ;cin>>n ;
    for(int i=1 ;i<=n ;i++){
        int inp ;cin>>inp ;
        insertLast(inp);
    }

    print();
    deleteLast();
    print();
    
    return 0 ;
}