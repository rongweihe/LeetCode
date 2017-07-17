

/* ***********************************************
Author        :herongwei
Created Time  :Mon 17 Jul 2017 06:20:14 PM CST
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast =  head;
        bool f=false;
        while(NULL!=slow && NULL!=slow->next)
        {
            slow=slow->next->next;
            fast= fast->next;
            if(fast == slow)
            {
                f=true;
                break;
            }
        }
        return f;
    }
};

