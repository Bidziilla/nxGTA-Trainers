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
		util::Write32(0, ADDR_CJRUNSPEED, 0x1E2E1002);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::Write32(0, ADDR_CJRUNSPEED, 0x1E241002);
		return true;		
    }

    return false;
  });
  return true;
}

#endif // PHYSICCHEAT_H
