{
  TFile *fData = TFile::Open("run10try0.root");
  TTree *EventData = (TTree*)fData->Get("EventData");
  EventData->Process("Tandem.C");

}
