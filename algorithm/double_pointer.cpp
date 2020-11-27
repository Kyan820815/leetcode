#include <iostream>

using namespace std;
struct node
{
	int val;
	struct node *next;
};

void test(struct node **node, int val)
{
	//--- we can use this insted *node = ...
	// struct node *test;
	// test = (struct node *)malloc(sizeof(struct node));
	// node = &test;

	*node = (struct node*)malloc(sizeof(struct node));
	(*node)->val = val;
	std::cout << "in function: \n\n";
	std::cout << "node value: " <<(*node)->val << "\n\n";
	std::cout << "first pointer addr " << &node << "\n\n";
	std::cout << "second pointer addr " << node << "\n\n";
	std::cout << "second pointer addr " << &(*node) << "\n\n";
	std::cout << "third pointer addr " << *node << "\n\n";
	std::cout << "third pointer addr " << &(*node)->val << "\n\n";
}

int main(void)
{
	struct node **node;
	
	node = (struct node **)malloc(sizeof(struct node*));
	*node = (struct node*)malloc(sizeof(struct node));
	(*node)->val = 5;
	std::cout << "node value: " <<(*node)->val << "\n\n";
	std::cout << "first pointer addr " << &node << "\n\n";
	std::cout << "second pointer addr " << node << "\n\n";
	std::cout << "second pointer addr " << &(*node) << "\n\n";
	std::cout << "third pointer addr " << *node << "\n\n";
	std::cout << "third pointer addr " << &(*node)->val << "\n\n";
	test(node, 6);
	std::cout << "out function: \n\n";
	std::cout << "node value: " <<(*node)->val << "\n\n";
	std::cout << "first pointer addr " << &node << "\n\n";
	std::cout << "second pointer addr " << node << "\n\n";
	std::cout << "second pointer addr " << &(*node) << "\n\n";
	std::cout << "third pointer addr " << *node << "\n\n";
	std::cout << "third pointer addr " << &(*node)->val << "\n\n";

	return 0;
}