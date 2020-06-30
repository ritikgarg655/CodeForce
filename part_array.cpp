// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int n,k,p;cin>>n>>k>>p;
// 	int arr[n];
// 	for(int i=0;i<n;i++){
// 		cin>>arr[i];
// 	}
// 	// int num_odd = 0;
// 	// int num_even = 0;
// 	// int prev_odd = 0;
// 	// int prev_even = 0;
// 	// bool done = false;
// 	// for(int i=0;i<n;i++){
// 	// 	if(arr[i]%2==0){
// 	// 		prev_even++;
// 	// 		num_even += prev_even;
// 	// 		num_odd += prev_odd;
// 	// 	}
// 	// 	else{
// 	// 		num_odd += prev_even;
// 	// 		num_even += prev_odd;
// 	// 		int temp = prev_odd;
// 	// 		prev_odd = prev_even+1;
// 	// 		prev_even = temp;
// 	// 		num_odd++;
// 	// 		// prev_odd++;
// 	// 	}
// 	// 	if(num_odd>=p and num_even>=(k-p)){
// 	// 		done = true;
// 	// 		false;
// 	// 	}
// 	// }
// 	// if(done){
// 	// 	cout<<"YES"<<endl;

// 	// }
// 	// else{
// 	// 	cout<<"NO"<<endl;
// 	// }
// 	// if(done){
// 	// 	// printing array
// 	// 	num_odd = 0;
// 	// 	num_even = 0;
// 	// 	prev_odd = 0;
// 	// 	prev_even = 0;
// 	// 	vector<vector<int>> sum_odd,sum_even;
// 	// 	for(int i=0;i<n;i++){
// 	// 		cout<<num_even<<num_odd<<endl;
// 	// 		if(arr[i]%2==0){
// 	// 			prev_even++;
// 	// 			num_even += prev_even;
// 	// 			num_odd += prev_odd;
// 	// 		}
// 	// 		else{
// 	// 			num_odd += prev_even;
// 	// 			num_even += prev_odd;
// 	// 			int temp = prev_odd;
// 	// 			prev_odd = prev_even+1;
// 	// 			prev_even = temp;
// 	// 			num_odd++;
// 	// 			// prev_odd++;
// 	// 		}
// 	// 		{
// 	// 			if(arr[i]%2==0){
// 	// 				int si = sum_even.size();
// 	// 				for(int j=0;j<si;j++){
// 	// 					if(sum_even.size()>=(k-p)){
// 	// 						break;
// 	// 					}
// 	// 					sum_even.push_back(sum_even[j]);
// 	// 					sum_even[sum_even.size()-1].push_back(arr[i]);
// 	// 				}
// 	// 				si = sum_odd.size();
// 	// 				for(int j=0;j<si;j++){
// 	// 					if(sum_odd.size()>=p){
// 	// 						break;
// 	// 					}
// 	// 					sum_odd.push_back(sum_odd[j]);
// 	// 					sum_odd[sum_odd.size()-1].push_back(arr[i]);
// 	// 				}
// 	// 				sum_even.push_back({arr[i]});
// 	// 			}
// 	// 			else{
// 	// 				int si = sum_even.size();
// 	// 				for(int j=0;j<si;j++){
// 	// 					if(sum_odd.size()>=p){
// 	// 						break;
// 	// 					}
// 	// 					sum_odd.push_back(sum_even[j]);
// 	// 					sum_odd[sum_odd.size()-1].push_back(arr[i]);
// 	// 				}
// 	// 				si = sum_odd.size();
// 	// 				for(int j=0;j<si;j++){
// 	// 					if(sum_even.size()>=(k-p)){
// 	// 						break;
// 	// 					}
// 	// 					sum_even.push_back(sum_odd[j]);
// 	// 					sum_even[sum_even.size()-1].push_back(arr[i]);
// 	// 				}
// 	// 				sum_even.push_back({arr[i]});				
// 	// 				sum_odd.push_back({arr[i]});
// 	// 			}
// 	// 		}
// 	// 		if(num_odd>=p and num_even>=(k-p)){
// 	// 			done = true;
// 	// 			break;
// 	// 		}
// 	// 	}
// 	// 	for(int i=0;i<min(k,(int)sum_odd.size());i++){
// 	// 		for(int j=0;j<sum_odd[i].size();j++){
// 	// 			cout<<sum_odd[i][j]<<" ";
// 	// 		}
// 	// 		cout<<endl;
// 	// 	}
// 	// 	for(int i=0;i<min(k-p,(int)sum_even.size());i++){
// 	// 		for(int j=0;j<sum_even[i].size();j++){
// 	// 			cout<<sum_even[i][j]<<" ";
// 	// 		}
// 	// 		cout<<endl;
// 	// 	}
// 	// }
// 	int num_even = 0;
// 	int num_odd = 0;
// 	int prev_odd = 0;
// 	int prev_even = 0;
// 	vector<vector<int>> ans;
// 	vector<int> rem_ev,rem_od;
// 	for(int i=0;i<n;i++){
// 		if(arr[i]%2==0){
// 			if(num_even<p){
// 				num_even++;
// 				ans.push_back({arr[i]});
// 				if(num_even>=p and num_odd>=(k-p)){
// 					break;
// 				}
// 			}
// 			else{
// 				prev_even++;
// 				rem_ev.push_back(arr[i]);
// 			}
// 		}
// 		else{
// 			if(num_odd<(k-p)){
// 				num_odd++;
// 				ans.push_back({arr[i]});
// 				if(num_even>=p and num_odd>=(k-p)){
// 					break;
// 				}
// 			}
// 			else{
// 				prev_odd++;
// 				rem_od.push_back(arr[i]);
// 				if(prev_odd%2==0){
// 					num_even++;
// 					ans.push_back(rem_od);
// 					rem_od.clear();
// 					prev_odd = 0;
// 				}
// 			}
// 		}
// 		if(num_even>=p and num_odd>=(k-p)){
// 			break;
// 		}
// 		// cout<<num_even<<num_odd<<endl;
// 	}

// 	if(num_even>=p and num_odd>=(k-p)){
// 		cout<<"YES"<<endl;
// 		for(int i=0;i<k;i++){
// 			cout<<ans[i].size()<<" ";
// 			for(int j=0;j<ans[i].size();j++){
// 				cout<<ans[i][j]<<" ";
// 			}
// 			cout<<endl;
// 		}
// 	}
// 	else{
// 		cout<<"NO";
// 	}
// }
    #undef NDEBUG
    #ifdef ssu1
    #define _GLIBCXX_DEBUG
    #endif
     
    #include <algorithm>
    #include <functional>
    #include <numeric>
    #include <iostream>
    #include <cstdio>
    #include <cmath>
    #include <cstdlib>
    #include <ctime>
    #include <cstring>
    #include <cassert>
    #include <vector>
    #include <list>
    #include <map>
    #include <set>
    #include <deque>
    #include <queue>
    #include <bitset>
    #include <sstream>
     
    using namespace std;
     
    #define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
    #define forn(i, n) fore(i, 0, n)
    #define fori(i, l, r) fore(i, l, (r) + 1)
    #define forit(i, a) for(typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
    #define sz(v) int((v).size())
    #define all(v) (v).begin(), (v).end()
    #define pb push_back
    #define mp make_pair
    #define X first
    #define Y second
     
    template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
    template<typename T> inline T sqr(T a){ return a * a; }
     
    typedef long long li;
    typedef long double ld;
    typedef pair<int, int> pt;
     
    const int N = (int) 1e5 + 100;
    int a[N];
     
    void print(vector<int> v) {
        assert(sz(v) >= 1);
        cout << sz(v) << " ";
        forn(i, sz(v)) {
            if (i) cout << " ";
            cout << v[i];
        }
        cout << endl;
    }
     
    int main() {
        int n, k, p;
        cin >> n >> k >> p;
        forn(i, n) cin >> a[i];
     
        vector<vector<int> > answer;
        vector<int> even, odd;
     
        forn(i, n) {
            if (a[i] % 2) odd.pb(a[i]);
            else even.pb(a[i]);
        }
     
        int oddNeed = k - p;
        int evenNeed = p;
        int ok = true;
     
        if(sz(odd) < oddNeed || sz(odd) % 2 != oddNeed % 2) {
            ok = false;
        } else {
            if (sz(even) + (sz(odd) - oddNeed) / 2 < evenNeed) {
                ok = false;
            } else {
                forn(i, oddNeed) {
                    vector<int> v;
                    v.pb(odd[odd.size() - 1]);
                    odd.pop_back();
                    answer.pb(v);
                }
     
                assert(sz(odd) % 2 == 0);
     
                while(odd.size() >= 2) {
                    vector<int> v;
                    v.pb(odd[odd.size() - 1]);
                    odd.pop_back();
                    v.pb(odd[odd.size() - 1]);
                    odd.pop_back();
                    answer.pb(v);
                    evenNeed--;
                }
     
                forn(i, sz(even)) {
                    vector<int> v;
                    v.pb(even[i]);
                    answer.pb(v);
                }
            }
        }
     
        if (!ok) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
     
            //cout << sz(answer) << endl;
     
            vector<int> last;
            assert(answer.size() >= k);
            for (int i = k - 1; i < answer.size(); i++) {
                forn(j, answer[i].size()) {
                    last.pb(answer[i][j]);
                }
            }
     
            forn(i, k - 1) {
                print(answer[i]);
            }
     
            //cout << sz(last) << endl;
     
            print(last);
        }
     
        return 0;
    }