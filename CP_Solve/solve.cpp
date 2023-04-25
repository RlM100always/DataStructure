#include<bits/stdc++.h>
using namespace std ;
#define LL long long int 
#define FASTER ios_base::sync_with_stdio(false);cin.tie(0);
int main(){
     FASTER ;
     int t ;cin>>t ;
     while(t--){
        string s ;cin>>s ;
        //aabbccdde
        int push = 0,c1;
        for(int i=s.size()-1 ;i>0 ;i--){
            int str=s[i]-'0';
            int str1 =s[i-1]-'0';
            c1=str+str1 ;
            if(str+str1>9){
               push =i ;
               s.erase(i-1,2);
              
               break ;
            }
        }
      //  cout<<push<<endl;
      if(push==0){
            //
      }else{
        string s1 =to_string(c1);
        cout<<s1<<endl;
       s.insert(5,s1[0]);
       s.insert(6,s1[1]);
      //  for(int i=0 ;i<s.size();i++){
      //     co
      //  }
      cout<<s<<endl;
      }
      
     }
       
   return 0 ;
}