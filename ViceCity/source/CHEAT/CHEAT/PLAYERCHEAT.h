#ifndef PLAYERCHEAT_H
#define PLAYERCHEAT_H
#include <string>

template <typename T>
bool Add250k2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		util::AddToOffset(0, ADDR_MONEY, 0x3D090);
		return true;
    }

    return false;
  });
  return true;
}

template <typename T>
bool RemoveCash2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_MONEY, &Zero, sizeof(4));
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_MONEY + 0x04, &Zero, sizeof(4));
		return true;
    }

    return false;
  });
  return true;
}

#endif // PLAYERCHEAT_H
