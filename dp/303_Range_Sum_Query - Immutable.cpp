#include <vector>
using namespace std;

// Memory Usage: 17.4 MB, less than 20.99%,Runtime: 200 ms, faster than 12.71%
// DP
// Input:O(n),Subproblems:O(n),Depend on:O(1),Time:O(n),Space:O(n)-->O(1)
class NumArray {
public:
    NumArray(vector<int> nums) {
        this->nums = nums;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for (int n = i; n <= j; n++) {
            sum += this->nums[n];
        }
        return sum;
    }
private:
    vector<int> nums;
};