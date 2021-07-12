/*

Dominos
Send Feedback
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input Format:
The first line of input contains one integer T, specifying the number of test cases to follow.
Each test case begins with a line containing two integers
The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case.
The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Constraints:
1 <= T <= 50
1 <= N, M <= 10^5
Output Format:
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input 1:
1
3 2
1 2
2 3
Sample Output 2:
1

*/

#include<bits/stdc++.h>
using namespace std;
vector<int>edge[100001];

stack<int>st;
void dfs1(int node , bool *visited) {

	visited[node] = true;
	for (auto u : edge[node]) {
		if (!visited[u]) {
			dfs1(u, visited);
		}
	}
	st.push(node);
}

void dfs2(int node, bool *visited) {
	visited[node] = true;

	for (auto u : edge[node]) {
		if (!visited[u]) {
			dfs2(u, visited);
		}
	}


}




int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			edge[x - 1].push_back(y - 1);

		}
		bool visited[n] = {0};
		for (int i = 0; i < n; i++) { // i got the stack
			if (!visited[i]) {
				dfs1(i, visited);
			}
		}

		memset(visited, false, sizeof(visited));
		int cnt = 0;
		// now visualizing the stack and incrementing the count accordingly
		while (!st.empty()) {
			int x = st.top();
			st.pop();
			if (!visited[x]) {

				dfs2(x, visited);
				cnt++;
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < n; i++) {
			edge[i].clear();

		}




	}
}