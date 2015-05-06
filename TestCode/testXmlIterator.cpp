// based on code written by Stephen Dicks
#include "testXmlIterator.hpp"

#include "XmlIterator.hpp"
#include "TagNotFoundException.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestXmlIterator);

void TestXmlIterator::setUp()
{
   m_pIter = new XmlIterator("<fred><jim>1</jim><bill>hello</bill><bert>0.2</bert></fred>");
}

void TestXmlIterator::tearDown()
{
   delete m_pIter;
}

void TestXmlIterator::goodTest()
{
   std::string inside = m_pIter->extractXml("fred");
   CPPUNIT_ASSERT_EQUAL(std::string("<jim>1</jim><bill>hello</bill><bert>0.2</bert>"), inside);
   XmlIterator insideIter(inside);
   CPPUNIT_ASSERT_EQUAL(1L, insideIter.extractLong("jim"));
   CPPUNIT_ASSERT_EQUAL(std::string("hello"), insideIter.extractString("bill"));
   CPPUNIT_ASSERT_EQUAL(0.2, insideIter.extractDouble("bert"));
}

void TestXmlIterator::badTest()
{
   std::string inside = m_pIter->extractXml("fred");
   XmlIterator insideIter(inside);
   CPPUNIT_ASSERT_THROW(insideIter.extractString("wibble"), TagNotFoundException);
   CPPUNIT_ASSERT_EQUAL(1L, insideIter.extractLong("jim"));
   CPPUNIT_ASSERT_THROW(insideIter.extractString("wibble"), TagNotFoundException);
}

void TestXmlIterator::spaceTest()
{
   XmlIterator fred("<jim>  <insidejim>stuff</insidejim></jim>");
   const std::string inside = fred.extractXml("jim");
   XmlIterator jim(inside);
   CPPUNIT_ASSERT_EQUAL(std::string("stuff"), jim.extractString("insidejim"));
}
