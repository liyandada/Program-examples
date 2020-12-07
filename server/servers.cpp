#include "servers.h"


servers::servers(int value)
{
    m_value = value;
}

int servers::maxValue()
{
    return 100;
}
int servers::minValue()
{
    return 0;
}
int servers::value()
{
    return m_value;
}
