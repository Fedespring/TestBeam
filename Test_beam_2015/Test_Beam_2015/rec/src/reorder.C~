#include "reorder.h"
#include <iostream>
#include <fstream>

using namespace std;



int reorder::reorde(vector<unsigned int> *_id,
		    vector<unsigned int> *_ch,
		    vector<vector<short> > *_q,
		    struct Hit *_GemHit)  {
    
    
    int kHit;
    int i;
    float temp,temp1,temp2,temp3,temp4,temp5,temp6,temp7;
    bool debug=false;    
    bool debug1=false;

    //_GemHit->strip[kHit] << endl; 
    //cout << _GemHit->nHit << endl;
    

    if  (debug) {
      cout << " " << endl;
      cout << "Numero di Hit passato nel Riordino " << _GemHit->nHit << endl;
      //cout << "Da cui devo togliere 1 perché Digitalizer incrementa di 1 alla fine dell'evento" << endl;
      cout << " " << endl;
      cout << "Ordine Normale " << endl;
      for (i=0;i<=(_GemHit->nHit-1); i++) {
	//for (i=0;i<=(kHit+1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << " Q " << _GemHit->q[i] << " Y " << _GemHit->y[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }


    //1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }
//1° Iteraction
    for (i=1;i<=(_GemHit->nHit-1); i++) {
      if (_GemHit->plane[i]==4 && _GemHit->plane[i-1]==4) {//next 
	if (_GemHit->strip[i] > _GemHit->strip[i-1]) {
	  //cout << _GemHit->strip[i] << " " << _GemHit->strip[i-1] << endl;
	  //cout << "qui" << endl;
	  temp                 = _GemHit->strip[i];
	  temp1                = _GemHit->q[i];
          temp2                = _GemHit->apv[i];
	  temp3                = _GemHit->plane[i];
	  temp4                = _GemHit->view[i]; 
	  temp5                = _GemHit->half[i];
	  temp6                = _GemHit->sample[i];
	  temp7                = _GemHit->y[i];

	  _GemHit->strip[i]   = _GemHit->strip[i-1];
	  _GemHit->q[i]       = _GemHit->q[i-1];
          _GemHit->apv[i]     = _GemHit->apv[i-1];
	  _GemHit->plane[i]   = _GemHit->plane[i-1];
	  _GemHit->view[i]    = _GemHit->view[i-1]; 
	  _GemHit->half[i]    = _GemHit->half[i-1];
	  _GemHit->sample[i]  = _GemHit->sample[i-1];
	  _GemHit->y[i]       = _GemHit->y[i-1];

	  _GemHit->strip[i-1] = temp;
	  _GemHit->q[i-1]     = temp1;
	  _GemHit->apv[i-1]   = temp2;
	  _GemHit->plane[i-1] = temp3; 
	  _GemHit->view[i-1]  = temp4;
	  _GemHit->half[i-1]  = temp5;
	  _GemHit->sample[i-1]= temp6;
	  _GemHit->y[i-1]     = temp7;
	}
      }
    }
    

    if  (debug1) {
      cout << "Prima iterazione " << endl;
       for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << endl;
	  //cout << _GemHit->plane[i] << endl;
	}
      }
      cout << " " << endl;
    }

    
    

    


    if (debug) {
      cout << "Ordering Finished" << endl;
      for (i=0;i<=(_GemHit->nHit-1); i++) {
	if (_GemHit->plane[i]==4) {
	  cout << "i " << i << " Strip " <<  _GemHit->strip[i] << " Q " << _GemHit->q[i] << " Y " << _GemHit->y[i] << endl;
	}
      }
      cout << " " << endl;
      cout << "End of Event " << endl;
      cout << " " << endl;
    }
      
    return kHit;
    
    

}
/*
void digitizer::initThreshold() {
    TString pedFile = PedDir + "ped_cal_run106.root.txt";
    ifstream iFile(pedFile);	// input.txt has integers, one per line

    int id;
    float Mean,RMS;
    while (iFile >> id)
    {
        iFile >> pedMean[id];
        iFile >> pedRMS[id];
    }    
    cout<<"Threshold loaded"<<endl;

}
*/















