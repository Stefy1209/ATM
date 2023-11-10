struct date{
    int day;
    int month;
    int year;
};

typedef struct date date;

date create_date(int day, int month, int year);
int get_day(date a);
int get_month(date a);
int get_year(date a);