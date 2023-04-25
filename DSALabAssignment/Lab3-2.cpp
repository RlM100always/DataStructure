#include<bits/stdc++.h>
using namespace std ;

//in this problem , k number of sorted linked list 
//convert one single sorted linked list
class node {
public:
  int data;
  node *next;
  node(int d) {
    data = d;
    next = NULL;
  }
};


void InsertatTail(node *&head, int d) {
  node *temp = new node(d);
  if (head == NULL) {
    head = temp;
    return;
  }
  node *temp1 = head;
  while (temp1->next != NULL)
    temp1 = temp1->next;
  temp1->next = temp;
}

void print(node *head) {
  node *temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void selectionSort(vector<int>&a ,int size){
     for(int i=0 ;i<=(size-1);i++){
          int min_index = i ;
          for(int j=i+1 ;j<=(size-1);j++){
               if(a[j]<a[min_index]){
                    min_index=j ;
               }
          }
          //swap i && update min_index value
          int temp ;
          temp =a[i];
          a[i]=a[min_index];
          a[min_index]=temp ;
     }
}


int main()
{
    freopen("input2.txt","r",stdin);
    freopen("output2.txt","w",stdout);
    node *head = NULL ;
     int k ;cin>>k ;
     vector<int>v ;

     while (k--)
     {
        int n ;
        cin>>n ;
        int arr[n];
        for(int i=0 ;i<n ;i++){
            cin>>arr[i];
        }      
    
        for(int i=0 ;i<n ;i++){
            v.push_back(arr[i]);
        }
     }


     // sort(v.begin(),v.end());
      selectionSort(v,v.size());
   
     for(int i=0 ;i<v.size() ;i++){
       InsertatTail(head ,v[i]);  
     }
     print(head);
     
}