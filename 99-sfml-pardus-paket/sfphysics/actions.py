#!/usr/bin/python
# -*- coding: utf-8 -*-
#
# Licensed under the GNU General Public License, version 3.
# See the file http://www.gnu.org/copyleft/gpl.txt

from pisi.actionsapi import autotools
from pisi.actionsapi import pisitools
from pisi.actionsapi import get

def build():
    pisitools.dosed("build/Makefile", "colorgcc", "g++")
    pisitools.dosed("build/Makefile", "/local", "")
    autotools.make()

def install():
    autotools.rawInstall("DESTDIR=%s/usr" % get.installDIR())
    pisitools.removeDir("/usr/lib/debug")
