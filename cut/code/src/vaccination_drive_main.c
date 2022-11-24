/********************************************************************************************************************************************************************
* * FILE NAME  			:  vaccination_drive_main.c
*
* * DESCRIPTION 		:  This file consists of Main and Menu displays the functions in it
*
*************************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vaccination_drive_header.h"
int main()
{
	char admin_pass[50];
	int choice;
	//printf("enter the choice");
	//scanf("%d",&choice);
	while(choice!=3)
	{
		//printf("enter the choice");
		printf("\n Main_menu\n");
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
int vaccination_admin_login()
{
	int choice3;
	printf("enter  the choice3\n");
	scanf("%d\n",&choice3);
	while(choice3!=8)
	{
		printf("\nAdmin login\n");
		printf("\n1.show beneficiary data\n2.add beneficiary data\n3.edit beneficiary data\n4.delete beneficiary data\n5.display fully vaccinated beneficiaries\n6.display partially vaccinated beneficiaries\n7.display today vaccinated beneficiaries\n8.Exit");
		switch(choice3)
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
	return EXIT_SUCCESS;
}

int new_user()
{
	/*int choice2;
	while(choice2!=3)
	{
		printf("\n New user corner\n");
		printf("\n1.create account\n2.view details\n3.exit\n");
		printf("\nEnter your choice\n");
		switch(choice2)
		{
			case 1:create_account();
			       break;
			case 2:view_details();
			       break;
			case 3:break;
			default:printf("\nInvalid choice\n");
				continue;
		}
	}*/
}

int registered_user()
{
	int choice4;
	while(choice4!=5)
	{
		printf("\n registered user corner\n");
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


