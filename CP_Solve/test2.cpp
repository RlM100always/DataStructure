#include<bits/stdc++.h>
#include<queue>
using namespace std ;



class Solution {
public:
    int countStudents(vector<int>& students, vector<int>&      sandwiches) {
        
        stack<int>st ;
        queue<int>qu ;

        for(int i=sandwiches.size()-1 ;i>=0 ;i--){
            st.push(sandwiches[i]);
        }
        
        for(int i= 0 ;i<students.size() ;i++){
            qu.push(students[i]);
        }
        int cnt =  0 ;
        while(1 ){
            if(qu.front() == st.top()){
                st.pop();
                qu.pop();
            }else if(qu.front() != st.top()){
                 int str = qu.front();
                 qu.pop();
                 qu.push(str);
                 cnt++ ;
                 if(cnt>students.size()){
                     break ;
                 }
            }
        }
        return st.size();
    }
};



int main()
{
    Solution sn ;

    int n ;cin>>n ;
    vector<int>a(n) ;
    vector<int>b(n) ;
    for(int i=0 ;i<n ;i++){
        cin>>a[i];
    }
    for(int i=0 ;i<n ;i++){
        cin>>b[i];
    }
   cout<< sn.countStudents(a,b);
    
    return 0 ;
}
