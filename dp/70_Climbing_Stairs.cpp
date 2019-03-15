
// DP
// Input:O(n),Subproblems:O(n),Depend on:O(1),Time:O(n),Space:O(n)-->O(1)
class Solution {
public:
    int climbStairs(int n) {
      int StepOne = 1;
      int StepTow = 0;
      // res代表到达第i阶台阶共有多少种走法
      int res = 0;
      for (int i = 1; i <= n; i++) {
          res = StepTow + StepOne;
          StepTow = StepOne;
          StepOne = res;
      }
      return res;
    }
};