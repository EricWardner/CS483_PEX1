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

/* list_remove: remove the node containing specific data; if multiple nodes
    contain the data, remove the node nearest to the head
*/

// What if the user enters a negative number or very big?

node* list_insertn(node* headPtr, char* data, int n){

	node* currNode;
	node* newNode;

	currNode = headPtr;

	newNode = (node*)malloc(sizeof(node));
	newNode->data = data;

	int pos = 0;
	if (headPtr == NULL) {

		return newNode;
	}

	while (currNode->next != NULL) {
	
		if (pos == n) {			
			
			newNode->next = currNode->next;
			currNode->next = newNode;
			
			return headPtr;
		}
		currNode = currNode->next;
		pos++;
	}	
}

void list_print(node* headPtr){
	node* currNode;
	currNode = headPtr;
	while(currNode != NULL){
		printf("%s\n",currNode->data);
		currNode = currNode->next;
	}
}

node* list_remove(node* headPtr, char* dataToRm){
	node* currNode;
	node* prevNode;
	
	currNode = headPtr->next;
	prevNode = headPtr;
	
	if(*(headPtr->data) == *dataToRm){
		
		headPtr = headPtr->next;
		return headPtr;
	}
	while(currNode->next != NULL){	
		
		if(*(currNode->data) == *dataToRm){
			prevNode->next = currNode->next;
			return headPtr;	
		}
		currNode = currNode->next;
		prevNode = prevNode->next;
	}
	
	
	if(*(currNode->data) == *dataToRm){
		free(currNode->next);		
		currNode == NULL;
		return headPtr;
	}
}
node* list_removen(node* headPtr, int n){

	node* currNode;
	node* prevNode;
	
	currNode = headPtr->next;
	prevNode = headPtr;
	//this is real janky
	int pos = 1;
	//is this ok, to just handle 0 case???
	if(n == 0){
		
		headPtr = headPtr->next;
		return headPtr;
	}
	while(currNode->next != NULL){	
		
		if(pos == n){
			prevNode->next = currNode->next;
			return headPtr;	
		}
		currNode = currNode->next;
		prevNode = prevNode->next;
		pos++;
	}
	
	
	if(currNode->next == NULL){
		free(currNode->next);
		free(currNode);
		prevNode->next = NULL;
		return headPtr;
	}	
}
int main(void){
	node* list;
	list = NULL;
	
	char* one = "one";
	char* two = "two";
	char* three = "three";
	char* four = "four";
	char* five = "five";
	

	list = list_insert_tail(list, one);
	list = list_insert_tail(list, two);
	list = list_insert_tail(list, three);
	list = list_insert_tail(list, four);
	list = list_insert_tail(list, five);

	
		
	list_print(list);

	list = list_removen(list, 2);
	printf("\n");

	list_print(list);

	//list = list_remove(list, one);
	//list = list_remove(list, four);
	

	//list_print(list);
}
