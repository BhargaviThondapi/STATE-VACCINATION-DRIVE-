#ifndef VACCINATION_DRIVE_HEADER_H
#define VACCINATION_DRIVE_HEADER_H

typedef struct beneficiary
{
	struct beneficiary *next;
	long long int beneficiary_aadharno;
	char beneficiary_name[20];
	long long int beneficiary_phno;
	char beneficiary_address[50];
	int beneficiary_age;
	int beneficiary_id;
	char center[20];
	char password[20];
	int choice;
	int no_of_doses;
}bn;

typedef struct beneficiary_temp
{
	long long int beneficiary_aadharno;
	char beneficiary_name[20];
	long long int beneficiary_phno;
	char beneficiary_address[50];
	int beneficiary_age;
	char center[20];
	char password[20];
	int choice;
	int no_of_doses;
}bt;
//operations performed by beneficairy
int vaccination_beneficiary_login();
int vaccination_admin_login();
int admin_login();
int user_registration();
int edit_user_details();
int view_user_details();
int new_user();
int registered_user();
int select_center();
int book_slot();
int view_details();
int get_vaccinated();
int view_beneficiary_data();
int add_beneficiary_data();
int edit_beneficiary_data();
int delete_beneficiary_data();
int display_fully_vaccinated_beneficiaries();
int display_partially_vaccinated_beneficiaries();
int display_today_vaccinated_beneficiaries();
int new_user();
//prototype for validation functions
int validate_aadhar(long long int num);
int validate_phoneno(long long int num);
int alpha_valid(char *s);
int age_validation(int age);
int gender_validation(char g);


int beneficiary_file_to_list();
int beneficiary_list_to_file();

#endif
