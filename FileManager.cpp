#include <iostream>
#include <fstream>
#include "FileManager.hpp"

FileManager::FileManager(const std::string& fileName)
: m_fileName(fileName)
, m_extent("")
{
   std::ifstream infile(m_fileName.c_str());
   if(infile)
   {
   }
   else
   {
      std::cerr << "Error opening " << fileName << std::endl;
   }
}

FileManager::FileManager(const std::string& fileName, const std::string& extent)
: m_fileName(fileName)
, m_extent(extent)
{
   std::ifstream infile(m_fileName.c_str());
   if(infile)
   {
   }
   else
   {
      std::cerr << "Error opening " << fileName << std::endl;
   }
}

void FileManager::handle_file_extent()
{
   std::string::size_type idx = m_fileName.find('.');   
   if(idx == std::string::npos)
   {
      m_fileName += m_extent;
   }
}
