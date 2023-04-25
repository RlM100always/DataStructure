#include<stdio.h>
int main()
{
   FILE *fp ;
   fp =fopen("test_file.txt","a");
   int i ;
   for(i=65 ;i<90 ;i++){
       fputc(i,fp);
   }
   char arr[1000]="vlo programmer tomake hotei hbe,onk droto onk besi applicatn sikha lgbe , cestsr komti rakha jbei na ,jotokhn porjonto top software Eingineer hoya jai  ";
     fputs(arr,fp); 
   fclose(fp);
   return 0;


}