/* 
   Copyright (c) 1991-1999 Thomas T. Wetmore IV

   Permission is hereby granted, free of charge, to any person
   obtaining a copy of this software and associated documentation
   files (the "Software"), to deal in the Software without
   restriction, including without limitation the rights to use, copy,
   modify, merge, publish, distribute, sublicense, and/or sell copies
   of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/
/* modified 05 Jan 2000 by Paul B. McBride (pmcbride@tiac.net) */
/*=============================================================
 * main.c -- Main program of LifeLines
 * Copyright(c) 1992-95 by T.T. Wetmore IV; all rights reserved
 *   2.3.4 - 24 Jun 93    2.3.5 - 07 Aug 93
 *   2.3.6 - 02 Oct 93    3.0.0 - 11 Oct 94
 *   3.0.1 - 11 Oct 93    3.0.2 - 01 Jan 95
 *   3.0.3 - 02 Jul 96
 *===========================================================*/

#include "sys_inc.h"
#ifdef OS_LOCALE
#include <locale.h>
#endif
#include "llstdlib.h"
#include "screen.h"
#include "btree.h"
#include "table.h"
#include "translat.h"
#include "gedcom.h"
#include "liflines.h"
#include "arch.h"
#include "lloptions.h"

#include "llinesi.h"

#ifdef HAVE_GETOPT
#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif /* HAVE_GETOPT_H */
#endif /* HAVE_GETOPT */

/*********************************************
 * external variables (no header)
 *********************************************/

extern STRING idldir, nodbse, crdbse, nocrdb, iddbse, usage;
extern STRING mtitle;

extern INT csz_indi, icsz_indi;
extern INT csz_fam, icsz_fam;
extern INT csz_sour, icsz_sour;
extern INT csz_even, icsz_even;
extern INT csz_othr, icsz_othr;
extern INT winx, winy;

extern int opterr;
extern BTREE BTR;

/*********************************************
 * required global variables
 *********************************************/

/* Finnish language support modifies the soundex codes for names, so
 * a database created with this support is not compatible with other
 * databases. 
 *
 * define FINNISH for Finnish Language support
 *
 * define FINNISHOPTION to have a runtime option -F which will enable
 * 	  	Finnish language support, but you risk corrupting your
 * 	  	database if you make modifications while in the wrong mode.
 */

#ifdef FINNISH
# ifdef FINNISHOPTION
int opt_finnish  = FALSE;/* Finnish Language sorting order if TRUE */
static STRING usage = (STRING) "lines [-akrwfmntcuFy] [database]   # Use -F for Finnish database";
# else
int opt_finnish  = TRUE;/* Finnish Language sorting order if TRUE */
static STRING usage = (STRING) "lines [-akrwfmntcuy] [database]   # Finnish database";
# endif
#else
int opt_finnish  = FALSE;/* Finnish Language sorting order id disabled*/
static STRING usage = (STRING) "lines [-akrwfmntcuy] [database]";
#endif

BOOLEAN opt_nocb  = FALSE;	/* no cb. data is displayed if TRUE */
BOOLEAN alloclog  = FALSE;	/* alloc/free debugging */
BOOLEAN keyflag   = TRUE;	/* show key values */
BOOLEAN readonly  = FALSE;	/* database is read only */
BOOLEAN forceopen = FALSE;	/* force database status to 0 */
BOOLEAN writeable = FALSE;	/* database must be writeable */
BOOLEAN cursesio  = TRUE;	/* use curses i/o */
BOOLEAN alldone   = FALSE;	/* completion flag */
BOOLEAN progrunning = FALSE;	/* program is running */
BOOLEAN progparsing = FALSE;	/* program is being parsed */
BOOLEAN traceprogram = FALSE;	/* trace program */
BOOLEAN traditional = TRUE;	/* use traditional family rules */
BOOLEAN selftest = FALSE; /* selftest rules (ignore paths) */
BOOLEAN showusage = FALSE;	/* show usage */
STRING btreepath = NULL;		/* database path given by user */
STRING readpath = NULL;		/* database path used to open */

/*********************************************
 * local function prototypes
 *********************************************/

static void show_open_error(INT dberr);
static BOOLEAN trytocreate(STRING);
static void platform_init(void);
static int open_database(STRING dbpath, STRING dbactual);

/*********************************************
 * local function definitions
 * body of module
 *********************************************/

/*==================================
 * main -- Main routine of LifeLines
 *================================*/
int
main (INT argc,
      char **argv)
{
	extern char *optarg;
	extern int optind;
	char * msg;
	int c,code=1;
	STRING dbpath=NULL; /* database (path) requested */
	STRING dbactual=NULL; /* database (path) found */

#ifdef OS_LOCALE
	setlocale(LC_ALL, "");
#endif

	/* catch any fault, so we can close database */
	set_signals();

	/* Parse Command-Line Arguments */
	opterr = 0;	/* turn off getopt's error message */
	while ((c = getopt(argc, argv, "akrwfmntc:Fu:y")) != -1) {
		switch (c) {
		case 'c':	/* adjust cache sizes */
			while(optarg && *optarg) {
				if(isalpha(*optarg) && isupper(*optarg))
					*optarg = tolower(*optarg);
				if(*optarg == 'i') {
					sscanf(optarg+1, "%d,%d", &csz_indi, &icsz_indi);
				}
				else if(*optarg == 'f') {
					sscanf(optarg+1, "%d,%d", &csz_fam, &icsz_fam);
				}
				else if(*optarg == 's') {
					sscanf(optarg+1, "%d,%d", &csz_sour, &icsz_sour);
				}
				else if(*optarg == 'e') {
					sscanf(optarg+1, "%d,%d", &csz_even, &icsz_even);
				}
				else if((*optarg == 'o') || (*optarg == 'x')) {
					sscanf(optarg+1, "%d,%d", &csz_othr, &icsz_othr);
				}
				optarg++;
				while(*optarg && isdigit(*optarg)) optarg++;
				if(*optarg == ',') optarg++;
				while(*optarg && isdigit(*optarg)) optarg++;
			}
			break;
#ifdef FINNISH
# ifdef FINNISHOPTION
		case 'F':	/* Finnish sorting order [toggle] */
			opt_finnish = !opt_finnish;
			/*
			TO DO - need to mark Finnish databases, as 
			name records are not interoperable, because of
			different soundex encoding
			2001/02/17, Perry Rapp
			*/
			break;
# endif
#endif
		case 'a':	/* debug allocation */
			alloclog = TRUE;
			break;
		case 'k':	/* don't show key values */
			keyflag = FALSE;
			break;
		case 'r':	/* request for read only access */
			readonly = TRUE;
			break;
		case 'w':	/* request for write access */
			writeable = TRUE;
			break;
		case 'm':
			cursesio = FALSE;
			break;
		case 'f':	/* force database open in all cases */
			forceopen = TRUE;
			break;
		case 'n':	/* use non-traditional family rules */
			traditional = FALSE;
			break;
		case 't': /* show lots of trace statements for debugging */
			traceprogram = TRUE;
			break;
		case 'u': /* specify screen dimensions */
			sscanf(optarg, "%d,%d", &winx, &winy);
			break;
		case 'y': /* only look in current path for databases */
			selftest = TRUE;
			break;
		case '?':
			showusage = TRUE;
			goto usage;
			break;
		}
	}

	/* Initialize Curses UI */
	initscr();
	platform_init();
	noecho();
	set_displaykeys(keyflag);
	/* initialize curses interface */
	if (!init_screen())
		goto finish;
	/* initialize non-db dependent options (environment stuff) */
	if (!init_lifelines_global(&msg)) {
		llwprintf("%s", msg);
		goto finish;
	}

	/* Validate Command-Line Arguments */
	if (readonly && writeable) {
		llwprintf("Select at most one of -r and -w options.");
		goto finish;
	}
	c = argc - optind;
	if (c > 1) {
		showusage = TRUE;
		goto usage;
	}

	/* Get Database Name (Prompt or Command-Line) */
	if (c <= 0) {
		/* ask_for_lldb returns static buffer, we save it below */
		dbpath = ask_for_lldb(idldir, "enter path: ", lloptions.lldatabases);
		if (ISNULL(dbpath)) {
			llwprintf(iddbse);
			goto finish;
		}
	} else {
		dbpath = (unsigned char *)argv[optind];
		if (ISNULL(btreepath)) {
			showusage = TRUE;
			goto usage;
		}
	}
	/* we will own the memory in dbpath */
	dbpath = strsave(dbpath);

	
	/* search for database */
	// TO DO dbpath = find_database(btreepath); 
	/* search for file in lifelines path */
	dbactual = filepath(dbpath, "r", lloptions.lldatabases, NULL);
	if (!dbactual) dbactual = dbpath;

	/* Open Database */
	if (!open_database(dbpath, dbactual)) goto finish;

	/* Start Program */
	init_lifelines_db();
	init_show_module();
	while (!alldone)
		main_menu();
	close_lifelines();
	code=0;

/*
 * MTE:  Here's were we would free() or deallocate() the dup'd strings
 * returned by strsave() and assigned to lldatabases and btreepath
 */

finish:
	term_screen();
	if (code) /* if error, give user a second to read it */
		sleep(1);
	/* Terminate Curses UI */
	endwin();

usage:
	/* Display Command-Line Usage Help */
	if (showusage) puts(usage);

	/* Exit */
	return(code);
}
/*==========================================
 * trytocreate -- Try to create new database
 *========================================*/
static BOOLEAN
trytocreate (STRING path)
{
	if (!ask_yes_or_no_msg(nodbse, crdbse)) return FALSE;

	if (!(BTR = openbtree(path, TRUE, !readonly))) {
		mprintf_error(nocrdb, path);
		return FALSE;
	}
	initxref();
	return TRUE;
}
/*===================================================
 * show_open_error -- Display database opening error
 *=================================================*/
static void
show_open_error (INT dberr)
{
	char buffer[256];
	describe_dberror(dberr, buffer, ARRSIZE(buffer));
	llwprintf(buffer);
	sleep(5);
}
/*==================================================
 * platform_init -- platform specific initialization
 *================================================*/
static void
platform_init (void)
{
#ifdef WIN32
	char buffer[80];
	sprintf(buffer, mtitle, get_lifelines_version(sizeof(buffer)-1-strlen(mtitle)));
	wtitle(buffer);
#endif
}
/*==================================================
 * is_unadorned_directory -- is it a bare directory name,
 *  with no subdirectories ?
 * Created: 2001/01/24, Perry Rapp
 *================================================*/
static BOOLEAN
is_unadorned_directory (STRING path)
{
	for ( ; *path; path++) {
		if (is_dir_sep(*path))
			return FALSE;
	}
	return TRUE;
}
/*==================================================
 * open_database_impl -- open database
 * dbpath: database to report
 * dbactual: actual database path (may be relative also)
 * If the llwprintfs were moved out of here, this could
 * be reused by non-curses versions
 *================================================*/
static BOOLEAN
open_database_impl (void)
{
	int c;

	if (forceopen) {
		/*
		Forcefully alter reader/writer count to 0.
		But do check keyfile2 checks first (in case it is a
		database from a different alignment).
		*/
		char scratch[200];
		FILE *fp;
		KEYFILE1 kfile1;
		KEYFILE2 kfile2;
		struct stat sbuf;
		sprintf(scratch, "%s/key", readpath);
		if (stat(scratch, &sbuf) || !S_ISREG(sbuf.st_mode)) {
			llwprintf("Database error -- ");
			llwprintf("could not open, read or write the key file.");
			return FALSE;
		}
		if (!(fp = fopen(scratch, LLREADBINARYUPDATE)) ||
		    fread(&kfile1, sizeof(kfile1), 1, fp) != 1) {
			llwprintf("Database error -- ");
			llwprintf("could not open, read or write the key file.");
			return FALSE;
		}
		if (fread(&kfile2, sizeof(kfile2), 1, fp) == 1) {
			if (!validate_keyfile2(&kfile2)) {
				llwprintf("Database error -- ");
				llwprintf("Invalid keyfile!");
				return FALSE;
			}
		}
		kfile1.k_ostat = 0;
		rewind(fp);
		if (fwrite(&kfile1, sizeof(kfile1), 1, fp) != 1) {
			llwprintf("Database error -- ");
			llwprintf("could not open, read or write the key file.");
			printf("Cannot properly write the new key file.\n");
			fclose(fp);
	 		return FALSE;
		}
		fclose(fp);
		/* okay, cleared reader/writer count
		now fall through to normal opening code */
	}
	if (!(BTR = openbtree(readpath, FALSE, !readonly))) {
		switch (bterrno) {
		case BTERR_NODB:
		case BTERR_NOKEY:	{
				/* error was only that db doesn't exist */
				/* unspecified new db is put in llnewdbdir */
				if (!selftest && is_unadorned_directory(btreepath)) {
					readpath = strsave(concat_path(lloptions.llnewdbdir, btreepath));
				}
				/* see if we can make a new db */
				if(!trytocreate(readpath)) {
					show_open_error(bterrno);
					return FALSE;
				}
			}
			break;
		default:
			show_open_error(bterrno);
			return FALSE;
		}
	}
	readonly = !bwrite(BTR);
	if (readonly && writeable) {
		c = bkfile(BTR).k_ostat;
		if (c < 0) {
			llwprintf("The database is already opened for ");
			llwprintf("write access.\n  Try again later.");
		} else {
			llwprintf("The database is already opened for ");
			llwprintf("read access by %d users.\n  ", c - 1);
			llwprintf("Try again later.");
		}
		close_lifelines();
		return FALSE;
	}
	return TRUE;
}
/*==================================================
 * open_database -- open database
 * dbpath: database to report
 * dbactual: actual database path (may be relative also)
 *================================================*/
static BOOLEAN
open_database (STRING dbpath, STRING dbactual)
{
	BOOLEAN rtn;

	/* tentatively copy paths */
	btreepath=strsave(dbpath);
	readpath=strsave(dbactual);

	rtn = open_database_impl();
	if (!rtn) {
		/* open failed so clean up */
		close_lifelines();
		strfree(&btreepath);
		strfree(&readpath);
	}
	return rtn;
}

