/*
Largest Piece
Send Feedback
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Input Format :
First line will contain T(number of test cases), each test case follows as.
Line 1 : An integer N denoting the size of cake
Next N lines : N characters denoting the cake
Output Format :
Print the size of the biggest piece of '1's and no '0'sfor each test case in a newline.
Constraints:
1 <= T <= 10
1 <= N <= 1000
Sample Input :
1
2
11
01
Sample Output :
3
*/

#include<bits/stdc++.h>
using namespace std;
const int mex = 1e3 + 1;
int arr[mex][mex];
int dfs(int i, int j, int n, int m, bool visited[][mex]) {
	if (arr[i][j] == 0) {
		return 0;
	}
	visited[i][j] = true;
	if (i >= n || j >= m || i < 0 || j < 0) {
		return 0;
	} int  w = 0, x = 0, y = 0, z = 0;
	if (j + 1 < m && arr[i][j + 1] == 1 && !visited[i][j + 1]) {
		x = 1 + dfs(i, j + 1, n, m, visited);
	}
	if (j - 1 >= 0 && arr[i][j - 1] == 1 && !visited[i][j - 1]) {
		y = 1 + dfs(i, j - 1, n, m, visited);
	}
	if (i + 1 < n && arr[i + 1][j] == 1 && !visited[i + 1][j]) {
		z = 1 + dfs(i + 1, j, n, m, visited);
	}
	if (i - 1 >= 0 && arr[i - 1][j] == 1 && !visited[i - 1][j]) {
		w = 1 + dfs(i - 1, j, n, m, visited);
	}
	return x + y + z + w;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				arr[i][j] = s[j] - '0';
			}
		}
		bool visited[mex][mex];
		int maxm = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && arr[i][j] == 1) {
					maxm = max(maxm, 1 + dfs(i, j, n, n, visited));
				}
			}
		}
		cout << maxm << endl;
	}
}