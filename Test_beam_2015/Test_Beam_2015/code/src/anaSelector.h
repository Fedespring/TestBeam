//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Nov 18 13:00:44 2014 by ROOT version 5.34/14
// from TTree t1/GemData
// found on file: recSim_run34.root
//////////////////////////////////////////////////////////

#ifndef anaSelector_h
#define anaSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class anaSelector : public TSelector {
private:


public :

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Int_t           Event;
   Int_t           nGemHit;
   Int_t           GemHit_apv[500];   //[nGemHit]
   Int_t           GemHit_plane[500];   //[nGemHit]
   Int_t           GemHit_view[500];   //[nGemHit]
   Int_t           GemHit_half[500];   //[nGemHit]
   Int_t           GemHit_sample[500];   //[nGemHit]
   Int_t           GemHit_strip[500];   //[nGemHit]
   Int_t           GemHit_q[500];   //[nGemHit]
   Double_t        GemHit_x[500];   //[nGemHit]
   Double_t        GemHit_y[500];   //[nGemHit]
   Double_t        GemHit_z[500];   //[nGemHit]
   Int_t           nGemCluster;
   Int_t           GemCluster1d_plane[500];   //[nGemCluster]
   Int_t           GemCluster1d_view[500];   //[nGemCluster]
   Int_t           GemCluster1d_q[500];   //[nGemCluster]
   Int_t           GemCluster1d_nHit[500];   //[nGemCluster]
   Double_t        GemCluster1d_x[500];   //[nGemCluster]
   Double_t        GemCluster1d_y[500];   //[nGemCluster]
   Double_t        GemCluster1d_z[500];   //[nGemCluster]
   Double_t        GemCluster1d_dx[500];   //[nGemCluster]
   Double_t        GemCluster1d_dy[500];   //[nGemCluster]
   Double_t        GemCluster1d_dz[500];   //[nGemCluster]
   Int_t           nGemCluster2d;
   Int_t           GemCluster2d_plane[500];   //[nGemCluster2d]
   Int_t           GemCluster2d_q[500];   //[nGemCluster2d]
   Int_t           GemCluster2d_qx[500];   //[nGemCluster2d]
   Int_t           GemCluster2d_qy[500];   //[nGemCluster2d]
   Double_t        GemCluster2d_x[500];   //[nGemCluster2d]
   Double_t        GemCluster2d_y[500];   //[nGemCluster2d]
   Double_t        GemCluster2d_z[500];   //[nGemCluster2d]
   Double_t        GemCluster2d_dx[500];   //[nGemCluster2d]
   Double_t        GemCluster2d_dy[500];   //[nGemCluster2d]
   Double_t        GemCluster2d_dz[500];   //[nGemCluster2d]
   Int_t           GemCluster2d_nHit[500];   //[nGemCluster2d]
   Int_t           GemCluster2d_nHitX[500];   //[nGemCluster2d]
   Int_t           GemCluster2d_nHitY[500];   //[nGemCluster2d]

   // List of branches
   TBranch        *b_Event;   //!
   TBranch        *b_nGemHit;   //!
   TBranch        *b_GemHit_apv;   //!
   TBranch        *b_GemHit_plane;   //!
   TBranch        *b_GemHit_view;   //!
   TBranch        *b_GemHit_half;   //!
   TBranch        *b_GemHit_sample;   //!
   TBranch        *b_GemHit_strip;   //!
   TBranch        *b_GemHit_q;   //!
   TBranch        *b_GemHit_x;   //!
   TBranch        *b_GemHit_y;   //!
   TBranch        *b_GemHit_z;   //!
   TBranch        *b_nGemCluster;   //!
   TBranch        *b_GemCluster1d_plane;   //!
   TBranch        *b_GemCluster1d_view;   //!
   TBranch        *b_GemCluster1d_q;   //!
   TBranch        *b_GemCluster1d_nHit;   //!
   TBranch        *b_GemCluster1d_x;   //!
   TBranch        *b_GemCluster1d_y;   //!
   TBranch        *b_GemCluster1d_z;   //!
   TBranch        *b_GemCluster1d_dx;   //!
   TBranch        *b_GemCluster1d_dy;   //!
   TBranch        *b_GemCluster1d_dz;   //!
   TBranch        *b_nGemCluster2d;   //!
   TBranch        *b_GemCluster2d_plane;   //!
   TBranch        *b_GemCluster2d_q;   //!
   TBranch        *b_GemCluster2d_qx;   //!
   TBranch        *b_GemCluster2d_qy;   //!
   TBranch        *b_GemCluster2d_x;   //!
   TBranch        *b_GemCluster2d_y;   //!
   TBranch        *b_GemCluster2d_z;   //!
   TBranch        *b_GemCluster2d_dx;   //!
   TBranch        *b_GemCluster2d_dy;   //!
   TBranch        *b_GemCluster2d_dz;   //!
   TBranch        *b_GemCluster2d_nHit;   //!
   TBranch        *b_GemCluster2d_nHitX;   //!
   TBranch        *b_GemCluster2d_nHitY;   //!

   anaSelector(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~anaSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree , TString);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate(TString);

   //ClassDef(anaSelector,0);
};

#endif

#ifdef anaSelector_cxx
void anaSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Event", &Event, &b_Event);
   fChain->SetBranchAddress("nGemHit", &nGemHit, &b_nGemHit);
   fChain->SetBranchAddress("GemHit_apv", GemHit_apv, &b_GemHit_apv);
   fChain->SetBranchAddress("GemHit_plane", GemHit_plane, &b_GemHit_plane);
   fChain->SetBranchAddress("GemHit_view", GemHit_view, &b_GemHit_view);
   fChain->SetBranchAddress("GemHit_half", GemHit_half, &b_GemHit_half);
   fChain->SetBranchAddress("GemHit_sample", GemHit_sample, &b_GemHit_sample);
   fChain->SetBranchAddress("GemHit_strip", GemHit_strip, &b_GemHit_strip);
   fChain->SetBranchAddress("GemHit_q", GemHit_q, &b_GemHit_q);
   fChain->SetBranchAddress("GemHit_x", GemHit_x, &b_GemHit_x);
   fChain->SetBranchAddress("GemHit_y", GemHit_y, &b_GemHit_y);
   fChain->SetBranchAddress("GemHit_z", GemHit_z, &b_GemHit_z);
   fChain->SetBranchAddress("nGemCluster", &nGemCluster, &b_nGemCluster);
   fChain->SetBranchAddress("GemCluster1d_plane", GemCluster1d_plane, &b_GemCluster1d_plane);
   fChain->SetBranchAddress("GemCluster1d_view", GemCluster1d_view, &b_GemCluster1d_view);
   fChain->SetBranchAddress("GemCluster1d_q", GemCluster1d_q, &b_GemCluster1d_q);
   fChain->SetBranchAddress("GemCluster1d_nHit", GemCluster1d_nHit, &b_GemCluster1d_nHit);
   fChain->SetBranchAddress("GemCluster1d_x", GemCluster1d_x, &b_GemCluster1d_x);
   fChain->SetBranchAddress("GemCluster1d_y", GemCluster1d_y, &b_GemCluster1d_y);
   fChain->SetBranchAddress("GemCluster1d_z", GemCluster1d_z, &b_GemCluster1d_z);
   fChain->SetBranchAddress("GemCluster1d_dx", GemCluster1d_dx, &b_GemCluster1d_dx);
   fChain->SetBranchAddress("GemCluster1d_dy", GemCluster1d_dy, &b_GemCluster1d_dy);
   fChain->SetBranchAddress("GemCluster1d_dz", GemCluster1d_dz, &b_GemCluster1d_dz);
   fChain->SetBranchAddress("nGemCluster2d", &nGemCluster2d, &b_nGemCluster2d);
   fChain->SetBranchAddress("GemCluster2d_plane", GemCluster2d_plane, &b_GemCluster2d_plane);
   fChain->SetBranchAddress("GemCluster2d_q", GemCluster2d_q, &b_GemCluster2d_q);
   fChain->SetBranchAddress("GemCluster2d_qx", GemCluster2d_qx, &b_GemCluster2d_qx);
   fChain->SetBranchAddress("GemCluster2d_qy", GemCluster2d_qy, &b_GemCluster2d_qy);
   fChain->SetBranchAddress("GemCluster2d_x", GemCluster2d_x, &b_GemCluster2d_x);
   fChain->SetBranchAddress("GemCluster2d_y", GemCluster2d_y, &b_GemCluster2d_y);
   fChain->SetBranchAddress("GemCluster2d_z", GemCluster2d_z, &b_GemCluster2d_z);
   fChain->SetBranchAddress("GemCluster2d_dx", GemCluster2d_dx, &b_GemCluster2d_dx);
   fChain->SetBranchAddress("GemCluster2d_dy", GemCluster2d_dy, &b_GemCluster2d_dy);
   fChain->SetBranchAddress("GemCluster2d_dz", GemCluster2d_dz, &b_GemCluster2d_dz);
   fChain->SetBranchAddress("GemCluster2d_nHit", GemCluster2d_nHit, &b_GemCluster2d_nHit);
   fChain->SetBranchAddress("GemCluster2d_nHitX", GemCluster2d_nHitX, &b_GemCluster2d_nHitX);
   fChain->SetBranchAddress("GemCluster2d_nHitY", GemCluster2d_nHitY, &b_GemCluster2d_nHitY);
}

Bool_t anaSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef anaSelector_cxx
