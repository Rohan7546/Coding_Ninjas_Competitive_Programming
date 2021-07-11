/*
Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
First line will contain T(number of test case), each test case follows as.
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0, for each test case in a new line
Constraints :
1 <= T <= 10
1 <= N <= 1000
1 <= M <= 1000
Sample Input :
1
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1

*/

#include<bits/stdc++.h>
using namespace std;
bool dfs(string s, int i, int j, int n, int m, char** res, bool **visited) {

	if (s.length() == 0) {
		return true;
	}

	if (i >= n || j >= m || i < 0 || j < 0) {
		return false;
	}

	int arr1[3] = {i - 1, i, i + 1};
	int arr2[3] = {j - 1, j, j + 1};
	for (int xe = 0; xe < 3; xe++) {

		for (int ye = 0; ye < 3; ye++) {
			int x = arr1[xe];
			int y = arr2[ye];
			if (x == i && y == j) {
				continue;
			}
			if (x < 0 || y < 0 || x >= n || y >= m) {
				continue;
			}

			if (res[x][y] == s[0] && !visited[x][y]) {
				visited[x][y] = true;
				bool find = dfs(s.substr(1), x, y, n, m, res, visited);
				if (find) {
					return find;
				}
				else {
					visited[x][y] = false;
				}
			}



		}
	}
	return false;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		char **edge = new char*[n];
		for (int i = 0; i < n; i++) {
			edge[i] = new char[m];
			string s; cin >> s;
			for (int j = 0; j < m; j++) {
				edge[i][j] = s[j];
			}
		}
		bool **visited = new bool*[1001];
		for (int i = 0; i < 1001; i++) {
			visited[i] = new bool[1001];
			for (int j = 0; j < 1001; j++) {
				visited[i][j] = false;
			}
		}
		bool flag = false;
		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {
				if (edge[i][j] == 'C') {
					bool check = dfs("ODINGNINJA", i, j, n, m, edge, visited);
					if (check) {
						flag = true; break;
					}

				}
			}
			if (flag)break;
		}
		if (flag) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
		for (int i = 0; i < n; i++) {
			delete []edge[i];
		}
		for (int i = 0; i < 1001; i++) {
			delete []visited[i];
		}
	}
}