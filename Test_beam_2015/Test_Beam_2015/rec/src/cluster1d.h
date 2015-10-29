#ifndef cluster1d_h
#define cluster1d_h

#include "parameters.h"


struct Cluster1d
{
    int nCluster;
    int plane[maxCluster1d];
    int view[maxCluster1d];
    int q[maxCluster1d];
    double x[maxCluster1d],y[maxCluster1d],z[maxCluster1d];
    double dx[maxCluster1d],dy[maxCluster1d],dz[maxCluster1d];
    int nHit[maxCluster1d];
    int HitIndex[maxCluster1d][maxHit];
    bool isGood[maxCluster1d];
};







#endif
