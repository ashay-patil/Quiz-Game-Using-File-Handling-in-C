//including libraries

#include<stdio.h>

#include<string.h>

#include<time.h>

#include<unistd.h>

#include<stdlib.h>

#include<ctype.h>

//help function

void displayhelp(){

    printf("\n\n------------------------------------------HELP! HELP! HELP!--------------------------------------\n\n");
        printf("->This game contains 70 questions.\n\n");
        printf("->Each question carries 10 points.\n\n");
        printf("->There is NO negative marking.\n\n");
        printf("->Every correct answer will give you 10 points.\n\n");
        printf("->There are 2 levels.Level one has 50 questions and level 2 has 20 questions\n\n");
        printf("->You can play level 2 only if you score 350 or above in level 1\n\n");
        printf("->Every question has 15 second time.\n\n");
        printf("->If you gave answer after 15 second then score will not be counted!!\n\n");
        printf("---------------------------------------Press 'R' to return to HOME-------------------------------\n\n");

    return;
}

void sort(int count, char name[100][30], int score[100]) {
    int temp;
    char arrtemp[30];

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (score[j] < score[j + 1]) {
                // Swap scores
                temp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = temp;

                // Swap names
                strcpy(arrtemp, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], arrtemp);
            }
        }
    }
}

// home function
void displayhome(char name[100]){
    printf("\n\n-----------------------------------------------------------------------------------------------------\n\n");
    printf("                                  WELCOME TO QUIZ GAME %s\n\n",name);
    printf("-----------------------------------------------------------------------------------------------------\n\n");
    printf("-----------------------------------------------------------------------------------------------------\n\n");
    printf("                               TEST YOUR KNOWLEDGE ABOUT C LANGUAGE\n\n");
    printf("-----------------------------------------------------------------------------------------------------\n\n");
    printf("-----------------------------------------------------------------------------------------------------\n\n");
    printf("                              -->Press 'S' to Start the Quiz\n\n");
    printf("                              -->Press 'H' for help\n\n");
    printf("-----------------------------------------------------------------------------------------------------\n\n");
    printf("                                     ALL THE BEST !!\n\n\n");
    return;
}

int main(){


    FILE *fptr;    // declaring file pointer

    char user_answer,correct_answer,choice,choice2;

    char name[100];

    int score=0;

    //start the game


    printf("\nEnter you name please(first name only) : "); //prompting user to tell his first name
    scanf(" %s",name);

    //clear screen
    system("cls");

    //design home screen


    home:
    displayhome(name);
    scanf(" %c",&choice);

    //clear screen;
    system("cls");

    printf("\n\n");


    //design help screen


    if(toupper(choice)=='H'){

        displayhelp();

        scanf(" %c",&choice2);

        if(toupper(choice2)=='R'){
            system("cls");//clear screen
            goto home;   // goto statement is used to transfer control to label(here label is home)
        }

        else {
            while(toupper(choice2)!='R'){
                printf("Invalid Key\n");
                scanf(" %c",&choice2);
            }
            if(toupper(choice2)=='R') {
                    system("cls"); //clear screen
                    goto home;
            }

        }

    }

    //start the quiz

    else if(toupper(choice)=='S'){

        printf("\n\n\n");
        printf("---------------------------------------QUIZ STARTED----------------------------------------\n\n");

        fptr=fopen("questions.txt","r");  //open the file

        char question[10000];

        while(fgets(question, 10000, fptr)!=NULL){    // in first iteration it reads \n and in other iteration also it reads \n

            printf("\n\n\n");

            fgets(question, 10000, fptr);   //read question

            printf(" %s",question);         // display question

            fgets(question,10000, fptr);   // read options

            printf("\n\n %s",question);     // display options

            fscanf(fptr, " %c",&correct_answer); // read answer

            printf("\n\nenter your answer : ");

            time_t start_time=time(NULL);  // store current time in start_time

            scanf(" %c",&user_answer);     // user will enter the answer after spending some time

            time_t end_time=time(NULL);     // store current time in end_time

            double diff=difftime(end_time,start_time);  // calculate difference between end_time and start_time and store the difference in diff variable

            if(diff>15){
                printf("\n\nTIME UP!!\n\n");
                sleep(2);
                system("cls");
                continue;
            }

            if(toupper(correct_answer)==toupper(user_answer)) {
                    printf("\n\ncorrect!!\n\n");
                    score++;  // increment the score
            }

            if(toupper(correct_answer)!=toupper(user_answer)){
                    printf("\n\noops!! your answer is wrong!!\n\n");
                    printf("Correct answer is option %c",correct_answer);
            }
            sleep(2);

            //clear screen

            system("cls");
        }

        fclose(fptr);

        printf("\n\n\n");

        printf("---------------------------------------LEVEL 1 COMPLETED-----------------------------------------------------\n\n");
        score = 40;
        printf("Your score is %d\n\n",10*score);

        if(score*10>=350){
            printf("CONGRATULATIONS YOU CAN PLAY LEVEL2 , PRESS L TO START LEVEL 2 OR E TO EXIT: ");
            char level;
            scanf(" %c",&level);
            if(toupper(level)=='L') goto level2;
            if(toupper(level)=='E') goto end;
        }
        else {
            printf("you need to try harder next time to go to level 2");
            goto end;
        }
        level2:

        fptr=fopen("level2questions.txt","r");

        char question2[10000];
        system("cls");

        printf("\n\n--------------------------LEVEL 2----------------------------\n\n");

        while(fgets(question2, 10000, fptr)!=NULL){    // in first iteration it reads \n and in other iteration also it reads \n

            printf("\n\n\n");

            fgets(question2, 10000, fptr);   //read question

            printf(" %s",question2);         // display question

            fgets(question2,10000, fptr);   // read options

            printf("\n\n %s",question2);     // display options

            fscanf(fptr, " %c",&correct_answer); // read answer

            printf("\n\nenter your answer : ");

            time_t start_time=time(NULL);  // store current time in start_time

            scanf(" %c",&user_answer);    // user will enter answer after taking some time

            time_t end_time=time(NULL);   //store current time in end_time

            double diff=difftime(end_time,start_time);

            if(diff>15){
                printf("\n\nTIME UP!!\n\n");
                sleep(2);
                system("cls");
                continue;
            }

            if(toupper(correct_answer)==toupper(user_answer)) {
                    printf("\n\ncorrect!!\n\n");
                    score++;
            }

            if(toupper(correct_answer)!=toupper(user_answer)){
                    printf("\n\noops!! your answer is wrong!!\n\n");
                    printf("Correct answer is option %c",correct_answer);
            }

            sleep(2);  //pause the running of code for 2 second

            //clear screen

            system("cls");

        }

        fclose(fptr);

        end:

        printf("\n\n--------------------------------THANK YOU-------------------------\n\n\n");

        //giving remarks to player on basis of their score

        printf("Your total score is %d\n\n",10*score);

        if(score*10>=600) printf("BRAVO!! Your have good command on C language\n\n");

        else if(score*10>=500) printf("NICE!! KEEP IT UP!!\n\n");

        else if(score*10>=350) printf("GOOD!! Your score is satisfactory\n\n");

        else printf("WELL TRY!! you can do much better!!\n\n");



    }

    else {
        printf("Invalid key");
        sleep(2);
        system("cls");
        goto home;
    }

    //storing player data in file

    FILE *ptr1;

    ptr1=fopen("leaderboard.txt", "a");

    fprintf(ptr1, "%s %d\n", name,score*10);   //storing player data in leaderboard file

    fclose(ptr1);

    //display data from file

    printf("\n\n------------------------------------------SCOREBOARD--------------------------------------\n\n");

    char read[100];
    char student_name[100][30];
    int i,student_score[100],count=0;

    ptr1=fopen("leaderboard.txt", "r");
    while(fgets(read, 100, ptr1)!=NULL){

        for(i=0;read[i]!=' ';i++){
            student_name[count][i]=read[i];  //storing student name in 2d character array
        }

        student_score[count]=atoi(&read[i+1]);     // score stored in the file is not a number but it is a character having ascii value.
                                                   // atoi function converts the character into number

        count++;
    }

    fclose(ptr1);

    sort(count,student_name,student_score);

    for(int k=0;k<count;k++){
        printf("name=%s\tscore=%d\n\n",student_name[k],student_score[k]);
    }


    printf("\n\n-----------------------------------------------------------------------------\n\n");

    printf("Give your feedback.\n\nHow was your experience?\n\nAre there any improvements needed?\n\nWRITE HERE : ");
    char review[1000];
    getchar();  // this getchar function is used to consume \n
    gets(review); //used to read string

    //storing feedback in file

    FILE *feedback;
    feedback=fopen("Feedback.txt", "a");
    fprintf(feedback, "name : %s\tFeedback : %s\n",name,review);
    fclose(feedback);

    printf("--------------------------------------------THANK YOU---------------------------------------------\n\n\n");
    return 0;
}
