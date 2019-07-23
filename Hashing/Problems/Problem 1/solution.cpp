#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int generateBase(const int before, const int after){
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt_rand(seed);
    int base = uniform_int_distribution<int >(before+1, after)(mt_rand);
    return base%2 == 0 ? base + 1 : base;
}

struct PolyHash{
       static const int mod = (int)1e9 + 123;
       static vector<int > pow1;
       static vector<ull > pow2;
       static int base;

       vector<int > pref1, suff1;
       vector<ull > pref2, suff2;

       PolyHash(const string& s)
            : pref1(s.length() + 1u, 0)
            , pref2(s.length() + 1u, 0)
            , suff1(s.length() + 1u, 0)
            , suff2(s.length() + 1u, 0)
        {
           assert(base < mod);
           const int n = s.length();

           while(pow1.size() <= n){
               pow1.push_back(1LL * pow1.back() * base % mod);
               pow2.push_back(pow2.back() * base);
           }

           for(int i = 0; i < n; i++){
           	   assert(s[i] < base);

               //make preffix table
               pref1[i+1] = (pref1[i] + 1LL * s[i] * pow1[i]) % mod;
               pref2[i+1] =  pref2[i] + s[i] * pow2[i];

               //make suffix table
               suff1[i+1] = (suff1[i] + 1LL * s[n - 1 - i] * pow1[i]) % mod;
               suff2[i+1] = pref2[i] + s[n - 1 - i] * pow2[i];
           }



        }

        inline bool operator()(const int left, const int right, const int n) const{

               int len = right - left + 1;

               // for preffix
               int pos = left - 1;
               int preHash1 = (pref1[pos + len] - pref1[pos] + mod) % mod;
               ull preHash2 = pref2[pos + len] - pref2[pos];


               // for suffix;
               int newPos = n - right;
               int suffHash1 = (suff1[newPos + len] - suff1[newPos] + mod) % mod;
               ull suffHash2 = suff2[newPos + len] - suff2[newPos];

               // preform operation for making equations equals
               if(pos != newPos){
                    int diff = abs(newPos - pos);
                    if(pos > newPos){
                        suffHash1 = (suffHash1 * 1LL * pow1[diff]) % mod;
                        suffHash2 *= pow2[diff];
                    }
                    else{
                        preHash1  = (preHash1 * 1LL * pow1[diff]) % mod;
                        preHash2 *= pow2[diff];
                    }
               }

               //cout<<"print first values is : "<<preHash1<<" "<<suffHash1<<"\n";
               //cout<<"print second values is : "<<preHash2<<" "<<suffHash2<<"\n";
               if(preHash1 == suffHash1 ||  preHash2 == suffHash2) return true;
               else return false;
        }
};

int PolyHash::base((int)1e+9 + 7);
vector<int > PolyHash::pow1{1};
vector<ull > PolyHash::pow2{1};

int main(){
    string originalString;
    cout<<"enter the string : "<<"\n";
    cin>>originalString;


    int n = originalString.length();

    PolyHash::base = generateBase(256, PolyHash::mod);

    PolyHash hash(originalString);

    int q;
    cout<<"enter the no of queries : \n";
    cin>>q;
    while(q--){

        cout<<"enter the left and right position of the string : "<<"\n";
        int left, right; cin>>left>>right;

        // print the appropriate answer
        if(hash(left, right, n) == true) cout<<"Given substring is palindrome!!!";
        else cout<<"It is not an palindrome!!!";
        cout<<"\n";

    }
    return 0;
}

