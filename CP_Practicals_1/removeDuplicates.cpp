#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Sort the array
    sort(arr.begin(), arr.end());
    
    // Print unique elements
    cout << "Output: ";
    for (int i = 0; i < n; i++) {
        // Print element only if it's the first element or different from the previous
        if (i == 0 || arr[i] != arr[i - 1]) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    
    return 0;
}
