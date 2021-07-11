/*
Bellman-Ford Algorithm
Send Feedback
you are given a weighted directed graph G with n vertices and m edges, and two specified vertex src and des. You want to find the length of shortest paths from vertex src to des. The graph may contain the edges with negative weight.
Input Format:
First line of input will contain T(number of test case), each test case follows as.
Line1: contain two space-separated integers N and M denoting the number of vertex and number of edges in graph respectively.
Line2: contain two space-separated integers src, des.
Next M line will contain three space-separated integers a, b, wt representing the edge from a to b with weight wt.
Output Format:
For each test case print the distance of des from src in new line.
Note: In case of no path is found print (10 ^ 9) in that case.
Constraints:
1 <= T <= 100
1 <= N <= 200
1 <= M <= min(800, N*(N-1))
1 <= a,b <= N
-10^5 <= wt <= 10^5
Sample Input:
1
3 6
3 1
3 1 -2
1 3 244
2 3 -2
2 1 201
3 2 220
1 2 223
Sample output:
-2
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ll_MAX LONG_MAX
struct edge {
	ll v1;
	ll v2;
	ll weight;
};
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		ll src, dest;
		cin >> src >> dest;
		edge arr[m];
		for (ll i = 0; i < m; i++) {
			cin >> arr[i].v1 >> arr[i].v2 >> arr[i].weight;
		}
		ll dist[n + 1];
		for (ll i = 0; i <= n; i++) {
			dist[i] = ll_MAX;
		}
		dist[src] = 0;
		for (ll i = 0; i < n - 1; i++) {


			for (ll j = 0; j < m; j++) {
				ll u = arr[j].v1;
				ll v = arr[j].v2;
				ll w = arr[j].weight;
				if (dist[u] != ll_MAX && (dist[v] > dist[u] + w)) {
					dist[v] = dist[u] + w;
				}
			}
		}
		if (dist[dest] != ll_MAX) {
			cout << dist[dest] << endl;
		}
		else {
			cout << 1000000000 << endl;
		}

	}

	return 0;
}