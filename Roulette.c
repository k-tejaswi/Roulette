#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int Odd[18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,29,32,34,36};
int Even[18]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,30,31,33,35};

int spin(void);
int game(int choice, int num, char type, int betamount, int balance);


int main() {
    int total, balance;
    int choice=-1;
    int num;
    char type='Z';
    int betamount;
    total=0;
    balance=total;
    printf("*** THE ROULETTE GAME *** \n");
    printf("\t\t\t $ £ ¢ € ¥ Rs \n");
    printf("\t\t * Welcome * \n");
    printf("Are you ready to play the game!!!!!! \n");
    printf("Then Let's Start \n");
    printf("\n");
    printf("\nBETTING CHOICES:-\n");
    printf("1) Choose a number \n");
    printf("2) Choosing a colour \n");
    printf("3) Choosing Odd/Even \n");
    printf("4) Choosing High 18/Low 18 numbers \n");
    printf("5) Exit\n");

    while(choice!=5){
        printf("\nEnter your choice :");
        scanf("%d", &choice);
        if (choice<5){
            printf("\nEnter the amount you like to play :");
            scanf("%d", &betamount);
        }
    
        switch(choice){
            case 1: {
                printf("\nEnter a number from 1 to 36 : ");
                scanf("%d",&num);
                break;
            }
            case 2:{
                printf("\nEnter 'R' for Red and 'B' for Black : ");
                scanf(" %c", &type);
                break;
            }
            case 3: {
                printf("\nEnter 'O' for Odd and 'E' for Even : ");
                scanf(" %c", &type);
                break;
            }
            case 4: {
                printf("\nEnter 'G' for greater than and 'L' for less than 18 : ");
                scanf(" %c", &type);
                break;
            }
            case 5: {
                printf("\n The Game Ends");
                break;
            }
            default: {
                printf("\nInvalid choice. Enter a valid bet choice");
            }
        }
        if (choice==1 || choice==2 || choice==3 || choice==4)   balance=game(choice, num, type, betamount, balance);
        printf("\nBalance : %d\n\n", balance);
    }
    
}

int spin(void) {
    int num;
    srand(time(NULL));
    num=(rand()%38);
    return num;
}

int game(int choice, int num, char type, int betamount, int balance){

    int result=spin(), flag=0;
    printf("\n Stopped position of the ball : %d \n\n", result);

    if (result==0 || result==37){
        printf("\n Game Ends");
    }
    else{
    switch (choice){
        case 1: {
            if (num==result && result<=36) {
                printf("* You Won!!! * \n");
                balance=(balance*35)+balance;
            }
            else {
                printf("* You Lost * \n");
                balance=balance-betamount;
            }
            break;
        }

        case 2: {
            for(int i=0; i<19; i++){
                if (type=='R' && Odd[i]==result){
                    printf("* You Won!!! * \n");
                    balance+=betamount;
                    flag++;
                    break;
                }
                else if (type=='B' && Even[i]==result){
                    printf("* You Won!!! * \n");
                    balance+=betamount;
                    flag++;
                    break;
                }    
            }
            if (flag==0) {
                printf("* You Lost * \n");
                balance=balance-betamount;
            }
            break;
        }

        case 3: {
            for(int i=0; i<19; i++){
                if ((type=='O' && Odd[i]==result && Odd[i]%2!=0) || (type=='O' && Even[i]==result && Even[i]%2!=0)){
                    printf("* You Won!!! * \n");
                    balance+=betamount;
                    flag++;
                    break;
                }

                else if ((type=='E' && Odd[i]==result && Odd[i]%2==0) || (type=='E' && Even[i]==result && Even[i]%2==0)){
                    printf("* You Won!!! * \n");
                    balance+=betamount;
                    flag++;
                    break;
                }
            }
            if (flag==0) {
                printf("* You Lost * \n");
                balance=balance-betamount;
            }
            break;
        }

        case 4: {
            for(int i=0; i<19; i++){
                if ((type=='L' && Odd[i]==result && Odd[i]<=18) || (type=='L' && Even[i]==result && Even[i]<=18)){
                    printf("* You Won!!! * \n");
                    balance+=betamount;
                    flag++;
                    break;
                }

                else if ((type=='U' && Odd[i]==result && Odd[i]>18) || (type=='U' && Even[i]==result && Even[i]>18)){
                    printf("* You Won!!! * \n");
                    balance+=betamount;
                    flag++;
                    break;
                }
            }
            if (flag==0) {
                printf("* You Lost * \n");
                balance=balance-betamount;
            }
            break;
        }

        case 5: {
            printf("\n Game Ends");
            break;
        }

        default: printf("\n Invalid Choice ");
    }
    }
    return balance;
}