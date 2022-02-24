#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <chrono>
#include <complex>
using namespace std;
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define mp                   make_pair
#define eb                   emplace_back
#define pb                   push_back
#define pf                   push_front
#define popb                 pop_back
#define popf                 pop_front
#define hashmap              unordered_map
#define hashset              unordered_set
#define lb                   lower_bound
#define ub                   upper_bound
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define ff                   first
#define ss                   second
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define fok(n) for(int k=0;k<n;k++)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,b,a) for(ll i=b;i>=a;i--)
#define repk(i,a,b,k) for(ll i=a;i<b;i=i+k)
#define graph          vector<vector<ll>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair< ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string>       vs;
typedef  vector<char>          vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>          mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  map<int, string>      mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
// ll ceils(ll x, ll y) {
//  return x / y + ((x % y) != 0);
// }
// ll gcd(ll a, ll b) {
//  if (b == 0)
//   return a;
//  else
//   return gcd(b, a % b);
// }

// ll power(ll x, ll y)
// {
//     ll res = 1;
//     while (y){
//         if (y % 2 == 1){
//             res = (res * x);
//         }
//         y = y >> 1;
//         x = (x * x);
//     }
//     return res;
// }

// ll modpower(ll x, ll y){
//     ll res = 1;
//     x = x % MOD;
//     if (x == 0){
//         return 0;
//     }
//     while (y > 0){
//         if (y & 1){
//             res = (res*x) % MOD;
//         }
//         y = y>>1;
//         x = (x*x) % MOD;
//     }
//     return res;
// }

// ll lcm(ll a, ll b) {
//  return a / gcd(a, b) * b;

// }
// ll powmod(ll x, ll y) {
//  ll res = 1;
//  for (ll i = 0; i < y; i++) {
//   res = res * x % MOD;
//  }
//  return res;
// }
// bool isPrime(ll n)
// {
//  if (n <= 1)
//   return false;
//  if (n <= 3)
//   return true;
//  if (n % 2 == 0 || n % 3 == 0)
//   return false;

//  for (ll i = 5; i * i <= n; i = i + 6)
//   if (n % i == 0 || n % (i + 2) == 0)
//   return false;

//  return true;
// }
bool COMP(pair<string, int> l, pair<string, int> r) {
 return l.ss < r.ss;
}

// string decToBinary(ll n, ll l) 
// { 
//     // array to store binary number 
//     int binaryNum[l]={0}; 
  
//     // counter for binary array 
//     int i = 0; 
//     while (n > 0) { 
  
//         // storing remainder in binary array 
//         binaryNum[i] = n % 2; 
//         n = n / 2; 
//         i++; 
//     }
//     string s;
//     rev(i,l-1,0){
//         if(binaryNum[i]){
//             s += '1';
//         }
//         else{
//             s += '0';
//         }
//     }
//     return s;
// }

void solve(){
    ll c,p;
    cin>>c>>p;
    map<string, map<string, ll>> m;
    map<string, bool> e;
    foi(c){
        string s;
        cin>>s;
        ll n;
        cin>>n;
        e[s] = 1;
        foj(n){
            string nm;
            cin>>nm;
            ll g;
            cin>>g;
            map<string, ll> f;
            f[nm] = g;
            m[s][nm] = g;
        }
    }
    map<string, ll> days;
    vector<pair<string, ll>> bb, sc;
    map<string, map<string, ll>> req;
    foi(p){
        string name;
        cin>>name;
        ll d,s,b,r;
        cin>>d>>s>>b>>r;
        days[name] = d;
        bb.pb(mp(name, b));
        sc.pb(mp(name, s));
        foj(r){
            string nm;
            cin>>nm;
            ll g;
            cin>>g;
            map<string, ll> f;
            f[nm] = g;
            req[name][nm] = g;
        }
    }
    sort(all(bb), COMP);
    map<string, vector<string>> ans;
    foi(p){
        string pre = bb[i].ff;
        map<string, ll> gg;
        ll len=0;
        for(auto j : req[pre]){
            len++;
            string nam = j.ff;
            ll re = j.ss;
            ll mini = INT_MAX;
            string anss;
            // bool inc=0;
            for(auto k : m){
                map<string, ll> res= k.ss;
                if(res[nam] > re){
                    // mini = min(mini, res[nam]);
                    if(mini > res[nam]){
                        mini = res[nam];
                        anss = k.ff;
                    }
                }
                else if(res[nam]==re || res[nam]==(re-1)){
                    // mini = min(mini, res[nam]);
                    if(mini > res[nam]){
                        mini = res[nam];
                        anss = k.ff;
                        gg[k.ff] = 1;
                    }
                    // inc=1;
                    // anss = k.ff;
                }
            }
            if(mini!=INT_MAX){
                ans[pre].pb(anss);
            }
        }
        if(sz(ans[pre])==len){
            ll ji=0;
            for(auto j : req[pre]){
                string de = j.ff;
                // ji++;
                if(gg[ans[pre][ji]]){
                    m[ans[pre][ji]][de]++;
                }
                ji++;
            }
        }
        else{
            if(sz(ans[pre])>0){
            ans[pre].clear();
            }
        }
    }
    ll dd = 0;
    for(auto i : ans){
        dd++;
    }
    cout<<dd<<"\n";
    for(auto i : ans){
        cout<<i.ff<<"\n";
        foj(sz(i.ss)){
            cout<<i.ss[j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}