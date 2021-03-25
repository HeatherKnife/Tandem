#include <iostream>
#include <fstream>
using namespace std;

/// Root Includes
#include <TROOT.h>
#include <TCanvas.h>
#include <TSystem.h>
#include <TFile.h>

#include <TH1F.h>

#include <iostream>
#include <cmath>
#include <TMath.h>

#include "CFile.h"
#include "CTrack.h"
#include "Class.h"


ClassImp(Class)

Class::Class() {

tree = new TTree("tree","tree");
tree->Branch("pA1",&pA1);
tree->Branch("pA2",&pA2);
tree->Branch("ph1",&ph[0]);
tree->Branch("ph2",&ph[1]);

tree->Branch("PostSig2",&PostSig2);
tree->Branch("PreSig2",&PreSig2);

tree->Branch("PostSig10",&PostSig10);
tree->Branch("PreSig10",&PreSig10);

tree->Branch("PostSig50",&PostSig50);
tree->Branch("PreSig2",&bl_post);

tree->Branch("PostSig100",&PostSig100);
tree->Branch("bl_post",&bl_post);

tree->Branch("PostSig200",&PostSig200);
tree->Branch("bl_post",&bl_post);

tree->Branch("PostSig400",&PostSig400);
tree->Branch("bl_post",&bl_post);





//def of two structures


gStyle->SetPalette(1);
}

//============================================================

Class::~Class() {
TFile f("/home/daniela/Documents/MastersThesis/Testdata1/dsp_Daniela_2021/dsp0.3/out.root","recreate");

  tree->Write();
  f.Close();
}

//============================================================


void Class::DoAnalysis(CTrack** ch, Int_t aNr) {



//================================================================================================
  tA1 = ch[5];
  tA2 = ch[6];

// =================Fission chamber================================================

  //Find pulse-heights. get the lowere values and higher values, then subtract them for average heights
tA1->BaseLine(20,20,-1.); 

bl_pre  = tA1->FindPulseHeight(0,100); //should be a gaussian around 0
bl_post = tA1->FindPulseHeight(600,700); 


  PostSig2 = tA1->FindPulseHeight(600,602);
  PreSig2 = tA1->FindPulseHeight(0,2);


  PostSig10 = tA1->FindPulseHeight(600,610);
  PreSig10 = tA1->FindPulseHeight(0,10);


  PostSig50 = tA1->FindPulseHeight(600,650);
  PreSig50 = tA1->FindPulseHeight(0,50);


  PostSig100 = tA1->FindPulseHeight(600,700);
  PreSig100 = tA1->FindPulseHeight(0,100);

  PostSig200 = tA1->FindPulseHeight(600,700);
  PreSig200 = tA1->FindPulseHeight(0,100);

  PostSig400 = tA1->FindPulseHeight(600,700);
  PreSig400 = tA1->FindPulseHeight(0,100);


//
//Other way of finding the pulse height
  tA1->FindPeakBin();
  pA1 = tA1->GetAmplitude();

//root tree for the pulse heights

//tA1->BaseLineCorrection(600);//10,50,100
  
        //cout << tA1 << endl;




  tA2->BaseLine(20,20,-1); 

//cout << "test "<<endl;

//tA1->DerivativeALF(1280); //go through different orders of magnitude.starting 11600
//tA1->IntegrateALF(0,1024);   
/*tA2->DerivativeALF(11600);    

  tA1->Fillter("crrc4",0.5);
  tA1->FindPeakBin();
  pA1 = tA1->GetAmplitude();
  tA2->Fillter("crrc4",0.5);
  tA2->FindPeakBin();
  pA2 = tA2->GetAmplitude();

*/
  tree->Fill();

  
}


//============================================================

void Class::Refresh(){
 //place here command to be executed to refresh the (if any) canvas
  //Class::Refresh() is called internaly at every X event or every X ms.
  //cout<<"That's refreshing\t"<<GetEventNb()<<"\t"<<iTimeRefresh<<"\t"<<iEventRefresh<<endl;
  //cout<<GetOutFileName()<<endl;
}

void Class::FastSlowComponent(CTrack* chx, Double_t &pulseheight, Double_t &fast, Double_t &slow) //From Catalin
{
fast = 0.;
slow = 0.;
pulseheight=0.;
Int_t a = (Int_t)chx->FindBin(chx->GetAmplitudePosition()-20);
Int_t b = (Int_t)chx->FindBin(chx->GetAmplitudePosition()+10);
Int_t c = (Int_t)chx->FindBin(chx->GetAmplitudePosition()+30);
Int_t d = (Int_t)chx->FindBin(chx->GetAmplitudePosition()+200);
if(d<=(Int_t) chx->GetNbinsX() && a>=1) {//check that integration range is within track
  for(Int_t i = a; i < b; i++){
       fast += chx->GetBinContent(i)/20.;
       }
  for(Int_t i = c; i < d; i++){
    slow += chx->GetBinContent(i)/180.;
     }
  for(Int_t i = a; i < d; i++){
    pulseheight += chx->GetBinContent(i)/200.;
    }
  };
}

Double_t Class::CenterOfGravityCharge(CTrack* Track, Double_t StartTime, Double_t RiseTime)
{
Double_t Ta = 2.0*RiseTime;

Int_t n = Track->GetNbinsX();
Int_t StartBin = (Int_t) StartTime; //track is out of range
if(StartBin<1) return 0.;
Int_t nn = StartBin + 2.0*Ta;
if(nn>n) nn=n;

Double_t *Data = new Double_t[n];
Double_t s = 0;
for(Int_t i=StartBin;i<nn;i++) {
  s +=  (Track->GetBinContent(i)-Track->GetBinContent(i-1))*(Double_t(i)-StartTime)*TMath::Exp(-TMath::Power((Double_t(i)-StartTime)/Ta,10.));
  Data[i-1] = s;
}
for(Int_t i=nn;i<=n;i++) {
  Data[i-1] = s;
}