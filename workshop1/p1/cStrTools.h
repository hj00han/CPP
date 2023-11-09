/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 9/14/2023
***********************************************************************/

#ifndef SDDS_cStrTools_H // replace with relevant names
#define SDDS_cStrTools_H

namespace sdds{
char toLower(char ch);
int strCmp(const char* s1, const char* s2);
int strnCmp(const char* s1, const char* s2, int len);
const char* strStr(const char* str, const char* find);
void strCpy(char* des, const char* src);
int strLen(const char* str);
int isAlpha(char ch);
int isSpace(char ch);
void trim(char word[]);
void toLowerCaseAndCopy(char des[], const char source[]);
}

#endif