#include<bits/stdc++.h>
#define SIZE 2*100000+10
using namespace std;
int main(){

      int i,j,k,t,n,x;
      scanf("%d",&t);

      while(t--) {
         int a[SIZE]={0};    
         scanf("%d",&n);
         for(i=0;i<n;i++) {
             scanf("%d",&x);
             if(x>=0)
               a[x]=1;    // non negative numbers are hashed from 0 to 10^5

            else
               a[100000+abs(x)]=1;  // Negative numbers are hashed from  10^5 to 2*10^5

          }

          scanf("%d",&k);

          for(i=0;i<k;i++){

             scanf("%d",&x);
             if(x>=0){

                 if(a[x]==1)
                    printf("Yes\n");
                else
                   printf("No\n");

             }
            else{
                if(a[100000+abs(x)]==1)  
                     printf("Yes\n");
                else
                    printf("No\n");

           }

      }
  }

  return 0;
  
}