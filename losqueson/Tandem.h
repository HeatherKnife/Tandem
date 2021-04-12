//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Mar 24 15:08:35 2021 by ROOT version 6.22/02
// from TTree EventData/EventData
// found on file: run10try0.root
//////////////////////////////////////////////////////////

#ifndef Tandem_h
#define Tandem_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <iostream>
#include <fstream>
#include <string>
#include <TH2.h>
#include <TStyle.h>
#include "TCanvas.h"
#include "TCut.h"
#include "TGraph.h"
#include <TH1D.h>
#include <cmath>
#include <TF1.h>
#include <TProfile.h>
#include <TRandom3.h>

// Headers needed by this particular selector


class Tandem : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   float_t        Time_A;
   float_t        Time_CFD_raw_A;
   float_t        Time_CFD_smooth_A;

   float_t        Time_B;
   float_t        Time_CFD_raw_B;
   float_t        Time_CFD_smooth_B;

   float_t        Time_C;
   float_t        Time_CFD_raw_C;
   float_t        Time_CFD_smooth_C;

   float_t        ToF_true;

 // List of branches
   TBranch        *b_Time_A;   //!
   TBranch        *b_Time_CFD_raw_A;   //!
   TBranch        *b_Time_CFD_smooth_A;   //!

   TBranch        *b_Time_B;   //!
   TBranch        *b_Time_CFD_raw_B;   //!
   TBranch        *b_Time_CFD_smooth_B;   //!

   TBranch        *b_Time_C;   //!
   TBranch        *b_Time_CFD_raw_C;   //!
   TBranch        *b_Time_CFD_smooth_C;   //!

   TBranch        *b_ToF_true;   //!

   Tandem(TTree * /*tree*/ =0) { }
   virtual ~Tandem() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
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

   ClassDef(Tandem,0);

};

#endif

#ifdef Tandem_cxx
void Tandem::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

    // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Time_A", &Time_A, &b_Time_A);
   fChain->SetBranchAddress("Time_CFD_raw_A", &Time_CFD_raw_A, &b_Time_CFD_raw_A);
   fChain->SetBranchAddress("Time_CFD_smooth_A", &Time_CFD_smooth_A, &b_Time_CFD_smooth_A);

   fChain->SetBranchAddress("Time_B", &Time_B, &b_Time_B);
   fChain->SetBranchAddress("Time_CFD_raw_B", &Time_CFD_raw_B, &b_Time_CFD_raw_B);
   fChain->SetBranchAddress("Time_CFD_smooth_B", &Time_CFD_smooth_B, &b_Time_CFD_smooth_B);

   fChain->SetBranchAddress("Time_C", &Time_C, &b_Time_C);
   fChain->SetBranchAddress("Time_CFD_raw_C", &Time_CFD_raw_C, &b_Time_CFD_raw_C);
   fChain->SetBranchAddress("Time_CFD_smooth_C", &Time_CFD_smooth_C, &b_Time_CFD_smooth_C);

 //  fChain->SetBranchAddress("ToF_true", &ToF_true, &b_ToF_true);

}

Bool_t Tandem::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef Tandem_cxx
