#include<bits/stdc++.h>
using namespace std;

# V is sorted 
# V.size() = N
# The function is initially called as so_something(V, k, 0, N-1)
 
int so_something(vector<int> &V, int k, int start_index, int end_index) {
    if (start_index > end_index) return 0;
    int mid_index = (start_index + end_index) / 2;
    if (V[mid_index] < k) return so_something(V, k, mid_index + 1, end_index);
    if (V[mid_index] > k) return so_something(V, k, start_index, mid_index - 1);
    return so_something(V, k, start_index, mid_index - 1) + 1 + so_something(V, k, mid_index + 1, end_index);
}

int main(){
	int n;
	cin>>n;
	int arr[5] = {1,2,3,4,5};
int val2 = 0;
for(int val1 = 0; val1 < n; val1++) {
    while(val2 < n && arr[val2] < arr[val2]) {
        val2++;
    }
}
	return 0;
}