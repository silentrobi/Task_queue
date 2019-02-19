//
// Created by MOHAMMAD ABU MUSA RABIUL on 28-Oct-18.
// ID:  220201072
//


#include <stdio.h>
#include "taskqueue.h"
#include<ctype.h>
#include <string.h>

int checkNumber(char* s);
void precheck(char* s, int size);

int main(int argc, char *argv[]){
    int n;
    precheck(argv[1],argc);// check input
    n= atoi(argv[1]); // converting string to integer
    manageTasks(n);
    return 0;


}

int checkNumber(char * s){
    int i=0;
    if(s[0]== '-'){
        for(i=1;i< strlen(s);i++){
            if (!isdigit(s[i])) return 0;
        }
        return 1;
    }
    else{
        for(;i< strlen(s);i++){
            if (!isdigit(s[i])) return 0;
        }
        return 1;
    }

}

void precheck(char* s, int size){
    if ( size<2){
        printf("%s\n","ERROR: too few arguments.");
        exit(1);
    }
    if (size >2){
        printf("%s\n","ERROR: too many arguments.");
        exit(1);

    }

    if(!checkNumber(s)) {

        printf("%s\n","ERROR: argument is not a number.");
        exit(1);

    }
    if( atoi(s) < 0 ){
        printf("%s\n","ERROR: argument is less than zero.");
        exit(1);
    }
}
