#include <iostream>
#include <vector>
using namespace std;


vector<int> merge(vector<int>&vec1 ,vector<int>&vec2){

    vector<int>rt ;
    int i=0 ,j =0,k=0 ;
    while(i<vec1.size() && j<vec2.size()){
        if(vec1[i]<vec2[j]){
          rt.push_back(vec1[i]);
          i++ ;
        }
        else{
           rt.push_back(vec2[j]);
           j++ ; 
        }
    }
     while(i<vec1.size()){
    
          rt.push_back(vec1[i]);
          i++ ;       
    }

     while(j<vec2.size()){
    
          rt.push_back(vec2[j]);
          j++ ;       
    }


    return rt ;

}

int main() {
    //input k sorted arrays
    freopen("out.txt","w",stdout);
    freopen("int.txt","r",stdin);
     
    int k ;
    cin>>k ;
    vector<vector<int>>v;

    
    for(int i=0 ;i<k;i++){
        vector<int>push ;
        int siz_push ; cin>>siz_push ;
        for(int j= 0 ;j<siz_push ;j++){
            int data ;cin>>data ;
              push.push_back(data);
        }
        v.push_back(push);
    }


    vector<int> result ;
    result=v[0];
    
    for(int i=0 ;i<v.size()-1 ;i++){
       
       result = merge(result,v[i+1]);
    //    cout<<"---After Merging ---"<<endl ;
    //    for(int i=0 ;i<result.size() ;i++){
    //     cout<<result[i]<<" " ;
    //    }


       cout<<endl ;
    }

    cout<<"---After Merging ---"<<endl ;
    for(int i=0 ;i<result.size() ;i++){
        cout<<result[i]<<" " ;
    }
    return 0;
}
