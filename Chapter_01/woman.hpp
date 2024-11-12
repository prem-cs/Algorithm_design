#ifndef WOMAN_HPP_INCLUDED
#define WOMAN_HPP_INCLUDED

#include <string>
#include <vector>
#include <stdexcept>

#include "../macros.h"

class Man;

class Woman {
public:
    Woman(const std::string& name) : m_name(name), m_engaged_with(-1)
    {
        if (name.empty())
            throw std::invalid_argument(nameof(name));
    }

    bool accept_proposal(Man* man);
    void prepare_preference_list(const std::vector<Man*>& men);

    bool is_engaged() const
    {
        return m_engaged_with >= 0;
    }

    const std::string& name() const
    {
        return m_name;
    }
    
private:
    std::string m_name;
    std::vector<Man*> m_men;
    int m_engaged_with;
};

typedef std::vector<Woman*>::iterator Woman_vector_iterator;

#endif