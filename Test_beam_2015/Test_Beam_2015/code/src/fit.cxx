{

const Int_t n=3;  
  Float_t y[n]={-12.255,-13.195,-19.655};
  Float_t z[n]={60,150,697};
  Float_t dy[n]={1,1,1};
  Float_t dz[n]={1,1,1};

  c1 = new TCanvas();
  mg = new TMultiGraph();
  TGraphErrors *plotZY = new TGraphErrors(n,z,y,dz,dy);
  mg->Add(plotZY);
  mg->Draw("APL");

  TF1 *fitZY = new TF1("fitZY","[0]+[1]*x",-1000,1000);
  plotZY->Fit(fitZY,"Q");
 
  A_ZY = fitZY -> GetParameter(0);
  B_ZY = fitZY -> GetParameter(1);
  cout << "p0 " << A_ZY << endl;
  cout << "p1 " << B_ZY << endl;

  TEllipse el1(568,-18.1392,.1,.2);
   el1.Draw();

  
}
