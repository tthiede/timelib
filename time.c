/**
 * Tag des Jahres
 * Autor: Timo Thiede
 * Erstellt am: 15.02.2021
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
 * und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
 * Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
 *
 * @param day: Tag
 * @param month: Monat
 * @param year: Jahr
 * @return Nummer des Tages
 **/
int day_of_the_year(int day, int month, int year)
{
    int ergebnis = 0;
    if (exists_date(day, month, year) == 1) //Pruefe ob Datum gueltig ist
    {
        for(int i = 1; i < month; i++)//Gehe von Monat 1 bis eingegebenen Monat
        {
            ergebnis = ergebnis + get_days_for_month(i, year);//Addiere alle Tage zusammen
        }
        ergebnis = ergebnis + day;
        return ergebnis;
    }
    else
    {
        return -1; //Datum ist ungueltig
    }
}

/**
 * Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum
 * ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.
 *
 * @param year: Zeiger auf Jahr
 * @param month: Zeifer auf Monat
 * @param day: Zeiger auf Tag
 * @return kein Rueckgabewert
 **/
void input_date(int *day, int *month, int *year)
{
    do
    {
        printf("Geben Sie den Tag ein: \n");
        scanf("%d", &*day);
        fflush(stdin);
        printf("Gben Sie den Monat ein: \n");
        scanf("%d", &*month);
        fflush(stdin);
        printf("Geben Sie das Jahr ein: \n");
        scanf("%d", &*year);
    } while (exists_date(*day, *month, *year) == 0);
}

/**
 * Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
 * ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben.
 *
 * @param year: Jahr
 * @return 1, wenn übergebenes Jahr ein
 * Schaltjahr ist
 * 0, wenn übergebenes Jahr kein
 * Schaltjahr ist
 * -1, wenn ein ungültiges Jahr
übergeben wurde
 **/
int is_leapyear(int year)
{
    if (year < 1582)
    {
        return -1;
    }
    if(year % 4 == 0) //Ist Jahr durch 4 teilbar
    {
        if(year % 100 == 0) //Ist  Jahr durch 100 teilbar
        {
            if (year % 400 == 0)  //Ist Jahr durch 400 teilbar
            {
                return 1;
            }
            else //Jahr ist nicht durch 400 teilbar
            {
                return 0;
            }
        }
        else //Jahr ist nicht durch 100 teilbar
        {
            return 1;
        }
    }
    else //Jahr ist nicht durch 4 teilbar
    {
        return 0;
    }
}


/**
 * Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
 * Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
 *
 * @param month: Monat
 * @param year: Jahr
 * @return Anzahl von Tagen: int
 * 1-31, wenn ein gültiger Monar
 * eingegeben wurde
 * -1, wenn ein ungültiger Monat oder
 * Jahr übergeben wurde
 **/
int get_days_for_month(int month, int year)
{
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int tage_pro_monat_schaltjahr[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int ergebnis = 0;

    if (is_leapyear(year) == 1) //Jahr ist Schaltjahr
    {
        return tage_pro_monat_schaltjahr[month - 1];
    }
    if (is_leapyear(year) == 0) //Jahr ist kein Schaltjahr
    {
        return tage_pro_monat[month - 1];
    }
    if  (is_leapyear(year) == -1) //Jahr ist ungueltig
    {
        printf("Bitte geben Sie ein Jahr nach 1582 ein! \n");
        return -1;
    }
    return ergebnis;
}

/**
*Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
* wie alle Daten nach dem 31.12.2400.
*
* @param day: Tag
* @param month: Monat
* @param year: Jahr
* @return 1, wenn das übergebene Datum
* gültig ist
* 0, wenn das Datum nicht gültig ist
**/
int exists_date(int day, int month, int year)
{
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int tage_pro_monat_schaltjahr[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

    if (is_leapyear(year) == 1) //Jahr ist Schaltjahr
    {
        if ((day <= tage_pro_monat_schaltjahr[month - 1]) && (month <= 12) && (year >= 1582) && (year <= 2400)) //Ueberpreufe alle Anforderungen
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if  (is_leapyear(year) == 0) //Jahr ist kein Schaltjahr
    {
         if ((day <= tage_pro_monat[month - 1]) && (month <= 12) && (year >= 1582) && (year <= 2400))
         {
             return 1;
         }
         else
         {
             return 0;
         }
    }
}
