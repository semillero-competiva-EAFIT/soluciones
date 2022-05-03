/*
https://leetcode.com/problems/beautiful-arrangement/
Por: Simón Fallon
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> power_set;
        int n = nums.size();
        
        for(int mask = 0; mask < 1<<n; ++mask){
            vector<int> cur_set;
            for(int bit = 0; bit < n; ++bit){
                if(mask & 1<<bit){
                    cur_set.push_back(nums[bit]);
                }
            }
            power_set.push_back(cur_set);
        }
        
        return power_set;
    }
};