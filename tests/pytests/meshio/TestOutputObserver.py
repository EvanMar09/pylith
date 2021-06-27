#!/usr/bin/env nemesis
#
# ======================================================================
#
# Brad T. Aagaard, U.S. Geological Survey
# Charles A. Williams, GNS Science
# Matthew G. Knepley, University of Chicago
#
# This code was developed as part of the Computational Infrastructure
# for Geodynamics (http://geodynamics.org).
#
# Copyright (c) 2010-2017 University of California, Davis
#
# See COPYING for license information.
#
# ======================================================================
#
# @file tests/pytests/meshio/TestOutputObserver.py
#
# @brief Unit testing of Python OutputObserver object.

import unittest

from pylith.testing.UnitTestApp import TestAbstractComponent
from pylith.meshio.OutputObserver import OutputObserver


class TestOutputObserver(TestAbstractComponent):
    """Unit testing of OutputObserver object.
    """
    _class = OutputObserver


if __name__ == "__main__":
    suite = unittest.TestSuite()
    suite.addTest(unittest.makeSuite(TestOutputObserver))
    unittest.TextTestRunner(verbosity=2).run(suite)


# End of file