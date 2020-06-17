
ll arr[100005];
ll s;
void fenwick(vector<ll>v)
{
     s=v.size();
    arr[0]=0;
    for(int i=1;i<=s;i++)arr[i]=v[i-1];
    for(int i=1;i<=s;i++){
        int j=i+(i&(-i));
        if(i<=s)arr[j]+=arr[i];
    }
}

ll sum(ll x)
{
    ll res=0LL;
    for(int i=x;i>0;i-=(i&(-i)))res+=arr[i];
    return res;
}
void update(ll x,ll val)
{
    for(++x;x<s;x+=x &(-x))arr[x]+=val;
}
ll range_sum(ll l,ll r){
    return sum(++r)-sum(l);
}

int main(){
return 0;
}
