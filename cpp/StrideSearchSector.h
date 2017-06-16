#ifndef _STRIDE_SEARCH_SECTOR_H_
#define _STRIDE_SEARCH_SECTOR_H_ 

#include "StrideSearch_Config.h"
#include "StrideSearch_TypeDefs.h"
#include <vector>
#include "StrideSearchWorkspaceDict.h"
#include "StrideSearchIDCriteria_Base.h"
#include "StrideSearchEvent.h"
#include "StrideSearchDateTime.h"

namespace StrideSearch {

/// A Sector is the StrideSearch algorithm's basic unit of work.
/**
    A Sector has a center point on the sphere, and   
    it maintains a record of all data points that lie within its boundaries (physical coordinates and data location).
    This record is created by the SectorList that constructed this sector.
    
    Sectors are responsible for 
    1. Receiving data from StrideSearchData_Base subclasses at each time step
    2. Evaluating a set of identification criteria (a collection of IDCriterion subclass instances).
*/
struct Sector {
    scalar_type centerLat;
    scalar_type centerLon;
    
    std::vector<ll_coord_type> data_coords;
    std::vector<vec_indices_type> data_indices;
    
    std::vector<WorkspaceDict> workspace;
    
    /// Constructor
    Sector(const scalar_type cLat, const scalar_type cLon, const std::vector<ll_coord_type>& crds,
           const std::vector<vec_indices_type>& inds, const index_type nCriteria) : 
           centerLat(cLat), centerLon(cLon), data_coords(crds), data_indices(inds), workspace(nCriteria) {};
    
    /// Allocates memory for this sector's local workspace
    void allocWorkspace(const std::vector<IDCriterion*>& criteria);
    
    /// Evaluates a set criteria against a set of local data; returns an event for each criterion that evaluates true.
    std::vector<Event> evaluateCriteriaAtTimestep(std::vector<IDCriterion*>& criteria, const DateTime& dt, 
        const std::string& fname, const index_type timeIndex);
    
    /// Returns a string containing this sector's information.
    std::string infoString(const int tabLevel = 0) const;    
};


}

#endif