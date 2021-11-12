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

template <typename T>
bool SpawnCar062(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &Rustler, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

template <typename T>
bool SpawnCar072(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &Beagle, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

template <typename T>
bool SpawnCar082(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &Nevada, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

template <typename T>
bool SpawnCar092(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &Cheetah, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

template <typename T>
bool SpawnCar0A2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &Dune, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

template <typename T>
bool SpawnCar0B2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &NRG_500, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

template <typename T>
bool SpawnCar0C2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &TowTruck, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

template <typename T>
bool SpawnCar0D2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &Maverick, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

template <typename T>
bool SpawnCar0E2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CHEATTRASHID, &Jetmax, sizeof(4));
		return true;
	}

    return false;
  });
  return true;
}

#endif // VEHCHEAT_H
