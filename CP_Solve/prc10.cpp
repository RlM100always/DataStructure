#include<bits/stdc++.h>
using namespace std ;

bool balancedCheck(string s ){
   stack<char>sk ;
   for(int i=0 ;i<s.size() ;i++){
       if(s[i]=='(' || s[i]=='{' || s[i]=='['){
           sk.push(s[i]);
       }
       else if(s[i]==')'){
          if(sk.top()=='('){
              sk.pop();
          }
          else{
            return false ;
            break;
          }
       }
       else if(s[i]=='}'){
          if(sk.top()=='{'){
              sk.pop();
          }
          else{
            return false ;
            break;
          }
       }
       else if(s[i]==']'){
          if(sk.top()=='['){
              sk.pop();
          }
          else{
            return false ;
            break;
          }
       }
   }
   return sk.empty();
}

int main(){
    
    string s ;
    cin>>s ;
    if(balancedCheck(s)){
         cout<<"Balanced Paranthesis"<<endl;
    }
    else{
        cout<<"Unbalanced Parenthesis"<<endl;
    }


   return 0 ;
}