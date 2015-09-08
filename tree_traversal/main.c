// This is a simple program working with the tree data structure.
// It will support postorder, inorder, and preorder traversals

#include <stdio.h>

struct node {
	char letter;
	struct node* left;
	struct node* right;
};

typedef struct node node_t;

void print_preorder(node_t* top) {
	if(top==NULL) return;
	printf("%c ",top->letter);
	print_preorder(top->left);
	print_preorder(top->right);
}

void print_postorder(node_t* top) {
	if(top==NULL) return;
	print_postorder(top->left);
	print_postorder(top->right);
	printf("%c ",top->letter);
}

void print_inorder(node_t* top) {
	if(top==NULL) return;
	print_inorder(top->left);
	printf("%c ",top->letter);
	print_inorder(top->right);
}

int main() {
	node_t a,b,c,d,e,f,g,h,i,j,k;
	a.letter = 'a';
	b.letter = 'b';
	c.letter = 'c';
	d.letter = 'd';
	e.letter = 'e';
	f.letter = 'f';
	g.letter = 'g';
	h.letter = 'h';
	i.letter = 'i';
	j.letter = 'j';
	k.letter = 'k';
	
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
	printf("\n");
	print_inorder(&f);
	printf("\n");
	print_postorder(&f);
	printf("\n");

	return 0;
}
