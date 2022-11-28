#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/vaccination_drive_header.h"
int main()
{
	beneficiary_file_to_list();
	//printf("enter the choice");
	//scanf("%d",&choice);
	int choice;
	while(choice!=3)
	{
		
		printf("\n*********** Main_menu***********\n");
		printf("\n1.Beneficiary_login\n");
		printf("\n2.Admin_login\n");
		printf("\n3.exit\n");
		printf("enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:vaccination_beneficiary_login();
		               break;
			case 2:admin_login();
			       break;
			case 3:break;
			default:printf("\nInvalid choice\n");
			continue;
		}
	}
	beneficiary_list_to_file();
}
int vaccination_beneficiary_login()
{
	int choice2;
	//printf("enter  the choice2\n");
	//scanf("%d\n",&choice2);
	while(choice2!=3)
	{
		printf("\n1.New_user\n2.Registered_user\n3.exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice2);
		switch(choice2)
		{
			case 1:new_user();
			       break;
			case 2:registered_user();
			       break;
			case 3:break;
			default:printf("\nInvalid choice\n");
				continue;
		}
	}
}
int admin_login()
{
	while(1)
	{
		char admin_id[50];
		char pswd[20];
		system("read a");
		system("clear");
		printf("Enter admin_id : ");
		scanf("%s",admin_id);
		printf("Enter password : ");
		scanf("%s",pswd);

		if(strcmp(pswd,"admin@123")==0)
		{
			system("clear");
			int ch1=0;
			while(ch1!=8)
			{
				printf("\n1.view beneficiary data\n2.add beneficiary data\n3.edit beneficiary data\n4.delete beneficiary data\n5.display fully vaccianted beneficiaries\n6.display partially vaccinated beneficiaries\n7.display today vaccinated beneficiaries\n8.goback\n");
				printf("Enter your choice:\n");
				scanf("%d",&ch1);
				switch(ch1)
				{
					case 1:view_beneficiary_data();
					       break;
					case 2:add_beneficiary_data();
					       break;
					case 3:edit_beneficiary_data();
					       break;
					case 4:delete_beneficiary_data();
					       break;
					case 5:display_fully_vaccinated_beneficiaries();
					       break;
					case 6:display_partially_vaccinated_beneficiaries();
					       break;
					case 7:display_today_vaccinated_beneficiaries();
					       break;
					case 8:break;
					default:printf("\nInvalid choice\n");
						continue;
				}
			}
		}
		else
		{
			printf("Wrong Password\nAccess Denied\n");
			continue;
		}
		break;
	}
}

int new_user()
{
	int choice2;
	while(choice2!=3)
	{
		system("read a");
		system("clear");
		printf("\n***********New user corner***********\n");
		printf("\n1.User registration\n2.edit user details\n3.view user details\n4.goback\n");
		printf("\nEnter your choice\n");
		scanf("%d",&choice2);
		switch(choice2)
		{
			case 1:user_registration();
			       break;
			case 2:edit_user_details();
			       break;
			case 3:view_user_details();
			       break;
			case 4:return EXIT_SUCCESS;
			default:printf("\nInvalid choice\n");
				continue;
		}
	}
}

int registered_user()
{
	int choice4;
	while(choice4!=5)
	{
		printf("\n***********Registered user corner***********\n");
		printf("\n1.select centre\n2.book slot\n3.view details\n4.get vaccinated\n5.exit\n");
		printf("Enter your choice");
		scanf("%d",&choice4);
		switch(choice4)
		{
			case 1:select_center();
			       break;
			case 2:book_slot();
			       break;
			case 3:view_details();
			       break;
			case 4:get_vaccinated();
			       break;
			case 5:break;
			default:printf("Invalid choice");
				continue;
		}
	}

}


