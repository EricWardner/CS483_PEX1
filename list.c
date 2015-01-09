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
		while(newNode->next != NULL){
			tempNode = headPtr->next;
		}
		tempNode->next = newNode;
		return headPtr;
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

int main(void){
	node* list;
	list = NULL;
	
	char* one = "one";
	char* two = "two";

	list = list_insert_tail(list, one);
	list = list_insert_tail(list, two);
		
	list_print(list);

}
