class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> range(26,0);
        for(int i=0;i<n;i++){
            range[s[i]-'a']=max(range[s[i]-'a'],i);
        }
        int j=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            j=max(j,range[s[i]-'a']);
            int k=i+1;
            while(k<=j){ 
                j=max(j,range[s[k]-'a']);
                k++;
            }
            ans.push_back(j-i+1);
            i=j;
        }
        return ans;
    }
};
