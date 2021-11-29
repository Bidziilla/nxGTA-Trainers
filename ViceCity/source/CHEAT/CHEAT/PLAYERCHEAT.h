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
	else if (keys & KEY_X) 
	{
		util::Write32(0, ADDR_MONEY, 0x3B9AC9FF);
		util::Write32(0, ADDR_MONEY + 4, 0x3B9AC9FF);
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
		util::Write32(0, ADDR_MONEY, Zero);
		util::Write32(0, ADDR_MONEY + 4, Zero);
		return true;
    }

    return false;
  });
  return true;
}

#endif // PLAYERCHEAT_H
