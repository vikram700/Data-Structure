/* 
     Problem No : 1517  freedom of choice
     
     Times online judge
*/

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
	// -------- static variables --------------
	static const int mod = (int)1e9+123;
	static vector<int > pow1;
	static vector<ull > pow2;
	static int base;

	// --------- Static functons --------
    static inline int diff(int a, int b) { 
    	// Diff between `a` and `b` modulo mod (0 <= a < mod, 0 <= b < mod)
        return (a -= b) < 0 ? a + mod : a;
    }

    // -------- Variables of class--------------
    vector<int > pref1;
    vector<ull > pref2;

    // ---------- constructor of class --------------
    PolyHash(const string& s)
       : pref1(s.size() + 1u, 0)
       , pref2(s.size() + 1U, 0)
    {
    	assert(base < mod);
        const int n = s.size(); // Firstly calculated needed power of base:
        while ((int)pow1.size() <= n) {
            pow1.push_back(1LL * pow1.back() * base % mod);
            pow2.push_back(pow2.back() * base);
        }
        for (int i = 0; i < n; ++i) { // Fill arrays with polynomial hashes on prefix
            assert(base > s[i]);
            pref1[i+1] = (pref1[i] + 1LL * s[i] * pow1[i]) % mod;
            pref2[i+1] = pref2[i] + s[i] * pow2[i];
        }
    }


    // Polynomial hash of subsequence [pos, pos+len)
    // If mxPow != 0, value automatically multiply on base in needed power. Finally base ^ mxPow
    inline std::pair<int, ull> operator()(const int pos, const int len, const int mxPow = 0) const {
        int hash1 = pref1[pos+len] - pref1[pos];
        ull hash2 = pref2[pos+len] - pref2[pos];
        if (hash1 < 0) hash1 += mod;
        if (mxPow != 0) {
            hash1 = 1LL * hash1 * pow1[mxPow-(pos+len-1)] % mod;
            hash2 *= pow2[mxPow-(pos+len-1)];
        }
        return std::make_pair(hash1, hash2);
    }
};


int PolyHash::base((int)1e9+7);
vector<int > PolyHash::pow1{1};
vector<ull > PolyHash::pow2{1};

int main(){
	int n; cin>>n;
    string a,b; cin>>a>>b;

    PolyHash::base = generateBase(256, PolyHash::mod);

    const int maxPow = max(a.length(), b.length());

    // Create hashing objects from strings:
    PolyHash hash_a(a), hash_b(b);
 
    int pos = -1, low = 0, high = min(a.length(), b.length()) + 1;
    while(high - low > 1){
        int mid = (low + high)/2;

        vector<pair<int, ull> > hashes;

        for(int i = 0; i + mid <= n; i++){
        	hashes.push_back(hash_a(i, mid, maxPow));
        }

        sort(hashes.begin(), hashes.end());

        int p = -1;
        for(int i = 0; i + mid <= n; i++){
        	if(binary_search(hashes.begin(), hashes.end(), hash_b(i, mid, maxPow))){
        		p = i;
        		break;
        	}
        }

        if(p >= 0){
        	low = mid;
        	pos = p;
        }
        else {
        	high = mid;
        }
    }

    assert(pos >= 0);

    cout<<(b.substr(pos, low).c_str())<<"\n";  
	return 0;
}