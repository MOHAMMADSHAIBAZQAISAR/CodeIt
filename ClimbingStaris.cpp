//746. Min Cost Climbing Stairs
/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
	    vector<int> dp(n);
			for (int i=0; i<n; i++) {
				if (i<2) dp[i] = cost[i];
				else dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
			}
			return min(dp[n-1], dp[n-2]);
    }
};