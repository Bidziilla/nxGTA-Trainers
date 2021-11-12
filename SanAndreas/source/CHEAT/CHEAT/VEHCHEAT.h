#ifndef VEHCHEAT_H
#define VEHCHEAT_H
#include <string>

template <typename T>
bool SpawnCar002(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &TrashMaster, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

template <typename T>
bool SpawnCar012(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &Stretch, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

template <typename T>
bool SpawnCar022(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &FBITruck, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

template <typename T>
bool SpawnCar032(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &CombineHarvester, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

template <typename T>
bool SpawnCar042(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &Andromada, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

template <typename T>
bool SpawnCar052(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &RCCAM, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

#endif // VEHCHEAT_H
