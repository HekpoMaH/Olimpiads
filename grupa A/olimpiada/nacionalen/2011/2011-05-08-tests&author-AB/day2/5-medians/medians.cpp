//Task: medians
//Author: Todor Petrov

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

enum Color {
	RED,
	BLACK
};

struct node {
	node* parent;
	node* left;
	node* right;
	Color color;
	int childrenCount;
	double value;
};

node* tree = NULL;
int totalNodes = 0;

struct node * grandparent(struct node *n)
{
	if ((n != NULL) && (n->parent != NULL))
		return n->parent->parent;
	else
		return NULL;
}
 
struct node * uncle(struct node *n)
{
	struct node *g = grandparent(n);
	if (g == NULL)
		return NULL; // No grandparent means no uncle
	if (n->parent == g->left)
		return g->right;
	else
		return g->left;
}

void insert_case1(struct node *n);
void insert_case2(struct node *n);
void insert_case3(struct node *n);
void insert_case4(struct node *n);
void insert_case5(struct node *n);

void insertNode(double value) {
	node* tempNode = new node;
	tempNode->childrenCount = 1;
	tempNode->color = RED;
	tempNode->left = NULL;
	tempNode->right = NULL;
	tempNode->parent = NULL;
	tempNode->value = value;

	if (tree == NULL) {
		tree = tempNode;		
	} else {

		node* currentNode = tree;
		node* previousNode = NULL;
		while (currentNode != NULL) {
			currentNode->childrenCount++;
			previousNode = currentNode;
			if (value > currentNode->value) {			
				currentNode = currentNode->right;
				if (currentNode == NULL) {
					previousNode->right = tempNode;
				}
			} else {
				currentNode = currentNode->left;
				if (currentNode == NULL) {
					previousNode->left = tempNode;
				}
			}
		}

		tempNode->parent = previousNode;
	}
	insert_case1(tempNode);
}

void deleteNode(node* n) {
	if (n == NULL) {
		return;
	}

	node* leftTree = n->left;
	node* rightTree = n->right;

	delete n;
	deleteNode(leftTree);
	deleteNode(rightTree);
}

void rotate_left(node* n) {
	node* g = grandparent(n);
	node* p = n->parent;

	if (g != NULL) {
		if (g->left == p) {
			g->left = n;			
		} else {
			g->right = n;			
		}
		n->parent = g;
	} else {

		// not good but easier for this task only
		tree = n;
		n->parent = NULL;
	}

	p->parent = n;
	n->childrenCount = p->childrenCount;
	node* nLeftChild = n->left;

	if (nLeftChild != NULL) {
		nLeftChild->parent = p;
	}
	n->left = p;
	p->right = nLeftChild;
	p->childrenCount = (p->left != NULL ? p->left->childrenCount : 0) 
		+ (p->right != NULL ? p->right->childrenCount : 0) + 1;
}

void rotate_right(node* n) {
	node* g = grandparent(n);
	node* p = n->parent;

	if (g != NULL) {
		if (g->left == p) {
			g->left = n;			
		} else {
			g->right = n;
		}
		n->parent = g;
	} else {
		// not good but easier for this task only
		tree = n;
		n->parent = NULL;
	}

	p->parent = n;
	n->childrenCount = p->childrenCount;
	node* nRightChild = n->right;

	if (nRightChild != NULL) {
		nRightChild->parent = p;
	}

	n->right = p;
	p->left = nRightChild;
	p->childrenCount = (p->left != NULL ? p->left->childrenCount : 0) 
		+ (p->right != NULL ? p->right->childrenCount : 0) + 1;
}

double findIndex(int index, node* n) {	
	if (n->left != NULL) {
		if (n->left->childrenCount == index) {
			return n->value;
		} else if (n->left->childrenCount > index) {
			return findIndex(index, n->left);
		} else return findIndex(index - n->left->childrenCount - 1, n->right); 
	}

	// no left node
	if (index == 0) {
		return n->value;
	}

	if (n->right != NULL) {
		return findIndex(index - 1, n->right);
	}

	// no left and right node
	return n->value;
}

double getMedian() {
	if (totalNodes % 2 == 1) {
		return findIndex(totalNodes / 2, tree);
	} else {
		int mid = totalNodes / 2;
		return (findIndex(mid - 1, tree) + findIndex(mid, tree)) / 2.0;
	}
}

int main() {

	int start = clock();
	// freopen("C:\\Users\\sexylover\\Desktop\\tasks-olympiads\\rules\\medians\\tests\\medians.09.in", "r", stdin);
	// freopen("C:\\Users\\sexylover\\Desktop\\tasks-olympiads\\rules\\medians\\tests\\medians.09.sol", "w", stdout);
	int n;
	scanf("%d", &n);
	char operation[10];
	double number;

	for (int i = 0; i < n; i++) {
		scanf("%s", operation);

		if (strcmp("A", operation) == 0) {						
			scanf("%lf", &number);
			insertNode(number);
			totalNodes++;
		} else {			
			printf("%.3lf\n", getMedian());			
		}
	}

	deleteNode(tree);

	// cout << (clock() - start) / (double) CLOCKS_PER_SEC << endl;
	return 0;
}

void insert_case1(struct node *n)
{
	if (n->parent == NULL)
		n->color = BLACK;
	else
		insert_case2(n);
}

void insert_case2(struct node *n)
{
	if (n->parent->color == BLACK)
		return; /* Tree is still valid */
	else
		insert_case3(n);
}

void insert_case3(struct node *n)
{
	struct node *u = uncle(n), *g;
 
	if ((u != NULL) && (u->color == RED)) {
		n->parent->color = BLACK;

		if (u != NULL) {
			u->color = BLACK;
		}
		g = grandparent(n);
		g->color = RED;
		insert_case1(g);
	} else {
		insert_case4(n);
	}
}

void insert_case4(struct node *n)
{
	struct node *g = grandparent(n);
 
	if ((n == n->parent->right) && (n->parent == g->left)) {
		rotate_left(n);
		n = n->left;
	} else if ((n == n->parent->left) && (n->parent == g->right)) {
		rotate_right(n);
		n = n->right;
	}
	insert_case5(n);
}

void insert_case5(struct node *n)
{
	struct node *g = grandparent(n);
 
	n->parent->color = BLACK;
	g->color = RED;
	if ((n == n->parent->left) && (n->parent == g->left)) {
		rotate_right(n->parent);
	} else { /* (n == n->parent->right) and (n->parent == g->right) */
		rotate_left(n->parent);
	}
}