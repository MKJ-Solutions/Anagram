#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ListPermutations(char *letters);
void RecursivePermute(char *prefix, char *rest, int *ptr);

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
    char *temp = malloc(sizeof(char *));
    char *new_prefix = malloc(sizeof(char *));
    char *rest_left = malloc(sizeof(char *));
    char *rest_right = malloc(sizeof(char *));
    char *new_rest = malloc(sizeof(char *));
    char rest_char;
    int idx = 0;
    int first_occurance = 0;
    int i;
    FILE *file;
    strcpy(temp, rest);
    if (*rest == '\0')
    {
        *ptr += 1;
        printf("Permutation %d: %s\n", *ptr, prefix);
        file = fopen("permutations.txt", "a");
        fprintf(file,"%s\n",prefix);
        fclose(file);
        return;
    }
    else
    {
        size_t rest_size = strlen(rest);
        while (*rest != '\0')
        {
            
            first_occurance = (strchr(temp, *rest) - temp - idx);
            if (first_occurance == 0)
            {
                rest_char = *rest;
                rest_left = strncpy(rest_left, rest-idx, idx);
                rest_right = strncpy(rest_right, rest+1, rest_size-1);
                sprintf(new_rest, "%s%s", rest_left, rest_right);
                sprintf(new_prefix,"%s%c", prefix, rest_char);
                RecursivePermute( new_prefix, new_rest, ptr);
            }
            rest++;
            idx ++;
        }
    }
}
