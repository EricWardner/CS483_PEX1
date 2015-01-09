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
        newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
	newNode->next = NULL;
	//recursion to find end of list
	if(headPtr == NULL){
		return newNode;
	}
	else{
		while(headPtr != NULL){
			headPtr = headPtr->next;
		}
		headPtr->next = newNode;
	}

}

int main(void){
	node* list;
	list->data = NULL;
	
	char* one = "one";

	list = list_insert_tail(list, one);	

}
