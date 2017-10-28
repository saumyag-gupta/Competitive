#include <iostream>
using namespace std;
#include<algorithm>

#define ll long long int
#define pb push_back
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,i,j,k,flag=0,a[10005];
    
    cin>>n;
    
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
    }

    sort(a,a+n);
    ll count=0;
    for(k=0;k<n-1;k++)
    {
    	i=k;j=k+1;
    	if(a[k-1]==a[k])
    	{
    		count++;
    		continue;
    	}
    	while(i>=0 && j<n)
    {	if(a[i]+a[j]==2*a[k])
    	{
    		count++;
    		break;
    	}
    	else if(a[k]-a[i]<a[j]-a[k])
    	 i--;
    	else
    	 j++;
    }
    	 
    }
cout<<count;
   return 0;
}