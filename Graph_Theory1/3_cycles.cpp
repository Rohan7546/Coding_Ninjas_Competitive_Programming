/*

3 Cycle
Send Feedback
Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Return Format :
The count the number of 3-cycles in the given Graph
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1

*/

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int arr[n + 1][n + 1];
	int xe[m];
	int ye[m];
	for (int i = 0; i < m; i++) {
		cin >> xe[i];
	}
	memset(arr, 0, sizeof(arr));
	for (int j = 0; j < m; j++) {
		cin >> ye[j];
		arr[xe[j]][ye[j]] = 1;
		arr[ye[j]][xe[j]] = 1;
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ( arr[i][j] == 1) {
				for (int k = 1; k <= n; k++) {

					if (i != k && arr[j][k] == 1 && arr[i][k] == 1) {
						count++;
					}
				}
			}
		}
	}
	cout << count / 6 << endl;; // each cycle is getting counted 6 times due to its 3 elements
}