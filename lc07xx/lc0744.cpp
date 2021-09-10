//--- Q: 0744. Find Smallest Letter Greater Than Target

//--- method 1: binary search
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (letters[mid] <= target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left == letters.size()-1 && letters[left] <= target ? letters[0] : letters[left];
    }
};