#include "BinarySearchTree.h"

void find( CBinarySearchTree bst, int key )
{
	auto findelement = bst.Find( key );
	if( findelement == nullptr ) {
		std::cout << key << " is missing\n";
	} else {
		std::cout << key << " is found\n";
	}
}

void f()
{
	CBinarySearchTree bst;
	bst.Insert( 77 );
	bst.Insert( 66 );
	bst.Insert( 88 );
	bst.Insert( 33 );
	bst.Insert( 70 );
	bst.Insert( 120 );
	bst.Insert( 90 );
	bst.Insert( 110 );
	bst.Insert( 22 );
	bst.Insert( 37 );
	bst.Insert( 68 );
	bst.Insert( 72 );
	bst.Print();

	//find( bst, 77 );
	//find( bst, 66 );
	//find( bst, 88 );
	//find( bst, 120 );
	//find( bst, 70 );
	//find( bst, 90 );
	//find( bst, 33 );

	//bst.Remove( 33 );
	//bst.Remove( 120 );
	bst.Remove( 66 );
	find( bst, 66 );

	std::cout << "min = " << bst.GetMin()->GetKey() << '\n';
}

int main()
{
	f();
	return 0;
}