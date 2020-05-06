#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    	a[i];
    }
    for (int i = 0; i < n; i++){
    	vector<bool> vis(n+1, false);
    	queue<int> q;
    	q.push(a[i]);
    	int p = a[i];
    	vis[i] = true;
    	while(!q.empty()){
    		p = q.front();
    		q.pop();
    		if (vis[p]) break;
    		vis[p] = true;
    		q.push(a[p]);
    	}
    	cout << p<< " ";
    }
    cout << endl;
    return 0;
	// cout<<ans<<endl;
}