#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity 
{
    int start;
    int finish;
    int index; 
};

bool activityCompare(Activity s1, Activity s2) 
{
    return (s1.finish < s2.finish);
}

int main() 
{
    int N;
    cout << "Enter the number of activities: ";
    cin >> N;
    
    vector<Activity> activities(N);
    cout << "Enter the starting times of activities: ";
    for (int i = 0; i < N; i++) 
    {
        cin >> activities[i].start;
        activities[i].index = i + 1; 
    }
    
    cout << "Enter the finishing times of activities: ";
    for (int i = 0; i < N; i++)
    {
        cin >> activities[i].finish;
    }
    
    sort(activities.begin(), activities.end(), activityCompare);
    
    vector<int> selectedActivities;
    
    int lastFinishTime = activities[0].finish;
    selectedActivities.push_back(activities[0].index);
    
    for (int i = 1; i < N; i++) 
    {
        if (activities[i].start >= lastFinishTime) 
        {
            selectedActivities.push_back(activities[i].index);
            lastFinishTime = activities[i].finish;
        }
    }
    
    cout << "No. of non-conflicting activities: " << selectedActivities.size() << endl;
    cout << "List of selected activities: ";
    for (size_t i = 0; i < selectedActivities.size(); i++) 
    {
        cout << selectedActivities[i];
        if (i < selectedActivities.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
