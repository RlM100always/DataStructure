#include<bits/stdc++.h>
using namespace std ;
#define LL long long int 
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
     FASTER ;
     int t ; cin>>t ;
     while(t--){
        int n ;cin>>n;
        string s ;cin>>s ;
        string s1="1";
        
        for(int i=0 ;i<n-1 ;i++){
           int c1 = s[i]-'0';
           int c2 =s1[s1.size()-1]-'0';
           int c3=c1^c2 ;
          // cout<<c3<<" ";
           char c4=c3;
          // cout<<c4<<endl;
          s1.push_back(c4);
        }
        //cout<<s1<<endl;
        int cnt =0 ;
        for(int j=0 ;j<s1.size() ;j++){
           if(s1[j]=='1')cnt++ ;
        }
        cout<<cnt<<endl ;
        
     }

     
    return 0 ;
}
