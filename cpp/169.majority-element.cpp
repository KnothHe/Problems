/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (51.40%)
 * Total Accepted:    346.2K
 * Total Submissions: 673.6K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int count = 0;
        for (int i = 1; i < nums.size(); i++)  {
            if (nums[i] != majority) {
                if (count == 0) {
                    majority = nums[i];
                    count = 0;
                } else {
                    count--;
                }
            } else {
                count++;
            }
        }

        return majority;
    }
};
