/*
https://leetcode.com/problems/unique-number-of-occurrences/submissions/
1207. Unique Number of Occurrences
Difficulty: Easy
Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Number of Occurrences.
Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Unique Number of Occurrences.
*/

class Solution
{
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        iostream::sync_with_stdio(false);
        cin.tie(0);

        sort(arr.begin(), arr.end());

        unordered_set<int> counter;
        int temp=0, arrSize=arr.size();

        for(int i=0; i<arrSize; ++i)
        {
            ++temp;

            if((i+1<arrSize && arr[i+1]!=arr[i]) || i==arrSize-1)
            {
                if(counter.count(temp))
                    return false;

                counter.insert(temp);
                cout<<temp<<"\n";

                temp=0;
            }
        }
        return true;
    }
};
