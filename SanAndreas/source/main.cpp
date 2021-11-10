#define TESLA_INIT_IMPL // If you have more than one file using the tesla header, only define this in the main one
#include <tesla.hpp>    // The Tesla Header
#include <dmntcht.h>
#include "CHEAT/DEFINITIONS/constants.h"
#include "CHEAT/DEFINITIONS/noval.h"
#include "CHEAT/DEFINITIONS/addresses.h"
#include "CHEAT/cheatFunctions.h"
#include "CHEAT/CHEAT/PLAYERCHEAT.h"
#include "CHEAT/CHEAT/TIMECHEAT.h"

#define GAME_TITLE_ID 0x0000000000000000
static bool initialized=false;

//CHECK
bool bid_match() {
    const unsigned char build_id_size=8;
    const unsigned char expected_build_id[build_id_size]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
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
			
			auto *MaxHealth = new tsl::elm::ListItem("Max Health", "\uE0A0");
			MaxHealth2(MaxHealth);
			
			auto *MaxArmor = new tsl::elm::ListItem("Max Armor", "\uE0A0");
			MaxArmor2(MaxArmor);
			
			auto *Suicide = new tsl::elm::ListItem("Kill CJ", "\uE0A0");
			Suicide2(Suicide);
			
			auto *MaxAmmo = new tsl::elm::ListItem("Max Ammunition", "\uE0A0");
			MaxAmmo2(MaxAmmo);
			
			list->addItem(new tsl::elm::CategoryHeader("Money Cheats"));
			list->addItem(Add250k);
			list->addItem(RemoveCash);
			list->addItem(new tsl::elm::CategoryHeader("Health/Armor/Ammo"));
			list->addItem(MaxHealth);
			list->addItem(MaxArmor);
			list->addItem(Suicide);
			list->addItem(MaxAmmo);
			list->addItem(new tsl::elm::CategoryHeader("Stats"));
			
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
			
			auto *TimeFreeze = new tsl::elm::ListItem("Freeze Daily Timer", "\uE07B / \uE07C");
			TimeFreeze2(TimeFreeze);
			
			list->addItem(new tsl::elm::CategoryHeader("\uE07B - Decrement  /  \uE07C - Increment"));
			list->addItem(TimeEditHour);
			list->addItem(TimeEditMin);
			list->addItem(new tsl::elm::CategoryHeader("\uE07B - OFF  /  \uE07C - ON"));
			list->addItem(TimeFreeze);
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
        auto rootFrame = new tsl::elm::OverlayFrame("GTA: SA TRAINER", "Made by Bidziilla, Ver: 1.0");
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
			
			/*auto *ShaderCheats = new tsl::elm::ListItem("Shader Cheats", "\u2600");
			ShaderCheats->setClickListener([](u64 keys) { 
            if (keys & KEY_A) {
                tsl::changeTo<SHADER_CHEAT_GUI>();
                return true;
            }

            return false;
			});*/
			
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
			/*list->addItem(ShaderCheats);*/
			list->addItem(new tsl::elm::CategoryHeader("Legal"));
			list->addItem(LEGALINFORMATION);
		}
		/*else
        {
			list->addItem(new tsl::elm::CategoryHeader("All you had to do was load the right game, CJ! \nERROR: TitleID Mismatch"));
        }*/

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
