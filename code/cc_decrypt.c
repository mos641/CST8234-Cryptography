/******************************************************************************************
*Assignment Name:    Lab 2: To perform Data Cryptography and De-cryptography
*Course:             C Language CST8234
*Source Files:       cc_encrypt.c cc_decrypt.c
******************************************************************************************/

/******************************************************************************************
*Filename:           cc_encrypt.c
*Version:            1
*Course:             C Language CST8234
*Assignment Name:    Lab 2: Decrypt
*Purpose:            Use a rotation key to decrypt messages
******************************************************************************************/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_MESSAGE 80

void encryption(char originalMessage[], char alteredMessage[], int key);

/******************************************************************************************
*Function name:              main
*Purpose:                    Main function for the program - decrypt a message
*Function In parameters:     None
*Function Out parameters:    An integer for function success
*Version:                    1
*Author:                     mos
******************************************************************************************/
int main(void)
{
    char alteredMessage[MAX_MESSAGE + 1];
    char originalMessage[MAX_MESSAGE + 1];
    int key = -1;
    originalMessage[0] = '\n';
    alteredMessage[0] = '\n';

    /* ask and store input, loops to validate */
    while (originalMessage[0] == '\n')
    {
        printf("Enter message to decrypt: \n");
        scanf("%80[^\n]*c", originalMessage);
        if (originalMessage[0] == '\n')
        {
            printf("Error - no message. Try again...");
        }
        while (getchar() != '\n');
    }

    while ((key < 0) || (key > 26))
    {
        key = -1;
        printf("Enter rotation key: \n");
        scanf("%d", &key);
        /* validate */
        if (isdigit(key) != 0)
        {
            printf("Error - key must be in range 0 and 26. Try again. \n");
            key = -1;
        }
        else if (key < 0 || key > 26)
        {
            printf("Error - key must be in range 0 and 26. Try again. \n");
        }
        while (getchar() != '\n');
    }
    key = 26 - key;

    encryption(originalMessage, alteredMessage, key);

    printf("\nDecrypting message (key = %d): %s\n\n\n%s\n", key, originalMessage, alteredMessage);

    return EXIT_SUCCESS;
}

/******************************************************************************************
*Function name:              encryption
*Purpose:                    Pass through a string and rotation key to encrypt or decrypt the string
*Function In parameters:     String for original message, String for altered message and Rotation key
*Function Out parameters:    None
*Version:                    1
*Author:                     mos
******************************************************************************************/
void encryption(char originalMessage[], char alteredMessage[], int key)
{
    int index;
    char character;

    /* loop through string until null to decrypt, replace each character with new one */
    for (index = 0; index < MAX_MESSAGE; index++)
    {
        /* store, if it becomes out of alphabet range bring it back to a, put in new array */
        character = originalMessage[index];
        if (character >= 'a' && character <= 'z')
        {
            if (originalMessage[index] + key > 'z')
            {
                character = originalMessage[index] + (key - 26);
            }
            else
            {
                character = (character + key);
            }
        }
        else if (character >= 'A' && character <= 'Z')
        {
            if (originalMessage[index] + key > 'Z')
            {
                character = originalMessage[index] + (key - 26);
            }
            else
            {
                character = (character + key);
            }
        }

        alteredMessage[index] = character;
    }
}
