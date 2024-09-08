class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;

        // Step 1: Push elements onto the stack
        for (int num : nums) {
            s.push(num);
        }

        // Step 2: Create a new vector to hold the next permutation
        vector<int> nextPerm;

        // Step 3: Find the next permutation
        for (int i = n - 1; i >= 0; --i) {
            if (!s.empty() && s.top() > nums[i]) {
                // Find the first element in the stack that is greater than nums[i]
                nextPerm.push_back(s.top());
                s.pop();
                break;
            } else {
                nextPerm.push_back(nums[i]);
                s.pop();
            }
        }

        // Step 4: Add remaining elements from the stack in reverse order
        while (!s.empty()) {
            nextPerm.push_back(s.top());
            s.pop();
        }

        // Step 5: Reverse the order of the elements that were added to nextPerm
        reverse(nextPerm.begin() + 1, nextPerm.end());

        // Step 6: Update the original nums array
        nums = nextPerm;
    }
};