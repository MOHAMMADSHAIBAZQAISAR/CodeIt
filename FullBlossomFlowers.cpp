/*
You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi]
 means the ith flower will be in full bloom from starti to endi (inclusive). 
 You are also given a 0-indexed integer array people of size n, where people[i] is the time that the 
 ith person will arrive to see the flowers.
Return an integer array answer of size n, where answer[i] is the number of flowers that 
are in full bloom when the ith person arrives.
*/

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        //create a sorted array of persons.
        vector<int> sortPersons(people.begin(), people.end());
        sort(sortPersons.begin(), sortPersons.end());
        priority_queue<int, vector<int> , greater<int>> pq;
        map<int,int> mp;

        sort(flowers.begin(), flowers.end());

        int n = people.size();
        int ind = 0;
        for(int i = 0;i<n;i++){
            while(ind<flowers.size() && flowers[ind][0] < sortPersons[i]){
                pq.push(flowers[ind][1]); ind++;
            }
            
            while(!pq.empty() && pq.top() < sortPersons[i]){
                pq.pop();
            }
            mp[sortPersons[i]] = pq.size();
        }

        vector<int> ans;
        for(int i = 0;i<n;i++){
            ans.push_back(mp[people[i]]);
        }
        return ans;
    }
};