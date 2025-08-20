#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>

#include "IncPath.hpp"
#include "utility.hpp"

// Default constructor
IncPath::IncPath() {}

IncPath::IncPath(std::string inc_line, char delim) :
   m_delim(delim), raw_line(inc_line)
{
   // TODO: Input validation

   std::string subpath;
   for ( const char c : inc_line )
   {
      if ( c == delim )
      {
         m_vec.push_back(subpath);
         m_set.insert(subpath);
         subpath = "";
      }
      else
         subpath.push_back(c);
   }

   if ( !subpath.empty() )
   {
      m_vec.push_back(subpath);
      m_set.insert(subpath);
   }
}

std::string IncPath::line(void)
{
   return raw_line;
}

std::vector<std::string> vector(void)
{
   return m_vec;
}

std::set<std::string> set(void)
{
   return m_set;
}

size_t len(void)
{
   return std::accumulate(
            m_vec.begin(),
            m_vec.end(),
            0, // initial accumulation value
            [](size_t sum, const std::string& next_str){
               return sum + next_str.length();
            };
}

size_t npaths(void)
{
   return m_vec.size();
}
