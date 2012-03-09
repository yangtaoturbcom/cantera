/**
 *  @file Elements.h
 *  Contains the LookupWtElements function and the definitions of element
 *  constraint types.
 */
//  Copyright 2001  California Institute of Technology

#ifndef CT_ELEMENTS_H
#define CT_ELEMENTS_H

#include "cantera/base/ct_defs.h"

namespace Cantera
{

/*!
  *  @name Types of Element Constraint Equations
  *
  *   There may be several different types of element constraints handled
  *   by the equilibrium program and by Cantera in other contexts.
  *   These defines are used to assign each constraint to one category.
  *   @{
  */

//! An element constraint that is current turned off
#define CT_ELEM_TYPE_TURNEDOFF       -1

//! Normal element constraint consisting of positive coefficients for the
//! formula matrix.
/*!
 * All species have positive coefficients within the formula matrix.
 * With this constraint, we may employ various strategies to handle
 * small values of the element number successfully.
 */
#define CT_ELEM_TYPE_ABSPOS           0

//! This refers to conservation of electrons
/*!
 * Electrons may have positive or negative values in the Formula matrix.
 */
#define CT_ELEM_TYPE_ELECTRONCHARGE   1

//! This refers to a charge neutrality of a single phase
/*!
 * Charge neutrality may have positive or negative values in the Formula matrix.
 */
#define CT_ELEM_TYPE_CHARGENEUTRALITY 2

//! Constraint associated with maintaing a fixed lattice stoichiometry in a solid
/*!
 * The constraint may have positive or negative values. The lattice 0 species will
 * have negative values while higher lattices will have positive values
 */
#define CT_ELEM_TYPE_LATTICERATIO 3

//! Constraint associated with maintaining frozen kinetic equilibria in
//! some functional groups within molecules
/*!
 *  We seek here to say that some functional groups or ionic states should be
 *  treated as if they are separate elements given the time scale of the problem.
 *  This will be abs positive constraint. We have not implemented any examples yet.
 *  A requirement will be that we must be able to add and subtract these constraints.
 */
#define CT_ELEM_TYPE_KINETICFROZEN 4

//! Constraint associated with the maintenance of a surface phase
/*!
 *  We don't have any examples of this yet either. However, surfaces only exist
 *  because they are interfaces between bulk layers. If we want to treat surfaces
 *  within thermodynamic systems we must come up with a way to constrain their total
 *  number.
 */
#define CT_ELEM_TYPE_SURFACECONSTRAINT 5

//! Other constraint equations
/*!
 * currently there are none
 */
#define CT_ELEM_TYPE_OTHERCONSTRAINT  6
//@}

//! Number indicating we don't know the entropy of the element in its most
//! stable state at 298.15 K and 1 bar.
#define ENTROPY298_UNKNOWN -123456789.

//! Function to look up an atomic weight
//! This function looks up the argument string in the database above and
//! returns the associated molecular weight.
//! The data are from the periodic table.
//!
//! Note: The idea behind this function is to provide a unified source for the
//! element atomic weights. This helps to ensure that mass is conserved.
//!     @param ename  String, Only the first 3 characters are significant
//!     @return The atomic weight of the element
//!     @exception CanteraError If a match is not found, throws a CanteraError
double LookupWtElements(const std::string& ename);

}  // namespace

#endif
