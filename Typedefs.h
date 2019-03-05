#pragma once
#include <stdint.h>
#include <list>
#include "GameObject.h"


typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int16_t i16;

typedef std::list<GameObject*> GOContainer;
typedef std::list<Projectile*> ProjContainer;

