// By 'Anki'
// Problem: Finding sum of xor of all pairs;

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
#define M 20000007
#define mod 1000000007
#define F first
#define S second
using u64= uint64_t;

int brute(vector<int>v,int n){
	int sum=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++)sum+=v[i]^v[j];
	}
return sum;
}
int bitmask(vector<int>v,int n){
	int sum=0;
	int tmp=1;
	for(int i=0;i<32;i++){
		int one=0,zero=0;
		for(int i=0;i<n;i++){
			if(v[i]&1)one++;
			else zero++;
			v[i]>>=1;
		}
		sum+=one*zero*tmp;
		tmp<<=1;
	}
	return sum;
}

int k=1;
void solve(){
ll n;
cin>>n;
vector<int>v(n);
for(auto &x:v)cin>>x;
cout<<bitmask(v,n)<<"\n";  // Time Complexity= O(n^2);
cout<<brute(v,n)<<"\n";  // Time Complexity= O(32*n);
return;
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
