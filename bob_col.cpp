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
// #define s second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,v) for(int i=0;i<v.size();i++)
#define reps(i,s) for(int i=0;i<s.length();i++)
#define allv(v) v.begin(),v.end()
#define alla(arr,sz) arr,arr+sz
#define rev(v) reverse(allv(v))
#define reva(a) reverse(alla(a))


void solve(){
	// int i,j,k,q,l;
	int r,g,b,w;
	// n = 1;
	cin>>r>>g>>b>>w;
	bool done = false;
	// if((r&1) + (g&1) + (b&1) + (w&1) <=1){
	// 	done = true;
	// }
	// else if((r&1) + (g&1) + (b&1) + (w&1) ==2){
	// 	done = false;
	// }
	// else if((r&1) + (g&1) + (b&1) + (w&1) == 3){
	// 	if(r==0 or g==0 or b==0){
	// 		done = false;
	// 	}
	// 	else if(w%2==1){
	// 		done = true;
	// 	}
	// 	else{
	// 		done = false;
	// 	}
	// }
	// else{
	// 	done = true;
	// }
int count_n=0;
if(r%2==0)
count_n++;
if(g%2==0)
count_n++;
if(b%2==0)
count_n++;
if(w%2==0)
{
  count_n++;
}
int minm=min(min(r,g),b);


if(count_n>=3)
{
  cout<<"Yes\n";return;
}
// bool flag=false;
if(minm>=1){
 r-=1;
b-=1;g-=1;
w+=3*1;
int count_n=0;
if(r%2==0)
count_n++;
if(g%2==0)
count_n++;
if(b%2==0)
count_n++;
if(w%2==0)
{
  count_n++;
}


if(count_n>=3){
done=true;}
   }
	// else if((r&1) + (g&1) + (b&1)==3 and (w%2==0)){
	// 	done = false;
	// }
	// else if((r&1) + (g&1) + (b&1)==3 and (w%2==1)){
	// 	done = true;
	// }
	// else if(r==0 or g==0 or b==0){
	// 	done = false;
	// }
	// else if((r&1) + (g&1) + (b&1) == 2 and (w%2==1)){
	// 	done = true;
	// }
	// else if((r&1) + (g&1) + (b&1) + (w&1) == 2){
	// 	done = false;
	// }
	// else{
	// 	done = false;
	// }
	if(done){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}

}
int main(){
	//ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
	int t;
	// t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}