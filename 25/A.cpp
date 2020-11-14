#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

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

template<typename T>
void pop_front(std::vector<T>& vec){
    vec.erase(vec.begin());
}

template <typename T>
class Tree{
private:
	Node<T>* root;
	Node<T>* NIL = new Node<T>(0);
	std::vector<Node<T>*> queue;

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

	void wfs(){
		this->queue.push_back(root);

		while (this->queue.size()){
			Node<T> tmp = *(this->queue[0]);
			std::cout << tmp.data << " ";
			if (tmp.left != NIL){
				this->queue.push_back(tmp.left);
				//std::cout << tmp.left->data << "l ";
			}
			if (tmp.right != NIL){
				this->queue.push_back(tmp.right);
				//std::cout << tmp.right->data << "r ";
			}
			pop_front(this->queue);
		}
		std::cout << "\n";
	}
};

int main(){
	Tree<int> t;
		while (std::cin){
			int x;
			std::cin >> x;
			t.insert(x);
		}
		t.wfs();
return 0;
}