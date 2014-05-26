## 
## $Id$
## Matcalc Copyright (C) 2002 Cristelle Barillon, Jean-Daniel PAUGET
## A small set graphical utilities for SDL
## 
## matcalc@disjunkt.com  -  http://matcalc.disjunkt.com/
## 
## This file is part of Matcalc.
## 
## Matcalc is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
## 
## Caroube is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with Caroube; if not, write to the Free Software
## Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
## you can also try the web at http://www.gnu.org/
## 
## matcalc@disjunkt.com  -  http://matcalc.disjunkt.com/

## probably redundant with somewhere else
## CFLAGS = -O2 -Wall

SUBDIRS = src

vimtest: check all
	## ./src/Caroube
	## startx -display :1 -e ./src/Caroube -- :1 -depth 16 -ac

vimtestw32: check all
	## rm -f ./src/Caroube.exe
	## mv ./src/Caroube ./src/Caroube.exe


##  additional file(s) to be removed when making dist...
## DISTCLEANFILES = ./src/Caroube.exe ./src/stderr.txt ./src/stdout.txt

clean-local:
	rm -f "${PACKAGE}_${VERSION}.orig.tar.gz" tarfiles.txt

## bad hook for removing dummy-files created in order to have out-of-source-dir build to work
distclean-local:
	rm -f src/include/Makefile
	rm -f "${PACKAGE}_${VERSION}.orig.tar.gz" tarfiles.txt

.PHONY: tar
tar: 
	repozclean && autoall
	find . | grep -v '\.git' | grep -v 'debian-src' | grep -v 'autom4te' > tarfiles.txt
	bozoconf
	tar -zcphf "${PACKAGE}_${VERSION}.orig.tar.gz" --no-recursion --transform='s=^='"${PACKAGE}"_"${VERSION}"'/=' -T tarfiles.txt
	tar -ztvf "${PACKAGE}_${VERSION}.orig.tar.gz"
