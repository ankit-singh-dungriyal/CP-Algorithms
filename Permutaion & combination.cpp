// By 'Anki'
 
#include<bits/stdc++.h>
// #include<iostream>
// #include<thread>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define mt make_tuple 
#define wr(i) cout<<#i<<" = "<<i<<",  ";
#define wre(i) cout<<#i<<"  =  "<<i<<endl;
#define all(v) v.begin(),v.end()
typedef long long ll;
#define lim 100000000LL
#define mod 998244353
typedef unsigned long long ull;
#define M 1003
#define N 30
#define F first
#define S second
using u64= uint64_t;
 
class pandc{
    vector<ll>fact,inv,ifact;
    public:
    pandc(ll n){
        fact.resize(n+1);
        inv.resize(n+1);
        ifact.resize(n+1);
        fact[0]=1;
        inv[0]=1;
        ifact[0]=1;
        for(int i=1;i<=n;i++){
            fact[i]=(fact[i-1]*i)%mod;
            inv[i]=power(i,mod-2);
            ifact[i]=power(fact[i],mod-2);
        }
    }
    ll power(ll x,ll y){
        ll res=1LL;
        while(y){
            if(y&1)res=(res*x)%mod;
            x=(x*x)%mod;
            y>>=1;
        }
        return res;
    }
    ll factorial(ll x){
        return (x>=0)?fact[x]:0;
    }
    ll ncr(ll n,ll r){
        ll tmp=(fact[n]*ifact[r])%mod;
        return(tmp*ifact[n-r])%mod;
    }
};
int main(){

return 0;
}
