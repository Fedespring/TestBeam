#ifndef rec_h
#define rec_h

#include "parameters.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TNtupleD.h"
#include "TH1.h"
#include "TH2.h"
#include <TStyle.h>
#include "TString.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TMath.h"
#include "TVectorT.h"


#include <iostream>
#include <vector>

TFile *myfile;
const int TRKA=0;
const int TRKB=1;
const int TRKC=5;  //Plane 5 must be set only on TRKC CAMBIATA DA 2 A 4
const int TRKD=6;
const int TEST=2;


// B = 0T
const float tiltX_TRKA = -0.84;
const float tiltX_TRKB = 0.64;
const float tiltX_TRKC = 0.13;
const float tiltX_TRKD = -1.69;
const float tiltY_TRKA = 0.47;
const float tiltY_TRKB = -0.47;
const float tiltY_TRKC = 0.;
const float tiltY_TRKD = 0.02;

/*
// B = 1T
const float tiltX_TRKA = -0.66;
const float tiltX_TRKB = .96;
const float tiltX_TRKC = 0.83;
const float tiltX_TRKD = -0.96;
const float tiltY_TRKA = -0.56;
const float tiltY_TRKB = -1.251;
const float tiltY_TRKC = 0.;
const float tiltY_TRKD = -0.03;
*/

//const float tiltX_TEST = -2.05; // B = 1 T
//const float tiltY_TEST = -6.26; // B = 1 T

//const float tiltX_TEST = -1.98; // B = -1 T 
//const float tiltY_TEST = 3.19; // B = -1 T

//const float tiltX_TEST = -2.05; // B = 0.5 T
//const float tiltY_TEST = -3.9; // B = 0.5 T

const float tiltX_TEST = -2.43; // ok up to run 275
const float tiltY_TEST = -1.1; //for first run no B run 203, 204, 205
//const float tiltY_TEST = -0.96; //264-271
//const float tiltY_TEST = -2.1; //313-315                                                                                                             
//const float tiltX_TEST = -2.06; //313-315


int  NTRKA_0, NTRKB_0, NTRKC_0, NTRKD_0, NTEST_0, NTRKA_1, NTRKB_1, NTRKC_1, NTRKD_1, NTEST_1;
int NGOOD; //Number of "good events" 
int  NGOODTestX;
int  NGOODTestY;
int NGOODTestXY;
int nGOODmin3sX;
int nGOODmin3sY;	
int nGOODmin3sXY;

int nGemClustermin3sX;
int nGemClustermin3sY;

int nGemClusterExtraX;
int nGemClusterExtraY;

double Chi2X, Chi2Y;

float dispY_trkA, dispY_trkB, dispY_trkD;
float dispX_trkA, dispX_trkB, dispX_trkC, dispX_trkD;

TH1I *cluster_size_trkA_X;
TH1I *cluster_size_trkB_X;
TH1I *cluster_size_trkC_X;
TH1I *cluster_size_trkD_X;

TH1I *cluster_size_trkA_Y;
TH1I *cluster_size_trkB_Y;
TH1I *cluster_size_trkD_Y;

TH1I *cluster_size_test_min3sX;
TH1I *cluster_size_test_min3sY;

TH1I *cluster_size_test_ExtraX;
TH1I *cluster_size_test_ExtraY;

TH1I *numClust;

TH1I *numClustX;
TH1I *numClustY;
	
TH1I *numClustmin3sX;
TH1I *numExtraClustX;

TH1I *numClustmin3sY;
TH1I *numExtraClustY;

TH1D *HresX;
TH1D *HresY;
TH1D *HresAllX;
TH1D *HresAllY;
TH1D *ChiresX;
TH1D *ChiresY;

TH1F *HresY_trkA;
TH1F *HresY_trkB;
TH1F *HresY_trkD;

TH1F *HresX_trkA;
TH1F *HresX_trkB;
TH1F *HresX_trkC;
TH1F *HresX_trkD;

TH2F *map_xAvsxB;
TH2F *map_xAvsxC;
TH2F *map_xAvsxD;

TH2F *map_yAvsyB;
TH2F *map_yAvsyC;
TH2F *map_yAvsyD;

TH1F *QX,*QY,QTOT;

#endif

// 0 -> -1.7
// 1 -> 1.1
// 2 ->
// 5 ->
// 6 ->
