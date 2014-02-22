/*
 * Rule.h
 *
 *  Created on: 20 Feb 2014
 *      Author: hieu
 */
#pragma once
#include <vector>
#include "Phrase.h"

class ConsistentPhrase;
class AlignedSentence;

class RulePhrase : public std::vector<const RuleSymbol*>
{

};

class Rule {
public:
	// original rule with no non-term
	Rule(const ConsistentPhrase &consistentPhrase, const AlignedSentence &alignedSentence);

	// extend a rule, adding 1 new non-term
	Rule(const Rule &copy, const ConsistentPhrase &cp);

	virtual ~Rule();

	bool IsValid() const
	{ return m_isValid; }

	bool CanRecurse() const
	{ return m_canRecurse; }

	const ConsistentPhrase &GetConsistentPhrase() const
	{ return m_consistentPhrase; }

	int GetNextSourcePosForNonTerm() const;

	std::string Debug() const;
	void Output(std::ostream &out) const;

protected:
	const ConsistentPhrase &m_consistentPhrase;
	const AlignedSentence &m_alignedSentence;
	RulePhrase m_source, m_target;

	// in source order
	std::vector<const ConsistentPhrase*> m_nonterms;

	bool m_isValid, m_canRecurse;

	void CreateSource();
};

