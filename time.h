/**
 * Tag des Jahres
 * Autor: Timo Thiede
 * Erstellt am: 15.02.2021
 */

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

int day_of_the_year(int day, int month, int year); //Deklaration der Funktionsprototypen
int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);
int iput_data(int day, int month, int year);


#endif // TIME_H_INCLUDED
