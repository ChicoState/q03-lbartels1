#ifndef GUESSER_H
#define GUESSER_H

#include <string>

using std::string;

class Guesser
{
private:
  string m_secret;
  unsigned int m_remaining;
  bool m_locked;
  unsigned int distance(string guess);

  
  public:

  Guesser(string secret);
  bool match(string guess);
  unsigned int remaining();

  // ------ getters to use private functions ------ //
  unsigned int use_distance(string guess);
  string get_m_secret();
};

#endif
