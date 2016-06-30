#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        if (edges.size() != n-1) return false;
        vector<int> label;
        for (int i=0; i<n; i++) {
            label.push_back(i);
        }
        for (int i=0; i<edges.size(); i++) {
            label[getFather(label,edges[i][0])] = getFather(label,edges[i][1]);
        }
        for (int i=0; i<n; i++) {
            if (getFather(label, i) != getFather(label,0)) return false;
        }
        return true;
    }
private:
    int getFather(vector<int> &label, int c) {
        if (label[c] != c) label[c] = getFather(label, label[c]);
        return label[c];
    }
};

int main()
{
	Solution s;
	vector<vector<int>> input;
	input.push_back(vector<int>({0,1}));
    input.push_back(vector<int>({2,3}));
    input.push_back(vector<int>({0,3}));
    input.push_back(vector<int>({2,4}));
	bool result = s.validTree(5,input);
	string resultStr = result==true ? "TRUE" : "FALSE";
    cout<<resultStr<<endl;
	return 0;
}
