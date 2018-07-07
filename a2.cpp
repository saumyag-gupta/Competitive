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

    ll n,m,i,j,k,flag=0,x,y,xx,yy;
    vll conb,cone;

    vl v,w;
    
    cin>>n>>xx>>yy;
    
    for(i=0;i<n;i++)
    {
        cin>>x>>y;conb.pb({x,y});cone.pb({y,x});
    }

    for(i=0;i<xx;i++)
    {
        cin>>x;v.pb(x);
    }

    for(i=0;i<yy;i++)
    {
        cin>>x;w.pb(x);
    }

    sort(conb.begin(),conb.end());
    sort(cone.begin(),cone.end());
    sort(v.begin(),v.end());
    sort(w.begin(),w.end());

    vll itr it;vl itr vit,wit;

    vit=v.begin();
    wit=w.begin();

    mll time;

    for(it=conb.begin();it!=conb.end();it++)
    {
        ll st=it->ff;
        while((*vit)<=st)
        {
            vit++;
            if(vit==v.end())break;
        }
        if(vit!=v.begin()){
        vit--;
        ll ans=1-(*vit);
        time[st]=ans;
        }   
    }

    for(it=cone.begin();it!=cone.end();it++)
    {
        ll en=it->ff;
        ll st=it->ss;

        while((*wit)<en && wit!=w.end())
        {
            wit++;
            if(wit==w.end())break;
        }

        if(wit!=w.end() && time.find(st)!=time.end())
        {
            ll ans=*wit;
            time[st]+=ans;
        }
        else if(time.find(st)!=time.end())
        {
            time[st]=INT_MAX;
        }
    }

    mll itr mall;ll mi=INT_MAX;

    for(mall=time.begin();mall!=time.end();mall++)
    {
        if(mall->ss < mi)mi=mall->ss;

    }

    cout<<mi;

   return 0;
}