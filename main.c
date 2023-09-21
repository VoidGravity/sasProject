#include <stdio.h>
#include <windows.h>


int characterCounter (char holder[40],char breaker) {

 for (int i =0;i<40;i++) {
        if (holder[i]==breaker) {
            return i;
        }
 }
}


int main () {

int logOPtions,verification,validEmailSize;
int validEmail=0;
int validEmailDOtcom=0;
int validEmailPreA =0;
char email[40],password[40];


printf (" 1-log in \n 2-Sing in \n");
scanf ("%d",&logOPtions);
if (logOPtions ==1) {}

//I'm here on acount creation step
else if (logOPtions==2) {
    printf ("\nPlease enter your email : ");
    scanf ("%s",email);
    //CHECK IF EMAIL IS VALID
    // EMAIL CHECK IS DONE but possible bugs are email lenght
    for (int i =0;i<40;i++) {
        if (email[i]=='@') {
            validEmail=1;
            validEmailSize=i;
            i++;
            }
        if (validEmail&(email[i]>48&&email[i]<58)||(email[i]>64&&email[i]<91)||(email[i]>96&&email[i]<122)&&email[i+1]!='\0') {
            i++ ;
            printf ("\nSTEP 2 REACHED");
            validEmailPreA=1;
             if (email[i]=='.'&&email[i+1]!='\0') {
                printf ("\nSTEP 3 workd");
                validEmailDOtcom=1;
                //adnaneothmane@gmail.com
            }
        }
}

    if (validEmail &&validEmailPreA&&validEmailDOtcom &&validEmailSize>0) {
        printf ("\nPlease choose a password (The password should be consisted of 8 numbers or more):  ");
        scanf ("%s",password);
    //CHECK IF PASWORD IS VALID
    //THIS STEP IS DONE , possible bugs are just character lenght

    if (characterCounter (password,'\0')>7) {
            printf ("\nPlease enter the verification code you've got : ");
            scanf ("%d",&verification);
    } else printf("your password is too weak");
    } else printf ("\nPlease enter a valid email : ");



}

else printf ("your choice is not valid");



}
