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
#include "CHEAT/CHEAT/MISCCHEAT.h"

#define GAME_TITLE_ID 0x010065a014024000
static bool initialized=false;

//CHECK
bool bid_match() {
    const unsigned char build_id_size=8;
    const unsigned char expected_build_id[build_id_size]={0x44, 0xCC, 0xC8, 0xF4, 0x65, 0x13, 0x09, 0xD3};
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
			
			list->addItem(new tsl::elm::CategoryHeader("\uE07B - Decrease / \uE07C - Increase"));
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
			
			list->addItem(new tsl::elm::CategoryHeader("\uE07B - OFF / \uE07C - ON"));
			list->addItem(RunFast);
		}
	
		rootFrame->setContent(list);
        return rootFrame;
    }
};

class GAME_CHEAT_GUI : public tsl::Gui {
public:
    GAME_CHEAT_GUI() {}

    virtual tsl::elm::Element* createUI() override {
        auto *rootFrame = new tsl::elm::OverlayFrame("Activate Cheats", "Rockstar approved cheats!");
		auto list = new tsl::elm::List();
		if (initialized&&debugService_isRunning()&&metadata.title_id==GAME_TITLE_ID&&bid_match())
		{
			auto *FlyingBoat = new tsl::elm::ListItem("Boats Fly", "\uE07B / \uE07C");
			FlyingBoat2(FlyingBoat);
			
			auto *CarsOnWater = new tsl::elm::ListItem("Cars on Water", "\uE07B / \uE07C");
			CarsOnWater2(CarsOnWater);
			
			auto *SportsCars = new tsl::elm::ListItem("Sports Traffic", "\uE07B / \uE07C");
			SportsCars2(SportsCars);
			
			auto *FlyingCars = new tsl::elm::ListItem("Cars Fly", "\uE07B / \uE07C");
			FlyingCars2(FlyingCars);
			
			auto *BunnyHop = new tsl::elm::ListItem("Big Bunny Hops", "\uE07B / \uE07C");
			BunnyHop2(BunnyHop);
			
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
			list->addItem(FlyingBoat);
			list->addItem(CarsOnWater);
			list->addItem(SportsCars);
			list->addItem(FlyingCars);
			list->addItem(BunnyHop);
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
			
			auto *ActivateCheatz = new tsl::elm::ListItem("Activate Cheats", "\u2600");
			ActivateCheatz->setClickListener([](u64 keys) { 
            if (keys & KEY_A) {
                tsl::changeTo<GAME_CHEAT_GUI>();
                return true;
            }

            return false;
			});
			
			list->addItem(new tsl::elm::CategoryHeader("Cheats"));
			list->addItem(PlayerCheats);
			list->addItem(TimeCheats);
			//list->addItem(PhysicCheats);
			list->addItem(ActivateCheatz);
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
