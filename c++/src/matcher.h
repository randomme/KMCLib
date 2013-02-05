/*
  Copyright (c)  2012  Mikael Leetmaa

  This file is part of the KMCLib project distributed under the terms of the
  GNU General Public License version 3, see <http://www.gnu.org/licenses/>.
*/



/*! \file  matcher.h
 *  \brief File for the Matcher class definition.
 */

#ifndef __MATCHER__
#define __MATCHER__

#include <vector>

#include "matchlistentry.h"

// Forward declarations.
class Interactions;
class Configuration;
class Process;
class LatticeMap;

/// A minimal struct for representing an add task.
struct AddTask
{
    int index;
    int process;
    double rate;
};

/// A minimal struct for representing an update task.
struct UpdateTask
{
    int index;
    int process;
    double rate;
};

/// A minimal struct for representing a remove task.
struct RemoveTask
{
    int index;
    int process;
};


/*! \brief Class for matching local geometries.
 */
class Matcher {

public:

    /*! \brief Default constructor.
     */
    Matcher();

    /*! \brief Calculate/update the matching of provided indices with
     *         all possible processes.
     *  \param interactions  : The interactions object holding info on possible processes.
     *  \param configuration : The configuration which the list of indices refers to.
     *  \param lattice_map   : The lattice map describing the configuration.
     *  \param indices       : The configuration indices for which the neighbourhood should
     *                         be matched against all possible processes.
     */
    void calculateMatching(Interactions & interactions,
                           Configuration & configuration,
                           const LatticeMap & lattice_map,
                           const std::vector<int> & indices) const;

    // ML
    void matchIndicesWithProcesses(const std::vector<std::pair<int,int> > & index_process_to_match,
                                   Interactions  & interactions,
                                   Configuration & configuration,
                                   std::vector<RemoveTask> & remove_tasks,
                                   std::vector<UpdateTask> & update_tasks,
                                   std::vector<AddTask> & add_tasks) const;

    // ML
    void updateProcesses(const std::vector<RemoveTask> & to_remove,
                         const std::vector<UpdateTask> & to_update,
                         const std::vector<AddTask>    & to_add,
                         Interactions & interactions) const;


    /*! \brief Calculate/update the matching of a provided index and process.
     *  \param process       : The process to check against and update if needed.
     *  \param configuration : The configuration which the index refers to.
     *  \param index         : The configuration index for which the neighbourhood should
     *                         be matched against the process.
      */
    void calculateMatching(Process & process,
                           Configuration & configuration,
                           const int index) const;

    /*! \brief Check the matching between two match lists, where the process match list
     *         must be shorter or equal in length to the index match list.
     *  \param process_match_list : The process match list to compare against.
     *  \param index_match_list   : The index match list to compare.
     *  \return : True if match.
     */
    bool isMatch(const std::vector<MinimalMatchListEntry> & process_match_list,
                 const std::vector<MinimalMatchListEntry> & index_match_list) const;


protected:

private:

};


#endif // __MATCHER__

