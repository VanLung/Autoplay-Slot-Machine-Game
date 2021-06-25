#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void Menu() {

    printf("\nChoose one of the following menu options:");
    printf("\n1) Play the slot machine");
    printf("\n2) Save game");
    printf("\n3) Cash out");
}

void writeToFile(char *fileName, float *cash)
{
    FILE *f = fopen(fileName, "w");
    fprintf(f, "%0.2f", *cash);
    fclose(f);
}

double readFile(char *fileName)
{
    int check;
    float cash;
    FILE *f = fopen(fileName, "r");
    if(f == NULL) 
        return 10;
    else   
        check = fscanf(f, "%0.2f", &cash);
        if(check == 0) return 10;
    fclose(f);
    return cash;
}

int main() {

    int counter;
    int counter2;
    int counter3;
    int counter4;
    float cash = 10.00;
    float bet = 0.25;
    int num1;
    int num2;
    int num3;
    int jackWin;
    int c, p;

    printf("\n\t\t============== Simple Slot Machine ==============");
    srand(time(NULL));


    do {
        printf("\nYou have $%0.2f.", cash);
        Menu();

        do {
//            printf("\nYour number: ");
//            scanf("%d", &c);
           c = 1;
        } while ((c < 0) || (c > 3));
     //   if(cash>=0){
//            cash= cash;
//        }
        switch (c) {
            case 1:
//                do {
                if(cash <=0){
                    printf("\nGood bye!");
                    exit(0);
                }
                    for (counter2 = 1; counter2 <= 5; counter2++) {
                        num1 = rand()%(8);
                        num2 = rand()%(8);
                        num3 = rand()%(8);
                    }
                    
                    
                    //Để lấy số ngẫu nhiên từ 0 đến n, ta sử dụng rand()%(n+1)
                    //Để lấy số ngẫu nhiên từ a đến b, ta sử dụng a + rand()%(b-a+1)
                   
                    
                    p = rand() % (999998);

                    if (p == 1) //0,00001 ra 3 số trùng nhau.
                    {
                        (num1 == num2)&&(num2 == num3)&&(num3 == num1);
                    }
                   
                    
                    if (p > 1 || p <= 5) // 0,0003 1 cặp trùng nhau.
                    {
                        ((num1 == num2)&&(num2 != num3)) || ((num3 == num1)&&(num1 != num2)) || ((num2 == num3)&&(num3 != num1));
                    }
                    
                    
                    else
                    {
                        (num1 != num2)&&(num2 != num3)&&(num3 != num1);
                    }

                    printf("\nSlot Machine Shows %d%d%d.", num1, num2, num3);


                    if ((num1 == num2)&&(num2 == num3)&&(num3 == num1)) {
                        cash -= bet;
                        cash += 10;
                        printf("\n\t\t\t\t******You win the big prize, $10.00!******\n");
                        printf("\nYou have $%0.2f\n", cash);
                    }


                    if ((num1 != num2)&&(num2 != num3)&&(num3 != num1)) {
                        cash -= bet;
                        printf("\nSorry you don't win anything.");
                        printf("\nYou have $%0.2f\n", cash);
                    }


                    if (((num1 == num2)&&(num2 != num3)) || ((num3 == num1)&&(num1 != num2)) || ((num2 == num3)&&(num3 != num1))) {
                        cash -= bet;
                        printf("\nYou win 25 cents!");
                        printf("\nYou have $%0.2f\n", cash + 0.25);

//                        if (cash == 0) {
//                            printf("\nGood bye!");
//                            exit(0);
                       // }
                    }
//                } while (cash >= 0);
                break;
            case 2:
                writeToFile("Cash.TXT", &cash);
                printf("Your money had saved!!!");
                break;
            case 3:
                printf("Thank you for playing! You end with %0.2f", cash);
                exit(0);
            default:

                printf("Please enter your number again from 0 to 3");
                break;
        }
    } while (c != 0);
}
