// Given an integer array nums and an integer k,
//  return the k most frequent elements. You may return the answer in any order.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>mpp;
        priority_queue<pair<int, int>>pq;
        vector<int>ans; //final answer that has top k elements
        // for loop to count number of occurences
        for(int i =0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        // push key value pairs in pq
        for(auto it: mpp){
            pq.push(make_pair(it.second, it.first));
        }
        while(k>0 && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};

// bucket solution
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        vector<int>ans; 

        for(int i =0; i<n; i++)   mpp[nums[i]]++;

        vector<vector<int>>bucket(n+1);
        for(auto it = mpp.begin(); it!=mpp.end(); it++)  bucket[it->second].push_back(it->first);

        for(int i=n; i>0; i--){
            if(ans.size()>=k)   break;
            if(!bucket[i].empty())     ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());;
        }
        return ans;
    }
};