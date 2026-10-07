class Solution {
public:
    int uniquePaths(int m, int n) {
  vector<vector<int>> dp(m, vector<int>(n,0));
  for (int i = 0;i<m;i++) dp[i][n-1] = 1;
  for (int i = 0;i<n;i++) dp[m-1][i] = 1;
  for(int i=n-1 ; i>=0;i--)
  {
    for(int j = m-1 ; j>=0;j--)
    {
      if (dp[j][i] == 1 ) continue;     
      dp[j][i] = dp[j+1][i] + dp[j][i+1] ;
    }
  }
  
  
  return dp[0][0];
    }
};
