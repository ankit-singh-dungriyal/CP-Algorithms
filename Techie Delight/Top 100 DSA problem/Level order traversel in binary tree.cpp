
// By 'Anki'

// Level order traversel in binary tree

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

node* addnode(int val){
	node* tmp=new node;
	tmp->data=val;
	tmp->l=tmp->r=nullptr;
	return tmp;
}

void levelordertraversel(node *root){
	if(root==nullptr)return;
	queue<node*>q;
	q.push(root);
	node* tmp=nullptr;
	while(!q.empty()){
		tmp=q.front();
		q.pop();
		cout<<tmp->data<<" ";
		if(tmp->l)q.push(tmp->l);
		if(tmp->r)q.push(tmp->r);
	}
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
    node* root=nullptr;
    root=addnode(1);
    root->l=addnode(2);
    root->r=addnode(3);
    root->l->l=addnode(4);
    root->r->r=addnode(5);
    root->l->l->r=addnode(6);
    // wr(root->data)
    levelordertraversel(root);
 
}
}
