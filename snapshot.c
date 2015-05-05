#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "snapshot.h"

#define NUM_FUNCTIONS 2

entry* firstEntry;

struct functionList{
        char* name;
	void (*ptr)();
};

void listKeys(char* args[MAX_LINE_LENGTH], int numArgs){
	if (firstEntry==NULL){
		printf("no keys\n");
	} else {
		printf("");
	}
}

void listEntries(char* args[MAX_LINE_LENGTH], int numArgs){
        if (firstEntry==NULL){
                printf("no entries\n");
        } else {
                printf("");
        }
}

void list(char* args[MAX_LINE_LENGTH], int numArgs){
        if (strcmp(args[2],"KEYS")){
                listKeys(args,numArgs);
        } else if (strcmp(args[2],"ENTRIES")){
                listEntries(args,numArgs);
        }
}


void get(char* args[MAX_LINE_LENGTH], int numArgs){
	if (firstEntry==NULL){
		printf("no such key\n");
	} else {
		printf("");
	}
}

void help(void){
        printf("%s",HELP);
}

void bye(){
        printf("bye\n");
        exit(0);
}

char* strLower(char* inString){
        for (int i=0; inString[i];i++){
                inString[i] = tolower(inString[i]);
        }
        return inString;
}

int main(void){
	firstEntry=NULL; //Set the pointer to null	
        while (1){
		//GET FUNCTION
		printf("> ");
		char userCommand[MAX_LINE_LENGTH];
		fgets(userCommand,MAX_LINE_LENGTH,stdin);
		char *args[MAX_LINE_LENGTH];
		int i=0;
		for (char* p=strtok(userCommand," "); p!=NULL; p=strtok(NULL," ") ){
				args[i]=p;
				i++;
		}
		args[0]=strLower(args[0]); //convert command to lowercase
		strtok(args[0],"\n"); //removes a trailing newline if one exists
		
		
		//RUN FUNCTION
		//Create a list of function names and function pointers
		//Run the function with the arguments

		struct functionList{
				char* name;
				void (*ptr)();
		};

		struct functionList myFnc[NUM_FUNCTIONS];

		myFnc[0].name="bye";
		myFnc[0].ptr=&bye;
		myFnc[1].name="help";
		myFnc[1].ptr=&help;
		myFnc[2].name="list";
                myFnc[2].ptr=&list;
                myFnc[3].name="get";
                myFnc[3].ptr=&get;

	        //printf("Command name is %s\n",args[0]);
		for (int i2=0; i2<NUM_FUNCTIONS; i2++){
	                //printf("%s --- %s\n",args[0],myFnc[i].name);
			if (strcmp(args[0],myFnc[i2].name)==0){
				(myFnc[i2].ptr)(args,i);
			}
		}
        }
        return 0;
}

