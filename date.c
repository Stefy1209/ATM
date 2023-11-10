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