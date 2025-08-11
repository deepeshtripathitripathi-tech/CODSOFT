#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "To-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    cout << "Tasks:" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description << " - ";
        if (tasks[i].completed) {
            cout << "Completed" << endl;
        } else {
            cout << "Pending" << endl;
        }
    }
}

void markTaskAsCompleted(vector<Task>& tasks) {
    viewTasks(tasks);
    int taskNumber;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);
    int taskNumber;
    cout << "Enter task number to remove: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}