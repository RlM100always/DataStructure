#include<bits/stdc++.h>
using namespace std ;

//reverse polish notation

int solve( vector<string>&v){
    stack<int>st ;
    for(string x:v)
    {
        if(x=="+"){
            int a = st.top();
            st.pop();
            int b= st.top();
            st.pop();
            st.push(a+b);
        }
    else if(x=="-"){
            int a = st.top();
            st.pop();
            int b= st.top();
            st.pop();
            st.push(b-a);
    }
    else if(x=="*"){
            int a = st.top();
            st.pop();
            int b= st.top();
            st.pop();
            st.push(a*b);
    }
    else if(x=="/"){
            int a = st.top();
            st.pop();
            int b= st.top();
            st.pop();
            st.push(b/a);
    }
    else{
        st.push(stoi(x));
    }
    
    }

    
    return st.top();
}
int main()
{
     freopen("input1.txt","r",stdin);
     freopen("output1.txt","w",stdout);
     int n ;
     cin>>n ;

    vector<string>v ;
    for(int i=0 ;i<n ;i++){
         string s ;
         cin>>s ;
         v.push_back(s);
    }

    cout<<solve(v)<<endl;

 return 0 ;
}