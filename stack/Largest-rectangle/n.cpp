#include<bits/stdc++.h>

using namespace std;

int max_area(vector<int >v){
    stack<int >s;

    int tp;
    int max_area = 0;
    int area_with_top;
    int i=0;
    while(i < v.size()){
          if(s.empty() || v[s.top()] <= v[i]){
            s.push(i++);
          }

          else{
            tp = s.top();
            s.pop();


            area_with_top = v[tp] *(s.empty() ? i : (i - s.top() -1));

            max_area = max(max_area,area_with_top);
          }

    }

    while(!s.empty()){
        tp = s.top();
        s.pop();

        area_with_top = v[tp] * (s.empty() ? i : (i - s.top() -1));
        max_area = max(max_area,area_with_top);
    }

    return max_area;
}
int main(){
    int n;
    cin>>n;
    vector<int >v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    cout<<max_area(v)<<"\n";
    return 0;

}
