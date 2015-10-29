
#ifndef recSelector_h
#define recSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include<vector>

using std::vector;
using std::string;

class recSelector : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

    
   // Declaration of leaf types
   UInt_t          apv_evt;
   Int_t           time_s;
   Int_t           time_us;
   vector<unsigned int> *apv_fecNo;
   vector<unsigned int> *apv_id;
   vector<unsigned int> *apv_ch;
   vector<string>  *mm_id;
   vector<unsigned int> *mm_readout;
   vector<unsigned int> *mm_strip;
   vector<vector<short> > *apv_q;
   UInt_t          apv_presamples;

   // List of branches
   TBranch        *b_apv_evt;   //!
   TBranch        *b_time_s;   //!
   TBranch        *b_time_us;   //!
   TBranch        *b_apv_fecNo;   //!
   TBranch        *b_apv_id;   //!
   TBranch        *b_apv_ch;   //!
   TBranch        *b_mm_id;   //!
   TBranch        *b_mm_readout;   //!
   TBranch        *b_mm_strip;   //!
   TBranch        *b_apv_q;   //!
   TBranch        *b_apv_presamples;   //!

   recSelector(TTree * /*tree*/ =0) { }
   virtual ~recSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree, TString);
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
   virtual void    Terminate();

   //ClassDef(recSelector,0);
};

#endif

#ifdef recSelector_cxx
void recSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   apv_fecNo = 0;
   apv_id = 0;
   apv_ch = 0;
   mm_id = 0;
   mm_readout = 0;
   mm_strip = 0;
   apv_q = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("apv_evt", &apv_evt, &b_apv_evt);
   fChain->SetBranchAddress("time_s", &time_s, &b_time_s);
   fChain->SetBranchAddress("time_us", &time_us, &b_time_us);
   fChain->SetBranchAddress("apv_fecNo", &apv_fecNo, &b_apv_fecNo);
   fChain->SetBranchAddress("apv_id", &apv_id, &b_apv_id);
   fChain->SetBranchAddress("apv_ch", &apv_ch, &b_apv_ch);
   fChain->SetBranchAddress("mm_id", &mm_id, &b_mm_id);
   fChain->SetBranchAddress("mm_readout", &mm_readout, &b_mm_readout);
   fChain->SetBranchAddress("mm_strip", &mm_strip, &b_mm_strip);
   fChain->SetBranchAddress("apv_q", &apv_q, &b_apv_q);
   fChain->SetBranchAddress("apv_presamples", &apv_presamples, &b_apv_presamples);
}

Bool_t recSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef recSelector_cxx
