// This is a simple program working with the tree data structure.
// It will support postorder, inorder, and preorder traversals

#include <iostream>
#include <climits>

template <typename T>
struct node_t {
	T value;
	struct node_t<T>* left;
	struct node_t<T>* right;
};

template <typename T>
void print_preorder(node_t<T>* top) {
	if(top==NULL) return;
	std::cout << top->value << " ";
	print_preorder(top->left);
	print_preorder(top->right);
}

template <typename T>
void print_postorder(node_t<T>* top) {
	if(top==NULL) return;
	print_postorder(top->left);
	print_postorder(top->right);
	std::cout << top->value << " ";
}

template <typename T>
void print_inorder(node_t<T>* top) {
	if(top==NULL) return;
	print_inorder(top->left);
	std::cout << top->value << " ";
	print_inorder(top->right);
}

int is_valid_bst_util(node_t<int>* top, int min, int max) {
	if (top==NULL) return 1;
	int new_min = (min < top->value) ? top->value : min;
	int new_max = (max < top->value) ? max : top->value;
	if(top->value > top->left->value && 
		top->value < top->right->value &&
		is_valid_bst_util(top->left,min,new_max) &&
		is_valid_bst_util(top->right,new_min,max)) {
		return true;
	}
	return false;
}

int is_valid_bst(node_t<int>* top) {
	// determines if a tree is a valid binary search tree
	// can be adapted to non int types if that type has
	// a clear minimum and maximum
	// Could also be templated by finding the min and max
	// of the tree, but this would take O(n) in itself
	return is_valid_bst_util(top,INT_MIN,INT_MAX);
}

int main() {
	node_t<char> a,b,c,d,e,f,g,h,i,j,k;
	a.value = 'a';
	b.value = 'b';
	c.value = 'c';
	d.value = 'd';
	e.value = 'e';
	f.value = 'f';
	g.value = 'g';
	h.value = 'h';
	i.value = 'i';
	j.value = 'j';
	k.value = 'k';
	
	f.left = &d;
	f.right = &j;
	d.left = &b;
	d.right = &e;
	b.left = &a;
	b.right = &c;
	j.left = &g;
	j.right = &k;
	g.right = &i;
	a.left = NULL;
	a.right = NULL;
	c.left = NULL;
	c.right = NULL;
	e.left = NULL;
	e.right = NULL;
	g.left = NULL;
	h.left = NULL;
	h.right = NULL;
	i.left = NULL;
	i.right = NULL;
	k.left = NULL;
	k.right = NULL;

	print_preorder(&f);
	std::cout << std::endl;
	print_inorder(&f);
	std::cout << std::endl;
	print_postorder(&f);
	std::cout << std::endl;

	return 0;
}
