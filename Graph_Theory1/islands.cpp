/*

Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 0 to N - 1) and M pair of integers (u and v) denoting island, u is connected to island v and vice versa. Can you count the number of connected groups of islands?
Input Format:
The first line of input will contain T(number of test cases), each test case follows as.
Line 1: Two Integers N and M (separated by space)
Next 'E' lines, each have two space-separated integers, 'u' and 'v', denoting that there exists an edge between Vertex 'u' and Vertex 'v'.
Output Format:
Print number of Islands for each test case in new line.
Constraints:
1 <= T <= 10
1 <= N <= 1000
1 <= M <= min((N*(N-1))/2, 1000)
0 <= u[i] ,v[i] < N
Output Return Format :
The count the number of connected groups of islands
Sample Input :
1
2 1
1 2
Sample Output :
1

*/

#include<bits/stdc++.h>
using namespace std;
vector<int>edge[10001];
void dfs(int node, bool * visited) {
	visited[node] = true;
	for (auto u : edge[node]) {
		if (!visited[u]) {
			dfs(u, visited);
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
			int f, s;
			cin >> f >> s;
			edge[f].push_back(s);
			edge[s].push_back(f);
		}

		bool visited[100001];
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				cnt++;
				dfs(i, visited);
			}
		}
		cout << cnt << endl;


		for (int i = 0; i < 10001; i++) {
			edge[i].clear();
		}
	}

	// write your code here
	return 0;
}