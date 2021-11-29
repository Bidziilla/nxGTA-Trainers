#ifndef VEHCHEAT_H
#define VEHCHEAT_H
#include <string>

template <typename T>
bool CarIDPicker2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		util::AddToOffset(1, Addr_CarID, 0x1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::SubFromOffset(1, Addr_CarID, 0x1);
		return true;
	}
	if (keys & KEY_R) 
	{
		util::AddToOffset(1, Addr_CarID, 0x10);
		return true;
	}
	else if (keys & KEY_L) 
	{
		util::SubFromOffset(1, Addr_CarID, 0x10);
		return true;		
    }

    return false;
  });
  return true;
}

template <typename T>
bool SetCarID2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_A) 
	{
		dmntchtReadCheatProcessMemory(metadata.heap_extents.base + Addr_CarID, &ActualCarID, sizeof(2));
		
		util::ConvertToMOV(ADDR_CHEATRHINOID, 0, ActualCarID);
        
		return true;
	}

    return false;
  });
  return true;
}

#endif // VEHCHEAT_H
