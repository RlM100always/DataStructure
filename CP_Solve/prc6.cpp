#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>&arr, int low, int mid, int high, int pos) {
   

    vector<int> temp(high-low+1);


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

void mergeSort(vector<int>& arr, int low, int high, int pos) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid, pos);
        mergeSort(arr, mid + 1, high, pos);
        merge(arr, low, mid, high, pos);
    }
}


int getMax(vector<int>& v){
    int min_val = v[0];
    for(int i=0 ;i<v.size() ;i++){
       min_val = max(min_val,v[i]);
      // if(v[i]>min_val)min_val=v[i];
    }
    return min_val;
}

void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);

    for (int pos = 1; maxVal / pos > 0; pos *= 10) {
        mergeSort(arr, 0, arr.size() - 1, pos);
    }
}

int main() {

     freopen("int.txt","r",stdin);
     freopen("out.txt","w",stdout);

    int n ;cin>>n ;
    vector<int> arr(n) ;
    

    for(int i=0 ;i<n ;i++){
        cin>>arr[i];
    }

    radixSort(arr);


    
    for(int i=0 ;i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;

    return 0;
}
