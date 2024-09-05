class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>numMap;
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if(numMap.find(complement)!= numMap.end()){
            result.push_back(numMap[complement]);
result.push_back(i);
break;
            }
            numMap[nums[i]]=i;
        }
        return result;
    }
};