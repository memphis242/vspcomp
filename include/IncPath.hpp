#pragma once

#include <set>
#include <vector>
#include <string>

class IncPath
{
public:
   IncPath();
   IncPath(std::string, char delim = ';');
   ~IncPath();

   std::string line(void) const;
   std::vector<std::string> vector(void) const;
   std::set<std::string> set(void) const;
   size_t len(void) const;
   size_t npaths(void) const;

   // TODO: Set delim?
   // TODO: Set new line?

private:
   char m_delim;
   std::string raw_line;
   std::vector<std::string> m_vec;
   std::set<std::string> m_set;
};
