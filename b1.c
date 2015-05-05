#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "snapshot.h"

#define NUM_FUNCTIONS 2

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

void run(char *args[MAX_LINE_LENGTH],int j){
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
	//myFnc[1].name="set";
        //myFnc[1].ptr=&SET;
        //myFnc[2].name="get";
        //myFnc[2].ptr=&GET;
        //myFnc[3].name="append";
        //myFnc[3].ptr=&append;




//	printf("Command name is %s\n",args[0]);
	for (int i=0; i<NUM_FUNCTIONS; i++){
//		printf("%s --- %s\n",args[0],myFnc[i].name);
		if (strcmp(args[0],myFnc[i].name)==0){
			(myFnc[i].ptr)(args,j);
		}
	}
}

void getCommand(void){
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
	run(args,i);
}

int main(void){
	while (1){
        	getCommand();
	}
        return 0;
}

