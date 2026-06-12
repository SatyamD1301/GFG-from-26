class Solution {
public:
    bool kSubstr(string &s, int k) {
        int n = s.size();

        if (n % k != 0) return false;

        int blocks = n / k;
        unordered_map<string, int> freq;

        for (int i = 0; i < n; i += k) {
            freq[s.substr(i, k)]++;
        }

        int mx = 0;
        for (auto &p : freq) {
            mx = max(mx, p.second);
        }

        // Already repeating or can be made repeating
        // by changing at most one k-length block.
        return mx >= blocks - 1;
    }
};