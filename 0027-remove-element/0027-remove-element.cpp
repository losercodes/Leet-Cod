class Solution {
public:
    int removeElement(vector<int>& num, int val) {
        // 'remove' shifts all elements that are not equal to 'val' to the beginning
        // of the vector and returns an iterator to the new end of the array.
        auto it = remove(num.begin(), num.end(), val);
        
        // Erase the remaining elements from the point returned by 'remove' to the end of the vector.
        num.erase(it, num.end());
        
        // Return the new size of the vector after erasing the elements.
        return num.size();
    }
};
