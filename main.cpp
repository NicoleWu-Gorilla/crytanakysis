#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

static const int maxNum = 101;
static const int letterNum = 26;

struct LetterCount {
    char letter;
    int count;
};

void initialArray(LetterCount array[]) {
    for (int i = 0; i < letterNum; i++) {
        array[i].letter = 'A' + i;
    }
}

void countLetters(char line[], LetterCount array[])
{
    int charIndex = 0;
    int targetIndex = 0;

    while(charIndex < strlen(line)) {
        // skip non-char
        if (isalpha(line[charIndex])) {
            targetIndex = (line[charIndex] >= 'A' && line[charIndex] <= 'Z') ? line[charIndex] % 65 : targetIndex = line[charIndex] % 97;
            array[targetIndex].count += 1;
        }

        charIndex++;
    }
}

bool compare(LetterCount a, LetterCount b)
{
    return a.count > b.count || (a.count == b.count && a.letter < b.letter);
}

void printResult(LetterCount array[]) 
{
    int loc = 0;
    while (array[loc].count > 0 && loc < letterNum)
    {
        printf("%c %d\n", array[loc].letter, array[loc].count);
        loc++;
    }
    
}

int main()
{
    int lineNum;
    int lineCount = 0;
    char line[maxNum] = {0};
    LetterCount array[letterNum] = {0};
    
    initialArray(array);

    // get line number & skip \n
    scanf("%d", &lineNum);
    getchar();

    while(scanf("%[^\n]", line) == 1 && lineCount < lineNum) {
        countLetters(line, array);
        lineCount++;
        getchar();
    }

    sort(array, array + letterNum, compare);
    printResult(array);

    return 0;
}