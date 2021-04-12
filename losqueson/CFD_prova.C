#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void CFD_prova()
{

   TFile *file0 = TFile::Open("run10try0.root");
   TTree *EventData=(TTree*) file0->Get("EventData");

   float Time_CFD_smooth_A;
   float Time_CFD_smooth_B;
   float Time_CFD_smooth_C;

   float ToF;


   EventData->SetBranchAddress("Time_CFD_smooth_A", &Time_CFD_smooth_A);
   EventData->SetBranchAddress("Time_CFD_smooth_B", &Time_CFD_smooth_B);
   EventData->SetBranchAddress("Time_CFD_smooth_C", &Time_CFD_smooth_C);


   int entries = EventData->GetEntries();

   cout << entries << endl;

 for(int i = 0; i < entries; i++)
   {
   	EventData->GetEntry(i);
   	cout << Time_CFD_smooth_A << " " << Time_CFD_smooth_B << " " << Time_CFD_smooth_C << endl;

      ToF = Time_CFD_smooth_C - Time_CFD_smooth_B;
      

   } 

   file0->Close();
}