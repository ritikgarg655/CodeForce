#include<bits/stdc++.h>
using namespace std;

// template 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vii;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,v) for(int i=0;i<v.size();i++)
#define reps(i,s) for(int i=0;i<s.length();i++)
#define allv(v) v.begin(),v.end()
#define alla(arr,sz) arr,arr+sz
#define rev(v) reverse(allv(v))
#define reva(a) reverse(alla(a))

typedef long long int ll;
int bs(vector<int> &v,int val,ll s,ll e){
    if(s == e){
        return v[s];
    }
    ll mid = (e+s)/2;
    if(v[mid] == val){
        return v[mid];
    }
    else if(v[mid]>val){
        return bs(v,val,s,mid-1);
    }
    else{
        return bs(v,val,mid+1,e);
    }
}


void solve(){
	/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// ListNode* Solution::solve(ListNode* A, int B) {
    vector<int> pow2;
    for(ll i =1;i<=100000;i = i*2){
        pow2.push_back(i);
    }
    cout<<(bs(pow2,3,0,(ll)pow2.size()-1));
    cout<<(bs(pow2,6,0,(ll)pow2.size()-1));
    cout<<(bs(pow2,8,0,(ll)pow2.size()-1));
    cout<<(bs(pow2,7,0,(ll)pow2.size()-1));
    cout<<(bs(pow2,1,0,(ll)pow2.size()-1));
    cout<<(bs(pow2,13,0,(ll)pow2.size()-1));

}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}