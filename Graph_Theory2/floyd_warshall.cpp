/*

Floyd-Warshall Algorithm
Send Feedback
You are given an undirected weighted graph G with n vertices. And Q queries, each query consists of two integers a and b and you have print the distance of shortest path between a and b.
Note: If there is no path between a and b print 10^9
Input Format:
First line of Input will contain T(number of test cases), each test case follows as.
Line1: contains two space-separated integers N and M denoting the number of vertex and edge in graph.
Next M line contain three space-separated integers a, b, c denoting the edge between a and b with weight c.
Next line will contain Q (number of queries)
Next Q lines will contain two space-separated integers a and b.
Output Format:
For each query of each test case print the answer in a newline.
Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= M <= 10^4
1 <= Q <= 10^4
1 <= wt <= 10^5 (for each edge)
Note: Graph may contain multiple edges.
Sample Input:
1
3 6
3 1 4
1 3 17
2 3 2
1 3 7
3 2 11
2 3 15
3
1 1
2 2
2 3
Sample output:
0
0
2

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ll_MAX LONG_MAX

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		ll dist[n][n];
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				if (i == j) {
					dist[i][j] = 0; continue;
				}
				dist[i][j] = ll_MAX;
			}
		}
		for (ll i = 0; i < m; i++) {
			ll f, d, w;
			cin >> f >> d >> w;
			f--, d--;
			dist[f][d] = min(dist[f][d], w);
			dist[d][f] = min(dist[f][d], w);
		}
		//floyd warshall begin
		for (ll k = 0; k < n; k++) {
			for (ll i = 0; i < n; i++) {
				for (ll j = 0; j < n; j++) {
					if (dist[i][k] != ll_MAX && dist[k][j] != ll_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		} //end

		ll q;
		cin >> q;
		while (q--) {
			ll a, b;
			cin >> a >> b;
			if (dist[a][b] == ll_MAX)cout << 1000000000;
			else
				cout << dist[a - 1][b - 1] << endl;
		}
	}
}
