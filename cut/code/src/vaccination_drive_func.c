#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/vaccination_drive_header.h"
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
		printf("\nEnter beneficiary aadharno :");
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
		printf("\nEnter beneficiary name:");
		scanf("%s",new->beneficiary_name);
		if(alpha_valid(new->beneficiary_name)==0)
		{
			printf("\n Name should have only alphabets");
			continue;
		}
		else
		{
			break;
		}
		break;
	}
	while(1)
	{
		printf("\nEnter beneficiary age:");
		scanf("%d",&new->beneficiary_age);
		if(age_validation(new->beneficiary_age)==0)
			continue;
		else
		{
	
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
			break;
		}
		break;
	}
	while(1)
	{
		printf("\nEnter bemeficiary Address:");
		scanf("%s",new->beneficiary_address);
		if(strlen(new->beneficiary_address)==0)
		{
			printf("\nThis fields can't be empty\n");
			continue;
		}
		else
		{
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
		last->next=new;
		last=new;
		new->next=NULL;
	}
	while(1)
	{
		printf("\nEnter the doses:\n");
		scanf("%d",&ptr->no_of_doses);
		printf("\n successfully vaccinated with %d doses ",ptr->no_of_doses);
		break;
	}


}
int view_beneficiary_data()
{
	if(!start)
	{
		printf("\nNo records found\n");
		return EXIT_FAILURE;
	}
	/*long long int beneficiary_aadharno;
	while(1)
	{
		printf("\nenter aadhar number :\n");
		scanf("%lld",&beneficiary_aadharno);
		if(validate_aadhar(beneficiary_aadharno))
		{
			printf("\nEnter valid aadharnumber\n");
			continue;
		}
		break;
	}*/
	/*for(ptr=start;(ptr)&&ptr->beneficiary_aadharno!=beneficiary_aadharno;ptr=ptr->next);
	if(!ptr)
	{
		printf("\nAadharno %lld not found \n",beneficiary_aadharno);
			return EXIT_FAILURE;
	}*/
	printf("\n aadharnumber   name   phonenumber   address    age   no of doses\n");
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		//if(ptr->beneficiary_aadharno==beneficiary_aadharno)
	printf("\n%lld   %4s  %5lld   %5s  %2d   %d\n",ptr->beneficiary_aadharno,ptr->beneficiary_name,ptr->beneficiary_phno,ptr->beneficiary_address,ptr->beneficiary_age,ptr->no_of_doses);
	}
	return EXIT_SUCCESS;
	
}


int edit_beneficiary_data()
{
	if(!start)
	{
		printf("\nEmpty list\n");
		return EXIT_FAILURE;
	}
	long long int beneficiary_aadharno;
	while(1)
	{
		printf("\nEnter aadhar number for editing:\n");
		scanf("%lld",&beneficiary_aadharno);
		if(validate_aadhar(beneficiary_aadharno))
		{
			printf("\nEnter valid aadharno:\n");
			continue;
		}
		break;
	}
	for(ptr=start;(ptr) && ptr->beneficiary_aadharno!=beneficiary_aadharno;ptr=ptr->next);
	if(!ptr)
	{
		printf("\nAadharno %lld not found\n",beneficiary_aadharno);
		return EXIT_FAILURE;
	}
	while(1)
	{
		printf("\nEnter the doses:\n");
		scanf("%d",&ptr->no_of_doses);
		printf("\n successfully vaccinated with %d doses ",ptr->no_of_doses);
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
		if(validate_aadhar(beneficiary_aadharno))
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
//beneficairy new user
int user_registration()
{
	if((new=(bn *)calloc(1,sizeof(bn)))==NULL)
	{
		printf("\nMemory allocation failure\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		printf("\nEnter beneficiary aadharno :");
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
		printf("\nEnter beneficiary name:");
		scanf("%s",new->beneficiary_name);
		if(alpha_valid(new->beneficiary_name)==0)
		{
			printf("\n Name should have only alphabets");
			continue;
		}
		else
		{
			break;
		}
		break;
	}
	while(1)
	{
		printf("\nEnter beneficiary age:");
		scanf("%d",&new->beneficiary_age);
		if(age_validation(new->beneficiary_age)==0)
			continue;
		else
		{
	
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
			break;
		}
		break;
	}
	while(1)
	{
		printf("\nEnter bemeficiary Address:");
		scanf("%s",new->beneficiary_address);
		if(strlen(new->beneficiary_address)==0)
		{
			printf("\nThis fields can't be empty\n");
			continue;
		}
		else
		{
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
		last->next=new;
		last=new;
		new->next=NULL;
	}
}
int view_user_details()
{
	if(!start)
	{
		printf("\nNo records found\n");
		return EXIT_FAILURE;
	}
	long long int beneficiary_aadharno;
	while(1)
	{
		printf("\nEnter aadhar number :\n");
		scanf("%lld",&beneficiary_aadharno);
		if(validate_aadhar(beneficiary_aadharno))
		{
			printf("\nEnter valid aadharnumber\n");
			continue;
		}
		break;
	}
	for(ptr=start;(ptr)&&ptr->beneficiary_aadharno!=beneficiary_aadharno;ptr=ptr->next);
	if(!ptr)
	{
		printf("\nAadharno %lld not found \n",beneficiary_aadharno);
			return EXIT_FAILURE;
	}
	printf("\n Aadharnumber  name   phonenumber   address   age   no.of doses\n");
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		if(ptr->beneficiary_aadharno==beneficiary_aadharno)
	printf("\n%lld    %4s    %5lld   %10s  %2d    %d\n",ptr->beneficiary_aadharno,ptr->beneficiary_name,ptr->beneficiary_phno,ptr->beneficiary_address,ptr->beneficiary_age,ptr->no_of_doses);
	}
	return EXIT_SUCCESS;
	
}
int edit_user_details()
{
	if(!start)
	{
		printf("\nEmpty list\n");
		return EXIT_FAILURE;
	}
	long long int beneficiary_aadharno;
	while(1)
	{
		printf("\nEnter aadhar number for editiong:\n");
		scanf("%lld",&beneficiary_aadharno);
		if(validate_aadhar(beneficiary_aadharno));
		{
			printf("\nEnter valid aadharno:\n");
			continue;
		}
		break;
	}
	for(ptr=start;(ptr) && ptr->beneficiary_aadharno!=beneficiary_aadharno;ptr=ptr->next);
	if(!ptr)
	{
		printf("\nAadharno %lld not found\n",beneficiary_aadharno);
		return EXIT_FAILURE;
	}
	while(1)
	{
		printf("\nEnter the doses:\n");
		scanf("%d",&ptr->no_of_doses);
		printf("\n successfully vaccinated with %d doses ",ptr->no_of_doses);
		break;
	}
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
		int choice=0;
		long long int beneficiary_aadharno;
		printf("\nEnter aadharno:");
		scanf("%lld",&beneficiary_aadharno);
		printf("\nchoose center:\n");
		printf("\n1.Ward1\n2.Ward2\n3.Ward3\n");
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
				printf("\nCenter2 slected successfully\n");
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
	if(!start)
	{
		printf("\nEmpty records\n");
		return EXIT_SUCCESS;
	}
	printf("\n------Display fully vaccinated beneficiaries------\n");
	printf("\nAadhar Age Gender Center Timeslots shots \n");
	int flag=0;
	long long int  beneficiary_aadharno;
	scanf("%lld",&beneficiary_aadharno);
	//for(beneficiary_aadharno



}
int display_partially_vaccinated_beneficiaries()
{
}
int display_today_vaccinated_beneficiaries()
{
}
int view_details()
{
}



