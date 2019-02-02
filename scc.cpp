#include<bits/stdc++.h>
#define ll long long int 

using namespace std;
vector<ll>adj[5005],bc;
vector<ll>radj[5005];
bool visited[5005];
bool inedge[5005];
int scc[5005];
ll n,m,capital;

void dfs(ll x)
{
	visited[x]=1;
		for(auto it : adj[x])
		{	
			if(!visited[it])
				dfs(it);
		}
		bc.push_back(it);
}
void rdfs(ll x,ll k)//k deonotes kaun sa vala scc 
{
	scc[x]=k;
	for(auto it :radj[x])
	{
		if(sc[it]==0)
			dfs(it,k);
		else if(sc[it]!=k)
			inedge[k]=true; // kisi aur ke sath uski bonding hai matlab reverse vale mai to original mai inedge hogi hi
	}
}


int main()
{
	cin>>n>>m>>>capital;
	ll i,x,y;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		radj[y].push_back(x);
	}
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
			dfs(i)
	}
	reverse(bc.begin(),bc.end());
	ll k=0;
	for(auto it:bc)
	{
		if(scc[it]==0)
			rdfs(it,++k);
	}
	ll ans=0;
	for(i=1;i<=k;i++)
	{
		if(inedege[i]==false&&scc[s]!=i)
			ans++;
	}
	cout<<ans;
}