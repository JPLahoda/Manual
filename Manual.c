/*
* Name: Jason Lahoda
* Section: 03
* Lab: CIS2107_Lab08_Manual
* Goal: To design and implement functions taking pointers as arguments
to process characters and strings.
*/
#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char
*s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char
*s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);
int main() {
//random generator
srand(time(NULL));
//test for upperLower
const char test[] = "This iS A Test";
upperLower(test);
//test for convertStrtoInt
printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));
//test for convertStrtoFloat
printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5",
"5.5", "6.5"));
//test for compareStr
compareStr("Test1", "Test2");
//test for comparePartialStr
comparePartialStr("Test1", "Test2", 4);
//test for randomize
randomize();
//test for tokenize number
char str[] = "(267) 436-6281";
tokenizeTelNum(str);
//test for reverse
char line[] = "Hello world";
reverse(line);
//test for countSubstr
char *line1 = "helloworldworld";
char *substring = "world";
printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1,
countSubstr(line1, substring));
//test for countChar
char w = 'w';
printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1,
w));
//test for countAlpha
char str1[] = "Hello it's me.";
countAlpha(str1);
//test for countWords
char countstring[] = "hello world!";
printf("\n\nNumber of words in string is: %d\n", countWords(countstring));
//test for startsWithB
char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
startsWithB(series);
//test for endsWithed
endsWithed(series);
}
// 1.(Displaying Strings in Uppercase and Lowercase)
void * upperLower (const char * s) {
    char lower[strlen(s) + 1];
    char upper[strlen(s) + 1];
    int i = 0;
    while (s[i]) {
        lower[i] = tolower(s[i]);
        upper[i] = toupper(s[i]);
        i++;
    }
    lower[i] = '\0';
    upper[i] = '\0';
    printf("Original string: %s\n", s);
    printf("Lowercase string: %s\n", lower);
    printf("Uppercase string: %s\n", upper);
}
// 2.(Converting Strings to Integers for Calculations)
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    int sum = atoi(s1) + atoi(s2) + atoi(s3) + atoi(s4);
    return sum;
}
//3.(Converting Strings to Floating Point for Calculations)
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char
*s4) {
    float sum = atof(s1) + atof(s2) + atof(s3) + atof(s4);
    return sum;
}
//4.(Comparing Strings)
void compareStr(const char *s1, const char *s2) {
    int compare = strcmp(s1, s2);
    if (compare == 0) {
        printf("\n\n%s and %s are equal.\n", s1, s2);
    } else if (compare < 0) {
        printf("\n\n%s is less than %s.\n", s1, s2);
    } else {
        printf("\n\n%s is greater than %s.\n", s1, s2);
    }
}
//5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n) {
    int compare = strncmp(s1, s2, n);
    if (compare == 0) {
        printf("\nThe first %d characters of %s and %s are equal\n", n, s1, s2);
    } else if (compare < 0) {
        printf("\nThe first %d characters of %s are less than %s\n", n, s1, s2);
    } else {
        printf("\nThe first %d characters of %s are greater than %s\n", n, s1, s2);
    }
}
//6.(Random Sentences)
void randomize(void) {
    const char *articles[] = {"the", "a", "one", "some", "any"};
    const char *nouns[] = {"boy", "girl", "dog", "town", "car"};
    const char *verbs[] = {"drove", "jumped", "ran", "walked", "skipped"};
    const char *prepositions[] = {"to", "from", "over", "under", "on"};
    for (int i = 0; i < 20; i++) {
        printf("\n%s %s %s %s %s %s.\n", articles[rand() % 5], nouns[rand() % 5], verbs[rand() % 5], prepositions[rand() % 5], articles[rand() % 5], nouns[rand() % 5]);
    }
    printf("\n");
}
//7.(Tokenizing Telephone Numbers)
int tokenizeTelNum(char *num) {
    char* token;
    char* areaCode;
    char* firstThreeDigits;
    char* lastFourDigits;
    char phoneNumber[8];
    int areaCodeInt;

    token = strtok(num, "() ");
    areaCode = token;

    token = strtok(NULL, "-");
    firstThreeDigits = token;

    token = strtok(NULL, "-");
    lastFourDigits = token;

    strcpy(phoneNumber, firstThreeDigits);
    strcat(phoneNumber, lastFourDigits);

    areaCodeInt = atoi(areaCode);

    long phoneNumberLong = atol(phoneNumber);

    printf("Area code: %d\n", areaCodeInt);
    printf("Phone number: %ld\n", phoneNumberLong);
}
//8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text) {
    printf("\n");
    char *word = strtok(text, " ");
    if (word == NULL) {
        return;
    }
    reverse(NULL);
    printf("%s ", word);
}
//9.(Counting the Occurrences of a Substring)
int countSubstr (char * line, char * sub) {
    int count = 0;
    char *ptr = line;
    while ((ptr = strstr(ptr, sub))) {
        count++;
        ptr++;
    }
    return count;
}
//10.(Counting the Occurrences of a Character)
int countChar (char *line, char c) {
    int count = 0;
    char *ptr;
    ptr = strchr(line, c);
    while (ptr != NULL) {
        count++;
        ptr = strchr(ptr + 1, c);
    }
    return count;
}
//11.(Counting the Letters of the Alphabet in a String)
void countAlpha(char *string) {
    int count[26] = {0};
    char *p;
    for (p = string; *p; p++) {
        if (isalpha(*p)) {
            count[toupper(*p) - 'A']++;
        }
    }
    printf("\n");
    printf("Letter\tCount\n");
    for (int i = 0; i < 26; i++) {
        printf("%c\t%d\n", 'A' + i, count[i]);
    }
}
//12.(Counting the Number of Words in a String)
int countWords(char *string) {
    int count = 0;
    char *token = strtok(string, " \n");

    while (token != NULL) {
        count++;
        token = strtok(NULL, " \n");
    }

    return count;
}
//13.(Strings Starting with "b")
void startsWithB(char *string[]) {
    for (int i = 0; string[i] != NULL; i++) {
        if (string[i][0] == 'b' || string[i][0] == 'B') {
            printf("%s\n", string[i]);
        }
    }
}
//14.(Strings Ending with "ed")
void endsWithed(char *string[]) {
    for (int i = 0; string[i] != NULL; i++) {
        int len = strlen(string[i]);
        if (len >= 2 && string[i][len-2] == 'e' && string[i][len-1] == 'd') {
            printf("%s\n", string[i]);
        }
    }
}