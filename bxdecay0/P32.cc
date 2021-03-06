// Copyright 1995-2016 V.I. Tretyak
// Copyright 2011-2017 F. Mauger
//
// This program is free software: you  can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free  Software Foundation, either  version 3 of the  License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

// Ourselves:
#include <bxdecay0/P32.h>

// Standard library:
#include <sstream>
#include <stdexcept>
#include <cmath>

// This project:
#include <bxdecay0/i_random.h>
#include <bxdecay0/event.h>
#include <bxdecay0/alpha.h>
#include <bxdecay0/gamma.h>
#include <bxdecay0/electron.h>
#include <bxdecay0/positron.h>
#include <bxdecay0/particle.h>
#include <bxdecay0/pair.h>
#include <bxdecay0/nucltransK.h>
#include <bxdecay0/nucltransKL.h>
#include <bxdecay0/nucltransKLM.h>
#include <bxdecay0/nucltransKLM_Pb.h>
#include <bxdecay0/beta.h>
#include <bxdecay0/beta1.h>
#include <bxdecay0/beta2.h>
#include <bxdecay0/beta_1fu.h>
#include <bxdecay0/PbAtShell.h>

namespace bxdecay0 {

  void P32(i_random & prng_,
           event & event_,
           const double tcnuc_,
           double & tdnuc_)
  {
    double t;
    //double tdlev;
    double thnuc;
    // Scheme of P32 beta decay, ToI'1998 and ENSDF'2004.
    // Input : tcnuc_ - time of creation of nucleus (sec)
    // Output: tdnuc_ - time of decay of nucleus (sec)
    // // common/genevent/tevst,npfull,npgeant(100),pmoment(3,100),// ptime(100).
    // VIT, 5.11.2006.
    thnuc=1.2323232e6;
    tdnuc_=tcnuc_-thnuc/std::log(2.)*std::log(prng_());
    // std::experimental corrections to the allowed beta shape from
    // H.Daniel, RMP 40(1968)659 and M.J.Canty et al., NP 85(1966)317
    // cf(e)=(1+c1/w+c2*w+c3*w**2+c4*w**3), w=e/emass+1
    decay0_beta1(prng_, event_, 1.710,16.,0.,0.,t,0.,0.003,0.,0.);
    return;
  }
  // end of P32.f




} // end of namespace bxdecay0

// end of P32.cc
// Local Variables: --
// mode: c++ --
// End: --
