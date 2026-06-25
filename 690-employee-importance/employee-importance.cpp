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
    unordered_map<int,Employee*> hash;
    int dfs(int id){
        int imp=hash[id]->importance;
        for(auto& sub:hash[id]->subordinates){
            imp+=dfs(sub);
        }
        return imp;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(auto& e:employees){
            hash[e->id]=e;
        }
        return dfs(id);
    }
};