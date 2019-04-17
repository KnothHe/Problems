/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (29.83%)
 * Total Accepted:    62.7K
 * Total Submissions: 210.1K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means . 
 * 
 * 
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> vec(nums.begin(), nums.end());
        sort(vec.begin(), vec.end());

        int beg = 0, end = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != vec[i]) {
                beg = i;
                break;
            }
        }
        for (int i = nums.size()-1; i >= 0; --i) {
            if (nums[i] != vec[i]) {
                end = i;
                break;
            }
        }

        return end-beg+1;
    }
};