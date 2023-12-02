#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_

namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;

    public:
        Portfolio();
        void emptyPortfolio();
        Portfolio(double value, const char* stock, char type);
        void dispPortfolio() const;
        std::ostream& display() const;
        operator double() const;
        operator const char* () const;
        operator char() const;
        operator bool() const;
        Portfolio& operator +=(double value);
        Portfolio& operator -=(double value);
        bool operator ~() const;
        Portfolio& operator <<(Portfolio& rightOp);
        Portfolio& operator >>(Portfolio& rightOp);
    };
    double operator +(const Portfolio& leftOp, const Portfolio& rightOp);
    double operator +=(double& value, const Portfolio& rightOp);
}
#endif // SDDS_Portfolio_H_
