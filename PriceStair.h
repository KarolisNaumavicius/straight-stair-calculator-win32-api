#ifndef PRICESTAIR_H
#define PRICESTAIR_H

class PriceStair {
private:
    double priceForAStep;
    double *price;
    int steps;

public:
    PriceStair(int s, double m, double* p) : steps(s), priceForAStep(m), price(p) {};

    void priceStair();

};

#endif