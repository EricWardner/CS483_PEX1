#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node* list_insert_head(node* headPtr, char* data){
	node* newNode;
	//allocate memory for new node
	newNode = (node*)malloc(sizeof(node));
	//link the nodes
	//newNode->data = data;
	newNode->data = (char*)malloc(strlen(data)+1);
	strcpy(newNode->data,data);
	newNode->next = headPtr;

	return newNode;
}

node* list_insert_tail(node* headPtr, char* data){
        node* newNode;
	node* tempNode;
	tempNode = headPtr;
        newNode = (node*)malloc(sizeof(node));
        //newNode->data = data;
	newNode->data = (char*)malloc(strlen(data)+1);
	strcpy(newNode->data,data);
	newNode->next = NULL;
	//find end of list
	//if empty, create head
	if(headPtr == NULL){
		return newNode;
	}
	else{
		//traverse through list until tail is found
		while(tempNode->next != NULL){
			tempNode = tempNode->next;
		}
		tempNode->next = newNode;
		return headPtr;
	}

}
// What if the user enters a negative number or very big?
node* list_insertn(node* headPtr, char* data, int n){

	node* currNode;
	node* newNode;

	currNode = headPtr;

	newNode = (node*)malloc(sizeof(node));
	//newNode->data = data;
	newNode->data = (char*)malloc(strlen(data)+1);
	strcpy(newNode->data,data);

	int pos = 1;
	if (headPtr == NULL) {

		return newNode;
	}

	while (currNode != NULL) {
	
		if (pos == n-1) {			
			
			newNode->next = currNode->next;
			currNode->next = newNode;
			
			return headPtr;
		}
		currNode = currNode->next;
		pos++;
	}
	return headPtr;	
}

void list_print(node* headPtr){
	node* currNode = headPtr;
	while(currNode != NULL){
		printf("%s\n",currNode->data);
		currNode = currNode->next;
	}
}

void list_printn(node* headPtr, int n){

        node* currNode = headPtr;
        int pos = 1;
        while(currNode != NULL){
                if(pos == n){
			printf("%s\n", currNode->data);
			return;
                }
                currNode = currNode->next;
                pos++;
        }
	return;
}

node* list_remove(node* headPtr, char* dataToRm){
	node* currNode;
	node* prevNode;
	
	currNode = headPtr->next;
	prevNode = headPtr;
	//handle head node case
	//if((headPtr->data) == dataToRm){
	if(strcmp(headPtr->data,dataToRm) == 0){
		//just increment the head
		currNode = headPtr->next;
		//free(headPtr);
		free(headPtr->data);
		free(headPtr);
		return currNode;
	}
	//traverse through list
	while(currNode != NULL){	
		//check for match in data
		//if((currNode->data) == dataToRm){
		if(strcmp(currNode->data,dataToRm) == 0){
			//link over and free node with match
			prevNode->next = currNode->next;
			//free(currNode);
			free(currNode->data);
			free(currNode);
			return headPtr;	
		}
		//increment nodes
		currNode = currNode->next;
		prevNode = prevNode->next;
	}
	
	//handle last case
//	if((currNode->data) == dataToRm){
//		free(currNode->next);		
//		free(currNode);
//		prevNode->next = NULL;
//		return headPtr;
//	}
	//if no match
	return headPtr;
}

node* list_removen(node* headPtr, int n){
	//need to keep track of previous node
	node* currNode = headPtr->next;
	node* prevNode = headPtr;
	int pos = 2;
	//handle first case, just remove head node
	if(n == 1){
		//free(headPtr);
		free(headPtr->data);
		free(headPtr);
		return currNode;
	}
	while(currNode != NULL){	
		//go through all nodes untill last node		
		if(pos == n){
		//link over the current node
			prevNode->next = currNode->next;
			//free(currNode);
			free(currNode->data);
			free(currNode);
			return headPtr;	
		}
		//increment nodes
		currNode = currNode->next;
		prevNode = prevNode->next;
		pos++;
	}
	//if n is not in list, just return the list
	return headPtr;
}

char* list_get(node* headPtr, int n){
	int pos = 1;
	node* currNode = headPtr;
	//loop through all the nodes 
	while(currNode != NULL){
		if(pos == n){
	//return the node's data, if right position
			return currNode->data;
		}
	//increment position and node
		pos++;
		currNode = currNode->next;
	}
	//if given n is out of bounds, return null
	return NULL; 
}

void list_destroy(node* headPtr){
	//initialize the nodes
	node* currNode = headPtr;
	node* nextNode = headPtr->next;
	if(nextNode == NULL){
		//free(currNode);
		free(currNode->data);
		free(currNode);
		return;
	}
	//loop through the whole list
	while(currNode != NULL){
		nextNode = currNode->next;
	//free the memory of each node
		//free(currNode);
		free(currNode->data);
		free(currNode);
		currNode = nextNode;
	}
	return;		
}
