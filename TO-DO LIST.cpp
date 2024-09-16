#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool is_completed;
};

void add_task(vector<Task>& tasks) {
    string task_description;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, task_description);

    tasks.push_back({task_description, false});
    cout << "Task added successfully!" << endl;
}

void view_tasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty!" << endl;
        return;
    }

    cout << "\nTo-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description << " [";
        if (tasks[i].is_completed) {
            cout << "Completed";
        } else {
            cout << "Pending";
        }
        cout << "]" << endl;
    }
}

void mark_task_completed(vector<Task>& tasks) {
    int task_number;
    cout << "Enter the task number to mark as completed: ";
    cin >> task_number;

    if (task_number < 1 || task_number > tasks.size()) {
        cout << "Invalid task number!" << endl;
        return;
    }

    tasks[task_number - 1].is_completed = true;
    cout << "Task marked as completed!" << endl;
}

void remove_task(vector<Task>& tasks) {
    int task_number;
    cout << "Enter the task number to remove: ";
    cin >> task_number;

    if (task_number < 1 || task_number > tasks.size()) {
        cout << "Invalid task number!" << endl;
        return;
    }

    tasks.erase(tasks.begin() + task_number - 1);
    cout << "Task removed successfully!" << endl;
}

void display_menu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        display_menu();
        cin >> choice;

        switch (choice) {
            case 1:
                add_task(tasks);
                break;
            case 2:
                view_tasks(tasks);
                break;
            case 3:
                mark_task_completed(tasks);
                break;
            case 4:
                remove_task(tasks);
                break;
            case 5:
                cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
