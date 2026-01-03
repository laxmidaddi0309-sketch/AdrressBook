#include <stdio.h>
#include "contact.h"
#include<string.h>
#include<ctype.h>
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"
/* Function definitions */
// void init_intitalization(AddressBook *addressbook)
// {
// }
//--------------------validating the name-------
int valid_name(char* name)
{
    int i=0;
    int len=strlen(name);
    while(name[i]!='\0')
    {
    if(isalpha(name[i])||(name[i]==' '))
    {
        i++;
    }
    else
    {
        //printf(RED "Error: Something went wrong!\n" RESET);
        printf( RED "name should contain only alphabets and spaces ! please try again\n" RESET);
        return 0;
    }
}
    if(len==i)
    {
        return 1;
    }
    

}

//----------------- validating the Mobile Number------------
int valid_number(char* mob,AddressBook *addressbook)
{
    //-----------------checking phone number contain 10 digits or not--------
    int len=strlen(mob);
        for (int i = 0; i < len; i++)
         {
            
                if (!(isdigit(mob[i]))) 
                {
                printf(RED "Mobile number should contain only numbers! Please try again\n" RESET);
                return 0;
                }
        }
        //-------------checking phone number is unique or not------
        for(int i=0;i<addressbook->contact_count;i++)
        {
        if(strcmp(mob,addressbook->contact_details[i].Mobile_number)==0)
         {
            printf(RED "phone number should be unique!\n" RESET);
            return 0;
         }
        }
         //---------------checking phone number start from 6-9------
        if (!(mob[0] >= '6' && mob[0] <= '9'))
                {
                printf( RED "Mobile numebr should start from (6-9)! please try again\n" RESET);
                return 0;
             }
        
        if(len==10)
               return 1;
        else
        {
            printf( RED "Mobile Number contain 10 digits !please try again\n" RESET);
            return 0;
        }
}

//---------------------validating the Mail ID--------------
 int valid_emailid(char* email,AddressBook *addressbook)
 {
    //email should contain only lowercase alphabet:
       int m=0;
    while(email[m]!='\0')
    {
    if(email[m]>='A' && email[m]<='Z')
    {
        printf(RED "Email must contain lowercase or digits! please try again\n" RESET);
        return 0;
    }
    m++;
    }
    // Before '@' Mail must atleast 2 characters
    for(int i=0;i<2;i++)
    {
        if(email[i]=='@')
        {
            printf(RED "Before @ Email must contain atleast 2 character\n" RESET);
            return 0;
        }
    }
    // Email id contain only one '@'not more than one '@'
    int i=0,count=0;
    while(email[i]!='\0')
    {
        if(email[i]=='@')
        {
            count++;
        }
        i++;
    }
    if(count!=1)
    {
        printf( RED "Email contain only one '@' try again\n" RESET);
        return 0;
    }

    // Dot is not in last position
    int len=strlen(email);
    if(email[len-1]=='.')
    {
        printf(RED "In Mail DOt is not valid for last position\n" RESET);
        return 0;
    }

    // domain name should come between '@ 'nad '.'
    int l=0,count2=0,found=0,valid=0;
    while(email[l]!='\0')
    {
        if(email[l]=='@') 
        {
        found=1; 
        }
      else if(found==1)
        {
            if(email[l]=='.')
            {
                if(count2>=4)
                {
                valid=1;
                }
            }
         count2++;
        }
        l++;
    }
    if(valid==0)
    {
        printf( RED "In Email domain must between  @ and '.'\n" RESET);
        return 0;
    }

    //checking there is dot ofter or before '@'.
    int j;
    for(j=0;email[j]!='\0';j++)
    {
        if(email[j]=='@')
            break;
    }
    if(email[j-1]=='.' || email[j+1]=='.')
    {
        printf(RED "DOT position is invalid\n" RESET);
        return 0;
    }
    // ofter @ only one dot
    int dotcount=0;
    for(int i=j+1;email[i]!='\0';i++)
    {
        if(email[i]=='.')
        {
           dotcount++;
        }
    }
    if (dotcount != 1) {
    printf(RED "after '@' mail should contain only one Dot\n" RESET);
    return 0;
    }

    // checking the before @ alphabets characters are there or not
    int count3=0;
    for(int i=0;i<j;i++)
    {
        if(islower(email[i]))
        {
            count3++;
        }
    }
    if(count3==0)
    {
        printf(RED "Invalid Email please try again\n" RESET);
        return 0;
    }

    // checking if Mail contain any space or not
    int k=0;
    while(email[k]!='\0')
    {
        if(email[k]==' ')
        {
        printf(RED "Email should not contain spaces!\n" RESET);
        return 0;
        }
        k++;
    }

 //checking email_id is repeat or not
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(email,addressbook->contact_details[i].Mail_ID)==0)
         {
            printf(RED "Email_ID already exist! please try another mail_id\n" RESET);
            return 0;
         }
    }
        //.com checking
        char str[20]=".com";
        if(strstr(email,str)==NULL)
        {
        printf(RED "Mail should contain .com\n"RESET);
        return 0;
        }

    return 1;
}

 //----------------------creating contacts------------   
int create_contact(AddressBook *addressbook)
{
    //addressbook->contact_count;
char name[20];
char mob[10];
char email[20];
int choose;
    
while(1)
{
    label:
    printf("Enter the name:");
    scanf(" %[^\n]",name);
    int result=valid_name(name);
    if(result==1)
    {
        strcpy(addressbook->contact_details[addressbook->contact_count].Name,name);
    }
    else
    goto label;

        label1:printf("Enter the mobile number:");
        scanf(" %s",mob);
        int result1=valid_number(mob,addressbook);
        if(result1==1)
            strcpy(addressbook->contact_details[addressbook->contact_count].Mobile_number,mob);
        else
        goto label1;

       label2: printf("Enter the email id:");
        scanf(" %s",email);
        int result2=valid_emailid(email,addressbook);
        if(result2 ==1)
            strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID,email);
        else
        goto label2;

    addressbook->contact_count++;
    printf(GREEN "Contact added successfully\n" RESET);
    printf(YELLOW "Do you want to enetr the another name:yes(1)/No(0)" RESET);
    scanf("%d",&choose);

    
    if(choose==0)
    {
        break;
    }
}
    return 0;
}
    

void list_contacts(AddressBook *addressbook)
{
    if(addressbook->contact_count>0)
    {
    for(int i=0;i<addressbook->contact_count;i++)
    {
        printf("------------------------------------\n");
        printf(BLUE "name:%s\nmobilenumber:%s\nemail id:%s\n"RESET,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
        printf("-------------------------------------\n");
    }
}
else
{
    printf(RED "No contacts available\n"RESET);
}
}

//-------------------searching contacts-------------
int search_contacts(AddressBook *addressbook)
{
    int choose;
    int found=0;
    int i,j,count;
    count=0;
    int arr[10];
    char name[20];
    char mob[11];
    char email[30];
    int choose1=1;
    printf( BLUE "Do you want \n1.search by name\n2.search by mobilenumber\n3.search by emailid\n" RESET);
    scanf("%d",&choose);
    switch(choose)
    {
        case 1:
        printf("Enter the name:");
        scanf(" %[^\n]",name);
        for(i=0;i<addressbook->contact_count;i++)
        {
           if(strcmp(addressbook->contact_details[i].Name,name)==0)
            {
                printf(BLUE "%s %s %s\n"RESET,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
                arr[count]=i;
                count++;
            }
        }
    
        int choose1;
        if(count>1)
            {
               printf(BLUE "There are %d contacts with the same name\nWhich field Do you want to search \n1.phone number\n2.email id\n" RESET,count);
               scanf("%d",&choose1);
               switch(choose1)
               {
                case 1:
                printf("Enter the phone number:");
                scanf(" %s",mob);
                for(j=0;j<count;j++)
                {
                    if(strcmp(addressbook->contact_details[arr[j]].Mobile_number,mob)==0)
                    {
                        found=1;
                        printf(GREEN "Contact found\n" RESET);
                        printf(BLUE "%s %s %s\n" RESET,addressbook->contact_details[arr[j]].Name,addressbook->contact_details[arr[j]].Mobile_number,addressbook->contact_details[arr[j]].Mail_ID);
                        return arr[j];
                    }
                }
                break;
                case 2:
                printf("Enter the Email id:");
                scanf(" %s",email);
                for(j=0;j<count;j++)
                {
                    if(strcmp(addressbook->contact_details[arr[j]].Mail_ID,email)==0)
                    {
                        found=1;
                         printf(GREEN "Contact found\n" RESET);
                        printf(BLUE "%s-%s-%s\n"RESET,addressbook->contact_details[arr[j]].Name,addressbook->contact_details[arr[j]].Mobile_number,addressbook->contact_details[arr[j]].Mail_ID);
                        return arr[j];
                    }
                }
                break; 
                }
            }
            else if(count==1){
                 printf(GREEN "Contact found\n" RESET);
                return arr[0];
            }
        
    if(!found)
    {
        printf(RED "contact not found\n" RESET);
    }
    break;
    case 2:
          printf("Enter the mobile number:");
          scanf(" %[^\n]",mob);

        for(i=0;i<addressbook->contact_count;i++)
        {
            if(strcmp(addressbook->contact_details[i].Mobile_number,mob)==0)
            {
                printf(GREEN "Contact found\n" RESET);
                printf(BLUE "%s %s %s"RESET,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);

                found=1;
                return i;
                break;

            }
                
        }
    if(!found)
    {
     printf(RED "contact not found\n" RESET);
    
    }
    break;
    case 3:
        printf("Enter the email:");
        scanf(" %[^\n]",email);
        for(i=0;i<addressbook->contact_count;i++)
        {
            if(strcmp(addressbook->contact_details[i].Mail_ID,email)==0)
            {
                printf(GREEN "Contact found\n" RESET);
                printf(BLUE "%s %s %s"RESET,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);

                found=1;
                return i;
                break;

            }
                
        }
    if(!found)
    {
     printf(RED "contact not found\n" RESET);
   }
    
    break;
   

    
}
}

//---------------edit contacts----------
int edit_contact(AddressBook *addressbook)
{
    int search_contacts(AddressBook* );
    int result=search_contacts(addressbook);
    int choose;
   if(result>=0 && result<=addressbook->contact_count)
   {
    printf(BLUE "Which field do you want to edit\n1.name\n2.mobile number\n3.email address\n4.editing all information"RESET);
    scanf("%d",&choose);
    switch(choose)
    {
        case 1:
        char Name1[30];
        label: printf("Enter the name:");
        scanf(" %[^\n]",Name1);
        int result1=valid_name(Name1);
        if(result1==1)
        {
        strcpy(addressbook->contact_details[result].Name,Name1);
        printf(GREEN "Editing Successfully\n" RESET);
        }
        else
        goto label;
        break;
       
        case 2:
        char Mobile_number1[11];
       label1: printf("Enter the mobile number:");
        scanf(" %s",Mobile_number1);
        int result2=valid_number(Mobile_number1,addressbook);
        if(result2==1){
        strcpy(addressbook->contact_details[result].Mobile_number,Mobile_number1);
        printf(GREEN "Editing Successfully\n" RESET);
        }
        else
        goto label1;
        break;
        
        case 3:
        char Mail_ID1[30];
        label2: printf("Enter the email id:");
        scanf(" %s",Mail_ID1);
        int result3=valid_emailid(Mail_ID1,addressbook);
        if(result3==1){
        strcpy(addressbook->contact_details[result].Mail_ID,Mail_ID1);
        printf(GREEN "Editing Successfully\n" RESET);
        }
        else
        goto label2;
        break;

        case 4:
            label3: char name[20]; 
                    printf("Enter the name:");
                    scanf(" %[^\n]",name);
                    int result4=valid_name(name);
                    if(result4==1)
                    {
                        strcpy(addressbook->contact_details[result].Name,name);
                    }
                    else
                    goto label3;

                    label4: char mob[11];
                            printf("Enter the mobile number:");
                            scanf(" %s",mob);
                            int result5=valid_number(mob,addressbook);
                            if(result5==1)
                            strcpy(addressbook->contact_details[result].Mobile_number,mob);
                             else
                            goto label4;

                     label5:char email[30];
                            printf("Enter the email id:");
                            scanf(" %s",email);
                            int result6=valid_emailid(email,addressbook);
                            if(result6==1)
                            strcpy(addressbook->contact_details[result].Mail_ID,email);
                            else
                            goto label5;
                         printf(GREEN "Editing Successfully\n" RESET);
                            break;
                          
    }
}
    return 0;
}
// --------------------deleting the contacts------------
int delete_contact(AddressBook *addressbook)
{
     int search_contacts(AddressBook *);
   int result=search_contacts(addressbook);
   if(result==-1)
   {
    return 0;
   }
   if(result>=0 && result<addressbook->contact_count)
   {
   int choose;
            printf( YELLOW "\nDo you want to delete contact\n1.yes\n0.No\n" RESET);
            scanf("%d",&choose);
   if(choose==1)
        {
            addressbook->contact_count--;
            for(int j=result;j<addressbook->contact_count;j++)
            {
                 addressbook->contact_details[j]= addressbook->contact_details[j+1];
            }
        }
    return 0;
}
}
//-----------------saving contacts--------------
int save_contacts(AddressBook *addressbook)
{
    FILE* fptr=fopen("data.txt","w");
    if(fptr==NULL)
    {
        printf("file not found\n");
        return 0;
    }
    Contacts temp;
    for(int i = 0; i < addressbook->contact_count - 1; i++)
    {
        for(int j = 0; j < addressbook->contact_count - i - 1; j++)
        {
            if(strcasecmp(addressbook->contact_details[j].Name,addressbook->contact_details[j + 1].Name) > 0)
            {
                temp = addressbook->contact_details[j];
                addressbook->contact_details[j] = addressbook->contact_details[j + 1];
                addressbook->contact_details[j + 1] = temp;
            }
        }
    }
    //-----writing the all data into file-----
    fprintf(fptr,"#%d\n",addressbook->contact_count);
    for(int i=0;i<addressbook->contact_count;i++)
    {
        fprintf(fptr,"%s,%s,%s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
    }
    fclose(fptr);
   
    return 0;
}