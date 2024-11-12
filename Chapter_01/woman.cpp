
#include "woman.hpp"

#include <algorithm>
#include <random>

#include "man.hpp"

bool Woman::accept_proposal(Man *man) {
  Man_vector_iterator iterator = std::ranges::find(m_men, man);

  if (iterator == m_men.end())
    throw std::invalid_argument{"man not in the preference list"};

  int man_index = static_cast<int>(std::distance(m_men.begin(), iterator));

  if (!is_engaged()){
    m_engaged_with = man_index;
    return true;
  }

  bool is_preferable_than_engaged = man_index < m_engaged_with;
  if (!is_preferable_than_engaged)
    return false;

  m_engaged_with = man_index;
  return true;
}

void Woman::prepare_preference_list(const std::vector<Man *> &men) {
  m_men = men;

  std::random_device device;
  std::mt19937 engine(device());

  std::shuffle(m_men.begin(), m_men.end(), engine);
}