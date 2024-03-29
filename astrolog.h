/*
** Astrolog (Version 6.40) File: astrolog.h
**
** IMPORTANT NOTICE: Astrolog and all chart display routines and anything
** not enumerated below used in this program are Copyright (C) 1991-2018 by
** Walter D. Pullen (Astara@msn.com, http://www.astrolog.org/astrolog.htm).
** Permission is granted to freely use, modify, and distribute these
** routines provided these credits and notices remain unmodified with any
** altered or distributed versions of the program.
**
** The main ephemeris databases and calculation routines are from the
** library SWISS EPHEMERIS and are programmed and copyright 1997-2008 by
** Astrodienst AG. The use of that source code is subject to the license for
** Swiss Ephemeris Free Edition, available at http://www.astro.com/swisseph.
** This copyright notice must not be changed or removed by any user of this
** program.
**
** Additional ephemeris databases and formulas are from the calculation
** routines in the program PLACALC and are programmed and Copyright (C)
** 1989,1991,1993 by Astrodienst AG and Alois Treindl (alois@astro.ch). The
** use of that source code is subject to regulations made by Astrodienst
** Zurich, and the code is not in the public domain. This copyright notice
** must not be changed or removed by any user of this program.
**
** The original planetary calculation routines used in this program have
** been copyrighted and the initial core of this program was mostly a
** conversion to C of the routines created by James Neely as listed in
** 'Manual of Computer Programming for Astrologers', by Michael Erlewine,
** available from Matrix Software.
**
** The PostScript code within the core graphics routines are programmed
** and Copyright (C) 1992-1993 by Brian D. Willoughby (brianw@sounds.wa.com).
**
** More formally: This program is free software; you can redistribute it
** and/or modify it under the terms of the GNU General Public License as
** published by the Free Software Foundation; either version 2 of the
** License, or (at your option) any later version. This program is
** distributed in the hope that it will be useful and inspiring, but
** WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** General Public License for more details, a copy of which is in the
** LICENSE.HTM file included with Astrolog, and at http://www.gnu.org
**
** Initial programming 8/28-30/1991.
** X Window graphics initially programmed 10/23-29/1991.
** PostScript graphics initially programmed 11/29-30/1992.
** Last code change made 7/22/2018.
*/

/*
** TO COMPILE: For most systems, especially Unix, DOS, and Macs, the only
** changes that should need to be made to the code are to edit or comment the
** #define's below to equal the particulars of your own system and locale:
**
** SYSTEM SECTION: These settings describe platform and hardware specifics.
** They are all required to be set properly or the program likely won't
** compile or run. Some of these are technically optional and can be
** commented out even if your system would normally support them, e.g.
** the X11 graphics can be disabled even if you are running X windows.
*/

#define PC /* Comment out this #define if you have a Unix, Mac, or other */
           /* system that isn't a generic PC running DOS or MS Windows.  */

/*#define MACOLD /* Comment out this #define if you're not compiling for an  */
               /* old pre-OSX Mac. Modern Mac systems should not use this. */

/*#define X11 /* Comment out this #define if you don't have X windows, or */
            /* else have them and don't wish to compile in X graphics.  */

#define WIN /* Comment out this #define if you don't have MS Windows, or */
            /* else have them but want a command line version instead.   */

/*#define MACG /* Comment out this #define if you don't have a Mac, or else  */
             /* have one and don't wish to compile in Mac screen graphics. */

/*#define WCLI /* Comment out this #define if you don't want to compile a    */
             /* command line Windows version that can still popup windows. */

#define TIME /* Comment out this #define if your compiler can't take the  */
             /* calls to the 'time' or 'localtime' functions as in time.h */

#define SWITCHES /* Comment out this #define if your system can not handle */
                 /* parameters on the command line (such as Mac's).        */

#define ENVIRON /* Comment out this #define if your system doesn't have  */
                /* environment variables or can't compile calls to them. */

/*#define ATOF /* Comment out this #define if you have a system in which  */
             /* 'atof' and related functions aren't defined in stdio.h, */
             /* such as most PC's, Linux, VMS compilers, and NeXT's.    */

#define PROTO /* Comment out this #define if you have an older compiler   */
              /* which doesn't allow full Ansi function prototypes. This  */
              /* is for programmers only and has no effect on executable. */

/*
** FEATURES SECTION: These settings describe features that are always
** available to be compiled into the program no matter what platform or
** hardware is available. Their settings are always optional.
*/

#define GRAPH /* Comment out this #define if you don't want any graphics   */
              /* in the program. This switch allows at least generation of */
              /* bitmap files and must be set if any of the more advanced  */
              /* graphics feature additions are also compiled in.          */

#define SWISS /* Comment out this #define if you don't want the Swiss      */
              /* Ephemeris most accurate calculation features and formulas */
              /* to be compiled into the program (as accessed with -b).    */

#define PLACALC /* Comment out this #define if you don't want the Placalc */
                /* less accurate calculation features and formulas to be  */
                /* compiled into the program (as accessed with -bp).      */

#define MATRIX /* Comment out this #define if you don't want the Matrix  */
               /* much less accurate calculation formulas to be compiled */
               /* into the program (as accessed with -bm).               */

#define PS /* Comment out this #define if you don't want the ability to */
           /* generate charts in the PostScript graphics format.        */

#define META /* Comment out this #define if you don't want the ability to  */
             /* generate charts in the MS Windows metafile picture format. */

#define WIRE /* Comment out this #define if you don't want the ability to */
             /* generate charts in the Daedalus wireframe vector format.  */

#define INTERPRET /* Comment out this #define if you don't want the ability */
                  /* to display interpretations of the various chart types. */

#define ARABIC /* Comment out this #define if you don't want any chart     */
               /* lists that include Arabic parts included in the program. */

#define CONSTEL /* Comment out this #define if you don't want any of the */
                /* astronomical constellation charts in the program.     */

#define BIORHYTHM /* Comment out this #define if you don't want the    */
                  /* non-astrological biorhythm charts in the program. */

/*
** DATA CONFIGURATION SECTION: These settings describe particulars of
** your own location and where the program looks for certain info. It is
** recommended that these values be changed appropriately, although the
** program will still run if they are left alone. They may also be
** specified within the default settings file or in the program itself.
*/

#ifndef PC
#define DEFAULT_DIR "~/astrolog"
#else
#define DEFAULT_DIR "C:\\Astrolog"
#endif
  /* Change this string to directory path program should look in for the  */
  /* astrolog.as default file, if one is not in the current directory or  */
  /* in the dirs indicated by environment variables. For PC systems, use  */
  /* two backslashes instead of one forward one to divide subdirectories. */

#define CHART_DIR DEFAULT_DIR
  /* This string is the directory the program looks in for chart info    */
  /* files (-i switch) if not in the current directory. This is normally */
  /* the default dir above but may be changed to be somewhere else.      */

#define EPHE_DIR DEFAULT_DIR
  /* This string is the directory the program looks in for the ephemeris */
  /* files as accessed with the -b switch. This is normally the default  */
  /* dir above but may be changed to be somewhere else.                  */

#define DEFAULT_LONG DM(122,20) /* Change numbers to longitude and latitude */
#define DEFAULT_LAT  DM(47, 36) /* of your current location. Use negative   */
                                /* values for eastern or southern degrees.  */

#define DEFAULT_ZONE 8.00 /* Change this number to the time zone of your */
                          /* current location in hours before (west of)  */
                          /* UTC. Use negative values for eastern zones. */

/*
** OPTIONAL CONFIGURATION SECTION: Although not necessary, one may like
** to change some of the values below: These constants affect some of
** the default parameters and related options. They may also be
** specified within the default settings file or in the program itself.
*/

#define DEFAULT_SYSTEM 0 /* Normally, Placidus houses are used (unless the */
                         /* user specifies otherwise). If you want a       */
                         /* different default system, change this number   */
                         /* to a value from 0..17 (values same as in -c).  */

#define DEFAULT_ASPECTS 5 /* Default number of aspects to use in charts. */

#define DIVISIONS 48 /* Greater numbers means more accuracy but slower  */
                     /* calculation, of exact aspect and transit times. */

#define DEFAULT_INFOFILE "astrolog.as"
  /* Name of file to look in for default program parameters (which will */
  /* override the compile time values here, if the file exists).        */

#define ENVIRONALL "ASTROLOG"
#define ENVIRONVER "ASTR"
  /* Name of environment variables to look in for chart, ephemeris, and  */
  /* default files. The second name is a version specific variable which */
  /* gets the current version appended to it before it is accessed.      */

#define WHEELCOLS 15   /* Affects width of each house in wheel display.    */
#define WHEELROWS 11   /* Max no. of objects that can be in a wheel house. */
#define SCREENWIDTH 80 /* Number of columns to print interpretations in.   */
#define MONTHSPACE 3   /* Number of spaces between each calendar column.   */
#define MAXINDAY 200   /* Max number of aspects or transits displayable.   */
#define MAXCROSS 750   /* Max number of latitude crossings displayable.    */
#define CREDITWIDTH 74 /* Number of text columns in the -Hc credit screen. */
#define MAXSWITCHES 64 /* Max number of switch parameters per input line.  */
#define PSGUTTER 9     /* Points of white space on PostScript page edge.   */

#ifdef GRAPH           /* For graphics, this char affects how bitmaps are */
#ifndef PC             /* written. 'N' is written like with the 'bitmap'  */
#define BITMAPMODE 'C' /* program, 'C' is compacted somewhat (files have  */
#else                  /* less spaces), and 'V' is compacted even more.   */
#define BITMAPMODE 'B' /* 'A' means write as rectangular Ascii text file. */
#endif                 /* 'B' means write as Windows bitmap (.bmp) file.  */
#endif /* GRAPH */

/*
** By the time you reach here and the above values are customized as
** desired, Astrolog is ready to be compiled! Be sure to similarly
** change the values in the astrolog.as file, which will override any
** corresponding compile time values here. Don't change any of the
** values in the section below unless you know what you're doing.
*/

#ifdef GRAPH
#define BITMAPX    2730 /* Maximum window size allowed */
#define BITMAPY    2730
#define BITMAPX1    180 /* Minimum window size allowed */
#define BITMAPY1    180
#define DEFAULTX    480 /* Default window size */
#define DEFAULTY    480
#define SIDESIZE    160 /* Size of wheel chart information sidebar.    */
#define MAXMETA 1000000 /* Max bytes allowed in a metafile.            */
#define METAMUL      12 /* Metafile coordinate to chart pixel ratio.   */
#define PSMUL        11 /* PostScript coordinate to chart pixel ratio. */
#define WIREMUL      10 /* Wireframe coordinate to chart pixel ratio.  */
#define CELLSIZE     14 /* Size for each cell in the aspect grid.      */
#define BIODAYS      14 /* Days to include in graphic biorhythms.      */
#define DEGINC        2 /* Number of degrees per segment for circles.  */
#define DEFORB      7.0 /* Min distance glyphs can be from each other. */
#define MAXSCALE    400 /* Max scale factor as passed to -Xs swtich.   */
#endif /* GRAPH */

#define chH    (char)(us.fAnsiChar ? 196 : '-')    /* Ansi and Ascii       */
#define chV    (char)(us.fAnsiChar ? 179 : '|')    /* characters used to   */
#define chC    (char)(us.fAnsiChar ? 197 : '|')    /* display text charts. */
#define chNW   (char)(us.fAnsiChar ? 218 : '+')
#define chNE   (char)(us.fAnsiChar ? 191 : '+')
#define chSW   (char)(us.fAnsiChar ? 192 : '+')
#define chSE   (char)(us.fAnsiChar ? 217 : '+')
#define chJN   (char)(us.fAnsiChar ? 193 : '-')
#define chJS   (char)(us.fAnsiChar ? 194 : '-')
#define chJW   (char)(us.fAnsiChar ? 180 : '|')
#define chJE   (char)(us.fAnsiChar ? 195 : '|')
#define chDeg0 (char)(us.fAnsiChar ? 248 : ' ')
#define chDeg1 (char)(us.fAnsiChar ? 248 : ':')
#define chDeg2 (char)(us.fAnsiChar ? 176 : ' ')


/*
** One shouldn't ever need to change anything below this line to compile.
*/

/*#define BETA /* Uncomment to compile in beta message on startup. */
#define ASTROLOG
#ifdef _DEBUG
#define DEBUG
#endif
#ifdef SWISS
#define EPHEM
#ifdef PLACALC
#define EPHEM2
#endif
#endif
#ifdef PLACALC
#define EPHEM
#endif

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#ifndef ATOF
#include <stdlib.h>
#endif
#include <math.h>
#ifdef PC
#include <malloc.h>
#include <windows.h>
#endif
#ifdef TIME
#include <time.h>
#endif

#ifdef X11
#define ISG
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#endif
#ifdef WIN
#define ISG
#define WINANY
#include <windows.h>
#include <commdlg.h>
#include <objbase.h>
#include <comdef.h>
#include <comdefsp.h>
#include <shlobj.h>
#include <shobjidl.h>
#include <shlwapi.h>
#include "resource.h"
#endif
#ifdef MACG
#define ISG
#endif
#ifdef WCLI
#define ISG
#define WINANY
#include <windows.h>
#endif
#ifdef PC
#ifdef _WIN64
#define szArchCore "64 bit"
#else
#define szArchCore "32 bit"
#endif
#endif /* PC */

#ifdef PS
#define VECTOR
#endif
#ifdef META
#define VECTOR
#endif
#ifdef WIRE
#define VECTOR
#endif


/*
** Make sure only legal combinations of options are active.
*/

#ifdef PLACALC
#ifndef MATRIX
#error "If 'PLACALC' is defined 'MATRIX' must be too"
#endif
#endif /* PLACALC */

#ifdef MACOLD
#ifdef SWITCHES
#error "If 'MACOLD' is defined 'SWITCHES' must not be as well"
#endif
#ifdef ENVIRON
#error "If 'MACOLD' is defined 'ENVIRON' must not be as well"
#endif
#endif /* MACOLD */

#ifdef X11
#ifndef GRAPH
#error "If 'X11' is defined 'GRAPH' must be too"
#endif
#ifdef WIN
#error "If 'X11' is defined 'WIN' must not be as well"
#endif
#ifdef MACG
#error "If 'X11' is defined 'MACG' must not be as well"
#endif
#ifdef WCLI
#error "If 'X11' is defined 'WCLI' must not be as well"
#endif
#ifdef PC
#error "If 'X11' is defined 'PC' must not be as well"
#endif
#endif /* X11 */

#ifdef WIN
#ifndef GRAPH
#error "If 'WIN' is defined 'GRAPH' must be too"
#endif
#ifdef X11
#error "If 'WIN' is defined 'X11' must not be as well"
#endif
#ifdef MACG
#error "If 'WIN' is defined 'MACG' must not be as well"
#endif
#ifdef WCLI
#error "If 'WIN' is defined 'WCLI' must not be as well"
#endif
#ifndef PC
#error "If 'WIN' is defined 'PC' must be too"
#endif
#endif /* WIN */

#ifdef MACG
#ifndef GRAPH
#error "If 'MACG' is defined 'GRAPH' must be too"
#endif
#ifdef X11
#error "If 'MACG' is defined 'X11' must not be as well"
#endif
#ifdef WIN
#error "If 'MACG' is defined 'WIN' must not be as well"
#endif
#ifdef WCLI
#error "If 'MACG' is defined 'WCLI' must not be as well"
#endif
#ifdef PC
#error "If 'MACG' is defined 'PC' must not be as well"
#endif
#endif /* MACG */

#ifdef WCLI
#ifndef GRAPH
#error "If 'WCLI' is defined 'GRAPH' must be too"
#endif
#ifdef X11
#error "If 'WCLI' is defined 'X11' must not be as well"
#endif
#ifdef WIN
#error "If 'WCLI' is defined 'WIN' must not be as well"
#endif
#ifdef MACG
#error "If 'WCLI' is defined 'MACG' must not be as well"
#endif
#ifndef PC
#error "If 'WCLI' is defined 'PC' must be too"
#endif
#endif /* WCLI */

#ifdef PS
#ifndef GRAPH
#error "If 'PS' is defined 'GRAPH' must be too"
#endif
#endif /* PS */

#ifdef META
#ifndef GRAPH
#error "If 'META' is defined 'GRAPH' must be too"
#endif
#endif /* META */

#ifdef WIRE
#ifndef GRAPH
#error "If 'WIRE' is defined 'GRAPH' must be too"
#endif
#endif /* WIRE */


/*
******************************************************************************
** Program Constants.
******************************************************************************
*/

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE  1
#endif
#define fFalse FALSE
#define fTrue  TRUE

#define szAppNameCore "Astrolog"
#define szVersionCore "6.40"
#define szDateCore    "July 2018"
#define szAddressCore \
  "Astara@msn.com - http://www.astrolog.org/astrolog.htm"
#define szNowCore     "now"
#define szTtyCore     "tty"
#define szSetCore     "set"
#define szNulCore     "nul"

#define cchSzDef   80
#define cchSzMax   255
#define nDegMax    360
#define nDegHalf   180
#define nLarge     9999999
#define nNegative  -1000
#define yeaJ2G     1582
#define monJ2G     mOct
#define dayJ2G1    4
#define dayJ2G2    15
#define zonLMT     24.0
#define dstAuto    24.0

#define rSqr2      1.41421356237309504880
#define rLog10     2.30258509299404568402
#define rLog101    4.61512051684125945088
#define rPi        3.14159265358979323846
#define rPi2       (rPi*2.0)
#define rPiHalf    (rPi/2.0)
#define rDegMax    360.0
#define rDegHalf   180.0
#define rDegQuad   90.0
#define rDegRad    (rDegHalf/rPi)
#define rFtToM     0.3048
#define rInToCm    2.54
#define rDayInYear 365.24219
#define rEarthDist 149.59787
#define rEpoch2000 (-24.736467)
#define rAxis      23.44578889
#define rSmall     (1.7453E-09)
#define rLarge     10000.0
#define rRound     0.5

#define chNull     '\0'
#define chEscape   '\33'
#define chBell     '\7'
#define chReturn   '\r'
#define chTab      '\t'
#define chDelete   '\b'
#define chBreak    '\3'
#define chRet      'R'

/* Array index limits */

#define cObjInt    uranHi
#define objMax     (cObj+1)
#define cCnstl     88
#define cZone      72
#define cSector    36
#define cPart      177
#define cStarSwiss 10000
#define cWeek      7
#define cColor     16
#define cRay       7
#define xFont      6
#define yFont      10
#define xFontT     (xFont * gi.nScaleText * gi.nScaleT)
#define yFontT     (yFont * gi.nScaleText * gi.nScaleT)
#define xSideT     (SIDESIZE * gi.nScaleText * gi.nScaleT)

/* Object array index values */

#define cPlanet oVes
#define cThing  oLil
#define oMain   10
#define oCore   21
#define cUran   9
#define cStar   47
#define cuspLo  (oCore+1)
#define cuspHi  (cuspLo+cSign-1)
#define uranLo  (cuspHi+1)
#define uranHi  (uranLo+cUran-1)
#define oNorm   uranHi
#define oNorm1  starLo
#define starLo  (uranHi+1)
#define starHi  (starLo+cStar-1)

/* Month index values */

enum _months {
  mJan = 1,
  mFeb = 2,
  mMar = 3,
  mApr = 4,
  mMay = 5,
  mJun = 6,
  mJul = 7,
  mAug = 8,
  mSep = 9,
  mOct = 10,
  mNov = 11,
  mDec = 12,
};

/* Elements */

enum _elements {
  eFir = 0,
  eEar = 1,
  eAir = 2,
  eWat = 3,
  cElem = 4,
};

/* Zodiac signs */

enum _signs {
  sAri = 1,
  sTau = 2,
  sGem = 3,
  sCan = 4,
  sLeo = 5,
  sVir = 6,
  sLib = 7,
  sSco = 8,
  sSag = 9,
  sCap = 10,
  sAqu = 11,
  sPis = 12,
  cSign = 12,
};

/* Objects */

enum _objects {
  oEar = 0,
  oSun = 1,
  oMoo = 2,
  oMer = 3,
  oVen = 4,
  oMar = 5,
  oJup = 6,
  oSat = 7,
  oUra = 8,
  oNep = 9,
  oPlu = 10,
  oChi = 11,
  oCer = 12,
  oPal = 13,
  oJun = 14,
  oVes = 15,
  oNod = 16,
  oSou = 17,
  oLil = 18,
  oFor = 19,
  oVtx = 20,
  oEP  = 21,
  oAsc = 22,
  o2nd = 23,
  o3rd = 24,
  oNad = 25,
  o5th = 26,
  o6th = 27,
  oDes = 28,
  o8th = 29,
  o9th = 30,
  oMC  = 31,
  o11t = 32,
  o12t = 33,
  oVul = 34,
  oOri = (starLo-1+10),
  oAnd = (starLo-1+47),
  cObj = 89,
};

/* Aspects */

enum _aspects {
  aHou = -4,  /* 3D House change  */
  aDeg = -3,  /* Degree change    */
  aDir = -2,  /* Direction change */
  aSig = -1,  /* Sign change      */
  aCon = 1,
  aOpp = 2,
  aSqu = 3,
  aTri = 4,
  aSex = 5,
  aInc = 6,
  aSSx = 7,
  aSSq = 8,
  aSes = 9,
  aQui = 10,
  aBQn = 11,
  aSQn = 12,
  aSep = 13,
  aNov = 14,
  aBNv = 15,
  aBSp = 16,
  aTSp = 17,
  aQNv = 18,
  cAspect = 18,
  cAspect2 = cAspect + aOpp,
};

/* House systems */

enum _housesystem {
  hsPlacidus      = 0,
  hsKoch          = 1,
  hsEqual         = 2,
  hsCampanus      = 3,
  hsMeridian      = 4,
  hsRegiomontanus = 5,
  hsPorphyry      = 6,
  hsMorinus       = 7,
  hsTopocentric   = 8,
  hsAlcabitius    = 9,
  hsKrusinski     = 10,
  hsEqualMC       = 11,
  hsSinewaveRatio = 12,
  hsSinewaveDelta = 13,
  hsWhole         = 14,
  hsVedic         = 15,
  hsSripati       = 16,
  hsHorizon       = 17,
  hsAPC           = 18,
  hsCarter        = 19,
  hsNull          = 20,
  cSystem = 21,
};

/* Biorhythm cycle constants */

#define brPhy 23.0
#define brEmo 28.0
#define brInt 33.0

/* Relationship chart modes */

enum _relationshipchart {
  rcNone       = 0,
  rcSynastry   = 1,
  rcComposite  = 2,
  rcMidpoint   = 3,
  rcDifference = 4,
  rcBiorhythm  = 5,
  rcDual       = -1,
  rcTriWheel   = -2,
  rcQuadWheel  = -3,
  rcTransit    = -4,
  rcProgress   = -5,
};

/* Aspect configurations */

enum _configurations {
  acS3 = 0,  // Stellium (3 planets)
  acGT = 1,  // Grand Trine
  acTS = 2,  // T-Square
  acY  = 3,  // Yod
  acGC = 4,  // Grand Cross
  acC  = 5,  // Cradle
  acS4 = 6,  // Stellium (4 planets)
  cAspConfig = 7,
};

/* Angle restrictions */

enum _angles {
  arAsc = 0,  // Ascendant
  arMC  = 1,  // Midheaven
  arDes = 2,  // Descendant
  arIC  = 3,  // Nadir
  arMax = 4,
};

/* Rulership restrictions */

enum _rulerships {
  rrStd = 0,  // Standard exoteric
  rrEso = 1,  // Esoteric
  rrHie = 2,  // Hierarchical
  rrExa = 3,  // Exaltation
  rrRay = 4,  // Ray rulership
  rrMax = 5,
};

/* Graphics chart modes */

enum _graphicschart {
  gWheel      = 1,
  gHouse      = 2,
  gGrid       = 3,
  gHorizon    = 4,
  gOrbit      = 5,
  gSector     = 6,
  gCalendar   = 7,
  gDisposit   = 8,
  gEsoteric   = 9,
  gAstroGraph = 10,
  gEphemeris  = 11,
  gTraTraGra  = 12,
  gTraNatGra  = 13,
  gSphere     = 14,
  gWorldMap   = 15,
  gGlobe      = 16,
  gPolar      = 17,
  gBiorhythm  = 18,
#ifdef WIN
  gAspect     = 19,
  gMidpoint   = 20,
  gArabic     = 21,
  gRising     = 22,
  gTraTraTim  = 23,
  gTraTraInf  = 24,
  gTraNatTim  = 25,
  gTraNatInf  = 26,
  gSign       = 27,
  gObject     = 28,
  gHelpAsp    = 29,
  gConstel    = 30,
  gPlanet     = 31,
  gRay        = 32,
  gMeaning    = 33,
  gSwitch     = 34,
  gObscure    = 35,
  gKeystroke  = 36,
  gCredit     = 37,
#endif
};

/* Colors */

enum _colors {
  kReverse = -2,
  kDefault = -1,
  kBlack   = 0,
  kMaroon  = 1,
  kDkGreen = 2,
  kOrange  = 3,
  kDkBlue  = 4,
  kPurple  = 5,
  kDkCyan  = 6,
  kLtGray  = 7,
  kDkGray  = 8,
  kRed     = 9,
  kGreen   = 10,
  kYellow  = 11,
  kBlue    = 12,
  kMagenta = 13,
  kCyan    = 14,
  kWhite   = 15,
  kElement = 16,
  kRay     = 17,
  kNull    = 16,
};

/* Arabic parts */

enum _arabicparts {
  apFor = 0,
  apSpi = 1,
};

/* Calculation methods */

enum _calculationmethod {
  cmSwiss   = 0,
  cmMoshier = 1,
  cmPlacalc = 2,
  cmMatrix  = 3,
  cmNone    = 4,
  cmMax     = 5,
};

/* Draw text formatting flags */

enum _drawtext {
  dtCent   = 0x0,  // Default: Center text at coordinates
  dtLeft   = 0x1,  // Left justify text at X coordinate
  dtTop    = 0x2,  // Y coordinate is top of text
  dtBottom = 0x4,  // Y coordinate is bottom of text
  dtErase  = 0x8,  // Erase background behind text
  dtScale  = 0x10, // Scale text by -Xs character scale
  dtScale2 = 0x20, // Scale text by -XS text scale
};

/* User string parse modes */

enum _parsemode {
  pmMon    = 1,
  pmDay    = 2,
  pmYea    = 3,
  pmTim    = 4,
  pmDst    = 5,
  pmZon    = 6,
  pmLon    = 7,
  pmLat    = 8,
  pmElv    = 9,
  pmLength = 10,
  pmObject = 11,
  pmAspect = 12,
  pmSystem = 13,
  pmSign   = 14,
  pmColor  = 15,
};

/* Termination codes */

enum _terminationcode {
  tcError = -1,
  tcOK    = 0,
  tcFatal = 1,
  tcForce = 2,
};


/*
******************************************************************************
** Macro Functions.
******************************************************************************
*/

#define BLo(w) ((byte)(w))
#define BHi(w) ((byte)((word)(w) >> 8 & 0xFF))
#define WLo(l) ((word)(dword)(l))
#define WHi(l) ((word)((dword)(l) >> 16 & 0xFFFF))
#define WFromBB(bLo, bHi) ((word)BLo(bLo) | (word)((byte)(bHi)) << 8)
#define LFromWW(wLo, wHi) ((dword)WLo(wLo) | (dword)((word)(wHi)) << 16)
#define LFromBB(b1, b2, b3, b4) LFromWW(WFromBB(b1, b2), WFromBB(b3, b4))
#define Rgb(bR, bG, bB) \
  (((dword)(bR)) | ((dword)(bG)<<8) | ((dword)(bB)<<16))
#define RGBR(l) BLo(l)
#define RGBG(l) BHi(l)
#define RGBB(l) ((byte)((dword)(l) >> 16 & 0xFF))
#define ChHex(n) (char)((n) < 10 ? '0' + (n) : 'a' + (n) - 10)

#define Max(v1, v2) ((v1) > (v2) ? (v1) : (v2))
#define Min(v1, v2) ((v1) < (v2) ? (v1) : (v2))
#define NSgn(n) ((n) < 0 ? -1 : (n) > 0)
#define RSgn2(r) ((r) < 0.0 ? -1.0 : 1.0)
#define FOdd(n) ((n) & 1)
#define FBetween(v, v1, v2) ((v) >= (v1) && (v) <= (v2))
#define ChCap(ch) ((ch) >= 'a' && (ch) <= 'z' ? (ch) - 'a' + 'A' : (ch))
#define ChUncap(ch) (FCapCh(ch) ? (ch) - 'A' + 'a' : (ch))
#define FCapCh(ch) ((ch) >= 'A' && (ch) <= 'Z')
#define FUncapCh(ch) ((ch) >= 'a' && (ch) <= 'z')
#define FNumCh(ch) ((ch) >= '0' && (ch) <= '9')
#define NMultDiv(n1, n2, n3) ((int)((long)(n1) * (n2) / (n3)))
#define Ratio(v1, v2, v3) ((v1) + ((v2) - (v1)) * (v3))
#define ZFromS(s) ((real)(((s)-1)*30))
#define SFromZ(r) (((int)(r))/30+1)
#define RFromD(r) ((r)/rDegRad)
#define DFromR(r) ((r)*rDegRad)
#define GFromO(o) ((rDegMax - (o))/10.0)
#define RAbs(r) fabs(r)
#define NAbs(n) abs(n)
#define RFloor(r) floor(r)
#define NFloor(r) ((int)RFloor(r))
#define RFract(r) ((r) - RFloor(r))
#define Sq(n) ((n)*(n))
#define RSqr(r) sqrt(r)
#define RLog(r) log(r)
#define RLog10(r) (RLog(r) / rLog10)
#define RSin(r) sin(r)
#define RCos(r) cos(r)
#define RTan(r) tan(r)
#define RAtn(r) atan(r)
#define RAsin(r) asin(r)
#define RAcos(r) acos(r)
#define RSinD(r) RSin(RFromD(r))
#define RCosD(r) RCos(RFromD(r))
#define RTanD(r) RTan(RFromD(r))
#define NSinD(nR, nD) ((int)((real)(nR)*RSinD((real)nD)))
#define NCosD(nR, nD) ((int)((real)(nR)*RCosD((real)nD)))

#define FItem(obj)    FBetween(obj, 0, cObj)
#define FNorm(obj)    FBetween(obj, 0, oNorm)
#define FCusp(obj)    FBetween(obj, cuspLo, cuspHi)
#define FAngle(obj)   (FCusp(obj) && ((obj)-cuspLo)%3 == 0)
#define FMinor(obj)   (FCusp(obj) && ((obj)-cuspLo)%3 != 0)
#define FUranian(obj) FBetween(obj, uranLo, uranHi)
#define FStar(obj)    FBetween(obj, starLo, starHi)
#define FObject(obj)  ((obj) <= oVes || (obj) >= uranLo)
#define FThing(obj)   ((obj) <= cThing || (obj) >= uranLo)
#define FHelio(obj)   (FNorm(obj) && FObject(obj) && (obj) != oMoo)
#define FAspect(asp)  FBetween(asp, 1, cAspect)
#define FAspect2(asp) FBetween(asp, 1, cAspect2)
#define FSector(s)    FBetween(s, 1, cSector)
#define ChDashF(f)    (f ? '=' : '_')
#define SzNumF(f)     (f ? "1 " : "0 ")
#define ChDst(dst)    (dst == 0.0 ? 'S' : (dst == 1.0 ? 'D' : \
  (dst != dstAuto ? 'A' : (is.fDst ? 'D' : 'S'))))
#define DayInYear(yea) (365-28+DayInMonth(2, yea))
#define FChSwitch(ch) \
  ((ch) == '-' || (ch) == '/' || (ch) == '_' || (ch) == '=' || (ch) == ':')

#define FValidMon(mon) FBetween(mon, 1, 12)
#define FValidDay(day, mon, yea) ((day) >= 1 && (day) <= DayInMonth(mon, yea))
#define FValidYea(yea) FBetween(yea, -32000, 32000)
#define FValidTim(tim) ((tim) > -2.0 && (tim) < 24.0)
#define FValidDst(dst) FValidZon(dst)
#define FValidZon(zon) FBetween(zon, -24.0, 24.0)
#define FValidLon(lon) FBetween(lon, -rDegHalf, rDegHalf)
#define FValidLat(lat) FBetween(lat, -rDegQuad, rDegQuad)
#define FValidAspect(asp) FBetween(asp, 0, cAspect)
#define FValidSystem(n) FBetween(n, 0, cSystem-1)
#define FValidDivision(n) FBetween(n, 1, 2880)
#define FValidOffset(r) FBetween(r, -rDegMax, rDegMax)
#define FValidCenter(obj) (FBetween(obj, oEar, uranHi) && FThing(obj))
#define FValidHarmonic(r) FBetween(r, -32000.0, 32000.0)
#define FValidWheel(n) FBetween(n, 0, WHEELROWS)
#define FValidAstrograph(n) ((n) > 0 && (n) < 90)
#define FValidPart(n) FBetween(n, 1, cPart)
#define FValidDwad(n) FBetween(n, 0, 12)
#define FValidBioday(n) FBetween(n, 1, 199)
#define FValidScreen(n) FBetween(n, 20, 200)
#define FValidMacro(n) FBetween(n, 1, 48)
#define FValidGlyphs(n) FBetween(n, 0, 2232)
#define FValidDecaType(n) FBetween(n, 0, 2)
#define FValidDecaSize(n) FBetween(n, 0, 100)
#define FValidDecaLine(n) FBetween(n, 1, 1000)
#define FValidGrid(n) FBetween(n, 0, cObj)
#define FValidEsoteric(n) FBetween(n, 1, 32000)
#define FValidScale(n) (FBetween(n, 100, MAXSCALE) && (n)%100 == 0)
#define FValidGraphx(x) (FBetween(x, BITMAPX1, BITMAPX) || (x) == 0)
#define FValidGraphy(y) (FBetween(y, BITMAPY1, BITMAPY) || (y) == 0)
#define FValidRotation(n) FBetween(n, 0, rDegMax-rSmall)
#define FValidTilt(n) FBetween(n, -rDegQuad, rDegQuad)
#define FValidColor(n) FBetween(n, 0, cColor-1)
#define FValidColor2(n) FBetween(n, 0, cColor-1 + 2)
#define FValidBmpmode(ch) \
  ((ch) == 'N' || (ch) == 'C' || (ch) == 'V' || (ch) == 'A' || (ch) == 'B')
#define FValidTimer(n) FBetween(n, 1, 32000)

#define DM(d, m) ((d) + (m)/60.0)
#define DMS(d, m, s) (DM(d, m) + (s)/3600.0)
#define ZD(z, d) ((real)(((z)-1)*30) + (d))
#define ZDMS(z, d, m, s) ((real)(((z)-1)*30) + DMS(d, m, s))
#define HM(h, m) ((h) + (m)/60.0)
#define HMS(h, m, s) (HM(h, m) + (s)/3600.0)

#define kSignA(s) kObjA[cuspLo-1+(s)]
#define kSignB(s) kObjB[cuspLo-1+(s)]
#define kModeA(m) kElemA[(m) <= 1 ? (m) : eWat]
#define kModeB(m) kElemB[(m) <= 1 ? (m) : eWat]
#define FInterpretObj(obj) ((obj) <= cObjInt && szMindPart[obj][0])
#define FInterpretAsp(asp) ((asp) > 0 && szInteract[asp][0])
#define szPerson  (ciMain.nam[0] ? ciMain.nam : "This person")
#define szPerson0 (ciMain.nam[0] ? ciMain.nam : "the person")
#define szPerson1 (ciMain.nam[0] ? ciMain.nam : "Person1")
#define szPerson2 (ciTwin.nam[0] ? ciTwin.nam : "Person2")
#define FIgnore(i) ignore[i]
#define FIgnore2(i) ignore2[i]
#define FAllow(i) (us.objRequire < 0 || (i) == us.objRequire)
#define FNoTimeOrSpace(ci) (ci.mon == -1)

#define loop for (;;)
#define inv(v) v = !(v)
#define neg(v) v = -(v)
#define PrintL() PrintCh('\n')
#define PrintL2() PrintSz("\n\n")
#define PrintF(sz) fprintf(file, sz)
#define PrintFSz() fprintf(file, sz)
#define SwapN(n1, n2) (n1)^=(n2)^=(n1)^=(n2)
#define FSwitchF(f) ((((f) | fOr) & !fAnd) ^ fNot)
#define SwitchF(f) f = FSwitchF(f)
#define SwitchF2(f) f = (((f) | (fOr || fNot)) & !fAnd)
#define SetCI(ci, M, D, Y, T, S, Z, O, A) \
  ci.mon = M; ci.day = D; ci.yea = Y; \
  ci.tim = T; ci.dst = S; ci.zon = Z; ci.lon = O; ci.lat = A

#define CONST const
#define PAllocateCore(cb) malloc(cb)
#define DeallocateP(p) free(p)
#ifndef PC
#define chDirSep '/'
#define chSwitch '-'
#ifndef MACOLD
#define ldTime 2440588L
#else
#define ldTime 2416481L
#endif
#else /* PC */
#define chDirSep '\\'
#define chSwitch '/'
#define ldTime 2440588L
#endif /* PC */

#ifdef GRAPH
#ifdef WINANY
#define API FAR PASCAL
#define hdcNil ((HDC)NULL)
#define SetWindowOrg(hdc, x, y) SetWindowOrgEx(hdc, x, y, NULL)
#define SetWindowExt(hdc, x, y) SetWindowExtEx(hdc, x, y, NULL)
#define SetViewportOrg(hdc, x, y) SetViewportOrgEx(hdc, x, y, NULL)
#define SetViewportExt(hdc, x, y) SetViewportExtEx(hdc, x, y, NULL)
#define MoveTo(hdc, x, y) MoveToEx(hdc, x, y, NULL)
#endif

/* Should an object in the outer wheel be restricted? */
#define FProper2(i) (!(us.nRel == rcTransit ? ignore2[i] : ignore[i]))

/* Are particular coordinates on the chart? */
#define FInRect(x, y, x1, y1, x2, y2) \
  ((x) >= (x1) && (x) < (x2) && (y) >= (y1) && (y) < (y2))
#define FOnWin(X, Y) FInRect((X), (Y), 0, 0, gs.xWin, gs.yWin)

/* Get a coordinate based on chart radius, a fraction, and (co)sin value. */
#define POINT1(U, R, S) ((int)(((U)+1.4)*(R)*(S)))
#define POINT2(U, R, S) ((int)(((U)-0.3)*(R)*(S)))

/* Determine (co)sin factors based on zodiac angle and chart orientation. */
#define PX(A) RCosD(A)
#define PY(A) RSinD(A)
#define PZ(A) PlaceInX(A)

/* Compute Mollewide projection in pixel scale given latitude. */
#define NMollewide(y) \
  ((int)(RSqr((real)(Sq(180*nScl) - 4*Sq((y)*nScl))) + rRound))

/* Do settings indicate the current chart should have the info sidebar? */
#define fSidebar ((gi.nMode == gWheel || gi.nMode == gHouse || \
  gi.nMode == gSector || gi.nMode == gSphere) && gs.fText && !us.fVelocity)

/* Is the current chart most properly displayed as a square graphic? */
#define fSquare \
  (gi.nMode == gWheel || gi.nMode == gHouse || gi.nMode == gGrid || \
  (gi.nMode == gHorizon && us.fPrimeVert) || gi.nMode == gDisposit || \
  gi.nMode == gOrbit || gi.nMode == gSector || gi.nMode == gSphere || \
  gi.nMode == gGlobe || gi.nMode == gPolar)

/* Does the current chart have to be displayed in a map rectangle? */
#define fMap \
  (gi.nMode == gAstroGraph || gi.nMode == gWorldMap)

/* Do settings indicate the current chart should have an outer border? */
#define fDrawBorder \
  ((gs.fBorder || gi.nMode == gGrid) && gi.nMode != gTraTraGra && \
  gi.nMode != gTraNatGra && gi.nMode != gGlobe && gi.nMode != gPolar && \
  (gi.nMode != gWorldMap || !gs.fMollewide))

/* Do settings indicate current chart should have chart info at its bottom? */
#define fDrawText \
  (gs.fText && gi.nMode != gCalendar && gi.nMode != gWorldMap && \
  gi.nMode != gGlobe && gi.nMode != gPolar && ((gi.nMode != gWheel && \
  gi.nMode != gHouse && gi.nMode != gSector && gi.nMode != gSphere) || \
  us.fVelocity))
#endif /* GRAPH */


/*
******************************************************************************
** Type Definitions.
******************************************************************************
*/

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned long dword;
typedef long word4;
typedef double real;
typedef unsigned char uchar;
typedef unsigned int uint;
typedef int flag;
typedef byte * lpbyte;

#ifdef GRAPH
typedef unsigned long KV;
typedef int KI;
#endif /* GRAPH */

typedef struct _StrLook {
  char *sz;
  int isz;
} StrLook;

typedef struct _PT3R {
  real x;
  real y;
  real z;
} PT3R;

typedef struct _GridInfo {
  byte n[objMax][objMax];
  int  v[objMax][objMax];
} GridInfo;

typedef struct _CrossInfo {
  real lat[MAXCROSS];
  real lon[MAXCROSS];
  int obj1[MAXCROSS];
  int obj2[MAXCROSS];
} CrossInfo;

typedef struct _InDayInfo {
  short source;
  short aspect;
  int dest;      /* Larger type because may store fraction of degree */
  char mon;
  char day;
  short yea;
  real time;
  char sign1;
  char sign2;
  char ret1;
  char ret2;
} InDayInfo;

typedef word *TransGraInfo[objMax][objMax][cAspect];

typedef struct _UserSettings {

  /* Chart types */
  flag fListing;       /* -v */
  flag fWheel;         /* -w */
  flag fGrid;          /* -g */
  flag fAspList;       /* -a */
  flag fMidpoint;      /* -m */
  flag fHorizon;       /* -Z */
  flag fOrbit;         /* -S */
  flag fSector;        /* -l */
  flag fInfluence;     /* -j */
  flag fEsoteric;      /* -7 */
  flag fAstroGraph;    /* -L */
  flag fCalendar;      /* -K */
  flag fInDay;         /* -d */
  flag fInDayInf;      /* -D */
  flag fEphemeris;     /* -E */
  flag fTransit;       /* -t */
  flag fTransitInf;    /* -T */
  flag fInDayGra;      /* -B */
  flag fTransitGra;    /* -V */

  /* Chart suboptions */
  flag fVelocity;      /* -v0 */
  flag fWheelReverse;  /* -w0 */
  flag fGridConfig;    /* -g0 */
  flag fGridMidpoint;  /* -gm */
  flag fAppSep;        /* -ga */
  flag fParallel;      /* -gp */
  flag fAspSummary;    /* -a0 */
  flag fMidSummary;    /* -m0 */
  flag fMidAspect;     /* -ma */
  flag fPrimeVert;     /* -Z0 */
  flag fHorizonSearch; /* -Zd */
  flag fSectorApprox;  /* -l0 */
  flag fInfluenceSign; /* -j0 */
  flag fLatitudeCross; /* -L0 */
  flag fCalendarYear;  /* -Ky */
  flag fInDayMonth;    /* -dm */
  flag fInDayYear;     /* -dy */
  flag fGraphAll;      /* -B0 */
  flag fArabicFlip;    /* -P0 */

  /* Table chart types */
  flag fCredit;        /* -Hc */
  flag fSwitch;        /* -H  */
  flag fSwitchRare;    /* -Y  */
  flag fKeyGraph;      /* -HX */
  flag fSign;          /* -HC */
  flag fObject;        /* -HO */
  flag fAspect;        /* -HA */
  flag fConstel;       /* -HF */
  flag fOrbitData;     /* -HS */
  flag fRay;           /* -H7 */
  flag fMeaning;       /* -HI */

  /* Main flags */
  flag fLoop;        /* -Q */
  flag fSidereal;    /* -s */
  flag fCusp;        /* -C */
  flag fUranian;     /* -u */
  flag fProgress;    /* Are we doing a -p progressed chart?           */
  flag fInterpret;   /* Is -I interpretation switch in effect?        */
  flag fHouse3D;     /* -c3 */
  flag fAspect3D;    /* -A3 */
  flag fAspectLat;   /* -Ap */
  flag fDecan;       /* -3 */
  int nDwad;         /* -4 */
  flag fFlip;        /* -f */
  flag fGeodetic;    /* -G */
  flag fVedic;       /* -J */
  flag fNavamsa;     /* -9 */
  flag fEphemFiles;  /* -b */
  flag fWriteFile;   /* -o */
  flag fAnsiColor;   /* -k */
  flag fGraphics;    /* -X */

  /* Main subflags */
  flag fNoSwitches;
  flag fLoopInit;    /* -Q0 */
  flag fSeconds;     /* -b0 */
  flag fSwissMosh;   /* -bs */
  flag fPlacalcAst;  /* -ba */
  flag fPlacalcPla;  /* -bp */
  flag fMatrixPla;   /* -bm */
  flag fMatrixStar;  /* -bU */
  flag fEquator;     /* -sr */
  flag fSolarArc;    /* -p0 */
  flag fWritePos;    /* -o0 */
  flag fAnsiChar;    /* -k0 */
  flag fTextHTML;    /* -kh */
  flag fSolarWhole;  /* -10 */

  /* Rare flags */
  flag fTruePos;     /* -YT */
  flag fTopoPos;     /* -YV */
  flag fBarycenter;  /* -Yh */
  flag fTrueNode;    /* -Yn */
  flag fEuroDate;    /* -Yd */
  flag fEuroTime;    /* -Yt */
  flag fEuroDist;    /* -Yv */
  flag fRound;       /* -Yr */
  flag fSmartCusp;   /* -YC */
  flag fSmartSave;   /* -YO */
  flag fClip80;      /* -Y8 */
  flag fWriteOld;    /* -Yo */
  flag fHouseAngle;  /* -Yc */
  flag fPolarAsc;    /* -Yp */
  flag fObjRotWhole; /* -Y10 */
  flag fIgnoreSign;  /* -YR0 */
  flag fIgnoreDir;   /* -YR0 */
  flag fNoWrite;     /* -0o */
  flag fNoRead;      /* -0i */
  flag fNoQuit;      /* -0q */
  flag fNoGraphics;  /* -0X */

  /* Value settings */
  int   nAspectSort;  /* -a */
  int   nEphemYears;  /* -Ey */
  int   nEphemRate;   /* -E0 */
  int   nEphemFactor; /* -E0 */
  int   nArabic;      /* -P */
  int   nRel;         /* What relationship chart are we doing, if any? */
  int   nHouseSystem; /* -c */
  int   nAsp;         /* -A */
  int   objCenter;    /* -h */
  int   nStar;        /* -U */
  real  rHarmonic;    /* Harmonic chart value passed to -x switch.     */
  int   objOnAsc;     /* Planet value passed to -1 or -2 switch.       */
  int   objRequire;   /* Required object passed to -RO switch.         */
  int   dayDelta;     /* -+, -- */
  int   nDegForm;     /* -s */
  int   nDivision;    /* -d */
  int   nScreenWidth; /* -I */
  real  dstDef;       /* -z0 */
  real  zonDef;       /* -z */
  real  lonDef;       /* -zl */
  real  latDef;       /* -zl */
  real  elvDef;       /* -zv */
  char *namDef;       /* -zj */
  char *locDef;       /* -zj */

  /* Value subsettings */
  int   nWheelRows;      /* Number of rows per house to use for -w wheel. */
  int   nAstroGraphStep; /* Latitude step rate passed to -L switch.       */
  int   nArabicParts;    /* Arabic parts to include value passed to -P.   */
  real  rZodiacOffset;   /* Position shifting value passed to -s switch.  */
  real  rProgDay;        /* Progression day value passed to -pd switch.   */
  int   nRatio1;         /* Chart ratio factors passed to -rc or -rm.     */
  int   nRatio2;
  int   nScrollRow;      /* -YQ */
  int   cSequenceLine;   /* -Yq */
  long  lTimeAddition;   /* -Yz */
  int   objRot1;         /* -Y1 */
  int   objRot2;         /* -Y1 */
  int   nArabicNight;    /* -YP */
  int   nBioday;         /* -Yb */
  int   nSignDiv;        /* -YRd */
} US;

typedef struct _InternalSettings {
  flag fHaveInfo;     /* Do we need to prompt user for chart info?         */
  flag fDst;          /* Has Daylight Saving Time been autodetected?       */
  flag fProgress;     /* Are we doing a chart involving progression?       */
  flag fReturn;       /* Are we doing a transit chart for returns?         */
  flag fMult;         /* Have we already printed at least one text chart?  */
  flag fSeconds;      /* Do we print locations to nearest second?          */
  flag fSzPersist;    /* Are parameter strings persistent when processing? */
  flag fSzInteract;   /* Are we in middle of chart so some setting fixed?  */
  flag fNoEphFile;    /* Have we already had a ephem file not found error? */
  char *szProgName;   /* The name and path of the executable running.      */
  char *rgszLine[9];  /* The command lines to run before each -Yq chart.   */
  char *szFileScreen; /* The file to send text output to as passed to -os. */
  char *szFileOut;    /* The output chart filename string as passed to -o. */
  char **rgszComment; /* Points to any comment strings after -o filename.  */
  int cszComment;     /* The number of strings after -o that are comments. */
  int cchCol;         /* The current column text charts are printing at.   */
  int cchRow;         /* The current row text charts have scrolled to.     */
  int nHTML;          /* HTML text output context mode for -kh.            */
  int nWheelRows;     /* Actual number of rows per house to use for -w.    */
  real rSid;          /* Sidereal offset degrees to be added to locations. */
  real JD;            /* Fractional Julian day for current chart.          */
  real JDp;           /* Julian day that a progressed chart indicates.     */
  FILE *S;  /* File to write text to.   */
  real T;   /* Julian time for chart.   */
  real MC;  /* Midheaven at chart time. */
  real Asc; /* Ascendant at chart time. */
  real RA;  /* Right ascension at time. */
  real OB;  /* Obliquity of ecliptic.   */
} IS;

typedef struct _ChartInfo {
  int mon;   /* Month            */
  int day;   /* Day              */
  int yea;   /* Year             */
  real tim;  /* Time in hours    */
  real dst;  /* Daylight offset  */
  real zon;  /* Time zone        */
  real lon;  /* Longitude        */
  real lat;  /* Latitude         */
  char *nam; /* Name for chart   */
  char *loc; /* Name of location */
} CI;

typedef struct _ChartPositions {
  real obj[objMax];   /* The zodiac positions.    */
  real alt[objMax];   /* Ecliptic declination.    */
  real dir[objMax];   /* Retrogradation velocity. */
  real cusp[cSign+1]; /* House cusp positions.    */
  int house[objMax];  /* House each object is in. */
} CP;

#ifdef GRAPH
typedef struct _GraphicsSettings {
  flag fBitmap;     /* Are we creating a bitmap file (-Xb set).         */
  flag fPS;         /* Are we generating a PostScript file (-Xp set).   */
  flag fMeta;       /* Are we generating a metafile graphic (-XM set).  */
  flag fWire;       /* Are we generating a wireframe graphic (-X3 set). */
  flag fColor;      /* Are we drawing a color chart (-Xm not set).      */
  flag fInverse;    /* Are we drawing in reverse video (-Xr set).       */
  flag fRoot;       /* Are we drawing on the X11 background (-XB set).  */
  flag fText;       /* Are we printing chart info on chart (-XT set).   */
  flag fFont;       /* Are we simulating fonts in charts (-XM0 set).    */
  flag fAlt;        /* Are we drawing in alternate mode (-Xi set).      */
  flag fBorder;     /* Are we drawing borders around charts (-Xu set).  */
  flag fLabel;      /* Are we labeling objects in charts (-Xl not set). */
  flag fJetTrail;   /* Are we not clearing screen on updates (-Xj set). */
  flag fConstel;    /* Are we drawing maps as constellations (-XF set). */
  flag fSouth;      /* Are we focus on south hemisphere (-XX0/XP0 set). */
  flag fMollewide;  /* Are we drawing maps scaled correctly (-XW0 set). */
  flag fEquator;    /* Are we showing equator on maps/globes (-Xe set). */
  flag fAllStar;    /* Are we drawing all sefstars.txt stars (-XU set). */
  flag fHouseExtra; /* Are we showing additional house info (-XC set).  */
  flag fPrintMap;   /* Are we printing globe names on draw (-XPv set).  */
  flag fKeepSquare; /* Are we preserving chart aspect ratio (-XQ set).  */
  flag fAnimMap;    /* Are we animating map instead of time (-XN set).  */
  int xWin;         /* Current size of graphic chart (-Xw).      */
  int yWin;
  int nAnim;        /* Current animation mode jump rate (-Xn).   */
  int nScale;       /* Current character scale factor (-Xs).     */
  int nScaleText;   /* Current graphics text scale factor (-XS). */
  int objLeft;      /* Current object to place on Asc (-X1).     */
  real rRot;        /* Current rotation degree of globe.         */
  real rTilt;       /* Current vertical tilt of rotating globe.  */
  char chBmpMode;   /* Current bitmap file type (-Xb).           */
  int nOrient;      /* PostScript paper orientation indicator.   */
  real xInch;       /* PostScript horizontal paper size inches.  */
  real yInch;       /* PostScript vertical paper size inches.    */
  char *szDisplay;  /* Current X11 display name (-Xd).           */
  int nDecaType;    /* Type of wheel chart decoration (-YXv).    */
  int nDecaSize;    /* Size of wheel chart decoration (-YXv).    */
  int nDecaLine;    /* Lines in wheel chart decoration (-YXv).   */
  int nGridCell;    /* Number of cells in -g grids (-YXg).       */
  real rspace;      /* Radius in AU of -S orbit chart (-YXS).    */
  int cspace;       /* Number of -S orbit trails allowed (-YXj). */
  int zspace;       /* Height diff of each orbit trail (-YXj0).  */
  int nRayWidth;    /* Column width in -7 esoteric chart (-YX7). */
  int nGlyphs;      /* Settings for what gylphs to use (-YXG).   */
  flag fColorSign;  /* More color for sign boundaries. (-YXk).   */
  flag fColorHouse; /* More color for house boundaries. (-YXk0). */
} GS;

typedef struct _GraphicsInternal {
  int nMode;            /* Current type of chart to create.           */
  flag fMono;           /* Is this a monochrome display.              */
  int kiCur;            /* Current color drawing with.                */
  lpbyte bm;            /* Pointer to allocated memory.               */
  int cbBmpRow;         /* Horizontal size of bitmap array in memory. */
  char *szFileOut;      /* Current name of bitmap file (-Xo).         */
  FILE *file;           /* Actual file handle writing graphics to.    */
  real rAsc;            /* Degree to be at left edge in wheel charts. */
  flag fFile;           /* Are we making a graphics file.             */
  flag fDidSphere;      /* Has a chart sphere been drawn once yet?    */
  int nScale;           /* Scale ratio, i.e. percentage / 100.        */
  int nScaleText;       /* Text scale ratio, i.e. percentage / 100.   */
  int nScaleT;          /* Relative scale to draw chart text at.      */
  int nGridCell;        /* Actual number of cells in -g grids.        */
  int nPenWid;          /* Pen width to use when creating metafiles.  */
  KI kiOn;              /* Foreground color. */
  KI kiOff;             /* Background color. */
  KI kiLite;            /* Hilight color.    */
  KI kiGray;            /* A "dim" color.    */
  int xOffset;          /* Viewport origin.                           */
  int yOffset;
  int xTurtle;          /* Current coordinates of drawing pen.        */
  int yTurtle;
  int xPen;             /* Cached coordinates where last line ended.  */
  int yPen;
  PT3R *rgspace;        /* List of orbit trail coordinates (-S -X).   */
  int ispace;           /* Index of most recent coordinate (-S -X).   */
  int cspace;           /* Coordinates within table so far (-S -X).   */
#ifdef X11
  Display *disp;        /* The opened X11 display (-Xd). */
  GC gc, pmgc;
  Pixmap pmap, icon;
  Window wind, root;
  int screen;
  int depth;            /* Number of active color bits.  */
#endif
#ifdef PS               /* Variables used by the PostScript generator. */
  flag fEps;            /* Are we doing Encapsulated PostScript.    */
  int cStroke;          /* Number of items drawn without flushing.  */
  flag fLineCap;        /* Are line ends rounded instead of square. */
  int nDash;            /* How much long are dashes in lines drawn. */
  int nFont;            /* What system font are we drawing text in. */
  real rLineWid;        /* How wide are lines, et al, drawn with.   */
#endif
#ifdef META             /* Variables used by the metafile generator.  */
  word *pwMetaCur;      /* Current mem position when making metafile. */
  word *pwPoly;         /* Position for start of current polyline.    */
  long cbMeta;
  KI kiLineAct;         /* Desired and actual line color. */
  KI kiLineDes;
  KI kiFillAct;         /* Desired and actual fill color. */
  KI kiFillDes;
  int nFontAct;         /* Desired and actual text font.  */
  int nFontDes;
  KI kiTextAct;         /* Desired and actual text color. */
  KI kiTextDes;
  int nAlignAct;        /* Desired/actual text alignment. */
  int nAlignDes;
#endif
#ifdef WIRE             /* Variables used by the wireframe generator. */
  word *pwWireCur;      /* Current mem position when doing wireframe. */
  long cbWire;
  int cWire;            /* Number of lines in wireframe file.         */
  KI kiInFile;          /* Actual line color currently in file.       */
  int zDefault;         /* Default elevation for 2D drawing.          */
#endif
#ifdef MACG
  WindowPtr wpAst;
  Rect rcDrag;
  Rect rcBounds;
#endif
} GI;
#endif /* GRAPH */

typedef struct _ArabicInfo {
  char *form;                 /* The formula to calculate it. */
  char *name;                 /* The name of the Arabic part. */
} AI;

typedef struct _ElementTable {
  int coSum;            /* Total objects considered.          */
  int coHemi;           /* Number that can be in hemispheres. */
  int coSign[cSign];    /* Number of objects in each sign.    */
  int coHouse[cSign];   /* Number of objects in each house.   */
  int coElemMode[4][3]; /* Objects in each elem/mode combo.   */
  int coElem[4];        /* Objects in each element.           */
  int coMode[3];        /* Objects in each sign mode.         */
  int coModeH[3];       /* Objects in each house mode.        */
  int coYang;           /* Objects in Fire/Air signs.         */
  int coYin;            /* Objects in Earth/Water signs.      */
  int coLearn;          /* Objects in first six signs.        */
  int coShare;          /* Objects in last six signs.         */
  int coAsc;            /* Objects in Eastern houses.         */
  int coDes;            /* Objects in Western houses.         */
  int coMC;             /* Objects in Southern houses.        */
  int coIC;             /* Objects in Northern houses.        */
} ET;

typedef struct _OrbitalElements {
  real ma0, ma1, ma2; /* Mean anomaly.           */
  real ec0, ec1, ec2; /* Eccentricity.           */
  real sma;           /* Semi-major axis.        */
  real ap0, ap1, ap2; /* Argument of perihelion. */
  real an0, an1, an2; /* Ascending node.         */
  real in0, in1, in2; /* Inclination.            */
} OE;

#ifdef WIN
#define nScrollDiv 24
#define nScrollPage 6
#define cchSzMaxFile 128
#define szFileTempCore "astrolog.tmp"
#define szFileAutoCore "astrolog.bmp"

typedef struct _WindowInternal {
  HINSTANCE hinst; /* Instance of the Astrolog window class.    */
  HWND hwndMain;   /* The outer created frame window.           */
  HWND hwnd;       /* The current window being dealt with.      */
  HMENU hmenu;     /* The Astrolog main menu bar.               */
  HACCEL haccel;   /* Keyboard accelerator or shortcut table.   */
  HDC hdc;         /* The current DC bring drawn upon.          */
  HDC hdcPrint;    /* The current DC being printed upon.        */
  HWND hwndAbort;  /* Window of the printing abort dialog.      */
  HPEN hpen;       /* Pen with the current line color.          */
  HBRUSH hbrush;   /* Fill if any with the current color.       */
  HFONT hfont;     /* Font of current text size being printed.  */
  HANDLE hMutex;   /* To ensure output file isn't already open. */
  size_t lTimer;   /* Identifier for the animation timer.       */
  short xScroll;   /* Horizontal & vertical scrollbar position. */
  short yScroll;
  short xClient;   /* Horizontal & vertical window size. */
  short yClient;
  int xChar;       /* Horizontal & vertical font character size. */
  int yChar;
  int xMouse;      /* Horizontal & vertical mouse position. */
  int yMouse;
  WORD wCmd;       /* The currently invoked menu command.        */
  LPARAM lParamRC; /* Coordinates where right click originated.  */
  int nMode;       /* New chart type to switch to if any.        */
  flag fMenu;      /* Do we need to repaint the menu bar?        */
  flag fMenuAll;   /* Do we need to redetermine all menu checks? */
  flag fRedraw;    /* Do we need to redraw the screen?           */
  flag fCast;      /* Do we need to recast the chart positions?  */
  flag fAbort;     /* Did the user cancel printing in progress?  */
  int nDlgChart;   /* Which chart to set in Open or Info dialog. */

  /* Window user settings. */
  flag fPause;        /* Is animation paused?                   */
  flag fBuffer;       /* Are we drawing updates off screen?     */
  flag fHourglass;    /* Bring up hourglass cursor on redraws?  */
  flag fChartWindow;  /* Does chart change cause window resize? */
  flag fWindowChart;  /* Does window resize cause chart change? */
  flag fNoUpdate;     /* Do we not automatically update screen? */
  flag fAutoSave;     /* Are we saving chart after win draw?    */
  flag fAutoSaveNum;  /* Autosave charts are incremental files? */
  flag fAutoSaveWire; /* Autosave wireframe instead of bitmap?  */
  int nAutoSaveNum;   /* Number of incremental bitmap save.     */
  KI kiPen;           /* The current pen scribble color.        */
  int nDir;           /* Animation step factor and direction.   */
  UINT nTimerDelay;   /* Milliseconds between animation draws.  */
} WI;
#endif

#ifdef WCLI
typedef struct _WindowInternal {
  HINSTANCE hinst; /* Instance of the Astrolog window class. */
  HWND hwndMain;   /* The outer created frame window.        */
  HWND hwnd;       /* The current window being dealt with.   */
  HDC hdc;         /* The current DC bring drawn upon.       */
  HPEN hpen;       /* Pen with the current line color.       */
  HBRUSH hbrush;   /* Fill if any with the current color.    */
  short xClient;   /* Horizontal & vertical window size.     */
  short yClient;
  flag fDoRedraw;
  flag fDoResize;
  flag fWndclass;
} WI;
#endif

#include "extern.h"

/* astrolog.h */
