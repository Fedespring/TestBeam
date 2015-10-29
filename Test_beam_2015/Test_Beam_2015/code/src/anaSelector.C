#define anaSelector_cxx

#include <math.h>
#include <iostream>
#include <fstream>
#include "ana.h"
#include "anaSelector.h"
#include "parameters.h"

double fResX(int trkA, int trkB, int trkC, int trkD, int test, double *GemCluster1d_x, double *GemCluster1d_dx, double *GemCluster1d_z, double *GemCluster1d_dz, double *Chi2, float *dispX_trkA, float *dispX_trkB, float *dispX_trkC, float *dispX_trkD); 
double fResY(int trkA, int trkB, int trkC, int trkD, int test, double *GemCluster1d_y, double *GemCluster1d_dy, double *GemCluster1d_z, double *GemCluster1d_dz, double *Chi2, float *dispY_trkA, float *dispY_trkB, float *dispY_trkD);

using namespace std;
using std::cout;
using std::endl;

void anaSelector::Begin(TTree * /*tree*/, TString inFile)
{
	cout << "Begin selector ... " << endl;
	
	TString rootFile = AnaDir+"ana_";
	rootFile += inFile;
	cout<<rootFile<<endl;
	myfile = new TFile(rootFile,"RECREATE");
	NGOOD = NGOODTestX = NGOODTestY = nGemClustermin3sX = nGemClustermin3sY = nGemClusterExtraX = nGemClusterExtraY = nGOODmin3sX = nGOODmin3sY = nGOODmin3sXY = 0;
	
	HresX = new TH1D();
	HresX->SetName("HresX");
	HresX->SetTitle("Residual Distribution X-Strips within 3Sigma");
	HresX->SetBins(100,-1,1);  
	
	HresAllX = new TH1D();
	HresAllX->SetName("HresAllX");
	HresAllX->SetTitle("Residual Distribution X-Strips");
	HresAllX->SetBins(500,-10,10); 
	
	HresY= new TH1D();
	HresY->SetName("HresY");
	HresY->SetTitle("Residual Distribution Y-Strips within 3Sigma");
	HresY->SetBins(100,-1,1);
	
	HresAllY= new TH1D();
	HresAllY->SetName("HresAllY");
	HresAllY->SetTitle("Residual Distribution Y-Strips");
	HresAllY->SetBins(500,-10,10);
	
	HresY_trkA= new TH1F();
	HresY_trkA->SetName("HresY_trkA");
	HresY_trkA->SetTitle("Residual Distribution TRKA Y-Strips");
	HresY_trkA->SetBins(100,-1,1);
	
	HresY_trkB= new TH1F();
	HresY_trkB->SetName("HresY_trkB");
	HresY_trkB->SetTitle("Residual Distribution TRKB Y-Strips");
	HresY_trkB->SetBins(100,-1,1);
	
	HresY_trkD= new TH1F();
	HresY_trkD->SetName("HresY_trkD");
	HresY_trkD->SetTitle("Residual Distribution TRKD Y-Strips");
	HresY_trkD->SetBins(100,-1,1);
	
	HresX_trkA= new TH1F();
	HresX_trkA->SetName("HresX_trkA");
	HresX_trkA->SetTitle("Residual Distribution TRKA X-Strips");
	HresX_trkA->SetBins(100,-1,1);
	
	HresX_trkB= new TH1F();
	HresX_trkB->SetName("HresX_trkB");
	HresX_trkB->SetTitle("Residual Distribution TRKB X-Strips");
	HresX_trkB->SetBins(100,-1,1);
	
	HresX_trkC= new TH1F();
	HresX_trkC->SetName("HresX_trkC");
	HresX_trkC->SetTitle("Residual Distribution TRKC X-Strips");
	HresX_trkC->SetBins(100,-1,1);
	
	HresX_trkD= new TH1F();
	HresX_trkD->SetName("HresX_trkD");
	HresX_trkD->SetTitle("Residual Distribution TRKD X-Strips");
	HresX_trkD->SetBins(100,-1,1);
	
	ChiresX = new TH1D();
	ChiresX->SetName("ChiresX");
	ChiresX->SetTitle("Chi-Square Distribution X-Strips");
	ChiresX->SetBins(100,0,25);  
	
	ChiresY= new TH1D();
	ChiresY->SetName("ChiresY");
	ChiresY->SetTitle("Chi-Square Distribution Y-Strips");
	ChiresY->SetBins(100,0,25);
	
	cluster_size_trkA_Y= new TH1I();
	cluster_size_trkA_Y->SetName("cluster_size_trkA_Y");
	cluster_size_trkA_Y->SetTitle("ClusterSize TRKA Y-Strips");
	cluster_size_trkA_Y->SetBins(20,0,20);
	
	cluster_size_trkB_Y= new TH1I();
	cluster_size_trkB_Y->SetName("cluster_size_trkB_Y");
	cluster_size_trkB_Y->SetTitle("ClusterSize TRKB Y-Strips");
	cluster_size_trkB_Y->SetBins(20,0,20);
	
	cluster_size_trkD_Y= new TH1I();
	cluster_size_trkD_Y->SetName("cluster_size_trkD_Y");
	cluster_size_trkD_Y->SetTitle("ClusterSize TRKD Y-Strips");
	cluster_size_trkD_Y->SetBins(20,0,20);
	
	cluster_size_trkA_X= new TH1I();
	cluster_size_trkA_X->SetName("cluster_size_trkA_X");
	cluster_size_trkA_X->SetTitle("ClusterSize TRKA X-Strips");
	cluster_size_trkA_X->SetBins(20,0,20);
	
	cluster_size_trkB_X= new TH1I();
	cluster_size_trkB_X->SetName("cluster_size_trkB_X");
	cluster_size_trkB_X->SetTitle("ClusterSize TRKB X-Strips");
	cluster_size_trkB_X->SetBins(20,0,20);
	
	cluster_size_trkC_X= new TH1I();
	cluster_size_trkC_X->SetName("cluster_size_trkC_X");
	cluster_size_trkC_X->SetTitle("ClusterSize TRKC X-Strips");
	cluster_size_trkC_X->SetBins(20,0,20);
	
	cluster_size_trkD_X= new TH1I();
	cluster_size_trkD_X->SetName("cluster_size_trkD_X");
	cluster_size_trkD_X->SetTitle("ClusterSize TRKD X-Strips");
	cluster_size_trkD_X->SetBins(20,0,20);
	
	cluster_size_test_min3sX= new TH1I();
	cluster_size_test_min3sX->SetName("cluster_size_test_min3sX");
	cluster_size_test_min3sX->SetTitle("ClusterSize TEST X-Strips within 3 Sigma");
	cluster_size_test_min3sX->SetBins(20,0,20);
	
	cluster_size_test_min3sY= new TH1I();
	cluster_size_test_min3sY->SetName("cluster_size_test_min3sY");
	cluster_size_test_min3sY->SetTitle("ClusterSize TEST Y-Strips within 3 Sigma");
	cluster_size_test_min3sY->SetBins(20,0,20);
	
	cluster_size_test_ExtraX= new TH1I();
	cluster_size_test_ExtraX->SetName("cluster_size_test_ExtraX");
	cluster_size_test_ExtraX->SetTitle("ClusterSize TEST X-Strips farther than 3 Sigma");
	cluster_size_test_ExtraX->SetBins(20,0,20);
	
	cluster_size_test_ExtraY= new TH1I();
	cluster_size_test_ExtraY->SetName("cluster_size_test_ExtraY");
	cluster_size_test_ExtraY->SetTitle("ClusterSize TEST Y-Strips farther than 3 Sigma");
	cluster_size_test_ExtraY->SetBins(20,0,20);
	
	map_xAvsxB = new TH2F("map_xAvsxB","Mapping x TRKA vs x TRKB",100,-50,50,100,-50,50);
	
	map_xAvsxC = new TH2F("map_xAvsxC","Mapping x TRKA vs x TRKC",100,-50,50,100,-50,50);
	
	map_xAvsxD = new TH2F("map_xAvsxD","Mapping x TRKA vs x TRKD",100,-50,50,100,-50,50);
	
	map_yAvsyB = new TH2F("map_yAvsyB","Mapping y TRKA vs y TRKB",100,-50,50,100,-50,50);
	
	map_yAvsyC = new TH2F("map_yAvsyC","Mapping y TRKA vs y TRKC",100,-50,50,100,-50,50);
	
	map_yAvsyD = new TH2F("map_yAvsyD","Mapping y TRKA vs y TRKD",100,-50,50,100,-50,50);
	
	numClust= new TH1I();
	numClust->SetName("numClust");
	numClust->SetTitle("Number of Cluster");
	numClust->SetBins(30,0,30);
	
	numClustX= new TH1I();
	numClustX->SetName("numClustX");
	numClustX->SetTitle("Number of X-Cluster");
	numClustX->SetBins(30,0,30);
	
	numClustmin3sX= new TH1I();
	numClustmin3sX->SetName("numClustmin3sX");
	numClustmin3sX->SetTitle("Number of X-Cluster within 3 Sigma");
	numClustmin3sX->SetBins(30,0,30);
	
	numExtraClustX= new TH1I();
	numExtraClustX->SetName("numExtraClustX");
	numExtraClustX->SetTitle("Number of X-Cluster farther than 3 Sigma");
	numExtraClustX->SetBins(30,0,30);
	
	numClustY= new TH1I();
	numClustY->SetName("numClustY");
	numClustY->SetTitle("Number of Y-Cluster");
	numClustY->SetBins(30,0,30);
	
	numClustmin3sY= new TH1I();
	numClustmin3sY->SetName("numClustmin3sY");
	numClustmin3sY->SetTitle("Number of Y-Cluster within 3 Sigma");
	numClustmin3sY->SetBins(30,0,30);
	
	numExtraClustY= new TH1I();
	numExtraClustY->SetName("numExtraClustY");
	numExtraClustY->SetTitle("Number of Y-Cluster farther than 3 Sigma");
	numExtraClustY->SetBins(30,0,30);
}

void anaSelector::SlaveBegin(TTree * /*tree*/)
{
	TString option = GetOption();
}

Bool_t anaSelector::Process(Long64_t entry) {
	
//	if (entry >= 4220 ) return 0;

	
	fChain->LoadTree(entry);
	fChain->GetEntry(entry);
	fChain->GetTreeNumber();
	
	if (nGemCluster > 25) return 0;
	
	int iClust;
	double resX, resY;
	int idTRKA_0,idTRKA_1,idTRKB_0,idTRKB_1,idTRKC_0,idTRKC_1,idTRKD_0,idTRKD_1,idTEST_0,idTEST_1;

	NTRKA_0 = NTRKB_0 = NTRKC_0 = NTRKD_0 = NTEST_0 = NTRKA_1 = NTRKB_1 = NTRKC_1 = NTRKD_1 = NTEST_1 = 0;
	
	if (entry%1==0)  cout << "now at event " << entry << endl;
	cout << "nGemClust =   " << nGemCluster << endl;

	for(iClust=0;iClust<nGemCluster;iClust++) {
		if(GemCluster1d_plane[iClust] == TRKA &&  GemCluster1d_view[iClust] == 0) {NTRKA_0++; idTRKA_0=iClust;}
		if(GemCluster1d_plane[iClust] == TRKB &&  GemCluster1d_view[iClust] == 0) {NTRKB_0++; idTRKB_0=iClust;}
		if(GemCluster1d_plane[iClust] == TRKC &&  GemCluster1d_view[iClust] == 0) {NTRKC_0++; idTRKC_0=iClust;}
		if(GemCluster1d_plane[iClust] == TRKD &&  GemCluster1d_view[iClust] == 0) {NTRKD_0++; idTRKD_0=iClust;}
		if(GemCluster1d_plane[iClust] == TEST &&  GemCluster1d_view[iClust] == 0) {NTEST_0++; idTEST_0=iClust;}
		if(GemCluster1d_plane[iClust] == TRKA &&  GemCluster1d_view[iClust] == 1) {NTRKA_1++; idTRKA_1=iClust;}
		if(GemCluster1d_plane[iClust] == TRKB &&  GemCluster1d_view[iClust] == 1) {NTRKB_1++; idTRKB_1=iClust;}
		if(GemCluster1d_plane[iClust] == TRKC &&  GemCluster1d_view[iClust] == 1) {NTRKC_1++; idTRKC_1=iClust;}
		if(GemCluster1d_plane[iClust] == TRKD &&  GemCluster1d_view[iClust] == 1) {NTRKD_1++; idTRKD_1=iClust;}
		if(GemCluster1d_plane[iClust] == TEST &&  GemCluster1d_view[iClust] == 1) {NTEST_1++; idTEST_1=iClust;}
	}
	
	if(NTRKA_0 == 1 && NTRKA_1 == 1 && NTRKB_0 == 1 && NTRKB_1 == 1 && NTRKC_0 == 1 && NTRKC_1 >= 0 && NTRKD_0 == 1 && NTRKD_1 == 1) {
		NGOOD++;
		
		cluster_size_trkA_X->Fill(GemCluster1d_nHit[idTRKA_0]);
		cluster_size_trkB_X->Fill(GemCluster1d_nHit[idTRKB_0]);
		cluster_size_trkC_X->Fill(GemCluster1d_nHit[idTRKC_0]);
		cluster_size_trkD_X->Fill(GemCluster1d_nHit[idTRKD_0]);
		
		cluster_size_trkA_Y->Fill(GemCluster1d_nHit[idTRKA_1]);
		cluster_size_trkB_Y->Fill(GemCluster1d_nHit[idTRKB_1]);
		cluster_size_trkD_Y->Fill(GemCluster1d_nHit[idTRKD_1]);
		
		map_xAvsxB->Fill(GemCluster1d_x[idTRKA_0]+ tiltX_TRKA,GemCluster1d_x[idTRKB_0]+ tiltX_TRKB);
		map_xAvsxC->Fill(GemCluster1d_x[idTRKA_0]+ tiltX_TRKA,GemCluster1d_x[idTRKC_0]+ tiltX_TRKC);
		map_xAvsxD->Fill(GemCluster1d_x[idTRKA_0]+ tiltX_TRKA,GemCluster1d_x[idTRKD_0]+ tiltX_TRKD);
		
		map_yAvsyB->Fill(GemCluster1d_y[idTRKA_1]+ tiltY_TRKA,GemCluster1d_y[idTRKB_1]+ tiltY_TRKB);
		map_yAvsyC->Fill(GemCluster1d_y[idTRKA_1]+ tiltY_TRKA,GemCluster1d_y[idTRKC_1]+ tiltY_TRKC);
		map_yAvsyD->Fill(GemCluster1d_y[idTRKA_1]+ tiltY_TRKA,GemCluster1d_y[idTRKD_1]+ tiltY_TRKD);
		
		numClust->Fill(nGemCluster);
		
		resX=fResX(idTRKA_0, idTRKB_0 , idTRKC_0, idTRKD_0, idTEST_0, GemCluster1d_x , GemCluster1d_dx ,GemCluster1d_z ,GemCluster1d_dz, &Chi2X, &dispX_trkA, &dispX_trkB, &dispX_trkC, &dispX_trkD);
		
		HresX_trkA->Fill(dispX_trkA);
		HresX_trkB->Fill(dispX_trkB);
		HresX_trkC->Fill(dispX_trkC);
		HresX_trkD->Fill(dispX_trkD);
		ChiresX->Fill(Chi2X);
		
		cout << idTRKA_1 << "     " << idTRKB_1 << "   " << idTRKC_1 << "     " << idTRKD_1 << "     " << iClust << endl ;
		resY=fResY(idTRKA_1, idTRKB_1 , idTRKC_1, idTRKD_1, idTEST_1, GemCluster1d_y , GemCluster1d_dy ,GemCluster1d_z ,GemCluster1d_dz, &Chi2Y, &dispY_trkA, &dispY_trkB, &dispY_trkD);

		HresY_trkA->Fill(dispY_trkA);
		HresY_trkB->Fill(dispY_trkB);
		HresY_trkD->Fill(dispY_trkD);
		ChiresY->Fill(Chi2Y);
		
		numClustX->Fill(NTEST_0);
		
		nGemClustermin3sX = nGemClusterExtraX = 0;

		
		
		if(NTEST_0 >= 1){
			
			NGOODTestX++;
			
			for(iClust=0;iClust<nGemCluster;iClust++) {
				if(GemCluster1d_plane[iClust] == TEST &&  GemCluster1d_view[iClust] == 0) {
					
					resX = 0.;
					resX = fResX(idTRKA_0, idTRKB_0 , idTRKC_0, idTRKD_0, iClust, GemCluster1d_x , GemCluster1d_dx ,GemCluster1d_z ,GemCluster1d_dz, &Chi2X, &dispX_trkA, &dispX_trkB, &dispX_trkC, &dispX_trkD);
					
					 //cout << idTRKA_0 << "     " << idTRKB_0 << "   " << idTRKC_0 << "     " << idTRKD_0 << "     " << iClust << endl ;
					
					cout << "resX --- >  " << resX << endl;
					
					if ((-1*resCut <= resX) && (resX<= resCut)) {
						
						nGemClustermin3sX++;
						cluster_size_test_min3sX->Fill(GemCluster1d_nHit[idTEST_0]);
						
					}
					else {
						nGemClusterExtraX++;
						cluster_size_test_ExtraX->Fill(GemCluster1d_nHit[idTEST_0]);
					}
				}
			}
			
			if(nGemClustermin3sX >= 1) nGOODmin3sX++;
			numClustmin3sX->Fill(nGemClustermin3sX);
			numExtraClustX->Fill(nGemClusterExtraX);
			
			if(NTEST_0 == 1){
				resX = 0.;
				resX = fResX(idTRKA_0, idTRKB_0 , idTRKC_0, idTRKD_0, idTEST_0, GemCluster1d_x , GemCluster1d_dx ,GemCluster1d_z ,GemCluster1d_dz, &Chi2X, &dispX_trkA, &dispX_trkB, &dispX_trkC, &dispX_trkD);
				
				if(-1*resCut <= resX && resX <= resCut){
					
					HresX->Fill(resX);  
				}
				
				HresAllX->Fill(resX);
			}
			
		}
		
		
		
		numClustY->Fill(NTEST_1);
		
		
		
		if(NTEST_1 >= 1){
			
			NGOODTestY++;
			nGemClustermin3sY = nGemClusterExtraY = 0;
			
			
			for(iClust=0;iClust<nGemCluster;iClust++) {
				if(GemCluster1d_plane[iClust] == TEST &&  GemCluster1d_view[iClust] == 1) {
					
					resY =  fResY(idTRKA_1, idTRKB_1 , idTRKC_1, idTRKD_1, iClust, GemCluster1d_y , GemCluster1d_dy ,GemCluster1d_z ,GemCluster1d_dz, &Chi2Y, &dispY_trkA, &dispY_trkB, &dispY_trkD);
					cout << "resY --- >  " << resY << endl;

					if(-1*resCut <= resY && resY <= resCut) {
						nGemClustermin3sY++;
						cluster_size_test_min3sY->Fill(GemCluster1d_nHit[idTEST_1]);
					}
					else {
						nGemClusterExtraY++;
						cluster_size_test_ExtraY->Fill(GemCluster1d_nHit[idTEST_1]);
					}
				}
			}
			if(nGemClustermin3sY >= 1) nGOODmin3sY++;
			numClustmin3sY->Fill(nGemClustermin3sY);
			numExtraClustY->Fill(nGemClusterExtraY);
			
			if(NTEST_0 >= 1){
				
				NGOODTestXY++;
				
			}
			
			if(nGemClustermin3sY >= 1 && nGemClustermin3sX >= 1 ) nGOODmin3sXY++;
			
			if(NTEST_1 == 1){
				
				resY = fResY(idTRKA_1, idTRKB_1 , idTRKC_1, idTRKD_1, idTEST_1, GemCluster1d_y , GemCluster1d_dy ,GemCluster1d_z ,GemCluster1d_dz, &Chi2Y, &dispY_trkA, &dispY_trkB, &dispY_trkD);
				
				if(-1*resCut <= resY && resY <= resCut){
					
					HresY->Fill(resY);
				}
				
				HresAllY->Fill(resY);
				
			}
		}

		
		 
	}
	Event++;
	return kTRUE;
}

void anaSelector::SlaveTerminate()
{
	
}

void anaSelector::Terminate(TString inFile)
{
	cout << "Terminate selector ... " << endl;
	
	cout << "Processed events: " << Event << endl;
	
	cout << "Number of Good Events:  "<< NGOOD << endl;
	
	cout << "Efficiency  X-Strips Test Chamber:                " << (100.*NGOODTestX)/NGOOD <<" %" << endl;
	cout << "Efficiency  Y-Strips Test Chamber:                " << (100.*NGOODTestY)/NGOOD <<" %" << endl;
	cout << "Efficiency  Test Chamber:                         " << (100.*NGOODTestXY)/NGOOD <<" %" << endl;
	cout << "Efficiency  X-Strips within 3 Sigma Test Chamber: " << (100.*nGOODmin3sX)/NGOOD <<" %" << endl;
	cout << "Efficiency  Y-Strips within 3 Sigma Test Chamber: " << (100.*nGOODmin3sY)/NGOOD <<" %" << endl;
	cout << "Efficiency  Test Chamber within 3 Sigma:          " << (100.*nGOODmin3sXY)/NGOOD <<" %" << endl;
	cout << "HHHH " << nGOODmin3sX << "  " << nGOODmin3sY << "  " << NGOOD << endl;  
	
	HresX->Write();
	HresY->Write();
	
	HresAllX->Write();
	HresAllY->Write();
	
	ChiresX->Write();
	ChiresY->Write();
	
	HresY_trkA->Write();
	HresY_trkB->Write();
	HresY_trkD->Write();
	
	HresX_trkA->Write();
	HresX_trkB->Write();
	HresX_trkC->Write();
	HresX_trkD->Write();
	
	cluster_size_trkA_X->Write();
	cluster_size_trkB_X->Write(); 
	cluster_size_trkC_X->Write();
	cluster_size_trkD_X->Write();
	
	cluster_size_trkA_Y->Write();
	cluster_size_trkB_Y->Write();
	cluster_size_trkD_Y->Write();
	
	cluster_size_test_min3sX->Write();
	cluster_size_test_ExtraX->Write(); 
	cluster_size_test_min3sY->Write();
	cluster_size_test_ExtraY->Write();
	
	map_xAvsxB->Write();
	map_xAvsxC->Write();
	map_xAvsxD->Write();
	
	map_yAvsyB->Write();
	map_yAvsyC->Write();
	map_yAvsyD->Write();
    
	numClust->Write();
	numClustX->Write();
	numClustmin3sX->Write();
	numExtraClustX->Write();
	numClustY->Write();
	numClustmin3sY->Write();
	numExtraClustY->Write();
	
	
	
	myfile->Write();
	myfile->Close();
}



double fResX(int trkA, int trkB, int trkC, int trkD, int test, double *GemCluster1d_x, double *GemCluster1d_dx, double *GemCluster1d_z, double *GemCluster1d_dz, double *Chi2, float *dispX_trkA, float *dispX_trkB, float *dispX_trkC, float *dispX_trkD) {
	
	double x[4],z[4],dx[4],dz[4];
	double xfit, dispX;
	double A_ZX,B_ZX;
	int n=4;
	
	TGraphErrors *plotZX;
	TF1 *fitZX;
	
	dispX=0.;
	
	x[0]  = GemCluster1d_x[trkA] + tiltX_TRKA;
	dx[0] = GemCluster1d_dx[trkA];
	z[0]  = GemCluster1d_z[trkA];
	dz[0] = GemCluster1d_dz[trkA];
	
	x[1]  = GemCluster1d_x[trkB] + tiltX_TRKB;
	dx[1] = GemCluster1d_dx[trkB];
	z[1]  = GemCluster1d_z[trkB];
	dz[1] = GemCluster1d_dz[trkB];
	
	x[2]  = GemCluster1d_x[trkC] + tiltX_TRKC;
	dx[2] = GemCluster1d_dx[trkC];
	z[2]  = GemCluster1d_z[trkC];
	dz[2] = GemCluster1d_dz[trkC];
	
	x[3]  = GemCluster1d_x[trkD] + tiltX_TRKD;
	dx[3] = GemCluster1d_dx[trkD];
	z[3]  = GemCluster1d_z[trkD];
	dz[3] = GemCluster1d_dz[trkD];

	
	//cout << x[0] << "    " << z[0] << "    " <<  x[1] << "    " << z[1] << "    " << x[2] << "    " << z[2] << "    " << x[3] << "    " << z[3] << "    " << endl;
	
	plotZX = new TGraphErrors(n,z,x,dz,dx);
	
	plotZX->Fit("pol1","Q");
	
	fitZX = plotZX->GetFunction("pol1");
	
	A_ZX = fitZX -> GetParameter(0);
	B_ZX = fitZX -> GetParameter(1);
	*Chi2 = (double) (fitZX->GetChisquare());

	
	//cout << GemCluster1d_z[test] << "     " << A_ZX << "     " << B_ZX << endl;
	
	xfit = A_ZX + (GemCluster1d_z[test]*B_ZX);
	//cout<<"xfit "<<xfit<<" xtest "<<GemCluster1d_x[test]<<endl;
	dispX = (xfit - (GemCluster1d_x[test] + tiltX_TEST));
	//cout << dispX << "    " << xfit << "     " << GemCluster1d_x[test] << "    " << test << "     " << tiltX_TEST << endl;
	
	
	xfit = A_ZX + (GemCluster1d_z[trkA]*B_ZX);
	*dispX_trkA = (xfit - (GemCluster1d_x[trkA] + tiltX_TRKA));
	
	xfit = A_ZX + (GemCluster1d_z[trkB]*B_ZX);
	*dispX_trkB = (xfit - (GemCluster1d_x[trkB] + tiltX_TRKB));
	
	xfit = A_ZX + (GemCluster1d_z[trkC]*B_ZX);
	*dispX_trkC = (xfit - (GemCluster1d_x[trkC] + tiltX_TRKC));
	
	xfit = A_ZX + (GemCluster1d_z[trkD]*B_ZX);
	*dispX_trkD = (xfit - (GemCluster1d_x[trkD] + tiltX_TRKD));


	
	//plotZX->~TGraphErrors() ;
	//fitZX->~TF1();
	
	
	return dispX;
	
}

double fResY(int trkA, int trkB, int trkC, int trkD, int test, double *GemCluster1d_y, double *GemCluster1d_dy, double *GemCluster1d_z, double *GemCluster1d_dz, double *Chi2, float *dispY_trkA, float *dispY_trkB, float *dispY_trkD) {

	double y[3],z[3],dy[3],dz[3];
	double yfit, dispY;
	double A_ZY,B_ZY;
	int n=3;
	
	TGraphErrors *plotZY;
	//TF1 *fitZY;
	TF1 *fitZY = new TF1("fitZY","[0]+[1]*x",-1000,1000);

	dispY=0.;

	y[0]  = GemCluster1d_y[trkA] + tiltY_TRKA;
	dy[0] = GemCluster1d_dy[trkA];
	z[0]  = GemCluster1d_z[trkA];
	dz[0] = GemCluster1d_dz[trkA];
	
	y[1]  = GemCluster1d_y[trkB] + tiltY_TRKB;
	dy[1] = GemCluster1d_dy[trkB];
	z[1]  = GemCluster1d_z[trkB];
	dz[1] = GemCluster1d_dz[trkB];
	
	/* y[2]  = GemCluster1d_y[trkC] + tiltY_TRKC;
	 dy[2] = GemCluster1d_dy[trkC];
	 z[2]  = GemCluster1d_z[trkC];
	 dz[2] = GemCluster1d_dz[trkC];*/
	
	y[2]  = GemCluster1d_y[trkD] + tiltY_TRKD;
	dy[2] = GemCluster1d_dy[trkD];
	z[2]  = GemCluster1d_z[trkD];
	dz[2] = GemCluster1d_dz[trkD];
	
	//cout << y[0] << "    " << z[0] << "    " <<  y[1] << "    " << z[1] << "    " << y[2] << "    " << z[2]  << endl;

	
	plotZY = new TGraphErrors(n,z,y,dz,dy);

//	plotZY->Fit("pol1","Q");
	plotZY->Fit(fitZY,"Q");

//	fitZY = plotZY->GetFunction(fitZY);

	A_ZY = fitZY -> GetParameter(0);
	B_ZY = fitZY -> GetParameter(1);

	
	yfit = A_ZY + (GemCluster1d_z[test]*B_ZY);
	dispY = (yfit - (GemCluster1d_y[test] + tiltY_TEST));

	yfit = A_ZY + (GemCluster1d_z[trkA]*B_ZY);
	*dispY_trkA = (yfit - (GemCluster1d_y[trkA] + tiltY_TRKA));
	
	yfit = A_ZY + (GemCluster1d_z[trkB]*B_ZY);
	*dispY_trkB = (yfit - (GemCluster1d_y[trkB] + tiltY_TRKB));
	
	yfit = A_ZY + (GemCluster1d_z[trkD]*B_ZY);
	*dispY_trkD = (yfit - (GemCluster1d_y[trkD] + tiltY_TRKD));

	*Chi2 = (double) (fitZY->GetChisquare());

	//plotZY->~TGraphErrors() ;
	//fitZY->~TF1();

	
	return dispY;

}
