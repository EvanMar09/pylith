#!/usr/bin/env python
#
# ======================================================================
#
#                           Brad T. Aagaard
#                        U.S. Geological Survey
#
# {LicenseText}
#
# ======================================================================
#

## @file unittests/pytests/materials/TestDruckerPrager3D.py

## @brief Unit testing of DruckerPrager3D object.

import unittest

from pylith.materials.DruckerPrager3D import DruckerPrager3D

# ----------------------------------------------------------------------
class TestDruckerPrager3D(unittest.TestCase):
  """
  Unit testing of DruckerPrager3D object.
  """

  def setUp(self):
    """
    Setup test subject.
    """
    self.material = DruckerPrager3D()
    return
  

  def test_constructor(self):
    """
    Test constructor.
    """
    self.assertEqual(3, self.material.dimension())
    return


  def test_useElasticBehavior(self):
    """
    Test useElasticBehavior().
    """
    self.material.useElasticBehavior(False)
    return


  def testHasStateVars(self):
    self.failUnless(self.material.hasStateVars())
    return


  def testTensorSize(self):
    self.assertEqual(6, self.material.tensorSize())
    return


  def testNeedNewJacobian(self):
    """
    Test needNewJacobian().
    """
    # Default should be False.
    self.failIf(self.material.needNewJacobian())

    # Should require a new Jacobian even if time step is the same.
    self.material.timeStep(1.0)
    self.failUnless(self.material.needNewJacobian())
    self.material.timeStep(2.0)
    self.failUnless(self.material.needNewJacobian())

    self.material.timeStep(2.0)
    self.failUnless(self.material.needNewJacobian())
    return
  

  def test_factory(self):
    """
    Test factory method.
    """
    from pylith.materials.DruckerPrager3D import material
    m = material()
    return


# End of file 