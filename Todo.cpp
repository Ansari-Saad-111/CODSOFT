#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string descrp;
    bool completed;
};

class Todolistmanager {
private:
    vector<Task> tasks;

public:
    void addtask(const string& descrp) {
        tasks.push_back({descrp, false});
        cout << "Task added: " << descrp << endl;
    }

    void viewtasks() {
        cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] "
                      << tasks[i].descrp << endl;
        }
    }

    void marktaskcompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed: " << tasks[index].descrp << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removetask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            cout << "Task removed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    Todolistmanager m;
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string descrp;
                cout << "Enter task description: ";
                cin.ignore(); 
                getline(cin, descrp);
                m.addtask(descrp);
                break;
            }
            case 2:
                m.viewtasks();
                break;
            case 3: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                m.marktaskcompleted(index - 1);
                break;
            }
            case 4: {
                int index;
                cout << "Enter task index to remove: ";
                cin >> index;
                m.removetask(index - 1);
                break;
            }
            case 5:
                cout << "Exiting...Thank You!" << endl;
                break;
            default:
                cout << "Invalid choice...Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
