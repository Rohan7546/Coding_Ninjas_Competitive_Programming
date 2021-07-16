/*
Knapsnack - Problem
Send Feedback
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Note: Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
1 <= W <= 1000
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/

#include<bits/stdc++.h>
using namespace std;
int dp[10001][1001];
int knapsack(int *W, int *V, int maxW, int n) {
	if (n <= 0) {
		return 0;
	}

	if (dp[n][maxW] != -1) {
		return dp[n][maxW];
	}

	if (maxW >= W[n - 1]) {
		return dp[n][maxW] = max(V[n - 1] + knapsack(W, V, maxW - W[n - 1], n - 1), knapsack(W, V, maxW, n - 1));
	}
	else {
		return dp[n][maxW] = knapsack(W, V, maxW, n - 1);
	}
}

int main() {

	// write your code here
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	int W[n];
	for (int i = 0; i < n; i++) {
		cin >> W[i];
	}
	int V[n];
	for (int i = 0; i < n; i++) {
		cin >> V[i];
	}
	int maxW;
	cin >> maxW;
	cout << knapsack(W, V, maxW, n);



	return 0;

}