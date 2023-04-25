#include<bits/stdc++.h>
using namespace std ;
void swap(int &x ,int &y)
{
  int temp = x ;
  x = y ;
  y = temp ;
}
void bubbleSort(vector<int>&v)
{
int size = v.size() ;
    for(int i = 0 ; i<size ; i++)
    {
      for(int j = 0 ; j+1<size-i ; j++)
      {
        if(v[j]>v[j+1])
        {
          swap(v[j],v[j+1]) ;
        }
      }
    }
}
void selectionSort(vector<int>&v){
    int size = v.size() ;
    int min_element ;
    int index ;
    for(int i = 0 ; i<size ; i++)
    {
       min_element = v[i] ;
       index = i ;
       for(int j = i+1 ; j<size ; j++)
       {
         if(min_element>v[j])
         {
             min_element = v[j] ;
             index = j ;
         }
       }
       swap(v[i],v[index]) ;
    }
}
void insertionSort(vector<int>&v)
{
   int size = v.size() ;
   for(int i = 0 ;i+1<size ; i++)
   {
       for(int j = i+1 ;j>0 ; j--)
       {
          if(v[j]<v[j-1])
          {
          swap(v[j],v[j-1]) ;
          }
       }
  }
}
void printArray(vector<int>&v)
{
  for(int i = 0 ; i<v.size()  ; i++)
  {
    if(i==0)printf("%d",v[i]) ;
    else printf(" %d",v[i]) ;
  }printf("\n") ;
}




int main()
{
  int row , col  ; scanf("%d %d",&row ,&col) ;
  int arr[row][col] ;
  for(int i = 0  ; i<row ; i++)
  {
    for(int j = 0 ; j<col ; j++)
    {
      scanf(" \n%d",&arr[i][j])  ;
    }
  }
  int st = row - 1 ;
  int ed = 0 ;
  while(st>=0 && ed<col)
  {
    if(st==0 && ed == col -1 )break  ;
    else if(st<=row-1 && ed<col && st!=0 )
    {
      st-- ;    
      ed = 0 ; 
    }
    else if(st==0 && ed <col-1)
    {
      ed++ ;
      st==0 ;
    }
    // diagonal traverse ;
    int i = st  , j = ed ;
   // printf("st : %d , ed %d\n",st,ed) ;
    vector<int>v ;
    while(i<row && j<col)
    {     
      int x = arr[i][j] ;
      v.push_back(x) ; 
      i++ ;
      j++ ; 
    }
    insertionSort(v) ;
    i = st , j = ed ;
    int v_index = 0 ;
    while(i<row && j<col)
    {
      arr[i][j] = v[v_index++] ;
      i++ ;
      j++ ;
    }
  


  }
  for(int i = 0 ; i<row ; i++)
  {
      for(int j = 0 ; j<col ; j++)
      {
         if(j==0)printf("%d",arr[i][j]) ;
         else printf(" %d",arr[i][j]) ;
      }
      printf("\n") ;
  }
  
  
  return 0 ;
}