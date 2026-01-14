#ifndef STRAIGHTSTAIR_H
#define STRAIGHTSTAIR_H

class StraightStair {
private:
    double floorToFloorHeight, ceilingLength, ceiling, headroomRise, openingLength;
    int steps;
    double *rise, *run, *lengthStair, *headroom;
public:

    StraightStair(double f, double* l, int s, double c, double o, double* run, double* rise, double* headroom) : floorToFloorHeight(f), lengthStair(l), steps(s), ceiling(c), openingLength(o), run(run), rise(rise), headroom(headroom) {};

    void riseAndRunCalculator();

    void lengthByRunCalculator();

    void headroomCalculator();

};

#endif