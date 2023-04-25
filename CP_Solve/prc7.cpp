#include<iostream>
using namespace std ;
struct node{
    int data ;
    struct node *link ;
};

//globallay declare a pointer variable 
struct node *head=NULL ;

void display(){
   node *ptr = head ;
   while(ptr != NULL){
      cout<<ptr->data<<"->";
      ptr=ptr->link ;
   }
   cout<<endl;
}
//3 4 5 

node* createNode(int value){
       node *newnode = new node();
       newnode->data = value ;
       newnode->link=nullptr;

       return newnode ;
}
//1 2   3  4 8 
void insertAnyPosition(int value ,int pos){
      node *newnode = createNode(value);
      if(head ==NULL) head = newnode; 
      else{
         node *ptr1 = head ;
      node *ptr2 = head->link;

      int i=1 ;//2->link = newnode //newnode->link= 3 add
      while(i<pos-1){
           i++ ;
           ptr1=ptr1->link ;
         //  ptr2=ptr2->link;
      }
      newnode->link=ptr1->link ;
      ptr1->link=newnode;

      }
      
      
      

}

void insertTail(int value){
  //create a node //than declare//than linkup

       node *newnode = createNode(value);
       

      if(head == nullptr)head = newnode ;
      else{
         node *ptr = head ;
         while(ptr->link != NULL){
            ptr=ptr->link;

         }
         ptr->link = newnode ;

      }
     

}
//5 10

int main()
{
    string choice ;
    //node *n1 =(node*) malloc(sizeof(node));
    // node *n1= new node ;
    // node *n2 =new node ;
    // head =n1 ;
    // n1->data=5 ;
    // n2->data = 10 ;
    // n1->link=n2;
    // n2->link=nullptr;
   //  do{
   //       cout<<"Enter Node :";
   //       int data ;cin>>data ;
   //       insertTail(data);
   //       cout<<"If you want to insert a node : choice yes otherwise choice no : ";
   //       cin>>choice ;
   //  }while(choice=="yes");

     insertTail(10);
     insertTail(20);
      insertTail(30);
     insertTail(40);
     insertTail(50);
     display();
    insertAnyPosition(5,1);
    insertAnyPosition(6,2);
    
   
    display();

}