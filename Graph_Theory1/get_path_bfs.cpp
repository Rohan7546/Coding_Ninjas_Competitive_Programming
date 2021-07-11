/*
Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
First line of input will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space) for each test case in new line.
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
Sample Output 2 :
*/

#include<bits/stdc++.h>
using namespace std;
int adj[1001][1001];

int main() {
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
		int v1, v2;
		cin >> v1 >> v2;

		map<int, int>mp;
		queue<int>q;
		q.push(v1);
		bool visited[100001];
		vector<int>vect;
		visited[v1] = true;
		bool flag = false;

		memset(visited, false, sizeof(visited));
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			if (x == v2) {
				flag = true; break;
			}

			for (int i = 0; i < v; i++) {
				if (adj[x][i] == 1 && !visited[i]) {
					mp[i] = x;
					q.push(i);
					visited[i] = true;

				}
			}
		}
		int x = v2;
		vect.push_back(x);

		if (flag) {
			while (x != v1) {


				int p = mp[x];
				vect.push_back(p);

				x = p;
			}



			for (auto u : vect) {
				cout << u << " ";
			} cout << endl;
		}



	}
}