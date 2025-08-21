#include <filesystem>
#include <fstream>
#include <string>
#include <string_view>

#include "ProjectDataExtractor.hpp"
#include "utility.hpp"

ProjectDataExtractor::ProjectDataExtractor(std::filesystem::path filepath) :
   m_filepath(filepath)
{
   if ( std::filesystem::exists(filepath) )
   {
      m_file = std::ifstream(filepath);
      if ( !m_file.is_open() )
      {
         // FIXME: Handle error of failing to open file.
      }
   }
   else
   {
      // FIXME: Handle error of invalid file.
   }
}

std::string ProjectDataExtractor::getLineWithTag(const std::string& tag)
{
   // TODO: Assertions

   if ( xml_tag == m_xml_tag && !m_line.empty() )
      return m_line

   new_data = true;
   m_file.seekg(0); // Rewind file

   constexpr size_t MaxLines = 100'000;
   bool lfound = true;
   size_t nlines = 1;
   do {
      (void)std::getline(m_file, m_line);
      lfound = Utility::str_contains(m_line, xml_tag);
   } while ( !lfound && (++nlines < MaxLines) );

   // Trim out the XML tag portions
   m_lines.erase(0, m_line.find('>') + 1);
   m_lines.erase(m_line.rfind('<'));

   return m_line;
}
