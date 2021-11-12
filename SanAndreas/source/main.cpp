#define TESLA_INIT_IMPL // If you have more than one file using the tesla header, only define this in the main one
#include <tesla.hpp>    // The Tesla Header
#include <dmntcht.h>
#include "CHEAT/DEFINITIONS/constants.h"
#include "CHEAT/DEFINITIONS/noval.h"
#include "CHEAT/DEFINITIONS/addresses.h"
#include "CHEAT/DEFINITIONS/VEHICLES.h"
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
    const unsigned char expected_build_id[build_id_size]={0x70, 0x61, 0x70, 0x6e, 0xf4, 0xd9, 0x7b, 0x84};
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
			auto *Add250k = new tsl::elm::ListItem("Add $25,000", "\uE0A0");
			Add250k2(Add250k);
			
			auto *RemoveCash = new tsl::elm::ListItem("Remove All Money", "\uE0A0");
			RemoveCash2(RemoveCash);
			
			/*auto *MaxHealth = new tsl::elm::ListItem("Max Health", "\uE0A0");
			MaxHealth2(MaxHealth);
			
			auto *MaxArmor = new tsl::elm::ListItem("Max Armor", "\uE0A0");
			MaxArmor2(MaxArmor);
			
			auto *Suicide = new tsl::elm::ListItem("Kill CJ", "\uE0A0");
			Suicide2(Suicide);
			
			auto *MaxAmmo = new tsl::elm::ListItem("Max Ammunition", "\uE0A0");
			MaxAmmo2(MaxAmmo);*/
			
			auto *MuscleEdit = new tsl::elm::ListItem("Muscle", "\uE07B / \uE07C");
			MuscleEdit2(MuscleEdit);
			
			auto *FatEdit = new tsl::elm::ListItem("Fat", "\uE07B / \uE07C");
			FatEdit2(FatEdit);
			
			auto *StaminaEdit = new tsl::elm::ListItem("Stamina", "\uE07B / \uE07C");
			StaminaEdit2(StaminaEdit);
			
			auto *RespectEdit = new tsl::elm::ListItem("Respect", "\uE07B / \uE07C");
			RespectEdit2(RespectEdit);
			
			auto *SexAppealEdit = new tsl::elm::ListItem("Sex Appeal", "\uE07B / \uE07C");
			SexAppealEdit2(SexAppealEdit);
			
			auto *MaxHealthEdit = new tsl::elm::ListItem("Max Health", "\uE07B / \uE07C");
			MaxHealthEdit2(MaxHealthEdit);
			
			list->addItem(new tsl::elm::CategoryHeader("Money Cheats"));
			list->addItem(Add250k);
			list->addItem(RemoveCash);
			//list->addItem(new tsl::elm::CategoryHeader("Health/Armor/Ammo"));
			//list->addItem(MaxHealth);
			//list->addItem(MaxArmor);
			//list->addItem(Suicide);
			//list->addItem(MaxAmmo);
			list->addItem(new tsl::elm::CategoryHeader("Stats"));
			list->addItem(MuscleEdit);
			list->addItem(FatEdit);
			list->addItem(StaminaEdit);
			list->addItem(RespectEdit);
			list->addItem(SexAppealEdit);
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
			auto *SpawnCar00 = new tsl::elm::ListItem("Trash Master", "\uE0A0");
			SpawnCar002(SpawnCar00);
			
			auto *SpawnCar01 = new tsl::elm::ListItem("Stretch", "\uE0A0");
			SpawnCar012(SpawnCar01);
			
			auto *SpawnCar02 = new tsl::elm::ListItem("FBI Truck", "\uE0A0");
			SpawnCar022(SpawnCar02);
			
			auto *SpawnCar03 = new tsl::elm::ListItem("Combine Harvester", "\uE0A0");
			SpawnCar032(SpawnCar03);
			
			auto *SpawnCar04 = new tsl::elm::ListItem("Andromada", "\uE0A0");
			SpawnCar042(SpawnCar04);
			
			auto *SpawnCar05 = new tsl::elm::ListItem("RC CAM", "\uE0A0");
			SpawnCar052(SpawnCar05);
			
			auto *SpawnCar06 = new tsl::elm::ListItem("Rustler", "\uE0A0");
			SpawnCar062(SpawnCar06);
			
			auto *SpawnCar07 = new tsl::elm::ListItem("Beagle", "\uE0A0");
			SpawnCar072(SpawnCar07);
			
			auto *SpawnCar08 = new tsl::elm::ListItem("Nevada", "\uE0A0");
			SpawnCar082(SpawnCar08);
			
			auto *SpawnCar09 = new tsl::elm::ListItem("Cheetah", "\uE0A0");
			SpawnCar092(SpawnCar09);
			
			auto *SpawnCar0A = new tsl::elm::ListItem("Dune", "\uE0A0");
			SpawnCar0A2(SpawnCar0A);
			
			auto *SpawnCar0B = new tsl::elm::ListItem("NRG-500", "\uE0A0");
			SpawnCar0B2(SpawnCar0B);
			
			auto *SpawnCar0C = new tsl::elm::ListItem("Tow Truck", "\uE0A0");
			SpawnCar0C2(SpawnCar0C);
			
			auto *SpawnCar0D = new tsl::elm::ListItem("Maverick", "\uE0A0");
			SpawnCar0D2(SpawnCar0D);
			
			auto *SpawnCar0E = new tsl::elm::ListItem("Jetmax", "\uE0A0");
			SpawnCar0E2(SpawnCar0E);
			
			list->addItem(new tsl::elm::CategoryHeader("A, R, A, R, \uE07B, \uE07B, R, L, A, \uE07C"));
			list->addItem(SpawnCar00);
			list->addItem(SpawnCar01);
			list->addItem(SpawnCar02);
			list->addItem(SpawnCar03);
			list->addItem(SpawnCar04);
			list->addItem(SpawnCar05);
			list->addItem(SpawnCar06);
			list->addItem(SpawnCar07);
			list->addItem(SpawnCar08);
			list->addItem(SpawnCar09);
			list->addItem(SpawnCar0A);
			list->addItem(SpawnCar0B);
			list->addItem(SpawnCar0C);
			list->addItem(SpawnCar0D);
			list->addItem(SpawnCar0E);
			//list->addItem(SpawnCar0F);
			
		}
	
		rootFrame->setContent(list);
        return rootFrame;
    }
};

class MISC_CHEAT_GUI : public tsl::Gui {
public:
    MISC_CHEAT_GUI() {}

    virtual tsl::elm::Element* createUI() override {
        auto *rootFrame = new tsl::elm::OverlayFrame("Misc Cheats", "Some extra stuff...");
		auto list = new tsl::elm::List();
		if (initialized&&debugService_isRunning()&&metadata.title_id==GAME_TITLE_ID&&bid_match())
		{
			auto *FixAudioo = new tsl::elm::ListItem("Increase Audio Volume", "\uE07B / \uE07C");
			FixAudioo2(FixAudioo);
			
			list->addItem(new tsl::elm::CategoryHeader("\uE07B - OFF  /  \uE07C - ON"));
			list->addItem(FixAudioo);
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
			
			auto *MiscCheats = new tsl::elm::ListItem("Misc Cheats", "\u2600");
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
