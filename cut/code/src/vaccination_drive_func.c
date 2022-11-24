/**********************************************************************************************************************
*
* FILE NAME 		: vaccination_drive_func.c
*
* DESCRIPTION 		: This file defines the functions in the beneficiary menu and admin to 
				perform various operations in the beneficiary database
*
****************************************************************************************************/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vaccination_drive_header.h"
//#include "vaccination_drive_func1.c"

bn *start,*new,*ptr,*prev,*last;

int add_beneficiary_data()

{
	if((new=(bn *)calloc(1,sizeof(bn)))==NULL)
	{
		printf("\nMemory allocation failure\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		printf("Enter beneficiary_aadharno range :");
		scanf("%lld",&new->beneficiary_aadharno);
		if(validate_aadhar(new->beneficiary_aadharno))
		{
			printf("\nInvalid beneficiary_aadharno\n");
			continue;
		}
		if(start)
		{
			for(ptr=start;(ptr) && ptr->beneficiary_aadharno!=new->beneficiary_aadharno;ptr=ptr->next);
			if((ptr)&& ptr->beneficiary_aadharno==new->beneficiary_aadharno)
			{
				printf("\nAadharnumber %lld already exits\n",new->beneficiary_aadharno);
				continue;
			}
			else
			{
				break;
			
			
			}
		}
		else
			break;
	}
	while(1)
	{
		printf("Enter beneficiary_name-");
		scanf("%s",&new->beneficiary_name);
		if(alpha_valid(new->beneficiary_name)==0)
		{
			printf("\n Name should have only alphabets");
			continue;
		}
		else
		{
			
			//new->beneficiary_name=beneficiary_name;
			break;
		}
		break;
	}
	while(1)
	{
		printf("Enter beneficiary-age-");
		scanf("%d",&new->beneficiary_age);
		if(age_validation(new->beneficiary_age)==0)
			continue;
		else
		{
			//new->beneficiary_age=beneficiary_age;
			break;
		
		}
		break;
	}
	while(1)
	{
		printf("\nEnter beneficiary phno:");
		scanf("%lld",&new->beneficiary_phno);
		if(validate_phoneno(new->beneficiary_phno))
		{
			printf("\nInvalid beneficiary_phno range is 1-10\n");
			continue;
		}
		else
		{
			//new->beneficiary_phno==beneficiary_phno;
			break;
		}
		break;
	}
	if(!start)
	{
		new->beneficiary_id=100;
		start=last=new;
		new->next=NULL;
	}
	else
	{
		new->beneficiary_id=last->beneficiary_id+1;
		last=new;
		new->next=NULL;
	}


}
int view_beneficiary_data()
{
	if(!start)
	{
		printf("\nNo records found\n");
		return EXIT_FAILURE;
	}
	for(ptr=start;(ptr);ptr=ptr->next)
	{
	printf("\n%lld %4s  %5lld %5s %2d\n",ptr->beneficiary_aadharno,ptr->beneficiary_name,ptr->beneficiary_phno,ptr->beneficiary_address,ptr->beneficiary_age);
	}
	return EXIT_SUCCESS;
	


}
int edit_beneficiary_data()
{
	if(!start)
	{
		printf("\nNo records found\n");
		return EXIT_FAILURE;
	}
	int beneficiary_aadharno;
	while(1)
	{
		printf("\nEnter the beneficiary aadhar no\n");
		scanf("%lld",&beneficiary_aadharno);
		for(ptr=start;(ptr)&&ptr->beneficiary_aadharno!=beneficiary_aadharno;ptr=ptr->next);
		if(!ptr)
		{
			printf("\nbeneficiary aadharno %d not found\n",beneficiary_aadharno);
			return EXIT_SUCCESS;
		}
		printf("Enter new address, new phone number");
		scanf("%s %lld",ptr->beneficiary_address,&ptr->beneficiary_phno);
	}
	return EXIT_SUCCESS;
}
int view_details()
{
	/*long int m_aadhar_no;
	if(l1.empty())
	{
		printf("Empty file");
		return EXIT_FAILURE;
	}
	printf("\nEnter your aadhar numner to view your details: ");
	scanf("%lf",&m_aadhar_no);
	printf("\naadhar Name Age Gender Shots\n");
	int flag=0;
	for(ptr=start;(ptr) && ptr->beneficiary_aadharno!=new->beneficiary_aadharno;ptr=ptr->next);
	{
		if(new->get_aadhar()==m_aadhar_no)
		{
			new->view_user();
			break;
		}
		else
		{
			flag=1;
		}
	}
	if(flag==1)
		{
			printf("\nAadhar number not found");
		}
		system("read a");
		system("clear");
		return EXIT_SUCCESS;*/
	

}
/*int select_user()
{
	long int m_aadhar_no=" ";
	printf("Enter your aadhar number: ");
	scanf("%lf",&m_aadhar_no);
	int choice=0;
	push("1.Hawkins");
	push("2. Riverdale");
	push("3.Central perk");
}*/

	
int admin_login()
{
	while(1)
	{
		char admin_id[50];
		char pswd[20];
		system("read a");
		system("clear");
		printf("Enter admin_id");
		scanf("%s",admin_id);
		printf("Enter password");
		scanf("%s",pswd);

		if(strcmp(pswd,"admin@123")==0)
		{
			system("clear");
			int ch1=0;
			while(ch1!=8)
			{
				printf("\n1.view beneficiary data\n2.add beneficiary data\n3.edit beneficiary data\n4.delete beneficiary data\n5.display fully vaccianted beneficiaries\n6.display partially vaccinated beneficiaries\7.display today vaccinated beneficiaries\n8.exit\n");
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
				break;
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
int delete_beneficiary_data()
{
	if(!start)
	{
		printf("\nNp record found\n");
		return EXIT_FAILURE;
	}
	long long int beneficiary_aadharno;
	while(1)
	{
		printf("\nEnter the aadhar no for deleting:");
		scanf("%lld",&beneficiary_aadharno);
		if(validate_aadhar(beneficiary_aadharno)>12||validate_aadhar(beneficiary_aadharno)<12)
		{
			printf("\nEnter valid aadhar no");
			continue;
		}
		else
		{
			break;
		
		}
		break;
	}
	if(beneficiary_aadharno==start->beneficiary_aadharno)
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
	else
	{
		for(ptr=start;(ptr) && ptr->beneficiary_aadharno!=beneficiary_aadharno;prev=ptr,ptr=ptr->next);
		if(!ptr)
		{
			printf("\nAadhar no %lld is not found\n",beneficiary_aadharno);
			return EXIT_FAILURE;
		}
		prev->next=ptr->next;
		free(ptr);
	}
	return EXIT_SUCCESS;
}
int select_center()
{
	if((new=(bn *)calloc(1,sizeof(bn)))==NULL)
	{
		printf("\nMemory allocation failure\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		long long int beneficiary_aadharno;
		printf("\nEnter aadharno:");
		printf("\nchoose center:\n");
		printf("\n1.Ward1\n2.Ward2\n3.Ward3\n");
		scanf("%lld",&beneficiary_aadharno);
		int choice=0;
		scanf("%d",&new->choice);
		if(new->choice>3)
		{
			printf("\nEnter valid center\n");
			continue;
		}
		else
		{
			if(new->choice==1)
			{
				strcpy(new->center,"Ward1");
				printf("\nCenter1 selected successfully\n");
			}
			if(new->choice==2)
			{
				strcpy(new->center,"Ward2");
				printf("\nCenter2 seleted successfully\n");
			}
			if(new->choice==3)
			{
				strcpy(new->center,"Ward3");
				printf("\nCenter2 selected successfully\n");
			}
		}
		break;


	}
}
int book_slot()
{

}
int get_vaccinated()
{
}

int display_fully_vaccinated_beneficiaries()
{
	char beneficiary_aadharno;
	printf("\n------Delete fully vaccinated beneficiaries------\n");
	printf("\nEnter the aadhar no whose record you want to delete:\n");
	scanf("%lld",&beneficiary_aadharno);


}
int display_partially_vaccinated_beneficiaries()
{
}
int display_today_vaccinated_beneficiaries()
{
}



