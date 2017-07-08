/* ***********************************************
Author        :herongwei
Created Time  :Thu 06 Jul 2017 11:15:24 AM CST
File Name     :001.cpp
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
#include "solution.h"
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
	Solution s;
	int a[7]={1,2,3,5,2,1,3};
	cout<< s.single_number(a,7)<<endl;
   return 0;
}
