/*
Pr. No: 05
Batch : A & D
Title: 	Consider telephone book database of N clients. 
	Make use of a hash table implementation to quickly look up client‘s telephone number. 
Date : 
*/


#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

//...........................................................................


struct Database 	//Structure for Hash Table 
{
	char Name[20];
	int tel_No;	

}Hash_Table[10];	//Hash Table using Array


//...........................................................................


class Tel_Book
{
    public:
	void create_Db();
	void print_Db();
        int Hash(char *str);
	void search_Db();
}B1;

//...........................................................................

void Tel_Book :: create_Db()
{
    int No,key;
    char NM[10];

    cout<<"\n\t Enter Client's Name: ";
    cin>>NM;
    cout<<"\n\t Enter Client's Telephone No: ";
    cin>>No;
 

    key = Hash(NM);

    strcpy(Hash_Table[key].Name , NM);
    Hash_Table[key].tel_No = No;

    cout<<"\n\n\t 1 Record Inserted in Hash Table !!!";
}

//...........................................................................

void Tel_Book :: print_Db()
{
    int i;
    
    cout<<"\n\t --** Hash Table **--";
    cout<<"\n\n\t Index   Name  \tTel_No";
    for(i=0; i<10; i++)
    {
	cout<<"\n\t  "<<i;
	cout<<"\t"<<Hash_Table[i].Name;
	cout<<"  "<<Hash_Table[i].tel_No;
    }
}
	
//...........................................................................

void Tel_Book :: search_Db()
{
    int key;
    char NM[10];

    cout<<"\n\t To Search Client ";
    cout<<"\n\t Enter Client's Name: ";
    cin>>NM;

    key = Hash(NM);

    if(Hash_Table[key].tel_No != 0) 
       cout<<"\n\n\t Clients Telephone No: "<<Hash_Table[key].tel_No;
    else
       cout<<"\n\n\t Record Not found in Hash Table !!!";
}

//...........................................................................

int Tel_Book :: Hash(char str[])
{
    int i,value = 0;

    for(i=0; i < strlen(str); i++)
    {
	value = value + str[i];
    }

    return value % 10;
    
}

//...........................................................................


int main()
{
    int ch;
    char ans;

    cout<<"\n\n\t !!! Telephone Database !!!";

    do
    {
	cout<<"\n\n *** Menu ***";
	cout<<"\n\n 1. Create Telephone database ***";
	cout<<"\n\n 2. Print Client's database   ***";
	cout<<"\n\n 3. Look up Client's Tele_No. ***";
	cout<<"\n\n 4. Quit Database ***";

	cout<<"\n\n Enter your choice: ";
	cin>>ch;

	switch(ch)
	{
	    	case 1: B1.create_Db();
			break;

	    	case 2: B1.print_Db();
			break;

	    	case 3: B1.search_Db();
			break;

	    	case 4: exit(0);
			break;
	
	}

	cout<<"\n\n\t Do you wanna continue ??? : ";
	cin>>ans;
    }while(ans != 'n');
}


/*----------- Output --------------------------------------

student@CORELAB1:~$ g++ Pr_5AD.cpp -o a
student@CORELAB1:~$ ./a


	 !!! Telephone Database !!!

 *** Menu ***

 1. Create Telephone database ***

 2. Print Client's database   ***

 3. Look up Client's Tele_No. ***

 4. Quit Database ***

 Enter your choice: 1

	 Enter Client's Name: Amit

	 Enter Client's Telephone No: 2343434


	 1 Record Inserted in Hash Table !!!

	 Do you wanna continue ??? : y


 *** Menu ***

 1. Create Telephone database ***

 2. Print Client's database   ***

 3. Look up Client's Tele_No. ***

 4. Quit Database ***

 Enter your choice: 1

	 Enter Client's Name: Sanjay

	 Enter Client's Telephone No: 2565656


	 1 Record Inserted in Hash Table !!!

	 Do you wanna continue ??? : y


 *** Menu ***

 1. Create Telephone database ***

 2. Print Client's database   ***

 3. Look up Client's Tele_No. ***

 4. Quit Database ***

 Enter your choice: 1

	 Enter Client's Name: Rahul

	 Enter Client's Telephone No: 2656565


	 1 Record Inserted in Hash Table !!!

	 Do you wanna continue ??? : y


 *** Menu ***

 1. Create Telephone database ***

 2. Print Client's database   ***

 3. Look up Client's Tele_No. ***

 4. Quit Database ***

 Enter your choice: 2

	--** Hash Table **--

	 Index   Name  	Tel_No
	  0	  0
	  1	  0
	  2	  0
	  3	  0
	  4	Sanjay  2565656
	  5	Amit  2343434
	  6	  0
	  7	  0
	  8	Rahul  2656565
	  9	  0

	 Do you wanna continue ??? : y


 *** Menu ***

 1. Create Telephone database ***

 2. Print Client's database   ***

 3. Look up Client's Tele_No. ***

 4. Quit Database ***

 Enter your choice: 3

	 To Search Client 
	 Enter Client's Name: Amit


	 Clients Telephone No: 2343434

	 Do you wanna continue ??? : y


*** Menu ***

 1. Create Telephone database ***

 2. Print Client's database   ***

 3. Look up Client's Tele_No. ***

 4. Quit Database ***

 Enter your choice: 3

	 To Search Client 
	 Enter Client's Name: rahul


	 Record Not found in Hash Table !!!


 *** Menu ***

 1. Create Telephone database ***

 2. Print Client's database   ***

 3. Look up Client's Tele_No. ***

 4. Quit Database ***

 Enter your choice: 4

student@CORELAB1:~$ 

*/

