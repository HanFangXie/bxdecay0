#ifndef BXDECAY0_TL207_H
#define BXDECAY0_TL207_H

namespace bxdecay0 {

  class i_random;
  class event;

  void Tl207(i_random & prng_,
	     event & event_,
	     const double tcnuc_,
	     double & tdnuc_);

} // end of namespace bxdecay0

#endif // BXDECAY0_TL207_H

// Local Variables: --
// mode: c++ --
// End: --
