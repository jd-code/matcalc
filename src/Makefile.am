## 
## $Id$
## Matcalc Copyright (C) 2002,2003 Cristelle Barillon & Jean-Daniel Pauget
##
## matcalc@disjunkt.com  -  http://matcalc.disjunkt.com/
## 
## Matcalc is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
## 
## Matcalc is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with GenRythm; if not, write to the Free Software
## Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
## you can also try the web at http://www.gnu.org/
## 
## matcalc@disjunkt.com  -  http://matcalc.disjunkt.com/

##	lib_LTLIBRARIES =libcaroube.la
##	
##	libcaroube_la_LDFLAGS = -version-info @lt_major@:@lt_revision@:@lt_age@ @GL_LIBS@
##	
##	libcaroube_la_SOURCES = samplesonge.cpp audio.cpp conv_ieee_ext.c \
##				readsample.cpp asequencer.cpp \
##				fft.c



## loopsoids_LDADD = @SDL_LIBS@ @GL_LIBS@ @GRAPEFRUIT_LIBS@
## loopsoids_LDADD = @GL_LIBS@

pkginclude_HEADERS =	include/matcalc/matcalc.h

TESTS = v3_comparison		\
	v3_addition		\
	v3_negation		\
	v3_substraction 	\
	v3_vectorialprod	\
	m4_transpose		\
	m4_invert		\
	m4_multiply
	

v3_comparison_SOURCES = v3_comparison.cpp
v3_addition_SOURCES = v3_addition.cpp
v3_negation_SOURCES = v3_negation.cpp
v3_substraction_SOURCES = v3_substraction.cpp
v3_vectorialprod_SOURCES = v3_vectorialprod.cpp
m4_transpose_SOURCES = m4_transpose.cpp
m4_invert_SOURCES = m4_invert.cpp
m4_multiply_SOURCES = m4_multiply.cpp

check_PROGRAMS = $(TESTS)

##SUBDIRS = include

