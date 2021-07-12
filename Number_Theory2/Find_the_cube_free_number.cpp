/*

Find The Cube Free Number
Send Feedback
A cube free number is a number who’s none of the divisor is a cube number (A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. Given a positive number you have to say if its a cube free number and if yes then tell its position among cube free numbers.
Note: we will consider 1 as the 1st cube free number
Input Format:
First line of the test case will be the number of test case T
Each test case contain an integer N
Output Format:
For each test case print the position of N in cube free numbers and if its not a cube free number print "Not Cube Free" in a newline.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^6
Sample Input:
10
1
2
3
4
5
6
7
8
9
10
Sample Output:
1
2
3
4
5
6
7
Not Cube Free
8
9

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void calc(ll dp1[]) {
	ll  dp[1000007] = {0};
	for (ll i = 2; i <= 100; i++) {
		ll k = i * i * i;
		for (ll j = k; j <= 1000000; j += k) {
			dp[j] = -1;
		}
	}
	int cnt = 0;
	for (ll i = 0; i < 1000007; i++) {
		if (dp[i] == -1) {
			dp1[i] = -1;
			cnt++;
		}
		else {
			dp1[i] = cnt;
		}

	}



}

int main() {
	ll dp[1000007];
	calc(dp);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (dp[n] == -1) {
			cout << "Not Cube Free" << endl;
		}
		else {
			cout << n - dp[n] << endl;
		}
	}
	// write your code here
	return 0;
}