// Fibonacci series (Companion Matrix)
// Here series started from 0 i.e(0,1,1,2,3,5,8,13.....) . Hence first element is 0.

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
#define mod 1000000007
#define N 30
#define F first
#define S second
using u64= uint64_t;

void mul(ll a[2][2],ll b[2][2]){
    ll ans[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ans[i][j]=0LL;
            for(int k=0;k<2;k++)ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%mod;
        }
    }
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)a[i][j]=ans[i][j];
}

ll power(ll a[2][2],ll n){
    ll res[2][2]={{1,0},{0,1}};
    while(n){
        if(n&1)mul(res,a);
        mul(a,a);
        n>>=1;
    }
    ll ans=res[0][0]%mod;
    return ans;
}

int main()
{
fast
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
ll t=1LL;
cin>>t;

while(t--)
{
    ll n;
    cin>>n;
    ll a[2][2]={{1,1},{1,0}};
    if(n<=1)cout<<0<<"\n";
    else if(n==2)cout<<1<<"\n";
    else cout<<power(a,n-2)<<"\n";
    
}
 
} 
