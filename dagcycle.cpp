#include<bits/stdc++.h>
#define ll long long int 

using namespace std;
ll n,m;
vector<ll>v[1000005],bc;
bool visited[100005],restack[100005];
ll indegree[100005];
bool cycle(ll x)
{
	if(visited[x]==false)
	{
		visited[x]=true;
		restack[x]=true;
		
		for(ll i=0;i<v[x].size();i++)
		{
			ll y=v[x][i];
			if(!visited[y]&&cycle(y))
			return true;
			else if(restack[y])
			return true;
		}
	}
	restack[x]=false;
	return false;
}
int main()
{
	ll x,y;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		indegree[y]++;
	}
	for(i=1;i<=n;i++)
	{
		if(cycle(i))
		{
			cout<<"yes";
			return 0;
		}
	}
	
}
