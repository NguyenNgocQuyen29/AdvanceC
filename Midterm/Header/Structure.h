/*
* File: Structute.h
* Author: Nguyen Thi Ngoc Quyen
* Date: 04/04/2024
* This file contains original function of all function information management
*/
#ifndef __STRUCTURE_H_
#define __STRUCTURE_H_

//#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Struct: Member
* Description: This struct contains information of a resident in apartment such as Uid, roomNumber, name, licensePlate
*/
typedef struct {
	char uid[20];    //uid của Rfid
	char roomNumber[10];
	char name[50];
	char licensePlate[20];
}Member;
/*
* Struct: MemberNode
* Description: This struct is node in linked list that value of it to contain bassic information of a resident 
*/
typedef struct MemberNode{
	Member data;
	struct MemberNode* next;
}MemberNode;

MemberNode* createMemberNode(Member member);
Member* enterDataNewMember();
int sizeApartment(MemberNode* list);
void addMember(MemberNode** list);
void createMember(MemberNode** list, Member member);
void deleteMember(MemberNode** list, char* uid);
void editMember(MemberNode** list, char* uid);
void getInfo(Member* member);
void searchByUID(MemberNode* list, char* uid);
void searchByLicensePlate(MemberNode* list, char* licensePlate);
void searchMember(MemberNode* list);


#endif 
