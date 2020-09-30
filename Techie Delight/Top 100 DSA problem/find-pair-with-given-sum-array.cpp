// By 'Anki'
 
#include<bits/stdc++.h>
// #include<thread>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define wr(i) cout<<#i<<" = "<<i<<",  ";
#define wre(i) cout<<#i<<"  =  "<<i<<endl;
#define all(v) v.begin(),v.end()
typedef long long ll;
#define lim 1000000000000000000LL
typedef unsigned long long ull;
#define M 1003
#define N 30
#define F first
#define S second
using u64= uint64_t;

int main()
{
fast
// #ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
// #endif
ll t=1LL;
// cin>>t;
 
while(t--)
{
   ll n,k;
   cin>>n>>k;
   vector<ll>v(n);
   map<ll,ll>m;
   ll ind=0LL;
   for(auto &x:v)cin>>x,m[x]=ind++;
   for(auto x:v)if(m[k-x]){cout<<m[x]<<" "<<m[k-x];break;}

}
 
} 
