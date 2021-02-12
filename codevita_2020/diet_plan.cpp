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
	int i,j,k,q,l;
	// int n;
	// // n = 1;
	// cin>>n;
	// int arr[n];
	// for(in ti==0;i<n;i++){
	// cin>>arr[i];
	// }
	// string s1,s2;cin>>s1>>s2;
	// cout<<s1<<s2;
	string max_s[3];
	int time = 0;
	for(int j=0;j<3;j++){
		string s1;cin>>s1;
		for(int i=0;i<s1.length();i++){
			if(s1[i]!=' ' and s1[i]!='P' and s1[i]!='F' and s1[i]!='C'){
				max_s[j] += s1[i];
			}
		}
	}
	int num_p = stoi(max_s[0]);
	int num_c = stoi(max_s[1]);
	int num_f = stoi(max_s[2]);
	vector<pair<int,pair<int,int>>> v;
	pair<string,int> prev;
	while(1){
		bool done = false;
		string max_S[3];
		if(v.size()>0){
			max_S[prev.second] = prev.first;
		}
		for(int i=0;i< (v.size()!=0?2:3);i++){
			string s1;cin>>s1;
			string temp;
			for(int j=0;j<s1.length();j++){
				if(s1[j]!='P' and s1[j]!='C' and s1[j]!='F' and s1[j]!='|'){
					temp += s1[j];
				}
				else if(s1[j]=='P'){
					max_S[0] = temp;
				}
				else if(s1[j]=='C'){
					max_S[1] = temp;
				}
				else if(s1[j]=='F'){
					max_S[2] = temp;
				}
				else if(s1[j] == '|'){
					j+=1;
					string prev1;
					while(j<s1.length()-1){
						prev1+=s1[j];
						j++;
					}
					int a ;
					if(s1[s1.length()-1] == 'P'){
						a = 0;
					}
					else if(s1[s1.length()-1] == 'C'){
						a = 1;
					}
					else{
						a = 2;
					}
					prev = {prev1,a};
					break;
				}
				if(i+1==(v.size()!=0?2:3) and j==(s1.length()-1)){
					done = true;
					break;
				}
			}
		}
		v.push_back({stoi(max_S[0]),{stoi(max_S[1]),stoi(max_S[2])}});
		if(done){
			break;
		}
	}
	int sum_p = 0;
	int sum_f = 0;
	int sum_c = 0;
	vector<pair<int,pair<int,int>>> v_sum;
	sort(v.begin(),v.end());
	int n = v.size();
	// for(int i=0;i<n;i++){
	// 	cout<<v_sum[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
	// }
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int l=k+1;l<n;l++){
					for(int m = l+1;l<n;l++){
						for(int o = m+1;o<n;o++){
							for(int p=o+1;p<n;p++){
								for(int q=p+1;q<n;q++){
									for(int r=q+1;r<n;r++){
										for(int s=r+1;s<n;s++){
											// 10 sum
											v_sum.push_back({v[i].first+v[s].first+v[q].first + v[j].first + v[k].first+ v[p].first+ v[l].first+ v[r].first+ v[m].first+ v[o].first,{v[i].second.first+v[s].second.first + v[j].second.first+v[r].second.first + v[k].second.first+ v[l].second.first+ v[m].second.first+ v[o].second.first+ v[p].second.first+ v[q].second.first,v[i].second.second + v[j].second.second+ v[k].second.second+ v[l].second.second + v[m].second.second+ v[o].second.second+ v[p].second.second+ v[q].second.second+ v[r].second.second+ v[s].second.second }});
										}
										//9 sum
										v_sum.push_back({v[i].first+v[q].first + v[j].first + v[k].first+ v[p].first+ v[l].first+ v[r].first+ v[m].first+ v[o].first,{v[i].second.first + v[j].second.first+v[r].second.first + v[k].second.first+ v[l].second.first+ v[m].second.first+ v[o].second.first+ v[p].second.first+ v[q].second.first,v[i].second.second + v[j].second.second+ v[k].second.second+ v[l].second.second + v[m].second.second+ v[o].second.second+ v[p].second.second+ v[q].second.second+ v[r].second.second }});
									}
									//8 sum
									v_sum.push_back({v[i].first+v[q].first + v[j].first + v[k].first+ v[p].first+ v[l].first+ v[m].first+ v[o].first,{v[i].second.first + v[j].second.first + v[k].second.first+ v[l].second.first+ v[m].second.first+ v[o].second.first+ v[p].second.first+ v[q].second.first,v[i].second.second + v[j].second.second+ v[k].second.second+ v[l].second.second + v[m].second.second+ v[o].second.second+ v[p].second.second+ v[q].second.second }});
								}
								// 7 sum
								v_sum.push_back({v[i].first + v[j].first + v[k].first+ v[p].first+ v[l].first+ v[m].first+ v[o].first,{v[i].second.first + v[j].second.first + v[k].second.first+ v[l].second.first+ v[m].second.first+ v[o].second.first+ v[p].second.first,v[i].second.second + v[j].second.second+ v[k].second.second+ v[l].second.second + v[m].second.second+ v[o].second.second+ v[p].second.second }});
							}
							// 6 sum
							v_sum.push_back({v[i].first + v[j].first + v[k].first+ v[l].first+ v[m].first+ v[o].first,{v[i].second.first + v[j].second.first + v[k].second.first+ v[l].second.first+ v[m].second.first+ v[o].second.first,v[i].second.second + v[j].second.second+ v[k].second.second+ v[l].second.second + v[m].second.second+ v[o].second.second }});
						}
						//5 sum
						v_sum.push_back({v[i].first + v[j].first + v[k].first+ v[l].first+ v[m].first,{v[i].second.first + v[j].second.first + v[k].second.first+ v[l].second.first+ v[m].second.first,v[i].second.second + v[j].second.second+ v[k].second.second+ v[l].second.second + v[m].second.second }});
					}
					// 4 sum
					v_sum.push_back({v[i].first + v[j].first + v[k].first+ v[l].first,{v[i].second.first + v[j].second.first + v[k].second.first+ v[l].second.first,v[i].second.second + v[j].second.second+ v[k].second.second+ v[l].second.second }});
				}
				// 3 sum
				v_sum.push_back({v[i].first + v[j].first + v[k].first,{v[i].second.first + v[j].second.first + v[k].second.first,v[i].second.second + v[j].second.second+ v[k].second.second }});
			}
			// 2 sum
			v_sum.push_back({v[i].first + v[j].first ,{v[i].second.first + v[j].second.first ,v[i].second.second + v[j].second.second }});
		}
// 1 sum
		v_sum.push_back({v[i].first  ,{v[i].second.first  ,v[i].second.second  }});
	}
	// cout<<num_p<<" "<<num_c<<" "<<num_f<<endl;
	sort(v_sum.begin(),v_sum.end(),greater<pair<int,pair<int,int>>>());
	for(int i=0;i<v_sum.size();i++){
		if(v_sum[i].first==0 or v[i].second.first==0 or v[i].second.second==0){
			continue;
		}
		int a = min((num_p/(v_sum[i].first)),min((num_c/(v_sum[i].second.first)),(num_f/(v_sum[i].second.second))));
		cout<<v_sum[i].first<<" "<<v_sum[i].second.first<<" "<<v_sum[i].second.second<<endl;
		if(a<=0){
			continue;
		}
		num_p -= v_sum[i].first*a;
		num_c -= v_sum[i].second.first*a;
		num_f -= v_sum[i].second.second*a;
		cout<<a<<endl;

		
	}
	cout<<num_p<<" "<<num_c<<" "<<num_f;
	// for(int )
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