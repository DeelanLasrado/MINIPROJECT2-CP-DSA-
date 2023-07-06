#include <stdio.h>
#include <string.h>

void encode(char s[], int k) {
    // changed string
    char newS[100];
    int i, val, encodedVal;

    // iterate for every character
    for (i = 0; i < strlen(s); ++i) {
        // ASCII value
        val = s[i];

        // calculate the new character value
        encodedVal = val + k;

        // handle wrap-around for characters after 'z'
        if (encodedVal > 122) {
            encodedVal = 97 + (encodedVal - 123);
        }

        // append the encoded character to the new string
        newS[i] = (char)encodedVal;
    }
    newS[i] = '\0';

    // print the new string
    printf("The encoded message is %s\n", newS);
}

void decode(char s[], int k) {
    // changed string
    char newS[100];
    int i, val, decodedVal;

    // iterate for every character
    for (i = 0; i < strlen(s); ++i) {
        // ASCII value
        val = s[i];

        // calculate the new character value
        decodedVal = val - k;

        // handle wrap-around for characters before 'a'
        if (decodedVal < 97) {
            decodedVal = 123 - (97 - decodedVal);
        }

        // append the decoded character to the new string
        newS[i] = (char)decodedVal;
    }
    newS[i] = '\0';

    // print the new string
    printf("The decoded message is %s\n", newS);
}

int main() {
    char str[100];
    int k;
    char s[10];

    printf("Type encode to encrypt and decode to decrypt: ");
    scanf("%s", s);

    printf("\nType the message: ");
    scanf("%s", str);

    printf("\nEnter the number of shifts: ");
    scanf("%d", &k);

    // function call
    if (strcmp(s, "decode") == 0)
        decode(str, k);
    else if (strcmp(s, "encode") == 0)
        encode(str, k);

    return 0;
}
