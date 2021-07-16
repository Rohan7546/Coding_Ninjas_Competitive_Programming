/*
Charlie and Pilots
Send Feedback
Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.
Input Format:
First line will contain T(number of test case), each test case as follow.
The first line of each test case contains integer N, N is even, the number of pilots working for the Charlie's company.
The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, a salary as a captain (X) and a salary as an assistant (Y).
Constraints
1 <= T <= 20
2 ≤ N ≤ 1000
1 ≤ Y < X ≤ 100000
Output Format:
For each test case print the minimal amount of money Charlie needs to give for the pilots' salaries. in newline.
Sample Input
1
4
5000 3000
6000 2000
8000 1000
9000 6000
Sample Output
19000
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int calc_pil(int *as, int *cp, int n, int i) {
	if (n == 0)return 0;

	if (dp[n][i] != -1)return dp[n][i];

	if (i == 0) {
		return dp[n][i] = as[0] + calc_pil(as + 1, cp + 1, n - 1, 1);
	}
	else if (i == n) {
		return dp[n][i] = cp[0] + calc_pil(as + 1, cp + 1, n - 1, i - 1);
	}

	return dp[n][i] = min(as[0] + calc_pil(as + 1, cp + 1, n - 1, i + 1), cp[0] + calc_pil(as + 1, cp + 1, n - 1, i - 1));
}


int main() {
	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		int as[n];
		int cp[n];
		for (int i = 0; i < n; i++) {
			cin >> cp[i] >> as[i];
		}
		memset(dp, -1, sizeof(dp));
		cout << calc_pil(as, cp, n, 0) << "\n";
	}
}