/*
 * File: checker.c
 * Author: Miles Tjandrawidjaja
 * Credits: WhozCraig
 * Last Updated: 01/12/2013
 * =========================
 * Description: This will take in a dictionary text file, and input text file, and verify input 
 *              text files for valid words. Ouput file is words.txt.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int bool;
#define True 1
#define False 0
#define MAXSIZE 128
#define DICTSIZE 53000
#define MAXWORDS 50

/* Function Prototypes */
unsigned int CheckFile(const char *input_file, const char *output_file, const char *dicitonary_file);
static size_t LoadFile(const char *faname, size_t max_words, char *word_list[max_words]);
static void FreeFile(size_t word_count, char *word_list[word_count]);
bool isValid(const char *word, size_t max_words, char *dictionary[max_words]);

int main(void){
    const char *input_name = "permutations.txt";
    const char *dictionary_name = "dictionary.txt";
    const char *output_name = "words.txt";
    unsigned num_words = CheckFile(input_name, output_name, dictionary_name);
    char *valid_words[MAXWORDS] = {0};
    size_t word_size = LoadFile(output_name, MAXWORDS, valid_words);

    /* Demonstration on how to use the functions */
    int i;
    for (i=0; i<word_size; i++)
    {
        printf("Word: %s\n",valid_words[i]);
    }
    printf("Number of Valid Words: %d\n", word_size);
    
    bool test;
    const char *rand_word = "miles";
    test = isValid(rand_word, word_size, valid_words);
    if (test)
    {
        printf("Valid Word\n");
    }
    else
    {
        printf("Invalid Word\n");
    }
    return 0;
}

/*
 * Function: CheckFile
 * =============================
 * Descriptions: Input location for input file and dictionary file and write the intersection of contents into output file
 *               
 */
unsigned int CheckFile(const char *input_file, const char *output_file, const char *dictionary_file)
{
    /*Load the dicitonary*/
    char *dictionary[DICTSIZE] = {0};
    size_t dictionary_size = LoadFile(dictionary_file, DICTSIZE, dictionary);
    int i;
    int num_words = 0;
    char *ptr_item;

    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");
    
    if (input)
    {
        char fmt[64], word[MAXSIZE];
        sprintf(fmt, " %%%ds", MAXSIZE-1);
        while (fscanf(input, fmt, word) == 1)
        {
            /* TODO: Use the bsearch() call to improve the performace */
            /*ptr_item = bsearch(word, dictionary, dictionary_size, strlen(word)+1, (int(*)(const void*, const void*))strcasecmp);
            if (ptr_item != NULL)
            {
                num_words++;
                fprintf(output, "%s\n", word);
            }
            else
            {
                printf("Nothing was found\n");
            }*/
            for (i=0; i<dictionary_size; i++)
            {
                if (strcasecmp(word, dictionary[i]) == 0)
                {
                    num_words++;
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
    FreeFile(dictionary_size, dictionary);

    return num_words;
}


/*
 * Function: LoadFile
 * =============================
 * Descriptions: Load contents of text file into memory
 *               
 */
size_t LoadFile(const char* fname, size_t max_words, char *word_list[max_words])
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
        /* TODO: May want to look into qsort() */
    }   
    return count;
}


/*
 * Function: FreeFile
 * =============================
 * Descriptions: Release word list that was loaded from LoadFile
 *               
 */
void FreeFile(size_t word_count, char *word_list[word_count])
{
    size_t i;
    for (i=0; i<word_count; free(word_list[i]), word_list[i++]=0);
}

/*
 * Function: isValid
 * ==================
 * Description: Checks if the word is valid against a dictionary
 */
bool isValid(const char *word, size_t max_words, char *dictionary[max_words])
{
    int i;
    for (i=0; i<max_words; i++)
    {
        if (strcasecmp(word, dictionary[i]) == 0)
        {
            printf("Dictionary: %s\n", dictionary[i]);
            printf("Word: %s\n", word);
            return True;
        }
    }
    return False;
}
