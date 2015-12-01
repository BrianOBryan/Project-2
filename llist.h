/*****************************************************************
 *
 * NAME: Brian Mayeshiro
 *
 * HOMEWORK: Project 2
 *
 * CLASS: ICS 212
 *
 * INSTRUCTOR: Ravi Narayan
 *
 * DATE: November 20, 2015
 *
 * FILE: llist.h
 *
 * DESCRIPTION: This file contains the class for llist to be used in project 2
 * 
 *****************************************************************/ 

#ifndef LLIST_H
#define LLIST_H
class llist
{

  private:
    record *    start;
    char        filename[16];
    int         readfile();
    int         writefile();
    record *    reverse(record * );
    void        cleanup();

  public:
    llist();
    llist(char[]);
    ~llist();
    int addRecord(char[], char[], int, char[]);
    int printRecord(char[]);
    int modifyRecord(char[], char[], char[]);
    void printAll();
    int deleteRecord(char[]);
    void reverse();
    friend ostream& operator<<(ostream&, const llist& list);

};
#endif
