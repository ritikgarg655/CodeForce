#include<bits/stdc++.h>
using namespace std;

int factorial(int a){
    return (a==1 or a==0)?1:(a * factorial(a-1))%1000003;
}

int findRank(string A) {
    set<char> sorted;
    for(int i=0;i<A.size();i++){
        sorted.insert(A[i]);
    }
    bool visited[A.size()] = {false};
    int ans = 0;
    for(int j=0;j<A.size();j++){
        int below = 0;
        int it=0;
        for(auto i = sorted.begin();i!=sorted.end();i++){
            if(*i==A[j] and !visited[it]){
                visited[it] = true;
                break;
            }
            it++;
            if(!visited[it-1])
                 below++;
        }
        // cout<<below*factorial(A.size()-1-j)<<endl;
        ans += (below * factorial(A.size()-1-j))%1000003;
    }
    return ans+1;
}

int main(){
    cout<<findRank("VIEW");
}