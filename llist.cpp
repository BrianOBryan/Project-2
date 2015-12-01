/*

NAME: Brian Mayeshiro
HW: Project 2
CLASS: ICS212
INSTRUCTOR: RAVI NARAYAN
FILE: llist.cpp
DESCRIPTION: MY DATABASE OF FUNCTIONS TO BE USED FOR THE USER INTERFACE FOR PROJECT 2.

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
#include "record.h"
#include "llist.h"

/*
Function name: llist
Description: The llist constructor.
Parameters: none
Return values: none
*/

llist::llist()
{
    this->start = NULL;
    strcpy(filename, "readtest.txt");
    readfile();
}

/*
Function name: llist
Description: The llist constructor with a filename parameter.
Parameters: filetoread[] (char) the file being read with info to put into llist  
Return values: none
*/

llist::llist(char filetoread[])
{
    this->start = NULL;
    strcpy(filename, filetoread);
    readfile();
}

/*
Function name: llist
Description: The llist destructor.
Parameters: none  
Return values: none
*/

llist::~llist()
{
    writefile();
    cleanup();
}

/*
Function name: reverse
Description: reverses the whole llist (start becomes the last node in linked list)
Parameters: none
Return Values: void
*/

void llist::reverse()
{
    reverse(start);
}

/*

Function name: reverse 
Description: helps recursively reverse the singly linked list
Parameters: ptr (struct*) the current record
Return Values: record

*/

record* llist::reverse(record *curr)
{    
    if(curr->next == NULL)
    {
        start = curr;
    }
    else
    {
        reverse(curr->next);
        curr->next->next = curr;
        curr->next = NULL;
    }    
    return curr;
}

/*
Function name: ostream&
Description: Overloaded operator, like printall
Paramaters: ostream &stream: the output stream
            llist &list: list being printed
Return values: none
*/

ostream& operator<<(ostream &stream, const llist &list)
{
    struct record *temp;    
    temp = list.start;
        
    if(temp == NULL)
    {
         stream << "The list is empty, nothing to print" << endl;
    }
    else
    {
        while(temp != NULL)
        {   
            stream << "Record Name: " << temp->name << endl;
            stream << "year of birth: " << temp->yearofbirth << endl;
            stream << "Address: " << temp->address << endl;
            stream << "Telno: " << temp->telno << "\n" << endl;

            temp = temp->next;
        }   
    }
}

/*

Function name: addRecord
Description: A database function that adds a new record to the end of a singly linked list of records.
Parameters: uname[] (char): the name to be added for the new record
            uaddr[] (char): the address to be added for the new record
            uyob (int): the year of birth to be added for the new record
            utelno[] (char): the telephone number to be added for the new record

Return values: 0 for a sucessful return
               -1 for an unsucessful return (failed to allocate space for new record)

*/
           
int llist::addRecord(char uname[], char uaddr[], int uyob, char utelno[])
{
    struct record *temp;
    struct record *newRecord;
    int retVal = 0;
    
    temp = start;
    
    newRecord = new record;

    strncpy(newRecord->name, uname, 25);
    strncpy(newRecord->address, uaddr, 80);
    strncpy(newRecord->telno, utelno, 15);
   
    newRecord->yearofbirth = uyob;
    newRecord->next = NULL;

    /*checking if list is empty*/

    if(start == NULL)
    {
        /*setting the newRecord as the start */

        start = newRecord;
        temp = newRecord;
    
        retVal = 0;
    }
    else
    {
        temp = start;
        
            while(temp->next != NULL)
            {
                temp = temp->next;                
            }
            
        temp->next = newRecord;
        
        retVal = 0;
    }

    return retVal;
}

/*  
    
Function name: deleteRecord
Description: A database function that deletes all records with a given name in singly linked list of records.
Parameters: uname[] (char): the name being searched for deletion.

Return values: 1 if name not found
               0 for a sucessful deletion
               -1 if list is empty
*/

int llist::deleteRecord(char uname[])
{
    int retVal = 1;
    struct record *temp;
    struct record *previous;
    
    previous = NULL;
    temp = start;
    
    if(temp == NULL)
    {
        retVal = -1;
    }
    else
    {
        while(temp != NULL)
        {
            if(strcmp(temp->name, uname) == 0)
            {
                if(temp == start)
                {
                    temp = temp->next;
                    delete(start);
                    start = temp;
                }
                else
                {
                    previous->next = temp->next;
                    delete(temp);
                    temp = previous->next;
                }
                retVal = 0;
            }
            else
            {
                previous = temp;
                temp = temp->next;
            }
        }
    }

    return retVal;
}

/*
    
Function name: printRecord
Description: A database function that prints all records with a given name in singly linked list of records. 
Parameters: uname[] (char): the name(s) being searched for printing.                
Return values:  1 if name not found
                0 for a sucessful printing of record
               -1 if the list is empty
*/

int llist::printRecord(char uname[])
{
    int retVal = 1;
    struct record *temp;
            
    temp = start;
     
    /* checking if list is empty */
 
    if(temp == NULL)
    {
        retVal = -1;
    }
    
    /* traversing through list */
    
    while(temp != NULL) 
    {    
        if(strcmp(temp->name, uname) == 0)
        {
            cout << "The Record information is: \n";
            cout << "Name: " << temp->name << endl;
            cout << "Address: " << temp->address << endl;
            cout << "Yearofbirth: " << temp->yearofbirth << endl;
            cout << "Telno: " << temp->telno << "\n" << endl;
         
            retVal = 0;
        }
            temp = temp->next;  
    }
    return retVal;
}

/*             
       
Function name: modifyRecord
Description: A database function that modifies all records with a given name inputed by the user.
Parameters: 
            name[] (char): The name of the record being modified
            addr[] (char): The new address of the record
            telno[] (char): The new telelphone number for the record
Return values: 1 if record not found
               0 for successful modification
              -1 for unsucessful modification
         
*/

int llist::modifyRecord(char uname[], char uaddr[], char utelno[])
{
    int retVal = 1;
    struct record *temp;
            
    temp = start;
             
    if(temp == NULL)
    {           
        retVal = -1;
    }
  
    while(temp != NULL)
    {
    
       if(strcmp(temp->name, uname) == 0)
       {            
            strncpy(temp->name, uname, 25);
            strncpy(temp->address, uaddr, 80);
            strncpy(temp->telno, utelno, 15);
  
            retVal = 0;
       }
       temp = temp->next;   
    }
    return retVal;
}

/*
     
Function name: printAll
Description: A database function that prints all records in singly linked list of records.
Parameters: none
Return values: void 
            
*/

void llist::printAll()
{
    struct record *temp;

    temp = start;
   
    if(temp == NULL)
    {
         cout << "The list is empty, nothing to print" << endl;
         return;
    }
    while(temp != NULL)
    {
        cout << "Record Name: " << temp->name << endl;
	    cout << "year of birth: " << temp->yearofbirth << endl;
	    cout << "Address: " << temp->address << endl;
        cout << "Telno: " << temp->telno << "\n" << endl;

        temp = temp->next;
    }
}


/*
        
Function name: cleanup
Description: A database function that deletes every record in the list of records including the start.
Parameters: none
Return values: void

*/

void llist::cleanup()
{
    struct record *temp;
    struct record *toDelete;

    temp = start;

    while(temp != NULL)
    {
        if(temp == start) 
        {
            temp = temp->next;
            delete(start);
            start = temp;
        }
        else
        {   
            toDelete->next = temp->next;
            delete(temp);
            toDelete->next = temp;
        }
    }
}

/*

Function name: readfile
Description: A database function that reads a file with its given record information.
Parameters: none
Return values: 1 if file is empty
               0 for a sucessful read of the file.
               -1 if reading the file was unsucessful or it doesn't exist.    
*/

int llist::readfile()
{
    ifstream filetoread;
    char address[80], name[25], telno[15], buffer[10];
    int yearofbirth = 0, retVal = 1;
    
    filetoread.open(filename);
    
    if(filetoread.fail())
    {
        retVal = -1;
    }
    if((filetoread.peek() == ifstream::traits_type::eof()))
    {
        cout << "the file is empty" << endl;
        filetoread.close();
    }
    else
    {
        while(filetoread.getline(name,25, '\n'))
        {
            filetoread >> yearofbirth;
            filetoread.getline(address, 80, '\t');
            filetoread.getline(buffer, 10, '\n');
            filetoread.getline(telno, 15, '\n');
            addRecord(name, address, yearofbirth, telno);
            filetoread.getline(buffer, 10, '\n');
        } 
        retVal = 0;
    }     
    filetoread.close();
    
    return retVal;
	
}

/*    

FUNCTION NAME: writefile
DESCRIPTION: Can write information onto a txt file.
PARAMETERS: none
RETURN VALUES: 0: success
              -1: failure
*/

int llist::writefile()
{
    ofstream filetowrite;
    struct record *temp;
    int retVal = 0;

    filetowrite.open(filename);
  
    temp = start;

    if(!filetowrite)
    {
        retVal = -1;
    }
    else
    {     
        while(temp != NULL)
        {
            filetowrite << temp->name << "\n" << temp->yearofbirth << temp->address << "\t\n" << temp->telno << "\n\n";
            
            temp = temp->next;
        }
    }
    filetowrite.close();

    return retVal;
}
