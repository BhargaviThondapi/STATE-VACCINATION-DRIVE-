/************************************************************************************************************
* * FILE NAME 			: vaccination_drive_func1.c
* * DESCRIPTION 		: This file consists of file_to_list and list_to_file
					operations for beneficiary and admin details
*
* ****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "vaccination_drive_header.h"
extern  bn *start,*new,*ptr,*prev,*last;
/*int count_digits(long long int num)
{
	int count=0;
	if(isdigit(num))
	{
		while(num!=0)
		{
			num=num/10;
			count++;
		}
	}
		return count;
}*/
int validate_aadhar(long long int num)
{
	if(num< 100000000000||num >999999999999)
	{
		printf("\nInvalid length.length should only of 12 digits.\n");
		return 1;
	}
	return 0;
}
int validate_phoneno(long long int num)
{
	if(num < 1000000000 ||num>9999999999)
	{
		printf("\nInvalid length.length should only of 10 digits.\n");
		return 1;
	}
	return 0;
}
int alpha_valid(char *s)
{
	for(char *p=s;(*p);p++)
	{
		if(isalpha(*p))
			return 1;
	}
	return 0;

}
int age_validation(int age)
{
	int y;
	if(age >= 18 && age <= 100)
	{
		if(age >= 35)
		{
			printf("Clearance from doctor");
			printf("\n1.For yes,enter 1\n2.For no,enter 0\n");
			scanf("%d",&age);
			if(y == 0)
			{
				printf("Doctor clearance needed Registration not completed");
				return 0;
			}
		}
		return 1;
	}
	else
	{
		printf("not for this age registration not completed");
		return 0;
	}
	return 1;

}
int gender_validation(char g)
{
	if (g == 'M' || g == 'F' || g == 'O')
	{
		return 1;
	}
	else
	{
		printf("Invalid gender");
		return 0;
	}
	return 1;
}
int beneficiary_file_to_list()
{
	FILE *pc;
	bt c1;
	if((pc=fopen("beneficiary.data","rb"))==NULL)
	{
		printf("\n File is not found\n");
		return EXIT_FAILURE;
	}
	fread(&c1,sizeof(bt),1,pc);
	while(!feof(pc))
	{
		if((new=(bn *)calloc(1,sizeof(bt)))==NULL)
		{
			printf("\n Memory allocation failed\n");
			return EXIT_FAILURE;
		}
		new->beneficiary_aadharno=c1.beneficiary_aadharno;
		strcpy(new->beneficiary_name,c1.beneficiary_name);
		strcpy(new->beneficiary_address,c1.beneficiary_address);
		new->beneficiary_phno=c1.beneficiary_phno;
		//strcpy(new->select_centre,c1.select_centre);
		strcpy(new->password,c1.password);
		if(!start)
		{
			start = last = new;
			new->next=NULL;
		}
		else
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}
		fread(&c1,sizeof(bt),1,pc);
	}
	fclose(pc);
	return EXIT_SUCCESS;
}
int beneficiary_list_to_file()
{
	bt c2;
	if(!start)
	{
		printf("\n The list is empty\n");
		return EXIT_FAILURE;
	}
	FILE *pc;
	if((pc=fopen("beneficiary.data","wb"))==NULL)
	{
		printf("\n File is not found\n");
		return EXIT_FAILURE;
	}
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		c2.beneficiary_aadharno=ptr->beneficiary_aadharno;
		strcpy(c2.beneficiary_name,ptr->beneficiary_name);
		strcpy(c2.beneficiary_address,ptr->beneficiary_address);
		c2.beneficiary_phno=ptr->beneficiary_phno;
		//strcpy(c2.select_centre,ptr->select_centre);
		strcpy(c2.password,ptr->password);
		fwrite(&c2,sizeof(bt),1,pc);
	
	}
	for(ptr=start;(ptr);prev=ptr,ptr=ptr->next)
	{
		free(prev);
	}
	free(prev);
	fclose(pc);
	return EXIT_SUCCESS;
}
