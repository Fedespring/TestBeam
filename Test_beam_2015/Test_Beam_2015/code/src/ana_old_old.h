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
const int WELL=4;


// B = 0T
const float tiltX_TRKA = -0.84;
const float tiltX_TRKB = 0.64;
const float tiltX_TRKC = 0.13;
const float tiltX_TRKD = -1.69;

/*const float tiltY_TRKA = 0.47;
const float tiltY_TRKB = -0.47;
const float tiltY_TRKC = 0.;
const float tiltY_TRKD = 0.02;*/
const float tiltY_TRKA = -0.06;
const float tiltY_TRKB = 0.06;
const float tiltY_TRKC = 0.;
const float tiltY_TRKD = 0.1;

const float tiltX_TEST = -2.06; //-1.98  
const float tiltY_TEST = 0.254;//-3.93

//WELL PART
//const float tiltY_WELL = 0.862;
const float tiltY_WELL = -0.262;

/*
//CON NUOVO ALLINEAMENTO B=0.1 T
const float tiltY_TRKA = -0.70;
//const float tiltY_TRKA = 0.47;
const float tiltY_TRKB = -0.47;
const float tiltY_TRKC = 0.;
const float tiltY_TRKD = 0.02;
const float tiltX_TEST = -2.43; // ok up to run 275
const float tiltY_TEST = -3.93; //for first run no B run 203, 204, 205
*/
/*
//B = 1T
const float tiltX_TRKA = -0.62;
const float tiltX_TRKB = .91;
//const float tiltX_TEST = .91;
const float tiltX_TRKC = 0.83;
const float tiltX_TRKD = -0.96;
const float tiltY_TRKA = -0.56;
const float tiltY_TRKB = -1.251;
//const float tiltY_TEST = -1.251;
const float tiltY_TRKC = 0.;
const float tiltY_TRKD = -0.03;
*/

//const float tiltX_TEST = -2.05; // B = 1 T
//const float tiltY_TEST = -6.26; // B = 1 T

//const float tiltX_TEST = -1.98; // B = -1 T 
//const float tiltX_TRKB = -1.98; // B = -1 T 
//const float tiltY_TEST = 3.19; // B = -1 T
//const float tiltY_TEST = -6.4; // B = -1 T     run 262
//const float tiltY_TRKB = -6.4; // B = -1 T     run 262
//const float tiltY_TEST = -7.1; // B = -1 T     run 242 circ

//const float tiltX_TEST = -2.05; // B = 0.5 T
//const float tiltY_TEST = -3.9; // B = 0.5 T

//const float tiltX_TEST = -1.98; // B = -0.5 T     run 200, 201, 202 
//const float tiltY_TEST = -3.93;  // B = -0.5 T     run 200, 201, 202

/*const float tiltX_TEST = -2.48; //-1.98  
  const float tiltY_TEST = -0.70;//-3.93*/



//const float tiltY_TEST = -1.1; //for first run no B run 203, 204, 205
//const float tiltY_TEST = -0.96; //264-271
//const float tiltY_TEST = -2.1; //313-315                                                                                                            
//const float tiltX_TEST = -2.06; //313-315
//const float tiltY_TEST = 6.96;




//int  NTRKA_0, NTRKB_0, NTRKC_0, NTRKD_0, NTEST_0, NTRKA_1, NTRKB_1, NTRKC_1, NTRKD_1, NTEST_1;
//int  NGOOD; //Number of "good events" 

int  NTRKA_0[8], NTRKB_0[8], NTRKC_0[8], NTRKD_0[8], NTEST_0[8];
int  NTRKA_1[8], NTRKB_1[8], NTRKC_1[8], NTRKD_1[8], NTEST_1[8];
int  NWELL_1[8],  NGOODWELLY[8], NGOOD[8]; //Number of "good events" ;




int  NGOODTestX;
int  NGOODTestY;
int NGOODTestXY;
int nGOODmin3sX;
int nGOODmin3sY;	
int nGOODmin3sXY;

//WELL PART
//int NWELL_1;
//int NGOODWELLY;
int nGOODWELLmin3sY;
int NGOODWELLYClust1;
int HitWELL;
//

int nGemClustermin3sX;
int nGemClustermin3sY;

int nGemClusterExtraX;
int nGemClusterExtraY;

//WELL PART
int nWELLClustermin3sY;
int nWELLClusterExtraY;
//

double Chi2X, Chi2Y, WELLChi2Y;

float dispY_trkA, dispY_trkB, dispY_trkD,dispY_WELL;
float dispX_trkA, dispX_trkB, dispX_trkC, dispX_trkD;

float W1dispY_trkA, W1dispY_trkB, W1dispY_test, W1dispY_trkD;

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

//WELL PART
TH1I *cluster_size_WELL_min3sY;
TH1I *cluster_size_WELL_ExtraY;
//

TH1I *numClust;

TH1I *numClustX;
TH1I *numClustY;

TH1I *numClustmin3sX;
TH1I *numExtraClustX;

TH1I *numClustmin3sY;
TH1I *numExtraClustY;

//WELL PART
TH1I *numClustWELLY;
TH1I *numClustWELLmin3sY;
TH1I *numExtraClustWELLY;
//


TH1D *HresX;
TH1D *HresY;

TH1D *HresAllX;
TH1D *HresAllY;
TH1D *ChiresX;
TH1D *ChiresY;

//WELL PART
//TH1D *WELLHresY;
TH1D *WELLHresAllY;

//for (int i=0;i<8;i++) {
TH1D *WELLHresY[8];
//}

TH1D *WELL1HresY;
TH1D *WELL1HresAllY;

TH1D *WELLChiresY;
TH1F *WELLresY_trkA;
TH1F *WELLresY_trkB;
TH1F *WELLresY_test;
TH1F *WELLresY_trkD;
//

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

TH1I *QX,*QY,*QTOT;
//WELL PART
TH1I *WELLQY;
//

#endif

// 0 -> -1.7
// 1 -> 1.1
// 2 ->
// 5 ->
// 6 ->
