/*

Winning Strategy
Send Feedback
The college team, along with their coach, is going to the sports fest to play a football match. There are n players in the team, numbered from 1 to n.
Someone gives a paper to the coach. The paper elaborates on the positions and strategies of the opponent team. Based on it, the coach creates a winning strategy. In that strategy, he decides and gives a particular position to every player.
After this, the coach starts swapping two players at a time to make them stand according to new positions decided on paper.
He swaps players by applying following rules:
1. Any player can swap with the player standing next to him.
2. One player can swap with at most two other players.
Given that initially all the players are standing linearly, numbered from 1 to n, you have to tell whether it is possible for the coach to create new positions by swapping within the constraints defined in the task.
Input Format
The first line of input will contain an integer, that denotes the value of the number of test cases. Let us denote the number of test cases by the symbol T.
Each of the following T test cases consists of two lines. The first line of each test case contains an integer n, that denotes the number of players in the team. The following line contains n space separated integers, denoting the specific position of players in winning strategy.
Output Format
For each test case, if it is possible to create winning strategy positions, then print "YES" (without quotes) and in the next line, print the minimum numbers of swaps required to form the winning strategy order, otherwise print "NO"(without quotes) in a new line.
Constraints
1 <= T <= 50
1 =< N <= 10^5
1 <= A[i] <= n
Time Limit: 1 second
Sample Input 1:
1
5
2 1 5 3 4
Sample Output 1:
YES
3
Explanation
In this case, we can achieve winning strategy positions in 3 swaps. Initial state of positions: 1 2 3 4 5
Three moves required to form winning strategy positions:
1 2 3 4 5 -> 1 2 3 5 4 -> 1 2 5 3 4 -> 2 1 5 3 4
Sample Input 2:
1
5
2 5 1 3 4
Sample Output 2:
NO
Explanation:
In the second case, there is no way to form the specific winning strategy positions by swapping within the constraints mentioned in the task.

*/

#include<bits/stdc++.h>
using namespace std;

int solve(int *a , int n) {
	if (n == 1) {
		return (a[0] == 1) ? 0 : -1;
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > i + 3 || a[i] < -1) {
			return -1;
		}

	}
	int i = 0;
	for (i ; i < n - 2; ++i)
	{
		if (a[i] > i + 3 || a[i] < i - 1) {
			return -1;
		}
		if (a[i] == i + 1)
		{
			continue;

		} else if (a[i + 1] == i + 1)
		{

			swap(a[i], a[i + 1]);
			count++;

			continue;
		} else if (a[i + 2] == i + 1)
		{
			swap(a[i + 2], a[i + 1]);
			count++;
			swap(a[i + 1], a[i]);
			count++;
			continue;
		} else {
			return -1;
		}
	}


	if (a[i] == i + 1 && a[i + 1] == i + 2)
	{
		return count;

	} else if (a[i] == i + 2 && a[i + 1] == i + 1) {
		swap(a[i], a[i + 1]);
		return count + 1;
	} else {
		return -1;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int x =	solve(a, n);
		if (x == -1) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			cout << x << endl;
		}
	}
}