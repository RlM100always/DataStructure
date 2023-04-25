#include<bits/stdc++.h>
using namespace std ;


int binarySearch(vector<int>v ,int x ){

   //4 5 7 8 9 10 11 

   int l = 0 , r = v.size()-1 ,mid ;
   while(l<=r){
      mid = (l+r)/2 ;
      if(v[mid]==x)return mid ;
      else if(v[mid]>x) r=mid-1 ;
      else l = mid + 1 ;
   }
  return -1 ;
}


//sorting algorithm 
//stable sorting ->which sorting algorithm maitain the reletive order
//of same value 


//Bubble sorting  
//compare two adjacent value 
//if a[i]>a[i+1] swap them (inner loop)->1 pass
//if no of element is  n ->number of pass is n-1
//2 6 8 0 1
void bubbleSort(vector<int> &v ){

   //&v pass by address thats why change is 
   //hapenning in this function also  in main function
   //if we write v ->change doesnt happening in the 
   //main function 
    
    for(int i=0 ;i<v.size()-1 ;i++){//number of passes
      for(int j=0 ;j<v.size()-1;j++){
         if(v[j]>v[j+1]){
             swap(v[j],v[j+1]);
         }
      }
    }

//   for(int i=0 ;i<v.size() ;i++ ){
//      cout<<v[i]<<" ";
//   }
//   cout<<endl ;
}



int main(){

   freopen("out.txt","w",stdout);
   freopen("int.txt","r",stdin);

  vector<int>v;
  int n ;
  cin>>n  ;
  for(int i=0 ;i<n ;i++){
     int val ;
     cin>>val ;
     v.push_back(val);
  }
  cout<<"----Before Sorting : ----"<<endl ;
  for(int i=0 ;i<n ;i++ ){
     cout<<v[i]<<" ";
  }
  cout<<endl ;

  bubbleSort(v);
  
  cout<<"----After Sorting : ----"<<endl;
  for(int i=0 ;i<n ;i++ ){
     cout<<v[i]<<" ";
  }
  cout<<endl ;

  int search_value ;
  cin>>search_value ;
  cout<<"Index : "<<binarySearch(v,search_value);
  
  
  return 0 ;
}