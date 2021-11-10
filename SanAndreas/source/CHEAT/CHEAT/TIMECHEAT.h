#ifndef TIMECHEAT_H
#define TIMECHEAT_H
#include <string>

template <typename T>
bool TimeEditHour2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		//util::AddToOffset(1, ADDR_HOUR, 0x1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		//util::SubFromOffset(1, ADDR_HOUR, 0x1);
		return true;		
    }

    return false;
  });
  return true;
}

template <typename T>
bool TimeEditMin2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		//util::AddToOffset(1, ADDR_MIN, 0x1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		//util::SubFromOffset(1, ADDR_MIN, 0x1);
		return true;		
    }

    return false;
  });
  return true;
}

template <typename T>
bool TimeFreeze2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		//dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_TIMEFREEZE1, &PlaceHolder, sizeof(4));
		//dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_TIMEFREEZE2, &PlaceHolder, sizeof(4));
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		//dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_TIMEFREEZE1, &PlaceHolder, sizeof(4));
		//dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_TIMEFREEZE2, &PlaceHolder, sizeof(4));
		return true;		
    }

    return false;
  });
  return true;
}

#endif // TIMECHEAT_H
