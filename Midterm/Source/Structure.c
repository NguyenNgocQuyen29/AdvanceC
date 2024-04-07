/*
* File: Structute.h
* Author: Nguyen Thi Ngoc Quyen
* Date: 04/04/2024
* This file contains function of all function information management
*/
#include "../Header/Structure.h"

/* 
* Function: createMemberNode
* Description: create the new node which has datatype is MemberNode
* Input:
*	member - a Member datatype - used to store data of every member
* Output:
*	return a pointer that store the address of the newly created node
*/
MemberNode* createMemberNode(Member member) {
	MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
	newNode->data = member;
	newNode->next = NULL;
	return newNode;
}
/*
* Function: createMember
* Description: add the new node at the first position of the linked list
* Input: 
*   list - pointer to pointer has datatype is node - address of pointer array which pointer to first node of linked list
*   member - a Member datatype - data
* Output:
*   new list with a new node at the beginning
*/
void createMember(MemberNode** list, Member member) {
    MemberNode* newNode = createMemberNode(member);
    newNode->next = (*list);
    (*list) = newNode;
}
/*
* Function: sizeApartment
* Description: number resident in apartment
* Input:
*	list - a Member datatype - address of list
* Output:
*	return size of apartment
*/
int sizeApartment(MemberNode* list){
    int count = 0;
    MemberNode* ptr = list;
    while(ptr->next != NULL){
        ptr = ptr->next;
        ++count;
    }
    return count;
}
/*
* Function: enterDataNewMember
* Description: enter information of the new member including UID, roomNumber, name, licensePlate
* Input:
*	member - an Member datatype - store data of each member
* Output:
*	return information of the newly added member
*/
Member* enterDataNewMember() {
    Member* member = (Member*)malloc(sizeof(Member));

    printf("Enter the new information of resident");
    printf("Enter UID: \n");
    fflush(stdin);
    scanf(" %s ", member->uid);

    printf("Enter roomNumber: \n");
    fflush(stdin);
    scanf(" %s ", member->roomNumber);

    printf("Enter name: \n");
    fflush(stdin);
    scanf(" %s ", member->name);

    printf("Enter licensePlate: \n");
    fflush(stdin);
    scanf(" %s ", member->licensePlate);

    //save data into number variable
    return member;
}
/*
* Function: addMember
* Description: add the new member at the last list
* Input:
*	list - pointer to pointer has datatype is memberNode - address of pointer array which point to first node of the linked list
*	member - a Member datatype - data of member
* Output
*	The new list with the new member at the last list
*/
void addMember(MemberNode** list){
    Member* newMember = enterDataNewMember();
    MemberNode* newNode = createMemberNode(*newMember);  //newMember is pointer ,need to pass value
    MemberNode* ptr = *list;

    if(*list = NULL){ //if list empty , node becomes the first of list
        *list = newNode;
    }else{
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode; //assgine next the last node by address of the newly created node
    }
}
/*
* Function: deleteMember
* Description: detele member information based on UID from CSV file.
* Input:
*   list - pointer to pointer has datatype is MemberNode - address of pointer array which point to first node of the linked list
* Output:
*   The new list with the update member list.
*/
void deleteMember(MemberNode* list){ //uid:pos
    MemberNode* ptr = list;
    MemberNode* temp;
    int uid = 0;
    int count = 0;
    printf("Nhập id"); 
    fflush(stdin); 
    scanf("%d", &uid);

    if(count < uid - 1){
        printf("No resident to delete");
    }
    //move to the uid previous node
    while((ptr != NULL) && (count < uid - 1)){
        ptr = ptr->next;
        ++count;
    } 
    temp = ptr->next;
    ptr->next = ptr->next->next; //p->next: next of the previous node, p->next->next: address of the next node
    free(temp);
}
/*
* Function: editMember
* Desription: update member information based on UID in CSV file
* Input:
*   list - pointer to pointer has datatype is MemberNode - address of pointer array which point to first node of the linked list
*   uid - a char datatype - uid of member need to modify
* Output:
*   updated CSV file with the modified information
*/
void editMember(MemberNode** list, char* uid){
    MemberNode* cur = *list;

    //check list empty or not
    if(cur = NULL){
        printf("Not found\n");
        return;
    }
    while(cur != NULL){
        //compare uid with uid in list
        if(strcmp(cur->data.uid, uid) == 0){
            //requied user enter the new information for member
            Member* newEdit = enterDataNewMember();

            //after have information need to edit, we updated information with old information
            strcpy(cur->data.roomNumber, newEdit->roomNumber);
            strcpy(cur->data.name, newEdit->name);
            strcpy(cur->data.licensePlate, newEdit->licensePlate);

            free(newEdit);
        }
    }
}
//viết hàm tìm kiếm bằng uid và biển số xe xong rồi switch case
/*
* Function: getInfo
* Description: print data about resident infomation 
* Input:
    member - a Member datatype 
* Output:
*   information of each member
*/
void getInfo(Member* member) {
    printf("UID: %s\n", member->uid);
    printf("Room Number: %s\n", member->roomNumber);
    printf("Name: %s\n", member->name);
    printf("License Plate: %s\n", member->licensePlate);
    printf("__________________________________________\n");
}
/*
* Function: searchByUID
* Description: Search member by UID number in the given file.
* Input:
*   list 
*   uid: 
* Output: 
*   return information of resident according to UID corresponding
*/
void searchByUID(MemberNode* list, char* uid) {
    MemberNode* ptr = list;
    while (ptr != NULL) {
        if (strcmp(ptr->data.uid, uid) == 0) {
            getInfo(&(ptr->data));
            return;
        }
        ptr = ptr->next;
    }
    printf("Member with UID %s not found.\n", uid);
}
/*
* Function: searchByLicensePlate
* Description: Search member by LicensePlate in the given file.
* Input:
*   list 
*   licensePlate: 
* Output: 
*   return information of resident according to licensePlate corresponding
*/
void searchByLicensePlate(MemberNode* list, char* licensePlate) {
    MemberNode* ptr = list;
    while (ptr != NULL) {
        if (strcmp(ptr->data.licensePlate, licensePlate) == 0) {
            getInfo(&(ptr->data));
            return;
        }
        ptr = ptr->next;
    }
    printf("Member with License Plate %s not found.\n", licensePlate);
}

void searchMember(MemberNode* list){
    int searchFunc;
    char searchValue[20];
    printf("Enter the method you want to find \n");
    printf("1. Search by UID \n");
    printf("2. Search by licensePlate \n");
    scanf("%d", &searchFunc);

    if(searchFunc == 1){
        printf("Enter UID: ");
        fflush(stdin);
        scanf("%s", searchValue);
        searchByUID(list, searchValue);
    }else if (searchFunc == 2) {
        printf("Enter LicensePlate: ");
        fflush(stdin);
        scanf("%s", searchValue);
        searchByLicensePlate(list, searchValue);
    } else {
        printf("Chọn lại đi\n");
    }
}
