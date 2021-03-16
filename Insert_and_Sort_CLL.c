/* Program to Insert an element in a Sorted Circular Linked list and then print the link list in a sorted manner */

/* We are keeping in mind that we are not optimising any approach and will use the knowledge of Basic pointers */

#include<stdio.h>
#include<stdlib.h>

/* function to insert a newNode in a list in sorted way. */
typedef struct Node 
{ 
    int x; 	
    struct Node* next; 		
}cll;

void sortedInsert(struct Node** headref, struct Node* newNode) 
{
	cll* current = *headref; 
  
	/* This if else decision making decides that at which position the newNode is inserted to giv a sorted list */

 	// if list is empty insertion at first position
  	if (current == NULL) 
  	{ 
     	newNode->next = newNode; 
     	*headref = newNode; 
  	} 

    // if the node is to be inserted at the beginning of the doubly linked list 
  	else if (current->x >= newNode->x) 
  	{ 
    	/* If value is smaller than head's value then we need to change next of last node */
    	while(current->next != *headref) 
		{
			current = current->next;
		}
         
		current->next = newNode; 
		newNode->next = *headref; 
		*headref = newNode; 
  	} 
  
  	else
  	{ 
		/* Locate the node before the point of insertion */
		while (current->next!= *headref &&  
					current->next->x < newNode->x) 
		{
			current = current->next; 
		}		
	
		newNode->next = current->next; 
		current->next = newNode; 
  	} 
} 

/* It is not mentioned to print the list but the following function prints the circular linked list */

/* Function to print nodes in a given linked list */
void printcll(cll *start) 
{ 
	cll *temp;   
  	if(start != NULL) 
  	{ 
    	temp = start; 
    	printf("\n"); 
    	do 
		{
			printf("%d ", temp->x); 
			temp = temp->next; 
		} while(temp != start); 
  	} 
} 

/* Main to run the program */
int main()
{
	int n;
	int list_size, i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int arr[n+1];
	printf("Enter your elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	/* start with empty linked list */
	cll *start = NULL;
	cll *temp;

	printf("Enter the extra element: ");
	scanf("%d",&arr[n]);

	/* Create linked list from the array arr[n+1].*/

	for (i = 0; i< n+1; i++)
	{
		temp = (cll *)malloc(sizeof(cll));
		temp->x = arr[i];
		sortedInsert(&start, temp);
	}

	printcll(start);
	return 0;
}
