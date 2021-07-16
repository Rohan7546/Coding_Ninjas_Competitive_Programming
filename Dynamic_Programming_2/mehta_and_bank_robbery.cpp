/*
Mehta and Bank Robbery - Problem
Send Feedback
One fine day, when everything was going good, Mehta was fired from his job and had to leave all the work. So, he decided to become a member of gangster squad and start his new career of robbing. Being a novice, mehta was asked to perform a robbery task in which he was given a bag having a capacity W units. So, when he reached the house to be robbed, there lay N items each having particular weight and particular profit associated with it. But, theres a twist associated, He has first 10 primes with him, which he can use atmost once, if he picks any item x, then he can multiply his profit[x] with any of the first 10 primes and then put that item into his bag. Each prime can only be used with one particular item and one item can only have atmost one prime multiplied with its profit. Its not necessary to pick all the items. If he doesnt want to use a prime with any particular item, he can simply add the profit as it is, more specifically, 1*profit[x] for xth item will get added to its total profit, and that he can do with as many items as he wants. He cannot fill his bag more than weight W units. Each item should be picked with its whole weight, i.e it cannot be broken into several other items of lesser weight. So, now to impress his squad, he wishes to maximize the total profit he can achieve by robbing this wealthy house.
Input Format:
The first line of input will contain T(number of test cases), each test will follow as.
First Line will contain two integers N and W (number of items and maximum weight respectively).
Second-line will contain N space-separated integers denoting the profit associated with the Ith item.
The third line will contain N space-separated integers denoting the weight of the Ith item.
Output Format:
Output the maximum profit obtainable for each test case in a new line.
Constraints:
1 <= T <= 20
1 <= N, W <= 500
1 <= profit[i] <= 10^4
1 <= weight[i] <= 10^4
Sample Input:
1
7 37
33 5 14 14 16 25 15
5 19 30 4 15 31 25
Sample output:
1591
*/




#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct knap {
	ll value, weight;
};
bool compare(knap k1, knap k2) {
	return k1.value < k2.value;
}
ll DP(knap* arr, int n, ll w, int prime[11]) {
	ll*** dp = new ll**[2];
	dp[0] = new ll*[n + 1];
	dp[1] = new ll*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		dp[0][i] = new ll[w + 1]();
		dp[1][i] = new ll[w + 1]();
	}

	for (int r = 1; r < n + 1; r++) {
		for (int c = 1; c < w + 1; c++) {
			dp[0][r][c] = dp[0][r - 1][c];
			if (c - arr[r - 1].weight >= 0)
				dp[0][r][c] = max(dp[0][r - 1][c], dp[0][r - 1][c - arr[r - 1].weight] + arr[r - 1].value);
		}
	}
	int k = 1;
	while (k < 11)
	{
		int v = k % 2;
		for (int r = 1; r < n + 1; r++) {
			for (int c = 1; c < w + 1; c++) {

				dp[v][r][c] = dp[v][r - 1][c];

				if (c - arr[r - 1].weight >= 0)
					dp[v][r][c] = max(dp[v][r - 1][c] , max(dp[v][r - 1][c - arr[r - 1].weight] + arr[r - 1].value ,
					                                        dp[v ^ 1][r - 1][c - arr[r - 1].weight] + prime[k] * arr[r - 1].value));
			}
		}
		k++;
	}
	return dp[0][n][w];
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, w;
		cin >> n >> w;
		knap* arr = new knap[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i].value;
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i].weight;
		}
		sort(arr, arr + n, compare);
		int prime[11] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
		cout << DP(arr, n, w, prime) << "\n";
	}

	return 0;
}
//credits to TA