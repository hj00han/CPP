/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 10/09/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_Label_H 
#define SDDS_Label_H
#define MAX_TEXT 70

namespace sdds {
    class Label {
        char m_frame[9];
        char* m_text;
    public:
        Label();
        Label(const char* framArg);
        Label(const char* framArg, const char* content);
        ~Label();
        std::istream& readLabel();
        std::ostream& printLabel()const;
        Label& text(const char* content);
    };
}
#endif