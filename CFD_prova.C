#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void CFD_prova()
{

   TFile *file0 = TFile::Open("run10try0.root");
   TTree *EventData=(TTree*) file0->Get("EventData");

   double Time_CFD_smooth_A;
   double Time_CFD_smooth_B;
   double Time_CFD_smooth_C;

   EventData->SetBranchAddress("Time_CFD_smooth_A", &Time_CFD_smooth_A);
   EventData->SetBranchAddress("Time_CFD_smooth_B", &Time_CFD_smooth_B);
   EventData->SetBranchAddress("Time_CFD_smooth_C", &Time_CFD_smooth_C);


   int entries = EventData->GetEntries();

   cout << entries << endl;

   for(int i = 0; i < entries; i++)
   {
   	EventData->GetEntry(i);
   	cout << Time_CFD_smooth_A << " " << Time_CFD_smooth_B << " " << Time_CFD_smooth_C << endl;
   }

   file0->Close();
}