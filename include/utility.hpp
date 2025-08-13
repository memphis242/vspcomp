#pragma once

#include <string>
#include <vector>

namespace Utility
{
   bool        str_contains( const std::string& str, const std::string& substr );
   std::string table_row( size_t cellwidth, char sep, const std::vector<std::string>& contents )
}
