/* ***********************************************
Author        :herongwei
Created Time  :Sat 22 Jul 2017 08:59:41 PM CST
File Name     :solution.h
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
typedef long long LL;
const int maxn  = 1e5+233;
const int MOD   = 1e9+7;
const double eps= 1e-6;
const double pi = acos(-1.0);
int n,m,t,ans,res,tmp; 

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        inorderTraversal2(root,v);
        return v;
    }
    void inorderTraversal2(TreeNode* root,vector<int> &v)
    {
        if(root==NULL) return;
        inorderTraversal2(root->left,v);
        v.push_back(root->val);
        inorderTraversal2(root->right,v);
    }
};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    return 0;
}
