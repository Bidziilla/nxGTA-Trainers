#define TESLA_INIT_IMPL // If you have more than one file using the tesla header, only define this in the main one
#include <tesla.hpp>    // The Tesla Header
#include <dmntcht.h>
#include "CHEAT/DEFINITIONS/constants.h"
#include "CHEAT/DEFINITIONS/noval.h"
#include "CHEAT/DEFINITIONS/addresses.h"
#include "CHEAT/cheatFunctions.h"
#include "CHEAT/CHEAT/PLAYERCHEAT.h"
#include "CHEAT/CHEAT/TIMECHEAT.h"
#include "CHEAT/CHEAT/PHYSICCHEAT.h"
#include "CHEAT/CHEAT/VEHCHEAT.h"
#include "CHEAT/CHEAT/MISCCHEAT.h"

#define GAME_TITLE_ID 0x010065a014024000
static bool initialized=false;

//CHECK
bool bid_match() {
    const unsigned char build_id_size=8;
    const unsigned char expected_build_id[build_id_size]={0x7D, 0x54, 0xA9, 0xE6, 0xB7, 0x11, 0x70, 0xDC};
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
        auto *rootFrame = new tsl::elm::OverlayFrame("Player Cheats", "Ay SIS JEJ");
		auto list = new tsl::elm::List();
		if (initialized&&debugService_isRunning()&&metadata.title_id==GAME_TITLE_ID&&bid_match())
		{
			auto *Add250k = new tsl::elm::ListItem("Add $250,000", "\uE0A0");
			Add250k2(Add250k);
			
			auto *RemoveCash = new tsl::elm::ListItem("Remove All Money", "\uE0A0");
			RemoveCash2(RemoveCash);

			auto *MuscleEdit = new tsl::elm::ListItem("Muscle", "\uE07B / \uE07C");
			MuscleEdit2(MuscleEdit);
			
			auto *FatEdit = new tsl::elm::ListItem("Fat", "\uE07B / \uE07C");
			FatEdit2(FatEdit);
			
			auto *StaminaEdit = new tsl::elm::ListItem("Stamina", "\uE07B / \uE07C");
			StaminaEdit2(StaminaEdit);
			
			auto *RespectEdit = new tsl::elm::ListItem("Respect", "\uE07B / \uE07C");
			RespectEdit2(RespectEdit);
			
			auto *MaxHealthEdit = new tsl::elm::ListItem("Max Health", "\uE07B / \uE07C");
			MaxHealthEdit2(MaxHealthEdit);
			
			list->addItem(new tsl::elm::CategoryHeader("Money Cheats"));
			list->addItem(Add250k);
			list->addItem(RemoveCash);
			list->addItem(new tsl::elm::CategoryHeader("Stats"));
			list->addItem(MuscleEdit);
			list->addItem(FatEdit);
			list->addItem(StaminaEdit);
			list->addItem(RespectEdit);
			list->addItem(MaxHealthEdit);
			
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

class PHYSIC_CHEAT_GUI : public tsl::Gui {
public:
    PHYSIC_CHEAT_GUI() {}

    virtual tsl::elm::Element* createUI() override {
        auto *rootFrame = new tsl::elm::OverlayFrame("Physics Cheats", "Fuck science!");
		auto list = new tsl::elm::List();
		if (initialized&&debugService_isRunning()&&metadata.title_id==GAME_TITLE_ID&&bid_match())
		{
			auto *RunFast = new tsl::elm::ListItem("Super Run", "\uE07B / \uE07C");
			RunFast2(RunFast);
			
			list->addItem(new tsl::elm::CategoryHeader("\uE07B - OFF  /  \uE07C - ON"));
			list->addItem(RunFast);
		}
	
		rootFrame->setContent(list);
        return rootFrame;
    }
};

class VEH_CHEAT_GUI : public tsl::Gui {
public:
    VEH_CHEAT_GUI() {}

    virtual tsl::elm::Element* createUI() override {
        auto *rootFrame = new tsl::elm::OverlayFrame("Vehicle Cheats", "Use Spawn Trashmasher Code");
		auto list = new tsl::elm::List();
		if (initialized&&debugService_isRunning()&&metadata.title_id==GAME_TITLE_ID&&bid_match())
		{
			CarIDPicker = new tsl::elm::ListItem("Busta! Straight busta!");
			CarIDPicker2(CarIDPicker);
			
			auto *SetCarID = new tsl::elm::ListItem("Apply ID", "\uE0A0");
			SetCarID2(SetCarID);
			
			list->addItem(new tsl::elm::CategoryHeader("A, R, A, R, \uE07B, \uE07B, R, L, A, \uE07C"));
			list->addItem(CarIDPicker);
			list->addItem(SetCarID);
			list->addItem(new tsl::elm::CategoryHeader("Help: \n  L/R - Change by 0x10. \n  \uE07B / \uE07C - Change by 0x01. \n\nFor a list of vehicle IDs, visit: \n https://gta.fandom.com/wiki/Vehicle_ID_List \n\nYOU MUST CONVERT FROM \nDECIMAL TO HEX!"));
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

class MISC_CHEAT_GUI : public tsl::Gui {
public:
    MISC_CHEAT_GUI() {}

    virtual tsl::elm::Element* createUI() override {
        auto *rootFrame = new tsl::elm::OverlayFrame("Activate Cheats", "Rockstar approved cheats!");
		auto list = new tsl::elm::List();
		if (initialized&&debugService_isRunning()&&metadata.title_id==GAME_TITLE_ID&&bid_match())
		{
			auto *Handling = new tsl::elm::ListItem("Insane Handling", "\uE07B / \uE07C");
			Handling2(Handling);
			
			auto *FlyingBoat = new tsl::elm::ListItem("Boats Fly", "\uE07B / \uE07C");
			FlyingBoat2(FlyingBoat);
			
			auto *CarsOnWater = new tsl::elm::ListItem("Cars on Water", "\uE07B / \uE07C");
			CarsOnWater2(CarsOnWater);
			
			auto *SportsCars = new tsl::elm::ListItem("Sports Traffic", "\uE07B / \uE07C");
			SportsCars2(SportsCars);
			
			auto *BunnyHop = new tsl::elm::ListItem("Big Bunny Hops", "\uE07B / \uE07C");
			BunnyHop2(BunnyHop);
			
			auto *FlyingCars = new tsl::elm::ListItem("Cars Fly", "\uE07B / \uE07C");
			FlyingCars2(FlyingCars);
			
			auto *DeathCar = new tsl::elm::ListItem("Vehicle of Death", "\uE07B / \uE07C");
			DeathCar2(DeathCar);
			
			auto *SuperJump = new tsl::elm::ListItem("Super Jump", "\uE07B / \uE07C");
			SuperJump2(SuperJump);
			
			auto *InfBreath = new tsl::elm::ListItem("Never Drown", "\uE07B / \uE07C");
			InfBreath2(InfBreath);
			
			auto *WantedLock = new tsl::elm::ListItem("Never Wanted", "\uE07B / \uE07C");
			WantedLock2(WantedLock);
			
			auto *SuperPunch = new tsl::elm::ListItem("Super Punch", "\uE07B / \uE07C");
			SuperPunch2(SuperPunch);
			
			list->addItem(new tsl::elm::CategoryHeader("\uE07B - OFF  /  \uE07C - ON"));
			list->addItem(Handling);
			list->addItem(FlyingBoat);
			list->addItem(CarsOnWater);
			list->addItem(SportsCars);
			list->addItem(BunnyHop);
			list->addItem(FlyingCars);
			list->addItem(DeathCar);
			list->addItem(SuperJump);
			list->addItem(InfBreath);
			list->addItem(WantedLock);
			list->addItem(SuperPunch);
		}
	
		rootFrame->setContent(list);
        return rootFrame;
    }
};

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
        auto rootFrame = new tsl::elm::OverlayFrame("GTA: SA TRAINER", "Made by Bidziilla, Ver: 2.1");
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
			
			auto *PhysicCheats = new tsl::elm::ListItem("Physics Cheats", "\u2600");
			PhysicCheats->setClickListener([](u64 keys) { 
            if (keys & KEY_A) {
                tsl::changeTo<PHYSIC_CHEAT_GUI>();
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
			
			auto *MiscCheats = new tsl::elm::ListItem("Activate Cheats", "\u2600");
			MiscCheats->setClickListener([](u64 keys) { 
            if (keys & KEY_A) {
                tsl::changeTo<MISC_CHEAT_GUI>();
                return true;
            }

            return false;
			});
			
			auto *LEGALINFORMATION = new tsl::elm::ListItem("Legal Information", "\u2600");
			LEGALINFORMATION->setClickListener([](u64 keys) { 
            if (keys & KEY_A) {
                tsl::changeTo<LEGALGUI>();
                return true;
            }

            return false;
			});
			
			list->addItem(new tsl::elm::CategoryHeader("Cheats"));
			list->addItem(PlayerCheats);
			list->addItem(TimeCheats);
			list->addItem(PhysicCheats);
			list->addItem(VehicleCheats);
			list->addItem(MiscCheats);
			list->addItem(new tsl::elm::CategoryHeader("Legal"));
			list->addItem(LEGALINFORMATION);
		}
		else
        {
			list->addItem(new tsl::elm::CategoryHeader("All you had to do was load the right game, CJ! \nERROR: TitleID Mismatch"));
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
