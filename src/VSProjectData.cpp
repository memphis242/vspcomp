#include <string>
#include <string_view>
#include <vector>
#include <set>
#include <array>

#include "VSProjectData.hpp"
#include "ProjectDataExtractor.hpp"
#include "Targets.hpp"

VSProjectData::VSProjectData(std::string filepath_str)
   : m_filename(filepath_str), m_filepath(filepath_str), exctarctor(m_filepath)
{
   for ( std::size_t i = 0; i < Targets::Count; ++i )
   {
      m_inc_paths[i] = IncPath(m_exctractor.line(IncPathXMLTags[i]));
   }
}

IncPath VSProjectData::inc_path(Target target) const
{
   return m_inc_paths[ static_cast<std::size_t>(target) ];
}

// TODO: Get functions
std::string VSProjectData::filename(void) const
{
   return m_filename;
}

#define VS_PROJ_TARGET(enumerator, xml_tag) xml_tag,
static const std::array<std::string, Targets::Count> IncPathXMLTags =
{
#  include "targets.h"
}
#undef VS_PROJ_TARGET
