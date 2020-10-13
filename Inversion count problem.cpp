// By 'Anki'

// Inversion count problem using merge sort

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
#define mod 1000000007
#define N 30
#define F first
#define S second
using u64= uint64_t;


ll count_inversion(vector<ll>&v,int l,int mid,int r){
    int i=l,j=mid+1;
    vector<ll>tmp;
    ll count=0LL;
    while(i<=mid&&j<=r){
        if(v[i]<=v[j])tmp.pb(v[i]),i++;
        else tmp.pb(v[j]),j++,count+=mid-i+1;
    }
    while(i<=mid)tmp.pb(v[i++]);
    while(j<=r)tmp.pb(v[j++]);
    int k=0;
    for(int i=l;i<=r;i++)v[i]=tmp[k++]; 
    return count;
}

ll merge(vector<ll>&v,int l,int r){
    ll ans=0LL;
    if(l<r){
        ll mid=l+(r-l)/2;
       ans+= merge(v,l,mid);
       ans+= merge(v,mid+1,r);

       ans+= count_inversion(v,l,mid,r);
    }
       return ans;
}

void solve(){
  ll n;
  cin>>n;
  vector<ll>v(n);
  for(auto &x:v)cin>>x;
  ll ans=merge(v,0,n-1);
  cout<<ans<<"\n";
  for(auto x:v)cout<<x<<" ";

}

int main()
{
fast
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
ll t=1LL;
// cin>>t;
while(t--)
{
solve();   
}
 
} 
