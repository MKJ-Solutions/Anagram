#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ListPermutations(char *letters);
void RecursivePermute(char *prefix, char *rest, int *ptr);
//int  Strlen(char *word);

main()
{
    char letters[] = "AABC";
    ListPermutations(letters);

    return 0;
}

/*
 * Function: ListPermuations
 * Usage:    ListPermuatations(char *)
 * -------------------------------------
 *  This function lists all permuations of a string of letters
 */

void ListPermutations(char *letters)
{
    int count = 0;
    RecursivePermute("", letters, &count);
    printf("Total of %d permutations\n", count);
}


/*
 * Function: RecursivePermute
 * Usage: RecursivePermute (*char prefix, *char rest, int *ptr)
 * --------------------------------------------------------------
 *  Recursive implementation of permutations using prefix and reset
 */

void RecursivePermute (char *prefix, char *rest, int *ptr)
{
    char *temp = malloc(sizeof(char *));
    int idx = 0;
    int first_occurance = 0;
    strcpy(temp, rest);
    if (*rest == '\0')
    {
        *ptr += 1;
        printf(" Permutation %d: %s\n", *ptr, prefix);
    }
    else
    {
        int i;
        size_t rest_size = strlen(rest);
        while (*rest != '\0')
        {
            
            //printf("get here %s\n", rest);
            first_occurance = (strchr(temp, *rest) - temp - idx);
            if (!first_occurance)
                printf("test\n");
            rest++;
            idx ++;
        }
    }
}
        /*for (i = 0; i < rest_size; i++){
            /*
            if (rest.find(rest[i] == i) 
            {
                    string newPrefix = prefix + rest[i];
                    string newRest = rest.substr(0, i) + rest.substr(i+1);
                    RecursivePermute (newPrefix, newRest, ptr);
                    }
                    }
                   */ 

/*
int Strlen (char *word){
    int size = 0;
    while ( *(word++) != '\0' )
        size++;
    return size;
}*/
