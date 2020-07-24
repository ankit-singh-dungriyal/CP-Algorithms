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
#define lim 10000007LL
typedef unsigned long long ull;
#define M 10004
using u64= uint64_t;
 
// vector<pair<ll,ll>>v[1002];

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
ll d[n+2][n+2];
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        {
            if(i==j)d[i][j]=0LL;
            else d[i][j]=lim;
        }
for(int i=0;i<m;i++){
    cin>>x>>y>>w;
    // v[x].pb(mp(y,w));
    // v[y].pb(mp(x,w));
    d[x][y]=w;
    d[y][x]=w;
}

//.........................
// Floyd-Warshall...

for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        if(d[i][k]<lim && d[k][j]<lim)
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
}
// Floyd-Warshall.....
//.....................
ll q;
cin>>q;
ll u,l,r,k;
for(int i=0;i<q;i++){
    cin>>u>>l>>r>>k;
    vector<ll>ans;
    for(int j=l;j<=r;j++){
        ans.pb(max(0LL,d[u][j]));
    }
    sort(all(ans));
    cout<<ans[k-1]<<"\n";
}
}
} 
