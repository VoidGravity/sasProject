#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


struct task {

int id;
int Prio;
int deadLine[3];
int deadLineStart [3];

char tages[20];
char title[40];
char desc [400];
char colab[20];


};
struct task holder;

///////////////////:hado 5asahom 5Dma dok functions

int TaskShow (){}
int taskSave () {

    FILE *taskfile = fopen ("Thetasks.txt","a");

    if (taskfile==NULL) {

            printf ("Error 404 : Failed to creat the task");
            return 1;

    }
    srand (time(NULL));
    holder.id=rand()%999+1000;
        //fprintf (taskfile,"test file");
    fprintf (taskfile," %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %s\n %s\n %s\n %s\n ",holder.id,holder.deadLine[0],holder.deadLine[1],holder.deadLine[2],holder.deadLineStart[0],holder.deadLineStart[1],holder.deadLineStart[2],holder.Prio,holder.title,holder.desc,holder.tages,holder.colab);


    fclose (taskfile);

}





int characterCounter (char holder[40],char breaker) {

 for (int i =0;i<40;i++) {
        if (holder[i]==breaker) {
            return i;
        }
 }
}
//i DO NOT NEED MULTIPLE STRUTRES FOR MULTIPLE TASKS ! BUT WHAT ABOUT USERS ? like 3d stuff ?







int main () {

int logOPtions,verification,validEmailSize;
int validEmail=0;
int validEmailDOtcom=0;
int validEmailPreA =0;
int existAcc = 1;
char email[40],password[40],logMail[40],logPass[40],choice[5];



printf (" 1-log in \n 2-Sing in \n");
scanf ("%d",&logOPtions);
if (logOPtions ==1) {
    logIn :
    printf ("\nPLease enter your Email : ");
    scanf ("%s",logMail);
    printf ("\nPLease enter your password : ");
    scanf("%s",logPass);
    //check if password matches the password either lid5l 9Bl or limsjl fdata, leave it for later
    /*
    for (int i = 0; i<40;i++) {
        if (logMail[i]!=email[i]&&logPass[i]!=password[i]) {

            existAcc = 0;
                printf ("\n condition is NOT met");



        }
    }
    */
    if (existAcc) {
        menu :
        system ("cls");
        system ("COLOR A");
        printf ("________________________>>Main Menue!<<_____________________________\n");
        printf ("||\t\t\t\t\t\t\t\t||\n");
        printf ("||\t\t\t\t\t\t\t\t||\n");
        printf ("||\t\t");
        printf ("choice 1: Add Task");
        printf ("\t\t\t\t||\n");
        printf ("||\t\t");
        printf ("choice 2: Edit Task");
        printf ("\t\t\t\t||\n");
        printf ("||\t\t");
        printf ("choice 3: Delate Task");
        printf ("\t\t\t\t||\n");
        printf ("||\t\t");
        printf ("choice 4: Show Task");
        printf ("\t\t\t\t||\n");
        printf ("||\t\t");
        printf ("choice 5: Search Task");
        printf ("\t\t\t\t||\n");
        printf ("||\t\t\t\t\t\t\t\t||\n");
        printf ("||\t\t\t\t\t\t\t\t||\n");
        printf ("||\t\t\t\t\t\t\t\t||\n");
        printf ("________________________>>Select a Choice!<<________________________\n");
        printf ("My choice is : ");
        scanf (" %1c",&choice[0]);

        switch (choice[0]){
            case '1':
                system ("cls");
                printf ("________________________>>Add Task!<<_____________________________\n");
                printf ("\n\n\n");
                printf ("Add the Title : ");
                scanf (" %s",holder.title);
                printf ("\nAdd the description : ");
                scanf (" %s",holder.desc);
                printf ("\nenter the deadline (Year/months/days) : ");
                scanf (" %d/%d/%d",&holder.deadLine[0],&holder.deadLine[1],&holder.deadLine[2]);
                printf ("\nenter a starting date (Year/months/days) or leave blank to start the task now : ");
                scanf (" %d/%d/%d",&holder.deadLine[3],&holder.deadLine[4],&holder.deadLine[5]);
                printf ("\nAdd a priority (or leave blank for low priority): \n choice 1 : critical priority \n choice 2 : high priority \n choice 3 : natural priority \n choice 4 : low priority\n");
                scanf (" %d",&holder.Prio);
                printf ("\nAdd tags : ");
                scanf (" %s",holder.tages);
                printf ("\nAdd a the colaborator's email (Leave Blank for no colaborator):");
                scanf (" %s",holder.colab);

                taskSave ();

                printf ("\nThe task : %s was added succsefully\n choice A:Main menue \n choice B:exit the program \n my choice : ",holder.title);
                scanf(" %1c",&choice[1]);

                if (choice [1]=='A'||choice [1]=='a') goto menu;
                else if (choice [1]=='B'||choice [1]=='b') return 0;
                else printf ("invalid choice");





                //if task is created





                //ana hna , the idea is to create a 2d array and once you successfully scanned the tiitle , incriment the value of the collumn
                //switched that Idea Up with a simple strcuture , turns out structures are pretty cool ,but don't worry arrays , daddy still love you





                break;
            case '2':
                system ("cls");
                printf ("________________________>>Edit Task!<<_____________________________\n");break;

            case '3':
                system ("cls");
                printf ("________________________>>Delate Task!<<_____________________________\n");break;
            case '4':
                system ("cls");
                printf ("________________________>>Show Task!<<_____________________________\n");break;
            case '5':
                system ("cls");
                printf ("________________________>>Search Task!<<_____________________________\n");break;
            default :
            printf ("\nYour choice is not valid,try again 3s...");
            Sleep (3000);
            goto menu;
        }







    }


}

//I'm here on acount creation step
else if (logOPtions==2) {
    printf ("\nPlease enter your email : ");
    emailFailed :
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
        passwordFailed :
        scanf ("%s",password);
    //CHECK IF PASWORD IS VALID
    //THIS STEP IS DONE , possible bugs are just character lenght

    if (characterCounter (password,'\0')>7) {
            FILE *sendVerification = fopen ("VerificationCode.txt","w");
            srand (time(NULL));
            int tempVerification = rand()%9000+ 1000;
            fprintf (sendVerification,"%d",tempVerification);
            fclose (sendVerification);
            printf ("\nPlease enter the verification code you've got : ");
            verificationFailed :
            scanf ("%d",&verification);
            if (tempVerification==verification)  {
                printf ("Congratulations! you're account is ready to go");
                goto logIn;

            } else {

                printf ("wrong verification code,try again : ");
                goto verificationFailed;


                }
    } else {

        printf("\nyour password is too weak,try another password : ");
        goto passwordFailed;


        }
    } else {

        printf ("\nPlease enter a valid email : ");
        goto emailFailed;



        }



} else printf ("your choice is not valid");


}
