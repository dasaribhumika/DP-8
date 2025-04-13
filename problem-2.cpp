// https://leetcode.com/problems/triangle/description/
// Time Complexity: O(n*n)
// Space Complexity: O(n)


// Bottom-up
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            vector<int> dp = triangle[n-1];
            for(int i = n-2; i>=0; i--){
                for(int j=0; j<=i; j++){
                    dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
                }
            }
            return dp[0];
        }
    };

// Top-down
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            vector<int> dp = triangle[0];
            for(int i = 1; i<n; i++){
                vector<int> temp(i+1, 0);
                for(int j=0; j<=i; j++){
                    int cnt = 0;
                    if(j==0){
                        temp[j] = dp[j] + triangle[i][j];
                    }else if(j == i){
                        temp[j] = dp[j-1] + triangle[i][j];
                    }else{
                        temp[j] = min(dp[j],dp[j-1]) + triangle[i][j];
                    }
                }
                dp=temp;
            }
            int minVal = INT_MAX;
            for(int i=0; i<n; i++){
                minVal = min(minVal,dp[i]);
            }
            return minVal;
        }
    };