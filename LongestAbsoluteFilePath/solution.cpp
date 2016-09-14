#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int result=0, count=0, ln=1, size=input.size();
        bool isFile=false;
        vector<int> level(200);
        level[0]=0;
        for(int i=0; i<size; i++){
            //find which level
            while(input[i]=='\t'){
                ln++;
                i++;
            }
            //read file name
            while(input[i]!='\n' && i<size){
                if(input[i]=='.') isFile=true;
                count++;
                i++;
            }
            //calculate
            if(isFile){
                result=max(result, level[ln-1]+count);
            }
            else{
                level[ln]=level[ln-1]+count+1;// 1 means '/'
            }
            //reset
            count=0; ln=1; isFile=false;
        }
        return result;
    }
};

int main()
{
    Solution s;
    string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    cout<<s.lengthLongestPath(input)<<endl;
    return 0;
}




