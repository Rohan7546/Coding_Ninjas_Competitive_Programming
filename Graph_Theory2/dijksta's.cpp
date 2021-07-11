/*
Dijkstra's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
First line will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
1 <= T <= 10
2 <= V, E <= 10^3
Sample Input 1 :
1
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/

#include<bits/stdc++.h>
using namespace std;


int getvertex(bool *visited, int n, int *dist) {
	int vertex = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && (vertex == -1 || dist[vertex] > dist[i])) {
			vertex = i;
		}
	}
	return vertex;
}




int main() {
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;
		int edge[v][v];
		memset(edge, 0, sizeof(edge));
		for (int i = 0; i < e; i++) {
			int f, d, w;
			cin >> f >> d >> w;
			edge[f][d] = w;
			edge[d][f] = w;
		}
		int dist[v];
		for (int i = 0; i < v; i++) {
			dist[i] = INT_MAX;
		}
		dist[0] = 0;
		bool visited[v];
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < v - 1; i++) {
			int vertex = getvertex(visited, v, dist);
			visited[vertex] = true;


			for (int j = 0; j < v; j++) {
				if (edge[vertex][j] != 0 && !visited[j]) {
					dist[j] = min(dist[j], dist[vertex] + edge[vertex][j]);
				}
			}
		}



		for (int i = 0; i < v; i++) {
			cout << i << " " << dist[i] << endl;
		}



	}
}