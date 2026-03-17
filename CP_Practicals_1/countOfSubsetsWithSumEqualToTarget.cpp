#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, target;
    cout << "Enter the number of elements (n): ";
    cin >> n;
    cout << "Enter the target sum: ";
    cin >> target;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Create a DP table
    // dp[i][j] = number of subsets using first i elements with sum j
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
    
    // Base case: sum = 0 can be achieved by empty subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    
    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            // Don't include current element
            dp[i][j] = dp[i - 1][j];
            
            // Include current element if possible
            if (j >= arr[i - 1]) {
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    
    cout << "Number of subsets with sum equal to " << target << ": " 
         << dp[n][target] << endl;
    
    return 0;
}
