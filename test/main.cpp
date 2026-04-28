#include "NumberSet/complex.h"
#include "NumberSet/natural.h"
#include "NumberSet/quotient.h"
#include "NumberSet/real.h"
#include "NumberSet/zahlen.h"

#include <cassert>
#include <iostream>

using N = math::Natural<unsigned int>;
using Z = math::Zahlen<int>;
using Q = math::Quotient<int>;
using R = math::Real<float>;
using C = math::Complex<int>;

using NL = math::Natural<unsigned long int>;
using ZL = math::Zahlen<long int>;
using QL = math::Quotient<long int>;
using RL = math::Real<long double>;
using CL = math::Complex<long int>;

using namespace math;
int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {

  int a = 1;
  unsigned int b = 2;
  long long int c = 3;
  unsigned long long int d = 4;
  float e = 5.1f;
  double f = 6.2f;
  N na = a;
  N nb(b);
  N nc = na + nb;
  N ne(na *= c);
  assert(ne == nc);
  NL nd = d;
  nd += na;
  std::cout << ne << '\n';

  Z za = a;
  Z zb(b);
  Z zc = za + zb;
  zb -= zc;
  Z ze(za *= c);
  assert(ze == zc);
  ZL zd = d;
  zd -= za;
  std::cout << ze << '\n';

  Q qa = a;
  Q qb(b, c);
  Q qc = qa + qb;
  qb -= qc;
  Q qe(qa *= c);
  qa /= qc;
  assert(qe != qc);
  QL qd = d;
  qd -= qa;
  std::cout << qc << '\n';

  R ra = a;
  R rb(f);
  R rc = ra + rb;
  rb -= rc;
  R re(ra *= c);
  ra /= rc;
  assert(re != rc);
  RL rd = d;
  rd -= ra;
  std::cout << re << '\n';

  C ca = a;
  C cb(b);
  C cc = ca + cb;
  cb -= cc;
  C ce(ca *= c);
  ca /= cc;
  assert(ce == cc);
  CL cd = d;
  cd -= ca;
  std::cout << ce << '\n';
  return 0;
}
