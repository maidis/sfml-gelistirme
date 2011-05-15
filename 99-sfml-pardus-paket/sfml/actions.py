#!/usr/bin/python
# -*- coding: utf-8 -*-
#
# Licensed under the GNU General Public License, version 3.
# See the file http://www.gnu.org/copyleft/gpl.txt

from pisi.actionsapi import cmaketools
from pisi.actionsapi import pisitools
from pisi.actionsapi import get

WorkDir = "LaurentGomila-SFML-0e826d8"

def setup():
    cmaketools.configure("-DBUILD_DOC=TRUE")

def build():
    cmaketools.make()

def install():
    cmaketools.rawInstall("DESTDIR=%s" % get.installDIR())

    pisitools.removeDir("/usr/share/SFML")

    pisitools.insinto("/usr/share/SFML", "examples/*")

    pisitools.dohtml("doc/*")

    pisitools.dodoc("license.txt")
