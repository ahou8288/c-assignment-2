#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "snapshot.h"

#define NUM_FUNCTIONS 4

entry* firstEntry;

struct functionList{
        char* name;
	void (*ptr)();
};

void set(char* args[MAX_LINE_LENGTH], int numArgs){	
	//Create the entry to add
	entry* newEntry=malloc(sizeof(entry));
	
	//Add the first value
	value* firstVal=malloc(sizeof(value));
	firstVal->next=NULL;
	firstVal->prev=NULL;
	firstVal->value=2;//sscanf(args[2],"%d");
	//Add subse
	int i=0;
	for (value* index=firstVal;i<numArgs-3;i++,index=index->next){
		value* nextVal=malloc(sizeof(value));
		nextVal->prev=index;
		index->next=nextVal;
		index->value=1;//sscanf(args[i+3],"%d");
	}
	
	memcpy(newEntry->key,args[1],MAX_KEY_LENGTH*sizeof(char));
	
	if (firstEntry==NULL){
		firstEntry=newEntry;
                printf("no keys\n");
        } else {
		entry* index;
		for (index=firstEntry;firstEntry->next!=NULL;index=index->next){
		}
		index->next=newEntry;
		newEntry->prev=index;
		newEntry->next=NULL;
                printf("");
        }
 }

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
	strtok(args[1],"\n"); //removes newline
	if (strcasecmp(args[1],"KEYS")==0){
                listKeys(args,numArgs);
        } else if (strcasecmp(args[1],"ENTRIES")==0){
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
		for (char* p=strtok(userCommand," \n"); p!=NULL; p=strtok(NULL," ") ){
				args[i]=p;
				i++;
		}
		args[0]=strLower(args[0]); //convert command to lowercase
		
		
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

