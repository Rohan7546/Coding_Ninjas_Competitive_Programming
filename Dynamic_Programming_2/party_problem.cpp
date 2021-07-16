/*
PARTY - Problem
Send Feedback
You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.
Input Format:
First line of input will contain an integer N (number of parties).
Next line of input will contain N space-separated integers denoting the entry fee of Ith party.
Next line will contain N space-separated integers denoting the amount of fun Ith party provide.
Last line of input will contain an integer W party budget.
Output Format:
For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated by a single space.
Note: In case of multiple cost provides the maximum fun output the minimum total cost.
Sample Input:
5
1 7 9 7 2
5 5 2 4 7
12
Sample Output:
10 17
*/

#include<bits/stdc++.h>
using namespace std;
int main() {

	// write your code here
	int n;
	cin >> n;
	int fee[n];
	for (int i = 0; i < n; i++) {
		cin >> fee[i];
	}
	int fun[n];
	for (int i = 0; i < n; i++) {
		cin >> fun[i];
	}
	int budget;
	cin >> budget;
	int cost = 0;
	int dp[n + 1][budget + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= budget; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if (fee[i - 1] <= j) {
				dp[i][j] = max(dp[i - 1][j], fun[i - 1] + dp[i - 1][j - fee[i - 1]]);

			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			//cout<<dp[i][j]<<" ";
		}//cout<<endl;

	}
	cost = 1000001;
	int fun_value = dp[n][budget];
	for (int i = 1; i <= budget; i++) {
		if (dp[n][i] == fun_value) {
			cost = min(cost, i);
		}
	}
	cout << cost << " " << dp[n][budget];
	return 0;
}