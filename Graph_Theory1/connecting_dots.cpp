/*

onnecting Dots
Send Feedback
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :
Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 400
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1

*/

#include<bits/stdc++.h>
using namespace std;
vector<int>arr[100001];
bool isvalid(int i, int j, int n, int m) {
	return (i >= 0 && i < n && j >= 0 && j < m);
}
vector<int>v;
bool dfs(int node, int parent, bool *visited) {
	visited[node] = true;
	v.push_back(node);
	for (int child : arr[node]) {
		if (visited[child] == 0) {
			if (dfs(child, node, visited)) {
				return true;
			}
		}
		else {
			if (child != parent) {
				if (v.size() >= 3) {
					return true;
				}
			}
		}
	}
	return false;
}


int main() {
	char ar [100][100];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			ar [i][j] = s[j];
			if (isvalid(i, j - 1, n, m) && ar[i][j - 1] == ar[i][j]) {
				arr[i * m + j - 1].push_back(i * m + j);
				arr[i * m + j].push_back(i * m + j - 1);
			}

			if (isvalid(i + 1, j, n, m) && ar[i + 1][j] == ar[i][j]) {
				arr[(i + 1)*m + j].push_back(i * m + j);
				arr[i * m + j].push_back((i + 1)*m + j);
			}

			if (isvalid(i - 1, j, n, m) && ar[i - 1][j] == ar[i][j]) {
				arr[i * m + j].push_back((i - 1)*m + j);
				arr[(i - 1)*m + j].push_back(i * m + j);
			}
			if (isvalid(i, j + 1, n, m) && ar[i][j + 1] == ar[i][j]) {
				arr[i * m + j + 1].push_back(i * m + j);
				arr[i * m + j].push_back(i * m + j + 1);
			}
		}
	}
	bool visited[100001] = {0};
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i * m + j]) {
				flag = dfs(i * m + j, -1, visited);
				if (flag) {
					break;
				}
				v.clear();
			}
		} if (flag)break;
	}
	if (flag)cout << "1\n";
	else cout << "0\n";
}