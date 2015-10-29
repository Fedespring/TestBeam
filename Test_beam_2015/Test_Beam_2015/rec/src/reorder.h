#ifndef reorder_h
#define reorder_h

#include "parameters.h"
#include "hit.h"
#include <vector>
#include <iostream>


using std::vector;
using std::cout;
using std::endl;

namespace reorder  {
	
    int reorde(vector<unsigned int> *_id,
	       vector<unsigned int> *_ch,
	       vector<vector<short> > *_q,
	       struct Hit *_GemHit);
    
    //void initThreshold();
    

}

#endif

