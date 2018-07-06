#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
{
    ll n,m,i,j,k,flag=0,a[100005];
    string str;
    map<ll , ll > Map;
    set<ll> Set;
    set<ll,greater<ll> >  :: iterator itr;
    cin>>n;
    
    for(i=0;i<n;i++)
    {
    	
    }


}
   return 0;
}