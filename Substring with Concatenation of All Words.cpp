class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wordLen = words[0].size();
        int totalWords = words.size();
        int totalLen = wordLen * totalWords;
        if (s.size() < totalLen)
            return ans;
        unordered_map<string, int> mp;
        for (string word : words)
            mp[word]++;
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> seen;
            for (int right = i; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);
                if (mp.find(word) == mp.end()) {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }
                seen[word]++;
                count++;
                while (seen[word] > mp[word]) {
                    string removeWord = s.substr(left, wordLen);
                    seen[removeWord]--;
                    left += wordLen;
                    count--;
                }
                if (count == totalWords) {
                    ans.push_back(left);
                    string removeWord = s.substr(left, wordLen);
                    seen[removeWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }
        return ans;
    }
};
