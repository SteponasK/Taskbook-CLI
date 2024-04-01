#include "ignoreLine.h"
#undef max // Delete Visual Studio definition of - max()
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}