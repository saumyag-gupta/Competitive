#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define pll pair<ll,ll>
#define vl vector<ll>
#define vll vector < pll >
#define sl set<ll>
#define mll map<ll,ll>
#define itr :: iterator
#define pf push_front
#define ff first
#define ss second
#define stkl stack <ll>
#define quel queue <ll>
#define pquel priority_queue <ll>
#define rep(i,n) for(i=0;i<n;i++)
#define MOD 1000000007
#define PRIME 1000000007 // For mod inverse and binary exponentiation

struct edge {
    ll A;
    ll B; 
};

ll power(ll a, ll b, ll mod){
    ll x = 1, y = a;
    while (b > 0){
        if (b%2){
            x = (x*y)%mod;
        }
        y = (y*y)%mod;
        b /= 2;
    }
    return x%mod;
}   
 
ll modular_inverse(ll n, ll mod){
    return power(n, mod-2, mod);
}


bool edgecompare(edge lhs, edge rhs) { if(lhs.B!=rhs.B)return lhs.B < rhs.B;
else return lhs.A<rhs.A;}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m,i,j,k,flag=0,x;
    vl a;
    
    cin>>n;
    
    rep(i,n)
    {
        cin>>x;a.pb(x);
    }

   return 0;
}