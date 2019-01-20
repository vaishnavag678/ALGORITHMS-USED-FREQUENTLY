#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
bool visited[100005];
vector<ll> v[100005];
ll indegree[100005];
ll n,m;


bool cycle(ll x,ll parent)
{
	visited[x]=1;
	for(ll i=0;i<v[x].size();i++)
	{
		ll y=v[x][i];
		if(!visited[y])
			{
				if(cycle(y,x))
				return true;
			}
		else if(y!=parent)
			{
				return true;
			}
	}
	
	//cout<<"vessi";
	return false;
}
 int main()
 {
 	cin>>n>>m;
 	ll x,y,i;
 	for( i=1;i<=m;i++)
 	{
 		cin>>x>>y;
		 v[x].push_back(y);
		 v[y].push_back(x);	
	}
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			//cout<<i<<"\n";
			if(cycle(i,i))
			{
				cout<<"yes";
				return 0;
			}
		}
	}
	cout<<"no";
	return 0;
 }
