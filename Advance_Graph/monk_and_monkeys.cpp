/*
Kingdom Of Monkeys
Send Feedback
This is the story in Zimbo, the kingdom officially made for monkeys. Our Code Monk visited Zimbo and declared open a challenge in the kingdom, thus spoke to all the monkeys :
You all have to make teams and go on a hunt for Bananas. The team that returns with the highest number of Bananas will be rewarded with as many gold coins as the number of Bananas with them. May the force be with you!
Given there are N monkeys in the kingdom. Each monkey who wants to team up with another monkey has to perform a ritual. Given total M rituals are performed. Each ritual teams up two monkeys. If Monkeys A and B teamed up and Monkeys B and C teamed up, then Monkeys A and C are also in the same team.
You are given an array A where Ai is the number of bananas i'th monkey gathers.
Find out the number of gold coins that our Monk should set aside for the prize.
Input Format:
First line contains an integer T. T test cases follow.
First line of each test case contains two space-separated N and M. M lines follow.
Each of the M lines contains two integers Xi and Yi, the indexes of monkeys that perform the i'th ritual.
Last line of the testcase contains N space-separated integer constituting the array A.
Output Format:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
0 ≤ M ≤ 10^5
0 ≤ Ai ≤ 10^9
Sample Input:
1
4 3
1 2
2 3
3 1
1 2 3 5
Sample Output:
6
Explanation:
Monkeys 1,2 ,3 are in the same team. They gather 1+2+3=6 bananas.
Monkey 4 is a team. It gathers 5 bananas.
Therefore, number of gold coins (highest number of bananas by a team) = 6.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>arr[100001];
int arrB[100001];
void dfs(int node, bool *visited, int &cnt) {
	visited[node] = true;
	cnt += arrB[node - 1];
	for (auto u : arr[node]) {
		if (!visited[u]) {
			dfs(u, visited, cnt);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		while (m--) {
			int a, b;
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		for (int i = 0; i < n; i++) {
			cin >> arrB[i];
		}
		int ans = 0;
		bool visited[n + 1];
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				int cnt = 0;
				dfs(i, visited, cnt);
				ans = max(ans, cnt);
			}
		}

		cout << ans << endl;
		for (int i = 0; i < n; i++) {
			arr[i].clear();
			arrB[i] = 0;
		}


	}
}