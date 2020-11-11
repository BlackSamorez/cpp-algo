#include <iostream>
#include <functional>
#include <algorithm>

typedef enum {BLACK, RED} nodeColor;

template<class T>
class Node{
private:
    Node<T>*left;
    Node<T>*right;
    Node<T>* parent;
    nodeColor color;
    T data;
public:
    Node(T data){
    	this->parent = NULL;
    	this->left = NULL;
    	this->right = NULL;
    	this->color = BLACK;
    	this->data = data;
    }
    template <typename G> friend class Tree;
};

template <typename T>
class Tree{
private:
	Node<T>* root;
	Node<T>* NIL = new Node<T>(0);

	Node<T>* find(T data){
		Node<T>*current = root;
	    while(current != NIL)
	        if(compEQ(data, current->data))
	            return (current);
	        else
	            current = compLT(data, current->data) ?
	                current->left : current->right;
	    return(0);
	}

	void rotateLeft(Node<T>*x) {
		Node<T>*y = x->right;

	    x->right = y->left;
	    if (y->left != NIL) y->left->parent = x;

	    if (y != NIL) y->parent = x->parent;
	    if (x->parent) {
	        if (x == x->parent->left)
	            x->parent->left = y;
	        else
	            x->parent->right = y;
	    } else {
	        root = y;
	    }

	    y->left = x;
	    if (x != NIL) x->parent = y;
	}

	void rotateRight(Node<T>*x) {
		Node<T>*y = x->left;

	    x->left = y->right;
	    if (y->right != NIL) y->right->parent = x;

	    if (y != NIL) y->parent = x->parent;
	    if (x->parent) {
	        if (x == x->parent->right)
	            x->parent->right = y;
	        else
	            x->parent->left = y;
	    } else {
	        root = y;
	    }

	    y->right = x;
	    if (x != NIL) x->parent = y;
	}

	void insertFixup(Node<T>*x) {
		while (x != root && x->parent->color == RED) {
	        if (x->parent == x->parent->parent->left) {
	            Node<T>*y = x->parent->parent->right;
	            if (y->color == RED) {

	                x->parent->color = BLACK;
	                y->color = BLACK;
	                x->parent->parent->color = RED;
	                x = x->parent->parent;
	            } else {

	                if (x == x->parent->right) {
	                    x = x->parent;
	                    this->rotateLeft(x);
	                }

	                x->parent->color = BLACK;
	                x->parent->parent->color = RED;
	                this->rotateRight(x->parent->parent);
	            }
	        } else {

	            Node<T>*y = x->parent->parent->left;
	            if (y->color == RED) {

	                x->parent->color = BLACK;
	                y->color = BLACK;
	                x->parent->parent->color = RED;
	                x = x->parent->parent;
	            } else {

	                if (x == x->parent->left) {
	                    x = x->parent;
	                    this->rotateRight(x);
	                }
	                x->parent->color = BLACK;
	                x->parent->parent->color = RED;
	                this->rotateLeft(x->parent->parent);
	            }
	        }
	    }
	    root->color = BLACK;
	}

	void deleteFixup(Node<T>*x) {
        while (x != root && x->color == BLACK) {
	        if (x == x->parent->left) {
	            Node<T>*w = x->parent->right;
	            if (w->color == RED) {
	                w->color = BLACK;
	                x->parent->color = RED;
	                this->rotateLeft(x->parent);
	                w = x->parent->right;
	            }
	            if (w->left->color == BLACK && w->right->color == BLACK) {
	                w->color = RED;
	                x = x->parent;
	            } else {
	                if (w->right->color == BLACK) {
	                    w->left->color = BLACK;
	                    w->color = RED;
	                    this->rotateRight(w);
	                    w = x->parent->right;
	                }
	                w->color = x->parent->color;
	                x->parent->color = BLACK;
	                w->right->color = BLACK;
	                this->rotateLeft(x->parent);
	                x = root;
	            }
	        } else {
	            Node<T>*w = x->parent->left;
	            if (w->color == RED) {
	                w->color = BLACK;
	                x->parent->color = RED;
	                this->rotateRight(x->parent);
	                w = x->parent->left;
	            }
	            if (w->right->color == BLACK && w->left->color == BLACK) {
	                w->color = RED;
	                x = x->parent;
	            } else {
	                if (w->left->color == BLACK) {
	                    w->right->color = BLACK;
	                    w->color = RED;
	                    this->rotateLeft(w);
	                    w = x->parent->left;
	                }
	                w->color = x->parent->color;
	                x->parent->color = BLACK;
	                w->left->color = BLACK;
	                this->rotateRight(x->parent);
	                x = root;
	            }
	        }
	    }
	    x->color = BLACK;
	}

	void deleteNode(Node<T>*z) {
	    Node<T>*x, *y;

	    if (!z || z == NIL) return;


	    if (z->left == NIL || z->right == NIL) {
	        y = z;
	    } else {
	        y = z->right;
	        while (y->left != NIL) y = y->left;
	    }

	    if (y->left != NIL)
	        x = y->left;
	    else
	        x = y->right;

	    x->parent = y->parent;
	    if (y->parent)
	        if (y == y->parent->left)
	            y->parent->left = x;
	        else
	            y->parent->right = x;
	    else
	        root = x;

	    if (y != z) z->data = y->data;


	    if (y->color == BLACK)
	        this->deleteFixup(x);

	    delete [] y;
	}

	std::function<bool(T, T)> compLT;
	std::function<bool(T, T)> compEQ;

public:
	void assignLT(std::function<bool(T, T)> f){
		this->compLT = f;
	}

	void assignEQ(std::function<bool(T, T)> f){
		this->compEQ = f;
	}

	Tree(T data){
		root = new Node<T>(data);
		NIL->left = NIL;
		NIL->right = NIL;
		NIL->parent = NULL;
		NIL->color = BLACK;
		NIL->data = 0;
		root->left = NIL;
		root->right = NIL;
		compLT = [](T a, T b){return a < b;};
		compEQ = [](T a, T b){return a == b;};
	}

	Tree(){
		root = NULL;
		NIL->left = NIL;
		NIL->right = NIL;
		NIL->parent = NULL;
		NIL->color = BLACK;
		NIL->data = 0;
		compLT = [](T a, T b){return a < b;};
		compEQ = [](T a, T b){return a == b;};
	}

	bool present(T data){
		return this->find(data);
	}

	void insert(T data){
		Node<T>*current, *parent;

		Node<T>*x = new Node<T>(data);

		if (!root){
			x->data = data;
		    x->parent = NULL;
		    x->left = NIL;
		    x->right = NIL;
		    x->color = BLACK;
			root = x;
			return;
		}

	   	current = root;
	    parent = 0;
	    while (current != NIL) {
	        if (compEQ(data, current->data)) return;
	        parent = current;
	        current = compLT(data, current->data) ?
	            current->left : current->right;
	    }

	    x->data = data;
	    x->parent = parent;
	    x->left = NIL;
	    x->right = NIL;
	    x->color = RED;

	    if(parent) {
	        if(compLT(data, parent->data))
	            parent->left = x;
	        else
	            parent->right = x;
	    } else {
	        root = x;
	    }

	    insertFixup(x);	
	}

	void erase(T data){
		if (this->find(data)){
			this->deleteNode(this->find(data));
		}
	}

	int depth(Node<T>* x){
		if (x == NIL){
			return 0;
		}
		return (1 + std::max(depth(x->right), depth(x->left)));
	}
};

int main(){
	std::function<bool(int, int)> greater = [](int a, int b){return a>b;}; 
	Tree<int> t;
	t.assignLT(greater);
	for (int i = 0; i < 100; ++i){
		t.insert((i * i * i + 3 * i + 2) % (i + 5));
	}
	for (int i = 0; i < 100; ++i){
		t.erase((i * i * i + 2 * i + 1) % (i + 3));
	}
return 0;
}
