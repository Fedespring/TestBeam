#include <iostream>
#include <fstream>

#include "parameters.h"
#include "TChain.h"
#include "TSystem.h"
#include "TString.h"
#include "recSelector.h"
#include "TSelector.h"
#include <TROOT.h>

using namespace std;
main(int argc, char* argv[]) {
    
    
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " filename.root" << std::endl;
        return 1;
    }
    TString inFile = RawDir+argv[1];
    
    
    std::ifstream inStream(inFile, std::ios::binary);
    if (!inStream) {
        std::cerr << "File " << inFile << " not found" << std::endl;
        return 1;
    }
       
    TChain ch("raw");
    ch.Add(inFile);
    
    recSelector *sel = new recSelector();
    
    sel->Init( (TTree* ) &ch);
    sel->Begin((TTree* ) &ch, argv[1]);
    long int nEntries = ch.GetEntries();
    
    for (long int i=0;i<nEntries;i++) {
        sel->Process(i);
    }

    sel->Terminate();

    
}


