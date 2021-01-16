/* ***********************************************
Author        :herongwei
Created Time  :Fri 07 Jul 2017 06:29:01 PM CST
File Name     :main.cpp
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
#include "003.solution.h"
using namespace std;
typedef long long LL;
const int maxn  = 1e5+233;
const int MOD   = 1e9+7;
const double eps= 1e-6;
const double pi = acos(-1.0);

int main()
{
	
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
   tree_node rt1(1); tree_node rt2(1);
   tree_node t2(2);  tree_node t3(3); tree_node t4(4);
   rt1.left = &t2 ;  rt1.right = &t3;
   rt2.left = &t2 ;  rt2.right = &t4;

   Solution s;
   cout<<s.is_same_tree(&rt1,&rt2)<<endl;
   
    return 0;
}
