#pragma once
#ifndef BST_H_
#define BST_H_
#include<iostream>
#include "Setting.h"

enum TYPE_SETTING {
	TYPE_GENERAL = 1,
	TYPE_DISPLAY,
	TYPE_SOUND,
	TYPE_ALL,
};
class BST {
private:
	struct node {
		Setting* data;
		node* left;
		node* right;
	};
	node* root;
	vector<node*>v;
public:
	BST();
	~BST();

	node* createLeaf(Setting* data);
	void InsertNode(Setting* data);
	void SaveDataOfNodes();
	node* searchNodeInKey(string key);
	int sizeTree();
	void inorder_print(TYPE_SETTING input);
	void InsertNodePrivate(Setting* data, node* ptr);
	void SaveDataOfNodesPrivate(node* ptr, ofstream& file);
	node* searchNodeInKeyPrivate(string key, node* ptr);
	int sizeTreePrivate(node* ptr);
	void inorder_print(TYPE_SETTING input, node* leaf);
	void searchNodeInnamePrivate(string name, node* ptr);
	vector<node*> searchNodeInName(string name);

};
#endif // !BST_H_



