#include "digitizer.h"
#include <iostream>
#include <fstream>

using namespace std;

float pedMean[maxHit];
float pedRMS[maxHit];

int digitizer::digitize(vector<unsigned int> *_id,
                        vector<unsigned int> *_ch,
                        vector<vector<short> > *_q,
                        struct Hit *_GemHit)  {
    
    
    int iId , jQ , kHit, nHit = 0;
    int SizeId = _id->size();
    int SizeQ;
    int myQ;
    float QMax;  
    float QPed;  
    float QThr;
    int sample; // to keep track of the signal sample
    
    QPed = -2850;// pedestal value fixed to be set to proper value    
    QThr = 75;   // fixed threshold to be set to proper value
    //QThr = 0; //Per WELL deve essere messo a zero
    kHit = 0;

    for (iId=0; iId<SizeId; iId++) {// loop on the channels	!!!
      //if (iId>255)*/ cout <<"iId "<<iId<<" APV "<< APVmap[_id->at(iId)]<<" Ch "<<_ch->at(iId)<< endl;

        //cout <<APVreadout[_id->at(iId)] ;
        
        //if ( /*!(APVreadout[_id->at(iId)]==1 && iId%2==1) &&*/ !(APVreadout[_id->at(iId)]==2 && iId%2==1) ) {

	  //cout << iId << " " << _id->at(iId) << " " << APVreadout[_id->at(iId)] <<endl; 

            SizeQ = _q->at(iId).size() ;
            QMax = -10000;

            
            for(jQ=0;jQ < SizeQ ;jQ++) { // loop on the Q charge samples to find the max            
                myQ =  _q->at(iId).at(jQ);
                if (myQ > QMax) {
                    QMax = myQ;
                    sample = jQ;
                }
            }
	    //if (APVreadout[_id->at(iId)]!=2 && QMax< QThr) {
	    //  cout << QMax << " " << APVreadout[_id->at(iId)] << endl;}

            //QPed = pedMean[iId];
            //QThr = n_of_sigma*pedRMS[iId];

           //if (iId==170) cout<<"QPed: "<<QPed<<" QThr:  "<<QThr<<" QMax: "<<QMax<<" QMax - QPed: "<<QMax - QPed<<" Qoffset: "<<Qoffset<<endl;
            
            //if  (Qoffset + QMax - QPed > QThr) {  // if the charge is greater than the threshold the hit is created
            if (QMax > QThr){ //if  (QMax - QPed > QThr) {  // if the charge is greater than the threshold the hit is created
                //_GemHit->q[kHit] = QMax - QPed;
                _GemHit->q[kHit] = QMax; 
                _GemHit->apv[kHit] = APVmap[_id->at(iId)] ;
                _GemHit->plane[kHit] = Planemap[_id->at(iId)] ;
                _GemHit->view[kHit] = Viewmap[_id->at(iId)] ;
                _GemHit->half[kHit] = Halfmap[_id->at(iId)] ;
                _GemHit->sample[kHit] = sample ;

                if (APVreadout[_id->at(iId)]==0) _GemHit->strip[kHit] = _ch->at(iId);
		else                             _GemHit->strip[kHit] = 127 - _ch->at(iId);   //GIGI
		//else                             _GemHit->strip[kHit] = 128 - _ch->at(iId); //NOI

                //strip calculation
		//if (APVreadout[_id->at(iId)]==0) //{//tracker
                //     _GemHit->strip[kHit] = 127 - ( 64 - (_ch->at(iId) / 2) -1 );
		//     else _GemHit->strip[kHit] = 127 - ( 128 - ((_ch->at(iId) +1) / 1 ) );                
                //    int Cha;
                //    if (iId%2==0) Cha = 126 - 2*_ch->at(iId);
                //    if (iId%2==1) Cha = 255 - (_ch->at(iId) * 2) ;
                //    if (iId%2==0) _GemHit->strip[kHit] = 127 - ( 64 - (/*_ch->at(iId)*/ Cha / 2) -1 );
                //    else _GemHit->strip[kHit] = 127 - ( 128 - ((/*_ch->at(iId)*/ Cha +1) / 2 ) );
		    //}
		    //if (APVreadout[_id->at(iId)]==1 ) {//bestest
	      //if (APVmap[_id->at(iId)]%2==0) _GemHit->strip[kHit] = _ch->at(iId) / 2;
		    //  if (APVmap[_id->at(iId)]%2==1) _GemHit->strip[kHit] = 64 + _ch->at(iId) / 2;
		    //}

            
                if (APVreadout[_id->at(iId)]==2) {//next
		  if (Halfmap[_id->at(iId)]==0) _GemHit->strip[kHit] = (_ch->at(iId) + 2 ) ; 
		  //else                          _GemHit->strip[kHit] = 127 - ( ( _ch->at(iId) ) ); //GIGI
		  else                          _GemHit->strip[kHit] = 128 - ( ( _ch->at(iId) ) );   //NOI
                }

		

                // position calculation
                _GemHit->z[kHit] = Zpos[Planemap[_id->at(iId)]] +  AllCoeff_z[Planemap[_id->at(iId)]] ;

                if(APVreadout[_id->at(iId)]==2) {
			 if (Viewmap[_id->at(iId)] == 0) {
				 _GemHit->x[kHit] = (pitchBen*(_GemHit->strip[kHit] - 64)) + AllCoeff_x[Planemap[_id->at(iId)]] + (pitchBen/2);
				 _GemHit->y[kHit] = -9999;
			 }
			 else {
				 _GemHit->y[kHit] = (pitchBen*(_GemHit->strip[kHit] - 64)) + AllCoeff_y[Planemap[_id->at(iId)]] + (pitchBen/2);
				 _GemHit->x[kHit] = -9999;
		         }                         
                }
          
                else {
			 if (Viewmap[_id->at(iId)] == 0) {
				 _GemHit->x[kHit] = (pitch*(_GemHit->strip[kHit] - 64)) + AllCoeff_x[Planemap[_id->at(iId)]] + (pitch/2);
				 _GemHit->y[kHit] = -9999;
			 }
			 else {
				 _GemHit->y[kHit] = (pitch*(_GemHit->strip[kHit] - 64)) + AllCoeff_y[Planemap[_id->at(iId)]] + (pitch/2);
				 _GemHit->x[kHit] = -9999;
		         }
                }
                kHit++;
	  } // if (QMax > QThr)
	    //} //!(APVreadout[_id->at(iId)]==2 && iId%2==1)
    } // loop on the channels	!!!
    _GemHit->nHit = kHit;

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















