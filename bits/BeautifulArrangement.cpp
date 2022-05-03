/*
https://leetcode.com/problems/beautiful-arrangement/
Por: Simón Fallon
*/

#include <bits/stdc++.h>
using namespace std;

int dp[15][1<<15];

class Solution {
public:
    
    int go(int idx, int mask, int n){
        if(idx == n) return 1;
        
        int& ans = dp[idx][mask];
        if(ans != -1) return ans;
        ans = 0;
        
        for(int i = 0; i < n; ++i){
            if(mask & 1<<i) continue;
            if(max(idx+1, i+1) % min(idx+1, i+1) == 0){
                int new_mask = mask | (1<<i);
                ans += go(idx+1, new_mask, n);
            }
        }
        return ans;
    }
    
    int countArrangement(int n) {
        memset(dp, -1, sizeof dp);
        return go(0, 0, n);
    }
};