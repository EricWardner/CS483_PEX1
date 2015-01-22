#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node* list_insert_head(node* headPtr, char* data){
	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = headPtr;

	return newNode;
}

node* list_insert_tail(node* headPtr, char* data){
        node* newNode;
	node* tempNode;
	tempNode = headPtr;
        newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
	newNode->next = NULL;
	//find end of list
	if(headPtr == NULL){
		return newNode;
	}
	else{
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
	newNode->data = data;

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
	node* currNode;
	currNode = headPtr;
	while(currNode != NULL){
		printf("%s\n",currNode->data);
		currNode = currNode->next;
	}
}

void list_printn(node* headPtr, int n){

        node* currNode = headPtr->next;
        node* prevNode = headPtr;
       
        int pos = 1;
        while(currNode->next != NULL){

                if(pos == n){
			printf("%s\n", currNode->data);
			return;
                }
                currNode = currNode->next;
                prevNode = prevNode->next;
                pos++;
        }
        if(currNode->next == NULL){
		printf("%s\n", currNode->data);
		return;
        }
	return;
}

node* list_remove(node* headPtr, char* dataToRm){
	node* currNode;
	node* prevNode;
	
	currNode = headPtr->next;
	prevNode = headPtr;
	
	if((headPtr->data) == dataToRm){
		
		currNode = headPtr->next;
		free(headPtr);
		return currNode;
	}
	while(currNode != NULL){	
		
		if((currNode->data) == dataToRm){
			prevNode->next = currNode->next;
			free(currNode);
			return headPtr;	
		}
		currNode = currNode->next;
		prevNode = prevNode->next;
	}
	
	
	if((currNode->data) == dataToRm){
		free(currNode->next);		
		free(currNode);
		prevNode->next = NULL;
		return headPtr;
	}
	return headPtr;
}

node* list_removen(node* headPtr, int n){
	//need to keep track of previous node
	node* currNode = headPtr->next;
	node* prevNode = headPtr;
	int pos = 1;
	while(currNode->next != NULL){	
		//go through all nodes untill last node		
		if(pos == n){
		//link over the current node
			prevNode->next = currNode->next;
			free(currNode);
			return headPtr;	
		}
		//increment nodes
		currNode = currNode->next;
		prevNode = prevNode->next;
		pos++;
	}
	
	//handle last case
	if(currNode->next == NULL){
		//so many frees
		free(currNode->next);
		free(currNode);
		//previous node is now last node, link to null
		prevNode->next = NULL;
		return headPtr;
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
	//loop through the whole list
	while(currNode != NULL){
		nextNode = currNode->next;
	//free the memory of each node
		free(currNode);
		currNode = nextNode;
	}
	return;		
}
