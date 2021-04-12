{
  TFile *fData = TFile::Open("run10try1.root");
  TTree *EventData = (TTree*)fData->Get("EventData");
  EventData->Process("Tandem.C");

}
