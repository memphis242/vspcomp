#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <string_view>
#include <array>

#include "ProjectDataExtractor.hpp"
#include "IncPath.hpp"
#include "utility.hpp"
#include "Targets.hpp"

class VSProjectData
{
public:
   VSProjectData(std::string filepath_str);
   ~VSProjectData();

   IncPath inc_path(Target) const;

   // TODO: More get functions?
   std::string filename(void) const;

private:
   static const std::array<std::string, Targets::Count> IncPathXMLTags;

   std::string m_filename;
   std::filesystem::path m_filepath;
   ProjectDataExtractor m_extractor;
   std::array<IncPath, Targets::Count> m_inc_paths;
};
