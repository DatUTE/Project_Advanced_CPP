#include "BST.h"
#include"Setting.h"
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<vector>


BST::BST() {
	root = NULL;
}

BST::~BST() {
	SaveDataOfNodes();
}

BST::node* BST::createLeaf(Setting* data) {
	node* n = new node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void BST::InsertNode(Setting* data) {
	InsertNodePrivate(data, root);
}

void BST::InsertNodePrivate(Setting* data, node* ptr) {
	string name_data = "";
	string node_data = "";
	if (ptr != NULL) {
		name_data = data->getPersonalKey();
		node_data = ptr->data->getPersonalKey();
	}
	if (root == NULL) {
		root = createLeaf(data);
	}
	else if (name_data.compare(node_data) < 0) {
		if (ptr->left != NULL) {
			InsertNodePrivate(data, ptr->left);
		}
		else {
			ptr->left = createLeaf(data);
		}
	}
	else if (name_data.compare(node_data) > 0) {
		if (ptr->right != NULL) {
			InsertNodePrivate(data, ptr->right);
		}
		else {
			ptr->right = createLeaf(data);
		}
	}
	else {
		cout << "Data: " << data << " has already been adde to the tree\n";
	}
}

void BST::SaveDataOfNodes() {
	ofstream file1("Setting.txt");
	try {
		if (file1.is_open()) {
			SaveDataOfNodesPrivate(root, file1);
		}
		else {
			throw exception();	//throw out the warning
		}
	}
	catch (const exception& e) {
		cerr << "Unable to open file to write " << "Setting.txt" << endl;
	}

}

void BST::SaveDataOfNodesPrivate(node* ptr, ofstream& file) {
	if (root != NULL) {
		if (ptr->left != NULL) {
			SaveDataOfNodesPrivate(ptr->left, file);
		}
		file << ptr->data->toStringSetting() << ptr->data->getGeneral()->toStringGeneral()
			<< ptr->data->getSound()->toStringSound() << ptr->data->getDisplay()->toStringDisplay() << endl;
		if (ptr->right != NULL) {
			SaveDataOfNodesPrivate(ptr->right, file);
		}
	}
	else {
		cout << "the tree is empty\n";
	}



}


int BST::sizeTree() {
	return sizeTreePrivate(root);
}
int BST::sizeTreePrivate(node* ptr) {
	if (ptr == NULL)
		return 0;
	else
		return(sizeTreePrivate(ptr->left) + 1 + sizeTreePrivate(ptr->right));
}

//in trung to LNR
void BST::inorder_print(TYPE_SETTING input) {
	inorder_print(input, root);
	cout << "\n";
}

void BST::inorder_print(TYPE_SETTING input, node* leaf) {
	if (leaf != NULL) {
		switch (input)
		{
		case 1:
			inorder_print(TYPE_GENERAL, leaf->left);
			leaf->data->xuatThongTin();
			leaf->data->getGeneral()->xuatThongTin();
			cout << endl;
			inorder_print(TYPE_GENERAL, leaf->right);
			break;
		case 2:
			inorder_print(TYPE_SOUND, leaf->left);
			leaf->data->xuatThongTin();
			leaf->data->getSound()->xuatThongTin();
			cout << endl;
			inorder_print(TYPE_SOUND, leaf->right);
			break;
		case 3:
			inorder_print(TYPE_DISPLAY, leaf->left);
			leaf->data->xuatThongTin();
			leaf->data->getDisplay()->xuatThongTin();
			cout << endl;
			inorder_print(TYPE_DISPLAY, leaf->right);
			break;
		case 4:
			inorder_print(TYPE_ALL, leaf->left);
			leaf->data->xuatThongTin();
			leaf->data->getDisplay()->xuatThongTin();
			leaf->data->getSound()->xuatThongTin();
			leaf->data->getGeneral()->xuatThongTin();
			cout << endl;
			inorder_print(TYPE_ALL, leaf->right);
		default:
			break;
		}
	}
}

vector<BST::node*> BST::searchNodeInName(string name) {
	v.clear();
	searchNodeInnamePrivate(name, root);
	return v;
}

void BST::searchNodeInnamePrivate(string name, node* ptr)
{
	if (ptr != NULL) {
		if (ptr->data->getCarName() == name) {
			v.push_back(ptr);
		}
		searchNodeInnamePrivate(name, ptr->left);
		searchNodeInnamePrivate(name, ptr->right);
	}

}
BST::node* BST::searchNodeInKey(string key) {
	return searchNodeInKeyPrivate(key, root);
}

BST::node* BST::searchNodeInKeyPrivate(string key, node* ptr) {
	if (ptr != NULL) {
		if (ptr->data->getPersonalKey() == key) {
			return ptr;
		}
		else {
			if (key < ptr->data->getPersonalKey()) {
				return searchNodeInKeyPrivate(key, ptr->left);
			}
			else {
				return searchNodeInKeyPrivate(key, ptr->right);
			}
		}
	}
	else {
		return NULL;
	}
}