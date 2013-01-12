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
#define MAXSIZE 128
#define MAXWORDS 53000

/* Function Prototypes */
size_t CheckFile(const char *input_file, const char *output_file, const char *dicitonary_file);
static size_t LoadDictionary(const char *faname, size_t max_words, char *word_list[max_words]);
static void FreeDictionary(size_t word_count, char *word_list[word_count]);
char *trimwhitespace(char *str);

int main(void){
    const char *input_name = "permutations.txt";
    const char *dictionary_name = "dictionary.txt";
    const char *output_name = "words.txt";
    CheckFile(input_name, output_name, dictionary_name);
    return 0;
}

/*
 * Function: CheckFile
 * =============================
 * Descriptions: Takes in list of words and dictionary files, and appends to specified
 *               output file
 *               
 */
size_t CheckFile(const char *input_file, const char *output_file, const char *dictionary_file)
{
    /*Load the dicitonary*/
    char *dictionary[MAXWORDS] = {0};
    size_t dictionary_size = LoadDictionary(dictionary_file, MAXWORDS, dictionary);
    int i = 0;
    for (i=0; i<dictionary_size; i++)
    {
        printf("MyDic: %s\n",dictionary[i]);
    }
    printf("Dictionary Size: %d\n", dictionary_size);

    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "a");
    
    if (input)
    {
        char fmt[64], word[MAXSIZE];
        sprintf(fmt, " %%%ds", MAXSIZE-1);
        while (fscanf(input, fmt, word) == 1)
        {
            /* TODO: Use the bsearch() call to improve the performace */
            size_t i=0;
            for (i=0; i<dictionary_size; i++)
            {
                if (strcasecmp(word, dictionary[i]) == 0)
                {
                    printf("Valid Word: %s\n", word);
                    fprintf(output, "%s\n", word);
                }
            }
        }
    }
    else
    {
        printf("Error input file %s not found", input_file);
    }
    fclose(input);
    fclose(output);
    FreeDictionary(dictionary_size, dictionary);

    return True;
}


size_t LoadDictionary(const char* fname, size_t max_words, char *word_list[max_words])
{
    int count = 0;
    memset(word_list, 0, sizeof(*word_list)*max_words);
    FILE *fp = fopen(fname, "r");

    if (fp)
    {   
        char fmt[64], word[MAXSIZE];
        sprintf(fmt, " %%%ds", MAXSIZE-1);
        while (fscanf(fp, fmt, word) == 1 && count < max_words)
        {   
            word_list[count] = malloc(strlen(word)+1);
            strcpy(word_list[count++], word);
        }   
        fclose(fp);
    
        /* TODO: sort the word list using `qsort()` to allow binary searching
           and O(logN) search time to find if a word is in the list */
    }   
    return count;

}


void FreeDictionary(size_t word_count, char *word_list[word_count])
{
    size_t i;
    for ( i=0; i<word_count; free(word_list[i]), word_list[i++]=0);
}
