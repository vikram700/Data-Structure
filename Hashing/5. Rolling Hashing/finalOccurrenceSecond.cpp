#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int generateBase(const int before, const int after){
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 mt_rand(seed);
	int base = uniform_int_distribution<int >(before+1, after)(mt_rand);
	return base%2 == 0 ? base - 1 : base;
}

struct PolyHash{
	static const int mod = (int)1e9+123;
	static vector<int > pow1;
	static vector<ull > pow2;
	static int base;

	static inline int diff(int a, int b){
		return (a-=b < 0 ? a + mod : a);
	}

	vector<int >pref1;
	vector<ull >pref2;

	PolyHash(const string& s): pref1(s.size()+1u, 0), pref2(s.size()+1u, 0)
	{
		assert(base < mod);
		const int n = s.size();

		while(pow1.size() <= n){
			pow1.push_back(1LL * pow1.back() * base % mod);
			pow2.push_back(pow2.back() * base);
		}

		for(int i = 0; i < n ; ++i){
			assert(base > s[i]);
			pref1[i+1] = (pref1[i] + 1LL * s[i] * pow1[i])%mod;
			pref2[i+1] = pref2[i] + s[i] * pow2[i];
		}
	}


	inline pair<int, ull> operator()(const int pos, const int len, const int maxPow = 0) const{
		int hash1 = pref1[pos + len] - pref1[pos];
		ull hash2 = pref2[pos + len] - pref2[pos];
		if(hash1 < 0) hash1 += mod;
		if(maxPow != 0){
			hash1 = 1LL * hash1 * pow1[maxPow - (pos+len-1)] % mod;
			hash2 *= pow2[maxPow - (pos + len - 1)];
		}
		return make_pair(hash1, hash2);
	}

};

int PolyHash::base((int)1e9+7);
vector<int > PolyHash::pow1;
vector<ull > PolyHash::pow2;

void findOccurrence(){
	PolyHash::pow1.push_back(1); PolyHash::pow2.push_back(1);

    string a,b; cin>>b>>a;

    const int maxPow = max(a.length(), b.length());

    PolyHash::base = generateBase(256, PolyHash::mod);

    PolyHash hash_a(a), hash_b(b);

    const auto need = hash_b(0, (int)b.length(), maxPow);

    vector<int > res;
    for(int i = 0; i + (int)b.length() <= (int)a.length(); ++i){
    	if(hash_a(i, b.length(), maxPow) == need){
    		res.push_back(i);
    	}
    }

    if(res.size() == 0) cout<<" "<<"\n";
    else{
    	for(auto it : res) cout<<it<<"\n";
    }

    PolyHash::pow1.clear();
    PolyHash::pow2.clear();
}


int main(){
	int t;
	while(cin >> t){
        findOccurrence();
	}
	return 0;
}
