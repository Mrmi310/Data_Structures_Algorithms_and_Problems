/*
https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
Difficulty: Easy
1403. Minimum Subsequence in Non-Increasing Order
Easy

Given the array nums, obtain a subsequence of the array whose sum of elements is
strictly greater than the sum of the non included elements in such subsequence.
If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions,
return the subsequence with the maximum total sum of all its elements.
A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array.
Note that the solution with the given constraints is guaranteed to be unique.
Also return the answer sorted in non-increasing order.
Input: nums = [4,3,10,9,8]
Output: [10,9]
Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is
strictly greater than the sum of elements not included, however, the subsequence [10,9] has the maximum total sum of its elements.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> minSubsequence(vector<int>& nums)
    {
        //Sort the given vector
        sort(nums.begin(), nums.end(), greater());

        //Calculate total sum of vector
        int totalSum=0;
        for(int el : nums)
            totalSum+=el;

        /*Go through the vector pushing back elements into the sequence until
        the sum of the sequence doesn't satisfy the sequence conditions (sequenceSum>totalSum-sequenceSum)*/
        int sequenceSum=0;
        vector<int> sequence;
        for(int el : nums)
        {
            if(sequenceSum>totalSum-sequenceSum)
            {
                break;
            }
            sequence+=el;
            sequence.push_back(el);
        }

        return sequence;
    }
};
