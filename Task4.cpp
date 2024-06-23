#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item {
    string details;
    bool isDone;
    Item(string desc) : details(desc), isDone(false) {}
};

class TaskManager {
private:
    vector<Item> items;
public:
    void addItem(const string &details) {
        items.emplace_back(details);
        cout << "Task added: " << details << endl;
    }

    void displayItems() const {
        if (items.empty()) {
            cout << "No tasks to show." << endl;
            return;
        }

        cout << "Tasks:\n";
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i + 1 << ". " << items[i].details
                 << " [" << (items[i].isDone ? "Completed" : "Pending") << "]" << endl;
        }
    }

    void markItemAsDone(int index) {
        if (index > 0 && index <= items.size()) {
            items[index - 1].isDone = true;
            cout << "Task marked as completed: " << items[index - 1].details << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void deleteItem(int index) {
        if (index > 0 && index <= items.size()) {
            cout << "Task removed: " << items[index - 1].details << endl;
            items.erase(items.begin() + index - 1);
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    TaskManager taskManager;
    bool isActive = true;

    while (isActive) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int userChoice;
        cin >> userChoice;

        switch (userChoice) {
            case 1: {
                cout << "Enter task description: ";
                cin.ignore();
                string taskDetails;
                getline(cin, taskDetails);
                taskManager.addItem(taskDetails);
                break;
            }
            case 2:
                taskManager.displayItems();
                break;
            case 3: {
                cout << "Enter task number to mark as completed: ";
                int taskIndex;
                cin >> taskIndex;
                taskManager.markItemAsDone(taskIndex);
                break;
            }
            case 4: {
                cout << "Enter task number to remove: ";
                int taskIndex;
                cin >> taskIndex;
                taskManager.deleteItem(taskIndex);
                break;
            }
            case 5:
                isActive = false;
                cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
