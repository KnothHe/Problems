/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (34.02%)
 * Total Accepted:    158K
 * Total Submissions: 464.3K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */

/*
 * reference: https://leetcode.com/problems/minimum-size-subarray-sum/solution/
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minNum = numeric_limits<int>::max();
        int left = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                minNum = min(minNum, i - left + 1);
                sum -= nums[left++];
            }
        }
        return minNum == numeric_limits<int>::max() ? 0 : minNum;
    }
};
