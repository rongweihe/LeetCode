**题意**  
Given a sorted array and a target value, return the index if the target is found.      
If not, return the index where it would be if it were inserted in order.   
You may assume no duplicates in the array.   

Example 1:   

Input: [1,3,5,6], 5  
Output: 2  
Example 2:  

Input: [1,3,5,6], 2  
Output: 1  
Example 3:  

Input: [1,3,5,6], 7  
Output: 4  
Example 4:  

Input: [1,3,5,6], 0  
Output: 0  

**参考代码**  
```c++
class Solution {
public:
    //o(n)
    /*
    int searchInsert(vector<int>& nums, int target) {
        register int i;
        for(i=0; i<nums.size() && nums[i]<target; i++);
           return i;
    }
    */
    //o(logn)
    int searchInsert(vector<int>& nums,int target){
        int low=0,high=nums.size()-1,mid=0;
        while(low<=high){
            mid = low + (high-low)/2;
            if(nums[mid] < target){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return low;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().searchInsert(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
```

