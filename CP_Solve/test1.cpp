#include<bits/stdc++.h>
using namespace std ;


void reverseIW(string s ){
   stack<char>st ;
   for(int i=0 ;i<=s.size() ;i++){
        st.push(s[i]);
        if(s[i]==' ' || s[i]=='\0'){
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
           
            cout<<" ";

        }

   }
   cout<<endl ;

}
int main(){
    string s ;getline(cin,s);
    reverseIW(s);
    return 0 ;
}