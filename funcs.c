#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "funcs.h"
#include <string.h>
#include <ctype.h>

void menu_item_1(void) {
    int band;
    printf("\n>> Resistor Colour Code Calculator\n");
    printf("\nWhat band resistor is it? (enter 3 to 6): \n");
    scanf("%d", &band);
    printf("\n >> %d\n", band);
    if (band != 3 && band !=4 && band !=5 && band !=6) {
        printf("\nInvalid entry, please restart\n");
        getchar();
        return;
    }
    float scan=1;
    float scan2=1;
    float scan3=1;
    float scan4=1;
    float scan5=1;
    float scan6=1;
    float result=1;
    

    printf("\nSelect colours from the following list by entering the corresponding number:\n");
    printf("\n | 1 - Black |\n | 2 - Brown |\n | 3 - Red |\n | 4 - Orange |\n | 5 - Yellow |\n | 6 - Green |\n | 7 - Blue |\n | 8 - Violet |\n | 9 - Grey |\n | 10 - White |\n | 11 - Gold |\n | 12 - Silver |\n");
    for (int i = 0; i<band; i++){
      printf("\nEnter colour of band %d (0-9): \n", i+1);
    
        if (i == 0){
            scanf("%f", &scan);
        }
        if (i ==1){
            scanf("%f", &scan2);
        }
        if (i ==2){
            scanf("%f", &scan3);
        }
        if (i ==3){
            scanf("%f", &scan4);
        }
        if (i ==4){
            scanf("%f", &scan5);
        }
        if (i ==5){
            scanf("%f", &scan6);
    }
   
    if(scan < 1 || scan > 12 || scan2 < 1 || scan2 > 12 || scan3 < 1 || scan3 > 12 || scan4 < 1 || scan4 > 12 || scan5 < 1 || scan5 > 12 || scan6 < 1 || scan6 > 12){
        printf("\nInvalid colour entry, please restart!\n");
        getchar();
        return;
    }

    
}

  float final;
    if(band == 3 || band == 4) {
        final = three_four_band(scan, scan2, scan3);
        
    }
   
    if(band == 5 || band == 6) {
        final = five_six_band(scan, scan2, scan3, scan4);
        
    }
    
    if(final >= 1000 && final < 1000000){
        final = final / 1000;
        printf("\nResistance is: %.2f KOhms", final);
        
    }
    else if(final >= 1000000){
        final = final / 1000000;
        printf("\nResistance is: %.2f MOhms", final);
        
    }
    else if(final<1000) {
    printf("\nResistance is: %.3f Ohms", final);
    }
   
    if(band == 4) {
       uncertainty(scan4);
    }
   else if(band == 5 || band == 6) {
       uncertainty(scan5);
   }
   if(band == 6){
         temp(scan6);
   }
 getchar();
 return;
}
    /* you can call a function from here that handles menu 1 */

float temp(float a){
    int temp;
    if(a >= 10) {
        printf("\nInvalid colour for temperature band :( - double check!\n");
        return 0;
    }
        if(a == 1) temp=250;
   else if(a == 2) temp=100;
   else if(a == 3) temp=50;
   else if(a == 4) temp=15;
   else if(a == 5) temp=25;
   else if(a == 6) temp=20;
   else if(a == 7) temp=10;
   else if(a == 8) temp=5;
   else if(a == 9) temp=1;
    printf("\nTemperature Coefficient: %d ppm/K", temp);
    return 0;
}

    
    

float three_four_band(float a, float b, float c){
    if(a>10 || b>10){
        printf("\nGold and Silver are invalid colours for a significant figure band!\n\n Please try again.\n");
        getchar();
        return 0;
    }
    a = a - 1;
    b = b - 1;
    c = c - 1;
    int m = 1;
    if(c<10){
    for(int i = 0; i < c; i++){
     m = m*10;
    }
float result = (a*10 + b)*m;
return result;
    }
    else if(c==10){
    float result = (a*10 + b)*0.1;
    return result;
    }
    else if(c==11){
    float result = (a*10 + b)*0.01;
    printf("\nResistance is: %.2f Ohms ", result);
    return result;
    }

    
}

float five_six_band(float a, float b, float c, float d){
    if(a>10 || b>10 || c>10){
        printf("\nGold and Silver are invalid colours for a significant figure band!\n\n Please try again.\n");
        return 0;
    }
    a=a-1;
    b=b-1;
    c=c-1;
    d=d-1;
    int m = 1;
    if(d<10){
    for(int i = 0; i < d; i++){
     m = m*10;
    }
    float result = (a*100 + b*10 + c)*m;
    return result;
 }
 else if(d==10){
    float result = (a*100 + b*10 + c)*0.1;
    return result;
 }
 else if(d==11){
    float result = (a*100 + b*10 + c)*0.01;
    return result;
 }
}


float uncertainty(float a){
    a =a - 1;
    if(a <= 0 || a == 3 || a == 4 ||a == 9 ||a > 11 ){
        printf("\nInvalid colour for tolerance band :(\n");
        return 0;
    }
    if(a >= 1 && a <= 2){
        float tolerance = a;
        printf(" +- %.2f%%!\n", tolerance);
        return a;
    }
    if(a == 5){
        float tolerance =0.5;
        printf(" +- %.2f%%!\n", tolerance);
        return tolerance;
    }
    if(a == 6){
        float tolerance= 0.25;
        printf(" +- %.2f%%!\n", tolerance);
        return 0;
    }
    if(a == 7){
        float tolerance= 0.10;
        printf(" +- %.2f%%!\n", tolerance);
        return 0;
    }
    if(a == 8){
        float tolerance = 0.05;
        printf(" +- %.2f%%!\n", tolerance);
        return 0;
    }
    if(a == 10){
        float tolerance = 5.0;
        printf(" +- %.2f%%!\n", tolerance);
        return 0;
    }
    if(a == 11){
        float tolerance = 10.0;
        printf(" +- %.2f%%!\n", tolerance);
        return 0;
    }
}
void calc(void){
    
    
    float num1, num2, res;
    char op;
    char buffer[50];
    char buffer2[50];
    printf("\nEnter first number: ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("%s\n", buffer);
    for(int i = 0; i < strlen(buffer)-1; i++){
        if(!isdigit(buffer[i]) && buffer[i] != '.' && buffer[i] != '-'){
            printf("Syntax error: Invalid number\n");
            getchar();
            return;
        }
    }
    num1 = atof(buffer);
    
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);
    getchar();
    if(op != '+' && op != '-' && op != '*' && op != '/'){
        printf("Syntax error: Invalid operator!\n");
        getchar();
        return;
    }

    printf("Enter second number: ");
    fgets(buffer2, sizeof(buffer2), stdin);
    
    for(int i = 0; i < strlen(buffer2)-1; i++){
        if(!isdigit(buffer2[i]) && buffer2[i] != '.' && buffer2[i] != '-'){
            printf("Syntax error: Invalid number!\n");
            return;
        }
    }
   num2 = atof(buffer2);
    switch(op){
        case '+':
            res = num1 + num2;
            break;
        case '-':
            res = num1 - num2;
            break;
        case '*':
            res = num1 * num2;
            break;
        case '/':
            if(num2 == 0){
                printf("Error: Division by zero!\n");
                getchar();
                break;
            }
            res = num1 / num2;
            break;
        
    }
    printf(" \n = %.4f\n", res);
    
    return;
}

void menu_item_2(void) {
    float res;
    int next=0;
    float prev=0;
    float ans=0;
   printf("\n>> Basic Calculator:\n");
   do {
    calc();
    printf("\nPerform another calculation? (1 for Yes, 0 for No): ");
    scanf("%d", &next);
    getchar();
    if(next != 0 && next != 1){
        printf("\nInvalid entry, exiting calculator.\n");
        return;
    }
    if(next == 0){
        printf("\nCalculations finished!\n");
        return;
    }
    
    
    } while(next != 0); 





    
    
    
 
    /* you can call a function from here that handles menu 2 */
}
void binary_to(void){
    char binary[100];
    int decimal = 0;
    printf("\nEnter a binary number: \n");
    fgets(binary, sizeof(binary), stdin);
    int len = strlen(binary) - 1;
    long long int bnum = strtoll(binary, NULL, 2);
    for(int i = 0; i < len; i++){
        if(binary[i] != '0' && binary[i] != '1'){
            printf("\nInvalid binary number, please restart!\n");
            return;
        }
    }
    
     printf("\n Decimal or hexadecimal conversion? (1 for Decimal, 2 for Hexadecimal): ");
    int pik;
    scanf("%d", &pik);
    if(pik != 1 && pik != 2){
        printf("\nInvalid entry, please try again :(\n");
        return;
    }
    if(pik == 1){
    
    printf("\nDecimal equivalent: %lld\n", bnum);

    }
    else if(pik == 2){
        printf("\nHexadecimal equivalent: %llX\n", bnum);
    }

}
void decimal_to(void){
    char decimal[100]; 
    int bn[1000];
    int j=0; 
    int rem = 0;
    long long int dec=0;
     long long int sig = 1;
    printf("\nEnter a decimal number(integer): ");
    fgets(decimal, sizeof(decimal), stdin);
    for(int i = 0; i < strlen(decimal)-1; i++){
        if(!isdigit(decimal[i])){
            printf("\nInvalid decimal number, please restart!\n");
            return;
        }
    }
    if(strlen(decimal)> 20){
        printf("\nDecimal number is too long, try a different number!\n");
        return;
    }
    dec = strtoll(decimal, NULL, 10);
    printf("\n Binary or hexadecimal conversion? (1 for Binary, 2 for Hexadecimal): ");
    int pik;
    scanf("%d", &pik);
    if(pik != 1 && pik != 2){
        printf("\nInvalid entry, please restart!\n");
        getchar();
        return;
    }
    if(pik == 1){
    printf("\nBinary equivalent: ");
    while (dec != 0){
        rem = dec % 2;
        bn[j++] = rem;
        dec = dec / 2;
        
        
    }
while(j>0){
    printf("%d", bn[--j]);
}
    
    
}
    else if(pik == 2){
        printf("\nHexadecimal equivalent: %llX ", dec );


    }

}
void hex_to(void){
    
    char decimal[100];
    int bn[1000];
    long long int rem = 0;
    long long int bin=0;
    int len=0;
    int j=0;
    long long int dec=0; 
    long long int sig = 1;
    printf("\nEnter a hexadecimal number(not including 0x): ");
    fgets(decimal, sizeof(decimal), stdin);
    for(int i = 0; i < strlen(decimal)-1; i++){
        if(!isdigit(decimal[i]) && decimal[i] != 'A' && decimal[i] != 'B' && decimal[i] != 'C' && decimal[i] != 'D' && decimal[i] != 'E' && decimal[i] != 'F' && decimal[i] != 'a' && decimal[i] != 'b' && decimal[i] != 'c' && decimal[i] != 'd' && decimal[i] != 'e' && decimal[i] != 'f'){
            printf("\nInvalid decimal number, please restart!\n");
            getchar();
            return;
        }
        if(isalpha(decimal[i])){
            decimal[i] = toupper(decimal[i]);
        }
    }
    if(strlen(decimal)> 17){
        printf("\nHexadecimal number is too long, try a different number!\n");
        return;
    }
    
     dec = strtoll(decimal, NULL, 16);
     
     
    printf("\n Binary or decimal conversion? (1 for Binary, 2 for Decimal): ");
    int pik;
    scanf("%d", &pik);
    if(pik != 1 && pik != 2){
        printf("\nInvalid entry, please restart!\n");
        return;
    }
    if(pik == 1){
    printf("\nBinary equivalent: ");
    while (dec != 0){
        rem = dec % 2;
        bn[j++] = rem;
        dec = dec / 2;
        
        
    }
while(j>0){
    printf("%d", bn[--j]);
}
}
    else if(pik == 2){
        printf("\nDecimal equivalent: %lld ", dec);


    }

}
    

void menu_item_3(void) {
    int base;
    int numb;
    printf("\n>> Binary/Hex/Decimal converter\n");
    printf("\nWhich number base do you want to input?\n\n | 1 - Binary |\n | 2 - Decimal |\n | 3 - Hexadecimal |\n\n");
    scanf("%d", &base);
    getchar();
    if(base < 1 || base > 3){
        printf("\nInvalid entry, please restart\n");
        return;
    }
    if(base == 1) {
        do{
            binary_to();
            printf("\nConvert another binary number? (1 for Yes, 0 for No):");
            scanf("%d", &numb);
            getchar();
            if(numb != 0 && numb != 1){
                printf("\nInvalid entry, exiting converter.\n");
                return;
            }
        } while (numb != 0);
        
    }
            
    else if(base == 2) do{
        decimal_to();
        printf("\nConvert another decimal number? (1 for Yes, 0 for No):");
        scanf("%d", &numb);
        getchar();
        if(numb != 0 && numb != 1){
                printf("\nInvalid entry, exiting converter.\n");
                getchar();
                return;
            }
        } while (numb != 0);
    else if(base == 3) do{
        hex_to();
        printf("\nConvert another hexadecimal number? (1 for Yes, 0 for No):");
        scanf("%d", &numb);
        getchar();
        if(numb != 0 && numb != 1){
                printf("\nInvalid entry, exiting converter.\n");
                getchar();
                return;
            }
        } while (numb != 0);
        
    /* you can call a function from here that handles menu 3 */
}

void good(void){
    printf("\n >> Validation:\n");
    int r=rand()%10;
    switch (r){
        case 0:
            printf("\n\nLook how far you've come over the last year! Faraday would be proud :)\n");
            break;
        case 1:
            printf("\nKeep sending those cold emails! Someone will respond eventually...right? \n");
            break;
        case 2:
            printf("\nDon't worry! Your circuit is correct, the components are just faulty!\n");
            break;
        case 3:
            printf("\nIt's okay, blowing up capacitors is just part of the learning process!\n");
            break;
        case 4:
            printf("\nJust have a rest and relax, then try that pesky question again!\n");
            break;
        case 5:
            printf("\nYou've done plenty of revision today! Remember that work-life balance.\n");
            break;
        case 6:
            printf("\nThey say the more you know about physics the less you know. So you must be really smart!\n");
            break;
        case 7:
            printf("\nRemember when you got 100 percent in the mobius lab that one time? Use that feeling as fuel!\n");
            break;
        case 8:
            printf("\nThat passion is still in there somewhere! Just do more worksheets!\n");
            break;
        case 9:
            printf("\nYou are an electronic engineering genius!\n");
            break;
    }
    

}
void quote(void){
    printf("\n >> Inspirational Quote:\n\n");
    int rq=rand()%7;
    switch (rq){
        case 0:
            printf("\n'There are children playing in the streets who could solve some of my top problems in physics,\n because they have modes of sensory perception that I lost long ago.'\n\nJ. Robert Oppenheimer\n\n");
            break;
        case 1:
            printf("\n'Scientists study the world as it is; Engineers create the world that has never been.'\n\n Albert Einstein\n\n");
            break;
        case 2:
            printf("\n'The human foot is a masterpiece of engineering and a work of art.'\n\n Leonardo da Vinci\n\n");
            break;
        case 3:
            printf("\n'One man's magic is another man's engineering. 'Supernatural' is a null word.'\n\n Robert A. Henlein\n\n");
            break;
        case 4:
            printf("\n'Engineering isn't about perfect solutions: it's about doing the best you can with limited resources.'\n\nRandy Pausch \n\n");
            break;
        case 5:
            printf("\n'I have not failed, but found 1000 ways not to make a light bulb.'\n\n Thomas Edison\n\n");
            break;
        case 6:
            printf("\n'Art without engineering is dreaming. Engineering without art is calculating.'\n\n Steven K. Roberts\n");
            break;
    }
    
}
void fact(void){
        printf("\n >> Fun Electricity Fact:\n\n");
    int rq=rand()%7;
    switch (rq){
        case 0:
            printf("\nElectric Eels can produce a shock of up to 600 Volts!\n\n");
            break;
        case 1:
            printf("\nElectrical signals travel at a speed near the speed of light!\n\n");
            break;
        case 2:
            printf("\nNikola Tesla created his first AC induction motor in the late 1800s completely in his head, then went on to craft it himself.\n\n");
            break;
        case 3:
            printf("\nThe first electrical engineering degree was awarded by Cornell University in 1885.\n\n");
            break;
        case 4:
            printf("\nMoore's Law: The number of transistors on a chip will double roughly every two years due to shrinking dimensions.\n\n");
            break;
        case 5:
            printf("\nThe Earliest known observation about electrical force was made around 600BC, by Thales of Mitus, a Greek philosopher.\n\n");
            break;
        case 6:
            printf("\nThe term 'Volt' comes from the name of Italian physicist Alessandro Volta, who invented the electric battery in 1799.\n\n Steven K. Roberts\n");
            break;
  }
  
}
void pick(void){
    int p=rand()%3;
    switch (p){
        case 0:
            good();
            break;
        case 1:
            quote();
            break;
        case 2:
            fact();
            break;
    }
    
}

    

void menu_item_4(void) {
    printf("\n>> Daily Electronic Affirmations\n");
    printf("\nWhat do you want to hear today?\n");
    printf("\n| 1 - 'Validate my electronic engineering' |\n| 2 - 'Random Inspirational Quote!' |\n| 3 - 'Give me a fun electronic fact'|\n| 4 - A random choice from above! |\n\n");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
    good();
    break;
        case 2:
    quote();
    break;
        case 3:
    fact();
    break;
        case 4:
    pick();
    break;
        
    /* you can call a function from here that handles menu 4 */
}
getchar();
}
