#include "man.hpp"

#include <random>
#include <algorithm>


#include "woman.hpp"

bool Man::propose()
{
    int preferred_next_woman = next_preferable_woman++;
    Woman* woman = m_women.at(preferred_next_woman);

    if (woman->accept_proposal(this)) {
         m_engaged_with = preferred_next_woman;
         return true;
    }

    return false;
}

void Man::break_engagement(Woman* woman)
{
    if (m_women[m_engaged_with] == woman)
        m_engaged_with = -1;
}

void Man::prepare_preference_list(const std::vector<Woman*>& women)
{
    m_women = women;

    std::random_device device;
    std::mt19937 engine(device());

    std::shuffle(m_women.begin(), m_women.end(), engine);
}