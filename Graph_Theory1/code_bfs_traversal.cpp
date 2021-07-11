/*
Code : BFS Traversal
Send Feedback
Given an undirected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note :
1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/

#include<bits/stdc++.h>
using namespace std;
int adj[1001][1001];
void bfs(int v, int sv, bool *visited) {
	queue<int>q;
	q.push(sv);
	visited[sv] = true;


	while (!q.empty()) {

		int x = q.front();

		q.pop();
		cout << x << " ";
		for (int i = 0; i < v; i++) {
			if (adj[x][i] == 1) {
				if (!visited[i]) {
					q.push(i);

					visited[i] = true;
				}
			}
		}
	}
}
int main() {

	// write your code here

	int v, e;
	cin >> v >> e;

	memset(adj, 0, sizeof(adj));
	for (int i = 0; i < e; i++) {
		int f, s;
		cin >> f >> s;
		adj[f][s] = 1;
		adj[s][f] = 1;
	}
	bool visited[100001];
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			bfs(v, i, visited);
		}
	}




	return 0;
}