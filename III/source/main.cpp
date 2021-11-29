#define TESLA_INIT_IMPL // If you have more than one file using the tesla header, only define this in the main one
#include <tesla.hpp>    // The Tesla Header
#include <dmntcht.h>
#include "CHEAT/DEFINITIONS/constants.h"
#include "CHEAT/DEFINITIONS/noval.h"
#include "CHEAT/DEFINITIONS/addresses.h"
#include "CHEAT/cheatFunctions.h"

#define GAME_TITLE_ID 0x0100C3C012718000

static bool initialized=false;

//CHECK
bool bid_match() {
    const unsigned char build_id_size=8;
	const unsigned char expected_build_id[build_id_size]={0xCB, 0x06, 0x43, 0x27, 0x0D, 0xA9, 0x6E, 0xCD};
    for(unsigned char i=0; i<build_id_size; i++)
        if(metadata.main_nso_build_id[i]!=expected_build_id[i])
            return false;
    return true;
}

bool debugService_isRunning(){
    Handle handle;
    SmServiceName service=smEncodeName("dmnt:cht");
    bool isRunning=R_FAILED(smRegisterService(&handle, service, false, 1));
    svcCloseHandle(handle);
    if(!isRunning) smUnregisterService(service);
    return isRunning;
}

class LEGALGUI : public tsl::Gui {
public:
    LEGALGUI() {}

    virtual tsl::elm::Element* createUI() override {
        auto *rootFrame = new tsl::elm::OverlayFrame("Legal Information", "You should read this.");
		auto list = new tsl::elm::List();
		if (initialized&&debugService_isRunning()&&metadata.title_id==GAME_TITLE_ID&&bid_match())
		{
			list->addItem(new tsl::elm::CategoryHeader("THIS SOFTWARE MUST NOT BE SOLD NEITHER \nALONE NOR AS PART OF A BUNDLE. \n\nIF YOU PAID FOR THIS SOFTWARE, YOU HAVE \nBEEN SCAMMED AND SHOULD DEMAND YOUR \nMONEY BACK IMMEDIATELY. \n\nThis software is not affiliated with, endorsed or \napproved by Nintendo, Rockstar Games or \nTakeTwo Interactive. \n\nThis software provides users with \nspecial cheats for one or more games in \nthe Grand Theft Auto Trilogy. \nThese cheats were made through \nthe use of cleanroom reverse engineering \ntherefore, no copyright law has been broken. \n\nIn other words, this is a passion project \nplease don't sue me."));
		}
	
		rootFrame->setContent(list);
        return rootFrame;
    }
};

class GuiTest : public tsl::Gui {
public:
    GuiTest(u8 arg1, u8 arg2, bool arg3) {}

    virtual tsl::elm::Element* createUI() override {
        auto rootFrame = new tsl::elm::OverlayFrame("GTA: 3 TRAINER", "Made by Bidziilla, Ver: 1.0");
        auto list = new tsl::elm::List();
        if (initialized&&debugService_isRunning()&&metadata.title_id==GAME_TITLE_ID&&bid_match())
        {
			auto *LEGALINFORMATION = new tsl::elm::ListItem("Legal Information", "\u2600");
			LEGALINFORMATION->setClickListener([](u64 keys) { 
            if (keys & HidNpadButton_A) {
                tsl::changeTo<LEGALGUI>();
                return true;
            }

            return false;
			});
			
			list->addItem(new tsl::elm::CategoryHeader("Cheats"));
			list->addItem(new tsl::elm::CategoryHeader("Legal"));
			list->addItem(LEGALINFORMATION);
		}

        rootFrame->setContent(list);
        return rootFrame;
    }

    virtual bool handleInput(u64 keysDown, u64 keysHeld, const HidTouchState &touchPos, HidAnalogStickState joyStickPosLeft, HidAnalogStickState joyStickPosRight) override 
    {
        return false;
    }
};

class OverlayTest : public tsl::Overlay {
public:
                                             
    virtual void initServices() override
    {
        if (debugService_isRunning())
        {
            dmntchtInitialize();
            dmntchtForceOpenCheatProcess();
            dmntchtGetCheatProcessMetadata(&metadata);

            initialized=true;
        }
    }
    virtual void exitServices() override
    {
        dmntchtExit();
        initialized=false;
    }

    virtual void onShow() override {}
    virtual void onHide() override {}

    virtual std::unique_ptr<tsl::Gui> loadInitialGui() override {
        return initially<GuiTest>(1, 2, true);
    }
};

int main(int argc, char **argv) {
    return tsl::loop<OverlayTest>(argc, argv);
}
