/*

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the total weight of Minimum Spanning Tree (MST) using Prim's algorithm.
Input Format :
First line will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Weight of MST for each test case in new line.
Constraints :
1 <= T <= 10
2 <= V, E <= 10^5
1 <= wt <= 10^4
Sample Input 1 :
1
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
9

*/

#include<bits/stdc++.h>
using namespace std;

int getMinVertex(bool *visited, int n, int *weight) {
	int minvertex = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && ((minvertex == -1 ) || weight[minvertex] > weight[i])) {
			minvertex = i;
		}
	}
	return minvertex;
}

void prims(int **edge, int n) {
	bool visited[n];
	memset(visited, false, sizeof(visited));

	int parent[n];
	int weight[n];
	for (int i = 0; i < n; i++) {
		weight[i] = INT_MAX;
	}
	parent[0] = -1;
	weight[0] = 0;
	for (int i = 0; i < n - 1; i++) {

		int minvertex = getMinVertex(visited, n, weight);
		visited[minvertex] = true;

		for (int j = 0; j < n; j++) {
			if (edge[minvertex][j] != 0 && !visited[j]) {
				if (weight[j] > edge[minvertex][j]) {
					weight[j] = edge[minvertex][j];
					parent[j] = minvertex;
				}
			}
		}


	}
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum += weight[i];
		//cout<<weight[i]<<" ";
	}
	cout << sum << endl;


}

int main() {
	int t ; cin >> t;
	while (t--) {

		int v, e;
		cin >> v >> e;
		int **edge = new int*[v];
		for (int i = 0; i < v; i++) {
			edge[i] = new int[v];
			for (int j = 0; j < v; j++) {
				edge[i][j] = 0;
			}
		}


		for (int i = 0; i < e; i++) {
			int f, d, w;
			cin >> f >> d >> w;
			if (edge[f][d] != 0) {
				edge[f][d] = min(edge[f][d], w);
				edge[d][f] = min(edge[d][f], w);
			}
			else {

				edge[f][d] = w;
				edge[d][f] = w;
			}
		}
		prims(edge, v);
		for (int i = 0; i < v; i++) {
			delete[] edge[i];
		}
	}

}