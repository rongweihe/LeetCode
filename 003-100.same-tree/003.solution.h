/*
define for a binary tree node
*/
struct tree_node{
	int val;
	tree_node* left;
	tree_node* right;
	tree_node(int x):val(x),left(NULL),right(NULL){}
};
class Solution{
	public:
		bool is_same_tree(tree_node* p,tree_node*q){
			if(NULL == p || NULL == q) return (q==p);
			return (p->val == q->val && is_same_tree(p->left,q->left) && is_same_tree(p->right,q->right));
		}
};

	

