{
  TFile *fData = TFile::Open("run6try0.root");
  TTree *EventData = (TTree*)fData->Get("EventData");
  EventData->Process("Tandem.C");

}
