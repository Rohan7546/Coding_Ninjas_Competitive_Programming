/*
BOTTOM
Send Feedback
We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.
Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).
Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Format:
First line of input will contain T(number of test case), each test case follows as.
First line will contain two space-separated integers N and M denoting the number of vertex and edges respectively.
Next M line will contain two space separated integers a, b denoting an edge from a to b.
Output Format:
For each test case output the bottom of the specified graph on a single line.
Constraints:
1 <= T <= 50
1 <= N, M <= 10^5
Sample Input:
1
3 6
3 1
2 3
3 2
1 2
1 3
2 1
Sample Output:
1 2 3

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100001], adj_rev[100001];
vector<bool> used;
vector<int> order, component;

bool finans[100001];

void dfs1(int v) {
	used[v] = true;

	for (auto u : adj[v])
		if (!used[u])
			dfs1(u);

	order.push_back(v);
}

void dfs2(int v, int cnt, int* array) {
	used[v] = true;
	array[v] = cnt;
	component.push_back(v);

	for (auto u : adj_rev[v])
		if (!used[u])
			dfs2(u, cnt, array);
}

int main() {
	int t;
	cin >> t;
	while (t--) {

		int n, m;
		cin >> n >> m;



		for (int i = 0; i < m; i++) {

			int a, b; cin >> a >> b;
			a--, b--;



			adj[a].push_back(b);
			adj_rev[b].push_back(a);
		}
		int array[n] = {0};

		used.assign(n, false);

		for (int i = 0; i < n; i++)
			if (!used[i])
				dfs1(i);

		used.assign(n, false);
		reverse(order.begin(), order.end());
		vector<vector<int>>ans;
		int cnt = 0;
		for (auto v : order)
			if (!used[v]) {
				dfs2 (v, cnt++, array);
				finans[cnt - 1] = true;

				ans.push_back(component);
				component.clear();
			}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				if (array[i] != array[adj[i][j]])	{
					finans[array[i]] = false;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (finans[array[i]]) {
				cout << i + 1 << " ";
			}
		} cout << endl;

		used.clear(), component.clear(), order.clear();

		for (int i = 0; i < n; i++) {

			finans[i] = 0;
			adj[i].clear();
			adj_rev[i].clear();
		}

	}

}// for algorithm check cp algo