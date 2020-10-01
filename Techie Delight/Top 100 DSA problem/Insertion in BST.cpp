// By 'Anki'

// Insertion in BST

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

struct node{
    int data;
    node *l,*r;
};

node* new_node(int val){
    node* tmp=new node;
    tmp->data=val;
    tmp->l=tmp->r=nullptr;
    return tmp;
}

node* insert(node* root,int val){
    if(root==nullptr){
        return new_node(val);
    }
    if(val>root->data){
        root->r=insert(root->r,val);
    }
    else{
        root->l=insert(root->l,val);
    }
    return root;
}

void insert_reference(node* &root,int val){
    if(root==nullptr)root=new_node(val);
    else{
        if(val>root->data)insert_reference(root->r,val);
        else insert_reference(root->l,val);
    }
}

void show(node* root){
    if(root==nullptr)return;
    show(root->l);
    cout<<root->data<<" ";
    show(root->r);
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
    int n;
    cin>>n;
    vector<ll>v(n);
    for(auto &x:v)cin>>x;
    node* root=nullptr;
    for(ll x:v)root=insert(root,x);
    // for(int x:v)insert_reference(root,x);
    show(root);
}
 
} 
