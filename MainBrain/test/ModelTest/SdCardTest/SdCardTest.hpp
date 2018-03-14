/**  Handles the hardware level functions of the SdFat library
 *
 * #include "SdCardTest.hpp"
 * Created 10-24-17  By: Smitty
 *
 * A longer description.
 */


#ifndef SDCARDTEST_HPP
#define SDCARDTEST_HPP

#include "SdFat.h"
#include "../BaseModelTest/BaseModelTest.hpp"

//Might need additional methods to flesh out all the functionality



class SdCardTest
{
public:
    SdCardTest(void);

    /** 
     * Drafting up possible functions
     * 
     * newFile()
     * newFolder()
     * mount()
     * openFile()
     * 
     * 
     */
private:
    SdFatSdioEX* storageCard;
};


#endif  //SDCARDTEST_HPP
