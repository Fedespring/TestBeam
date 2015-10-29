#ifndef clusterizer_h
#define clusterizer_h

#include "cluster1d.h"
#include "cluster2d.h"
#include "hit.h"

#include "math.h"
#include <iostream>
#include <fstream>

namespace clusterizer  {
	
	int clusterize(struct Hit *_GemHit, struct Cluster1d *_GemCluster1d);
    int clusterize2d(struct Cluster1d *_GemCluster1d, struct Cluster2d *_GemCluster2d);

    void NewCluster(struct Hit *_GemHit, struct Cluster1d *_GemCluster1d, int Hit_id, int Clust_id);
    void AddHit(struct Hit *_GemHit, struct Cluster1d *_GemCluster1d, int Hit_id, int Clust_id);
    void Finalize(struct Hit *_GemHit, struct Cluster1d *_GemCluster1d	, int Clust_id);

}

#endif

