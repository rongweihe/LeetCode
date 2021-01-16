 /* ***********************************************
Author        :herongwei
Created Time  :Fri 07 Jul 2017 08:10:47 AM CST
File Name     :002.cpp
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
#include "002_solution.h"
using namespace std;
typedef long long LL;
const int maxn  = 1e5+233;
const int MOD   = 1e9+7;
const double eps= 1e-6;
const double pi = acos(-1.0);

/* create a tree;
        1
       / \ 
      2   3 
     / \   \
    4  5    6
   / \
  7   8
    
*/

int main()
{
	  
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
TreeNode root(1);
TreeNode t2(2);
TreeNode t3(3);
TreeNode t4(4);
TreeNode t5(5);
TreeNode t6(6);
TreeNode t7(7);
TreeNode t8(8);
TreeNode t9(9);
	
root.left = &t2;
root.right = &t3;
t2.left = &t4;
t2.right = &t5;
t3.right = &t6;
t4.left = &t7;
t4.right = &t8;
t8.left = &t9;
	
Solution s;
std::cout << s.maxDepth(&root) << std::endl;
    
return 0;
}
