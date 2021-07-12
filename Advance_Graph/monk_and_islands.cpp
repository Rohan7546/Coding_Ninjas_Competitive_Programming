/*

Monk and the Islands
Send Feedback
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
Input format:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
Output format:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N
Sample Input
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
Sample Output
2
2

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>arr[100001];



int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		while (m--) {
			ll a, b;
			cin >> a >> b;
			a--; b--;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		ll cnt = 0;
		queue<ll>q;
		q.push(0);
		bool visited[n] = {0};
		ll dist[n] = {0};
		visited[0] = true;

		while (!q.empty()) {
			ll x = q.front();



			q.pop();
			for (auto u : arr[x]) {
				if (!visited[u]) {
					q.push(u);
					dist[u] = dist[x] + 1;
					//	cout<<u<<" ";
					visited[u] = true;
				}
			}//cout<<endl;//
		}



		cout << dist[n - 1] << endl;
		for (ll i = 0; i < n; i++) {
			arr[i].clear();



		}
	}
}