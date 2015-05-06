#ifndef FILEHAND_H_
#define FILEHAND_H_

#include <string>


class FileHand
{
public: 
   FileHand(const std::string& dataFileName);
   std::string getData();
private:
   const std::string m_dataFileName;
};

#endif
