#include<bits/stdc++.h>
using namespace std;

struct node{
	int priority;
	char data;
	vector<char> child; 
	vector<node *> child_add;
};

void add_node(node * par,string str,int value){
	// l;
	for(unsigned int i=0;i<str.length();i++){
		if(par->priority==-1){
			par->priority = 0;
		}
		par->priority += value;
		bool found= false;
		for(unsigned int j=0;j<par->child.size();j++){
			if(par->child[j]==str[i]){
				found = true;
				par = par->child_add[j];	
				break;
			}
		}
		if(!found){
			node* new_node = (node*)malloc(sizeof(node));
			new_node->priority = -1;
			new_node->data = str[i];
			par->child.push_back(str[i]);
			par->child_add.push_back(new_node);
			par = new_node;
		}
	}
}

int query_res(node* par,string q){
	bool done = true;
	for(unsigned int i=0;i<q.length();i++){
		for(unsigned int j=0;j<par->child.size();j++){
			if(par->child[j]==q[i]){
				// found = true;
				par = par->child_add[j];	
				break;
			}
			else{
				done = false;
				break	;
			}
		}
		if(!done){
			break;
		}
	}
	int result = 0;
	if(!done){
		return -1;
	}
	else{
		// cout<<"sa";
		while(par!=NULL and par->child.size()>0){
			int max_value = INT_MIN;
			node* max_node = NULL;
			char add_r;
			for(unsigned int i=0;i<par->child.size();i++){
				if(max_value<par->child_add[i]->priority and par->child_add[i]->priority!=-1){
					max_value = par->child_add[i]->priority;
					max_node = par->child_add[i];
					add_r = par->data;
				}	
			}
			// cout<<max_value<<endl;
			if(max_node!=NULL){
				result = max_value;
				par = max_node;
			}
			else{
				break;
			}
		}
	}
	return result;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n,q;cin>>n>>q;
	vector<pair<string,int>> dict;
	for(int i=0;i<n;i++){
		string s;int pr;
		cin>>s>>pr;
		dict.push_back({s,pr});
	}
	string query[q];
	
	node* new_child = (node*)malloc(sizeof(node));
	new_child->priority = 0;
	node* root = new_child;
	for(int i=0;i<n;i++){
		add_node(root,dict[i].first,dict[i].second);
	}
	for(int i=0;i<q;i++){
		cin>>query[i];
		int ans = query_res(root,query[i]);
		if(ans!=NULL)
		cout<<ans<<endl;
	}
}