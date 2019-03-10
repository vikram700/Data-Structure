#include <bits/stdc++.h>

using namespace std;
long long int n;
long long int mod = 1000000007;
long long int arr[100011];
long long int size[100011];
bool visited[100011];
vector<long long int> v[100011];

long long int choice3(int n) {
  long long int res = 1;
  for (int i = n - 2; i <= n; i++) {
    res *= i;
  }
  return res / 6;
}

long long int choice2(int n) {
  long long res = 1;
  for (int i = n - 1; i <= n; i++) {
    res *= i;
  }
  return res / 2;
}

long long int BFS(int start) {
  long long int result = 0;
  int count = 0;
  queue<int> q;
  q.push(start);
  visited[start] = true;
  count++;
  while (!q.empty()) {
    int temp = q.front();
    q.pop();
    for (int i = 0; i < v[temp].size(); i++) {
      if (!visited[v[temp][i]]) {
        count++;
        visited[v[temp][i]] = true;
        q.push(v[temp][i]);
      }
    }
  }
  long long int choice_3 = choice3(count);
  long long int choice_2 = choice2(count) * (n - count);

  return (choice_3 + choice_2);
}
void initialize() {
  for (int i = 1; i <= n; i++) {
    arr[i] = i;
    size[i] = 1;
    visited[i] = false;
  }
}

int root(int i) {
  while (arr[i] != i) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}

void insert_union(int A, int B) {
  int root_A = root(A);
  int root_B = root(B);

  if (size[root_A] <= size[root_B]) {
    arr[root_A] = root_B;
    size[root_B] += size[root_A];

  } else {
    arr[root_B] = root_A;
    size[root_A] += size[root_B];
  }
}

int main() {
  cin >> n;

  initialize();


  for (int i = 1; i < n; i++) {
    int a, b;
    char ch;
    cin >> a >> b >> ch;
    if (ch == 'b') {
      insert_union(a, b);
      v[a].push_back(b);
      v[b].push_back(a);
    }
  }

  long long int result = choice3(n);
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      result -= BFS(i);
    }
  }
  cout << result%mod << "\n";
  return 0;
}
