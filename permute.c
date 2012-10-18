#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ListPermutations(char *letters);
void RecursivePermute(char *prefix, char *rest, int *ptr);
//int  Strlen(char *word);

main()
{
    char letters[] = "AAB";
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
    //printf("--------------\n");
    //printf("Prefix: %s\n", prefix);
    //printf("Rest  : %s\n", rest);
    char *temp = malloc(sizeof(char *));
    char *new_prefix = malloc(sizeof(char *));
    char *new_rest = malloc(sizeof(char *));
    char *new_rest2 = malloc(sizeof(char *));
    char *new_rest3 = malloc(sizeof(char *));
    char first_char;
    int idx = 0;
    int first_occurance = 0;
    strcpy(temp, rest);
    if (*rest == '\0')
    {
        *ptr += 1;
        printf(" Permutation %d: %s\n", *ptr, prefix);
        printf("--------------\n");
        return;
    }
    else
    {
        int i;
        size_t rest_size = strlen(rest);
        while (*rest != '\0')
        {
            
            first_occurance = (strchr(temp, *rest) - temp - idx);
            if (!first_occurance)
            {
                //new_prefix = strcat(prefix, rest);
                first_char = *rest;
                //printf("INDEX: %d\n", idx);
                //printf("Rest Size: %d\n", rest_size);
                new_rest = strncpy(new_rest, rest-idx, idx);
                new_rest2 = strncpy(new_rest2, rest+1, rest_size-1);
                //printf("NEW_BETA: %s|%s\n", new_rest,new_rest2);
                snprintf(new_rest3, sizeof new_rest3, "%s%s", new_rest, new_rest2);
                //printf("NEW_REST: %s\n", new_rest3);
                snprintf(new_prefix, sizeof new_prefix, "%s%s", prefix, &first_char);
                //printf("NEW_PREF: %s\n", new_prefix);
                //printf("Prefix: %s\n", prefix);
                //printf("Rest : %c\n", first_char);
                //printf("AM i working? %s\n", new_prefix);
                RecursivePermute( new_prefix, new_rest3, ptr);
            }
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
