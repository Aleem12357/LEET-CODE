#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int totalLeft = (m + n + 1) / 2;
        
        int left = 0, right = m;
        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = totalLeft - i;
            
            int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
            int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2RightMin = (j == n) ? INT_MAX : nums2[j];
            
            if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
                // Found the correct partition
                if ((m + n) % 2 == 0) {
                    return (std::max(nums1LeftMax, nums2LeftMax) + std::min(nums1RightMin, nums2RightMin)) / 2.0;
                } else {
                    return std::max(nums1LeftMax, nums2LeftMax);
                }
            } else if (nums1LeftMax > nums2RightMin) {
                // Move `i` to the left
                right = i - 1;
            } else {
                // Move `i` to the right
                left = i + 1;
            }
        }
        
        throw std::invalid_argument("Input arrays are not sorted.");
    }
};
