/*

Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 1 to V.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
First line of input will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
For each test case and each connected components print the connected components in sorted order in new line.
Order of connected components doesn't matter (print as you wish).
Constraints :
2 <= V <= 10000
1 <= E <= 10000
Sample Input 1:
1
4 2
2 1
4 3
Sample Output 1:
1 2
4 3

*/

#include<bits/stdc++.h>
using namespace std;

vector<int>vect;
vector<int>edge[10001];
void dfs(int sv, bool *visited) {
	visited[sv] = true;
	vect.push_back(sv);
	for (auto u : edge[sv]) {
		if (!visited[u]) {
			visited[u] = true;
			dfs(u, visited);
		}
	}
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;


		for (int i = 0; i < e; i++) {
			int f, s;
			cin >> f >> s;
			edge[f].push_back(s);
			edge[s].push_back(f);
		}
		int cnt = 0;
		bool visited[10001];
		memset(visited, false, sizeof(visited));
		vector<vector<int>>parent;

		for (int i = 1; i <= v; i++) {
			if (!visited[i]) {
				dfs(i, visited);
				//sort(vect.begin(),vect.end());


				parent.push_back(vect);
				vect.clear();
			}
		}

		for (int i = 0; i < parent.size(); i++) {
			sort(parent[i].begin(), parent[i].end());
			for (int j = 0; j < parent[i].size(); j++) {
				cout << parent[i][j] << " ";
			} cout << endl;
		}
		for (int i = 0; i < 10001; i++) {
			edge[i].clear();
		}



	}
}