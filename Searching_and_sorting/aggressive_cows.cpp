/*
Aggressive Cows Problem
Send Feedback
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input Format:
The first line of input contains number of test cases, which will be denoted by the symbol t. In the following lines, the t test cases are written.
The first line of each of the test cases contain two space separated integers: N and C. The following line contains N space separated integers, where the ith integer denote the position of ith stall.
It is given that sum of N over all the test cases doesn't exceed 1000, 000.
Output Format:
As described in the problem statement, the first and only line of output will print the largest minimum distance possible.
The output for each test case will be printed on a separate line.
Sample Input 1:
2
11 3
15 5 2 4 17 16 12 8 19 18 11
15 13
20 8 16 3 13 9 11 10 15 17 18 14 1 2 5
Sample Output 1:
8
1
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}


int main() {
	//debugMode();
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		ll n, c;
		cin >> n >> c;
		ll a[n];
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];


		}
		sort(a, a + n);
		ll start = 0;
		ll end = *max_element(a, a + n);
		ll ans;
		while (start <= end) {
			ll mid = (start + end) / 2;

			int count = 1;
			ll fp = a[0];
			for (int i = 1; i < n; i++) {
				if (abs(a[i] - fp) >= mid) {
					count++;
					fp = a[i];

				}
				else {
					continue;
				}
				if (count == c) {break;}
			}

			if (count == c) {
				ans = mid;
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}



		}


		cout << ans << endl;

	}

}