#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "bfd.h"
#include "debugger.h"

void display_section_info(bfd *abfd, asection *sect, void *obj)
{
	fprintf(stderr, "%4d %-18s  %08x  %08x  %016x\n", 
            sect->index, sect->name, (unsigned int)sect->rawsize, (unsigned int)sect->size, (unsigned int)sect->vma);
}

int load_elf(const char *path) {
    if (!debugger_status.is_init_bfd) {
        bfd_init();
        debugger_status.is_init_bfd = TRUE;
    }
    
    bfd *bfd_info = bfd_openr(path, NULL);
    if (!bfd_info || bfd_get_error() != 0) {
        fprintf(stderr, "Error opening file `%s`: %s\n", path, bfd_errmsg(bfd_get_error()));
        return -1;
    }
    if (!bfd_check_format(bfd_info, bfd_object)) {
        bfd_close_all_done(bfd_info);
        fprintf(stderr, "File is not a valid object file\n");
        return -1;
    }

    int storage_needed = bfd_get_symtab_upper_bound(bfd_info);
    if (storage_needed < 0) {
        fprintf(stderr, "Error reading symbol table in file `%s`: %s\n", path, bfd_errmsg(bfd_get_error()));
        return -1;
    } else {
        if (storage_needed == 0) {
            fprintf(stderr, "No symbols found in file `%s`\n", path);
            return -1;
        }
    }
    asymbol **symbol_table = malloc(storage_needed);
    int number_of_symbols = bfd_canonicalize_symtab(bfd_info, symbol_table);
    if (number_of_symbols < 0) {
        fprintf(stderr, "Error reading symbol table in file '%s': %s\n", path, bfd_errmsg(bfd_get_error()));
        return -1;
    }

    fprintf(stderr, "\nSections:\n\n");
    fprintf(stderr, " Idx Name                rSize     cSize     VMA     \n");
    bfd_map_over_sections(bfd_info, display_section_info, NULL);
    fprintf(stderr, "\n");

    fprintf(stderr, "\nSymbols:\n\n");
    for (int i = 0; i < number_of_symbols; i++) {
        fprintf(stderr, "%016lx  %s\n", symbol_table[i]->section->vma + symbol_table[i]->value, symbol_table[i]->name);
    }

    free(symbol_table);

    return 0;
}   

