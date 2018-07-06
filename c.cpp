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
    cout.tie(NULL);

    ll n,m,i,j,k,flag=0,a[100005],lit=0,unlit=0;
    string str;
    map<ll , ll > Map;
    set<ll> Set;
    cin>>n>>m;

    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    a[n+1]=m;
    a[0]=0;
    ll ans=0;
    ll state=0;
    for(i=1;i<=n+1;i++)
    {
        if(i%2==1)
        {
            lit+=(a[i]-a[i-1]);
        }
        else
        {
            unlit+=(a[i]-a[i-1]);
        }
    }
    ll mal=lit,mul=unlit;
    if(n%2==0)state=1;
    else state=0;

    lit=0;unlit=0;
    ll ma=(unlit-lit),index=-1;


    for(i=n;i>=0;i--)
    {
        if(state)
        {
            lit+=a[i+1]-a[i];
            state=0;
        }
        else
        {
            unlit+=a[i+1]-a[i];
            state=1;
        }

        if((unlit-lit)>ma){
            ma=(unlit-lit);index=i;
        }
    }
    if(index!=-1)
    cout<<ma+mal-1;
else
    cout<<mal;

   return 0;
}