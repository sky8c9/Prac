#include <iostream>
#include <vector>
#include <algorithm>
/* Note:

Represent problem as 3 dices. Each has N face values.
	dp[i][j] = x
		i : # of dices
		j : possible sum of i dices
		x : number of ways to construct j sum

O(N^2):
	dp[0][0] =  1;
	for(int i = 0; i < 3; i++) {
		for(int total = 0; total <= i*n; total++) {
			for(int faceVal = 1; faceVal <= n; faceVal++) {
				dp[i + 1][total + faceVal] += dp[i][total];  
			}
		}
	}

O(N) with cumulative sum: 
	Observation:
		dp[i+1][j+1] += dp[i][j] (fix the last dice as 1)
		dp[i+1][j+2] += dp[i][j] (fix the last dice as 2)
		dp[i+1][j+3] += dp[i][j] (fix the last dice as 3)
		....

	Mark the boundary with +val and -val and sweep left to right to find culmulative sum

	Example with N = 3 (3 face value dice):	
		i = 1
			dp[0][0] = 1;
			dp[1][1] += dp[0][0]
			dp[1][4] -= dp[0][0]

			Sum					0	1	2	3	4
			Mark boundary		   +1	       -1
			Cul Sum				0   1   1   1   0

		i = 2
			dp[2][2] += dp[1][1]
			dp[2][5] -= dp[1][1]

			dp[2][3] += dp[1][2]
			dp[2][6] -= dp[1][2]

			dp[2][4] += dp[1][3]
			dp[2][7] -= dp[1][3]

			Sum     			0	1	2	3	4	5	6	7
				   	   	   			   +1          -1
				   	       	   			   +1          -1
											   +1		   -1

			Cul Sum				0   0   1   2   3   2   1   0


*/

using namespace std;

void task() {
	int n;
	long long k;
	cin >> n >> k;

	vector<vector<long long>> dp(4, vector<long long>(3*1e6 + 1));
	dp[0][0] = 1;

	for(int i = 0; i < 3; i++) {
		for(int sum = 0; sum <= i * n; sum++) {
			dp[i + 1][sum + 1] += dp[i][sum];
			dp[i + 1][sum + n + 1] -= dp[i][sum];
		}

		for(int sum = 1; sum <= (i+1) * n; sum++) {
			dp[i + 1][sum] += dp[i + 1][sum - 1];
		}
	}

	int curSum = 0;
	for(int sum = 3; sum <= 3*n; sum++) {
		if (k > dp[3][sum]) k -= dp[3][sum];
		else {
			curSum = sum;
			break;
		}
	}

	for(int beauty = 1; beauty <= n; beauty++) {
		int tasteLow = max(1, curSum - beauty - n);
		int tasteHigh = min(n, curSum - beauty - 1);

		if (tasteLow > tasteHigh) continue;

		if (k > (tasteHigh - tasteLow + 1)) {
			k -= (tasteHigh - tasteLow + 1);
			continue;
		}

		int taste = tasteLow + k - 1;
		int popularity = curSum - beauty - taste;

		cout << beauty << " " << taste << " " << popularity << endl;
		break; 
	}

}

int main() {
	task();
	return 0;
}