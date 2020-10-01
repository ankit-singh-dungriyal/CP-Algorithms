// By 'Anki'

// Longest common subsequence 

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

map<pair<ll,ll>,ll>dp;
ll lcs1(string a,string b,ll n,ll m){
    if(n==0||m==0)return 0LL;
    if(!dp[{n,m}]){
        if(a[n-1]==b[m-1])dp[{n,m}]=lcs1(a,b,n-1,m-1)+1;
        else dp[{n,m}]=max(lcs1(a,b,n-1,m),lcs1(a,b,n,m-1));
    }
    return dp[{n,m}];
}

ll lcs2(string a,string b,ll n,ll m){
    ll dp[n+1][m+1];
    for(int i=0;i<=n;i++)dp[i][0]=0LL;
    for(int j=0;j<=m;j++)dp[0][j]=0LL;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];

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
    dp.clear();
   string a,b;
   cin>>a>>b;
    ll n=a.length();
    ll m=b.length();
    cout<<lcs1(a,b,n,m)<<" ";
    cout<<lcs2(a,b,n,m)<<"\n";

}
 
} 
