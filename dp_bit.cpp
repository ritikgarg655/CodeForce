#include <bits/stdc++.h>

using namespace std;

#define N 105
#define M 1<<17
#define MAX 60
#define PRIMESIZE 17
#define INF INT_MAX

typedef long long ll;

int n, a[N], b[N], dp[N][M], factorMask[MAX];
int primes[PRIMESIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

void computeFactorMask() {
    for(int i=1;i<MAX;i++){
        for(int j=0;j<PRIMESIZE;j++){
            if(i%primes[j] == 0) {
                factorMask[i] |= 1<<j;
            }
        }
    }
}

int computeMinSum(int index, int mask, int n, int a[]) {
    if(index >= n) {
        return 0;
    }
    if(dp[index][mask] != -1) {
        return dp[index][mask];
    }
    dp[index][mask] = INF;
    for(int bi=1;bi<2*a[index];bi++){
        int primeFactorMask = factorMask[bi];
        if((mask & primeFactorMask) == 0){
            dp[index][mask] = min(dp[index][mask], abs(a[index]-bi) +
                                                   computeMinSum(index+1, mask|primeFactorMask, n, a));
        }
    }
    return dp[index][mask];

}

void findArrayBUtil(int index, int mask, int n, int a[], int minSum) {
    if(index >= n) {
        return;
    }
    for(int bi=1;bi<2*a[index];bi++) {
        int primeFactorMask = factorMask[bi];
        if((primeFactorMask & mask) == 0) {
            int newMask = mask | primeFactorMask;
            if(abs(a[index]-bi) + dp[index+1][newMask] == minSum) {
                b[index] = bi;
                findArrayBUtil(index+1, newMask, n, a, minSum - abs(a[index]-bi));
                return;
            }
        }
    }
}

void findArrayB() {
    int minSum = computeMinSum(0, 0, n, a);
    findArrayBUtil(0, 0, n, a, minSum);
}

void printArrayB() {
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(i >= n)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }

    computeFactorMask();
    findArrayB();

    printArrayB();

    return 0;

}