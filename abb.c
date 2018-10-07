/* This program is simulating the string that can only end with abb
   if it is not then it will not be accepted
   input sybmols are a and b only
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>

int test(char*);
int check(char*);
char getch(); 

void main(){
    char *string;
    int size;
    int flag;


    printf("\nEnter the size of string ");
    scanf("%d",&size);

    string = malloc(sizeof(char)*(size+1));

    printf("\nEnter the string ");
    scanf("%s",string);

    flag = check(string);  

    if(flag==1){
    if(test(string))
           printf("\n%s is accepted",string);
    else
           printf("\n%s is not accepted",string);
    }else
           printf("\nYour string contain input other than a and b");


    free(string);
    string = NULL;

    getch();
}

int test(char *str){
    int i = 0;
    int current = 1;

    while(str[i]!='\0'){
        
         if(current==1){
		if(str[i]=='a')
			current = 2;
		else
			current = 1;
         }else if(current==2){
                 if(str[i]=='a')
			current = 2;
                 else
			current = 3;
        }else if(current==3){
                 if(str[i]=='a')
			current = 2;
                 else
			current = 4;
       }else if(current==4){
                 if(str[i]=='a')
			current = 2;
                 else
			current = 1;
      }
      
      i++;
   }

   if(current==4)
         return 1;
   else 
	return 0;
}

int check(char *str){
    int i = 0;

    while(str[i]!='\0'){
           if(str[i]=='a' || str[i]=='b')
                      i++;
           else
                  return 0;
   }

    return 1;
}

char getch(){
    /*#include <unistd.h>   //_getch*/
    /*#include <termios.h>  //_getch*/
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    printf("%c\n",buf);
    return buf;
 }
