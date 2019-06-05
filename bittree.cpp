#include<bits/stdc++.h>
#define ll long long int
using namespace std;
priority_queue<ll,vector<ll>,greater<ll>>pq;
set<ll>s;
set<ll>v[100005];
ll a[100005];
ll n;
ll bit[100005];
void update(ll x,ll delta)
{
	for(;x<=n;x+=x&-x)
		bit[x]=bit[x]+delta;
}
ll query(ll x)
{
	//yahi hoti hai range original baki lite hai 
	ll sum=0;
	for(;x>0;x-=x&-x)
		sum+=bit[x];
	return sum;
}
ll rg(ll l,ll r)
{
	if(l>r)
	return query(n)-query(l-1)+query(r);
	else
	return query(r)-query(l-1);
}

int main()
{
	ll i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		v[a[i]].insert(i);
		update(i,1);
		pq.push(a[i]);
	}
	
	ll left=1;ll ans=0;
	while(!pq.empty())
	{
		ll x=pq.top();
		
		auto it=v[x].lower_bound(left);
		if(it==v[x].end())
			it=v[x].begin();
		ll right=*it;
		ans=ans+rg(left,right);
		left=*it;
		update(right,-1);
		pq.pop();
		q[x].erase(right);
	}
	cout<<ans;
}
