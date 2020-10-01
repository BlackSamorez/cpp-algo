#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

//struct Node { int64_t value; Node *next; };

Node *mergeLists(Node *first_node, Node *second_node){
	Node *nnode = new Node;
	if (first_node == NULL or second_node == NULL){
		if (first_node == NULL and second_node == NULL){
			return NULL;
		}
	if (first_node == NULL and second_node != NULL){
		return second_node;
	}
	if (first_node != NULL and second_node == NULL){
		return first_node;
	}

	} else {
		if (first_node->value > second_node->value){
			nnode->value = second_node->value;
			nnode->next = mergeLists(first_node, second_node->next); 
		}
		if (first_node->value < second_node->value){
			nnode->value = first_node->value;
			nnode->next = mergeLists(first_node->next, second_node); 
		}
		if (first_node->value == second_node->value){
			nnode->value = first_node->value;
			nnode->next = mergeLists(first_node->next, second_node->next);
		}

	}
	return nnode;
}
/*
int main(){
	int n, m;
	cin >> n >> m;
	Node nn[n], nm[m];
	for (int i = 0; i < n; i++){
		cin >> nn[i].value;
		if (i != n - 1){
			nn[i].next = nn + i + 1;
		} else {
			nn[i].next = NULL;
		}
	}
	for (int i = 0; i < m; i++){
		cin >> nm[i].value;
		if (i != m - 1){
			nm[i].next = nm + i + 1;
		} else {
			nm[i].next = NULL;
		}
	}
	Node *out;
	out = mergeLists(nn, nm);
	for (int i = 0; i < n + m; i++){
		cout << out->value << " ";
		out = out->next;
	}
	cout << "\n";


return 0;
} */