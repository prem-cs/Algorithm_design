#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>
#include <ranges>
#include <fstream>

#include "man.hpp"
#include "woman.hpp"


// template <typename Proposers, typename Acceptors>
// auto generate_stable_matching(const Proposers& proposers, const Acceptors&
// acceptors)
// {
//     for (Proposer& proposer :  proposers)
//         proposer.prepare_preference_list(acceptors);

//     proposers.prepare_preference_list(acceptors)
// }

void generate_stable_matching(const std::vector<Man *> &men,
                              const std::vector<Woman *> &women) {
  for (auto &&man : men)
    man->prepare_preference_list(women);

  for (auto &&woman : women)
    woman->prepare_preference_list(men);

  auto man_selector = [](Man *man) { return !man->is_engaged(); };
  while (std::ranges::any_of(men, man_selector)) {
    for (auto &&man : men | std::views::filter(man_selector)) {
        man->propose();
    }
  }
}
int main(int argc, char const *argv[]) {
  std::vector<Man *> men;
  std::vector<Woman *> women;

  std::ifstream data {"data.dat"};
  std::string name;
  while(data) {
      data >> name;
      men.push_back(new Man(name));

      data >> name;
      women.push_back(new Woman(name));
  }

  generate_stable_matching(men, women);

  for (auto &&man : men)
  {
    std::cout << man->name() << "    is engaged with    " << man->engaged_with()->name() << "\n";
  }
    


  return 0;
}
