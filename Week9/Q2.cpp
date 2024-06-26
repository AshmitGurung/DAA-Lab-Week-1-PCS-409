#include<bits/stdc++.h>
using namespace std;

int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input_2.txt", "r", stdin);
    freopen("output_2.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<double> items(n);
    vector<double> val(n);
    vector<vector<double>> job;
    for (int i = 0; i < n; i++) 
    {
        cin >> items[i];
    }
    for (int i = 0; i < n; i++) 
    {
        cin >> val[i];
        job.push_back({ val[i] / items[i], items[i], (double)(i + 1) });
    }
    double k;
    cin >> k;
    sort(job.rbegin(), job.rend());
    vector<pair<double, double>> ls;
    float profit = 0;
    for (int i = 0; i < n; i++)
      {
        if (job[i][1] >= k) {
            profit += k * job[i][0];
            ls.push_back(make_pair(k, job[i][2]));
            break;
        }
        else
        {
            profit += job[i][1] * job[i][0];
        }
        ls.push_back(make_pair(job[i][1], job[i][2]));
        k = k - job[i][1];
    }
    cout << "Maximum Value is: " << profit << endl;
    cout << "Item - Weight" << endl;
    for (auto it : ls)
        cout << it.second << " - " << it.first << endl;
    return 0;
}
