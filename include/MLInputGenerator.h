// MLInputGenerator.h
#ifndef mlinputgenerator_h
#define mlinputgenerator_h 1

#include "lcfiplus.h"
#include "TTree.h"
#include "TFile.h"
#include "TVector3.h"

#include <vector>
#include <variant>
#include <map>
#include <functional>

namespace lcfiplus {

// Type alias for the variant of calculation functions
using CalcInputVariant = std::variant<
  std::function<double(const Event*)>,
  std::function<double(const Jet*)>,
  std::function<double(const Track*)>,
  std::function<double(const Track*, const Jet*)>,
  std::function<double(const Track*, const Vertex*)>,
  std::function<double(const Neutral*)>,
  std::function<double(const Neutral*, const Jet*)>,
  std::function<double(const Neutral*, const Vertex*)>
>;

// Type alias for the map of calculation functions
using CalcInputMap = std::map<std::string, CalcInputVariant>;

// Static class for ML input generation
class MLInputGenerator {
public:
  // Initialize the calculation function map
  static void init();

  // Get const reference to the calculation input map
  static const CalcInputMap& getCalcInput() { return _calcInput; }

  // FCC functions
  static float calc_dxy(float, float, float, TVector3, TVector3, int);
  static float calc_dz(float, float, float, TVector3, TVector3, int);
  static float calc_sip2d(float, float, float, float);
  static float calc_sip3d(float, float, float, TVector3);
  static float calc_jetDist(float, float, float, TVector3, TVector3);
  static void calc_thetaphi(TVector3, TVector3, float&, float&);

private:
  // Private static members
  static CalcInputMap _calcInput;
  static bool _initialized;

  // Delete constructor to prevent instantiation
  MLInputGenerator() = delete;
};

}

#endif
