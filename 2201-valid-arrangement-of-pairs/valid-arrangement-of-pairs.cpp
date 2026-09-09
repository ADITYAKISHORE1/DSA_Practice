class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> indeg,outdeg;
        for(auto&i:pairs){
            adj[i[0]].push_back(i[1]);
            indeg[i[1]]++;
            outdeg[i[0]]++;
        }
        int startNode=pairs[0][0];
        for(auto& i:adj){
            if(outdeg[i.first]-indeg[i.first]==1){
                startNode=i.first;
                break;
            }
        }

        stack<int> st;
        st.push(startNode);
        vector<int> eularPath;
        while(!st.empty()){
            int v=st.top();
            if(!adj[v].empty()){
                st.push(adj[v].back());
                adj[v].pop_back();
            }else{
                eularPath.push_back(v);
                st.pop();
            }
        }     
        vector<vector<int>> ans;
        for(int i=eularPath.size()-2;i>=0;i--){
            ans.push_back({eularPath[i+1],eularPath[i]});
        }
        return ans;
    }
};