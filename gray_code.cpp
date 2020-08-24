// By 'Anki'
// Gray code

#include<bits/stdc++.h>
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
#define M 200005LL
#define F first
#define S second
using u64= uint64_t;


ll gray_code(ll n){
    return n^(n>>1);
}

int main()
{
fast
ll t=1LL;
// cin>>t;

while(t--)
{
ll n;
cin>>n;
cout<<gray_code(n);

}
} 
