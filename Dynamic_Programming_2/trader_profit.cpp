/*
Trader Profit
Send Feedback
Mike is a stock trader and makes a profit by buying and selling stocks. He buys a stock at a lower price and sells it at a higher price to book a profit. He has come to know the stock prices of a particular stock for n upcoming days in future and wants to calculate the maximum profit by doing the right transactions (single transaction = buying + selling). Can you help him maximize his profit?
Note: A transaction starts after the previous transaction has ended. Two transactions can't overlap or run in parallel.
The stock prices are given in the form of an array A for n days.
Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions.
Input Format:
The first line of input contains an integer T(number of test cases).

The first line of each test case contains a positive integer k, denoting the number of transactions.

The second line of each test case contains a positive integer n, denoting the length of the array A.

The third line of each test case contains n space-separated positive integers, denoting the prices of each day in the array A.
Output Format
For each test case print the maximum profit earned by Mike on a new line.
Constraints:
1 <= T <= 10^3
0 < k <= 10

2 <= n <= 10^4

0 <= elements of array A <= 10^5
Sample Input
3
2
6
10 22 5 75 65 80
3
4
20 580 420 900
1
5
100 90 80 50 25
Sample Output
87
1040
0
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10001][11][2];

ll transaction (ll *a, ll n, ll k, ll cur_status) {
	if (k <= 0) {
		return 0;
	}
	if (n == 0) {
		return 0;
	}
	if (dp[n][k][cur_status] != -1) {
		return dp[n][k][cur_status];
	}


	if (cur_status) {
		return dp[n][k][cur_status] = max(transaction(a + 1, n - 1, k, 1), transaction(a + 1, n - 1, k - 1, 0) + a[0]);
	}
	else {
		if (k > 0) {
			return dp[n][k][cur_status] = max(transaction(a + 1, n - 1, k, 0), transaction(a + 1, n - 1, k, 1) - a[0]);
		}
	}
}
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		ll a[m];
		for (ll i = 0; i < m; i++) {
			cin >> a[i];
		}

		memset(dp, -1, sizeof(dp));
		cout << transaction(a, m, n, 0) << "\n";
	}
}