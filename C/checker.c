/*
 * File: verify_word.c
 * Author: Miles Tjandrawidjaja
 * Last Updated: 11/25/2012
 * =========================
 * Description: This will take in a dictionary text file, and input text file, and verify input 
 *              text files for valid words. Ouput file is words.txt.Dictionary file is dictionary.txt            
 *
 */


/*
 * Notes
 * ==========
 * 1. If comparing strings (*char) with ==
 *    You are actually comparing their addresses
 *    Solution to this is use strcmp or strcasecmp
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int bool;
#define True 1
#define False 0

#define MAXSIZE 6
/* Function Prototypes */
void write_valid_words(char *input_file, char *dictionary_file, char *output_file);
char *trimwhitespace(char *str);

int main(void){
    char *input_name = "permutations.txt";
    char *dictionary_name = "dictionary.txt";
    char *output_name = "words.txt";
    write_valid_words(input_name, dictionary_name, output_name);
    return 0;
}

/*
 * Function: write_valid_words
 * =============================
 * Descriptions: Takes in list of words and dictionary files, and appends to specified
 *               output file
 *               
 */
void write_valid_words(char *input_file, char *dictionary_file, char *output_file)
{
    /* Open files as read or append */
    FILE *input, *dictionary, *output;
    input = fopen(input_file, "r");
    dictionary = fopen(dictionary_file, "r");
    output = fopen(output_file,"a");

    /* Read from files */
    if (input != NULL && dictionary!= NULL)
    {
        char *iline = malloc(MAXSIZE*sizeof(char)); 
        char *dline = malloc(MAXSIZE*sizeof(char));

        while (fgets (iline, sizeof iline, input) != NULL)
        {
            while (fgets (dline, sizeof dline, dictionary) != NULL)
            {
                trimwhitespace(iline);
                trimwhitespace(dline);
                if (strcasecmp(iline, dline) == 0 )
                {
                    fprintf(output, "%s\n",iline);
                }

            }
            rewind(dictionary);
        }

        fclose(input);
        fclose(dictionary);
        fclose(output);
        free(iline);
        free(dline);
    }
    else
    {
        printf("An error has occured\n");
    }
}

/*
 * Function: trimwhitesapce(char *str)
 * Description: This function removes any whitespace
 */
char *trimwhitespace(char *str)
{
  char *end;

  /* Trim leading Whitespace */
  while(isspace(*str)) str++;

  /* Check if string is empty*/
  if(*str == 0) { return str; }

  /* Trim trailing whitesapce */
  end = str + strlen(str) - 1;
  while(end > str && isspace(*end)) end--; 

  /* Add new terminating character */
  *(end+1) = 0;

  return str;
}
