/*
Subset Sum - Problem
Send Feedback
Given an array of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
Input Format
First-line will contain T(number of test cases), each test case consists of three lines.
First-line contains a single integer N(length of input array).
Second-line contains n space-separated integers denoting the elements of array.
The last line contains a single positive integer k.
Output Format
Output Yes if there exists a subset whose sum is k, else output No for each test case in new line.
Constraints:
1 <= T <= 100
1 <= N <= 500
1 <= arr[i] <= 10^4
1 <= K <= 500
Sample Input
1
3
1 2 3
4
Sample Output
Yes
*/
#include<bits/stdc++.h>
using namespace std;
int dp[501][501];
bool sbsum(int *a, int k, int n) {
	if (k == 0) {
		return true;
	}
	if (n <= 0) {
		return false;
	}

	if (dp[n][k] != -1) {
		return dp[n][k];
	}
	if (k >= a[n - 1]) {
		return dp[n][k] = sbsum(a, k - a[n - 1], n - 1) || sbsum(a, k, n - 1);
	}
	else {
		return dp[n][k] = sbsum(a, k, n - 1);
	}

}

int main() {

	// write your code here
	int t;
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		int n;
		cin >> n;
		int sb[n];
		for (int i = 0; i < n; i++) {
			cin >> sb[i];
		}

		int k;
		cin >> k;

		if (sbsum(sb, k, n)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}


	}
	return 0;
}