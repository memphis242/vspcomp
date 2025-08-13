#include <string>
#include <vector>

#include "utility.hpp"

namespace Utility
{
   bool str_contains( const std::string& str, const std::string& substr )
   {
      return str.find(substr) != std::string::npos;
   }

   std::string table_row( size_t cellwidth, char sep, const std::vector<std::string>& contents )
   {
      std::string rowstr;

      rowstr += sep;
      for ( auto& str : contents )
      {
         size_t len = str.length();
         if ( len < cellwidth )
         {
            // Append full contents plus any necessary padding to center-align
            size_t padding = (cellwidth - len) / 2;
            size_t compensate = (cell_width - len) % 2;
            rowstr.append(padding, ' ');
            rowstr += str;
            rowstr.append(padding + compensate, ' ');
         }
         else
         {
            // Can't append full contents
            rowstr += str.substr(0, cellwidth+1);
         }

         rowstr += sep;
      }
      rowstr += '\n';

      return rowstr; // NRVO FTW
   }
}
