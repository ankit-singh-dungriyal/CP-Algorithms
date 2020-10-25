// By 'Anki'
// Trie Implementation

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


struct trie{
	trie* children[10];
	bool end;
};


trie *addnode(){
	trie *tmp=new trie();
	for(int i=0;i<10;i++)tmp->children[i]=NULL;
	tmp->end=false;
	return tmp;
}

void insert(trie *&root,string s){
	if(!root)root=addnode();
	trie *trav=root;
	for(int i=0;i<s.length();i++){
		if(trav->children[s[i]-'0']==NULL)trav->children[s[i]-'0']=addnode();
		trav=trav->children[s[i]-'0'];
	}
	trav->end=true;
}

bool search(trie* root,string s){
	if(!root){wr("!!!")return false;}
	trie *trav=root;
	for (int i=0;i<s.length();i++){
		if(trav->children[s[i]-'0']==NULL)return false;
		trav=trav->children[s[i]-'0'];
	}
	if(trav && trav->end==true)return true;
	return false;
}

void solve(){
	string input[4]={"9087654532","9876543210","9087654832","9999999999"};
	trie *root =NULL;
	for(int i=0;i<4;i++)insert(root,input[i]);
	cout<<" checking for 9087654532 : "<<search(root,"9087654532")<<"\n";
	cout<<" checking for 9876543210 : "<<search(root,"9876543210")<<"\n";
	cout<<" checking for 9876543200 : "<<search(root,"9876543200")<<"\n";
	cout<<" checking for 9876543211 : "<<search(root,"9876543211")<<"\n";

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
