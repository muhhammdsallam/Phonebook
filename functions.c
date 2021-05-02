#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structures.h"
#include "headers.h"
void menu()
{
    char c,z,e[20];
    int found[contacts];
    fillzero(found,contacts);
    menulist();
    do
    {
        printf("\nEnter Command Code: ");
        charcheck(&c);
        printf("\n");
        if(c=='s'||c=='S')
        {
            searchlist();
            printf("\nEnter Command Code: ");
            charcheck(&z);
            Search(z,found);
            printfound(found);
        }
        else if(c=='a'||c=='A')
        {
            Add();
        }
        else if(c=='v'||c=='V')
        {
            Save();
        }
        else if(c=='d'||c=='D')
        {
            int i;
            int y;
            printf("\tSearch to delete\n\n");
            searchlist();
            printf("\nEnter Command Code: ");
            charcheck(&z);
            Search(z,found);
            printfound(found);
            while(!zerocheck(found,contacts))
            {
                if(!zerocheck(found,contacts))
                {
                    char q;
                    printf("\n\t`Research to delete:  R\t`Cancel Delete:  C\n");
                    do
                    {
                        printf("\nEnter Command Code:");
                        charcheck(&q);
                        if(q=='r'||q=='R')
                        {
                            printf("\n");
                            searchlist();
                            printf("\nEnter Command Code: ");
                            charcheck(&z);
                            Search(z,found);
                            printfound(found);
                        }
                        else if(q=='c'||q=='C')
                        {
                            printf("\n\t> Canceled Delete!\n");
                            menu();
                        }
                        else
                        {
                            q='\0';
                            printf("Error, Command code not found!\n");

                        }
                    }
                    while(!q);
                }
            }
            printf("Enter Contact Number to be deleted\n");
            printf("\n* To cancel delete please press 0 *\n");
            printf("\nContact Number:");
            gets(e);
            while(!validatenumber(e))
            {
                printf("\nPlease enter valid contact number: ");
                gets(e);
            }
            y=atoi(e);
            while((!found[y-1]||y<0||y>contacts)&&y)
            {
                printf("\n\t> Contact not included!\n");
                printf("\nPlease enter valid contact number: ");
                gets(e);
                while(!validatenumber(e))
                {
                    printf("\nPlease enter valid contact number: ");
                    gets(e);
                }
                y=atoi(e);
            }
            if(y==0)
            {
                printf("\n\t> Canceled Delete\n");
                menu();
            }
            Delete(y);
            printf("\n\t> Contact %d is successfully deleted!\n",y);
        }
        else if(c=='m' || c=='M')
        {
            int u;
            printf("\tSearch to modify\n\n");
            searchlist();
            printf("\nEnter Command Code: ");
            charcheck(&z);
            Search(z,found);
            printfound(found);
            while(!zerocheck(found,contacts))
            {
                if(!zerocheck(found,contacts))
                {
                    char q;
                    printf("\n\t`Research to modify:  R\t`Cancel modify:  C\n");
                    do
                    {
                        printf("\nEnter Command Code:");
                        charcheck(&q);
                        if(q=='r'||q=='R')
                        {
                            printf("\n");
                            searchlist();
                            printf("\nEnter Command Code: ");
                            charcheck(&z);
                            Search(z,found);
                            printfound(found);
                        }
                        else if(q=='c'||q=='C')
                        {
                            menu();
                        }
                        else
                        {
                            q='\0';
                            printf("Error, Command code not found!\n");

                        }
                    }
                    while(!q);
                }
            }
            printf("Enter Contact Number to be modified\n");
            printf("\n* To cancel modify please press 0 *\n");
            printf("\nContact Number:");
            gets(e);
            while(!validatenumber(e))
            {
                printf("\nPlease enter valid contact number: ");
                gets(e);
            }
            u=atoi(e);
            while((!found[u-1]||u<0||u>contacts)&&u)
            {
                printf("\n\t> Contact not included!\n");
                printf("\nPlease enter valid contact number: ");
                gets(e);
                while(!validatenumber(e))
                {
                    printf("\nPlease enter valid contact number: ");
                    gets(e);
                }
                u=atoi(e);

            }
            if(u==0)
            {
                printf("\n\t> Canceled Modify\n");
                menu();
            }
            u--;
            modify(u);
            printf("\n\t> Contact is Successfully Modified!\n\n");
            printdir(d[u],u+1);
            char q;
            do
            {
                printf("\n\t`Continue modifying contact %d:  C\t`Leave Modify:  L\n",u+1);
                printf("\nEnter Command Code:");
                charcheck(&q);
                if(q=='c'||q=='C')
                {
                    modify(u);
                    printf("\n\t> Contact is Successfully Modified!\n\n");
                    printdir(d[u],u+1);
                    q='\0';

                }
                else if(q=='l'||q=='L')
                {
                    printf("\n\t> Left Modify\n");
                    menu();
                }
                else
                {
                    q='\0';
                    printf("Error, Command code not found!\n");

                }
            }
            while(!q);
        }
        else if(c=='p'||c=='P')
        {
            sortlist();
            Sort();
            fillone(found,contacts);
            printfound(found);
        }
        else if(c=='q'||c=='Q')
        {
            Quit();
        }
        else
        {
            c='\0';
            printf("Error, Command code not found!\n");

        }
    }
    while(!c);
    menu();
}
void load()
{
    FILE* a;
    a=fopen("contacts.txt","r");
    int i;
    if(contacts)
    {
        d=malloc(sizeof(directory)*contacts);
    }
    else
    {
        d=malloc(sizeof(directory));
    }
    for(i=0; i<contacts; i++)
    {
        fscanf(a,"%[^,],",d[i].name.last);
        fscanf(a,"%[^,],",d[i].name.first);
        fscanf(a,"%d-",&d[i].DoB.day);
        fscanf(a,"%d-",&d[i].DoB.month);
        fscanf(a,"%d,",&d[i].DoB.year);
        fscanf(a,"%[^,],",d[i].street);
        fscanf(a,"%[^,],",d[i].email);
        fscanf(a,"%d-",&d[i].phone.code);
        fscanf(a,"%u\n",&d[i].phone.num);
    }
    fclose(a);
}
void Add()
{
    realloc(d,(sizeof(directory)*(contacts+1)));
    char s[20];
    printf("Enter first name: ");
    gets(d[contacts].name.first);
    while(!validatename(d[contacts].name.first))
    {
        printf("\nName entered is not Valid!\n\n");
        printf("Enter first name: ");
        gets(d[contacts].name.first);
    }

    printf("\nEnter last name: ");
    gets(d[contacts].name.last);
    while(!validatename(d[contacts].name.last))
    {
        printf("\nName entered is not Valid!\n\n");
        printf("Enter last name: ");
        gets(d[contacts].name.last);
    }

    printf("\nEnter birth day: ");
    gets(s);
    while(!validatenumber(s))
    {
        printf("\nDay entered is not Valid!\n\n");
        printf("Enter birth day: ");
        gets(s);
    }
    d[contacts].DoB.day= atoi(s);
    printf("\nEnter birth month: ");
    gets(s);
    while(!validatenumber(s))
    {
        printf("\nMonth entered is not Valid!\n\n");
        printf("Enter birth month: ");
        gets(s);
    }
    d[contacts].DoB.month= atoi(s);
    printf("\nEnter birth year: ");
    gets(s);
    while(!validatenumber(s))
    {
        printf("\nYear entered is not Valid!\n\n");
        printf("Enter birth year: ");
        gets(s);
    }
    d[contacts].DoB.year= atoi(s);
    while(!validatedate(d[contacts].DoB.day,d[contacts].DoB.month,d[contacts].DoB.year))
    {
        printf("\nDate entered is not Valid!\n\n");
        printf("Enter birth day: ");
        gets(s);
        while(!validatenumber(s))
        {
            printf("\nDay entered is not Valid!\n\n");
            printf("Enter birth day: ");
            gets(s);
        }
        d[contacts].DoB.day= atoi(s);
        printf("\nEnter birth month: ");
        gets(s);
        while(!validatenumber(s))
        {
            printf("\nMonth entered is not Valid!\n\n");
            printf("Enter birth month: ");
            gets(s);
        }
        d[contacts].DoB.month= atoi(s);
        printf("\nEnter birth year: ");
        gets(s);
        while(!validatenumber(s))
        {
            printf("\nYear entered is not Valid!\n\n");
            printf("Enter birth year: ");
            gets(s);
        }
        d[contacts].DoB.year= atoi(s);
    }

    printf("\nEnter street address: ");
    gets(d[contacts].street);

    printf("\nEnter email address: ");
    gets(d[contacts].email);
    while(!validateemail(d[contacts].email))
    {
        printf("\nEmail entered is not Valid!\n\n");
        printf("Enter email address: ");
        gets(d[contacts].email);
    }

    printf("\nEnter area code: ");
    gets(s);
    while(!validatenumber(s))
    {
        printf("\nArea code entered is not Valid!\n\n");
        printf("Enter area code: ");
        gets(s);
    }
    d[contacts].phone.code= atoi(s);
    printf("\nEnter phone number: ");
    gets(s);
    while(!validatenumber(s))
    {
        printf("\nPhone number entered is not Valid!\n\n");
        printf("Enter phone number: ");
        gets(s);
    }
    unsigned long long int j;
    j=atoll(s);
    while(j>4294967295||!validatenumber(s))
    {
        if(j>4294967295)
            printf("\nNumber is too large!\n\n");
        if(!validatenumber(s))
           printf("\nPhone number entered is not Valid!\n\n");
           printf("Enter new phone number: ");
        gets(s);
        j=atoll(s);
    }
    d[contacts].phone.num= atoi(s);

    printf("\n\t> Contact is Successfully Added!\n\n");
    printdir(d[contacts],contacts+1);
    contacts++;
}
void Save()
{
    FILE* a;
    a=fopen("contacts.txt","w");
    int i=0;
    for(i; i<contacts; i++)
    {
        fprintf(a,"%s,",d[i].name.last);
        fprintf(a,"%s,",d[i].name.first);
        fprintf(a,"%d-",d[i].DoB.day);
        fprintf(a,"%d-",d[i].DoB.month);
        fprintf(a,"%d,",d[i].DoB.year);
        fprintf(a,"%s,",d[i].street);
        fprintf(a,"%s,",d[i].email);
        fprintf(a,"%02u-",d[i].phone.code);
        fprintf(a,"%u",d[i].phone.num);
        if(i<contacts-1)
        {
            fprintf(a,"\n");
        }
    }
    fclose(a);
    printf("\t> Progress is Successfully Saved!\n");
}
void Delete(x)
{
    int i=x-1;
    for(i; i<contacts-1; i++)
    {
        Shift(i,i+1);
    }
    contacts--;
    realloc(d,(sizeof(directory)*(contacts)));
}
void Quit()
{
    printf("\nAny unsaved progress will be lost, are you sure you want to Quit?\n");
    printf("\nYes: Y\tNo: N\tYes,but save first: S\n");
    char c;
    do
    {
        printf("\nEnter Command Code:");
        charcheck(&c);
        if(c=='y'||c=='Y')
        {
            printf("\nQuiting Program...\n");
            exit(0);
        }
        else if(c=='n'||c=='N')
        {
            menu();
        }
        else if(c=='s'||c=='S')
        {
            Save();
            printf("\nQuiting Program...\n");
            exit(0);
        }
        else
        {
            c='\0';
            printf("\nError, Command code not found!\n");
        }
    }
    while(!c);
}
void modify(int z)
{
    printf("\nContact to be Modified:\n\n");
    printdir(d[z],z+1);
    modifylist();
    char c,s[20];
    do
    {
        printf("\nEnter Command Code:");
        charcheck(&c);
        if(c=='l'||c=='L')
        {
            printf("Enter new last name: ");
            gets(d[z].name.last);
            while(!validatename(d[z].name.last))
            {
                printf("\nName entered is not Valid!\n\n");
                printf("Enter new last name: ");
                gets(d[z].name.last);
            }
        }
        else if (c=='f'||c=='F')
        {
            printf("Enter new first name: ");
            gets(d[z].name.first);
            while(!validatename(d[z].name.first))
            {
                printf("\nName entered is not Valid!\n\n");
                printf("Enter new first name: ");
                gets(d[z].name.first);
            }
        }
        else if(c=='e'||c=='E')
        {
            printf("\nEnter new email address: ");
            gets(d[z].email);
            while(!validateemail(d[z].email))
            {
                printf("\nEmail entered is not Valid!\n\n");
                printf("Enter new email address: ");
                gets(d[z].email);
            }
        }
        else if (c=='s'||c=='S')
        {
            printf("\nEnter new street address: ");
            gets(d[z].street);
        }
        else if(c=='d'||c=='D')
        {
            printf("\nEnter new birth day: ");
            gets(s);
            while(!validatenumber(s))
            {
                printf("\nDay entered is not Valid!\n\n");
                printf("Enter new birth day: ");
                gets(s);
            }
            d[z].DoB.day= atoi(s);
            printf("\nEnter new birth month: ");
            gets(s);
            while(!validatenumber(s))
            {
                printf("\nMonth entered is not Valid!\n\n");
                printf("Enter new birth month: ");
                gets(s);
            }
            d[z].DoB.month= atoi(s);
            printf("\nEnter new birth year: ");
            gets(s);
            while(!validatenumber(s))
            {
                printf("\nYear entered is not Valid!\n\n");
                printf("Enter new birth year: ");
                gets(s);
            }
            d[z].DoB.year= atoi(s);
            while(!validatedate(d[z].DoB.day,d[z].DoB.month,d[z].DoB.year))
            {
                printf("\nDate entered is not Valid!\n\n");
                printf("Enter new birth day: ");
                gets(s);
                while(!validatenumber(s))
                {
                    printf("\nDay entered is not Valid!\n\n");
                    printf("Enter new birth day: ");
                    gets(s);
                }
                d[z].DoB.day= atoi(s);
                printf("\nEnter new birth month: ");
                gets(s);
                while(!validatenumber(s))
                {
                    printf("\nMonth entered is not Valid!\n\n");
                    printf("Enter new birth month: ");
                    gets(s);
                }
                d[z].DoB.month= atoi(s);
                printf("\nEnter new birth year: ");
                gets(s);
                while(!validatenumber(s))
                {
                    printf("\nYear entered is not Valid!\n\n");
                    printf("Enter new birth year: ");
                    gets(s);
                }
                d[z].DoB.year= atoi(s);
            }
        }
        else if (c=='p'||c=='P')
        {
            printf("\nEnter new area code: ");
            gets(s);
            while(!validatenumber(s))
            {
                printf("\nArea code entered is not Valid!\n\n");
                printf("Enter new area code: ");
                gets(s);
            }
            d[z].phone.code= atoi(s);
            printf("\nEnter new phone number: ");
            gets(s);
            while(!validatenumber(s))
            {
                printf("\nPhone number entered is not Valid!\n\n");
                printf("Enter new phone number: ");
                gets(s);
            }
            unsigned long long int j;
            j=atoll(s);
            while(j>4294967295||!validatenumber(s))
            {
                if(j>4294967295)
                    printf("\nNumber is too large!\n\n");
                if(!validatenumber(s))
                    printf("\nPhone number entered is not Valid!\n\n");
                printf("Enter new phone number: ");
                gets(s);
                j=atoll(s);
            }
            d[z].phone.num= atoi(s);
        }
        else if (c=='c'||c=='C')
        {
            printf("\n\t> Canceled Modify!\n");
            menu();
        }
        else
        {
            c='\0';
            printf("\nError, Command code not found!\n");
        }
    }
    while(!c);
}
void Sort()
{
    char c;
    do
    {
        printf("\nEnter Command Code: ");
        charcheck(&c);
        printf("\n");
        if(c=='f'||c=='F')
        {
            sortByFname();
        }
        else if(c=='l'||c=='L')
        {
            sortByLname();
        }
        else if(c=='d'||c=='D')
        {
            sortByDOB();
        }
        else if(c=='c'||c=='C')
        {
            printf("\n\t> Canceled Sort!\n");
            menu();
        }
        else
        {
            c='\0';
            printf("Error, Command code not found!\n");

        }
    }
    while(!c);
}
void sortByDOB()
{
    int i,j;
    for(j=0; j<contacts-1; j++)
    {
        for(i=0; i<contacts-1-j; i++)
        {
            if(d[i].DoB.year<d[i+1].DoB.year)
            {
                Swap(i,i+1);
                continue;
            }
            else if(d[i].DoB.year==d[i+1].DoB.year)
            {
                if(d[i].DoB.month<d[i+1].DoB.month)
                {
                    Swap(i,i+1);
                    continue;
                }
                else if(d[i].DoB.month==d[i+1].DoB.month)
                {
                    if(d[i].DoB.day<d[i+1].DoB.day)
                    {
                        Swap(i,i+1);
                        continue;
                    }
                }
            }
        }
    }
}
void sortByLname()
{
    int i=0,j=0,x,y;
    for(i=0; i<contacts-1; i++)
    {
        for(j=0; j<contacts-1-i; j++)
        {
            x=strcasecmp(d[j].name.last,d[j+1].name.last);
            if(x==1)
            {
                Swap(j,j+1);
            }
            else if (x==0)
            {
                y=strcasecmp(d[j].name.first,d[j+1].name.first);
                if(y==1)
                {
                    Swap(j,j+1);
                }
            }
        }
    }
}
void sortByFname()
{
    int i=0,j=0,x,y;
    for(i=0; i<contacts-1; i++)
    {
        for(j=0; j<contacts-1-i; j++)
        {
            x=strcasecmp(d[j].name.first,d[j+1].name.first);
            if(x==1)
            {
                Swap(j,j+1);
            }
            else if (x==0)
            {
                y=strcasecmp(d[j].name.last,d[j+1].name.last);
                if(y==1)
                {
                    Swap(j,j+1);
                }
            }
        }
    }

}
void Search(char c,int* found)
{
    int i=0;
    if(c=='l'||c=='L')
    {
        char s[15];
        printf("\nEnter last name: ");
        gets(s);
        for(i; i<contacts; i++)
        {
            found[i]=substring(d[i].name.last,s);
        }

    }
    else if(c=='f'||c=='F')
    {
        char s[15];
        printf("\nEnter first name: ");
        gets(s);
        for(i=0; i<contacts; i++)
        {
            found[i]=substring(d[i].name.first,s);
        }
    }
    else  if(c=='s'||c=='S')
    {
        char s[40];
        printf("\nEnter street address: ");
        gets(s);
        for(i; i<contacts; i++)
        {
            found[i]=substring(d[i].street,s);
        }

    }
    else  if(c=='e'||c=='E')
    {
        char s[40];
        printf("\nEnter email address: ");
        gets(s);
        for(i; i<contacts; i++)
        {
            found[i]=substring(d[i].email,s);
        }

    }
    else if(c=='p'||c=='P')
    {
        int i;
        int fa[contacts];
        int fn[contacts];
        printf("\nEnter area code: ");
        inttostr(fa,'a');
        printf("\nEnter phone number: ");
        inttostr(fn,'n');
        for(i=0; i<contacts; i++)
        {
            if(fa[i]&&fn[i])
            {
                found[i]=1;
            }
        }
    }
    else if(c=='d'||c=='D')
    {
        int i;
        int fd[contacts];
        int fm[contacts];
        int fy[contacts];
        printf("\nEnter day of birth: ");
        inttostr(fd,'d');
        printf("\nEnter month of birth: ");
        inttostr(fm,'m');
        printf("\nEnter year of birth: ");
        inttostr(fy,'y');
        for(i=0; i<contacts; i++)
        {
            if(fd[i]&&fm[i]&&fy[i])
            {
                found[i]=1;
            }
        }
    }
    else if(c=='m'||c=='M')
    {
        printf("\nTo skip a category, just press enter\n");
        Multisearch(found);
    }
    else if(c=='c'||c=='C')
    {
        printf("\n\t> Canceled Search!\n");
        menu();
    }
    else
    {
        printf("\nError, Command code not found!\n");
        printf("\nEnter Command Code: ");
        charcheck(&c);
        Search(c,found);
    }
}
void inttostr(int* found,char c)
{
    int i=0;
    char b[12];
    char s[contacts][12];
    gets(b);
    /*if(!validatenumber(b))
    {
        c='\0';
    }
    if(validatenumber(b))
    {
        int x;
        x=atoi(b);
        sprintf(b,"%d",x);
    }
    else */if(c=='a')
    {
        for(i=0; i<contacts; i++)
        {
            sprintf(s[i],"%d",d[i].phone.code);
            found[i]=substring(s[i],b);
        }
    }
    else if(c=='n')
    {
        for(i=0; i<contacts; i++)
        {
            sprintf(s[i],"%u",d[i].phone.num);
            found[i]=substring(s[i],b);
        }
    }
    else if(c=='d')
    {
        for(i=0; i<contacts; i++)
        {
            sprintf(s[i],"%d",d[i].DoB.day);
            found[i]=substring(s[i],b);
        }
    }
    else if(c=='m')
    {
        for(i=0; i<contacts; i++)
        {
            sprintf(s[i],"%d",d[i].DoB.month);
            found[i]=substring(s[i],b);
        }
    }
    else if(c=='y')
    {
        for(i=0; i<contacts; i++)
        {
            sprintf(s[i],"%d",d[i].DoB.year);
            found[i]=substring(s[i],b);
        }
    }
}
int substring(char* m,char* s)
{
    int i=0,j;
    if(s[0]=='\0')
    {
        return 1;
    }
    while(m[i])
    {
        if(tolower(s[0])==tolower(m[i]))
        {
            for(j=1; s[j]; j++)
            {
                if(tolower(s[j])!=tolower(m[i+j]))
                {
                    break;
                }
            }
            if(!s[j])
            {
                return 1;
            }
        }
        i++;
    }
    return 0;
}
void Multisearch(int* found)
{
    int i;
    int fl[contacts];
    int ff[contacts];
    int fs[contacts];
    int fe[contacts];
    int fd[contacts];
    int fp[contacts];
    Search('l',fl);
    Search('f',ff);
    Search('s',fs);
    Search('e',fe);
    Search('d',fd);
    Search('p',fp);
    for(i=0; i<contacts; i++)
    {
        if(fl[i]&&ff[i]&&fs[i]&&fe[i]&&fp[i]&&fd[i])
        {
            found[i]=1;
        }
    }
}
void menulist()
{
    printf("\nNumber of Contacts: %d\n\n",contacts);
    printf("\tCommand Window\n\n");
    printf("\t` Search Contact: S\t` Add New Contact: A\t` Save Progress: V\t\n");
    printf("\t` Delete Contact: D\t` Modify Contact:  M\t` Print Contacts[Sorted]: P\t\n");
    printf("\t` Quit Program: Q\n");
}
void searchlist()
{
    printf("\tSearch By\n\n");
    printf("\t` First Name:  F\t` Email Address:  E\t` Date of Birth: D\t\n");
    printf("\t` Last Name:   L\t` Street Address: S\t` Phone Number:  P\t\n");
    printf("\t` MultiSearch: M\t` Cancel Search:  C\n");
}
void modifylist()
{
    printf("\tModify\n\n");
    printf("\t` First Name:  F\t` Email Address:  E\t` Date of Birth: D\t\n");
    printf("\t` Last Name:   L\t` Street Address: S\t` Phone Number:  P\t\n");
    printf("\t` Cancel Modify:  C\n");
}
void sortlist()
{
    printf("\tSort By\n\n");
    printf("\t` First Name:   F\t` Last Name:  L\t\t` Date of Birth:  D\t\n");
    printf("\t` Cancel Sort:  C\n");
}
void printdir(directory z,int i)
{
    printf("\t\tContact %d\n\n",i);
    printf("\tFirst Name:      %s\n",z.name.first);
    printf("\tLast Name:       %s\n",z.name.last);
    printf("\tDate of Birth:   %02d-%02d-%04d\n",z.DoB.day,z.DoB.month,z.DoB.year);
    printf("\tStreet Address:  %s\n",z.street);
    printf("\tEmail Address:   %s\n",z.email);
    printf("\tPhone Number:    %02d-%u\n",z.phone.code,z.phone.num);
    printf("\n");
}
void printfound(int* found)
{
    int i,x=0;
    printf("\n");
    for(i=0; i<contacts; i++)
    {
        if(found[i])
        {
            x++;
            printdir(d[i],i+1);
        }
    }
    if(!x)
    {
        printf("\t> No Contacts Found!\n");

    }
}
int counter()
{
    FILE* a;
    a=fopen("contacts.txt","r");
    char c;
    int n=0;
    fscanf(a,"%c",&c);
    while(!feof(a))
    {
        fscanf(a,"%c",&c);
        if(c=='\n'||feof(a))
        {
            n++;
        }
    }
    fclose(a);
    return n;
}
void fillzero(int* a,int x)
{
    int i;
    for(i=0; i<x; i++)
    {
        a[i]=0;
    }
}
void fillone(int* a,int x)
{
    int i;
    for(i=0; i<x; i++)
    {
        a[i]=1;
    }
}
void Shift(int i,int j)
{
    strcpy(d[i].name.last,d[j].name.last);
    strcpy(d[i].name.first,d[j].name.first);
    d[i].DoB.day=d[j].DoB.day;
    d[i].DoB.month=d[j].DoB.month;
    d[i].DoB.year=d[j].DoB.year;
    strcpy(d[i].street,d[j].street);
    strcpy(d[i].email,d[j].email);
    d[i].phone.code=d[j].phone.code;
    d[i].phone.num=d[j].phone.num;
}
void Swap(int i,int j)
{
    directory temp;
    strcpy(temp.name.last,d[j].name.last);
    strcpy(temp.name.first,d[j].name.first);
    temp.DoB.day=d[j].DoB.day;
    temp.DoB.month=d[j].DoB.month;
    temp.DoB.year=d[j].DoB.year;
    strcpy(temp.street,d[j].street);
    strcpy(temp.email,d[j].email);
    temp.phone.code=d[j].phone.code;
    temp.phone.num=d[j].phone.num;

    strcpy(d[j].name.last,d[i].name.last);
    strcpy(d[j].name.first,d[i].name.first);
    d[j].DoB.day=d[i].DoB.day;
    d[j].DoB.month=d[i].DoB.month;
    d[j].DoB.year=d[i].DoB.year;
    strcpy(d[j].street,d[i].street);
    strcpy(d[j].email,d[i].email);
    d[j].phone.code=d[i].phone.code;
    d[j].phone.num=d[i].phone.num;

    strcpy(d[i].name.last,temp.name.last);
    strcpy(d[i].name.first,temp.name.first);
    d[i].DoB.day=temp.DoB.day;
    d[i].DoB.month=temp.DoB.month;
    d[i].DoB.year=temp.DoB.year;
    strcpy(d[i].street,temp.street);
    strcpy(d[i].email,temp.email);
    d[i].phone.code=temp.phone.code;
    d[i].phone.num=temp.phone.num;
}
int zerocheck(int* found,int x)
{
    int i,flag=0;
    for(i=0; i<x; i++)
    {
        if(found[i])
        {
            flag=1;
            break;
        }
    }
    return flag;
}
int validateemail(char* e)
{
    int i=0,l;
    char c[40];
    char* t;
    char* p;
    l=strlen(e);
    strcpy(c,e);
    p=c;
    if(!isalpha(c[0]))
        return 0;
    if(!substring(c,"@"))
        return 0;
    if(!substring(p,"."))
        return 0;
    if(!substring(p,".com"))
        return 0;
    if(substring(c,"@."))
        return 0;
    if(c[l-1]=='.')
        return 0;
    t=strtok(c,"@");
    i=0;
    while(t[i])
    {
        if((!isalnum(t[i]))&&t[i]!='.'&&t[i]!='_'&&t[i]!='-')
            return 0;
        i++;
    }
    t=strtok(NULL,".");
    i=0;
    while(t[i])
    {
        if(!isalpha(t[i]))
            return 0;
        i++;
    }
    t=strtok(NULL,"");
    i=0;
    while(t[i])
    {
        if(!isalpha(t[i]))
            return 0;
        i++;
    }
    return 1;
}
int validatedate(int d,int m,int y)
{
    int leap=0,n=0;
    if(!(y%4))
        leap=1;
    if(d<1||m<1||m>12||y<1)
        return 0;
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        if(d>31)
            return 0;
    if(m==4||m==6||m==9||m==11)
        if(d>30)
            return 0;
    if(m==2)
    {
        if(!leap&&d>28)
            return 0;
        if(leap&&d>29)
            return 0;
    }
    return 1;
}
int validatename(char* n)
{
    int i;
    for(i=0; n[i]; i++)
    {
        if(!isalpha(n[i]))
            return 0;
    }
    return 1;
}
int validatenumber(char* n)
{
    int i;
    for(i=0; n[i]; i++)
    {
        if(!isdigit(n[i]))
            return 0;
    }
    return 1;
}
void charcheck(char* c)
{
    char cs[15];
    *c='\0';
    gets(cs);
    if(!cs[1])
    {
        *c=cs[0];
    }
}
