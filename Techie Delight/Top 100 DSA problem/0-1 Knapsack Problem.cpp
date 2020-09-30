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

map<pair<ll,ll>,ll>m;
ll knapsack1(vector<ll>v,vector<ll>w,ll weigh, ll n){
    if(weigh==0||n<0)return 0;  
    if(m[{n,weigh}]) return m[{n,weigh}];
    if(w[n]>weigh)return knapsack1(v,w,weigh,n-1);
    m[{n,weigh}]=max((v[n]+knapsack1(v,w,weigh-w[n],n-1)),knapsack1(v,w,weigh,n-1));
    return m[{n,weigh}];
    
}

ll knapsack2(vector<ll>v,vector<ll>w,ll weigh,int n){
    ll c[n+1][weigh+1];

    for(int i=0;i<=weigh;i++)c[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=weigh;j++){
            l++;
            if(w[i-1]>j)c[i][j]=c[i-1][j];
            else c[i][j]=max(v[i-1]+c[i-1][j-w[i-1]],c[i-1][j]);
        }
    }
    return c[n][weigh];

}


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
    ll n,weigh;
    cin>>n>>weigh;
    vector<ll>v(n),w(n);
    for(auto &x:v)cin>>x;
    for(auto &x:w)cin>>x;
    cout<<knapsack1(v,w,weigh,n-1)<<"\n";
    cout<<knapsack2(v,w,weigh,n)<<"\n";

}
 
} 
