#include <iostream>
#include <fstream>

#include "TChain.h"
#include "TSystem.h"
#include "TString.h"
#include "TSelector.h"
#include <TROOT.h>
#include "anaSelector.h"
#include "parameters.h"

main(int argc, char* argv[]) {
    
    
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " filename.root" << std::endl;
        return 1;
    }
    TString inFile = RecDir+argv[1];
    
    
    std::ifstream inStream(inFile, std::ios::binary);
    if (!inStream) {
        std::cerr << "File " << inFile << " not found" << std::endl;
        return 1;
    }
       
    TChain ch("t1");
    ch.Add(inFile);

    anaSelector *sel = new anaSelector();
    
    sel->Init( (TTree* ) &ch);
    sel->Begin((TTree* ) &ch, argv[1]);
    long int nEntries = ch.GetEntries();

    std::cout << "-------- " << nEntries << std::endl;
    
    for (long int i=0;i<nEntries;i++) {

      sel->Process(i);
    }

    sel->Terminate(argv[1]);

    
}


