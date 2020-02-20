#ifndef __RESULT_PROCESSOR_H__
#define __RESULT_PROCESSOR_H__

#include "typedefs.h"
#include <experimental/filesystem>
#include "utils.h"
#include "iutils.h"
#include "iresultprocessor.h"
#include "stats.h"

namespace fs = std::experimental::filesystem;

namespace ft {
////////////////////////////////////////////////////////////////////////
/// \copyright Copyright (c) 2019, Wasserman lab
/// \author    Godfrain Jacques Kounkou
/// \brief This file contains the declaration of kmergenerator class
////////////////////////////////////////////////////////////////////////
class ResultProcessor : public IResultProcessor {
public:
    ////////////////////////////////////////////////////////////////////////
    /// \brief ResultProcessor
    ////////////////////////////////////////////////////////////////////////
    ResultProcessor();

    ////////////////////////////////////////////////////////////////////////
    /// \brief ~ResultProcessor
    ////////////////////////////////////////////////////////////////////////
    virtual ~ResultProcessor();

    ////////////////////////////////////////////////////////////////////////
    /// \brief ResultProcessor::getIndexCounts
    /// \param readIDResults
    /// \return
    ////////////////////////////////////////////////////////////////////////
    MapOfCounts getIndexCounts(ReaIDsMap& readIDResults);

    ////////////////////////////////////////////////////////////////////////
    /// \brief ResultProcessor::processIndexPos
    /// \param indexPosResults
    /// \param ignore_multi_hits
    /// \param readLen
    /// \return
    ////////////////////////////////////////////////////////////////////////
    ReaIDsMap processIndexPos(ResultsMap& indexPosResults, uint readLen);

    ////////////////////////////////////////////////////////////////////////
    /// \brief ResultProcessor::processResults
    /// \param indexPosResults
    /// \param indexMapFile
    /// \param extract_matching_reads
    /// \param ignore_multi_hits
    /// \param readLen
    /// \return
    ////////////////////////////////////////////////////////////////////////
    MapOfCounts processResults(ResultsMap& indexPosResults, uint readLen, uint readlines, const fs::path& matchingReads = "");

    ////////////////////////////////////////////////////////////////////////
    /// \brief overrideUtils
    /// \param utils
    ////////////////////////////////////////////////////////////////////////
    void overrideUtils(std::shared_ptr<IUtils> utils);

    ////////////////////////////////////////////////////////////////////////
    /// \brief KmerGenerator::overrideStats
    /// \param stats
    ////////////////////////////////////////////////////////////////////////
    void overrideStats(std::shared_ptr<IStats> stats);

private:
    ////////////////////////////////////////////////////////////////////////
    /// \brief _utils
    ////////////////////////////////////////////////////////////////////////
    Utils _ownedUtils;

    ////////////////////////////////////////////////////////////////////////
    /// \brief _utils
    ////////////////////////////////////////////////////////////////////////
    IUtils* _utils;

    ////////////////////////////////////////////////////////////////////////
    /// \brief _utils
    ////////////////////////////////////////////////////////////////////////
    Stats _ownedStats;

    ////////////////////////////////////////////////////////////////////////
    /// \brief _stats
    ////////////////////////////////////////////////////////////////////////
    IStats* _stats;
};
}

#endif // end of class