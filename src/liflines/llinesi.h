#ifndef _LIFLINES_PRIV_H
#define _LIFLINES_PRIV_H

/* add.c */
NODE add_child(NODE, NODE);
NODE add_family(NODE, NODE, NODE);
BOOLEAN add_linked_indi(NODE);
BOOLEAN add_spouse(NODE, NODE, BOOLEAN);
NOD0 add_indi_by_edit(void);

/* advedit.c */
void advanced_person_edit(NODE);
void advanced_family_edit(NODE);

/* ask.c */
NODE ask_for_indi(STRING, CONFIRMQ, ASK1Q);
INDISEQ ask_for_indiseq(STRING, INT*);
BOOLEAN ask_yes_or_no(STRING);

/* browse.c */
void browse(NODE, INT code);
NOD0 choose_any_event(void);
NOD0 choose_any_other(void);
NOD0 choose_any_source(void);
INT display_2fam(NODE fam1, NODE fam2, INT mode);
INT display_2indi(NODE indi1, NODE indi2, INT mode);
BOOLEAN handle_fam_mode_cmds(INT c, INT * mode);
BOOLEAN handle_indi_mode_cmds(INT c, INT * mode);
BOOLEAN handle_menu_cmds(INT c, BOOLEAN * reuse);
BOOLEAN handle_scroll_cmds(INT c, BOOLEAN * reuse);


/* delete.c */
void delete_indi(NODE, BOOLEAN);
void delete_fam(NODE);

/* edit.c */
NODE edit_family(NODE);
NODE edit_indi(NODE);

/* export.c */
BOOLEAN archive_in_file (void);

/* import.c */
BOOLEAN import_from_file(void);

/* lbrowse.c */
INT browse_list(NODE*, NODE*, NODE*, NODE*, INDISEQ*);

/* merge.c */
NODE merge_two_indis(NODE, NODE, BOOLEAN);
NODE merge_two_fams(NODE, NODE);

/* miscutls.c */
void key_util(void);
void show_database_stats(void);
void who_is_he_she(void);

/* newrecs.c */
NOD0 ask_for_record(STRING, INT);
void edit_event(NODE);
void edit_other(NODE);
void edit_source(NODE);
NODE add_event(void);
NODE add_other(void);
NODE add_source(void);

/* pedigree.c */
enum { GDVW_NORMAL, GDVW_EXPANDED, GDVW_TEXT };
void pedigree_draw_ancestors(NODE indi, INT row, INT menuht, BOOLEAN reuse);
void pedigree_draw_descendants(NODE indi, INT row, INT menuht, BOOLEAN reuse);
void pedigree_draw_gedcom(NODE node, INT gdvw, INT row, INT hgt, BOOLEAN reuse);
void pedigree_increase_generations(INT delta);
void pedigree_reset_scroll(void);
void pedigree_scroll(INT delta);
void pedigree_toggle_mode(void);

/* remove.c */
BOOLEAN choose_and_remove_child(NODE indi, NODE fam, BOOLEAN nolast);
BOOLEAN choose_and_remove_spouse(NODE indi, NODE fam, BOOLEAN nolast);
BOOLEAN remove_child(NODE indi, NODE fam);
BOOLEAN remove_spouse (NODE indi, NODE fam);

/* scan.c */
NOD0 full_name_scan(void);
NOD0 name_fragment_scan(void);
NOD0 refn_scan(void);

/* screen.c */
void adjust_menu_height(INT delta);
void cycle_menu(void);
void toggle_menu(void);

/* show.c */
void display_cache_stats(void);
void put_out_line(WINDOW * win, INT x, INT y, STRING string, INT width, INT flag);
void show_aux_display(NODE, INT mode, INT hgt, BOOLEAN reuse);
void show_ancestors(NODE indi, INT row, INT hgt, BOOLEAN reuse);
void show_childnumbers(void);
void show_descendants(NODE indi, INT row, INT hgt, BOOLEAN reuse);
void show_gedcom_main(NODE node, INT gdvw, INT row, INT hgt, BOOLEAN reuse);
void show_list(INDISEQ, INT, INT, INT);
void show_long_family(NODE, INT row, INT hgt, INT width, BOOLEAN reuse);
void show_person(WINDOW *, NODE, INT row, INT hgt, INT width, INT *scroll, BOOLEAN reuse);
void show_person_main(NODE, INT row, INT hgt, BOOLEAN reuse);
void show_reset_scroll(void);
void show_sour_display(NODE, INT, INT);
void show_scroll(INT delta);
void show_scroll2(INT delta);
void switch_scrolls(void);

/* swap.c */
BOOLEAN swap_children(NODE, NODE);
BOOLEAN swap_families(NODE);

/* tandem.c */
INT browse_tandem(NODE*, NODE*, NODE*, NODE*, INDISEQ*);
INT browse_2fam(NODE*, NODE*, NODE*, NODE*, INDISEQ*);

/* valgdcom.c */
int check_stdkeys (void);
void addmissingkeys (INT);
INT xref_to_index (STRING);
BOOLEAN validate_gedcom (FILE*);

#endif /* _LIFLINES_PRIV_H */
