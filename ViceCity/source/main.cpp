#define TESLA_INIT_IMPL // If you have more than one file using the tesla header, only define this in the main one
#include <tesla.hpp>    // The Tesla Header
#include <dmntcht.h>
#include "CHEAT/DEFINITIONS/constants.h"
#include "CHEAT/DEFINITIONS/noval.h"
#include "CHEAT/DEFINITIONS/addresses.h"
#include "CHEAT/cheatFunctions.h"
#include "CHEAT/CHEAT/PLAYERCHEAT.h"
#include "CHEAT/CHEAT/TIMECHEAT.h"
#include "CHEAT/CHEAT/VEHCHEAT.h"
#include "CHEAT/CHEAT/MISCCHEAT.h"

#define GAME_TITLE_ID 0x0100182014022000
static bool initialized=false;
FanController g_ICon;

//CHECK
bool bid_match() {
    const unsigned char build_id_size=8;
    const unsigned char expected_build_id[build_id_size]={0xA6, 0x0E, 0x8C, 0xA8, 0x6C, 0x6F, 0xD7, 0x04}; //AnthonyUDT got this for me, thanks!!
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

class PLAYER_CHEAT_GUI : public tsl::Gui {
public:
    PLAYER_CHEAT_GUI() {}

    virtual tsl::elm::Element* createUI() override {
        auto *rootFrame = new tsl::elm::OverlayFrame("Player Cheats", "I don't have the money, Sonny.");
		auto list = new tsl::elm::List();
		if (initialized&&debugService_isRunning()&&metadata.title_id==GAME_TITLE_ID&&bid_match())
		{
			auto *Add250k = new tsl::elm::ListItem("Add $250,000", "\uE0A0");
			Add250k2(Add250k);
			
			auto *RemoveCash = new tsl::elm::ListItem("Remove All Money", "\uE0A0");
			RemoveCash2(RemoveCash);
			
			list->addItem(new tsl::elm::CategoryHeader("Money Cheats"));
			list->addItem(Add250k);
			list->addItem(RemoveCash);
		}
	
		rootFrame->setContent(list);
        return rootFrame;
    }
};

class TIME_CHEAT_GUI : public tsl::Gui {
public:
    TIME_CHEAT_GUI() {}

    virtual tsl::elm::Element* createUI() override {
        auto *rootFrame = new tsl::elm::OverlayFrame("Time Cheats", "Back to the future!");
		auto list = new tsl::elm::List();
		if (initialized&&debugService_isRunning()&&metadata.title_id==GAME_TITLE_ID&&bid_match())
		{
			auto *TimeEditHour = new tsl::elm::ListItem("Hour", "\uE07B / \uE07C");
			TimeEditHour2(TimeEditHour);
			
			auto *TimeEditMin = new tsl::elm::ListItem("Minute", "\uE07B / \uE07C");
			TimeEditMin2(TimeEditMin);
			
			list->addItem(new tsl::elm::CategoryHeader("\uE07B - Decrement  /  \uE07C - Increment"));
			list->addItem(TimeEditHour);
			list->addItem(TimeEditMin);
		}
	
		rootFrame->setContent(list);
        return rootFrame;
    }
};

class VEH_CHEAT_GUI : public tsl::Gui {
public:
    VEH_CHEAT_GUI() {}

    virtual tsl::elm::Element* createUI() override {
        auto *rootFrame = new tsl::elm::OverlayFrame("Vehicle Cheats", "Use Spawn Rhino Code");
		auto list = new tsl::elm::List();
		if (initialized&&debugService_isRunning()&&metadata.title_id==GAME_TITLE_ID&&bid_match())
		{
			CarIDPicker = new tsl::elm::ListItem("Failed to read data!");
			CarIDPicker2(CarIDPicker);
			
			auto *SetCarID = new tsl::elm::ListItem("Apply ID", "\uE0A0");
			SetCarID2(SetCarID);
			
			list->addItem(new tsl::elm::CategoryHeader("\uE0A0, \uE0A0, \uE0A4, \uE0A0, \uE0A0, \uE0A0, \uE0A4, \uE0A6, \uE0A5, \uE0A2, \uE0A0, \uE0A2"));
			list->addItem(CarIDPicker);
			list->addItem(SetCarID);
			list->addItem(new tsl::elm::CategoryHeader("Help: \n  L/R - Change by 0x10. \n  \uE07B / \uE07C - Change by 0x01. \n\nFor a list of vehicle IDs, visit: \n https://gtamods.com/wiki/List_of_vehicles_(VC) \n\nNOTE: ID Range -> 0x82 - 0xEC. \nUse any value in between those two \nnumbers. Anything else will CRASH."));
		}
	
		rootFrame->setContent(list);
        return rootFrame;
    }
	
	virtual void update() override
    {
        if (initialized&&debugService_isRunning()&&metadata.title_id==GAME_TITLE_ID&&bid_match())
        {
			if(!dmntchtReadCheatProcessMemory(metadata.heap_extents.base + Addr_CarID, &CarID_DEC, sizeof(2)))
			{
                char buffer[9];
				sprintf(buffer, "%8X", CarID_DEC);
				std::string HexString = std::string(buffer);
				CarIDPicker->setText("Vehicle ID:                   "+HexString);
			}
        }
    }
};

class GuiTest : public tsl::Gui {
public:
    GuiTest(u8 arg1, u8 arg2, bool arg3) {}

    virtual tsl::elm::Element* createUI() override {
        auto rootFrame = new tsl::elm::OverlayFrame("GTA: VC TRAINER", "Made by Bidziilla, Ver: 1.0");
        auto list = new tsl::elm::List();
        if (initialized&&debugService_isRunning()&&metadata.title_id==GAME_TITLE_ID&&bid_match())
        {
			auto *PlayerCheats = new tsl::elm::ListItem("Player Cheats", "\u2600");
			PlayerCheats->setClickListener([](u64 keys) { 
            if (keys & KEY_A) {
                tsl::changeTo<PLAYER_CHEAT_GUI>();
                return true;
            }

            return false;
			});
			
			auto *TimeCheats = new tsl::elm::ListItem("Time Cheats", "\u2600");
			TimeCheats->setClickListener([](u64 keys) { 
            if (keys & KEY_A) {
                tsl::changeTo<TIME_CHEAT_GUI>();
                return true;
            }

            return false;
			});
			
			auto *VehicleCheats = new tsl::elm::ListItem("Vehicle Cheats", "\u2600");
			VehicleCheats->setClickListener([](u64 keys) { 
            if (keys & KEY_A) {
                tsl::changeTo<VEH_CHEAT_GUI>();
                return true;
            }

            return false;
			});
			
			list->addItem(new tsl::elm::CategoryHeader("Cheats"));
			list->addItem(PlayerCheats);
			list->addItem(TimeCheats);
			//list->addItem(EnableCheats);
			list->addItem(VehicleCheats);
		}
		else
        {
			list->addItem(new tsl::elm::CategoryHeader("This doesn't look much like GTA: Vice City...  \nERROR: TitleID Mismatch"));
        }

        rootFrame->setContent(list);
        return rootFrame;
    }
	

    virtual bool handleInput(u64 keysDown, u64 keysHeld, touchPosition touchInput, JoystickPosition leftJoyStick, JoystickPosition rightJoyStick) override {
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
			fanInitialize();
			fanGetServiceSession();
			//fanOpenController(&g_ICon, 1);

            initialized=true;
        }
    }
    virtual void exitServices() override
    {
        dmntchtExit();
		fanControllerClose(&g_ICon);
		fanExit();
		
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
