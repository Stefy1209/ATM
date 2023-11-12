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
int is_before(date Date1, date Date2);
int is_after(date Date1, date Date2);