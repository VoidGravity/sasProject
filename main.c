#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//use the char counter to count how many characters in the desc , make it usefull


typedef struct{


int id;
char Prio;
int deadLine[3];
int deadLineStart [3];


char tages[20];
char title[40];
char desc [400];
char colab[40];


}task;
task holder;
task stuff[300];
task temp;

char choice[10];

///////////////////////////////////I HAAAATe.............. gonna take a pause


int tasksize=0;
int lastthree = 0;

///////////////////:hado 5asahom 5Dma dok functions


int taskSave () {

    FILE *taskfile = fopen ("Thetasks.txt","a");

    if (taskfile==NULL) {

            printf ("Error 404 : Failed to create the task");
            return 404;

    }
    srand (time(NULL));

    holder.id=rand()%999+1000;
        //fprintf (taskfile,"test file");
    fprintf (taskfile,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%s\n%s\n%s\n%s\n",holder.id,holder.deadLine[0],holder.deadLine[1],holder.deadLine[2],holder.deadLineStart[0],holder.deadLineStart[1],holder.deadLineStart[2],holder.Prio,holder.title,holder.desc,holder.tages,holder.colab);


    fclose (taskfile);
}

int timediff( int tc){

time_t timsec = time(NULL);
struct tm mytime = *localtime(&timsec);

int deadLineTotal = (stuff[tc].deadLine[2]+(stuff[tc].deadLine[1] * 30) + (stuff[tc].deadLine[0] * 365) );
int cday = mytime.tm_mday;
int cmonth = mytime.tm_mon + 1;
int cyear = mytime.tm_year + 1900;

int ctottal = cday+(cmonth*30)+(cyear*365);

return deadLineTotal-ctottal;


}


int TaskShow(char yourchoice) {

    FILE *taskfile = fopen("Thetasks.txt", "r");

    if (taskfile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }


    while (fscanf(taskfile, " %d", &stuff[tasksize].id) != EOF) {
        fscanf(taskfile, " %c", &stuff[tasksize].Prio);
        for (int j = 0; j < 3; j++) {
            fscanf(taskfile, "%d", &stuff[tasksize].deadLine[j]);
        }
        for (int j = 0; j < 3; j++) {
            fscanf(taskfile, "%d", &stuff[tasksize].deadLineStart[j]);
        }
        fscanf(taskfile, " %39[^\n]", stuff[tasksize].title);
        fscanf(taskfile, " %399[^\n]", stuff[tasksize].desc);
        fscanf(taskfile, " %19s", stuff[tasksize].tages);
        fscanf(taskfile, " %39[^\n]", stuff[tasksize].colab);

        tasksize++;
        if (choice[6]=='5') {
            lastthree = tasksize-3;
            if (lastthree<0) lastthree = 0;
        }

    }

    fclose(taskfile);

    // this is where I sort the taskss
        //alpha
         if (choice[6]== '1') {

            for (int i = 0;i <tasksize;i++) {
                    for (int k=0; k<tasksize-i-1;k++) {
                        if (strcmp(stuff[k].title,stuff[k+1].title)>0) {

                            temp= stuff[k];
                            stuff[k] = stuff[k+1];
                            stuff[k+1]= temp;
                        }
                    }
                }

            }
        //creation date
         else if (choice[6]== '4') {


            goto prnt;

         }
         //priority
         else if (choice[6]=='3') {

            for (int i = 0;i <tasksize;i++) {
                    for (int k=0; k<tasksize-i-1;k++) {

                        if (stuff[k].Prio>stuff[k+1].Prio) {

                            temp= stuff[k];
                            stuff[k] = stuff[k+1];
                            stuff[k+1]= temp;
                        }
                    }
                }
         }
         // still choice 2 deadline anc choice 5 3 days
         //deadline 2
         else if (choice[6]=='2'||choice[6]=='5' ) {
           // task = 9 ; task = 3 ; task - somthing = 9-5 so they need to be 3 apart

            for (int i = 0;i <tasksize;i++) {
                    for (int k=0; k<tasksize-i-1;k++) {

                        if (stuff[k].deadLine[0]>stuff[k+1].deadLine[0]) {

                            temp= stuff[k];
                            stuff[k] = stuff[k+1];
                            stuff[k+1]= temp;
                            }
                        else if (stuff[k].deadLine[0]==stuff[k+1].deadLine[0]) {
                                if (stuff[k].deadLine[1]>stuff[k+1].deadLine[1]) {
                                        temp= stuff[k];
                                        stuff[k] = stuff[k+1];
                                        stuff[k+1]= temp;
                                }
                                    else if (stuff[k].deadLine[1]==stuff[k+1].deadLine[1]) {

                                        if (stuff[k].deadLine[2]>stuff[k+1].deadLine[2]) {

                                            temp= stuff[k];
                                            stuff[k] = stuff[k+1];
                                            stuff[k+1]= temp;
                                         }

                                    }

                                }

                        }


             }
          }
          //deadline 3 days (6)
           if (choice[6]== '6') {

                  for (int k=0; k<tasksize;k++) {
                        printf ("lopp enetered");
                     if (timediff(k)<=3 && timediff(k)>0 ) {

                            printf("\nTitle: %s\n", stuff[k].title);
                            printf("ID: %d\n", stuff[k].id);
                            printf("Priority: %c\n", stuff[k].Prio);
                            printf("Deadlines: %d %d %d\n", stuff[k].deadLine[0], stuff[k].deadLine[1], stuff[k].deadLine[2]);
                            printf("DeadlineStarts: %d %d %d\n", stuff[k].deadLineStart[0], stuff[k].deadLineStart[1], stuff[k].deadLineStart[2]);
                            printf("Description: %s\n", stuff[k].desc);
                            printf("Tags: %s\n", stuff[k].tages);
                            printf("Collaborators: %s\n", stuff[k].colab);

                            }
                        }
                 return 0;
          }


//                if (timediff[k]<=3 && timediff[k]>0 ) {
//
//
//                }



        prnt :
    for (int k = 0; k < tasksize-lastthree; k++) {

        printf("\nTitle: %s\n", stuff[k].title);
        printf("ID: %d\n", stuff[k].id);
        printf("Priority: %c\n", stuff[k].Prio);
        printf("Description: \n%s\n", stuff[k].desc);
        printf("Tags: %s\n", stuff[k].tages);
        printf("Collaborators: %s\n", stuff[k].colab);
        printf("Deadlines: %d\%d\%d\n", stuff[k].deadLine[0], stuff[k].deadLine[1], stuff[k].deadLine[2]);
        printf("DeadlineStarts: %d\%d\%d\n", stuff[k].deadLineStart[0], stuff[k].deadLineStart[1], stuff[k].deadLineStart[2]);


    }
            printf("\nTotal Tasks: %d\n",tasksize);

}






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
int existAcc = 1;
char email[40],password[40],logMail[40],logPass[40];



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
        scanf (" %s",&choice[0]);

        switch (choice[0]){
            case '1':
                newtask:
                system ("cls");
                printf ("________________________>>Add Task!<<_____________________________\n");
                printf ("\n\n\n");
                printf ("Add the Title : ");
                scanf (" %[^\n]s",holder.title);
                printf ("\nAdd the description: ");
                scanf (" %[^\n]s",holder.desc);


                //here you do desctiption stuff


                printf ("\nenter the deadline (Year/months/days) : ");
                deadLine:
                scanf (" %d/%d/%d",&holder.deadLine[0],&holder.deadLine[1],&holder.deadLine[2]);
                if (holder.deadLine[0]<0 || holder.deadLine[1]<0||holder.deadLine[1]>12 ||holder.deadLine[2]<0 || holder.deadLine[2]>31) {

                    printf ("Invalid date,try again : ");
                    goto deadLine;
                }
                printf ("\nenter a starting date (Year/months/days) or leave blank to start the task now : ");
                deadLineStart:
                scanf (" %d/%d/%d",&holder.deadLineStart[0],&holder.deadLineStart[1],&holder.deadLineStart[2]);
                if (holder.deadLineStart[0]<0 || holder.deadLineStart[1]<0||holder.deadLineStart[1]>12 ||holder.deadLineStart[2]<0 || holder.deadLineStart[2]>31) {

                    printf ("Invalid date,try again : ");
                    goto deadLineStart;
                }
                printf ("\nAdd a priority (or leave blank for low priority): \n choice 1 : critical priority \n choice 2 : high priority \n choice 3 : natural priority \n choice 4 : low priority\n");

                printf ("\nMy choice : ");

                priority:

                scanf (" %c",&holder.Prio);

                if (holder.Prio<49||holder.Prio>52) {

                    printf ("\n Invalid choice,try again : ");

                    goto priority;
                }

                printf ("\nAdd tags : ");
                scanf (" %[^\n]s",holder.tages);
                printf ("\nAdd a the colaborator's email (enter 'N' for no colaboration):");
                scanf (" %s",holder.colab);

                taskSave ();

                printf ("\nThe task : %s was added succsefully\n choice A:Main menue \n choice B:exit the program \n choice C:Add New Task \n my choice : ",holder.title);
                MainORexit:
                scanf(" %c",&choice[1]);

                if (choice [1]=='A'||choice [1]=='a') goto menu;
                else if (choice [1]=='B'||choice [1]=='b') return 0;
                else if (choice [1]=='C'||choice [1]=='c') goto newtask;
                else {
                        printf ("Invalid Choice!\n try again : ");
                        goto MainORexit;

                }





                //if task is created





                //ana hna , the idea is to create a 2d array and once you successfully scanned the tiitle , incriment the value of the collumn
                //switched that Idea Up with a simple strcuture , turns out structures are pretty cool ,but don't worry arrayarrays , daddy still love you





                break;
            case '2':
                system ("cls");
                printf ("________________________>>Edit Task!<<_____________________________\n");
                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("||\t\t");
                printf ("choice 1: Edit Title");
                printf ("\t\t\t\t||\n");
                printf ("||\t\t");
                printf ("choice 3: Edit Description");
                printf ("\t\t\t||\n");
                printf ("||\t\t");
                printf ("choice 4: edit Tag");
                printf ("\t\t\t\t||\n");
                printf ("||\t\t");
                printf ("choice 5: Edit Dead-Line");


                printf ("\t\t\t||\n");
                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("________________________>>Select a Choice!<<________________________\n");

                printf ("My choice : ");
                scanf(" %c",&choice[2]); // should I make a function ? or do what ? I do not want to nest the switch case
                break;



            case '3':
                system ("cls");
                printf ("________________________>>Delate Task!<<_____________________________\n");


                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("||\t\t");
                printf ("choice 1: delate by ID");
                printf ("\t\t\t\t||\n");
                printf ("||\t\t");
                printf ("choice 2: delate by tittle");
                printf ("\t\t\t||\n");
                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("________________________>>Select a Choice!<<________________________\n");

                printf ("My choice : ");
                scanf(" %c",&choice[3]);
                break;
            case '4':
                system ("cls");
                printf ("________________________>>Show Task!<<_____________________________\n");


                    printf ("Choice 1 : sort alphabetically\n Choice 2 : sort by deadline \n Choice 3 : sort by priority \n Choice 4 : sort by creation date \n Choice 5 : Show 3 tasks by deadLine : ");
                    printf ("\n Choice 6 : Show tasks whose deadline is in 3 days or less. \n My choice :");
                    sortOp:
                    scanf(" %c",&choice[6]);
                    switch (choice[6]) {
                        case '1': TaskShow (choice[6]); break;
                        case '2': TaskShow (choice[6]); break;
                        case '3': TaskShow (choice[6]); break;
                        case '4': TaskShow (choice[6]); break;
                        case '5': TaskShow (choice[6]); break;
                        case '6': TaskShow (choice[6]); break;

                        default :
                            printf ("Invalid Choice , Please try again : ");
                            goto sortOp;

                        break;
                    }

//
//
//
//
//                    }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                printf ("My choice : ");
//                scanf(" %c",&choice[4]);

                break;
                //here I should put the fuction that shows tasks
            case '5':
                system ("cls");
                printf ("________________________>>Search Task!<<_____________________________\n");

                 printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("||\t\t");
                printf ("choice 1: search by Title");
                printf ("\t\t\t||\n");
                printf ("||\t\t");
                printf ("choice 2: search by identifier");
                printf ("\t\t\t||\n");
                printf ("||\t\t");
                printf ("choice 3: search by Tag");
                printf ("\t\t\t\t||\n");
                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("||\t\t\t\t\t\t\t\t||\n");
                printf ("________________________>>Select a Choice!<<________________________\n");
                printf ("My choice : ");
                srch :
                scanf(" %c",&choice[5]);
                switch (choice[7]){
                    case '1': TaskShow (choice[7]); break;
                    case '2': TaskShow (choice[7]); break;
                    case '3': TaskShow (choice[7]); break;
                    default :
                        printf ("invalid choice , Please try again : ");
                        goto srch;
                        break;


                }


                break;





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
