//
//  main.c
//  ChangeReturnProgram
//  This is one of the projects from:
//  https://github.com/karan/Projects
//
//  Created by Jeremy Hamning on 7/10/14.
//
//

#include <stdio.h>

void calculate_change(int change[9], float dollar_denominations[9], float cost, float money_given);


int main(int argc, const char * argv[])
{
    int change[9];
    float cost = 0;
    float money_given = 0;
    float dollar_denominations[9] = {100, 20, 10, 5, 1, .25, .1, .05, .01};
    
    do {
        printf("Please enter the cost and the money given.\n");
        scanf("%f %f", &cost, &money_given);
        if (money_given < cost) {
            printf("The money given must be greater than the cost.\n");
        }
    } while (money_given < cost);
    
    if (money_given == cost) {
        printf("No change needed.\n");
        return 0;
    }
    
    calculate_change(change, dollar_denominations, cost, money_given);

    printf("Change to return:\n");
    for(int i = 0; i < 9; i++) {
        printf("%.2f: %d\n", dollar_denominations[i], change[i]);
    }
    return 0;
}

//The change array maps to the dollar_denominations array and counts the number of a certain denomination to return.
void calculate_change(int change[9], float dollar_denominations[9], float cost, float money_given) {
    float money_to_divide = money_given - cost;
    float amount_to_subtract;
    
    for(int i = 0; i < 9; i++) {
        change[i] = money_to_divide / dollar_denominations[i];
        amount_to_subtract = change[i] * dollar_denominations[i];
        if(money_to_divide - amount_to_subtract >= 0){
            money_to_divide -= amount_to_subtract;
        }
    }
}

