#include<bits/stdc++.h>
using namespace std ;

//  1 3 4 0 9 -4 6 7 
//stable 
void insertionSort(int arr[] ,int siz ){
    for(int i=1 ;i<siz ;i++){
        int hole = arr[i];
        int j =i-1 ;
        while((hole<arr[j]) && j>=0 ){
            //shifting
            arr[j+1]=arr[j];
            j-- ;
        }
        arr[j+1]=hole;
    }
}

int main(){

   freopen("out.txt","w",stdout);
   freopen("int.txt","r",stdin);

  int n ;cin>>n ;
  int array[n];
  for(int i=0 ;i<n ;i++){
     cin>>array[i];
  }
  cout<<"----Before Sorting : ----"<<endl ;
  for(int i=0 ;i<n ;i++ ){
     cout<<array[i]<<" ";
  }
  cout<<endl ;

  insertionSort(array,n);
  
  cout<<"----After Sorting : ----"<<endl;
  for(int i=0 ;i<n ;i++ ){
     cout<<array[i]<<" ";
  }
  cout<<endl ;


  
  
  return 0 ;
}