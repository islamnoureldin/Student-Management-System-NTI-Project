/**********************************************************************************

                    ENG: Islam Nour Eldin

**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define MAX_FATHER_NAME 50
#define MAX_STUDENT_NAME 50
#define MAX_STUDENT_ADDRESS 150
char permission;

typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;

typedef struct student{
    int student_id;
    char studentName[MAX_STUDENT_NAME];
    char fatherName[MAX_FATHER_NAME];
    char studentAddr[MAX_STUDENT_ADDRESS];
    int id,phoneNum,year,day,mons;
	float gpa;
	Date date;
    struct student *next;
}Student_info;

Student_info *head;

void AddStudent(int student_id,int phoneNum,float gpa,char* studentName,char* fatherName,char* studentAddr,int day,int year,int mons)
{
    Student_info *new_Student=(Student_info *)malloc(sizeof(Student_info));
	new_Student->student_id=student_id;
	new_Student->phoneNum=phoneNum;
	new_Student->gpa=gpa;
    new_Student->day=day;
    new_Student->mons=mons;
    new_Student->year=year;

    strcpy(new_Student->studentName,studentName);
    strcpy(new_Student->fatherName,fatherName);
    strcpy(new_Student->studentAddr,studentAddr);
	new_Student->next=NULL;

	if(head == NULL){
		head=new_Student;
	}
	else{
		new_Student->next=head;
		new_Student->student_id=student_id;
	    new_Student->phoneNum=phoneNum;
		new_Student->gpa=gpa;
		new_Student->day=day;
		new_Student->mons=mons;
		new_Student->year=year;

        strcpy(new_Student->studentName,studentName);
        strcpy(new_Student->fatherName,fatherName);
        strcpy(new_Student->studentAddr,studentAddr);
		head=new_Student;
	}
}
void DeleteStudent(int student_id)
{
  Student_info *temp1 = head;
	Student_info *temp2 = head;
	while(temp1 != NULL){
		if(temp1->student_id==student_id){
			printf("\t\t\t\tRecord with id => %d Founded !!!\n", student_id);
			if(temp1 == temp2){
				head = head -> next;
				free(temp1);
			}
			else{
				temp2->next = temp1->next;
				free(temp1);
			}
			printf("\t\t\t\tStudent Successfully Deleted !!!\n");
			return;
		}
		temp2 = temp1;
		temp1 = temp1->next;
	}
	printf("\t\t\t\tStudent with id => %d is not found !!!\n", student_id);
}
void listStudent()
{
 Student_info * temp = head;
	printf("\n\n\tID\tNAME\t\t\tGPA\t\tPHONE\t\tBIRTH-DATE\tADDRESS\n");
    while(temp!=NULL){
        printf("\n\t%d", temp->student_id);
        printf("\t%s %s", temp->studentName,temp->fatherName);
        printf("\t\t%f", temp->gpa);
	    printf("\t%d",temp->phoneNum);
	    printf("\t\t%d/%d/%d",temp->day,temp->mons,temp->year);
		printf("\t%s", temp->studentAddr);

        temp = temp->next;
    }
}
void UpdateStudent(int student_id)
{
 int edit_choice=0;
    Student_info *temp = head;

    while( temp != NULL){

        if(temp->student_id == student_id){

			printf("\t\t\tRecord with id => %d Founded !!!\n", student_id);


        printf("*******************************************************************\n");
        printf("*Which data you want to change?********************************   *\n");
        printf("*  ************************************************************   *\n");
        printf("*  ┇Please enter the function you want to select:             *   *\n");
        printf("*  * 1.All                                                    *   *\n");
        printf("*  * 2.phone                                                  *   *\n");
        printf("*  * 3.GPA                                                    *   *\n");
        printf("*  * 4.Name                                                   *   *\n");
        printf("*  * 5.Address                                                *   *\n");
        printf("*  * 6.Birth_Date                                             *   *\n");
        printf("*  * 7.Exit                                                   *   *\n");
        printf("*  ************************************************************   *\n");
        printf("*                                            Made By:islam nour   *\n");
        printf("*                                                                 *\n");
        printf("*                                                                 *\n");
        printf("*******************************************************************\n");
        printf("\n·Please enter the function you want to select:");
	        scanf("%d",&edit_choice);

	        switch(edit_choice){

		        case 1:

		        	printf("\t\t\tEnter new phone number: ");
                    scanf("%d",&temp->phoneNum);
				    printf("\t\t\t\tEnter new GPA : ");
				    scanf("%f",&temp->gpa);
			        printf("\t\t\t\tEnter new student name: ");
                    scanf("%s",temp->studentName);
			        printf("\t\t\t\tEnter new father name: ");
                    scanf("%s",temp->fatherName);
                    printf("\t\t\t\tEnter new address: ");
                    scanf("\n");
			        scanf("%[^\n]%*c",temp->studentAddr);
			        printf("\t\t\t\tEnter new birth-data (day mons year):\n");
                    scanf("\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d",&temp->day,&temp->mons,&temp->year);

			        printf("\t\t\tUpdation Successful!!!\n");
			        listStudent();
		            break;

		        case 2:
		            printf("Enter new phone number: ");
                    scanf("%d",&temp->phoneNum);
		        	printf("Updation Successful!!!\n");
		        	listStudent();
		            break;

		        case 3:
                    printf("Enter new GPA : ");
				    scanf("%F",&temp->gpa);
					printf("\t\t\tUpdation Successful!!!\n");
					listStudent();

		        case 4:
                    printf("\t\t\t\tEnter new student name: ");
                    scanf("%s",temp->studentName);
			        printf("\t\t\t\tEnter new father name: ");
                    scanf("%s",temp->fatherName);
                    printf("\t\t\t\tEnter new address: ");

                    printf("Updation Successful!!!\n");
		        	listStudent();
		            break;

		        case 5:
                    printf("\t\t\t\tEnter new address: ");
                    scanf("\n");
			        scanf("%[^\n]%*c",temp->studentAddr);

					printf("Updation Successful!!!\n");
		        	listStudent();
					break;

			    case 6:
                    printf("\t\t\t\tEnter new birth-data (day mons year):\n");
                    scanf("\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d",&temp->day,&temp->mons,&temp->year);

					printf("Updation Successful!!!\n");
		        	listStudent();
					break;

		        case 7:
                    exit(1);
		            break;
		        default:
		            printf("\n\t\t---------------Invalid input!! try again-----------------\n");
			}
		return;
		}

		temp = temp->next;
    }
    printf("\t\t\tStudent with id=> %d is not found !!!\n", student_id);
}
void RankStudent()
{
   Student_info * currnode;
    Student_info * nextnode;
    int temp_id,temp_phone,temp_year,temp_mons,temp_day;
	float temp_gpa;
	char temp_studentName[MAX_STUDENT_NAME],temp_fatherName[MAX_FATHER_NAME],temp_studentAddr[MAX_STUDENT_ADDRESS];

    if(head==NULL)
     {
         printf("No data found in the list\n");
     }
     else
     {
         currnode=head;
         while(currnode!=NULL)
         {
             nextnode=currnode->next;
             while(nextnode!=NULL)
             {
                 if(currnode->gpa < nextnode->gpa)
                 {

                    temp_id = currnode->student_id;
                    currnode->student_id=nextnode->student_id;
                    nextnode->student_id=temp_id;

					temp_phone = currnode->phoneNum;
                    currnode->phoneNum=nextnode->phoneNum;
                    nextnode->phoneNum=temp_phone;

					temp_gpa = currnode->gpa;
                    currnode->gpa=nextnode->gpa;
                    nextnode->gpa=temp_gpa;

					temp_day = currnode->day;
                    currnode->day=nextnode->day;
                    nextnode->day=temp_day;

					temp_year = currnode->year;
                    currnode->year=nextnode->year;
                    nextnode->year=temp_year;


					temp_mons = currnode->mons;
                    currnode->mons=nextnode->mons;
                    nextnode->mons=temp_mons;

	                strcpy(temp_studentName,currnode->studentName);
					strcpy(currnode->studentName,nextnode->studentName);
					strcpy(nextnode->studentName,temp_studentName);


                    strcpy(temp_fatherName,currnode->fatherName);
					strcpy(currnode->fatherName,nextnode->fatherName);
					strcpy(nextnode->fatherName,temp_fatherName);

					strcpy(temp_studentAddr,currnode->studentAddr);
					strcpy(currnode->studentAddr,nextnode->studentAddr);
					strcpy(nextnode->studentAddr,temp_studentAddr);

                 }
                 nextnode=nextnode->next;

             }
             currnode=currnode->next;

         }
		 	 listStudent();

     }
}
void student_score()
{
Student_info *temp = head;
   for(int i=0; temp != NULL ;i++){
		printf("\t\t\tid=>%d\n",temp->student_id);
		printf("\t\t\t\tEnter new GPA : ");
	    scanf("%f",&temp->gpa);
		temp = temp->next;
		}
}
void welcomeMessage()
{
    printf("\n\n\n\t\t\t             Loading enter any key to continue.....");
    getch();
}

void menu()
{
head = NULL;
	int choice=0;
    char studentName[MAX_STUDENT_NAME];
    char fatherName[MAX_FATHER_NAME];
	char studentAddr[MAX_STUDENT_ADDRESS];
    int student_id,phoneNum,year,day,mons;
	float gpa;
        do{
        printf("\n\n\n\t\t\tEnter choice => \n");
        printf("\t\t\*******************************************************************\n");
        printf("\t\t\*  ************************************************************   *\n");
        printf("\t\t\*  *Please enter the function you want to select:             *   *\n");
        printf("\t\t\*  * 1.new Student                                            *   *\n");
        printf("\t\t\*  * 2.list Student                                           *   *\n");
        printf("\t\t\*  * 3.Delete Student                                         *   *\n");
        printf("\t\t\*  * 4.Update Student                                         *   *\n");
        printf("\t\t\*  * 5.Rank                                                   *   *\n");
        printf("\t\t\*  * 6.student score                                          *   *\n");
        printf("\t\t\*  * 7.Exit                                                   *   *\n");
        printf("\t\t\*  ************************************************************   *\n");
        printf("\t\t\*                                            Made By:islam nour   *\n");
        printf("\t\t\*                                                                 *\n");
        printf("\t\t\*                                                                 *\n");
        printf("\t\t\*******************************************************************\n");
        printf("\n Please enter the function you want to select:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\t\t\t\tEnter id: ");
            scanf("%d", &student_id);
			printf("\t\t\t\tEnter phone number: ");
            scanf("%d",& phoneNum);
			printf("\t\t\t\tEnter gpa: ");
            scanf("%f",& gpa);
			printf("\t\t\t\tEnter student name: ");
            scanf("%s", studentName);
			printf("\t\t\t\tEnter father name: ");
            scanf("%s", fatherName);
            printf("\t\t\t\tEnter address: ");
            scanf("\n");
			scanf("%[^\n]%*c",studentAddr);
			printf("\t\t\t\tEnter the birth-data (day mons year):\n");
            scanf("\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d",&day,&mons,&year);
            AddStudent(student_id,phoneNum,gpa,studentName,fatherName,studentAddr,day,year,mons);
            break;
        case 2:
            listStudent();
            break;
        case 3:
            DeleteStudent(student_id);
            break;
        case 4:
            UpdateStudent(student_id);
            break;
        case 5:
            RankStudent();
            break;
        case 6:
            student_score();
            break;
        case 7:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }                                            //Switch Ended
    }
    while(choice!=0);                                       //Loop Ended
}
int check_name(char name[]){
	int i,name_len=0;
	int validName=1;
	name_len=strlen(name);
	for(i=0;i<name_len;i++){
	     if(!((name[i]>=65 && name[i]<=90 )||(name[i]>=97 && name[i]<=122))&&(name[i] != '\n')&&(name[i] !=32))
		 {
			validName=0;
			break;
		}
	}
	if(validName==0)
	printf("please enter a valid name\n\n");
	return validName;
}
void login()
{
    char email[30],pass[30];
    printf("\n\t\t\t------------ Student Management System NTI ------------");
    printf("\t\t\t\t\t\n\n");

    printf("\t\t\t\t\t\tEnter Email\t:   ");         scanf("%s",email);
    printf("\n\n\t\t\t\t\t\tEnter Password\t:   ");  scanf("%s",pass);

    if(strcmp(email,"islamgad999@gmail.com")==0 && strcmp(pass,"gadgad999")==0)
    {
        system("CLS");     menu();
    }
    else
    {
      printf("\n\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
      printf("\t\t\t\t\t\t!!! Invalid Email / Password !!!\n\n");
      printf("\t\t\t\t\t\t\tTry Again ? y / n ");  permission = getchar();

      if(permission == 'Y' || permission == 'y')
      {
          system("CLS");    login();
      }
      else
        exit(1);
    }
}
void main()
{
    welcomeMessage();
    login();
}

