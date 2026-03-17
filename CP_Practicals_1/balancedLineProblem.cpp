#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    deque<int> line;
    int choice, x;
    
    cout << "Balanced Line Problem using Deque" << endl;
    cout << "===================================" << endl;
    cout << "Operations:" << endl;
    cout << "1. push_front x - Add person at front" << endl;
    cout << "2. push_back x - Add person at back" << endl;
    cout << "3. pop_front - Remove person from front" << endl;
    cout << "4. pop_back - Remove person from back" << endl;
    cout << "5. Exit" << endl;
    cout << "===================================" << endl;
    
    while (true) {
        cout << "\nEnter operation (1-5): ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "Enter person ID: ";
                cin >> x;
                line.push_front(x);
                cout << "Added " << x << " at front" << endl;
                break;
            }
            case 2: {
                cout << "Enter person ID: ";
                cin >> x;
                line.push_back(x);
                cout << "Added " << x << " at back" << endl;
                break;
            }
            case 3: {
                if (!line.empty()) {
                    cout << "Removed " << line.front() << " from front" << endl;
                    line.pop_front();
                } else {
                    cout << "Line is empty! Cannot remove from front." << endl;
                }
                break;
            }
            case 4: {
                if (!line.empty()) {
                    cout << "Removed " << line.back() << " from back" << endl;
                    line.pop_back();
                } else {
                    cout << "Line is empty! Cannot remove from back." << endl;
                }
                break;
            }
            case 5: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice! Please enter 1-5." << endl;
                continue;
            }
        }
        
        // Print current contents of the line
        cout << "Current line: ";
        if (line.empty()) {
            cout << "Empty" << endl;
        } else {
            for (int person : line) {
                cout << person << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
