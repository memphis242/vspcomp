#pragma once

#include <array>

#define VS_PROJ_TARGET(enumerator, xml_tag) enumerator,
enum class Target
{
#  include "targets.h"
   NUM_OF_TARGETS
};
#undef VS_PROJ_TARGET

namespace Targets
{
   constexpr static std::size_t Count = static_cast<std::size_t>(Target::NUM_OF_TARGETS);

#  define VS_PROJ_TARGET(enumerator, xml_tag) Target::enumerator,
   inline std::array<Target, count> List =
   {
#     include "targets.h"
   };
#  undef VS_PROJ_TARGET

#  define VS_PROJ_TARGET(enumerator, xml_tag) #enumerator,
   inline std::array<Target, count> ToStrLookup =
   {
#     include "targets.h"
   };
#  undef VS_PROJ_TARGET
};
