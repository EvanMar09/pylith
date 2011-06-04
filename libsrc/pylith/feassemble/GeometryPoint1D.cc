// -*- C++ -*-
//
// ======================================================================
//
// Brad T. Aagaard, U.S. Geological Survey
// Charles A. Williams, GNS Science
// Matthew G. Knepley, University of Chicago
//
// This code was developed as part of the Computational Infrastructure
// for Geodynamics (http://geodynamics.org).
//
// Copyright (c) 2010 University of California, Davis
//
// See COPYING for license information.
//
// ======================================================================
//

#include <portinfo>

#include "GeometryPoint1D.hh" // implementation of class methods

#include "pylith/utils/array.hh" // USES double_array

#include <cassert> // USES assert()

// ----------------------------------------------------------------------
// Default constructor.
pylith::feassemble::GeometryPoint1D::GeometryPoint1D(void) :
  CellGeometry(POINT, 1)
{ // constructor
  const double vertices[] = { 0.0 };
  _setVertices(vertices, 1, 1);
} // constructor

// ----------------------------------------------------------------------
// Default destructor.
pylith::feassemble::GeometryPoint1D::~GeometryPoint1D(void)
{ // destructor
} // destructor

// ----------------------------------------------------------------------
// Create a copy of geometry.
pylith::feassemble::CellGeometry*
pylith::feassemble::GeometryPoint1D::clone(void) const
{ // clone
  return new GeometryPoint1D();
} // clone

// ----------------------------------------------------------------------
// Get cell geometry for lower dimension cell.
pylith::feassemble::CellGeometry*
pylith::feassemble::GeometryPoint1D::geometryLowerDim(void) const
{ // geometryLowerDim
  return 0;
} // geometryLowerDim

// ----------------------------------------------------------------------
// Transform coordinates in reference cell to global coordinates.
void
pylith::feassemble::GeometryPoint1D::ptsRefToGlobal(double* ptsGlobal,
						    const double* ptsRef,
						    const double* vertices,
						    const int dim,
						    const int npts) const
{ // ptsRefToGlobal
  assert(0 != ptsGlobal);
  assert(0 != ptsRef);
  assert(0 != vertices);
  assert(1 == dim);
  assert(spaceDim() == dim);

  for (int i=0; i < npts; ++i)
    ptsGlobal[i] = vertices[i];
} // ptsRefToGlobal

// ----------------------------------------------------------------------
// Compute Jacobian at location in cell.
void
pylith::feassemble::GeometryPoint1D::jacobian(double_array* jacobian,
					      double* det,
					      const double_array& vertices,
					      const double_array& location) const
{ // jacobian
  assert(0 != jacobian);
  assert(0 != det);

  assert(1 == jacobian->size());
  
  (*jacobian)[0] = 1.0;
  *det = 1.0;
} // jacobian

// ----------------------------------------------------------------------
// Compute Jacobian at location in cell.
void
pylith::feassemble::GeometryPoint1D::jacobian(double* jacobian,
					      double* det,
					      const double* vertices,
					      const double* ptsRef,
					      const int dim,
					      const int npts) const
{ // jacobian
  assert(0 != jacobian);
  assert(0 != det);
  assert(0 != vertices);
  assert(0 != ptsRef);
  assert(1 == dim);
  assert(spaceDim() == dim);

  for (int i=0; i < npts; ++i) {
    jacobian[i] = 1.0;
    det[i] = 1.0;
  } // for
} // jacobian


// End of file