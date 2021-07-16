/*

Edit Distance - Problem
Send Feedback
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
First line of input will contain T (number of test cases), each test case consists of two lines.
Line 1 : String s
Line 2 : String t
Output Format :
For each test case print the Edit Distance value in new line.
Constraints:
1 <= T <= 100
1<= m,n <= 100
Sample Input 1 :
1
abc
dc
Sample Output 1 :
2

*/

#include<bits/stdc++.h>
using namespace std;
int main() {

	// write your code here
	int q;
	cin >> q;
	while (q--) {
		string s;
		string t;
		cin >> s >> t;
		int n = s.length();
		int m = t.length();
		int dp[n + 1][m + 1];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0 ) {
					dp[i][j] = j;
				}
				else if (j == 0) {
					dp[i][j] = i;
				}
				else if (s[i - 1] == t[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
				}
			}
		}
		cout << dp[n][m] << endl;



	}
	return 0;
}