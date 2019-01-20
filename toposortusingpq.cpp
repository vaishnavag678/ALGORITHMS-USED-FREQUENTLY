#include<bits/stdc++.h>
#define ll long long int 

using namespace std;
ll n,m;
vector<ll>v[1000005],bc;
ll indegree[100005];

int main()
{
	ll x,y,i;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		indegree[y]++;
	}
	priority_queue<ll,vector<ll>,greater<ll>>q;
	for(i=1;i<=n;i++)
		if(indegree[i]==0)
			q.push(i);
	while(!q.empty())
	{
		ll x=q.top();
		q.pop();
		bc.push_back(x);
		for(i=0;i<v[x].size();i++)
		{
			y=v[x][i];
			indegree[y]--;
			if(indegree[y]==0)
				q.push(y);
		}
	}
	for(i=0;i<bc.size();i++)
		cout<<bc[i]<<"\n";
}
