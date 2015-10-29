#define recSelector_cxx

#include "parameters.h"
#include "recSelector.h"
#include "rec.h"
#include "hit.h"
#include "cluster1d.h"
#include "cluster1d.h"
#include "digitizer.h"
#include "reorder.h"
#include "clusterizer.h"
#include "TString.h"

#include "digitizer.h"



using std::cout;
using std::endl;

void recSelector::Begin(TTree * /*tree*/, TString inFile)
{
    cout << "Begin selctor ... " << endl;

    TString rootFile = RecDir+"/rec_";
    rootFile += inFile;

    fFile = new TFile(rootFile,"RECREATE");
    t1 = new TTree("t1","GemData");
    
    t1->Branch("Event",&Event,"Event/I");

    t1->Branch("nGemHit",&nGemHit,"nGemHit/I");
    t1->Branch("GemHit_apv",GemHit.apv,"GemHit_apv[nGemHit]/I");
    t1->Branch("GemHit_plane",GemHit.plane,"GemHit_plane[nGemHit]/I");
    t1->Branch("GemHit_view",GemHit.view,"GemHit_view[nGemHit]/I");
    t1->Branch("GemHit_half",GemHit.half,"GemHit_half[nGemHit]/I");
    t1->Branch("GemHit_sample",GemHit.sample,"GemHit_sample[nGemHit]/I");
    t1->Branch("GemHit_strip",GemHit.strip,"GemHit_strip[nGemHit]/I");
    t1->Branch("GemHit_q",GemHit.q,"GemHit_q[nGemHit]/F");
    //t1->Branch("GemHit_qRead",GemHit.qRead,"GemHit_qRead[nGemHit]/F");
    t1->Branch("GemHit_readoutch",GemHit.readoutch,"GemHit_readoutch[nGemHit]/I");
    t1->Branch("GemHit_x",GemHit.x,"GemHit_x[nGemHit]/D");
    t1->Branch("GemHit_y",GemHit.y,"GemHit_y[nGemHit]/D");
    t1->Branch("GemHit_z",GemHit.z,"GemHit_z[nGemHit]/D");
    
    t1->Branch("nGemCluster",&nGemCluster,"nGemCluster/I");
    t1->Branch("GemCluster1d_plane",GemCluster1d.plane,"GemCluster1d_plane[nGemCluster]/I");
    t1->Branch("GemCluster1d_view",GemCluster1d.view,"GemCluster1d_view[nGemCluster]/I");
    t1->Branch("GemCluster1d_q",GemCluster1d.q,"GemCluster1d_q[nGemCluster]/I");
    t1->Branch("GemCluster1d_nHit",GemCluster1d.nHit,"GemCluster1d_nHit[nGemCluster]/I");
    t1->Branch("GemCluster1d_x",GemCluster1d.x,"GemCluster1d_x[nGemCluster]/D");
    t1->Branch("GemCluster1d_y",GemCluster1d.y,"GemCluster1d_y[nGemCluster]/D");
    t1->Branch("GemCluster1d_z",GemCluster1d.z,"GemCluster1d_z[nGemCluster]/D");
    t1->Branch("GemCluster1d_dx",GemCluster1d.dx,"GemCluster1d_dx[nGemCluster]/D");
    t1->Branch("GemCluster1d_dy",GemCluster1d.dy,"GemCluster1d_dy[nGemCluster]/D");
    t1->Branch("GemCluster1d_dz",GemCluster1d.dz,"GemCluster1d_dz[nGemCluster]/D");
    t1->Branch("GemCluster1d_isGood",GemCluster1d.isGood,"GemCluster1d_isGood[nGemCluster]/O");
    
    t1->Branch("nGemCluster2d",&nGemCluster2d,"nGemCluster2d/I");
    t1->Branch("GemCluster2d_plane",GemCluster2d.plane,"GemCluster2d_plane[nGemCluster2d]/I");

    t1->Branch("GemCluster2d_q", GemCluster2d.q, "GemCluster2d_q[nGemCluster2d]/I");
    t1->Branch("GemCluster2d_qx",GemCluster2d.qx,"GemCluster2d_qx[nGemCluster2d]/I");
    t1->Branch("GemCluster2d_qy",GemCluster2d.qy,"GemCluster2d_qy[nGemCluster2d]/I");
    
    t1->Branch("GemCluster2d_x", GemCluster2d.x, "GemCluster2d_x[nGemCluster2d]/D");
    t1->Branch("GemCluster2d_y", GemCluster2d.y, "GemCluster2d_y[nGemCluster2d]/D");
    t1->Branch("GemCluster2d_z", GemCluster2d.z, "GemCluster2d_z[nGemCluster2d]/D");
    t1->Branch("GemCluster2d_dx",GemCluster2d.dx,"GemCluster2d_dx[nGemCluster2d]/D");
    t1->Branch("GemCluster2d_dy",GemCluster2d.dy,"GemCluster2d_dy[nGemCluster2d]/D");
    t1->Branch("GemCluster2d_dz",GemCluster2d.dz,"GemCluster2d_dz[nGemCluster2d]/D");

    t1->Branch("GemCluster2d_nHit", GemCluster2d.nHit, "GemCluster2d_nHit[nGemCluster2d]/I");
    t1->Branch("GemCluster2d_nHitX",GemCluster2d.nHitX,"GemCluster2d_nHitX[nGemCluster2d]/I");
    t1->Branch("GemCluster2d_nHitY",GemCluster2d.nHitY,"GemCluster2d_nHitY[nGemCluster2d]/I");
    
    Event = 0;
    
    
    //digitizer::initThreshold();
    
}

void recSelector::SlaveBegin(TTree * /*tree*/)
{
    TString option = GetOption();
}




Bool_t recSelector::Process(Long64_t entry)
{
    
    fChain->LoadTree(entry);
    fChain->GetEntry(entry);
    fChain->GetTreeNumber();
    
    if (entry%1000==0)  cout << "now at event " << entry << endl;
    
    
    // digitize
    nGemHit = digitizer::digitize(apv_id,mm_strip,apv_q,&GemHit);
    
    //reorder
    nGemHit = reorder::reorde(apv_id,mm_strip,apv_q,&GemHit);
   
    // clusterize
    nGemCluster = clusterizer::clusterize(&GemHit,&GemCluster1d);

    // combine 1d clusters into 2d cluster
    //nGemCluster2d = clusterizer::clusterize2d(&GemCluster1d,&GemCluster2d);

    
       
    Event++;
    t1->Fill();

    return kTRUE;
}





void recSelector::SlaveTerminate()
{
    
}

void recSelector::Terminate()
{

    cout << "Terminate selector ... " << endl;
    
    fFile->Write();
    fFile->Close();

    cout << "Processed events " << Event << endl;
    
}

