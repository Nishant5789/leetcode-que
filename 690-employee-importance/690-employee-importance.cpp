/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employee, int id) {
        
        unordered_map<int, pair<int,vector<int>>> employees;
        for(int i=0; i<employee.size(); i++)
        {
            employees.insert({employee[i]->id,{employee[i]->importance, employee[i]->subordinates}});
        }
        queue<int> q;
        int ans=0;
        q.push(id);
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans+=employees[node].first;
            
            for(auto child: employees[node].second)
            {
                q.push(child);
            }
        }
        return ans;
    }
};