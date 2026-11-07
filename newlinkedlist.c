
#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	int value;
	struct Node *next;
}Node;


//
Node *create_node(int data);
//
void append(Node **head, int data);
// void append_not_elegant(Node **head, int data);
//
void print_list(Node *head);
//
int list_length(Node *head);
//
// void free_list(Node **head);
//
void push_front(Node **head, int value);
void insert_at(Node **head,int value, int index);
//
// void delete_value(Node **head, int value);
// void delete_at(Node **head, int index);



int main(){
	Node *head = NULL;

	insert_at(&head, 100, 0);
	insert_at(&head, 200, 1);
	print_list(head);
	insert_at(&head, 400, 1);
	print_list(head);

}

Node *create_node(int value){

	Node *nodePtr = malloc(sizeof(Node));

	if (nodePtr== NULL){
		return NULL;
	}

	nodePtr->next = NULL;
	nodePtr->value = value;

	return nodePtr;

}


void append(Node **head, int value){

	Node **trace = head;

	while (*trace != NULL) {
		trace = &(*trace)->next;
	}

	Node *newNode = create_node(value);

	if (newNode==NULL){
		printf("error creaintg node before appedning value %d \n", value);
		return;
	}

	*trace = newNode;


}

void print_list(Node *head){
	printf("{ ");

	while (head!=NULL) {
		printf("%d, ",head->value);
		head = head->next;
	}
	printf("}\n");
}

int list_length(Node *head){

	int i =0;
	while (head!=NULL) {
		printf("%d, ",head->value);
		head = head->next;
		i++;
	}
	return i;
}

 void push_front(Node **head, int value){
	Node *newHead = create_node(value);
	newHead->next = *head;
	*head = newHead;
	printf("new head is %d \n", (*head)->value);
}



/* insert 400 en index 1 
 *  (100 -> 200)
 *
 * i = 0 
 * *trace = puntero a 100
 *
 * i= 1
 * *trace = puntero a 200
 *
 * *tmp = puntero a 200
 *
 * pero el prevNode apiuntaba a *trace????
 * *trace = puntero al NUEVO 
 * */
 void insert_at(Node **head, int value, int index){

	Node **trace = head; 

	int i=0;
	while (*trace != NULL && i<index){
		trace = &(*trace)->next;
		i++;
	}

	if (i!=index){
		printf("invalid index");
		return;
	}

	//*head = newNode (if the first elemnt was null)
	//* trace equivale al valor de index que queremos poner. 
	// 100 - 200 - 300.    Si queremos añadir 1 al index 1. 
	// Entonces *trace equivale al index 1 = 200
	// Debemos t
	//Este de abajo equilve al nodo de 200
	Node *tmp = *trace;

	//*trace apuntaba a 200, ahora apunta a 1. seria ahora 100 -> 1  y 200->300. Faltaria apuntar 1 -> 200
	*trace = create_node(value);

	//actualizamso para que quede 100-> 1 -> (esto es) 200 ->300
	(*trace)->next = tmp;

}

