#include <iostream>
#include <string>
using namespace std;
class M_30{

   public :
   void intToString(int data){
          string s =to_string(data);
          cout<<"Int : "<<data+10<<endl ;
          cout<<"Int to String : "<<s+"34"<<endl ;
    }

    void stringToInt(string s){
          int val =10+stoi(s);
          cout<<"String : "<<s+"12"<<endl ;//concatenate string 
          cout<<"String to int : "<<val<<endl ;
    }

};


int main() {
     //integer to string 
     M_30 obj ;
     int data =20 ;
     obj.intToString(data);

    //  string s1 ="130";
    //  obj.stringToInt(s1);

     
    return 0;
}





















//package : Group of class 
//pak1 ->c1 ,c2,c3,c4 
//pak2 ->c4,c5,c6
//pak3->c1,c4,c2
//package are store in hierarchical mannar .
//class has only two access modifier ->one is public 
//other one is default 


//public class is accesible from everywhere .
//default class is access only from this package 
//import java.lang.* ;

//class Myclass extends java.util.Date { }
