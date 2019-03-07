// creating min_heap using make_heap() function

#include<bits/stdc++.h>

using namespace std;


struct greaters{
  bool operator() (const long& a,const long& b) const{
     return a>b;
  }
};
int main(){

    vector<int > vi = {123,234,345,456,567,23,43,56,67,79,234};

    cout<<"print the vector before creating heap \n";
    for(int i = 0;i<vi.size();i++){
        cout<<vi[i]<<" ";
    }
    cout<<"\n";

    make_heap(vi.begin(),vi.end(),greaters());

    cout<<"print the vector after creating heap \n";
    for(int i = 0;i<vi.size();i++){
        cout<<vi[i]<<" ";
    }
    cout<<"\n";

    vi.push_back(1);

    cout<<"print the heap after adding new node \n";
    for(int i = 0;i<vi.size();i++){
        cout<<vi[i]<<" ";
    }

    make_heap(vi.begin(),vi.end(),greaters());

    cout<<"print the heap after creating heap again \n";
    for(int i = 0;i<vi.size();i++){
        cout<<vi[i]<<" ";
    }

    cout<<"\n";
    cout<<"the min element is : "<<vi.front()<<"\n";
    return 0;
}
