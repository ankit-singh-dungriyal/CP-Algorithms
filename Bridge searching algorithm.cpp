// Bridge searching algorithm - (using dfs tree)
// 'By Anki'
 
#include<bits/stdc++.h>
// #include<iostream>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define wr(i) cout<<#i<<" = "<<i<<",  ";
#define wre(i) cout<<#i<<"  =  "<<i<<endl;
#define all(v) v.begin(),v.end()
typedef long long ll;
#define lim 1000000007LL
typedef unsigned long long ull;
#define M 200005
using u64= uint64_t;

vector<ll>v[M];
vector<bool>vis(M);
vector<ll>in(M),low(M);
vector<pair<ll,ll>>bridge;
ll timer=0LL;

void dfs(ll n,ll pr){
  vis[n]=true;
  in[n]=low[n]=timer++;
  for(auto x:v[n]){
    if(x==pr)continue;
    if(vis[x])low[n]=min(in[x],low[n]);
    else
    {
      dfs(x,n);
      low[n]=min(low[n],low[x]);
      if(low[x]>low[n]){
        bridge.pb(mp(n,x));
      }
    }
    
  }
}
int main()
{
fast
ll t=1LL;
// cin>>t;

while(t--)
{
 ll n,m;
 cin>>n>>m;
 ll x,y;
 in.assign(n+1,-1);
 low.assign(n+1,-1);
 for(int i=0;i<m;i++)
 {
   cin>>x>>y;
   v[x].pb(y);
   v[y].pb(x);
 }
 dfs(0,-1);
  for(auto x:bridge){
    cout<<x.first<<" - "<<x.second<<"\n";
  }
 
}
} 
