/*

NAME: Brian Mayeshiro
 
HOMEWORK: project 2

CLASS: ICS 212

INSTRUCTOR: Ravi Narayan

DATE: November 21 2015

FILE: record.h

DESCRIPTION: This file contains the struct record which holds the information
             for the linked list in project 2

*/

#ifndef RECORD_H
#define RECORD_H
struct record
{
    char                   name[25];
    char                   address[80];
    int                    yearofbirth;
    char                   telno[15];
    struct record*    	   next;
}; /* This semicolon is important!!! */
#endif
