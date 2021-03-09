/**
 * Tag des Jahres
 * Autor: Timo Thiede
 * Erstellt am: 15.02.2021
 */

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

struct date
{
    int day, month, year;
};
int day_of_the_year(struct date dt); //Deklaration der Funktionsprototypen
int is_leapyear(int year);
int get_days_for_month(struct date *dt);
int exists_date(struct date *dt);
int iput_data(struct date *dt);
#endif // TIME_H_INCLUDED
