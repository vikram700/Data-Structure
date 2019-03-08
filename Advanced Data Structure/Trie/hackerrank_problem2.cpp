#include <bits/stdc++.h>

using namespace std;

struct trienode {
  struct trienode *childs[26];
  bool terminate;
};

struct trienode *getNode() {
  struct trienode *node = new trienode;
  node->terminate = false;
  for (int i = 0; i < 26; i++) {
    node->childs[i] = nullptr;
  }
  return node;
}

int insert_string(trienode *root, string s) {
  struct trienode *temp = root;

  for (int i = 0; i < s.length(); i++) {

    int index = s[i] - 'a';
    if (!temp->childs[index])
      temp->childs[index] = getNode();

    temp = temp->childs[index];
    if(temp->terminate == true ) return 1;
  }
  temp->terminate = true;
  for(int i=0;i<26;i++){
      if(temp->childs[i]){
          return 1;
      }
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  string s;
  struct trienode *root = getNode();

  for (int i = 0; i < n; i++) {
    cin >> s;
    int x = insert_string(root, s);
    if (x) {
      cout << "BAD SET\n";
      cout << s << "\n";
      return 0;
    }
  }
  cout << "GOOD SET\n";
  return 0;
}
