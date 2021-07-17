/*

XOR of Natural Numbers
Send Feedback
You are given an integer N and asked to find the Xor of first N natural numbers.
Input Format:
The first line of input will contain T(number of test cases), each test case follows as.
The only line of input contains an integer N.
Output Format:
For each test case print the Xor of first N natural number in a new line.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^9
Sample Input:
1
8
Sample Output:
8

*/

#include<bits/stdc++.h>
using namespace std;
int solve(int n) {
	if (n % 4 == 0) {
		return n;
	}
	if (n % 4 == 1) {
		return 1;
	}
	if (n % 4 == 2) {
		return n + 1;
	}
	return 0;
}
int main() {

	// write your code here
	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		cout << solve(n) << endl;

	}
	return 0;
}