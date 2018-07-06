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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m,i,j,k,flag=0,a[200005],next[200005];
    set<ll> S[200005],les,mor;
    slitr itr,itr1,itr2;
    cin>>n>>m;
    k=n/m;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        j=a[i]%m;
        S[j].insert(i);
    }
    for(i=0;i<n;i++)
    {
    	next[i]=-1;
    }
    vl prev_mor;
    for(j=0;j<m;j++)
    {
    	if(S[j].size()>k)
    	{
           mor.insert(j);
           prev_mor.pb(j);
    	}
    	else if(S[j].size()<k)
    	{
    		les.insert(j);
    		for(i=0;i<prev_mor.size();i++)
    		{
    			next[prev_mor[i]]=j;
    		}
            prev_mor.clear();
    	}
    }
    ll count=0;
    for(itr=mor.begin();itr!=mor.end();itr++)
    {
    	ll jmor=*itr;
    	for(;S[jmor].size()!=k;)
    	{
    		itr1=S[jmor].begin();
            i=*itr1;
            flag=0;//cout<<i<<endl;
            	//cout<<" "<<jles<<endl;
            	if(next[jmor]!=-1 && les.find(next[jmor])!=les.end())
            	{
            		ll jles=next[jmor];
                    count+=(jles-jmor);
                    a[i]+=(jles-jmor);
                    S[jmor].erase(i);
                    S[jles].insert(i);
                    if(S[jles].size()==k)
                    {
                    	les.erase(jles);
                    }
            	
            }
            else
            {
            	itr2=les.begin();
            	while(*itr2<jmor)
            	{
            		itr2++;
            	}
            	ll jles=*itr2;
            	count+=(jles-jmor+m);
                    a[i]+=(jles-jmor+m);
                    S[jmor].erase(i);
                    S[jles].insert(i);
                    if(S[jles].size()==k)
                    {
                    	les.erase(jles);
                    }
            }
    	}

    }
    cout<<count<<endl;

    for(i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
    }

   return 0;
}