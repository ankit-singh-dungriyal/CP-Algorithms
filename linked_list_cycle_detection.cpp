// By 'Anki'

// Linked list cycle detection

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
    int val;
    node *next;
    public:
    node(){
        val=0;
        next=NULL;
    }
    node(int x){
        val=x;
        next=NULL;
    }
    node(int x,node *tmp){
        val=x;
        next=tmp;
    }
};

struct node* head=NULL;

struct node* addnode(int x){
    if(head==NULL){
        head=new node(x);
        return head;
    }
    else{
        struct node* tmp=head;
        while(tmp->next!=NULL)tmp=tmp->next;
        tmp->next=new node(x);
        return tmp->next;
    }
}

void printlist(struct node* trav){
    int x=0;
    while(trav){
        cout<<trav->val<<" ";
        trav=trav->next;
        x++;
        if(x>15)break;  // printing first 16 elements of node;
    }
}

bool iscircular(){
    struct node *first=head,*second=head;
    first=first->next;
    if(second->next==NULL)return false;
    second=second->next->next;
    while(first && second && second->next){
        if(first==second){
            // cout<<first->val<<" "; 
            return true;
        }
        first=first->next;
        second=second->next->next;
    }
    return false;

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
    addnode(1);
    addnode(2);
    addnode(3);
struct node *f= addnode(4);
    addnode(5);
    addnode(6);
    addnode(7);
struct node *s= addnode(8);
  s->next=f;

    printlist(head);
    cout<<"\n";
    cout<<iscircular()<<" ";

}
 
} 