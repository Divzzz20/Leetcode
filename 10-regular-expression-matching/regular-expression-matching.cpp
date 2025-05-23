class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
    int m = p.length();

    // dp[i][j] represents whether s[0...i-1] matches p[0...j-1]
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // Base case: empty string matches empty pattern
    dp[0][0] = true;

    // Handle patterns starting with '*' (e.g., "a*")
    for (int j = 1; j <= m; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2]; // '*' matches zero occurrences
        }
    }

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                // Current characters match (or '.' matches any character)
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                // '*' case:
                dp[i][j] = dp[i][j - 2]; // '*' matches zero occurrences

                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    // '*' matches one or more occurrences
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            } else {
                // Characters don't match
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
    }
};

