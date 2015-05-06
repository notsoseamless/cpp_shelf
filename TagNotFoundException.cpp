#include "TagNotFoundException.hpp"

TagNotFoundException::TagNotFoundException(const std::string& tagname, const std::string& context)
: std::runtime_error(std::string("Element ")  tagname 