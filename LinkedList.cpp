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


int countOfLinkedListRecursively(struct Node* p) {

	if (p == 0) {
		return 0;
	}
	else
		return  countOfLinkedListRecursively(p->next) + 1 ;
}


void sumOfLinkedList(struct Node* p) {

	int sum = 0;

	while (p != NULL) {

		sum = sum + p->data;
		
		p = p->next;

	}
	std::cout << "Sum: " << sum << '\n';

};



int sumOfLinkedListRecursively(struct Node* p) {
	//Return 0 if p == NULL
	if (p == 0) {

		return 0;
	}
	//Recursive function so call itself, but also add the data for the return
	//We also want to call the next node with p->next
	else
		return sumOfLinkedListRecursively(p->next) + p->data;
};


int maxNodeInLinkedList(struct Node* p) {

	//Set max to the first node value inside of the linked list
	int max = p->data;

	//Create a while loop that stops at the final node in the linked list
	while (p != NULL) {

		//If a value is greater than the max value (first node's value) change the max to that new value
		if (p->data > max) {

			max = p->data;
		}

		p = p->next;
	}
	return max;
};

int minNodeInLinkedList(struct Node* p) {
	//Set min to the first node value inside of the linked list
	int min = p->data;

	//Create a while loop that stops at the final node in the linked list
	while (p != NULL) {

		//If a value is greater than the max value (first node's value) change the max to that new value
		if (p->data < min) {

			min = p->data;
		}
		p = p->next;
	}
	return min;
};


//Linear search v1 of a linked list
//We are going to have the node itself returned which will be an address
//We are going to be searching for a value within the node (the key)

struct Node* linearSearchLinkedList(struct Node* p, int key) {

	//Traverse through the linked list
	while (p != NULL) {

		if (key == p->data) {

			std::cout << "Key Found " << '\n';

			//if we find the node that is equal to the data then return the node itself (the address)
			return p;
		}
		else {

			//if we do not find the key within the node, then traverse to the next node
			p = p->next;
		}
	}

	//If we traversed through the linked list and still have not found the key, then return null
	//indicating that the key value was not present within the linked list
	std::cout << "Key not found " << '\n';
	return NULL;


};















 


int main() {

	int A[] = { 3,5,7,10,15,8,12,20,2};
	createLinkedList(A, 9);
	//display(first);
	//displayLinkedListRecursively(first);
	//displayLinkedListInReverseRecursively(first);
	//std::cout << "Number of nodes: " << countOfLinkedList(first);
	std::cout << "Number of nodes: " << countOfLinkedListRecursively(first) << '\n';
	//sumOfLinkedList(first);
	std::cout << "Sum of nodes: " << sumOfLinkedListRecursively(first) << '\n';
	std::cout << "Max node: " << maxNodeInLinkedList(first) << '\n';
	std::cout << "Min node: " << minNodeInLinkedList(first) << '\n';
	linearSearchLinkedList(first, 12);





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