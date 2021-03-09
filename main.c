/**
 * Ausgabe: Tag des Jahres
 * Autor: Timo Thiede
 * Erstellt am: 15.02.2021
 */

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main()
{
    struct date dt;
    input_date(&dt);
    printf("Tag des Jahres: %i\n", day_of_the_year(dt));
    return 0;
}
