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

int n,d,x[100];
vector<int> ans;

int main(){
    cin>>n>>d;

    for(int i=0;i<n;i++) cin>>x[i];

    for(int i=0;i<n;i++){
        int xl = x[i]-d;
        int xr=x[i]+d;

        bool okayl=true;
        bool okayr=true;

        for(int j=0;j<n;j++){
            if(fabs((ll)xl-x[j]) < (ll)d) okayl=false;
            if(fabs((ll)xr-x[j]) < (ll)d) okayl=false;
        }
        if(okayl) ans.pb(xl);
        if(okayr) ans.pb(xr);
    }

    sort(ans.begin(),ans.end());

    int cnt=0;
    int len=ans.size();

    if(len==0)cout<<"0";
    else
    {
        cnt=1;
        for(int i=1;i<len;i++) if(ans[i] !=ans[i-1])cnt++;
        cout<<cnt;
    }
}