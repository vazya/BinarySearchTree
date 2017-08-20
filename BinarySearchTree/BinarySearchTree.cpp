#include "BinarySearchTree.h"

void CBinarySearchTree::Print()
{
	if( root != nullptr ) {
		std::cout << "root = ";
		Print( root );
	} else {
		std::cout << "CBinarySearchTree is empty\n";
	}
}

void CBinarySearchTree::Print( Node* currentNode )
{
	if( currentNode != nullptr ) {
		std::cout << "current = " << currentNode->GetKey() << " size = " << currentNode->GetSize() << '\n';
		Print( currentNode->left );
		Print( currentNode->right );
	} else {
		//std::cout << "current is empty\n";
	}
}

void CBinarySearchTree::Insert( int key )
{
	if( root == nullptr ) {
		root = new Node( key );
	} else {
		Insert( key, root, root );
	}
}

Node* CBinarySearchTree::Insert( int key, Node* currentNode, Node* parentNode )
{
	if( currentNode == nullptr ) {
		currentNode = new Node( key, parentNode );
	} else {
		if( key < currentNode->GetKey() ) {
			currentNode->left = Insert( key, currentNode->left, currentNode );
		} else {
			currentNode->right = Insert( key, currentNode->right, currentNode );
		}
		currentNode->height = currentNode->GetHeigh();
		currentNode->size = currentNode->GetSize();
	}
	return currentNode;
}


Node* CBinarySearchTree::Find( int key )
{
	if( root == nullptr ) {
		return nullptr;
	} else {
		Find( key, root );
	}
}

Node* CBinarySearchTree::Find( int key, Node* currentNode )
{
	if( currentNode == nullptr ) {
		return nullptr;
	} else {
		int currentKey = currentNode->GetKey();
		if( key == currentKey ) {
			return currentNode;
		}
		if( key < currentKey ) {
			return Find( key, currentNode->left );
		} else {
			return Find( key, currentNode->right );
		}
	}
	//return currentNode;
}

void CBinarySearchTree::Remove( int key )
{
	auto node = Find( key );
	if( node == nullptr ) {
		std::cout << "This element is missing\n";
	} else {
		Remove( key, node );
	}
}

void CBinarySearchTree::Remove( int key, Node* currentNode )
{
	if( key != currentNode->GetKey() ) {
		std::cout << "You obosralsya\n";
	}
	auto parentNode = currentNode->parent;

	// в случае когда мы в листе
	if( currentNode->IsLeaf() ) {
		if( parentNode == nullptr ) {
			// такое может быть только в root-е, т.е. в дереве 1 элемент
			root = nullptr;
		} else {
			if( parentNode->left != nullptr && parentNode->left->GetKey() == key ) {
				parentNode->left = nullptr;
			} else {
				parentNode->right = nullptr;
			}
			parentNode->SetSize();
		}
	}

	// отсутствует правое поддерево
	if( currentNode->left != nullptr && currentNode->right == nullptr ) {
		if( parentNode == nullptr ) {
			// такое может быть только в root-е, т.е. в дереве 1 элемент
			root = currentNode->left;
		} else {
			if( parentNode->left != nullptr && parentNode->left->GetKey() == key ) {
				parentNode->left = currentNode->left;
			} else {
				parentNode->right = currentNode->left;
			}
			currentNode->parent = parentNode;
			parentNode->SetSize();
		}
	}

	// отсутствует левое поддерево
	if( currentNode->left == nullptr && currentNode->right != nullptr ) {
		if( parentNode == nullptr ) {
			// такое может быть только в root-е, т.е. в дереве 1 элемент
			root = currentNode->right;
		} else {
			if( parentNode->left != nullptr && parentNode->left->GetKey() == key ) {
				parentNode->left = currentNode->right;
			} else {
				parentNode->right = currentNode->right;
			}
			currentNode->parent = parentNode;
			parentNode->SetSize();
		}
	}

	auto minRight = GetMin( currentNode->right );
	// отрезали следующий элемент
	auto minRightParent = minRight->parent;
	minRightParent->left = nullptr;
	minRightParent->SetSize();

	minRight->left = currentNode->left;
	minRight->left->parent = minRight;
	minRight->right = currentNode->right;
	minRight->right->parent = minRight;
	minRight->parent = parentNode;

	if( parentNode == nullptr ) {
		// такое может быть только в root-е, т.е. в дереве 1 элемент
		root = minRight;
	} else {
		if( parentNode->left != nullptr && parentNode->left->GetKey() == key ) {
			parentNode->left = minRight;
		} else {
			parentNode->right = minRight;
		}
		currentNode = nullptr;
	}	
}

