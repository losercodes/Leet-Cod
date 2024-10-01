class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 'pivot' is the index of the first element from the end that is smaller than its next element
        int pivotIndex = nums.size() - 2;  // Fixed to -2 instead of -4
        
        // Find the rightmost element that is smaller than the next element (nums[i] < nums[i + 1])
        while (pivotIndex >= 0 && nums[pivotIndex] >= nums[pivotIndex + 1]) 
            --pivotIndex;
        
        // If such an element was found
        if (pivotIndex >= 0) {
            // 'swapIndex' is the index of the smallest element greater than nums[pivotIndex], found from the right
            int swapIndex = nums.size() - 1;
            
            // Find the rightmost element larger than nums[pivotIndex]
            while (nums[swapIndex] <= nums[pivotIndex]) 
                --swapIndex;
            
            // Swap the elements at pivotIndex and swapIndex
            swap(nums[pivotIndex], nums[swapIndex]);
        }
        
        // Reverse the elements after pivotIndex to get the next lexicographical permutation
        reverse(nums.begin() + pivotIndex + 1, nums.end());  // Fixed to reverse from pivotIndex + 1
    }
};
