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
		//util::AddToOffset(1, ADDR_CJMONEY, 0x3D090);
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
		//dmntchtWriteCheatProcessMemory(metadata.heap_extents.base + ADDR_CJMONEY, &Zero, sizeof(4));
		return true;
    }

    return false;
  });
  return true;
}

template <typename T>
bool MaxHealth2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		//dmntchtWriteCheatProcessMemory(metadata.heap_extents.base + ADDR_CJHEALTH, &PlaceHolder, sizeof(4));
		return true;
    }

    return false;
  });
  return true;
}

template <typename T>
bool MaxArmor2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		//dmntchtWriteCheatProcessMemory(metadata.heap_extents.base + ADDR_CJARMOR, &PlaceHolder, sizeof(4));
		return true;
    }

    return false;
  });
  return true;
}

template <typename T>
bool Suicide2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		/*dmntchtWriteCheatProcessMemory(metadata.heap_extents.base + ADDR_CJHEALTH, &PlaceHolder, sizeof(4));
		dmntchtWriteCheatProcessMemory(metadata.heap_extents.base + ADDR_CJARMOR, &PlaceHolder, sizeof(4));*/
		return true;
    }

    return false;
  });
  return true;
}

template <typename T>
bool MaxAmmo2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		//dmntchtWriteCheatProcessMemory(metadata.heap_extents.base + ADDR_PLACEHOLDER, &PlaceHolder, sizeof(4));
		return true;
    }

    return false;
  });
  return true;
}

#endif // PLAYERCHEAT_H
