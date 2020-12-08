#include <iostream>
#include <string>

#define CHARS 256

using namespace std;

void preprocess_bc(int* bc, char* pat, int m)
{
    for (int i = 0; i < CHARS; i++) {
        bc[i] = -1;
    }

    for (int i = 0; i < m - 1; i++) {
        bc[(int)pat[i]] = i;
    }
}

void preprocess_case1(int* shift, int* bpos, char* pat, int m)
{
    int i = m, j = m + 1;
    bpos[i] = j;

    while (i > 0)
    {
        while (j <= m && pat[i - 1] != pat[j - 1])
        {
            if (shift[j] == 0)
                shift[j] = j - i;

            j = bpos[j];
        }

        i--;
        j--;
        bpos[i] = j;
    }
}

void preprocess_case2(int* shift, int* bpos, char* pat, int m)
{
    int i, j;
    j = bpos[0];
    for (i = 0; i <= m; i++)
    {
        if (shift[i] == 0)
            shift[i] = j;

        if (i == j)
            j = bpos[j];
    }
}

//void Search(char* pat, char* txt)
//{
//    int txtLen = strlen(txt);
//    int patLen = strlen(pat);
//    int* bc = preprocess_bc(pat, patLen);
//    int shift = 0;
//    int patIdx = 0;
//
//    while (shift <= (txtLen - patLen)) {
//        patIdx = patLen - 1;
//
//        while (patIdx >= 0 && pat[patIdx] == txt[shift + patIdx]) {
//            patIdx--;
//        }
//
//        if (patIdx < 0) {
//            cout << "String found at index " << shift << endl;
//
//            shift = shift + ((shift + patLen < txtLen) ? patLen - bc[txt[shift + patLen]] : 1);
//        }
//        else {
//            shift = shift + max(1, patIdx - bc[txt[shift + patIdx]]);
//        }
//    }
//
//    delete bc;
//}

void search(char* text, char* pat)
{
    int s = 0, j;
    const int m = strlen(pat);
    const int n = strlen(text);

    int* bc = new int[CHARS];
    int* bpos = new int[m + 1];
    int* shift = new int[m + 1];

    for (int i = 0; i < m + 1; i++) shift[i] = 0;

    preprocess_bc(bc, pat, m);
    preprocess_case1(shift, bpos, pat, m);
    preprocess_case2(shift, bpos, pat, m);

    while (s <= n - m)
    {

        j = m - 1;

        while (j >= 0 && pat[j] == text[s + j])
            j--;

        if (j < 0)
        {
            cout << "pattern occurs at shift : " << s << endl;
            s += shift[0];
        }
        else
            s += max(shift[j + 1], j - bc[text[s + j]]);
    }

    delete[] bc;
    delete[] bpos;
    delete[] shift;
}

int main()
{
    char text[] = "ABAAAABAACD";
    char pat[] = "ABA";
    search(text, pat);

    return 0;
}