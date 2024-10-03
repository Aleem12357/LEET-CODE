class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total_sum = sum(nums)
        remainder = total_sum % p
        
        # If the total sum is already divisible by p, return 0
        if remainder == 0:
            return 0
        
        # If total_sum is less than p, no valid removal can make it divisible
        if total_sum < p:
            return -1
        
        prefix_sum = 0
        min_length = float('inf')
        prefix_map = {0: -1}  # Maps prefix_sum % p to the last index
        
        for i in range(len(nums)):
            prefix_sum += nums[i]
            # Current remainder with respect to p
            current_rem = prefix_sum % p
            
            # We want to find if there's a prefix sum that gives us the required remainder
            target_rem = (current_rem - remainder + p) % p
            
            if target_rem in prefix_map:
                # Calculate the length of the subarray to be removed
                min_length = min(min_length, i - prefix_map[target_rem])
            
            # Update the map with the most recent index of this current remainder
            prefix_map[current_rem] = i
        
        # If the smallest length found is equal to the length of the array, return -1
        return min_length if min_length != float('inf') and min_length < len(nums) else -1