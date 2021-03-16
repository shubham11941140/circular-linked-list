/* Definition of a Node of a circular linked list */

typedef struct Node 
{ 
    Element_type element; 	// in this case taken as (int data)
    struct Node* next; 		// Pointer to next node in cll
}cll; // completely replaced the value of struct node to a new Abstract Data Type(ADT) cll for further use in the program

/* Only code snippet has been mentioned here as we do not require to write the full code */
