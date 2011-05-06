/*
 * =====================================================================================
 *
 *       Filename:  ModelChecker.h
 *
 *    Description:  
 *
 *         Author:  Dan Horgan (danhgn), danhgn@googlemail.com
 *
 * =====================================================================================
 */

#ifndef MODELCHECKER_H
#define MODELCHECKER_H

#include <boost/shared_ptr.hpp>
#include "Environment.h"
#include "formula/Formula.h"
#include "Automata.h"

using namespace Formula;

template <class A>
class PredecessorConfigurations {
private:
public:
   bool Contains(const KripkeState *state_1, const KripkeState *state_2, const A *action) const;
};

// Will contain example/counterexample if available
class Result : public Showable {
private:
   Configuration _config_id;
   bool _evaluation;
public:
   Configuration GetID() const { return _config_id; }
   bool GetEvaluation() const { return _evaluation; }
   Result(unsigned int, bool);
   string ToString() const;
};

class CheckResults : public Showable {
private:
   map<unsigned int, Result*> _result_map; // from configuration to value
public:
   CheckResults();
   void AddResult(Result *result );
   string ToString() const;
   const Result &GetResult(unsigned int id) const;
   const map<unsigned int, Result *> &GetResults() const;
};

class ResultsTable : public Showable {
private:
   map<unsigned int, CheckResults *> _entries;
   const Environment &_environment;
   const KripkeStructure &_system;
public:
   ResultsTable(const Environment &env, const KripkeStructure &lts);
   bool HasEntry( Formula::Formula::const_reference formula ) const;
	const CheckResults *GetEntry( Formula::Formula::const_reference formula ) const;
	void SetEntry( Formula::Formula::const_reference formula, CheckResults *check_results );
   string ToString() const;
};

class Environment;

class ModelChecker : public Formula::Visitor {
private:
   Environment &_environment;
   const KripkeStructure &_system;

public:
   ModelChecker(
      Environment &environment,
      const KripkeStructure &transition_system
   );

   // combine _system and automata
   ProductSystem *ConstructProductSystem(
      const PDA &automaton,
      Formula::Formula::const_reference x,
      Formula::Formula::const_reference y
   );

   void Visit(const Formula::False       &formula_false);
   void Visit(const Formula::True        &formula_true);
   void Visit(const Formula::PVar        &release);
   void Visit(const Formula::Negation    &negation);
   void Visit(const Formula::Conjunction &conjunction);
   void Visit(const Formula::Until       &until);
   void Visit(const Formula::Release     &release);

   const CheckResults *Check( Formula::Formula::const_reference formula );
};

#endif
