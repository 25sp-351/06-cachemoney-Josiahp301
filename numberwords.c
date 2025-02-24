#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "numberwords.h"
#include "cache.h"

#define BUFFER_SIZE 256



const char* ones[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen"
};

const char* tens[] = {
    "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
    "eighty", "ninety"
};

const char* powers[] = {
    "thousand", "million", "billion"
};





void number_to_text(int num, char* result) {
    if (num == 0) {
        strcpy(result, "zero");
        return;
    }

    if (num < 0) {
        strcpy(result, "negative ");
        number_to_text(-1 * num, result + strlen(result));
        return;
    }

    if (num < 20) {
        strcpy(result, ones[num]);
    } else if (num < 100) {
        strcpy(result, tens[num / 10 - 2]);
        if (num % 10 != 0) {
            strcat(result, " ");
            number_to_text(num % 10, result + strlen(result));
        }
    } else if (num < 1000) {
        number_to_text(num / 100, result);
        strcat(result, " hundred");
        if (num % 100 != 0) {
            strcat(result, " ");
            number_to_text(num % 100, result + strlen(result));
        }
    } else {
        int power_index = 0;
        int divisor = 1000;
        while (num / divisor >= 1000) {
            divisor *= 1000;
            power_index++;
        }
        number_to_text(num / divisor, result);
        strcat(result, " ");
        strcat(result, powers[power_index]);
        if (num % divisor != 0) {
            strcat(result, " ");
            number_to_text(num % divisor, result + strlen(result));
        }
    }

}

int number_to_string() {
    initialize_cache();

    int num;
   // printf("Enter a number in cents: ");
    scanf("%d", &num);
    char result[BUFFER_SIZE];



    int dollars = num / 100;
    int cents = num % 100;

    char dollar_text[BUFFER_SIZE];
    char cent_text[BUFFER_SIZE];

    number_to_text(dollars, dollar_text);
    number_to_text(cents, cent_text);

    if (dollars > 0 && cents > 0) {
        snprintf(result, BUFFER_SIZE, "%s dollars and %s cents", dollar_text, cent_text);
    } else if (dollars > 0) {
        snprintf(result, BUFFER_SIZE, "%s dollars", dollar_text);
    } else {
        snprintf(result, BUFFER_SIZE, "%s cents", cent_text);
    }

    printf(result);

    return 0;
}