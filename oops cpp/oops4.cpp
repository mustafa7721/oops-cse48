
// Program to manage a simple to-do list
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> tasks;
    int choice;
    string task;

    do {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n2. View Tasks\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline from input buffer

        switch(choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                tasks.push_back(task);
                break;
            case 2:
                cout << "\nTasks:\n";
                for(int i = 0; i < tasks.size(); i++)
                    cout << i + 1 << ". " << tasks[i] << endl;
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 3);

    return 0;
}
