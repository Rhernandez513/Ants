#include "..\\Headers\\RandomHelper.h"
#include <random>
#include <chrono>

namespace {
  // from http://www.cplusplus.com/reference/random/linear_congruential_engine/max/
  unsigned seed =
    static_cast<unsigned>(
      std::chrono::system_clock::now().time_since_epoch().count()
      );

  // minstd_rand0 is a standard linear_congruential_engine
  std::minstd_rand0 generator (seed); 
}
// Returns a random number between 0 and (2^32)
int Ants::RandomHelper::GetRand() {
  return generator();
}