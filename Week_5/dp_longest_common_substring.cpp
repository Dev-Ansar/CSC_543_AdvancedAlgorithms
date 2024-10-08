#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For setw

using namespace std;


void longestCommonSubstring(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a 2D table 
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxLength = 0;
    int endIndex = 0; // To store the end index of the longest common substring

    // Fill the table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1; // End index of the longest substring in s1
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    
    cout << "Lookup Table:" << endl;

    // Print column headings
    cout << "      "; 
    for (char c : s2) {
        cout << setw(3) << c;
    }
    cout << endl;

    // Print each row with row headings
    for (int i = 0; i <= m; ++i) {
        if (i == 0) {
            cout << setw(3) << " ";
        } else {
            cout << setw(3) << s1[i - 1];
        }
        for (int j = 0; j <= n; ++j) {
            cout << setw(3) << dp[i][j];
        }
        cout << endl;
    }

    // Extract the longest common substring
    string lcs = s1.substr(endIndex - maxLength + 1, maxLength);

    cout << "The length of the longest common substring is: " << maxLength << endl;
    cout << "One of the longest common substrings is: " << lcs << endl;
}

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    if (s1.length() != s2.length()) {
        cout << "The strings must be of the same length." << endl;
        return 1;
    }

    longestCommonSubstring(s1, s2);

    return 0;
}
