class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int currentCost = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            currentCost += abs(s[right] - t[right]);

            while (currentCost > maxCost) {
                currentCost -= abs(s[left] - t[left]);
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};