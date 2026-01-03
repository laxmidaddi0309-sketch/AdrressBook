/*Name:Laxmi B Daddi
Project Name:AddressBook
Date of Submission:7/12/2025
Discription of project:In AddressBokk project there are 7 functions:
1.create contact:
Adds a new contact to the address book and Collects details such as name, mobile number, and email ID, validates them, and stores the contact in the address book structure.
Validate each field (name, mobile, email) and Insert the new contact into the next available index.Update total contact count
2.search contact:
Searches for existing contacts based on a user-selected Name,mobile number,mail ID.
3.edit contact:
Edits an existing contacts and Search for the contact and Display old details and Validate new user input and User can choose what to edit: name, mobile number, or email ID.
4.delete contact:
Deletes an existing contact and first we search for the contact and Remove it by shifting remaining contacts up by one index and decrement total count.
5.display contact:
display the stored contact Loop through the contact array and Print each contact’s details in a formatted manner.
6.saving contact:
Saves the entire contact list to a file 
7.loading contacts:
Loads existing contacts from a file into memory when the program starts.*//
#include <stdio.h>
#include "contact.h"
#include<string.h>
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"
/* Structure declaration */

int main()
{
    /* Variable and structre defintion */
    int option;
    AddressBook addressbook;
    addressbook.contact_count = 0;

    // init_intitalization(&addressbook);
    //--------------reading the data from file------
    FILE* fptr=fopen("data.txt","r");
    if(fptr==NULL)
    {
        printf("File is not avilable\n");
    }
    else
    printf("File is available\n");
    rewind(fptr);
    fscanf(fptr,"#%d\n",&addressbook.contact_count);
    for(int i=0;i<addressbook.contact_count;i++)
        {
            fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressbook.contact_details[i].Name,addressbook.contact_details[i].Mobile_number,addressbook.contact_details[i].Mail_ID);
        }
    fclose(fptr);
    Contacts temp;
    for(int i = 0; i < addressbook.contact_count - 1; i++)
    {
        for(int j = 0; j < addressbook.contact_count - i - 1; j++)
        {
            if(strcasecmp(addressbook.contact_details[j].Name,addressbook.contact_details[j + 1].Name) > 0)
            {
                temp = addressbook.contact_details[j];
                addressbook.contact_details[j] = addressbook.contact_details[j + 1];
                addressbook.contact_details[j + 1] = temp;
            }
        }
    }


    while (1)
    {
        printf("\nAddress book menu\n"); /* Give a prompt message for a user */
        printf("1.Add contact\n2.search contact\n3.Edit contact\n4.Delete contact\n5.Display contact\n6.Save contact\n7.Exit\n");
        printf("Enter the option : ");
        scanf("%d", &option);

        switch (option) /* Based on choosed option */
        {
        case 1:
        {
            create_contact(&addressbook);
            break;
        }

        case 2:
        {
            
            //printf("Search Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4. Exit\nEnter the option : "); /* Providing menu */
            int choose1=1;
            while(choose1)
            {
            search_contacts(&addressbook);
            printf(YELLOW "\nDo you want continue\n1.yes\n0.No\n" RESET);
            scanf("%d",&choose1);
            }
            break;
        }
        case 3:
            //printf("Edit Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */
            int choose1=1;
            while(choose1)
            {
            edit_contact(&addressbook);
            printf(YELLOW "Do you want continue\n1.yes\n0.No\n"RESET);
            scanf("%d",&choose1);
            }
           break;

        case 4:
        {
            printf("Delete Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */
            int choose1=1;
             while(choose1)
            {
                delete_contact(&addressbook);
                printf(GREEN "Delete Successfully\n" RESET);
                printf(YELLOW "Do you want continue\n1.yes\n0.No\n" RESET);
                scanf("%d",&choose1);
            }
           break;
        }
        case 5:
        {
            printf("List Contacts:\n");
            list_contacts(&addressbook);
            break;
        }

        case 6:
            printf(GREEN "Saving contacts\n" RESET);
            save_contacts(&addressbook);
            break;

        case 7:
            printf(GREEN "INFO : Save and Exit...\n" RESET);
            save_contacts(&addressbook);
             return 0;

        default:
            printf(RED "Invalid option \n" RESET);
            break;
        }
    }
    return 0;
}
