#ifndef rec_h
#define rec_h

#include "parameters.h"
#include "hit.h"
#include "cluster1d.h"
#include "cluster2d.h"

#include "TFile.h"
#include "TNtuple.h"
#include "TNtupleD.h"
#include <TH2.h>
#include <TStyle.h>
#include <TROOT.h>

#include <iostream>
#include <vector>

int Event;

int nGemHit;
int nGemCluster;
int nGemCluster2d;

struct Hit GemHit;
struct Cluster1d GemCluster1d;
struct Cluster2d GemCluster2d;


TFile *fFile;
TTree *t1;


//int Hit_Strip[maxHit];



#endif
