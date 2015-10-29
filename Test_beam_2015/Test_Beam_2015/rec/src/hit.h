#ifndef hit_h
#define hit_h

#include "parameters.h"

struct Hit
{
    int nHit;
    int apv[maxHit];
    int plane[maxHit];
    int view[maxHit];
    int half[maxHit];
    int sample[maxHit];
    int strip[maxHit];
    float q[maxHit];
    //float qRead[maxHit];
    int readoutch[maxHit];
    double x[maxHit],y[maxHit],z[maxHit];
};



#endif