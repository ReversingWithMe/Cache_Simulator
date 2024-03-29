# Cache_Simulator
Spim_Cache/

Mips simulator that includes cache simulator, used for compiler course optimization performance. Penultimate compiler course with correct assembly to be evaluated against optimized to minimize memory access, strongest indicator of timing performance.

# Orignal_Readme
                        README FILE FOR SPIM, XSPIM, PCSPIM, and QTSPIM 
                        ===============================================

This directory contains SPIM--an assembly language MIPS32 simulator.

SPIM is Copyright (c) 1990-2010, by James R. Larus.
All rights reserved.

SPIM is distributed under a BSD license:

     Redistribution and use in source and binary forms, with or without modification, are
     permitted provided that the following conditions are met:

         Redistributions of source code must retain the above copyright notice, this list of
         conditions and the following disclaimer.

         Redistributions in binary form must reproduce the above copyright notice, this list of
         conditions and the following disclaimer in the documentation and/or other materials
         provided with the distribution.

         Neither the name of the James R. Larus nor the names of its contributors may be used to
         endorse or promote products derived from this software without specific prior written
         permission.

     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
     OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
     MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
     COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
     EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
     SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
     TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


                                      GETTING SPIM SOURCE
                                      ===================

Spim is hosted on SourceForge and its source code is available through SVN:
https://sourceforge.net/projects/spimsimulator/


                                          DIRECTORIES
                                          ===========

The subdirectories can be divided into two categories.

1. Common to all versions of Spim:

    CPU -- Contains the MIPS simulator and some utility functions common to all version of the
           simulator.

    Documentation -- Contains the man pages, web page, and other documentation.

    bin -- Utilities.

    Setup -- Contain tools used to build deployable versions of the simulators.

    Tests -- Contains regression test for the simulator.

    Boneyard -- Copies of the recent releases of Spim.


2. Front-ends for different versions of Spim:

    PCSpim -- Microsoft Windows front end for Spim.

    QtSpim -- Front end for Spim that works on Microsoft Windows, Linux, and Mac OS X.

    spim -- Text-only (terminal or console) front end for Spim. Works on all platforms.

    xspim -- X-Windows front end for Spim. Works on Linux and Mac OS X. (Built on a very old
             X Windows library that is no longer supported by the Mac.)


                                        BUILDING QTSPIM
                                        ===============

It is generally not necessary to build QtSpim as the Spim website contains an installable
version for most systems.

Install the bison parser generator and flex lexer generator, either using Cygwin on Windows or
native on Linux.

1. Download the free (open source) version of Qt Creator from
   http://qt.nokia.com/downloads/. This is a large download that might take a while.

        The open source version of Qt Creator for Windows, which uses mingw, works fine, as does
        the version (which you need to build yourself) that uses Microsoft Visual Studio's C++
        compiler.

        The Qt Creator package for Ubuntu is an old version, which has some problems with
        QtSPIM.  Download a recent version from http://qt.nokia.com/downloads/.

        The Mac Qt SDK is located at http://qt.nokia.com/downloads/sdk-mac-os-cpp.

2. Start QtCreator and open the file QtSpim/QtSpim.pro.

3. Compile QtSpim.

        If you are porting to a new system and see a large number of compiler errors in
        QtCreator, changes are good that you need to change QtSpim.pro to define the compiler
        flag that says "treat all files, including .c files, as C++ code. This flag is "-X C++"
        for gcc and "-TP" for the Microsoft compiler.


                                    BUILDING SPIM and XSPIM
                                    =======================

It is necessary to build spim and xspim, as they are only distributed as source.

   1. Download the source for spimsimulator from sourceforge
   (https://sourceforge.net/projects/spimsimulator/), either through Subversion from the
   spimsimulator repository (http://spimsimulator.svn.sourceforge.net/viewvc/spimsimulator/) or
   by downloading a tarball
   (http://spimsimulator.svn.sourceforge.net/viewvc/spimsimulator/?view=tar).

   2. Decompress the file, using either the program uncompress for the first file or gzip for
      the second file:

          % uncompress spim.tar.Z

      or

          % gzip -d spim.tar.gz

   3. Move the file spim.tar to the directory in which you want to build spim and untar it:

          % tar xf spim.tar

      It will create a directory named spim-8.0 (or the most recent version number).

   4. The simple terminal interface is contained in the spim-8.0/spim directory and the
   X-windows interfaces is in the spim-8.0/xspim directory. The other directories are described
   in the README file.

   5. Next, you must set the directories in which spim will be installed by editing the Makefile
   (the file that contains instructions on building spim). In general, if you are installing
   spim and want the windowing version (xspim), edit the file xspim/Imakefile. If you don't want
   xspim or are running on a system without X-windows installed, you use the file spim/Makefile.

      The programs are installed in standard locations, but you can change the pathnames to other locations:

          EXCEPTION_DIR -- The full pathname of the directory in which to install the spim exception handler (exceptions.s).

          BIN_DIR -- The full pathname of the directory in which spim and xspim should be installed.

          MAN_DIR -- The full pathname of the directory in which the manual pages for spim and xspim should be installed.

      In general, the remaining parameters in a Makefile need not be changed.

   6. Then, if you are building xspim, change to the spim-8.0/xspim directory and type:

          % xmkmf
          % make

      If you do not have a copy of xmkmf, you can use the Makefile in the xspim directory, but
      beware that it may not work on your system because the paths to the X windows libraries
      could be different.

   7. If you do not have X-windows, change to thespim-8.0/spim directory, edit Makefile, and type:

          % make

   8. To run spim or xspim, the exception handler must be installed in the directory specified
   by the variable EXCEPTION_DIR in the Makefile. If the file exception.s is not installed, spim
   and xspim fail before they start running. You can either install this file by hand or by
   typing:

          % make install

   which also installs spim or xspim, and the manual pages in the directories that you set
   (above). You may need root permission to install these files, in which case type:

          % sudo make install

   9. To test that spim is correctly built, change to the spim-8.0/spim directory and type:

          % make test

      and examine the output of the test. (Note: the exception handler must be installed before
      running the test.)


                                        BUILDING PCSPIM
                                        ===============

It is not necessary to compile PCSpim (the Microsoft Windows version), as the Spim web site
contains a precompiled version.

The Microsoft Windows version of Spim is called PCSpim and is built using Microsoft Visual
Studio.

spim (the terminal version) works well on Microsoft Windows.  You can easily build it using the
Cygwin port of the GNU tools (see www.cygwin.com).



                                      NEW VERSIONS OF SPIM
                                      ===================

I generally release new version of SPIM once a year, before a semester boundary (late August or
early January).  The new version are available on:

		https://sourceforge.net/projects/spimsimulator/
		
                                        CACHE SIMULATOR
                                      ===================
                                      
Cache Simulator utilizes modified SPIM revision 656 code to generate a list of memory address that are read from and written to during the couse of execution of Mips code through the Spim Simulator. Using this list of memory accesses, a cache enviroment is created with user input of cache specifications such as cache line size, number of sets, number of blocks, and algorithms for placing addresses in blocks and replacing addresses in blocks.


