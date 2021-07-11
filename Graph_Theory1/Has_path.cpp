/*
Code : Has Path
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
First line will contain T(number of test cases), each test case as follow.
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false for each test case in a newline.
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
true
Sample Input 2 :
1
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
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
		//cout<<x<<" ";
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
	int t;
	cin >> t;
	while (t--) {


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
		int v1, v2;
		cin >> v1 >> v2;

		bfs(v, v1, visited);
		if (visited[v1] == true && visited[v2] == true) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
		memset(visited, false, sizeof(visited));
		memset(adj, 0, sizeof(adj));



	}


	return 0;
}