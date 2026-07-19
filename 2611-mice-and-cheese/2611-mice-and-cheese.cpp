class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0 ; i<reward1.size() ; i++){
            pq.push({reward2[i]-reward1[i],i});
        }
        int sum = 0 ;
        for(int i = 0 ; i<k ; i++){
            int index = pq.top().second;
            sum+=reward1[index];
            reward2[index]=0;
            pq.pop();
        }
        for(auto i : reward2){
            sum+=i;
        }
        return sum;
    }
};