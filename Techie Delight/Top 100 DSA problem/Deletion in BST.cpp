// By 'Anki'

// Deletion in BST

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

node* newnode(int val){
    node* tmp=new node;
    tmp->data=val;
    tmp->l=tmp->r=NULL;
    return tmp;
}

node* insert(node* root,int val){
    if(root==nullptr){
        return newnode(val);
    }
    else{
        if(val>root->data)root->r=insert(root->r,val);
        else root->l=insert(root->l,val);
    }
    return root;
}

void insert_reference(node* &root,int val){
    if(root==nullptr)root=newnode(val);
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


void search_node(node* &curr,int val,node* &par){

    while(curr!=nullptr && curr->data!=val){
        par=curr;
        if(val>curr->data)curr=curr->r;
        else curr=curr->l;
    }
}

void minimum_node(node* &tmp){
    while(tmp->l!=nullptr)tmp=tmp->l;
}


void delete_node(node* &root,int val){
    node* par=nullptr;
    node* curr=root;
    if(curr==nullptr)return;
    search_node(curr,val,par);
    // wr(par->data)

    if(curr==nullptr)return;
    
    // if required node has no children
    if(curr->l==nullptr && curr->r==nullptr){
        if(curr==root){
            root=nullptr;
        }
        else{
            if(par->l==curr)par->l=nullptr;
            else par->r=nullptr;
        }
        free(curr);
    }

    // if required node has two children
    else if(curr->l && curr->r){
        node* min_succ=curr->r;
        minimum_node(min_succ);

        if(curr==root){
            min_succ->l=root->l;
            root=root->r;
        }
        else{
            par->r=curr->r;
            min_succ->l=curr->l;
        }
        free(curr);

    }

    // if required node has only one child
    else{
        node* child=(curr->l)?curr->l:curr->r;
        if(curr==root){
            root=child;
        }
        else{
            if(par->l==curr)par->l=child;
            else par->r=child;
        }
        free(curr);
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
    int n;
    cin>>n;
    vector<ll>v(n);
    for(auto &x:v)cin>>x;
    node* root=nullptr;
    for(ll x:v)root=insert(root,x);
    // for(int x:v)insert_reference(root,x);
    show(root);
    //  Enter value to node to be deleted:
    int p;
    cin>>p;
    // wr(root->data)
    delete_node(root,p);
    cout<<"\n";
    show(root);
}
 
} 
