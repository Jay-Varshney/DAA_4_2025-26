class Solution {
  public:
  
  bool recfun(vector<int>& arr, int sum, int i , int curr , vector<vector<int>>& dp){
      if(curr > sum){
          return false;
      }
      if(i >= arr.size()){
          return (curr == sum);
      }
      if(curr == sum){
          return dp[i][curr] = true;
      }
      if(dp[i][curr] != -1){
          return dp[i][curr];
      }
      return dp[i][curr] = (recfun(arr , sum , i+1 , curr+arr[i] , dp) || recfun(arr , sum , i+1 , curr , dp));
  }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>> dp(arr.size() , vector<int>(sum+1 , -1));
        return recfun(arr , sum , 0 , 0 , dp);
    }
};