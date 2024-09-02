class Solution {
public:
    typedef pair<int,int> PPI;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //min heap
        //unordered map

        unordered_map<int,int> freq;

        for(auto& num: nums){
            freq[num]++;
        }

        //min heap
        priority_queue<PPI, vector<PPI>, greater<PPI>> minheap;

        for(auto& pair: freq){
            int val = pair.first;
            int fq = pair.second;

            minheap.push({fq,val});

            while(minheap.size() > k ){
                minheap.pop();
            }
        }

        vector<int> kmostfreq;

        while(minheap.size() > 0){
            PPI pair = minheap.top();
            kmostfreq.push_back(pair.second);
            minheap.pop();
        }

        return kmostfreq;

    }
};