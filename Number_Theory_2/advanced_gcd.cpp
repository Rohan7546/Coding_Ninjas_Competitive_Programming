/*

Advanced GCD
Send Feedback
Varun explained its friend Sanchit the algorithm of Euclides to calculate the GCD of two numbers. Then Sanchit implements the algorithm
int gcd(int a, int b)
{

    if (b==0)
    return a;
    else
    return gcd(b,a%b);
}
and challenges to Varun to calculate gcd of two integers, one is a little integer and another integer can have 10^4 digits.
Your task is to help Varun an efficient code for the challenge of Sanchit.
Input Format
The first line of input will contain T(number of the test case), each test case follows as.

Each test case consists of two number A and B.
Output Format:
Print for each pair (A,B) in the input one integer representing the GCD of A and B.
Constraints:
1 <= T <= 100
1 <= A <= 4*10^5
1 <= |B| <= 10^4
where |B| is the length of the integer B
Sample Input:
2
2 6
10 11
Sample Output:
2
1

*/

#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a;
		cin >> a;
		string s;
		cin >> s;
		int ans = 0;
		int mod = a;
		for (int i = 0; i < s.length(); i++) {
			ans = (ans % mod + (s[i] - '0') % mod) % mod;
			if (i != s.length() - 1) {

				ans = (ans % mod * 10 % mod) % mod;
			}
		}
		cout << gcd(a, ans) << endl;
	}
}