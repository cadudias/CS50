#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void){
    
    string name = get_string();
    
    if(name != NULL)
    {
        for(int i = 0, name_length = strlen(name); i < name_length; i++)
        {
            if(i == 0) { //get first letter
                printf("%c", toupper(name[0]));
    
            }else if(name[i] == ' ' ) {//get other first letters after space
                printf("%c", toupper(name[i+1]));
            }
        }
        
        printf("\n");
    }
        
}