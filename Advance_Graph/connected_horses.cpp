/*

Connected Horses
Send Feedback
You all must be familiar with the chess-board having 8 x 8 squares of alternate black and white cells. Well, here we have for you a similar N x M size board with similar arrangement of black and white cells.
A few of these cells have Horses placed over them. Each horse is unique. Now these horses are not the usual horses which could jump to any of the 8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Since this answer may be quite large, calculate in modulo 10^9+7.
Input Format:
First line contains T which is the number of test cases.
T test cases follow first line of each containing three integers N, M and Q where N,M is the size of the board and Q is the number of horses on it.
Q lines follow each containing the 2 integers, X and Y which are the coordinates of the Horses.
Output format:
For each test case, output the number of photographs taken by a photographer in new line.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
Sample Input:
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
Sample Output:
4
2

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll arr[1001][1001];


ll fact(ll n) {
	ll s = 1;
	for (ll i = 2; i <= n; i++) {
		s *= i;
		s %= mod;
	}
	return s;
}

ll find(ll i, ll j, ll n, ll m) {
	arr[i][j] = -1;
	ll total = 1;
	if (i - 2 >= 1 && j + 1 <= m && arr[i - 2][j + 1] == 1)
	{
		total += find(i - 2, j + 1, n, m);
	}
	if (i - 2 >= 1 && j - 1 >= 1 && arr[i - 2][j - 1] == 1)
	{
		total += find(i - 2, j - 1, n, m);
	}
	if (i + 2 <= n && j + 1 <= m && arr[i + 2][j + 1] == 1)
	{
		total += find(i + 2, j + 1, n, m);
	}
	if (i + 2 <= n && j - 1 >= 1 && arr[i + 2][j - 1] == 1)
	{
		total += find(i + 2, j - 1, n, m);
	}

	if (i - 1 >= 1 && j + 2 <= m && arr[i - 1][j + 2] == 1)
	{
		total += find(i - 1, j + 2, n, m);
	}
	if (i - 1 >= 1 && j - 2 >= 1 && arr[i - 1][j - 2] == 1)
	{
		total += find(i - 1, j - 2, n, m);
	}
	if (i + 1 <= n && j + 2 <= m && arr[i + 1][j + 2] == 1)
	{
		total += find(i + 1, j + 2, n, m);
	}
	if (i + 1 <= n && j - 2 >= 1 && arr[i + 1][j - 2] == 1)
	{
		total += find(i + 1, j - 2, n, m);
	}
	return total;
}


int main() {

	ll t;
	cin >> t;
	while (t--) {
		ll n, m, q;
		cin >> n >> m >> q;

		memset(arr, 0, sizeof(arr));
		while (q--) {
			ll f, d;
			cin >> f >> d;
			arr[f][d] = 1;

		}
		ll ans = 1;

		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					ll cnt = find(i, j, n, m);
					ans *= (fact(cnt));
					ans %= mod;
				}
			}
		}

		cout << ans << endl;

	}
}