/*
Edges in MST
Send Feedback
You are given a connected weighted undirected graph without any loops and multiple edges.
Let us remind you that a graph's spanning tree is defined as an acyclic connected subgraph of the given graph that includes all of the graph's vertexes. The weight of a tree is defined as the sum of weights of the edges that the given tree contains. The minimum spanning tree (MST) of a graph is defined as the graph's spanning tree having the minimum possible weight. For any connected graph obviously exists the minimum spanning tree, but in the general case, a graph's minimum spanning tree is not unique.
Your task is to determine the following for each edge of the given graph: whether it is either included in any MST, or included at least in one MST, or not included in any MST.
Input Format:
The first line contains two space-separated integers n and m — the number of the graph's vertexes and edges, correspondingly.
 Then follow m lines, each of them contains three integers — the description of the graph's edges as "ai bi wi", where ai and bi are the numbers of vertexes connected by the i-th edge, wi is the edge's weight.
Output Format:
Print m lines — the answers for all edges. If the i-th edge is included in any MST, print "any"; if the i-th edge is included at least in one MST, print "at least one"; if the i-th edge isn't included in any MST, print "none". Print the answers for the edges in the order in which the edges are specified in the input.
Constraints:
 1 <= N, M <= 10^5
 1 <= a, b <= N
 1 <= w[i] <= 10^6
 Graph is connected and does not contain self loops and multiple edges.
Sample Input:
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
Sample Output:
none
any
at least one
at least one
any
*/
#include<bits/stdc++.h>
using namespace std;
const int mex = 1e5 + 5;
int par[mex];


int findparent(int a) {
	if (par[a] == a) {
		return a;
	}
	return par[a] = findparent(par[a]);
}

void Union(int a, int b) {
	int pa = findparent(a);
	int pb = findparent(b);
	par[pb] = pa;
}

vector<pair<int, int>>g[mex];
vector<pair<int, pair<int, pair<int, int>>>>edge;
int tin[mex], up[mex];
int ans[mex];
int t;

void dfs(int n, int id) {
	tin[n] = up[n] = ++t;
	for (int i = 0; i < g[n].size(); i++) {
		int v = g[n][i].first;
		int iid = g[n][i].second;

		if (id == iid) {
			continue;
		}
		if (!tin[v]) {
			dfs(v, iid);
			up[n] = min(up[n], up[v]);

			if (up[v] > tin[n]) {
				ans[iid] = 1;
			}
		}
		else {
			up[n] = min(up[n], tin[v]);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({w, {u, {v, i}}});
	}
	sort(edge.begin(), edge.end());

	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	int i;
	for (i = 0; i < m;) {
		int j = i;
		while (j + 1 < m && edge[i].first == edge[j + 1].first)
			j++;

		for (int k = i; k <= j; k++) {
			int u = edge[k].second.first;
			int v = edge[k].second.second.first;
			int id = edge[k].second.second.second;
			int w = edge[k].first;
			int pa = findparent(u);
			int pb = findparent(v);
			if (pa == pb) {
				ans[id] = 3;
			}
			else {
				ans[id] = 2;
				tin[pa] = tin[pb] = 0;
			}
			g[pa].clear();
			g[pb].clear();

		}

		for (int k = i; k <= j; k++) {
			int u = edge[k].second.first;
			int v = edge[k].second.second.first;
			int id = edge[k].second.second.second;
			int w = edge[k].first;
			int pa = findparent(u);
			int pb = findparent(v);
			if (pa != pb) {
				g[pa].push_back({pb, id});
				g[pb].push_back({pa, id});
			}
		}
		t = 0;
		for (int k = i; k <= j; k++) {
			int u = edge[k].second.first;
			int v = edge[k].second.second.first;
			int pa = findparent(u);
			int pb = findparent(v);
			if (!tin[pa]) {
				dfs(pa, 0);
			}
		}

		for (; i <= j; i++) {
			int u = edge[i].second.first;
			int v = edge[i].second.second.first;
			Union(u, v);
		}
	}
	for (int i = 1; i <= m; i++) {
		if (ans[i] == 1) {
			cout << "any\n";
		}
		else if (ans[i] == 2) {
			cout << "at least one\n";
		}
		else if (ans[i] == 3) {
			cout << "none\n";
		}
	}
}