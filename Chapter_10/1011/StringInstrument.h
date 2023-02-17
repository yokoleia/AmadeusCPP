#ifndef STR_INSTRUMENTH
#define STR_INSTRUMENTH
#include "Instrument.h"
#include <string>
using namespace std;
 
class StringInstrument : public Instrument {
    private:

        int numStrings;
        int numFrets;
        bool bowed;
        

    public: 
        //(int numStrings, int numfrets, bool bowed);
        
        int GetNumOfStrings() const;
        int GetNumOfFrets() const;
        bool GetIsBowed() const;

        void SetName(string stringInstrumentName);
        void SetManufacturer(string stringManufacturer);
        void SetYearBuilt(int stringYearBuilt);
        void SetCost(int stringCost);
        void SetNumOfStrings(int numStrings);
        void SetNumOfFrets(int numFrets);
        void SetIsBowed(bool bowed);
        

};


#endif