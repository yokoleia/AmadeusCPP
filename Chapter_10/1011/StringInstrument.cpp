#include "StringInstrument.h"
using namespace std;

void StringInstrument::SetName(string stringInstrumentName) {
    this->instrumentName = stringInstrumentName;
}
void StringInstrument::SetManufacturer(string stringManufacturer) {
    this->instrumentManufacturer = stringManufacturer;
}
void StringInstrument::SetYearBuilt(int stringYearBuilt) {
    this->yearBuilt = stringYearBuilt;
}
void StringInstrument::SetCost(int stringCost) {
    this->cost = stringCost;
}
void StringInstrument::SetNumOfStrings(int numStrings) {
    this->numStrings = numStrings;
}
void StringInstrument::SetNumOfFrets(int numFrets) {
    this->numFrets = numFrets;
}
void StringInstrument::SetIsBowed(bool bowed) {
    this->bowed = bowed;
}

int StringInstrument::GetNumOfStrings() const {
    return this->numStrings;
}
int StringInstrument::GetNumOfFrets() const {
    return this->numFrets;
}
bool StringInstrument::GetIsBowed() const {
    return this->bowed;
} 



