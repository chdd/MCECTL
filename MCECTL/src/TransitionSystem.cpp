/*
 * =====================================================================================
 *
 *       Filename:  TransitionSystem.cpp
 *    Description:  Definitions for regular and pushdown transition systems
 *         Author:  Dan Horgan (danhgn), danhgn@googlemail.com
 *
 * =====================================================================================
 */

#include <string>
#include <sstream>
#include <numeric>

#include "TransitionSystem.h"
#include "Automata.h"
#include "Util.h"

// KRIPKE STATE

string KripkeState::ToString() const {
   stringstream s;
   //vector<const string *> propositions(_valuation.GetEntries());
   //s << "[" << _name << ": "
   //   // TODO
   // // << accumulate(propositions.begin(), propositions.end(), string(""), JoinWithComma)
   //  << "]";
   return s.str();
}

// TRANSITION SYSTEM

TransitionSystem::~TransitionSystem() { }

// KRIPKE STRUCTURE

//KripkeStructure::KripkeStructure(const set<KripkeState *> &states, KripkeState *initial_state)
//   : FiniteAutomaton<RegularAction, RegularConfiguration, KripkeState>( states, initial_state ) { }
KripkeStructure::KripkeStructure(const set<KripkeState *> &states, KripkeState *initial_state) { }

string KripkeStructure::ToString() const {
   stringstream s;
   s << "KRIPKE STRUCTURE:" << endl;
   //  << FiniteAutomaton<RegularAction, RegularConfiguration, KripkeState>::ToString();
   return s.str();
}

// PUSH DOWN SYSTEM

PushDownSystem::PushDownSystem(const set<KripkeState *> &states, KripkeState *initial_state) { }
   //: FiniteAutomaton<PushDownAction, PushDownConfiguration, KripkeState>( states, initial_state ) { }

string PushDownSystem::ToString() const {
   stringstream s;
   s << "PUSHDOWN SYSTEM:" << endl;
    // << FiniteAutomaton<PushDownAction, PushDownConfiguration, KripkeState>::ToString();
   return s.str();
}

