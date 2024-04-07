/*
* File: GUI.h
* Author: Nguyen Thi Ngoc Quyen
* Date: 06/04/2024
* This file contains original of GUI program
*/
#ifndef __GUI_H_
#define __GUI_H_


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../Header/Structure.h"

void readData(const char* fileName, MemberNode** list);
void display(const char* fileName, MemberNode** list);

#endif