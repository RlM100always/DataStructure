#include <bits/stdc++.h>
#define  vi vector<int>

using namespace std;
//radix implementation by using merge sort algorithm
//merge->stable ,TC(o(nlog(n))),comparison

int getMin(vi &v){
    int max_val = v[0];
    for(int i=0 ;i<v.size() ;i++){
       max_val = max(max_val,v[i]);
      // if(v[i]<min_val)min_val=v[i];
    }
    return max_val;
}



void merge(vi & arr, int low, int mid, int high, int pos) {
   
    vi temp(high - low + 1);
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (((arr[i] / pos) % 10) <= ((arr[j] / pos) % 10)) {
            temp[k] = arr[i];k++;i++ ;
        } else {
            temp[k] = arr[j];k++;j++ ;
        }
    }

    while (i <= mid) {
        temp[k] = arr[i];k++ ;i++ ;
    }

    while (j <= high) {
        temp[k] = arr[j];k++ ; j++ ;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i-low];
    }
}

void mergeSort(vi &v ,int l ,int r,int pos){
    //divide conquer process recursivelt untill array size not equql to one .
    //if(l==r)return ;
    if(l<r) {
       int mid =(l+r)/2 ;//2 //1//0//2
       mergeSort(v,l,mid,pos);//0 2 //0 1//0 0//
       mergeSort(v,mid+1 ,r,pos);//1 4//
       merge(v,l,mid,r,pos);
    }
    
}
void radixSort(vi &v){
    int max_value = getMin(v);
    int pos = 1 ;
    int l = 0 ,ro =v.size()-1 ;
    while(max_value/pos>0){//this loop determines ->how much digits contains maximum number
       //mergeSort(v,l,ro,pos);
        mergeSort(v, 0, v.size() - 1, pos);
       pos *=10 ;

       
    }

}

int main() {
    //input k sorted arrays
    freopen("out.txt","w",stdout);
    freopen("int.txt","r",stdin);
    int n ; cin>>n ;
    vi v;
    for(int i=0 ;i<n ;i++){
        int val ;cin>>val ;
        v.push_back(val);

    }
    radixSort(v);

    for(int i=0 ;i<n ;i++){
        cout<<v[i]<<" ";
    }
   //cout<<getMin(v)<<endl;

  
    return 0;
}
