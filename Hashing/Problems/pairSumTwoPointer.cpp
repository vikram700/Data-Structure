
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
     cin>>n>>k;
     int a[n];
     for(int i = 0; i < n; i++) cin>>a[i];
     sort(a,a+n);
     int left = 0, right = n-1;
     while(left < right){
         if(a[left]+a[right] > k) right--;
         else if(a[left]  + a[right] < k) left++;
         else{
             cout<<"YES";
             return 0;
         }
     }
     cout<<"NO\n";
     return 0;
}
