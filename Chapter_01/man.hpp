#ifndef MAN_HPP_INCLUDED
#define MAN_HPP_INCLUDED

#include <string>
#include <vector>
#include <stdexcept>

#include "../macros.h"

class Woman;

class Man {
public:
    Man(const std::string& name) : m_name(name), m_engaged_with(-1), next_preferable_woman(0)
    {
        if (m_name.empty())
            throw std::invalid_argument(nameof(name));
    }

    bool propose();
    void break_engagement(Woman* woman);
    void prepare_preference_list(const std::vector<Woman*>& women);

    bool is_engaged() const
    {
        return m_engaged_with >= 0;
    }

    const std::string& name() const
    {
        return m_name;
    }

    Woman* engaged_with() const
    {
        return m_women[m_engaged_with];
    }
    
private:
    std::string m_name;
    std::vector<Woman*> m_women;
    int m_engaged_with;
    int next_preferable_woman;
};

typedef std::vector<Man*>::iterator Man_vector_iterator;

#endif