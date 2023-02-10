#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TF 20

// Struct for login information
struct system{	
	char user[20];
	char pass[20];
};

// Struct for regist information
struct regist{
	char name[20];
	char lastname[20];
	struct system login; 

};

int login(struct regist client[TF], int tl){
    int i, confirm;
    char user_temp[20], pass_temp[20];
	system("cls");
	
    printf("\n\t\t\tUsername\n");
    printf("\t\t\t _______________\n");
    printf("\t\t\t  ");
    	scanf("%s", user_temp);
    printf("\t\t\t _______________\n");
    printf("\n\t\t\tPassword\n");
    printf("\t\t\t _______________\n");
    printf("\t\t\t  ");
   		scanf("%s", pass_temp);
    printf("\t\t\t _______________\n");
    printf("\n\n\t\t\t1-Confirm   2-Exit");
    printf("\n\n\t\t\t    --> ");
 	   scanf("%d", &confirm);

    if(confirm == 1){
        for(i = 0; i < tl; i++){
            if((strcmp(user_temp, client[i].login.user) == 0) && (strcmp(pass_temp, client[i].login.pass) == 0)){
                return 1;
            }
        }
    }
    else if(confirm == 2){
        return 0;
    }
    return 0;
}

void registration(struct regist client[TF], int &tl){
  struct regist c;
  int i,confirm,ok;
  char confirm_pass[20];
		system("cls");		
	if(tl + 1 >= TF){
		printf("Error: Maximum number of clients reached.");
	}else{
  		printf("\n\n\t\t\tFirst name\n");
 		printf("\t\t\t _______________\n");
 		printf("\t\t\t  ");
 			scanf("%s", c.name);
 			
 		printf("\n\n\t\t\tLast name\n");
 		printf("\t\t\t _______________\n");
		printf("\t\t\t  ");
 			scanf("%s", c.lastname);
 			
 		printf("\n\n\t\t\tUsername\n");
 		printf("\t\t\t _______________\n");
 	    printf("\t\t\t  ");
	   		scanf("%s", &c.login.user);
	   		
		for(i = 0; i < tl; i++){
			if(strcmp(c.login.user, client[i].login.user) == 0){
     			 printf("\n\n\t\t\t[User already exists]");  
     			 printf("\n\t\t\t[Try to login]\n");
     			 printf("\n\t\t\t1-Ok  ->");
     			 	scanf("%d",&ok);
     		
  			}else{	
				printf("\n\n\t\t\tSenha\n");
 				printf("\t\t\t _______________\n");
 				printf("\t\t\t  ");
 					scanf("%s", &c.login.pass);
				
				client[tl]= c;
				tl++;
				
				FILE *arq = fopen("bank_for_login.txt","w");
				for (i=0;i<tl;i++)
				fprintf(arq,"\n%s %s %s %s \n",client[i].name,client[i].lastname,client[i].login.user,client[i].login.pass);
					fclose(arq); 
			
				system("cls");			
				printf("\n\n\t\t\tRegistered Successfully!\n");
				printf("\n\n\t\t\t1-Ok  ->");
					scanf("%d",&ok);			
				system("cls");
		
			}
		}
	}
}

int main(){
	int i,tl=0,option=0,sequence;
	struct regist client[TF];
	char name[20],lastname[20],user[20],pass[20],user_temp[20];

	
	FILE *arq = fopen("bank_for_login.txt", "r");
		if(arq == NULL)
			printf("Error 404 -> unable to open file\n");
		else  {
			while( !feof(arq) ){
			     fscanf(arq,"%s %s %s %s \n",name,lastname,user,pass);
			     strcpy(client[tl].name,name);
			     strcpy(client[tl].lastname,lastname);
			     strcpy(client[tl].login.user,user);
			     strcpy(client[tl].login.pass,pass);				 				 			     
			     tl++;
          	}
	    	fclose(arq);
		}	
		
	while(option!=1){
		system("cls");
		printf("\n      (C) Copyright 2023, WFA Corporation. Todos os direitos reservados.");
		printf("\n\n\n\t\t\t________________________\n");
		printf("\t\t\t       User number\n");
		printf("\t\t\t________________________\n");
		printf("\t\t\t        ********\n");
		printf("\t\t\t________________________\n");
		printf("\n\n\t\t     1-Login   2-Registration   3-Exit");
		printf("\n\n\t\t\t    --> ");
			scanf("%d",&option);
			
		switch (option){
			case 1:	sequence=login(client,tl);
				break;
			case 2: registration(client,tl);
				break;
			case 3: option=1;
				break;
		}
	}
	
	if(sequence==1){
		system("cls");
        printf("\n\t\t\t _______________\n");
        printf("\t\t\t  Login Approved");
        printf("\n\t\t\t _______________\n");	
	
				
	}else{
		system("cls");
        printf("\n\t\t\t _______________\n");
        printf("\t\t\t  Login Denied");
        printf("\n\t\t\t _______________\n");
	}	
		
	return 0;		
}