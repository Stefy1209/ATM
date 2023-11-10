struct tranzaction{
    date data;
    char description[301];
    float amount;
    int type; // 0 == income ; 1 == expense
};

typedef struct tranzaction tranzaction;

tranzaction create_tranzaction(date data, char description[301], float amount, int type);
void printf_tranzaction(tranzaction x);