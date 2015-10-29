#include "digitizerSample.h"
#include <iostream>
#include <fstream>

using namespace std;

float pedMean[maxHit];
float pedRMS[maxHit];

int digitizerSample::digitize(vector<unsigned int> *_id,
                        vector<unsigned int> *_ch,
                        vector<vector<short> > *_q,
                        struct Hit *_GemHit)  {
    
    
    int iId , jQ , kHit, nHit = 0;
    int SizeId = _id->size();
    int SizeQ;
    int myQ;
    float QMax,QMaxtot;  
    float QThr;
    float GEMQThr;
    float WELLQThr;
    int sample, min_samp, max_samp,WELLmin_samp,WELLmax_samp; // to keep track of the signal sample
    int i=0;
    bool flag=false;
    //bool flag=true;

    QThr = 0;
    //GEMQThr= 55; // fixed threshold to be set to proper value
    GEMQThr= 55; // fixed threshold to be set to proper value
    WELLQThr = 50;
   
    kHit = 0;
    min_samp = 1;//5
    max_samp = 30;//20
    WELLmin_samp = 3;
    WELLmax_samp = 10;
    /* WELLmin_samp = 0;
       WELLmax_samp = 30;*/
    QMaxtot=1600;
    
    /*for (iId=0; iId<SizeId; iId++) {// loop on the channels	!!!      
        SizeQ = _q->at(iId).size() ;
	QMax = -10000;
        
	for(jQ=0;jQ < SizeQ ;jQ++) { // loop on the Q charge samples to find the max            
	  myQ =  _q->at(iId).at(jQ);
	  if (myQ > QMax) {
	    QMax = myQ;
	    sample = jQ;
	  }
	}
	if (QMax>QMaxtot && APVreadout[_id->at(iId)]==2 ) {
	  QMaxtot=QMax;
	  i++;
	  flag=true;
	  //cout << flag << " qui " << QMaxtot << endl;
	  }
    }
    //cout << i << endl;*/
    
    if (!(flag)) {
    for (iId=0; iId<SizeId; iId++) {// loop on the channels	!!!      
        SizeQ = _q->at(iId).size() ;
	QMax = -10000;
        
	for(jQ=0;jQ < SizeQ ;jQ++) { // loop on the Q charge samples to find the max            
	  myQ =  _q->at(iId).at(jQ);
	  //cout << myQ << endl;
	  /*if (myQ > QMax) {
	    QMax = myQ;
	    sample = jQ;
	    }*/
	  //}
	
	//if (APVreadout[_id->at(iId)]==0 && QMax > GEMQThr && sample>min_samp && sample<max_samp) {//Tracker
	  if (APVreadout[_id->at(iId)]==0) {//Tracker
	  _GemHit->q[kHit] = myQ;
	  _GemHit->apv[kHit] = APVmap[_id->at(iId)] ;
	  _GemHit->plane[kHit] = Planemap[_id->at(iId)] ;
	  _GemHit->view[kHit] = Viewmap[_id->at(iId)] ;
	  _GemHit->half[kHit] = Halfmap[_id->at(iId)] ;
	  _GemHit->sample[kHit] = sample ;
	  _GemHit->strip[kHit] = _ch->at(iId);
	  /*cout << "kHit " << kHit << endl;
	    cout << _GemHit->strip[kHit] << " " <<_ch->at(iId) <<  endl;*/
	  //cout << "kHit " << kHit << " Strip " <<  _GemHit->strip[kHit] << endl; 
	  _GemHit->z[kHit] = Zpos[Planemap[_id->at(iId)]] +  AllCoeff_z[Planemap[_id->at(iId)]] ;
	  
	  if (Viewmap[_id->at(iId)] == 0) {
	    _GemHit->x[kHit] = (pitch*(_GemHit->strip[kHit] - 64)) + AllCoeff_x[Planemap[_id->at(iId)]] + (pitch/2);
	    _GemHit->y[kHit] = -9999;
	  }
	  else {
	    _GemHit->y[kHit] = (pitch*(_GemHit->strip[kHit] - 64)) + AllCoeff_y[Planemap[_id->at(iId)]] + (pitch/2);
	    _GemHit->x[kHit] = -9999;
	  }
	  kHit++;
	}
	 

	  //if (APVreadout[_id->at(iId)]==1 && QMax > GEMQThr && sample>min_samp && sample<max_samp ) {//BESIII
	  if (APVreadout[_id->at(iId)]==1) {//BESIII
	  _GemHit->q[kHit] = myQ;
	  _GemHit->apv[kHit] = APVmap[_id->at(iId)] ;
	  _GemHit->plane[kHit] = Planemap[_id->at(iId)] ;
	  _GemHit->view[kHit] = Viewmap[_id->at(iId)] ;
	  _GemHit->half[kHit] = Halfmap[_id->at(iId)] ;
	  _GemHit->sample[kHit] = sample ;
	  _GemHit->strip[kHit] = 127 - _ch->at(iId); 
	  /*cout << "kHit " << kHit << endl;
	    cout << _GemHit->strip[kHit] << " " <<_ch->at(iId) <<  endl;*/
	  //cout << "kHit " << kHit << " Strip " <<  _GemHit->strip[kHit] << endl; 
	  _GemHit->z[kHit] = Zpos[Planemap[_id->at(iId)]] +  AllCoeff_z[Planemap[_id->at(iId)]] ;

	  if (Viewmap[_id->at(iId)] == 0) {
	    _GemHit->x[kHit] = (pitch*(_GemHit->strip[kHit] - 64)) + AllCoeff_x[Planemap[_id->at(iId)]] + (pitch/2);
	    _GemHit->y[kHit] = -9999;
	  }
	  else {
	    _GemHit->y[kHit] = (pitch*(_GemHit->strip[kHit] - 64)) + AllCoeff_y[Planemap[_id->at(iId)]] + (pitch/2);
	    _GemHit->x[kHit] = -9999;
	  }
	  kHit++;
	}
	  
	  //if (APVreadout[_id->at(iId)]==2 && QMax >= WELLQThr && sample>=WELLmin_samp && sample<=WELLmax_samp) {//next 
	  if (APVreadout[_id->at(iId)]==2) {//next 
	  
	    //cout << "_ch= " << _ch->at(iId) << endl;
	  _GemHit->q[kHit] = myQ;
	  _GemHit->apv[kHit] = APVmap[_id->at(iId)] ;
	  _GemHit->plane[kHit] = Planemap[_id->at(iId)] ;
	  _GemHit->view[kHit] = Viewmap[_id->at(iId)] ;
	  _GemHit->half[kHit] = Halfmap[_id->at(iId)] ;
	  //_GemHit->sample[kHit] = sample ;
	  _GemHit->sample[kHit] = jQ;
	  _GemHit->strip[kHit] = 127- _ch->at(iId); 		  
	  
	  cout << _GemHit->q[kHit]  << " " <<  _GemHit->sample[kHit] <<  " " << _GemHit->plane[kHit] << endl;
	  _GemHit->z[kHit] = Zpos[Planemap[_id->at(iId)]] +  AllCoeff_z[Planemap[_id->at(iId)]] ;
	  
	  if (Viewmap[_id->at(iId)] == 0) {
	    _GemHit->x[kHit] = (pitchBen*(_GemHit->strip[kHit] - 64)) + AllCoeff_x[Planemap[_id->at(iId)]] + (pitchBen/2);
	    _GemHit->y[kHit] = -9999;
	  }
	  else {
	    _GemHit->y[kHit] = (pitchBen*(_GemHit->strip[kHit] - 64)) + AllCoeff_y[Planemap[_id->at(iId)]] + (pitchBen/2);
	    //cout << "kHit " << kHit << " Strip " <<  _GemHit->strip[kHit] << " Q " <<  _GemHit->q[kHit] << " Y " << _GemHit->y[kHit] << endl; 
	    _GemHit->x[kHit] = -9999;
	  }
	  kHit++;	
	  }

	}

    }	//for (iId=0; iId<SizeId; iId++)
    
    } //if !(flag)

    _GemHit->nHit = kHit;
    
    return kHit; 
    
}
/*
void digitizer::initThreshold() {
    TString pedFile = PedDir + "ped_cal_run106.root.txt";
    ifstream iFile(pedFile);	// input.txt has integers, one per line

    int id;cout << kHit << endl;
    float Mean,RMS;
    while (iFile >> id)
    {
        iFile >> pedMean[id];
        iFile >> pedRMS[id];
    }    
    cout<<"Threshold loaded"<<endl;

}
*/















