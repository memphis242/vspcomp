#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <string_view>
#include <vector>

#include "utility.hpp"

class ProjectDataExtractor
{
public:
   ProjectDataExtractor(std::filesystem::path);
   ~ProjectDataExtractor();

   std::string getLineWithTag(const std::string& tag) const;

private:
   std::filesystem::path m_filepath;
   std::ifstream m_file;

   bool new_data;
   std::string m_xml_tag;
   std::string m_line;
};
