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
	node* tempNode;

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
		
		currNode == NULL;
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
	list = list_insert_tail(list, one);
	list = list_insert_tail(list, two);
	list = list_insert_tail(list, two);
	list = list_insert_head(list, four);
	list = list_insert_tail(list, five);
	list = list_insert_head(list, four);
	
		
	list_print(list);

	list = list_insertn(list, five, 3);

	list_print(list);

	//list = list_remove(list, one);
	//list = list_remove(list, four);
	

	//list_print(list);
}
