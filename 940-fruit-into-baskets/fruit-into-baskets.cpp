class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l=0;
        int maxFruit = 0;
        unordered_map<int,int> freq;
        for(int r=0;r<n;r++){
            freq[fruits[r]]++;
            while(l<n and freq.size()>2){
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0){
                    freq.erase(fruits[l]);
                }
                l++;
            }
            maxFruit=max(maxFruit,r-l+1);
        }
        return maxFruit;
    }
};