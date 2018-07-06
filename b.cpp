#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define pll pair<ll,ll>
#define vl vector<ll>
#define vll vector < pll >
#define sl set<ll>
#define mll map<ll,ll>
#define slitr set<ll,greater<ll> >  :: iterator
#define mllitr map <ll, ll> :: iterator itr;
#define pf push_front
#define f first
#define s second
#define MOD 1000000007

struct edge {
    ll A;
    ll B; 
};

bool edgecompare(edge lhs, edge rhs) { if(lhs.B!=rhs.B)return lhs.B < rhs.B;
else return lhs.A<rhs.A;}

vl primeFactors(ll n)
{
  vl a;
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        a.pb(2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
          a.pb(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        a.pb(n);

      return a;
}

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
    cout.tie(NULL);

    ll n,m,i,j,k,l,r,x,y;
    vl xp,yp;
    cin>>l>>r>>x>>y;
    sl s;
    s.clear();
    if(x==y && x>=l && x<=r)
    {
      cout<<"1";
      return 0;
    }
    xp=primeFactors(x);
    yp=primeFactors(y);
    m=yp.size()-xp.size();
    
    sort(yp.begin(),yp.end());
    sort(xp.begin(),xp.end());
    i=0;j=0;

    while(i<yp.size() && j<xp.size())
    {
      if(xp[j]==yp[i])
      {
         xp.erase(xp.begin()+j);
         vector<ll>::iterator it;it=yp.begin();
         yp.erase(it+i);
      }
      else if(yp[i]<xp[j])
         i++;
       else j++;
      
    }
    if(!xp.empty())
    {
      cout<<"0";
      return 0;
    }
    m=0;ll mi=x;ll ma=y/x;
    for(i=0;i<yp.size();i++)
    {
         if(s.find(yp[i])==s.end())
         {
          if(mi>=l && mi<=r && ma>=l && ma<=r)
            m++;
          s.insert(yp[i]);
         }

      mi*=yp[i];
      ma=y/mi;ma*=x;
    }
    if(m==0)cout<<"0";
    else
    cout<<pow(2,m);
   return 0;
}