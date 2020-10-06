/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2019, The Souffle Developers. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file Level.h
 *
 * Get level of an expression/condition. The level of a condition/expression
 * determines the outer-most scope in a loop-next of a query,  for which the
 * expression/condition is still safe to be computed.
 *
 ***********************************************************************/

#pragma once

#include "ram/Node.h"
#include "ram/TranslationUnit.h"
#include "ram/analysis/Analysis.h"

namespace souffle::ram::analysis {

/**
 * @class RelationAnalysis
 * @brief A RAM Analysis for finding relations by name
 *
 */
class RelationAnalysis : public Analysis {
public:
    RelationAnalysis(const char* id) : Analysis(id) {}

    static constexpr const char* name = "relation-analysis";

    void run(const TranslationUnit&) override;

    const ram::Relation& lookup(const std::string& name) const;

protected:
    std::map<std::string, const ram::Relation*> relationMap;
};

}  // namespace souffle::ram::analysis
