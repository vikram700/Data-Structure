#include<bits/stdc++.h>

using namespace std;


int generateBase(const int before, const int after){
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 mt_rand(seed);
	int base = uniform_int_distribution<int >(before+1, after)(mt_rand);
	return base%2 == 0 ? base - 1 : base;
}

vector<int > robinKarp(const string& t, const string& p){
	int mod = 1e9 + 123;
    int base = generateBase(256, (int)1e9 + 7);

    int n = t.length(), m = p.length();
    vector<unsigned long long > pow{1};
    while(pow.size() <= n){
        pow.push_back(1LL * base * pow.back() % mod);
    }

    vector<int > pref(n + 1u, 0);
    for(int i = 0; i < n; i++){
        pref[i+1] = (pref[i] + 1LL * t[i] * pow[i]) % mod;
    }

    int need = 0;
    for(int i = 0; i < m; ++i){
        need = ( need + 1LL * pow[i] * p[i]) % mod;
    }

    vector<int >res;
    for(int i = 0; i + p.length() <= t.length(); i++){
         long long cur_h = (pref[i+m] + mod - pref[i]) % mod;
        if (cur_h == need * pow[i] % mod)
            res.push_back(i+1);
    }

    return res;
}


int main(){
    int t; cin>>t;
    while(t--){
        string t, p;
        cin>>t>>p;
        vector<int >res = robinKarp(t, p);
        if(res.size() == 0){
        	cout<<"Not Found\n";
        }
        else{
        	cout<<res.size()<<"\n";
        	for(auto it : res) cout<<it<<" ";
        	cout<<"\n";
        }

        cout<<"\n";
    }
    return 0;
}
