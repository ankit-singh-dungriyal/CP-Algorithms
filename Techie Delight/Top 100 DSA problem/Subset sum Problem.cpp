/*
Subset sum Problem
Given a set of positive integers and an integer k, is there any non-empty subset whose sum equal to k.
*/

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

map<pair<ll,ll>,bool>m;
bool solve1(vector<ll>v,ll k,ll n){
    if(k==0)return true;
    if(k<0||n<0)return false;
    if(m[{k,n}])return m[{k,n}];
    m[{k,n}]=(solve1(v,k-v[n],n-1)||solve1(v,k,n-1));
    return m[{k,n}];
}

bool solve2(vector<ll>v,ll k,ll n){
    bool ans[n+1][k+1];
    for(int i=0;i<=n;i++)ans[i][0]=true;
    for(int j=1;j<=k;j++)ans[0][j]=false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(v[i-1]>j)ans[i][j]=ans[i-1][j];
            else{
                ans[i][j]=(ans[i-1][j-v[i-1]])||(ans[i-1][j]);
            }
        }
    }
    if(n==5)
   for(int i=0;i<=n;i++){
       for(int j=0;j<=k;j++)cout<<ans[i][j]<<" ";
       cout<<"\n";
   }
    return ans[n][k];
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
   ll n,k;  // k is sum of subset of array 
   cin>>n>>k;
   vector<ll>v(n);
   for(auto &x:v)cin>>x;

   if(solve1(v,k,n-1))cout<<"YES\n";
   else cout<<"NO\n";
   if(solve2(v,k,n))cout<<"YES\n";
   else cout<<"NO\n";




}
 
} 
