#ifndef cluster2d_h
#define cluster2d_h

#include "parameters.h"


struct Cluster2d
{
    int nCluster2d;
    int plane[maxCluster2d];
    int q[maxCluster2d];
    int qx[maxCluster2d];
    int qy[maxCluster2d];
    double x[maxCluster2d],y[maxCluster2d],z[maxCluster2d];
    double dx[maxCluster2d],dy[maxCluster2d],dz[maxCluster2d];
    int ClusterIdX[maxCluster2d];
    int ClusterIdY[maxCluster2d];
    int nHitX[maxCluster2d];
    int nHitY[maxCluster2d];
    int nHit[maxCluster2d];
};







#endif
