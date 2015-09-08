// This is a simple program working with the tree data structure.
// It will support postorder, inorder, and preorder traversals

#include <iostream>

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
