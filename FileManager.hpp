#ifndef FILEMANAGER_Guard
#define FILEMANAGER_Guard

#include <string>

class FileManager
{
public:
   FileManager(const std::string& fileName);
   FileManager(const std::string& fileName, const std::string& extent);
private:
   void handle_file_extent();
   std::string m_fileName;
   std::string m_extent;
};

#endif
