#include <cstdio>
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include "stdafx.h"

FileHand::FileHand(const std::string& dataFileName)
: m_dataFileName(dataFileName)
{}

std::string FileHand::getData()
{
   // open the config file
   boost::shared_ptr<FILE> configFile(fopen(m_dataFileName.c_str(), "r"),fclose);
   if (!configFile)
   {
      std::cout << "Could not open " << m_dataFileName << std::endl;
      exit(1);
   }
   // get the size of the file
   fseek(configFile.get(), 0, SEEK_END);
   long fileSize = ftell(configFile.get());
   rewind(configFile.get());
   // read in the configuration from the xml file
   char configBuf[fileSize];
   fread(configBuf, 1, fileSize, configFile.get());
   return std::string(configBuf);
}

