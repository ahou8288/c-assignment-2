#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "snapshot.h"

void run(char *args[MAX_LINE_LENGTH],int j){
	//Just prints the argumnets
	for (int i=0;i<j;i++){
		printf("%s\n",args[i]);
	}
}

void getCommand(void){
        char userCommand[MAX_LINE_LENGTH];
        fgets(userCommand,MAX_LINE_LENGTH,stdin);
	char *args[MAX_LINE_LENGTH];
	int i=0;        
	for (char* p=strtok(userCommand," "); p!=NULL; p=strtok(NULL," ") ){
		args[i]=p;
		i++;
	}
	run(args,i);
}

int main(void){
	while (1){
        	getCommand();
	}
        return 0;
}

