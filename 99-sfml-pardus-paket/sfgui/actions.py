#!/usr/bin/python
# -*- coding: utf-8 -*-
#
# Licensed under the GNU General Public License, version 3.
# See the file http://www.gnu.org/copyleft/gpl.txt

from pisi.actionsapi import pisitools
from pisi.actionsapi import scons

def build():
    scons.make()

def install():
    pisitools.insinto("/usr/include", "include/*")
    pisitools.dolib("lib/*")
    pisitools.dodoc("CONTRIB", "LICENSE", "README")
