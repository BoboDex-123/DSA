class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
       int n = nums.size();
        vector<int> dpMax(n), dpMin(n);
        dpMax[0] = dpMin[0] = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < n; i++) {
            int prevMax = dpMax[i-1];
            int prevMin = dpMin[i-1];
            
            dpMax[i] = max({nums[i], prevMax * nums[i], prevMin * nums[i]});
            dpMin[i] = min({nums[i], prevMax * nums[i], prevMin * nums[i]});
            
            result = max(result, dpMax[i]);
        }
        return result;
    }

};