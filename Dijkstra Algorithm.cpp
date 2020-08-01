// By "ANKI"
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
#define lim 10000007LL
typedef unsigned long long ull;
#define M 300006
#define F first
#define S second
using u64= uint64_t;
 

vector<pair<ll,ll>>v[M];
vector<ll>dis(M,lim);
vector<ll>path(M,-1);
void dijkstra(ll n){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    // priority_queue<pair<ll,ll>>pq;
    pq.push(mp(0,n));
    dis[n]=0LL;
    while(!pq.empty()){
        ll u=pq.top().second;
        pq.pop();
        for(auto x:v[u]){
            if(dis[x.first]>dis[u]+x.second){
                dis[x.first]=dis[u]+x.second;
                path[x.first]=u;
                pq.push(mp(dis[x.first],x.first));
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
ll x,y,w;
for(int i=0;i<m;i++){
    cin>>x>>y>>w;
    v[--x].pb(mp(--y,w));
    v[y].pb(mp(x,w));
}
dijkstra(0);
for(int i=0;i<n;i++)cout<<i<<" - "<<dis[i]<<"\n";
cout<<"Path: \n" ;
for(int i=0;i<n;i++){
    cout<<i<<" - ";
    ll x=path[i];
    while(x!=-1){
        cout<<x<<", ";
        x=path[x];
    }
    cout<<"\n";
}
}
} 
