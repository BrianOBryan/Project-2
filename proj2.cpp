/*
NAME: BRIAN MAYESHIRO
HOMEWORK: PROJECT 2
CLASS: ICS212
INTRUCTOR: RAVI NARAYAN
DATE: November 21 2015
FILE: proj2.cpp
DESCRIPTION: This file contatins the main function along with the user
interface and debug mode which aids in debugging this program.
*/

#include <iostream>
#include <string>
using namespace std;
#include "record.h"
#include "llist.h"

/* prototypes */
void getfield(char[], char[], int*, char[]);
void modifyfield(char[], char[], char[]);

/*

Function name: getfield
DESCRIPTION: This function obtains the information from the user. Gets the 
Name, address, year of 
             birth, and tel number.
Parameters: name[] (char): The name being entered in from the user
            address[] (char): the address being entered in from the user
            *yobba(int pointer): integer for yearofbirth entered from user 
that modifies yearorbirth in main.
            telNumber[] (char): the telNumber being entered in from the user
Return values: void

*/

void getfield(char name[], char address[], int *yobba, char telNumber[])
{
    char yearofbirth[5];	
    char buffer[50];
    
    #ifdef DEBUG
        cout << "**DEBUG**Entering name" << endl;
    #endif

    cout << "Please enter the Name: " << endl;
    
    cin.getline(name, 25, '\n');
    
    #ifdef DEBUG
        cout << "**DEBUG**The name is: " << name << endl;
        cout << "**DEBUG**Entering yob" << endl;
    #endif

    cout << "Please enter the year of birth: " << endl;
    cin.getline(yearofbirth, 5, '\n');

    *yobba = atoi(yearofbirth);
	
    #ifdef DEBUG
        cout << "**DEBUG**the yob is: " << *yobba << "\n\n";
        cout << "**DEBUG**Entering Address" << endl;
    #endif
    
    cout << "Please Enter the address (Press TAB and ENTER when done): \n";
    cin.getline(address, 80, '\t');

    #ifdef DEBUG
        cout << "**DEBUG**The Address is: " << endl;
       
        cout << address;
        
        cout << "\n";
        cout << "**DEBUG**Entering phone number " << endl;
    #endif
    
    cout << "Please Enter the telephone number: " << endl;
    
    cin.getline(buffer, 50);
    cin.getline(telNumber, 15);

    #ifdef DEBUG
        cout << "**DEBUG**The telNumber is: " <<  telNumber << "\n" << endl;
    #endif
}

/*   
        
Function name: modifyfield
DESCRIPTION: This function obtains the information from the user. Gets the 
Name, address, and tel number for modification of the record in modifyRecord.
Parameters: name[] (char): The name being entered in from the user
            address[] (char): the address being entered in from the user
            telNumber[] (char): the telNumber being entered in from the user

Return values: void
        
*/

void modifyfield(char name[], char address[],  char telNumber[])
{
    char yearofbirth[5];
    char buffer[50];
    
    #ifdef DEBUG
        cout << "**DEBUG**Entering name" << endl;
    #endif
        
    cout << "Please enter the Name: " << endl;
        
    cin.getline(name, 25, '\n');
    
    #ifdef DEBUG
        cout << "**DEBUG**The name is: " << name << endl;
    #endif
        
    cout << "Please Enter the address (Press TAB and ENTER when done): " << endl;
    cin.getline(address, 80, '\t');
    
    #ifdef DEBUG
        cout << "**DEBUG**The Address is: ";
        
        cout << address;
    
        cout << "\n";
        cout << "**DEBUG**Entering phone number " << endl;
    #endif
        
    cout << "Please Enter the telephone number: " << endl;
    cin.getline(buffer, 50);
    cin.getline(telNumber, 15);
        
    #ifdef DEBUG
        cout << "**DEBUG**The telNumber is: " << telNumber << "\n" << endl;
    #endif   

}

/*

FUNCTION NAME: main
DESCRIPTION: My main function for the user interface, to be used by the 
user
PARAMETERS: argc (int): contains the number of arguments to be passed.
            *argv[] (char): contains the array of arguments
RETURN VALUES: void

*/

int main()
{
    
    llist mylist;

    int yearofbirth = 0;
    char name[25];
    char address[80];
    char telNumber[15];
    
    char command[20];
    int status = 0, result = 0;
    
    
    #ifdef DEBUG
        cout << "**DEBUG**Readfile was called on 'readtest.txt'\n";
    #endif
       
    cout << "Hello!\n";
    cout << "This program is a Record Database for Addresses. \n";
 
      do
      {
        
        cout << "\nPlease enter a Command: \n";
        
        cin.getline(command, sizeof(command));

        cout << "\n";
            
            if(strcmp(command, "add") == 0)
            {
                cout << "Please add an address (Include Name, Year of Birth, Address, and Phone Number): " << endl;

                getfield(name, address, &yearofbirth, telNumber);
                
                mylist.addRecord(name, address, yearofbirth, telNumber);
                
                cout << "Record has been added" << endl;
                
                #ifdef DEBUG
                    cout << "******** DEBUG ************\n";
                    cout << "**DEBUG**addRecord function was called with the parameters: \n\t" << name << " \n\t" << address << " \n\t" << yearofbirth << " \n\t" << telNumber << endl;
                    cout << "**DEBUG**The year of birth is: " << yearofbirth << endl;
                #endif
    
                cout << "\n";
            }
            else if(strcmp(command, "modify") == 0)
            {   
                cout << "Please enter the name of the record you wnat to modify: " << endl;
                
                modifyfield(name, address, telNumber);
     
                result = mylist.modifyRecord(name, address, telNumber);
                
                if(result == -1)
                {
                    cout << "The list is empty" << endl;
                }
                else if(result == 1)
                {
                    cout << "Record does not exist, nothing to modify" << endl;
                }
                else
                {
                    cout << "Record has been modified" << endl;
                }

                #ifdef DEBUG
                    cout << "******** DEBUG ************\n";
                    cout << "**DEBUG**modifyRecord function was called with the parameters: " << name << " " << address << " " << telNumber;
                #endif
                
                cout << "\n";
            }
            else if(strcmp(command, "print") == 0)
            {
                cout << "Please enter the name of the record you want to print: "; 

                cin.getline(name, sizeof(name));

                result = mylist.printRecord(name);
                
                if(result == -1)
                {
                    cout << "The list is empty " << endl;
                }
                else if(result == 1)
                {
                    cout << "Name not found" << endl;
                }
                
                #ifdef DEBUG
                    cout << "******DEBUG********\n";
                    cout << "**DEBUG**print function was called with the parameter: " << name << endl; 
                #endif
                
            }
                
            else if(strcmp(command, "printall") == 0)
            {
                cout << "Printing all information in the database..." << endl;

                cout << mylist;
                cout << endl;
                
                #ifdef DEBUG
                    cout << "******** DEBUG ************\n";
		            cout << "**DEBUG**printAllRecords was executed" << endl;
                    cout << "**DEBUG**printAllRecords function was called" << endl; 
                #endif
            }
            else if(strcmp(command, "delete") == 0)
            {
                cout << "Please enter the name of the record you would like to delete: ";
                          
                cin.getline(name, sizeof(name));

                result = mylist.deleteRecord(name);

                if(result == -1)
                {
                    cout << "List is empty, nothing to delete " << endl;
                }
                else if(result == 1)
                {
                    cout << "Name not found" << endl;
                }
                else
                {
                    cout << "Record(s) deleted" << endl;
                }
                
                #ifdef DEBUG
                    cout << "******** DEBUG ************\n"; 
                    cout << "**DEBUG**deleteRecord function was called with the parameter: " << name << endl;
                #endif
 
                cout << "\n";
            }
            else if(strcmp(command, "reverse") == 0)
            {
                #ifdef DEBUG
                    cout << "**DEBUG**" << endl;
                    cout << "**DEBUG**reversing the list" << endl;
                #endif

                mylist.reverse();
                cout << "List has been reversed" << endl;
            }
            else if(strcmp(command, "quit") == 0)
            {
                cout << "BYE! \n";
                
                #ifdef DEBUG
                    cout << "**DEBUG**writefile called" << endl; 
                    cout << "**DEBUG**Cleaning up the linked list" << endl;
                #endif                

                status = 1;
                
                #ifdef DEBUG
                    cout << "******** DEBUG ************\n";
		    cout << "**DEBUG**EXITING THE PROGRAM\n"; 
                #endif
                
            }
            else
            {
                
                cout << "Please enter an appropriate command:\n\n";
                cout << "add\n";
                cout << "print\n";
                cout << "modify\n";
                cout << "printall\n";
                cout << "delete\n";
                cout << "reverse\n";
                cout << "quit (to exit out of the program)\n\n";

            }

    }while(!status);

    #ifdef DEBUG
        cout << "**END OF DEBUG**\n";
    #endif
    
    return 0;

}
