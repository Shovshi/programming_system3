#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define WORD 30
#define LINE 256

void inputKeyword( char * str);
void inputOption(char * option);
void findLines(char key []);
int subString(char * str1 , char * str2);
void findWords(char key []);
int isSimilar(char * key  , char * word);

int main()
{


    char option = 0;
    char keyWord[WORD];

    // we take input and set it as the keyword we will look for in the text
    // and what kind of option we would like to search
    inputKeyword(keyWord);
    inputOption(&option);

    //to scan the spare enter in between the text and the option letter
    char c = 0;
    scanf("%c\n", &c);

    //if option is a we search the lines , if b we search for similar words
    if(option == 97)
    {
        findLines(keyWord);
    }
    else
    {
        findWords(keyWord);
    }

}

// take input from user for they keyword
void inputKeyword(char * str)
{
    int i = 0;
    char c = 0;
    while (c != 32)
    {
        scanf("%c", &c);
        str[i] = c;
        i++; 
    }

    str[i - 1] = '\0';
}

// take input from user as what search option to use
void inputOption(char * option)
{
    char c = 0;

    scanf("%c", &c);
    *option = c;
}

// we search the lines that hold they keyword
void findLines(char key [])
{
    char line[LINE];
    char c = 0;
    int i = 0;

    while (scanf("%c", &c) != EOF)
    {
        if(c != '\n')
        {
            line[i] = c;
            i++;
        }
        else
        {
           line[i] = '\0'; // we add a \0 so we know the string is done
           if(subString(line , key) == 1) // if the line has the keyword, we print it
           {
              printf("%s\n" , line);
           }
           i = 0; 
        }
    }
}

// we check if a certain key is inside the line
int subString(char * line , char * key)
{
    char * cLine = line;
    char * cKey = key;
    int i = 0;

    while (*(cLine) != '\0')
    {
        i = 0;
        while (*(cLine) == *(cKey))
        {
            cLine++;
            cKey++;
            i++;
            if (*(cKey)== '\0')
            {
                return 1;
            }            
        }

        cLine = cLine - i;
        cKey = cKey - i;

        cLine++; 
    }  
    
    return 0;
}

// we scan through the text according to option b and check each word
// if it is similar to our key word, if so we print it
void findWords (char key [])
{
    char word[WORD];
    char c = 0;
    int i = 0;

    while (scanf("%c" , &c) != EOF)
    {
        if(c == '\n' || c == 32)
        {
            word[i] = '\0';
            i = 0;

            if (isSimilar(key, word))
            {
                printf("%s\n", word);
            }
            
        }
        else
        {
            word[i] = c;
            i++;
        }
        
    }
        
}

// we check if the word we received is similar to the keyword by one letter difference
int isSimilar(char * key  , char * word )
{
    int cnt = 0;
    char * cWord = word;
    char * cKey = key;

    int keyLength = strlen(key);
    int wordLength = strlen(word);
    int difference = wordLength - keyLength;

    if(difference < 0 || difference > 1)
    {
        return 0;
    }

    while(*(cWord) != '\0')
    {
        if(*(cWord)== *(cKey))
        {
            cKey++;
            cWord++;
        }
        else
        {
            cnt++;
            cWord++;
        }
    }

    if(cnt <= 1)
    {
        return 1;
    }   
    
    return 0;
}