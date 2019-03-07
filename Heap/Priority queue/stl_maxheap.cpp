// make_heap() function is only used when we don't want ot insert element after creating heap

#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int > vi = {123,123,234,456,234,567,123,45,678};

    cout<<"Before creating the heap \n";
    for(int i = 0;i<vi.size();i++){
        cout<<vi[i]<<" ";
    }

    make_heap(vi.begin(),vi.end());
    cout<<endl;
    cout<<"Sfter creating the heap \n";
    for(int i = 0;i<vi.size();i++){
        cout<<vi[i]<<" ";
    }
    cout<<endl;

    vi.push_back(590);

    cout<<"After inserting the new element \n";
    for(int i = 0;i<vi.size();i++){
        cout<<vi[i]<<" ";
    }

    make_heap(vi.begin(),vi.end());

    cout<<"After creating again heap \n";
    for(int i = 0;i<vi.size();i++){
        cout<<vi[i]<<" ";
    }
    return 0;
}
