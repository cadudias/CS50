#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    
    do{
        printf("Height: ");
        height = get_int();
    }
    while(height < 0 || height > 23);
    // When height is a valid input (true) we proceed to the rest of the program
    // If its not valid (false) we stop the program and ask again
    
    /*
        First loop iterates through the lines of the pyramid
        
        Second and third loops position the spaces and hashes in the lines
    */
    for(int i = 0; i < height; i++)
    {
        // print spaces on each row
        // on each row (i) we have to decrement one space starting with i = 0 (height - 1 - i)
        for(int j = 0; j < height - 1 - i; j++){
            printf(" ");
        }
        
        // print hashes on each row
        // on each row (i) we have to increment one hash starting with i = 0 (i + 2)
        for(int k = 0; k < i + 2; k++){
            printf("#");
        }
        
        printf("\n");
    }
}