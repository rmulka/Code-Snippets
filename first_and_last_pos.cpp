/**
 * Given an array of integers nums sorted in ascending order, 
 * find the starting and ending position of a given target value.
 * 
 * If the target is not found in the array, return [-1, -1]. 
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range = {-1, -1};
        int numsSize = nums.size();
        
        for (int i = 0; i < numsSize; ++i) {
            if (nums[i] == target) {
                range[0] = range[1] = i;
                for (int j = i + 1; j < numsSize; ++j) {
                    if (nums[j] == target) {
                        range[1] = j;
                    }
                    else if (nums[j] > target) {
                        break;
                    }
                }
                break;
            }
            else if (nums[i] > target) {
                break;
            }
        }
        
        return range;
    }
};