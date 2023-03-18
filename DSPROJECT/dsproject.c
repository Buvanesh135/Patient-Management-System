#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct patient{
	char id[10];
	char patientname[30];
	char address[40];
	char disease[30];
	char gender[10];
	char room_no[4];
	char age[4];
	long int totalamount;
	long int deposited;
	long int pending;
	char date[10];
};
void welcomeMessage()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =                  HOSPITAL                 =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    //getchar();
}
void addpatient()
{
	 int ch;
	  scanf("%d",&ch);
	   	struct patient p;
	   	FILE *fp;
	   	 FILE *fp1;
	  while(ch)
	  {
	  	 printf("1.Emergencypateint\n2.outpatient\n");
	  	 printf("enter the choice:");
	  	 scanf("%d",&ch);
	  	 switch(ch)
	  	 {
	  	 	case 0:
	  	 		 break;
	  	 	case 1:
				  	fp=fopen("emergencypatient.txt","a");
					if(fp==NULL)
					   printf("file not exist");
					 printf("enter the details..");
					 	 printf("\nenter patient id:");
					 	 fflush(stdin);
					 	 gets(p.id);
					 	 printf("\nenter patient name:");
					 	 fflush(stdin);
					 	 gets(p.patientname);
					 	 printf("\nenter patient address:");
					     fflush(stdin);
					 	 gets(p.address);
						printf("\nenter patient disease:");
					 	fflush(stdin);
					 	 gets(p.disease);
					 	 	printf("\nenter patient gender:");
					 	fflush(stdin);
					 	 gets(p.gender);
					 	 	printf("\nenter patient age:");
					 	fflush(stdin);
					 	 gets(p.age);
					 	 	printf("\nenter patient room no:");
					 	fflush(stdin);
					 	 gets(p.room_no);
					 	 printf("\nenter patient totalamount no:");
					 	fflush(stdin);
					 	 scanf("%ld",&p.totalamount);
					 	 printf("\nenter patient deposited no:");
					 	fflush(stdin);
					 	 scanf("%ld",&p.deposited);
					 	p.pending=p.totalamount-p.deposited;
						 printf("\nenter date:");
					 	fflush(stdin);
					 	 gets(p.date);					 	 
					   fwrite(&p,sizeof(p),1,fp);
					   fclose(fp);
					   fp1=fopen("patient.txt","a");
					   fwrite(&p,sizeof(p),1,fp1);
					   fclose(fp1);
				  	 		break;
	  	 	case 2:
			fp=fopen("outpatient.txt","a");
			if(fp==NULL)
			 printf("file not exist");
			 printf("enter the details..");
			 	 printf("\nenter patient id:");
			 	 fflush(stdin);
			 	 gets(p.id);
			 	 printf("\nenter patient name:");
			 	 fflush(stdin);
			 	 gets(p.patientname);
			 	 printf("\nenter patient address:");
			     fflush(stdin);
			 	 gets(p.address);
				printf("\nenter patient disease:");
			 	fflush(stdin);
			 	 gets(p.disease);
			 	 	printf("\nenter patient gender:");
			 	fflush(stdin);
			 	 gets(p.gender);
			 	 	printf("\nenter patient age:");
			 	fflush(stdin);
			 	 gets(p.age);
			 	 	printf("\nenter patient room no:");
			 	fflush(stdin);
			 	 gets(p.room_no);
			 	 printf("\nenter patient totalamount no:");
					 	fflush(stdin);
					 	 scanf("%ld",&p.totalamount);
					 	 printf("\nenter patient deposited no:");
					 	fflush(stdin);
					 	 scanf("%ld",&p.deposited);
					 	 p.pending=p.totalamount-p.deposited;
					 	  printf("\nenter date:");
					 	fflush(stdin);
					 	 gets(p.date);
			   fwrite(&p,sizeof(p),1,fp);
			   fclose(fp);
			   fp1=fopen("patient.txt","a");
			   fwrite(&p,sizeof(p),1,fp1);
			   fclose(fp1);
	  	 		 break;
	  	 	default:
	  	 		printf("enter valid option");
	  	 		break;
	     }
	  }
	
}
void listallpatient()
{
	
	FILE *fp;
		struct patient p;
		int i;
		 printf("<====================================================================================================Patient List ==================================================================== ==>\n\n");
    
    printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "Id", "Patient Name", "Address", "Disease", "age","gender","roomno","totalamount","deposited","pending","Date");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    fp = fopen("patient.txt", "rb");
    if(fp==NULL)
		 printf("file not exist");
    while(fread(&p, sizeof(p), 1, fp) == 1){
        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15ld %-15ld %-15ld %-15s\n", p.id, p.patientname, p.address, p.disease, p.age,p.gender,p.room_no,p.totalamount,p.deposited,p.pending,p.date);
    }

    fclose(fp);

}
void listemergencypatient()
{
		FILE *fp;
		struct patient p;
		int i;
		  printf("<============================================================================================== Patient List==================================================================== ==>\n\n");
    
    printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "Id", "Patient Name", "Address", "Disease", "age","gender","roomno","totalamount","deposited","pending","Date");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    fp = fopen("emergencypatient.txt", "rb");
    if(fp==NULL)
		 printf("file not exist");
    while(fread(&p, sizeof(p), 1, fp) == 1){
        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15ld %-15ld %-15ld %-15s\n", p.id, p.patientname, p.address, p.disease, p.age,p.gender,p.room_no,p.totalamount,p.deposited,p.pending,p.date);
    }

    fclose(fp);

	
}
void listbasedondates()
{
	FILE *fp;
		struct patient p;
		int i=1;
		char date[10];
		scanf("%s",date);
		  printf("<===================================================================== Patient List==================================================================== ==>\n\n");
    
    fp = fopen("patient.txt", "rb");
    if(fp==NULL)
		 printf("file not exist");
    while(fread(&p, sizeof(p), 1, fp) == 1){
    	if(strcmp(p.date,date)==0)
    	{
    		printf("\n\nrecordfound\n\n");
    		i=0;
    		printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "Id", "Patient Name", "Address", "Disease", "age","gender","roomno","totalamount","deposited","pending","Date");
          printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15ld %-15ld %-15ld %-15s\n", p.id, p.patientname, p.address, p.disease, p.age,p.gender,p.room_no,p.totalamount,p.deposited,p.pending,p.date);
    }
}
    if(i==1)
     printf("\nNO record found\n\n");

    fclose(fp);
}
void listpatient()
{
	int ch;
	  scanf("%d",&ch);
	  while(ch)
	  {
	  printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=");
    printf("\n\t\t\t        =                  1.ListALLPatient                            =");
    printf("\n\t\t\t        =                  2.listemergencypatient                      =");
    printf("\n\t\t\t        =                  3.listoutpatient                            =");
    printf("\n\t\t\t        =                  4.listpatientinaonDates                     =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-==-=-==-=-");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    //printf("\n\n\n\t\t\t Enter any key to continue.....");
	  	 printf("\nenter the choice:");
	  	 scanf("%d",&ch);
	  	 switch(ch)
	  	 {
	  	 	case 1:
	  	 		listallpatient();
	  	 		break;
	  	 	case 2:
	  	 		 listemergencypatient();
	  	 		 break;
	  	 	case 3:
	  	 		listoutpatient();
	  	 		break;
	  	 	case 4:
	  	 		 listbasedondates();
	  	 		 break;
	  	 	default:
	  	 		printf("enter valid option");
	  	 		break;
	    }
     }
}

void listoutpatient()
{
		FILE *fp;
		struct patient p;
		int i;
		  printf("<====================================================================================================Patient List ==================================================================== ==>\n\n");
    
    printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "Id", "Patient Name", "Address", "Disease", "age","gender","roomno","totalamount","deposited","pending","Date");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    fp = fopen("outpatient.txt", "rb");
    if(fp==NULL)
		 printf("file not exist");
    while(fread(&p, sizeof(p), 1, fp) == 1){
        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15ld %-15ld %-15ld %-15s\n", p.id, p.patientname, p.address, p.disease, p.age,p.gender,p.room_no,p.totalamount,p.deposited,p.pending,p.date);
    }

    fclose(fp);
	
}
void searchpatient()
{
	    char name[30];
		FILE *fp;
		struct patient p;
		int f=1;
		fp = fopen("patient.txt", "rb");
		printf("enter the patient name:");
		 scanf("%s",name);
		 while(fread(&p, sizeof(p), 1, fp) == 1){
		 	 if(strcmp(p.patientname,name)==0)
		 	 {
		 	 	    printf("\nrecord found\n\n");
		 	 	    f=0;
		 	 	    printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "Id", "Patient Name", "Address", "Disease", "age","gender","roomno","totalamount","deposited","pending");
                     printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                      printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15ld %-15ld %-15ld\n", p.id, p.patientname, p.address, p.disease, p.age,p.gender,p.room_no,p.totalamount,p.deposited,p.pending);
            }
        }
            if(f==1)
             printf("\nno record found\n\n");
    fclose(fp);
		
	
}

int main()
{
	welcomeMessage();
	  int ch;
	  scanf("%d",&ch);
	  while(ch)
	  {
	  printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  1.addpatient                        =");
    printf("\n\t\t\t        =                  2.listpatient                       =");
    printf("\n\t\t\t        =                  3.searchpatient                     =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    //printf("\n\n\n\t\t\t Enter any key to continue.....");
	  	 printf("\nenter the choice:");
	  	 scanf("%d",&ch);
	  	 switch(ch)
	  	 {
	  	 	case 1:
	  	 		addpatient();
	  	 		break;
	  	 	case 2:
	  	 		 listpatient();
	  	 		 break;
	  	 	case 3:
	  	 		 searchpatient();
	  	 		 break;
	  	 	default:
	  	 		printf("enter valid option");
	  	 		break;
	     }
	  }
		 return 0;
}
