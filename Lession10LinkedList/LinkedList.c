#include <stdio.h>
#include <stdlib.h>

/*
address:  0x01    0xa3    0xb2   0xf2    0xc9
value:    1       5       4      2       9
next:     0xa3    0xb2    0xf2   0xc9    NULL
*/

typedef struct node{
    int value;
    struct node *next;
}node;
/*
* Fuction: createNode
* Description: create a node in a linked list have 2 number: value of the node and a pointer hold address of the next node
* Input:
*   value - an interger value - value of the number
* Output:
*   ptr - address of the created node
*/
node* createNode(int value){
    //cấp phát động bộ nhớ bằng với kích thước của node,malloc cấp phát động trả về con trỏ kiểu NULL nên phải ép kiểu node cho nó
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}
/*
* Function: push_back
* Description: add the new node at the last node in the linked list
* Input:
*   array - pointer to pointer has datatype is node - address of pointer array which point to first node of linked list
*   value - an integer value - value of the number
* Output:
*   The new linked list with new mode at the last position.
*/
void push_back(node **array, int value){
    node *temp, *p;
    temp = createNode(value);
    p = *array; //*array is address of the first node of the linked list
    if(*array = NULL)
    {
        *array = temp; //if array doesn't any node yet
    }else{
        while(p->next != NULL){ //the current node isn't the last node
            p = p->next; //check the next node until it is a last node
        }
        p->next = temp; //assign next of previous node equal address of the new created node
    }
}
/*
* Function: push_front
* Description: add the new node at the first position of the linked list
* Input: 
*   array - pointer to pointer has datatype is node - address of pointer array which pointer to first node of linked list
*   value - an integer value - value of the member
* Output:
*   new list with a new node at the beginning
*/
void push_front(node** array, int value){
    node* temp = createNode(value);
    if (*array == NULL){
        *array = temp;
    }else
    {
        temp->next = *array; //assign next of new created node by address of the first node , tức là đẩy node hiện tại ra đằng sau
        *array = temp; //assgin temp is first node of the linked list
    }
}
/*
* Fuction: pop_back
* Desctiption: delete the last node of the linked  list
* Input: 
*   array - pointer to pointer has datatype is node - addresss of pointer array which point to first node of the linked list
* Outpur:
*   new list with deleted node at the last linked list
*/
void pop_back(node** array){
    node *p, *temp;
    p = *array;
    int i = 0;
    while(p->next->next!=NULL){ //check next of the next node p
        p = p->next; //point to next node
        i++;
    }
    temp = p->next; //p->next is address of the last node
    p->next = NULL; //p->next is next of the previois last node.
    free(p);
}
/*
* Fuction: pop_font
* Desctiption: delete the first node of the linked  list
* Input: 
*   array - pointer to pointer has datatype is node - addresss of pointer array which point to first node of the linked list
* Outpur:
*   new list with deleted node at the first linked list
*/
void pop_front(node **array){
    node* p;
    p = *array;
    *array = p->next; //assign the address of the next node is the address of the first node
    free(p);
}
/*
* Function: int_front
* Description: return the first value of the linked list
* Input:
*   array: pointer to pointer has datatype is node - address of pointer array which point to first node of the linked list
* Output:
*   value of the first node - an integer value
*/

int front(node* array){//return the value =>needn't transmit address
    return array->value;
}
/*
* Function: int_back
* Description: return the last value of the linked list
* Input:
*   array: pointer to pointer has datatype is node - address of pointer array which point to first node of the linked list
* Output:
*   value of the last node - an integer value
*/
int back(node *array){
    while(array->next != NULL){
        array = array->next;
    }
    return array->value;
}
/*
* Function: inssert
* Description: add the new node at position you want
* Input:
*   array - pointer to pointer has datatype is node - address of pointer array which point to first node of the linked list
*   value - an integer value - value of the node
*   pos - an integer value - position of the list to add new node
* Output:
*    new list with new mode at the position input
*/
void inssert(node** array, int value, int pos){
    node *temp, *p;
    temp = createNode(value);
    p = *array;
    int i = 1;
    if(pos = 0){
        temp->next = *array;
        *array = temp;
    }
    while (p->next != NULL && pos!= i){
        p = p->next;
        i++;
    }
    temp->next = p->next; //thay null thành giá trị của next nút phía trước
    p->next = temp; //thay next của p thành địa chỉ của nút mới
}
/*
* Function: delete 
* Description: delete the node at position you want
* Input:
*   array - pointer to pointer has datatype is node - address of pointer array which point to first node of the linked list
*   pos - an integer value - position of the list to delete node
* Output:
*    new list with deleted mode at the position input
*/
void deletee(node **array, int pos){
    node* temp, *p;
    p = *array;
    int i = 1;
    while(p->next != NULL && pos != i){  //access to the previous node of the linked list 
        p = p->next;
        i++;
    }
    temp = p->next; //store the address of the node want to delete - truy cập tới phần tử trước đó để lấy địa chỉ của node muốn xóa - tại vì next của phần tử tước đó là địa chỉ cuả node muốn xóa
    p->next = p->next->next; //next of the next node
    free(temp);
}
/*
* Function: size - phần tử
* Description: return the size of the linked list
* Input:
*   array - pointer to pointer has datatype is node - address of pointer array which point to first node of the linked list
* Output:
*    value of size of the linked list
*/
int size(node **array){
    int count = 1;
    node *p = array;
    while(p->next != NULL){
        p = p->next;
        count++; //count how many node until the last
    }
    return count;
}
/*
* Function: get
* Description: return the value of the position you want
* Input:
*   array - pointer to pointer has datatype is node - address of pointer array which point to first node of the linked list
*   pos - an integer value - position of the node that you want to know its value
* Output:
*    value of the node that you want to know - an integer value
*/
int get(node **array, int pos){
    int i = 0;
    node* p = *array;
    while(p->next != NULL & pos != i){
        p = p->next;
        i++;
    }
    int value = p->value;
    return value;
}
/*
* Function: empty
* Description: check whether our list is empty or not
* Input:
*   array - pointer to pointer has datatype is node - address of pointer array which point to first node of the linked list
* Output:
*    true if our list is empty
*    false if our list isn't empty
*/
bool empty(node *array){
    if(array == NULL){
        return true;
    }else{
        return false;
    }
}