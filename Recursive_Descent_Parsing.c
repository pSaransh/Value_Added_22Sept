#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char token;
int lookahead=0;
char *string;
void accept();
void reject();
char getToken();
void fA();
void fB();
void fS();
void accept(){
    printf("%s\n","Sucessfully Parsed");
}
void reject(){
    printf("%s\n","Error in Parsing");
}

char getToken(){
    lookahead+=1;
    return string[lookahead];
}
void fA(){
    if(token == 'b'){
        token=getToken();
        if(token == 'a')
            token=getToken();
        else{
            reject();
            exit(1);
        }
    }
    else if (token == 'a' || token == 'c'){
        fS();
        fB();
    }
    else{
        reject();
        exit(1);
    }
}
void fB(){
     if(token == 'b'){
        token=getToken();
        fA();
     }
    else if(token == 'a' ||  token == 'c')
        fS();
    else{
        reject();
        exit(1);
    }
}

void fS(){
    if(token == 'a'){
        token=getToken();
        fA();
        fS();
    }
    else if(token == 'c')
        token=getToken();
    else{
        reject();
        exit(1);
    }
}
int main() {
    char ch[40];
    scanf("%s",ch);
    string=strcat(ch,"$");
    token=string[0];
     fS();
    if(token == '$')
        accept();
    else
        reject();
   
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
