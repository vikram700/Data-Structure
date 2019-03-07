/* this problem is based on 3 problem on hacker rank

*/

#include <bits/stdc++.h>

using namespace std;

struct compare{
     bool operator()(const pair<int,int>& a, const pair<int,int>& b){
         return (a.first > b.first);
     }

};
int main() {

  long long n;
  cin >> n;
  vector<pair<long long, long long>> v;
  v.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }

  sort(v.begin(), v.end());
  priority_queue < pair<long long, long long>, vector<pair<long long, long long>>,
      compare> pq;
  long long i = 1;
  long long w = 0;
  long long cur_time = v[0].first;
  pq.push(make_pair(v[0].second, v[0].first));
  while (!pq.empty() || i < n) {

    while (i < n && v[i].first <= cur_time) {
      pq.push(make_pair(v[i].second, v[i].first));
      i++;
    }

    if (pq.empty() && i < n) {
      cur_time = v[i].first;
      pq.push(make_pair(v[i].second, v[i].first));
      i++;

    }

    pair<long long, long long> p = pq.top();
    pq.pop();

    cur_time += p.first;
    w += (cur_time - p.second);
  }

  cout << w / n << "\n";
  return 0;
}
