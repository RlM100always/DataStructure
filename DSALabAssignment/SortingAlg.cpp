

#include <bits/stdc++.h>
#include<time.h>
using namespace std ;
//#include <time.h>

int getMax(int arr[],int siz){
    int max= arr[0];
    for(int i=0 ;i<siz ;i++){
         if(arr[i]>max){
          max =arr[i];
    }
    }
    return max ;
}

void countSort(int arr[],int siz,int pos){
    int out[siz];
    int cnt[10];
     for(int i=0;i<10 ;i++){
       cnt[i]=0;
    }
    for(int i=0 ;i<siz ;i++){
        cnt[(arr[i]/pos)%10]++ ;
    }
    for(int i=1 ;i<10 ;i++){
       cnt[i]=cnt[i]+cnt[i-1];
    }
   for(int i=siz-1 ;i>=0 ;i--){
       out[--cnt[(arr[i]/pos)%10]]=arr[i];
   }
   for(int i=0 ;i<siz ;i++){
       arr[i]=out[i];
   }

}

void selectionSort(int arr[],int n,int exp){

    for(int i=0 ; i<n-1 ; i++){
        int min_Idx = i ;
        for(int j=i+1 ; j<n ; j++){
            if((arr[j]/exp)%10 <(arr[min_Idx]/exp)%10){
                min_Idx = j;
            }
        }
        
        swap(arr[i],arr[min_Idx]);

    }
}


void merge(int *arr,int digit[],int s , int e){

    int mid= (s+e)/2 ;

    int len1 = mid-s+1 ;
    int len2 = e-mid ;

    int *first = new int[len1];
    int *second = new int[len2];

    int *first1 = new int[len1];
    int *second1 = new int[len2];

    //copy valus
    int mainArrayIndex = s ;
    for(int i=0 ; i<len1 ; i++){
        first[i]=digit[mainArrayIndex];
        first1[i]=arr[mainArrayIndex++];
    }
    mainArrayIndex = mid+1 ;
    for(int i=0 ; i<len2 ; i++){
        second[i] = digit[mainArrayIndex];
        second1[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted array
    int index1 = 0 ;
    int index2 = 0;
    mainArrayIndex = s ;

    while(index1<len1 && index2< len2){
        if(first[index1]<second[index2]){
            digit[mainArrayIndex]=first[index1];
            arr[mainArrayIndex++]=first1[index1++];

        }else{
            digit[mainArrayIndex]=second[index2];
            arr[mainArrayIndex++]=second1[index2++];
        }
    }

    while(index1<len1){
        digit[mainArrayIndex]=first[index1];
        arr[mainArrayIndex++]=first1[index1++];
    }

    while(index2<len2){
        digit[mainArrayIndex]=second[index2];
        arr[mainArrayIndex++]=second1[index2++];
    }

    delete []first;
    delete []second;
    delete []first1;
    delete []second1;

}
void mergeSort(int *arr ,int digit[] , int s , int e){
    // base case 
    if(s>=e){
        return;
    }

    int mid=(s+e)/2 ;
    //left part sort 
    mergeSort(arr,digit,s,mid);

    // right part sort
    mergeSort(arr,digit,mid+1,e);

    merge(arr,digit,s,e);
}

//Quick Sort

int partition(int arr[], int digit[] , int s , int e){
    
    int pivot  = digit[s];
    int cnt = 0 ;
    for(int i=s+1 ; i<=e ; i++){
        if(pivot >= digit[i])
        {
            cnt++ ;
        }
    }

    int pidx = s+cnt ;

    swap(digit[s],digit[pidx]);
    swap(arr[s],arr[pidx]);

    int i = s , j =e ;
    while(i<pidx && j>pidx){
        while(digit[i]<=digit[pidx])
        {
            i++ ;
        }
       while(digit[j]>digit[pidx])
        {
            j-- ;
        }

        if(i<pidx && j>pidx)
        {
            swap(digit[i],digit[j]) ;
            swap(arr[i++],arr[j--]) ;
        }
    }

    return pidx ;
}

void quickSort(int arr[] ,int digit[], int s , int e){

    if(s>=e) return  ;

    int pidx = partition(arr,digit,s,e);

    quickSort(arr,digit,s,pidx-1);

    quickSort(arr,digit,pidx+1,e) ;

}


void merge_quick_Sort(int arr[],int n,int exp){
    int digit_arr[n];
    for(int i= 0 ; i<n ; i++){
        digit_arr[i]=(arr[i]/exp)%10 ;
    }

    
      mergeSort(arr,digit_arr,0,n-1);
      quickSort(arr,digit_arr,0,n-1) ;
    
}



void radixSort(int arr[],int siz){
    int max = getMax(arr,siz);
    for(int pos=1 ;(max/pos)>0 ;pos*=10 ){
              countSort(arr,siz,pos);
             //selectionSort(arr,siz,pos);
            //merge_quick_Sort(arr,siz,pos);
        
    }
}   



int main() {


  freopen("int.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int siz ;//5000 elements
  cin>>siz ;
  //siz=5000;
  int arr[siz];
  for(int i=0 ;i<siz ;i++){
       cin>>arr[i];
  }
 
 
  clock_t start, end;
   /* Store start time here */
   start = clock();
   

  radixSort(arr,siz);
  
   end = clock();
   /* Get the time taken by program to execute in seconds */
   double duration = ((double)end - start)/CLOCKS_PER_SEC;
   cout<<endl ;
   printf("Time taken to execute in seconds : %f", duration);
  cout<<endl;
  for(int i=0 ;i<siz ;i++){
       cout<<arr[i]<<" ";
  }


   return 0;
}




