#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]){
    
    if(argc != 2){
        printf("Incorret number of arguments, pass in only the key to cypher \n");
        return 1;
    }
    
    int p, cipher_index, c = 0;
    int key = atoi(argv[1]);
    int ASC2_UPPERCASE_START_NUMBER = 65;
    int ASC2_LOWERCASE_START_NUMBER = 97;
    
    printf("plaintext: ");
    string text = get_string();
    
    printf("ciphertext: ");
    
    // O(n) - constant growth based on the text length
    for(int i = 0, text_length = strlen(text); i < text_length; i++)
    {
        char current_char = text[i];
        
        if(isalpha(current_char)){
            //find the aplhabetical index of the letter we want to cipher
            p = isupper(current_char) ? current_char - ASC2_UPPERCASE_START_NUMBER : current_char - ASC2_LOWERCASE_START_NUMBER;
            
            // index of the character after aplying the key
            cipher_index = (p + key) % 26;
            
            c = isupper(current_char) ? cipher_index + ASC2_UPPERCASE_START_NUMBER : cipher_index + ASC2_LOWERCASE_START_NUMBER;
            printf("%c", c);
        }else{
            printf("%c", current_char);
        }
    }
    
    printf("\n");
}