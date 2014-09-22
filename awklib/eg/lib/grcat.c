/*
 * grcat.c
 *
 * Generate a printable version of the group database
 */
/*
 * Arnold Robbins, arnold@gnu.org, May 1993
 * Public Domain
 */

#if HAVE_CONFIG_H
#include<config.h>
#endif

#include <stdio.h>
#include <grp.h>

int
main(argc, argv)
int argc;
char **argv;
{
#if HAVE_GETPGRENT
    struct group *g;
    int i;

    while ((g = getgrent()) != NULL) {
        printf("%s:%s:%d:", g->gr_name, g->gr_passwd,
                                            g->gr_gid);
        for (i = 0; g->gr_mem[i] != NULL; i++) {
            printf("%s", g->gr_mem[i]);
            if (g->gr_mem[i+1] != NULL)
                putchar(',');
        }
        putchar('\n');
    }
    endgrent();
#endif
    exit(0);
}
