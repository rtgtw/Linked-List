#include <iostream>


struct Node {

	//Create the data type and the node pointer

	int data;
	struct Node* next;

}*first = NULL;


void displayLinkedList(struct Node *p) {

	//Create a while loop that continues only if the next node pointing is pointing at another node and is not null
	while (p != NULL) {

		int count = 0;

		//Count how many nodes there are
		count++;

		//First print the value that is being pointed at by the first node
		std::cout << "Value of Node " << count << " is: " << p->data << '\n';

		//Store the value of p->next to point to the next node, since its in a while loop it will go until
		//There are no more nodes left
		p = p->next;


	};
};


void displayLinkedListRecursively(struct Node* p) {

	//Recursively iterate through a Linked List and display the elements

	if (p != NULL) {
		//display the data in the first element
		std::cout << "Value is: " << p->data << '\n';


		//call the function again but this time direct it to the next of the current node
		displayLinkedListRecursively(p->next);
	}
};




void displayLinkedListInReverseRecursively(struct Node* p) {

	//Recursively iterate through a Linked List and display the elements

	if (p != NULL) {

		//call the function first so the value is printed on the return to make it reverse
		displayLinkedListInReverseRecursively(p->next);
	
		//display the data in the first element
		std::cout << "Value is: " << p->data << '\n';


	}
};






void createLinkedList(int A[], int n) {

	int i;
	
	struct Node* t;
	struct Node* last;
	
	//Create the first node for the linked list
	first = new Node;

	//Put the data of the first element within the array as the value to the first node, and set the next node to the first node as null
	first->data = A[0];
	first->next = NULL;

	//Last is equal to the first node, which is the last node in the linked list
	last = first;


	for (i = 1; i < n; i++) {


		//We are creating a new node, however last still has the memory address of the previous node
		t = new Node;
		t->data = A[i];
		t->next = NULL;

		//BECAUSE THIS IS ALSO POINTING TO FIRST NEXT, since last = first;
		//Now the first next has the node T, which we just created
		//we are changing the previous nodes next from null, to the value of the new node
		last->next = t;

		//This is very tricky, since last->next is also first->next, that means first is pointing to t;
		//Since first is pointing to t now, we can change the value of last completely and move
		//INTO the t node since first is pointing at it now, and we can repeat this process
		//We are essentially using last as a buffer to create new links
		last = t;



	 }
}


int countOfLinkedList(struct Node* p) {

	int count = 0;

	while (p != NULL) {
		count++;
		p = p->next;

	}

	return count;
}









int main() {

	int A[] = { 3,5,7,10,15 };

	createLinkedList(A, 5);
	//display(first);
	//displayLinkedListRecursively(first);
	//displayLinkedListInReverseRecursively(first);
	std::cout << "Number of nodes: " << countOfLinkedList(first);


	return 0;
}

















/*
---------------------------------------------------------------------------------------------------
A link list is comprised of self referential structures


struct Node{

int data;

struct Node *next;



//q=p; this means that q will be pointing on the same node as p
	//q =p->next, q will be pointing to the next node just like p-> next
	// p = p->next, means p wil move to the next node
	//struct Node *p = NULL, makes the pointer p null
	//0 = false, non-0 = true
	//if (p == NULL) determine if P is null or not
	//if (p != NULL)
	//if (p ->next == NULL) this will detemrine if P is pointing to another node or not



}










---------------------------------------------------------------------------------------------------





	//Create the first pointer in the stack
	struct Node* first;


	//Create a node inside of the heap, assign it to the first pointer
	//Use arrow operator to access members of a node
	first = new Node;

	//access members
	first->data = 5;

	//We should assign the next node with the new node in order to continue the link
	first->next = new Node;


	//In order to call the data members of the second node we need to refer to the first node to do it
	first->next->data = 25;
	first->next->next = new Node;


	//In order to call the data members of the third node we need to refer to first node to do it
	first->next->next->data = 53;
	first->next->next->next = NULL;



	//Assign a new pointer to point at exactly where the first pointer of the linked list is pointing at
	//This way we can traverse through the linkedlist with a second pointer
	struct Node* p = first;



	Display(first);





















---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------













---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------










---------------------------------------------------------------------------------------------------



*/