#pragma once

#include <string>
#include "StatelessFeatureFunction.h"

namespace Moses
{

class SyntaxRHS : public StatelessFeatureFunction
{
public:
  SyntaxRHS(const std::string &line);

  bool IsUseable(const FactorMask &mask) const {
    return true;
  }

  void EvaluateInIsolation(const Phrase &source
                , const TargetPhrase &targetPhrase
                , ScoreComponentCollection &scoreBreakdown
                , ScoreComponentCollection &estimatedFutureScore) const;
  void Evaluate(const InputType &input
                , const InputPath &inputPath
                , const TargetPhrase &targetPhrase
                , const StackVec *stackVec
                , ScoreComponentCollection &scoreBreakdown
                , ScoreComponentCollection *estimatedFutureScore = NULL) const;
  void Evaluate(const Hypothesis& hypo,
                ScoreComponentCollection* accumulator) const;
  void EvaluateChart(const ChartHypothesis &hypo,
                     ScoreComponentCollection* accumulator) const;

};

}

