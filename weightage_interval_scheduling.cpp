#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
        int memo[5000];
        int n;

        int getNextIndex(vector<vector<int>> & array, int start, int target){
            int end = n - 1;
            int result = INT_MIN;

            
            while(start <= end){
                int mid = start + (end-start)/2;

                if(array[mid][0] >= target){
                    result = mid;
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
            return result;
        }
        int solve(vector<vector<int>> & array, int i){
            if(i>=n){
                return 0;
            }

            if(memo[i] != -1){
                return memo[i];
            }

            int next = getNextIndex(array, i+1, array[i][1]);

            int taken = array[i][2] + solve(array, next);
            int notTaken = solve(array, i+1);

            return memo[i] = max(taken, notTaken);
        }

        int jobScheduling(vector<int> & startTime, vector<int> & endTime, vector<int> & profit){
            n = startTime.size();

            vector<vector<int>> array(n, vector<int>(3,0));

            for(int i = 0; i<n; i++){
                array[i][0] = startTime[i];
                array[i][1] = endTime[i];
                array[i][2] = profit[i];
            }

            sort(begin(array), end(array));

            return solve(array,0);

        }
};

int main(){
    Solution Jobs;
    vector<int> startTime = {1,2,4,6,5,7};
    vector<int> endTime = {3,5,6,7,8,9};
    vector<int> profit = {5,6,5,4,11,2};

    cout << Jobs.jobScheduling(startTime, endTime, profit);
    return 0;
}