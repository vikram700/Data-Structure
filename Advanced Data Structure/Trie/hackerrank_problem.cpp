#include <bits/stdc++.h>

using namespace std;

struct trienode {
  trienode *childs[26];
  int data;
};

struct trienode *getNode() {
  trienode *temp = new trienode;

  temp->data = 0;

  for (int i = 0; i < 26; i++) {
    temp->childs[i] = nullptr;
  }
  return temp;
}

void insert_string(trienode *root, string s) {

  trienode *temp = root;
  temp->data+=1;
  for (int i = 0; i < s.length(); i++) {
    int index = s[i] - 'a';

    if (!temp->childs[index])
      temp->childs[index] = getNode();
    temp = temp->childs[index];
    temp->data+=1;
  }

}

int find(trienode *root, string s) {
  trienode *temp = root;
  for (int i = 0; i < s.length(); i++) {

    int index = s[i] - 'a';
    if (!temp->childs[index])
      return 0;
    temp = temp->childs[index];
  }
  return temp->data;
}
int main() {
  int n;
  cin >> n;

  struct trienode* root = getNode();
  while(n--){
      string s,s1;
      cin>>s>>s1;
      if(s == "add"){
          insert_string(root, s1);
      }
      else{
          cout<<find(root,s1)<<"\n";
      }
  }

  return 0;
}
