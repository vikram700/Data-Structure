#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int generateBase(const int before, const int after){
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed ^ ull(new ull));
    uniform_int_distribution<int >dist(before + 1, after);
    int base = dist(gen);

    return base % 2 == 0 ? base + 1 : base; 
}

struct HashTable{
    static const int mod = 2000177;

    const int step;

    array<ull, mod> data;
 
    inline int get_hash(ull value) const {
        return int((value + step) % mod);
    }
    
    HashTable() : step(generateBase(mod/10, mod)){
        for(auto &it : data) it = 0;
    }


    void insert(ull value){
        int hash = get_hash(value);
        while(true){
            if(data[hash] == value) return;

            if(data[hash] == 0){
                data[hash] = value;
                return;
            }

            hash += step;
            if(hash >= mod) hash -= mod;

        }
    }

    bool search(ull value) const{
        int hash = get_hash(value);
        while(true){
            if(data[hash] == value) return true;

            if(data[hash] == 0) break;

            hash += step;
            if(hash >= mod) hash -= mod;

        }
        return false;
    }
};


struct PolyHash{
    // -------- Static variables --------
    static const ull mod = (ull(1) << 61) - 1; // prime mod of hashing
    static int base;                           // odd base of hashing
    static std::vector<ull> pow;               // powers of base modulo mod;
 
    // -------- Static functions --------
    static inline ull add(ull a, ull b) {
        // Calculate (a + b) % mod, 0 <= a < mod, 0 <= b < mod
        return (a += b) < mod ? a : a - mod;
    }
 
    static inline ull sub(ull a, ull b) {
        // Calculate (a - b) % mod, 0 <= a < mod, 0 <= b < mod
        return (a -= b) < mod ? a : a + mod;
    }
 
    static inline ull mul(ull a, ull b){
        // Calculate (a * b) % mod, 0 <= a < mod, 0 <= b < mod
        ull l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
        ull l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
        ull ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
        ret = (ret & mod) + (ret >> 61);
        ret = (ret & mod) + (ret >> 61);
        return ret-1;
    }
 
    // -------- Variables of class --------
    std::vector<ull> pref; // polynomial hash on prefix
 
    // Constructor from string:
    PolyHash(const std::string& s) 
        : pref(s.size()+1u, 0) 
    {
        // Pre-calculate powers of base:
        while (pow.size() <= s.size()) {
            pow.push_back(mul(pow.back(), base));
        }
        // Calculate polinomial hash on prefix:
        for (int i = 0; i < (int)s.size(); ++i) {
            pref[i+1] = add(mul(pref[i], base), s[i]);
        }
    }
 
    // Get hash from [pos, pos+len-1] segment of string
    inline ull operator()(const int pos, const int len) const {
        return sub(pref[pos+len], mul(pref[pos], pow[len]));
    }

};


// Init static variables of class PolyHash:
int PolyHash::base((int)1e9+7);
std::vector<ull> PolyHash::pow{1};
 
// Solve problem using binary search and hash table in O(n log(n)):
int solve(const std::string& s, const std::string& t) {    
    // Pre-calculate hash:
    PolyHash hash_s(s), hash_t(t);
    // Binary search by len:
    int low = 0, high = std::min((int)s.size(), (int)t.size())+1;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        // Insert all hashes of segments length mid of string s:
        HashTable hashes;
        for (int i = 0; i + mid - 1 < (int)s.size(); ++i) {
            hashes.insert(hash_s(i, mid));
        }
        // Search all hashes of segments length mid of string t:
        bool success = false;
        for (int i = 0; i + mid - 1 < (int)t.size(); ++i) {
            if (hashes.search(hash_t(i, mid))) {
                success = true;
                break;
            }
        }
        if (success) low = mid; else high = mid;
    }
    return low;
}

int main(){
    string s, t;
    cin>>s>>t;

    PolyHash::base = generateBase(256,2e9);
    cout<<solve(s, t)<<"\n";
    return 0;
}