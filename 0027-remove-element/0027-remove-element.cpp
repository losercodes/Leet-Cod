class Solution {
public:
    int removeElement(vector<int>& num, int val) {
        auto it = remove(num.begin(), num.end(), val);
        num.erase(it, nums.end());
        return num.size();
    }
};
