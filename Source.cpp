#include <iostream>
#include<string>

using namespace std;

int totalweight = 0;
char previousNode = 'g';

struct node {

	node* link[50]; //this array stores the links between nodes. This allows a node to have as many link as required
	int weights[50];
	char name;

	/*these constructors link the weights passed in the consructor to the links.*/

	node(int one, int two, char nme) {
		weights[0] = one;
		weights[1] = two;
		name = nme;

		for (int i = 2; i < 50; i++) {
			weights[i] = 9999;
		}

		for (int i = 0; i < 50; i++) //sets all pointers in the array to null when constructed
			link[i] = nullptr;
	}

	node(int one, int two, int three, char nme) {
		weights[0] = one;
		weights[1] = two;
		weights[2] = three;
		name = nme;

		for (int i = 3; i < 50; i++)
			weights[i] = 9999;

		for (int i = 0; i < 50; i++)
			link[i] = nullptr;
	}
};


void displayPath(node*);

int main() {

	node a(2, 4, 'a');
	node b(1, 5, 'b');
	node c(10, 8, 1, 'c');
	node d(2, 6, 'd');
	node e(5, 2, 'e');
	node z(0, 0, 'z');

	a.link[0] = &c;
	a.link[1] = &b;

	b.link[0] = &c;
	b.link[1] = &d;

	c.link[0] = &e;
	c.link[1] = &d;
	c.link[2] = &b;

	d.link[0] = &e;
	d.link[1] = &z;

	e.link[0] = &z;
	e.link[1] = &d;

	z.link[0] = nullptr;
	z.link[1] = nullptr;
	z.link[2] = nullptr;


	cout << "a:Child1 " << a.link[0] << endl;
	cout << "a:Child2 " << a.link[1] << endl;
	cout << "a:weight1 " << a.weights[0] << endl;
	cout << "a:wight2 " << a.weights[1] << endl;

	cout << endl << endl << endl;
	
	
	displayPath(&a);

	return 0;
}

void displayPath(node* node) {

	bool completed = false;

	cout << "We are at: " << node->name << endl;
	cout << "The previous node was " << previousNode << endl;

	if (node->link[0]) {


		if (node->weights[0] < node->weights[1] && node->weights[0] < node->weights[2] && completed == false) {
			if (previousNode != node->link[0]->name) {

				totalweight += node->weights[0];
				previousNode = node->name;
				cout << "The current weight is: " << totalweight << endl;
				node->weights[0] = 9999;
				displayPath(node->link[0]);
				completed = true;
			}
		}

		if (node->weights[1] < node->weights[2] && completed == false) {
			if (previousNode != node->link[1]->name) {

				totalweight += node->weights[1];
				previousNode = node->name;
				cout << "The current weight is: " << totalweight << endl;
				node->weights[1] = 9999;
				displayPath(node->link[1]);
				completed = true;
			}
			else {
				totalweight += node->weights[0];
				previousNode = node->name;
				cout << "The current weight is: " << totalweight << endl;
				node->weights[0] = 9999;
				displayPath(node->link[0]);
				completed = true;
			}
		}

		if (node->link[2] != nullptr && completed == false) {

			if (previousNode != node->link[2]->name) {

				previousNode = node->name;
				totalweight += node->weights[2];
				cout << "The current weight is: " << totalweight << endl;
				node->weights[2] = 9999;
				displayPath(node->link[2]);
				completed = true;
			}
		}
	}
}





	//if (node->leftWeight < node->rightWeight && node->left != nullptr && node->right != nullptr) {
	//	pathweight += node->leftWeight;
	//	cout << "left " << endl;
	//	cout << pathweight << endl;
	//	displayPath(node->left);
	//}
	//else if (node->left != nullptr && node->right != nullptr) {
	//	pathweight += node->rightWeight;
	//	cout << "right " << endl;
	//	cout << pathweight << endl;
	//	displayPath(node->right);
	//}
	//else
	//	cout << "The total weight of the shortest path is: " << pathweight << endl;
