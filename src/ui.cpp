/**
 * @file main.cpp
 * @brief This is a test of CMake, doxygen, and GitHub.
 * @details This is the long brief at the top of main.cpp.
 * @author Scott Gillis and Benson Nyakango
 * @date 4/21/2021
 * 
 */

/**
 * Sources:
 * https://www.geeksforgeeks.org/trie-insert-and-search/
 * https://youtu.be/vXD0JuuLatA
 * 
*/


#include<iostream>

using namespace std;
int menu();
int k=0;


int main()
{
	string Fname[100];
	string Pnumber[100];
	int check=0;
	int Total_contacts=0;
    check=menu();
    do
    {
    	// Add contacts 
    	if(check==1)
    	{
    		cout<<"\t\t\t\t\t\t Name: ";
    		cin>>Fname[k];
    		cout<<"\t\t\t\t\t\t Phone no: ";
    		cin>>Pnumber[k];
    		k++;
    		Total_contacts++;
		}
		
		//Display contacts
		else if (check==2)
		{
			int check2=0;
			for(int i=0; i<100;i++)
			{
				if(Fname[i]!="\0")
				cout<<"\t\t\t\t\t Contact Name: "<<Fname[i]<< "     Phone # of contact: "<<Pnumber[i]<<endl;
				check2++;
			}
			if(check2==0)
			{
				cout<<"\t\t\t\t\t";
			}
		}
		//Search by Number
		else if(check==3)
		{
			string temp;
			cout<<"\t\t\t\t\tNumber: ";
			cin>>temp;
			int check2=0;
			for(int i=0;i<100;i++)
			{
				if(temp==Pnumber[i])
				{
					cout<<"\t\t\t\t\tNumber is Found\n";
					cout<<"\t\t\t\t\tName : "<<Fname[i]<<"       Phone : "<<Pnumber[i]<<endl;
					check2++;
				}
			}
			if(check2==0)
			{
				cout<<"\t\t\t\t\t This Number is Not found in your contact list\n";
			}
		}
		//Search By Name
		else if(check==4)
		{
				string temp;
			cout<<"\t\t\t\t\tName : ";
			cin>>temp;
			int check2=0;
			for(int i=0;i<100;i++)
			{
				if(temp==Fname[i])
				{
					cout<<"\t\t\t\t\tName is Found\n";
					cout<<"\t\t\t\t\tName : "<<Fname[i]<<"       Phone : "<<Pnumber[i]<<endl;
					check2++;
				}
				
			}
			if(check2==0)
			{
				cout<<"\t\t\t\t\t This name is Not found in your contact list\n";
			}
		}
		// Update
		else if(check==5)
		{
			string temp,temp2,temp3;
			cout<<"\t\t\t\t\tName : ";
			cin>>temp;
			int check2=0;
			for(int i=0;i<100;i++)
			{
				if(temp==Fname[i])
				{
					cout<<"\t\t\t\t\tNew Name : ";
					cin>>temp2;
					cout<<"\t\t\t\t\tNew Number : ";
					cin>>temp3;
					Fname[i]=temp2;
					Pnumber[i]=temp3;
					check2++;
					cout<<"\t\t\t\t\tUpdated Successfully ";
				}
			
			}
				if(check2==0)
			{
				cout<<"\t\t\t\t\t This name is Not found in your contact list\n";
			}
		}
		// Delete
		else if(check==6)
		{
				string temp;
			cout<<"\t\t\t\t\tFor Delete Enter Name : ";
			cin>>temp;
			int check2=0;
			for(int i=0;i<100;i++)
			{
				if(temp==Fname[i])
				{
					cout<<"\t\t\t\t\tDeleted Successfully\n";
					cout<<"\t\t\t\t\tName : "<<Fname[i]<<"       Phone : "<<Pnumber[i]<<endl;
					Fname[i]="\0";
					Pnumber[i]="\0";
					check2++;
					Total_contacts--;
				}
			}
			if(check2==0)
			{
				cout<<"\t\t\t\t\t This name is Not found in your contact list\n";
			}
		}
		// Deletes all the contacts
		else if(check==7)
		{	
		
					cout<<"\t\t\t\t\t All Deleted Successfully\n";
					for(int i=0;i<k;i++)
					{
						Fname[i]="\0";
						Pnumber[i]="\0";
					}
					k=0;
					Total_contacts=0;
		}
		
		check=menu();
		
	}while(check!=8);
	
}
int menu()
{
    cout<<"\t\t\t\t\t--------------------------------------------\n";
	cout<<"\t\t\t\t\t|          Phonebook Program               |\n";
	cout<<"\t\t\t\t\t--------------------------------------------\n";
	cout<<"\t\t\t\t\t|       1.   Add Contacts                  |\n";
	cout<<"\t\t\t\t\t|       2.   Display All Contacts          |\n";
	cout<<"\t\t\t\t\t|       3.   Search by Number              |\n";
	cout<<"\t\t\t\t\t|       4.   Search by Name                |\n";
	cout<<"\t\t\t\t\t|       5.   Modify                        |\n";
	cout<<"\t\t\t\t\t|       6.   Delete                        |\n";
	cout<<"\t\t\t\t\t|       7.   Delete All                    |\n";
	cout<<"\t\t\t\t\t|       8.   Exit                          |\n";
	cout<<"\t\t\t\t\t--------------------------------------------\n";
	
	int a;
	cin>>a;
	return a;
}



 

