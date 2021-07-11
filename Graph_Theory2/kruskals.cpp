/*

Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the total weight of Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
struct edge {
	int src;
	int dest;
	int weight;
};
int topmost(int *parent, int n) {

	while (parent[n] != n) {
		n = parent[n];
	}
	return parent[n];

}
bool compare(edge e1, edge e2) {
	return e1.weight < e2.weight;
}

int main() {
	int t;
	cin >> t;
	while (t--) {



		int v, e;
		cin >> v >> e;
		edge arr[e];
		for (int i = 0; i < e; i++) {
			cin >> arr[i].src >> arr[i].dest >> arr[i].weight;
		}

		int parent[v];
		for (int i = 0; i < v; i++) {
			parent[i] = i;
		}
		sort(arr, arr + e, compare);
		int count = 0;
		int sum = 0;
		int i = 0;
		while (count < v - 1) {
			if (topmost(parent, arr[i].src) != topmost(parent, arr[i].dest)) {
				sum += arr[i].weight;
				count++;
				int x = topmost(parent, arr[i].dest);
				parent[x] = topmost(parent, arr[i].src);

				i++;
			}
			else {
				i++;
			}

			// check if we will take v1 and v2
			// if yes make changes to the topmost parent
		}
		cout << sum << endl;
	}

}