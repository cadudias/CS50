#include <stdio.h>
#include <cs50.h>

int getCreditCardLenght();
void checkCardNumber();
int doubleEveryOtherNumberStartingFormSecondToLast();
int sumNotMultipliedNumbers();

int main(void)
{
    printf("Number: ");
    long long CC_NUMBER = get_long_long();
    
    int x2_prod = doubleEveryOtherNumberStartingFormSecondToLast(CC_NUMBER);

    int notx_sum = sumNotMultipliedNumbers(CC_NUMBER);
    
    int totalSum = x2_prod + notx_sum;
    
    // if the number doesn't end in 0 it's invalid
    if(totalSum % 10 != 0){
        printf("INVALID\n");
        return 0;
    }

    // check the company identifier for the credid card number
    checkCardNumber(CC_NUMBER);
}

void checkCardNumber(long long CC_NUMBER)
{
    if( (CC_NUMBER >= 4000000000000 && CC_NUMBER < 5000000000000) || 
        (CC_NUMBER >= 4000000000000000 && CC_NUMBER < 5000000000000000) ) {
        printf("VISA\n");
    }else if( (CC_NUMBER >= 5100000000000000 && CC_NUMBER < 5600000000000000) ) { 
        printf("MASTERCARD\n");
    }else if( (CC_NUMBER >= 340000000000000 && CC_NUMBER < 350000000000000) ||
              (CC_NUMBER >= 370000000000000 && CC_NUMBER < 380000000000000)) {
        printf("AMEX\n");
    }else{
        printf("INVALID\n");
    }
}

int doubleEveryOtherNumberStartingFormSecondToLast(long long CC_NUMBER)
{
    int x2_prod = 0;
    long long cc_number_divided;
    // double every other digit starting w/ 2nd to last
    // #### CC_NUMBER / 10 #### - 2nd to last
    for (cc_number_divided = CC_NUMBER / 10, x2_prod = 0; cc_number_divided > 0; cc_number_divided /= 100 )
    {
         int current_digit = cc_number_divided % 10;

         // if doubling the digit is greater than 9
         // the product of that multiplication is not a single digit
         int xnumber = 2 * current_digit;

         if ( xnumber > 9 )
         {
             //ex: 14 = 1 + 4
             x2_prod += xnumber / 10; // / get the first digit of the decimal number
             x2_prod += xnumber % 10; // get the product of that decimal number
             
         }else{
             x2_prod += xnumber;
         }
    }
    
    return x2_prod;
}

int sumNotMultipliedNumbers(long long CC_NUMBER)
{
    int notx_sum = 0;
    long long cc_number_divided;
    
    // sum the digits that werent multiplied by two - notx_sum
    for ( cc_number_divided = CC_NUMBER, notx_sum = 0; cc_number_divided > 0; cc_number_divided /= 100 )
    {
        int current_digit = cc_number_divided % 10;
        notx_sum += current_digit;
    }
    
    return notx_sum;
}