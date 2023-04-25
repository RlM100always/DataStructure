#include<bits/stdc++.h>
using namespace std ;
bool solve( vector<int>pushed, vector<int>poped){
    stack<int>s ;
    int i=0 ;
    int j=0 ;

    for( i=0 ;i<pushed.size() ;i++){
        s.push(pushed[i]);
        while(!s.empty() && s.top()==poped[j]){
               s.pop();
               j++ ;
        }
    }
   
    return s.empty();
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n ;
    cin>>n ;
     vector<int>pushed ,poped;
     for(int i=0 ;i<n ;i++){
          int val ;
          cin>>val ;
          pushed.push_back(val);
     }
     for(int i=0 ;i<n ;i++){
          int val1 ;
          cin>>val1 ;
          poped.push_back(val1);
     }
     int k=solve(pushed,poped);
     if(k){
        cout<<"True"<<endl;
     }else cout<<"False"<<endl ;
     return 0 ;
}