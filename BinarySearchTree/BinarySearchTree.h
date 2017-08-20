#pragma once
#include <iostream>

// структура для представления узлов дерева
class Node {
public:
	int key;
	int height;
	int size;
	Node* left;
	Node* right;
	Node* parent;
	Node() : key( 0 ), left( nullptr ), right( nullptr ), parent( nullptr ), height( 1 ), size( 1 ) {};
	Node( int k ) : key( k ), left( nullptr ), right( nullptr ), parent( nullptr ), height( 1 ), size( 1 ) {};
	Node( int k, Node* parentNode ) : key( k ), left( nullptr ), right( nullptr ), parent( parentNode ), height( 1 ), size( 1 ) {};

	int GetKey() { return key; }
	int GetSize() {
		int leftSize = ( left == nullptr ) ? 0 : left->GetSize();
		int rightSize = ( right == nullptr ) ? 0 : right->GetSize();
		return leftSize + rightSize + 1;
	}
	void SetSize()
	{
		size = GetSize();
		if( parent != nullptr ) {
			parent->SetSize();
		}
	}

	int GetHeigh() {
		int leftHeigh = ( left == nullptr ) ? 0 : left->GetHeigh();
		int rightHeigh = ( right == nullptr ) ? 0 : right->GetHeigh();
		return leftHeigh + rightHeigh + 1;
	}
	bool IsLeaf()
	{
		if( ( left == nullptr ) && ( right == nullptr ) ) {
			return true;
		}
		return false;
	}
};

class CBinarySearchTree {
public:
	void Insert( int key );
	Node* Find( int key );
	void Remove( int key );

	void Print();

	CBinarySearchTree() { root = nullptr; }

	Node* Insert( int key, Node* currentNode, Node* parentNode );
	Node* Find( int key, Node* currentNode );
	void Remove( int key, Node* currentNode );
	void Print( Node* currentNode );

	Node* GetMin()	{
		return GetMin( root );
	}
	Node* GetMin( Node* currentNode )	{		if( currentNode->left != nullptr ) {
			return GetMin( currentNode->left );
		}
		return currentNode;
	}
private:
	Node* root;
};