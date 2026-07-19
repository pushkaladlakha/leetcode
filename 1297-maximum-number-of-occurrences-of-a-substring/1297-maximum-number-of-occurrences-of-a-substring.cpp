class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> substringFreq;
        unordered_map<char, int> charFreq;

        int distinct = 0;
        int answer = 0;

        // Build first window
        for (int i = 0; i < minSize; i++) {
            if (++charFreq[s[i]] == 1)
                distinct++;
        }

        if (distinct <= maxLetters) {
            answer = ++substringFreq[s.substr(0, minSize)];
        }

        // Slide the window
        for (int right = minSize; right < s.size(); right++) {
            char outgoing = s[right - minSize];
            if (--charFreq[outgoing] == 0) {
                charFreq.erase(outgoing);
                distinct--;
            }

            char incoming = s[right];
            if (++charFreq[incoming] == 1)
                distinct++;

            if (distinct <= maxLetters) {
                string sub = s.substr(right - minSize + 1, minSize);
                answer = max(answer, ++substringFreq[sub]);
            }
        }

        return answer;
    }
};