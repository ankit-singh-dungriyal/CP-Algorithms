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
#define M 30001
#define F first
#define S second
using u64= uint64_t;

vector<ll>seg(4*M);

// build segment tree
void seg_build(vector<ll>&v, int sl,int sr,int i){
  if(sl>sr)return;
  if(sl==sr)seg[i]=v[sl];
  else{
    int sm=(sl+sr)/2;
    seg_build(v,sl,sm,2*i);
    seg_build(v,sm+1,sr,2*i+1);
    seg[i]=seg[2*i]+seg[2*i+1];
  }
}

// Range sum query
ll sum(int l,int r,int sl,int sr,int i){
  if(l>r)return 0;
  if(l==sl && r==sr)return seg[i];
  else{
    int sm=(sl+sr)/2;
    return sum(l,min(sm,r),sl,sm,2*i)+sum(max(l,sm+1),r,sm+1,sr,2*i+1);
  }
}


// update query
void update(vector<ll>&v,int sl,int sr,int pos,ll val,int i){
  if(sl==sr)seg[i]=val;
  else{
    int sm=(sl+sr)/2;
    if(pos<=sm)update(v,sl,sm,pos,val,2*i);
    else update(v,sm+1,sr,pos,val,2*i+1);
    seg[i]=seg[2*i]+seg[2*i+1];
  }
}

// range update query
void update_range(int sl,int sr,int l,int r,int val,int i){
  if (l>r)return;
  if(sl==sr)seg[i]=val;
  else{
    int sm=(sl+sr)/2;
    update_range(sl,sm,l,min(r,sm),val,2*i);
    update_range(sm+1,sr,max(l,sm+1),r,val,2*i+1);
    seg[i]=seg[2*i]+seg[2*i+1];
  }

}

int main()
{
fast
ll t=1LL;
// cin>>t;
while(t--)
{
ll n,m;
cin>>n;
vector<ll>v(n);
seg.resize(4*n);
for(auto &x:v)cin>>x;

// build segment tree
seg_build(v,0,n-1,1);

// update query
int pos;
ll val;
cin>>pos>>val;
update(v,0,n-1,pos,val,1);

// range_sum query
int l,r;
cin>>l>>r;
cout<<sum(l,r,0,n-1,1)<<"\n";

// range_ update query
cin>>l>>r>>val;
update_range(0,n-1,l,r,val,1);

for(auto x:seg)cout<<x<<" ";

}
} 
