#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	int value;
	struct Node *next;

}Node;


Node *create_node(int data);

void append_elegant(Node **head, int data);
void append_not_elegant(Node **head, int data);

void print_list(Node *head);

int list_length(Node *head);

void free_list(Node **head);

void push_front(Node **head, int value);
int insert_at(Node **head,int index, int value);

void delete_value(Node **head, int value);
void delete_at(Node **head, int index);

Node *find_node(Node *head, int vlaue);


void reverse_list(Node **head);
int main(){

	Node *head = NULL;

	// append_elegant(&head, 1);
	push_front(&head, 10);
	append_elegant(&head, 15);
	append_elegant(&head, 20);
	int length = list_length(head);
	print_list(head);

	reverse_list(&head);
	print_list(head);
	Node *found = find_node(head, 20);


	FILE *f ; 
	printf("find node ptr %p --- should be the same as head: %p \n",found, head);
	Int i = fprintf(*buffer,"hola");
	print_list(head);
	return 0;
}





/* 
reverse_list	Invertir completamente el orden de los nodos de la lista.
find_node	Buscar un valor y devolver el nodo que lo contiene.
get_middle	Encontrar el nodo central de la lista y devolver su valor.
clear_list	Eliminar todos los nodos y liberar toda la memoria.
copy_list	Crear una copia independiente de una lista existente.
*/

void reverse_list(Node **head){
	Node *prev= NULL; 
	Node *curr = *head;

	while (curr != NULL) {
		Node *tmpNext = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmpNext;

	
	}

	*head = prev; 
}


Node *find_node(Node *head, int value){
	printf("netrando a find node \n");
	while (head!=NULL) {
		if (head->value == value){
			return head;
		}
		head = head->next;
	}

	printf("value: %d not found \n", value);
	fprintf();
	return NULL;

}


Node get_middle(){

}


/* 
 * como calculamos el punto medio de una lista?.  1 2 3.     final +1 / 2 ? 
 *  1 2 3 4  la mitad es 2. pero aca el punto medio cual seria
 *
 * */


































Node *create_node(int value){
	Node *nodeptr = malloc(sizeof(Node));
	if (nodeptr ==NULL){
		printf("Malloc failed for value %d \n", value);
	}
	nodeptr->value=value;
	nodeptr->next=NULL;
	return nodeptr;
}

//porque pasar un puntero, que apunta head?, no podriamos mas facil pasar nada mas un el puntero a head?
void append_not_elegant(Node **head, int data){
	Node *newNodePtr = create_node(data);
	if (*head == NULL){
		*head = newNodePtr;
		return;
	}

	Node *curr = *head;
	while (curr->next != NULL){
		curr = curr->next;
	}
	curr->next = newNodePtr;
}

void append_elegant(Node **head, int data){
	// 0x1234 
	Node **trace = head;

	while (*trace != NULL) {
		//trace deberia ser igual a head
		//
		 // &(*trace)->next  va a ser un **puntero a el siguente nodo. que vale por ejmeplo 0x400;
		trace = &(*trace)->next;
	}

	//trace vale antes 0x1234, el valor del final
	//trace vale ahora 0x1234, el valor del final
	*trace = create_node(data);
}

void print_list(Node *head){
	printf("{");
	while(head!=NULL){
		printf(" %d ", head->value);
		head = head->next;
	}
	printf("} \n");
}

int list_length(Node *head){
	int i = 0;
	while(head!=NULL){
		i++;
		head = head->next;

	}
	return i;

}

void free_list(Node **head){
	Node *currPtr = *head;
	while (currPtr!=NULL) {
		Node *shouldBeFreed = currPtr;
		currPtr = currPtr->next;
		free(shouldBeFreed);
	}
	*head = NULL;

	return;
}







//ejercicio 2

void push_front(Node **head, int value){
	//tomar el nodo que esta en la head
	Node *newnodePtr = create_node(value);

	newnodePtr->next = *head;
	*head = newnodePtr;

}


int insert_at_not_elegant(Node **head, int index, int value){
	//invalid index
	if (index<0){
		return -1;
	}

	if (index==0){
		push_front(head, value);
		return 0;
	}

	if (*head==NULL){
		printf("list is empty, and trying to update an index >=1 ");
		return -1;
	}

	//we already checked for inserting at the start with index=0 (and there we update the head)
	Node *prev = *head;   
	Node *curr = (*head)->next;


	for (int i=1; i<index; i++){
		//avoid this invalid index when is bigger than the size, witohtu traversing the hwole array
		if (curr == NULL){
			return -1;
		}

		prev = curr;
		curr = curr->next;
		

	}


	Node *newnodePtr = create_node(value);
	prev->next = newnodePtr;
	newnodePtr->next = curr;
	return 0;
}



int insert_at(Node **head, int index, int value){

	if (index<0 || *head==NULL){
		printf("invalid index, or null head \n");
	}


	Node **trace = head;

	int i=0;
	while (*trace!=NULL && i<=index) {
		i++;
		trace = &(*trace)->next;

	}

	if (i!=index){
		printf("no valid index;");
		return -1;
	}

	Node *tmp = *trace;
	*trace = create_node(value);
	(*trace)->next = tmp;
	return 0;


}


void delete_value_elegant(Node **head, int value){

	//x1234
	Node **trace = head;

	//*trace apunta a x100


	while ((*trace)!= NULL) {
		if ((*trace)->value == value) {
			//x100
			Node *toFree = *trace;

			//prev was pointing to *trace, so we just update it to the next which is 0x200

			//now **trace value is still x1234 
			//now **head is also value is still x1234 
			//If we update *trace, we only update the value inside, so head will also be updated in this first case
			*trace = (*trace)->next;
			
			free(toFree);


		
		}
	
		//if we are deleting a differnet node than the first one, we just update the **trace, so that it does not modify the HEAD
		trace = &(*trace)->next;
	}


}

void delete_at(Node **head, int index){
	if (index<0){
		printf("invalid index should be >=0 \n");
		return;
	}

	if (*head==NULL){
		printf("head is null, the list is empty");
		return;
	}


	Node **trace = head;

	for (int i=0; i<index; i++) {
		if ((*trace)==NULL) {
			return;
		}

		trace = &(*trace)->next;
		//etto de abajo modificaria la head al sugiente y sigiuetne y asi sucesiamet no?
		// *trace = (*trace)->next;
	}

	Node *toDelete = *trace;
	*trace = (*trace)->next;
	free(toDelete);
	}

// push_front	Insertar un nuevo nodo al principio de la lista.
// insert_at	Insertar un nuevo nodo en una posición específica (índice) de la lista.
// delete_value	Buscar un valor y eliminar el primer nodo que lo contenga.
// delete_at	Eliminar el nodo que se encuentre en un índice específico.
