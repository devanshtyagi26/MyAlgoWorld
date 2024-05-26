#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job{
    public:
        int duration;
        int deadline;
        vector<vector<int>> Line;


        void Assignment(int order, int duration, int deadline){
            vector<int> J = {order, duration, deadline};
            Line.push_back(J);
        }

        void VectorSort(){
            sort(begin(Line), end(Line), [](const auto &a, const auto &b) {
            return a[2] < b[2];
            });
        }
        vector<vector<int>> minLateness(){
            VectorSort();
            int t = 0;
            int n = Line.size();
            vector<vector<int>> arr;
            for(int j = 0; j<n; j++){
                int sj = t;
                int lj = 0;
                int fj = t + Line[j][1];
                lj = max(0, fj - Line[j][2]);
                arr.push_back({Line[j][0],sj,fj, lj});
                t = fj;
            }

            return arr;
        }
};


int main(){
    Job a;
    a.Assignment(1, 3, 4);
    a.Assignment(3, 1, 8);
    a.Assignment(2, 2, 7);
    a.Assignment(4, 4, 8);
    a.Assignment(5, 2, 10);
    vector<vector<int>> l;
    l = a.minLateness();
    cout << "\n------------------------------------------------------------\n| Jobs\t|\tStart Time |\tEnd Time   |\tLateness   |\n------------------------------------------------------------\n";
    for(int i = 0; i<l.size(); i++){
        cout << "| Job " << l[i][0] << "\t|\t";
        for(int j = 1; j<l[0].size(); j++){
            cout << l[i][j] << "\t   |\t";
        }
        cout << endl;
    }

    int maxLate = 0;
    for(int i = 0; i<l.size(); i++){
        if(maxLate < l[i][3]){
            maxLate = l[i][3];
        }
    }

    cout << "\nThe Maximum Lateness is : " << maxLate << endl;
    return 0;
}