#ifndef PHYSICCHEAT_H
#define PHYSICCHEAT_H
#include <string>

template <typename T>
bool RunFast2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CJRUNSPEED, &CJRunFast, sizeof(4));
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		dmntchtWriteCheatProcessMemory(metadata.main_nso_extents.base + ADDR_CJRUNSPEED, &DefaultFloat2, sizeof(4));
		return true;		
    }

    return false;
  });
  return true;
}

#endif // PHYSICCHEAT_H
