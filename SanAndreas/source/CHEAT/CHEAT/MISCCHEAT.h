#ifndef MISCCHEAT_H
#define MISCCHEAT_H
#include <string>

template <typename T>
bool FlyingBoat2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		util::Write8(0, ADDR_CheatBase, 1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::Write8(0, ADDR_CheatBase, 0);
		return true;		
    }

    return false;
  });
  return true;
}

template <typename T>
bool CarsOnWater2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		util::Write8(0, ADDR_CheatBase + 0x1, 1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::Write8(0, ADDR_CheatBase + 0x1, 0);
		return true;		
    }

    return false;
  });
  return true;
}

template <typename T>
bool SportsCars2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		util::Write8(0, ADDR_CheatBase + 0xD, 1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::Write8(0, ADDR_CheatBase + 0xD, 0);
		return true;		
    }

    return false;
  });
  return true;
}

template <typename T>
bool FlyingCars2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		util::Write8(0, ADDR_CheatBase + 0xE, 1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::Write8(0, ADDR_CheatBase + 0xE, 0);
		return true;		
    }

    return false;
  });
  return true;
}

template <typename T>
bool BunnyHop2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		util::Write8(0, ADDR_CheatBase + 0xF, 1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::Write8(0, ADDR_CheatBase + 0xF, 0);
		return true;		
    }

    return false;
  });
  return true;
}

template <typename T>
bool DeathCar2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		util::Write8(0, ADDR_CheatBase + 0x12, 1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::Write8(0, ADDR_CheatBase + 0x12, 0);
		return true;		
    }

    return false;
  });
  return true;
}

template <typename T>
bool SuperJump2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		util::Write8(0, ADDR_CheatBase + 0x1A, 1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::Write8(0, ADDR_CheatBase + 0x1A, 0);
		return true;		
    }

    return false;
  });
  return true;
}

template <typename T>
bool InfBreath2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		util::Write8(0, ADDR_CheatBase + 0x1C, 1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::Write8(0, ADDR_CheatBase + 0x1C, 0);
		return true;		
    }

    return false;
  });
  return true;
}

template <typename T>
bool WantedLock2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		util::Write8(0, ADDR_CheatBase + 0x1F, 1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::Write8(0, ADDR_CheatBase + 0x1F, 0);
		return true;		
    }

    return false;
  });
  return true;
}

template <typename T>
bool SuperPunch2(T *entry) 
{
  entry->setClickListener([](u64 keys) 
  { 
    if (keys & KEY_DRIGHT) 
	{
		util::Write8(0, ADDR_CheatBase + 0x21, 1);
		return true;
	}
	else if (keys & KEY_DLEFT) 
	{
		util::Write8(0, ADDR_CheatBase + 0x21, 0);
		return true;		
    }

    return false;
  });
  return true;
}

#endif // MISCCHEAT_H
