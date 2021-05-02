extern int contacts;
typedef struct
{
    int day;
    int month;
    int year;
}date;
typedef struct
{
    char first[15];
    char last[15];
}fullname;
typedef struct
{
    unsigned int code;
    unsigned int num;
}phonenumber;
typedef struct
{
    fullname name;
    date DoB;
    char street[40];
    char email[40];
    phonenumber phone;
}directory;
directory* d;
