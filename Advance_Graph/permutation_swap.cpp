/*
Permutation Swaps
Send Feedback
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.
He also believes that there are M good pairs of integers (ai, bi). Kevin can perform following operation with his permutation:
Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.
Input format:
The first line of input will contain an integer T, denoting the number of test cases.

Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi. The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.
Output format:
For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.
Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 100000
1 ≤ M ≤ 100000
1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
1 ≤ ai < bi ≤ N
Time Limit: 1 second
Sample Input 1:
2
4 1
1 3 2 4
1 4 2 3
3 4
4 1
1 3 2 4
1 4 2 3
2 4
Sample Output 1:
NO
YES
*/

// find connected components of graph
// for each of the componentes find the elements at those indices in p
// check for the indices in q if they have the same element, then yes otherwise no
#include<bits/stdc++.h>
using namespace std;
vector<int>arr[100001];

void dfs(int node, bool *visited, vector<int>&v) {

	v.push_back(node);
	visited[node] = true;
	for (auto u : arr[node]) {
		if (!visited[u]) {
			dfs(u, visited, v);
		}
	}


}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int p[n];
		int Q[n];
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> Q[i];
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			arr[x - 1].push_back(y - 1);
			arr[y - 1].push_back(x - 1);
		}
		vector<vector<int>>ans;
		bool visited[n] = {0};

		for (int i = 0; i < n; i++)
		{	if (!visited[i]) {

				vector<int>v;
				dfs(i, visited, v);

				ans.push_back(v);
			}
		}

		map<int, int>mp1;
		map<int, int>mp2;
		bool flag = true;
		for (int i = 0; i < ans.size(); i++) {
			for (auto u : ans[i]) {

				mp1[p[u]]++;
				mp2[Q[u]]++;
			}
			for (auto u : mp1) {
				if (mp2[u.first] == 0) {

					flag = false;
					break;
				}
			}
			mp1.clear();
			mp2.clear();
			if (!flag) {
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		for (int i = 0; i < n; i++) {
			arr[i].clear();
		}
	}
}

