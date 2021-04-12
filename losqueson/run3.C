{
  TFile *fData = TFile::Open("run7try0.root");
  TTree *EventData = (TTree*)fData->Get("EventData");
  EventData->Process("Tandem.C");

}
