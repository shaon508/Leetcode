class Solution {
public:
    bool check(vector<int>& arr) {
        int cnt = 0;
        for(int i = 1 ; i < arr.size() ; i++)
        {
            if(arr[i] < arr[i-1])cnt++;
        }
        if(arr[arr.size()-1] > arr[0])cnt++;
        return (cnt <= 1);
    } 
};