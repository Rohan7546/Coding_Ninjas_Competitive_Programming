/*
Distinct Subsequences
Send Feedback
Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
Input Format:
First line of input contains an integer T which is equal to the number of test cases.
Each of next T lines contains a string s.
Output Format:
Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large, you need to output ans%(10^9 + 7) where ans is the number of distinct subsequences.
Constraints:
T ≤ 100
1 <= length(S) ≤ 10^5
All input strings shall contain only uppercase letters.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
int main() {
	ll t;
	cin >> t;
	while (t--) {

		string s;
		cin >> s;
		ll l = s.length();
		ll dp[l + 1];
		dp[0] = 1;
		unordered_map<char, ll>mp;
		for (ll i = 1; i <= l; i++) {
			dp[i] = (2 * dp[i - 1]) % mod;
			if (mp.count(s[i - 1])) {
				ll j = mp[s[i - 1]];
				dp[i] -= dp[j - 1];
				dp[i] = (dp[i] + mod) % mod;
			}
			mp[s[i - 1]] = i;

		}
		cout << dp[l] << "\n";
	}
	return 0;
}