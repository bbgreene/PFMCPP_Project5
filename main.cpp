/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
 */




#include <iostream>
/*
 copied UDT 1:
 */
struct HousePlant
{
    int currentNumRoots;
    int numLeaves;
    float waterInRoots;
    int numFlowers;
    int numLadybirdsPerDay;
    int potentialLeafGrowthPerDay;
    
    HousePlant();
    ~HousePlant();

    void memberFunc()
    {
        std::cout << "HousePlant: Amount of water in the roots is " << this->waterInRoots << " litres" << std::endl;
    }

    void transportWater();
    void absorbWater(float amountOfWaterPerDay, bool wasItWatered);
    void growthPerDay(bool sunnyDay);
    int addLeaves(int fertiliserThres);
};

HousePlant::HousePlant()
{
    currentNumRoots = 25;
    numLeaves = 73;
    waterInRoots = 1.2f;
    numFlowers = 22;
    numLadybirdsPerDay = 3;
    potentialLeafGrowthPerDay = 0;
}

HousePlant::~HousePlant() 
{
    std::cout << "How to deconstruct a house plant" << std::endl;
}

void HousePlant::transportWater()
{
    std::cout << "The amount of leaves that need water is " << numLeaves << std::endl;
}

void HousePlant::absorbWater(float amountOfWaterPerDay, bool wasItWatered)
{
    if(wasItWatered)
    {
        amountOfWaterPerDay = 1.2f;
    }
    else 
    {
        amountOfWaterPerDay = 0.1f;
    }
    waterInRoots += amountOfWaterPerDay;
}

void HousePlant::growthPerDay(bool sunnyDay)
{
    if(sunnyDay)
    {
        numFlowers += 1;
        std::cout << "The amount of flowers is " << numFlowers << std::endl;
    } 
    else 
    {
        std::cout << "The amount of flowers is " << numFlowers << std::endl;  
    }
}

int HousePlant::addLeaves(int fertiliserThres)
{
    for(potentialLeafGrowthPerDay = 0; potentialLeafGrowthPerDay < fertiliserThres; potentialLeafGrowthPerDay += 1)
    {   
        if(potentialLeafGrowthPerDay >= 3)
        {
            std::cout << "More than 1 leaf has been grown" << std::endl;
            break;    
        } 
    }
    return potentialLeafGrowthPerDay;
}
/*
 copied UDT 2:
 */
struct Envelope
{
    float attTime;
    float decTime;
    float susLevel;
    float relTime; 
    int midiVelLevel;
    
    Envelope();
    ~Envelope();

    void memberFunc()
    {
        std::cout << "Envelope: The current sustain level is: " << this->susLevel << std::endl;
    }

    void addAttackToAmp();
    void controlCutoffOverTime(bool filterEnvSelected, bool isKeyPressed, double maxValueFilter);
    void controlPitchOverTime(bool pitchEnvSelected, bool isKeyPressed, double maxValuePitch);
    float looping(float envLoopThres);
};

Envelope::Envelope()
{
    attTime = 0.3f;
    decTime = 0.5f;
    susLevel = 2.0f;
    relTime = 1.5f; 
    midiVelLevel = 75;
}

Envelope::~Envelope() 
{
    std::cout << "This deconstructs the envelope" << std::endl;
}

void Envelope::addAttackToAmp()
{
   std::cout << "The attack time is " << attTime << " seconds" << std::endl;
}

void Envelope::controlCutoffOverTime(bool filterEnvSelected, bool isKeyPressed, double maxValueFilter)
{
    if(isKeyPressed && filterEnvSelected)
    {
        maxValueFilter = midiVelLevel * 10;
    }
    else 
    {
        maxValueFilter = 1000;
    }
}

void Envelope::controlPitchOverTime(bool pitchEnvSelected, bool isKeyPressed, double maxValuePitch)
{
    if(isKeyPressed && pitchEnvSelected)
    {
        maxValuePitch = 24 / 100 * midiVelLevel;
    }
    else 
    {
        maxValuePitch = 0;
    }
}

float Envelope::looping(float envLoopThres)
{
    float looplength {0.0f};

    while(looplength < envLoopThres)
    {
        looplength += 0.1f;
        
        if(looplength >= 1.0f)
        {
            std::cout << looplength << " sec(s): The envelope is not looping" << std::endl;
            break;    
        } 
    }
    return looplength;
}
/*
 copied UDT 3:
 */
struct LFO
{
    int modDest;
    float lfoRate;
    float modAmount;
    float attack;
    std::string waveform;
    
    LFO();
    ~LFO();

    void memberFunc()
    {
        std::cout << "LFO: The current modulating waveform is: " << this->waveform << std::endl;
    }

    void modAmpOfSample();
    void modPitchOfSample(bool lfoON, int pitchRange, bool pitchToggle);
    void modPanOfSample(bool lfoON, int panRange, bool panToggle);
    float createSidebands(float sidebandThres);
};

LFO::LFO()
{
    modDest = 0;
    lfoRate = 0.0f;
    modAmount = 0.5f;
    attack = 2.3f;
    waveform = "Saw";
}

LFO::~LFO()
{
    std::cout << "This deconstructs the LFO" << std::endl;
}

void LFO::modAmpOfSample()
{
   std::cout << "Please modulation the amplitude for a tremolo effect" << std::endl;
}

void LFO::modPitchOfSample(bool lfoON, int pitchRange, bool pitchToggle = true)
{
    if(lfoON && pitchToggle)
    {
        pitchRange = 24;
    }
    else
    {
        pitchRange = 0;
    }
    modDest += 1;
}

void LFO::modPanOfSample(bool lfoON, int panRange, bool panToggle = true)
{
    if(lfoON && panToggle)
    {
        panRange = 100;
    }
    else
    {
        panRange = 0;
    }
    modDest += 2;
}

float LFO::createSidebands(float sidebandThres)
{
    float currentRate {0.0f};

    while(currentRate < sidebandThres)
    {
        currentRate += 0.1f;
        
        if(currentRate >= 15.0f)
        {
            std::cout << currentRate << " Hz: The modulation is now synthesising sidebands!" << std::endl;
            break;    
        } 
    }
    return currentRate;
}
/*
 new UDT 4:
 with 2 member functions
 */
struct Daw
{
    LFO lfoNum;
    Envelope env;

    Daw();
    ~Daw();

    void memberFunc()
    {
        std::cout << "The attack of this specific LFO is " << this->lfoNum.attack << " secs" << std::endl;
    }

    void applyLFO(bool lfoOn, int modDest);
    void applyEnvtoPitch(bool filterEnvSelected, bool isKeyPressed);
};

Daw::Daw()
{
    lfoNum.modDest = 2;
    env.controlPitchOverTime (true, true, 2000.0);
}

Daw::~Daw() 
{
    std::cout << "Turn off LFO" << std::endl;
    lfoNum.modAmount = 0.0f;
    std::cout << "Envelope not responding to velocity" << std::endl;
    env.midiVelLevel = 0;
}

void Daw::applyLFO(bool lfoOn, int modDest)
{
    if(lfoOn && modDest > 0)
    {
        std::cout << "The LFO is on" << std::endl;
    }
}

void Daw::applyEnvtoPitch(bool filterEnvSelected, bool isKeyPressed)
{
    if(filterEnvSelected && isKeyPressed)
    {
        std::cout << "The envelope is modulating the pitch" << std::endl;
    }
    else
    {
        std::cout << "The envelope is not modulating the pitch" << std::endl;
    }
}
/*
 new UDT 5:
 with 2 member functions
 */
struct WindowSill
{
    HousePlant plant1, plant2;
    HousePlant plant3;

    WindowSill();
    ~WindowSill();
    
    void memberFunc()
    {
        std::cout << "The current number of roots in plant 3 is " << this->plant3.currentNumRoots << std::endl;
    }

    void letLightIn(bool windowBlindsOpen);
    void evaporateWater(float insideTemp, float evapTemp);
};

WindowSill::WindowSill()
{
    plant1.numFlowers = 23;
    plant2.numFlowers = 44;
    plant3.waterInRoots = 4.2f;
}

WindowSill::~WindowSill()
{
    std::cout << "No extra flowers for Plant 1 today, please destroy" << std::endl;
    plant1.growthPerDay(false);
    std::cout << "Some extra flowers for Plant 2 today, destroy anyway" << std::endl;
    plant2.growthPerDay(true);
    std::cout << "Plant 3 has more leaves today, however, you must bin it!" << std::endl;
    plant3.addLeaves(4);
}

void WindowSill::letLightIn(bool windowBlindsOpen)
{
    if(windowBlindsOpen)
    {
        std::cout << "The plants will grow today!" << std::endl;
        plant1.potentialLeafGrowthPerDay += 1;
        std::cout << "Potential leaves grown today for Plant 1 is: " << plant1.potentialLeafGrowthPerDay << std::endl;
    }    
}

void WindowSill::evaporateWater(float insideTemp, float evapTemp)
{
    if(insideTemp > evapTemp)
    {
        plant2.waterInRoots -= 0.2f;
        std::cout << "Plant 2 has lost some water....it has " << plant2.waterInRoots << " litre left" << std::endl;
    }
    else
    {
        std::cout << "The temparture is good. Plant 2 currently has " << plant2.waterInRoots << " litres left" << std::endl;
    }

}
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    HousePlant swissCheese;
    swissCheese.transportWater();
    swissCheese.growthPerDay(false);
    auto leavesAdded = swissCheese.addLeaves(3);

    std::cout << leavesAdded << " leaves have been added " << std::endl;
    std::cout << "The plant now has " << leavesAdded + swissCheese.numLeaves << " leaves" << std::endl;
    std::cout << "Swiss Cheese: Amount of water in the roots is " << swissCheese.waterInRoots << " litres" << std::endl;

    swissCheese.memberFunc();

    Envelope firstEnvelope;
    firstEnvelope.addAttackToAmp();
    auto loopingFunction = firstEnvelope.looping(0.5f);

    std::cout << "A looping value above " << loopingFunction << " sec(s) does not loop" << std::endl;

    std::cout << "Does the audio reach full amplitude immdetiately? " << (firstEnvelope.attTime < 0.1f ? "Yes" : "No") << std::endl;

    std::cout << "First envelope: The current sustain level is: " << firstEnvelope.susLevel << std::endl;

    firstEnvelope.memberFunc();

    LFO myLFO;
    myLFO.modAmpOfSample();
    auto modulationRate = myLFO.createSidebands(16.0f);

    std::cout << "The current modulating rate is: " << modulationRate << " Hz" << std::endl;
    
    std::cout << "myLFO: The current modulating waveform is: " << myLFO.waveform << std::endl;

    myLFO.memberFunc();

    Daw daw;
    daw.applyLFO(true, 2);
    daw.applyEnvtoPitch(false, true);

    std::cout << "The attack of the LFO is " << daw.lfoNum.attack << " secs" << std::endl;
    
    daw.memberFunc();

    WindowSill windowsill;
    windowsill.letLightIn(true);
    windowsill.evaporateWater(26.0f, 25.0f);

    std::cout << "The current number of roots is " << windowsill.plant3.currentNumRoots << std::endl;

    windowsill.memberFunc();

    std::cout << "good to go!" << std::endl;
}
