#include<bits/stdc++.h>
#define Fox ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define turn_on_clock clock_t start,end;start=clock();
#define turn_off_clock end=clock();printf("\nTime eclipse:%.5lfms\n",(double)(end-start)/CLOCKS_PER_SEC*1000);
using namespace std;
typedef long long ll;
const int SIZE=1e5+10;
const int INF=0x3f3f3f3f;
const double eps=1e-5;
const double PI=atan(1.0)*4.0;
const ll mod=1e9+7;
int n,m;
char s[55][55];
int v[55][55],cnt,res;
vector<int>pos[2];
void dfs(int x,int y){
	v[x][y]=1;res++;
	pos[0].push_back(x),pos[1].push_back(y);
	if(x>1 && s[x-1][y]=='B' && !v[x-1][y])dfs(x-1,y);
	if(x<n && s[x+1][y]=='B' && !v[x+1][y])dfs(x+1,y);
	if(y>1 && s[x][y-1]=='B' && !v[x][y-1])dfs(x,y-1);
	if(y<m && s[x][y+1]=='B' && !v[x][y+1])dfs(x,y+1);
}
void Judge(int a,int b){
	int x=pos[0][a],y=pos[1][a];
	int l=x,r=x;
	int u=y,d=y;
	for(int i=x;i<=n;i++)
		if(s[i][y]=='B')r++;
		else break;
	for(int i=x;i;i--)
		if(s[i][y]=='B')l--;
		else break;
	for(int i=y;i<=m;i++)
		if(s[x][i]=='B')u++;
		else break;
	for(int i=y;i;i--)
		if(s[x][i]=='B')d--;
		else break;
	int dx=pos[0][b],dy=pos[1][b];
	if(dx>=l && dx<=r){
		int c=1;
		for(int i=min(y,dy);i<=max(y,dy);i++)
			if(s[dx][i]!='B')c=0;
		
		if(c)return;
	}
	if(dy>=d && dy<=u){
		int c=1;
		for(int i=min(x,dx);i<=max(x,dx);i++)
			if(s[i][dy]!='B')c=0;
		if(c)return;
	}
	cout<<"NO";
	exit(0);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>(s[i]+1);
	turn_on_clock
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!v[i][j] && s[i][j]=='B')dfs(i,j),cnt++;
	if(cnt>1){
		cout<<"NO";
		return 0;
	}
	if(res==1){
		cout<<"YES";
		return 0;
	}
	for(int i=0;i<res;i++)
		for(int j=i+1;j<res;j++)
			Judge(i,j);
	cout<<"YES";
	//turn_off_clock
	return 0;
}