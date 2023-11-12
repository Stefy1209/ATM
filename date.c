struct date{
    int day;
    int month;
    int year;
};

typedef struct date date;

date create_date(int day, int month, int year){
    // creates a date
    date a;
    a.day = day;
    a.month = month;
    a.year = year;
    return a;
}

int get_day(date a){
    // gets the day of a date
    return a.day;
}

int get_month(date a){
    // gets the month of a date
    return a.month;
}

int get_year(date a){
    // gets the year of a date
    return a.year;
}

int is_before(date Date1, date Date2){
    //verifies if date 1 is before date 2
    if(get_year(Date1) < get_year(Date2))
        return 1;

    if(get_year(Date1) > get_year(Date2))
        return 0;

    if(get_month(Date1) < get_month(Date2))
        return 1;

    if(get_month(Date1) > get_month(Date2))
        return 0;

    if(get_day(Date1) <= get_day(Date2))
        return 1;

    if(get_day(Date1) > get_day(Date2))
        return 0;
}

int is_after(date Date1, date Date2){
    //verifies if date 1 is after date 2
    if(get_year(Date1) < get_year(Date2))
        return 0;

    if(get_year(Date1) > get_year(Date2))
        return 1;

    if(get_month(Date1) < get_month(Date2))
        return 0;

    if(get_month(Date1) > get_month(Date2))
        return 1;

    if(get_day(Date1) < get_day(Date2))
        return 0;

    if(get_day(Date1) >= get_day(Date2))
        return 1;
}