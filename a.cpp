#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define pf push_front
#define f first
#define s second
#define MOD 1000000007

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
    return power(n, p-2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
ll nCr(ll n, ll r, ll p)
{
   // Base case
   if (r==0)
      return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    ll fac[n+1];
    fac[0] = 1;
    for (ll i=1 ; i<=n; i++)
        fac[i] = fac[i-1]*i%p;
 
    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
{
    ll n,m,i,j,k,flag=0,a,b;
    vector<ll> l,r;
    cin>>n>>k;
    
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        l.pb(a);r.pb(b);
    }

    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    map<ll , ll > nc;
    nc[k-1]=1;
    for(i=k;i<n;i++)
    {
        nc[i]=nCr(i,k-1,MOD);
    }
    ll tot=nCr(n,k,MOD);
    ll count=0;
    ll curr=l[0];count=1;
    i=1;j=0;
    while(i<n)\
    {
       curr=min(l[i],r[j]);

       if(curr==l[i])
       {
        i++;
        count++;
       }
       else
       {
        j++;
        if(count>=k)
        {
            tot-=(nc[count-1]);
            if(tot<0)tot+=MOD;
        }
        count--;
       }
    }
    while(j<n)
    {
      j++;
      if(count>=k)
        {
            tot-=(nc[count-1]);
            if(tot<0)tot+=MOD;
        }
        count--;
    }

    cout<<tot<<endl;
}
   return 0;
}