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
 * alloc.c -- Allocate nodes for report generator
 * pnodes are parse nodes in the parse tree built by yacc.c
 * Copyright(c) 1991-95 by T.T. Wetmore IV; all rights reserved
 *   2.3.4 - 24 Jun 93    2.3.5 - 17 Aug 93
 *   3.0.0 - 28 Jun 94    3.0.2 - 23 Dec 94
 *   3.0.3 - 10 Aug 95
 *===========================================================*/

#include "llstdlib.h"
#include "table.h"
#include "translat.h"
#include "gedcom.h"
#include "cache.h"
#include "interp.h"
#include "liflines.h"
#include "screen.h"

/*********************************************
 * external/imported variables
 *********************************************/

extern STRING ierror;
extern STRING Pfname;

/*********************************************
 * local types
 *********************************************/

struct pn_block
{
	struct pn_block * next;
	struct itag nodes[100]; /* arbitrary size may be adjusted */
};
typedef struct pn_block *PN_BLOCK;
#define BLOCK_NODES (sizeof(((PN_BLOCK)0)->nodes)/sizeof(((PN_BLOCK)0)->nodes[0]))

/*********************************************
 * local function prototypes
 *********************************************/

static PNODE alloc_pnode_memory(void);
static void free_pnode_memory(PNODE node);
static void delete_pnode(PNODE node);
static void set_parents(PNODE body, PNODE node);

/*********************************************
 * local variables
 *********************************************/

static PNODE free_list = 0;
static INT live_pnodes = 0;
static PN_BLOCK block_list = 0;

/*********************************************
 * local function definitions
 * body of module
 *********************************************/

/*========================================
 * alloc_pnode_memory -- return new pnode memory
 * We use a custom allocator, which lowers our overhead
 * (no heap overhead per pnode, only per block)
 * and also allows us to clean them all up after the
 * report.
 * NB: This is not traditional garbage collection - we're
 *  not doing any live/dead analysis; we depend entirely
 *  on carnal knowledge of the program.
 * As far as I know, no pnodes were ever being freed before.
 * Perry Rapp, 2001/01/20
 *======================================*/
static PNODE
alloc_pnode_memory (void)
{
	PNODE node;
	
	/*
	This assumes that all pnodes are scoped
	within report processing. If this ceases to
	be true, this breaks.
	*/
	if (!free_list) {
		PN_BLOCK new_block = stdalloc(sizeof(*new_block));
		INT i;
		new_block->next = block_list;
		block_list = new_block;
		for (i=0; i<BLOCK_NODES; i++) {
			PNODE node1 = &new_block->nodes[i];
			itype(node1) = IFREED;
			inext(node1) = free_list;
			free_list = node1;
		}
	}
	node = free_list;
	free_list = inext(node);
	live_pnodes++;
	return node;
}
/*========================================
 * free_pnode_memory -- return pnode to free-list
 * (see alloc_pnode_memory comments)
 * Created: 2001/01/21, Perry Rapp
 *======================================*/
static void
free_pnode_memory (PNODE node)
{
	/* put on free list */
	inext(node) = free_list;
	free_list = node;
	live_pnodes--;
	ASSERT(live_pnodes>=0);
}
/*======================================
 * free_all_pnodes -- Free every pnode
 * Created: 2001/01/21, Perry Rapp
 *====================================*/
void
free_all_pnodes (void)
{
	PN_BLOCK block;
	/* live_count is how many were leaked */
	while ((block = block_list)) {
		PN_BLOCK next = block->next;
		free_list = 0;
		if (live_pnodes) {
			INT i;
			for (i=0; i<BLOCK_NODES; i++) {
				PNODE node1=&block->nodes[i];
				if (itype(node1) != IFREED) {
					/* leaked */
					delete_pnode(node1);
				}
			}
		}
		stdfree(block);
		block_list = next;
	}
	free_list = 0;
}
/*==================================
 * create_pnode -- Create PNODE node
 * 2001/01/21 changed to block allocator
 *================================*/
PNODE
create_pnode (INT type)
{
	PNODE node = alloc_pnode_memory();
	itype(node) = type;
	iprnt(node) = NULL;
	inext(node) = NULL;
	iline(node) = Plineno;
	ifname(node) = Pfname;
	node->i_word1 = node->i_word2 = node->i_word3 = NULL;
	node->i_word4 = node->i_word5 = NULL;
	return node;
}
/*========================================
 * clear_pnode -- Empty contents of pvalue
 * I don't know if anything in the node needs to
 *  be freed, Perry
 * Created: 2001/01/20, Perry Rapp
 *======================================*/
void
clear_pnode (PNODE node)
{
	/*
	Is there anything needing handling here?

	Don't touch any pvalues, because the block cleaner
	freed them all!
	*/
}
/*==================================
 * delete_pnode -- Create PNODE node
 * Created: 2001/01/21, Perry Rapp
 *================================*/
static void
delete_pnode (PNODE node)
{
	if (!node) return;
	clear_pnode(node);
	free_pnode_memory(node);
}
/*==================================
 * string_node -- Create string node
 *  This is called from lex.c, and str points to
 *  a static buffer
 *================================*/
PNODE
string_node (STRING str)
{
	PNODE node = create_pnode(ISCONS);
	ASSERT(str); /* we're not converting NULL to "" because nobody passes us NULL */
	ivalue(node) = create_pvalue(PSTRING, (VPTR) str);
	return node;
}
/*========================================
 * children_node -- Create child loop node
 *======================================*/
PNODE
children_node (PNODE fexpr,     /* expr */
               STRING cvar,     /* child */
               STRING nvar,     /* counter */
               PNODE body)      /* loop body */
{
	PNODE node = create_pnode(ICHILDREN);
	iloopexp(node) = (VPTR) fexpr;
	ichild(node) = (VPTR) cvar;
	inum(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*========================================
 * spouses_node -- Create spouse loop node
 *======================================*/
PNODE
spouses_node (PNODE pexpr,      /* expr */
              STRING svar,      /* spouse */
              STRING fvar,      /* family */
              STRING nvar,      /* counter */
              PNODE body)       /* body */
{
	PNODE node = create_pnode(ISPOUSES);
	iloopexp(node) = (VPTR) pexpr;
	ispouse(node) = (VPTR) svar;
	ifamily(node) = (VPTR) fvar;
	inum(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*=========================================
 * families_node -- Create family loop node
 *=======================================*/
PNODE
families_node (PNODE pexpr,     /* expr */
               STRING fvar,     /* family */
               STRING svar,     /* spouse */
               STRING nvar,     /* counter */
               PNODE body)      /* body */
{
	PNODE node = create_pnode(IFAMILIES);
	iloopexp(node) = (VPTR) pexpr;
	ifamily(node) = (VPTR) fvar;
	ispouse(node) = (VPTR) svar;
	inum(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*=========================================
 * fathers_node -- Create fathers loop node
 *=======================================*/
PNODE
fathers_node (PNODE pexpr,      /* expr */
              STRING pvar,      /* father */
              STRING fvar,      /* family */
              STRING nvar,      /* counter */
              PNODE body)       /* body */
{
	PNODE node = create_pnode(IFATHS);
	iloopexp(node) = (VPTR) pexpr;
	iiparent(node) = (VPTR) pvar;
	ifamily(node) = (VPTR) fvar;
	inum(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*=========================================
 * mothers_node -- Create mothers loop node
 *=======================================*/
PNODE
mothers_node (PNODE pexpr,      /* expr */
              STRING pvar,      /* mother */
              STRING fvar,      /* family */
              STRING nvar,      /* counter */
              PNODE body)       /* body */
{
	PNODE node = create_pnode(IMOTHS);
	iloopexp(node) = (VPTR) pexpr;
	iiparent(node) = (VPTR) pvar;
	ifamily(node) = (VPTR) fvar;
	inum(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*=========================================
 * parents_node -- Create parents loop node
 *=======================================*/
PNODE
parents_node (PNODE pexpr,      /* expr */
              STRING fvar,      /* family */
              STRING nvar,      /* counter */
              PNODE body)       /* body */
{
	PNODE node = create_pnode(IFAMCS);
	iloopexp(node) = (VPTR) pexpr;
	ifamily(node) = (VPTR) fvar;
	inum(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*========================================
 * forindiset_node -- Create set loop node
 *======================================*/
PNODE
forindiset_node (PNODE iexpr,   /* expr */
                 STRING ivar,   /* person */
                 STRING vvar,   /* value */
                 STRING nvar,   /* counter */
                 PNODE body)    /* body */
{
	PNODE node = create_pnode(ISET);
	iloopexp(node) = (VPTR) iexpr;
	ielement(node) = (VPTR) ivar;
	ivalvar(node) = (VPTR) vvar;
	inum(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*======================================
 * forlist_node -- Create list loop node
 *====================================*/
PNODE
forlist_node (PNODE iexpr,      /* expr */
              STRING evar,      /* element */
              STRING nvar,      /* counter */
              PNODE body)       /* body */
{
	PNODE node = create_pnode(ILIST);
	iloopexp(node) = (VPTR) iexpr;
	ielement(node) = (VPTR) evar;
	inum(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*=========================================
 * forindi_node -- Create forindi loop node
 *=======================================*/
PNODE
forindi_node (STRING ivar,      /* pers */
              STRING nvar,      /* counter */
              PNODE body)       /* body */
{
	PNODE node = create_pnode(IINDI);
	ielement(node) = (VPTR) ivar;
	inum(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*=========================================
 * forsour_node -- Create forsour loop node
 *=======================================*/
PNODE
forsour_node (STRING fvar,    /* fam */
              STRING nvar,    /* counter */
              PNODE body)     /* body */
{
	PNODE node = create_pnode(ISOUR);
	ielement(node) = (VPTR) fvar;
	inum(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*=========================================
 * foreven_node -- Create foreven loop node
 *=======================================*/
PNODE
foreven_node (STRING fvar,    /* fam */
              STRING nvar,    /* counter */
              PNODE body)     /* body */
{
	PNODE node = create_pnode(IEVEN);
	ielement(node) = (VPTR) fvar;
	inum(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*=========================================
 * forothr_node -- Create forothr loop node
 *=======================================*/
PNODE
forothr_node (STRING fvar,    /* fam */
              STRING nvar,    /* counter */
              PNODE body)     /* body */
{
	PNODE node = create_pnode(IOTHR);
	ielement(node) = (VPTR) fvar;
	inum(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*=======================================
 * forfam_node -- Create forfam loop node
 *=====================================*/
PNODE
forfam_node (STRING fvar,    /* fam */
             STRING nvar,    /* counter */
             PNODE body)     /* body */
{
	PNODE node = create_pnode(IFAM);
	ielement(node) = (VPTR) fvar;
	inum(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*===========================================
 * fornotes_node -- Create fornotes loop node
 *=========================================*/
PNODE
fornotes_node (PNODE nexpr,   /* expr */
               STRING vvar,   /* value */
               PNODE body)    /* body */
{
        PNODE node = create_pnode(INOTES);
        iloopexp(node) = (VPTR) nexpr;
        ielement(node) = (VPTR) vvar;
        ibody(node) = (VPTR) body;
        set_parents(body, node);
        return node;
}
/*===========================================
 * fornodes_node -- Create fornodes loop node
 *=========================================*/
PNODE
fornodes_node (PNODE nexpr,    /* expr */
               STRING nvar,    /* node (next level) */
               PNODE body)     /* body */
{
	PNODE node = create_pnode(INODES);
	iloopexp(node) = (VPTR) nexpr;
	ielement(node) = (VPTR) nvar;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*===========================================
 * traverse_node -- Create traverse loop node
 *=========================================*/
PNODE
traverse_node (PNODE nexpr,    /* node */
               STRING snode,   /* subnode */
               STRING levv,    /* level */
               PNODE body)     /* body */
{
	PNODE node = create_pnode(ITRAV);
	iloopexp(node) = (VPTR) nexpr;
	ielement(node) = (VPTR) snode;
	ilev(node) = (VPTR) levv;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*====================================
 * iden_node -- Create identifier node
 *==================================*/
PNODE
iden_node (STRING iden)
{
	PNODE node = create_pnode(IIDENT);
	iident(node) = (VPTR) iden;
	return node;
}
/*==================================
 * icons_node -- Create integer node
 *================================*/
PNODE
icons_node (INT ival)
{
	PNODE node = create_pnode(IICONS);
	ivalue(node) = create_pvalue(PINT, (VPTR) ival);
	return node;
}
/*===================================
 * fcons_node -- Create floating node
 *=================================*/
PNODE
fcons_node (FLOAT fval)
{
	PNODE node = create_pnode(IFCONS);
	UNION u;
	u.f = fval;
	ivalue(node) = create_pvalue(PFLOAT, u.w);
	return node;
}
/*===================================
 * proc_node -- Create procedure node
 *=================================*/
PNODE
proc_node (STRING name,    /* proc name */
           PNODE parms,    /* param/s */
           PNODE body)     /* body */
{
	PNODE node = create_pnode(IPDEFN);
	iname(node) = (VPTR) name;
	iargs(node) = (VPTR) parms;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*==================================================
 * fdef_node -- Create user function definition node
 *================================================*/
PNODE
fdef_node (STRING name,    /* proc name */
           PNODE parms,    /* param/s */
           PNODE body)     /* body */
{
	PNODE node = create_pnode(IFDEFN);
	iname(node) = (VPTR) name;
	iargs(node) = (VPTR) parms;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*=======================================================
 * func_node -- Create builtin or user function call node
 *=====================================================*/
PNODE
func_node (STRING name,    /* function name */
           PNODE elist)    /* param/s */
{
	PNODE node;
	INT lo, hi, md=0, n, r;
	BOOLEAN found = FALSE;

/* See if the function is user defined */
	if (in_table(functab, name)) {
		node = create_pnode(IFCALL);
		iname(node) = (VPTR) name;
		iargs(node) = (VPTR) elist;
		ifunc(node) = (VPTR) valueof(functab, name);
		return node;
	}

/*
	See if the function is builtin
	Assumes that builtins[] is in alphabetic order
*/
	
	lo = 0;
	hi = nobuiltins - 1;
	while (lo <= hi) {
		md = (lo + hi) >> 1;
		if ((r = nestr(name, builtins[md].ft_name)) < 0)
			hi = md - 1;
		else if (r > 0)
			lo = md + 1;
		else {
			found = TRUE;
			break;
		}
	}
	if (found) {
		if ((n = num_params(elist)) < builtins[md].ft_nparms_min
		    || n > builtins[md].ft_nparms_max) {
			llwprintf(ierror, Pfname, Plineno);
			llwprintf("%s: must have %d to %d parameters.\n", name,
		    	builtins[md].ft_nparms_min, builtins[md].ft_nparms_max);
			Perrors++;
		}
		node = create_pnode(IBCALL);
		iname(node) = (VPTR) name;
		iargs(node) = (VPTR) elist;
		ifunc(node) = (VPTR) builtins[md].ft_eval;
		return node;
		
	}

/* If neither make it a user call to undefined function */
	node = create_pnode(IFCALL);
	iname(node) = (VPTR) name;
	iargs(node) = (VPTR) elist;
	ifunc(node) = NULL;
	return node;
}
/*=============================
 * if_node -- Create an if node
 *===========================*/
PNODE
if_node (PNODE cond,     /* cond expr */
         PNODE tnode,    /* then */
         PNODE enode)    /* else */
{
	PNODE node = create_pnode(IIF);
	icond(node) = (VPTR) cond;
	ithen(node) = (VPTR) tnode;
	ielse(node) = (VPTR) enode;
	set_parents(tnode, node);
	set_parents(enode, node);
	return node;
}
/*================================
 * while_node -- Create while node
 *==============================*/
PNODE
while_node (PNODE cond,     /* cond expr */
            PNODE body)     /* body */
{
	PNODE node = create_pnode(IWHILE);
	icond(node) = (VPTR) cond;
	ibody(node) = (VPTR) body;
	set_parents(body, node);
	return node;
}
/*===================================
 * call_node -- Create proc call node
 *=================================*/
PNODE
call_node (STRING name,    /* proc name */
           PNODE args)     /* arg/s */
{
	PNODE node = create_pnode(IPCALL);
	iname(node) = (VPTR) name;
	iargs(node) = (VPTR) args;
	return node;
}
/*================================
 * break_node -- Create break node
 *==============================*/
PNODE break_node (void)
{
	PNODE node = create_pnode(IBREAK);
	return node;
}
/*======================================
 * continue_node -- Create continue node
 *====================================*/
PNODE continue_node (void)
{
	PNODE node = create_pnode(ICONTINUE);
	return node;
}
/*==================================
 * return_node -- Create return node
 *================================*/
PNODE
return_node (PNODE args)
{
	PNODE node = create_pnode(IRETURN);
	iargs(node) = (VPTR) args;
	return node;
}
/*==============================================
 * set_parents -- Link body nodes to parent node
 *============================================*/
void
set_parents (PNODE body,
             PNODE node)
{
	while (body) {
		iprnt(body) = node;
		body = inext(body);
	}
}
/*=========================================================
 * show_pnode -- DEBUG routine that shows a PNODE structure
 *=======================================================*/
void
show_pnode (PNODE node)
{
	while (node) {
		show_one_pnode(node);
		node = inext(node);
	}
}
/*==========================================================
 * show_pnodes -- DEBUG routine that shows expression PNODEs
 *========================================================*/
void
show_pnodes (PNODE node)
{

	while (node) {
		show_one_pnode(node);
		node = inext(node);
		if (node) llwprintf(",");
	}
}
/*====================================================
 * show_one_pnode -- DEBUG routine that show one PNODE
 *==================================================*/
void
show_one_pnode (PNODE node)     /* node to print */
{
	UNION u;

	switch (itype(node)) {

	case IICONS:
		llwprintf("%d", pvalue(ivalue(node)));
		break;
	case IFCONS:
		u.w = pvalue(ivalue(node));
		llwprintf("%f", u.f);
		break;
	case ILCONS:
		llwprintf("*ni*");
		break;
	case ISCONS:
		llwprintf("^^%s^^", pvalue(ivalue(node)));
		break;
	case IIDENT:
		llwprintf("%s", iident(node));
		break;
	case IIF:
		llwprintf("if(");
		show_pnodes(icond(node));
		llwprintf("){");
		show_pnodes(ithen(node));
		llwprintf("}");
		if (ielse(node)) {
			llwprintf("else{");
			show_pnodes(ielse(node));
			llwprintf("}");
		}
		break;
	case IWHILE:
		llwprintf("while(");
		show_pnodes(icond(node));
		llwprintf("){");
		show_pnodes(ibody(node));
		llwprintf("}");
		break;
	case IBREAK:
		llwprintf("break ");
		break;
	case ICONTINUE:
		llwprintf("continue ");
		break;
	case IRETURN:
		llwprintf("return(");
		show_pnodes(iargs(node));
		llwprintf(")");
		break;
	case IPDEFN:
		llwprintf("*PDefn *");
		break;
	case IPCALL:
		llwprintf("%s(", iname(node));
		show_pnodes(iargs(node));
		llwprintf(")");
		break;
	case IFDEFN:
		llwprintf("*FDefn *");
		break;
	case IFCALL:
		llwprintf("%s(", iname(node));
		show_pnodes(iargs(node));
		llwprintf(")");
		break;
	case IBCALL:
		llwprintf("%s(", iname(node));
		show_pnodes(iargs(node));
		llwprintf(")");
		break;
	case ITRAV:
		llwprintf("*Traverse *");
		break;
	case INODES:
		llwprintf("*Fornodes *");
		break;
	case IFAMILIES:
		llwprintf("*FamiliesLoop *");
		break;
	case ISPOUSES:
		llwprintf("*SpousesLoop *");
		break;
	case ICHILDREN:
		llwprintf("*ChildrenLoop *");
		break;
	case IINDI:
		llwprintf("*PersonLoop *");
		break;
	case IFAM:
		llwprintf("*FamilyLoop *");
		break;
	case ISOUR:
		llwprintf("*SourceLoop *");
		break;
	case IEVEN:
		llwprintf("*EventLoop *");
		break;
	case IOTHR:
		llwprintf("*OtherLoop *");
		break;
	case ILIST:
		llwprintf("*ListLoop *");
		break;
	case ISET:
		llwprintf("*IndisetLoop *");
		break;
	case IFATHS:
		llwprintf("*FathersLoop *");
		break;
	case IMOTHS:
		llwprintf("*MothersLoop *");
		break;
	case IFAMCS:
		llwprintf("*ParentsLoop *");
		break;
	case INOTES:
		llwprintf("*NotesLoop *");
		break;
	default:
		break;
	}
}
