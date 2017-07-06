class Solution {
public:
	int single_number(int a[],int n){
	int res=0;
	for(int i=0; i<n; ++i) res^=a[i];
	return res;
	}
};
