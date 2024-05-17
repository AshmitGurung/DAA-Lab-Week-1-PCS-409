#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task 
{
    int time;
    int deadline;
    int index; 
};

bool taskCompare(Task t1, Task t2) 
{
    return (t1.deadline < t2.deadline);
}

int main()
{
    int n;
    cout << "Enter the total number of tasks: ";
    cin >> n;

    vector<Task> tasks(n);
    cout << "Enter the time taken by each task: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> tasks[i].time;
        tasks[i].index = i + 1; 
    }

    cout << "Enter the deadline associated with each task: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> tasks[i].deadline;
    }

    sort(tasks.begin(), tasks.end(), taskCompare);

    vector<int> selectedTasks;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime + tasks[i].time <= tasks[i].deadline) 
        {
            selectedTasks.push_back(tasks[i].index);
            currentTime += tasks[i].time;
        }
    }

    cout << "Max number of tasks = " << selectedTasks.size() << endl;
    cout << "Selected task numbers : ";
    for (size_t i = 0; i < selectedTasks.size(); i++) 
    {
        cout << selectedTasks[i];
        if (i < selectedTasks.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
