// based on code written by Stephen Dicks
#ifndef XMLITERATOR_H_
#define XMLITERATOR_H_

#include <string>

class XmlIterator
{
public:
   explicit XmlIterator(const std::string& xmlData);
   std::string extractString(const std::string& elementName);
   long extractLong(const std::string& elementName);
   double extractDouble(const std::string& elementName);
   std::string extractXml(const std::string& elementName);
private:
   std::string m_data;
   std::string::size_type m_pos;
};

#endif
