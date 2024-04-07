/*
* File: GUI.h
* Author: Nguyen Thi Ngoc Quyen
* Date: 06/04/2024
* This file contains GUI information
*/
#include "../Header/GUI.h"

/*
* Function: readData
* Description: Each information field is separated by , Read the file and write each information field to its location
* Input:
*   fileName - name of file 
*   list - pointer to pointer......
* Output
* file readed, each information field writed into corresponding locations
*/
void readData(const char* fileName, MemberNode** list){
    char row[500]; //array to save the line from file

    FILE *file = fopen(fileName, "r"); //open the file in read mode 
    if (file == NULL) {
        printf("Cannot open file %s\n", fileName);
        return;
    }
    

    char* ptr; //pointer to save each part after separation
    while(fgets(row, 500, file) != NULL){ //feof: check current address whether is last character of the file?
    //saparate the line into part with ,
    ptr = strtok(row, ",");
    Member CurMember; //variable to save current member information
    int cnt = 0; //every line have 4 token
    while(ptr != NULL){//lặp qua các token trong 1 dòng
        ++cnt;
        switch(cnt){
            case 1: //first token
                strcpy(CurMember.uid, ptr); //write first token into uid of Memnber
                break;
            case 2: //second token
                strcpy(CurMember.roomNumber, ptr); //write secon token into roomNumber of Memnber
                break;
            case 3: //third token
                strcpy(CurMember.name, ptr); //write third token into name of Memnber
                break;
            case 4: //last token
                strcpy(CurMember.licensePlate, ptr); //write last token into licensePlate of Memnber
                break;
        }
        //continue saparate other token in line
        ptr = strtok(NULL, ",");
    }
    createMember(list, CurMember);
    }
     fclose(file); //close file after reading
}
/*
* Function: display
* Description: main GUI of program, khi executive program, it displays options for the user to select the function
* Input:
*   fileName - name of file
*   list - pointer to pointer
* Output:
*   display options for the user to select
*/

void display(const char* fileName, MemberNode** list){
    readData(fileName, list);
    int choice = 0;
    int UID;

    printf("_________List of Options_________");
    printf("1. Population numbers \n");
    printf("2. Add a new resident \n");
    printf("3. Search resident information \n");
    printf("4. Edit resident information \n");
    printf("5. Delete resident from list \n");
    printf("6. Exit program \n");

    printf("Enter your option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Number of resident : %d \n", sizeApartment(*list));
            break;
        case 2:
            printf("Enter Information want to add: \n");
            addMember(list);
            break;
        case 3:
            printf("Find resident information : \n");
            searchMember(*list);
            break;
        case 4:
            printf("Enter uid of resident want to edit : \n");
            scanf("%d", &UID);
            editMember(*list);
            break;
        case 5:
            printf("Enter uid of resident want to delete: \n");
            deleteMember(*list);
            break;
        default:
            break;
        }


    
}
