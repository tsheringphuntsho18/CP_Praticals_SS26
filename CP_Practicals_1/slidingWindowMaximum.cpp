#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int n, k;
    cout << "Enter the size of array (N): ";
    cin >> n;
    cout << "Enter the window size (K): ";
    cin >> k;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Deque to store indices of useful elements
    deque<int> dq;
    
    cout << "Output: ";
    
    // Process first window
    for (int i = 0; i < k; i++) {
        // Remove elements from back while current element is greater
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    // Print maximum of first window
    cout << arr[dq.front()] << " ";
    
    // Process remaining windows
    for (int i = k; i < n; i++) {
        // Remove elements outside current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove elements from back while current element is greater
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // Print maximum of current window
        cout << arr[dq.front()] << " ";
    }
    
    cout << endl;
    
    return 0;
}
