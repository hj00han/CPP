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
