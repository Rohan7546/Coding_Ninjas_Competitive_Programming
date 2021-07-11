/*

Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
First line will contain T(number of test case), each test follow as.
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space) for each test case in newline.
Constraints :
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
1
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
1
6 3
5 3
0 1
3 4
0 3

*/

#include<bits/stdc++.h>
using namespace std;
int adj[1001][1001];

vector<int> dfs(int sv, int n, int x, bool *visited) {

	visited[sv] = true;
	if (sv == x) {
		vector<int>v;
		v.push_back(sv);
		return v;

	}

	for (int i = 0; i < n; i++) {
		if (i == sv) {
			continue;
		}
		if (adj[sv][i] == 1 && !visited[i]) {

			vector<int>v;
			v = dfs(i, n, x, visited);
			if (v.size() != 0) {
				v.push_back(sv);
				return v;
			}

		}
	}
	vector<int>v;
	return v;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, e;
		cin >> n >> e;
		memset(adj, 0, sizeof(adj));
		for (int i = 0; i < e; i++) {
			int f, s; cin >> f >> s;
			adj[f][s] = 1;
			adj[s][f] = 1;
		}
		bool visited[10001];
		memset(visited, false, sizeof(visited));
		int v1, v2;
		cin >> v1 >> v2;
		vector<int>v =	dfs(v1, n, v2, visited);

		if (v.size() != 0) {
			for (auto u : v) {
				cout << u << " ";
			} cout << endl;
		}

	}
}